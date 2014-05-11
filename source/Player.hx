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

    private var xChange:Float;
    private var yChange:Float;

	public function new(X:Float, Y:Float)
	{
		super(X, Y);

        loadGraphic("assets/images/player.png", true, 16,16);
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

        // animations
        if (Global.move.x == 0 || Global.move.y == 0)
        {
            animation.play("stop_" + cAnim);
        }
        if (Math.abs(speed.x) > Math.abs(speed.y))
        {
            if (speed.x > 0)
                animation.play("right");
            if (speed.x < 0)
                animation.play("left");
            cAnim = animation.curAnim.name;
        }
        else if (Math.abs(speed.x) < Math.abs(speed.y))
        {
            if (speed.y > 0)
                animation.play("down");
            if (speed.y < 0)
                animation.play("up");
            cAnim = animation.curAnim.name;
        }

        // sholdn't be nessesary in final build


        xChange = speed.x * FlxG.elapsed;
        yChange = speed.y * FlxG.elapsed;

        stopAtEdges();

        x += xChange;
        y += yChange;


        //trace(Calc.getTileType((x + height * 0.5),(y + height * 0.5)));
	}

    private function stopAtEdges():Void{

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
}