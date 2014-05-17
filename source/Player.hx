package ;

import flixel.FlxG;
import flixel.FlxSprite;
import flixel.util.FlxPoint;

class Player extends FlxSprite
{

    public var maxSpeed:Float = 80;
    public var speed:FlxPoint;
    public var dir:String = "down";
    public var cAnim:String = "down";

    // postioning
    public var moveingDir:FlxPoint = new FlxPoint(0,0);
    public var perfectY:Float;

    private var xChange:Float;
    private var yChange:Float;

    public var knock:Bool;

	public function new(X:Float, Y:Float)
	{
		super(X, Y);

        loadGraphic("assets/images/player.png", true, 16,17);
        animation.add("down", [0,1],6);
        animation.add("left", [2,3],6);
        animation.add("up", [4,5],6);
        animation.add("right", [6,7],6);
        animation.add("stop_down", [0]);
        animation.add("stop_left", [2]);
        animation.add("stop_up", [4]);
        animation.add("stop_right", [6]);

        speed = new FlxPoint();
	}


	override public function update():Void
	{
        super.update();

        // for testing - should be off on phone
        #if ( !cpp && !neko )
            computerControlls();
        #end

        speed.x = 0;
        speed.y = 0;

        if (Global.changingScreens) {
            animation.play(Global.nextDir);
            return;
        }

        // movement
        if (Global.move.x != 0 || Global.move.y != 0)
        {
            speed.x = Global.move.x * maxSpeed;
            speed.y = Global.move.y * maxSpeed;
        }
        moveingDir.x = Global.move.x;
        moveingDir.y = Global.move.y;

        // animations
        if (knock)
        {
            animation.play(cAnim);
        }
        else if (Global.move.x == 0 && Global.move.y == 0)
        {
            animation.play("stop_" + cAnim);
        }
        else if (Math.abs(speed.x) > Math.abs(speed.y))
        {
            if (speed.x > 0) {
                animation.play("right");
                dir = "right";
            }
            if (speed.x < 0) {
                animation.play("left");
                dir = "left";
            }
            cAnim = animation.curAnim.name;
        }
        else if (Math.abs(speed.x) < Math.abs(speed.y))
        {
            if (speed.y > 0) {
                animation.play("down");
                dir = "down";
            }
            if (speed.y < 0) {
                animation.play("up");
                dir = "up";
            }
            cAnim = animation.curAnim.name;
        }

        // sholdn't be nessesary in final build


        xChange = speed.x * FlxG.elapsed;
        yChange = speed.y * FlxG.elapsed;

        stopAtEdges();


        if (hitSides()) {
            x = Math.round(x/Global.tileSize) * Global.tileSize;
            xChange = 0;
        }
        if (hitVert()) {
            perfectY = Math.round(y/Global.tileSize) * Global.tileSize + Global.mapyTSD;
            y = perfectY;
            if (yChange < 0)
               y -= (height * 0.3);
            else y -= 1;
            yChange = 0;
        }


        x += xChange;
        y += yChange;

        //trace(quadHitCheck());

        //trace(Calc.getTileType((x + height * 0.5),(y + height * 0.5)));
	}



    var cx:Float;   // check x
    var cy:Float;   // check y
    private function hitSides():Bool {
        cx = x;
        cy = y;
        if (xChange > 0)
            cx += width;

        cy += height * 0.3;
        if (Calc.getHitType(cx + xChange, cy) == 1)
            return true;
        cy += height * 0.325;
        if (Calc.getHitType(cx + xChange, cy) == 1)
            return true;
        cy += height * 0.325;
        if (Calc.getHitType(cx + xChange, cy) == 1)
            return true;
        return false;

    }
    private function hitVert():Bool {
        cx = x;
        cy = y + height * 0.3;
        if (yChange > 0)
            cy = y + height * .95;

        cx += width * 0.1;
        if (Calc.getHitType(cx, cy + yChange) == 1)
            return true;
        cx += width * 0.4;
        if (Calc.getHitType(cx, cy + yChange) == 1)
            return true;
        cx += width * 0.4;
        if (Calc.getHitType(cx, cy + yChange) == 1)
            return true;
        return false;
    }


    private function stopAtEdges():Void {

        // left
        if (xChange < 0 && (x + xChange)/Global.tileSize < 0 && Global.c[1] == 0)
            xChange = 0;
        // right
        if (xChange > 0 && (x + width + xChange)/Global.tileSize > Global.gameTileSize[0] && Global.c[1] == Global.levels[0].length -1)
            xChange = 0;
        // up
        if (yChange < 0 && (y + yChange)/Global.tileSize < 0 && Global.c[0] == 0)
            yChange = 0;
        // down
        if (yChange > 0 && (y + height + yChange)/Global.tileSize > Global.gameTileSize[1] && Global.c[0] == Global.levels.length -1)
            yChange = 0;
    }

    private function computerControlls():Void {
        if (FlxG.keys.anyPressed(["LEFT", "A"]))
            Global.move.x = -1;

        if (FlxG.keys.anyPressed(["RIGHT", "D"]))
            Global.move.x = 1;

        if (FlxG.keys.anyPressed(["UP", "W"]))
            Global.move.y = -1;

        if (FlxG.keys.anyPressed(["DOWN", "S"]))
            Global.move.y = 1;

        if (Global.move.x != 0 && Global.move.y != 0) {
            Global.move.x *= 0.75;
            Global.move.y *= 0.75;
        }
    }
}