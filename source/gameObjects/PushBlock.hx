package gameObjects;

import flixel.FlxObject;
import flixel.FlxSprite;

class PushBlock extends GameObject
{

    private var pushing:Bool;
    private var pushStarted:Bool;
    private var pushDir:String = "";
    private var pushTimer:Int = 0;
    private var pushTime:Int = 15;
    private var pushSpeed:Float = 1;
    private var accumulativePushPx:Float = 0;

    public var okHitType:Int = 0;


	public function new(X:Float, Y:Float)
	{
		super(X, Y);

        loadGraphic("assets/tilesets/gameobjects.png", true, 16, 16);

        animation.add("Basic", [1]);
        animation.play("Basic");

        immovable = true;
	}

    override public function update():Void
    {
        super.update();

        if (entering || Global.changingScreens || primeForDeath)
            return;

        if (!hitSides(true))
            x += xChange;
        if (!hitVert(true))
            y += yChange;

        xChange = 0;
        yChange = 0;

        checkForPush();

        push();
    }


    override public function scrollEndIni():Void {
        MapControl.updateHitMap(x,y,1);
    }


    private function checkForPush():Void {
        pushing = true;
        if (Global.player.x == x + Global.tileSize && (Global.player.y < y + height * 0.35 && Global.player.y > y - height * 0.35) && Global.player.dir == "left" && Global.player.moveingDir.x < 0 && MapControl.getHitType(x - Global.tileSize,y) == okHitType)
            pushDir = "left";
        else if (Global.player.x == x - Global.tileSize && (Global.player.y < y + height * 0.35 && Global.player.y > y - height * 0.35) && Global.player.dir == "right" && Global.player.moveingDir.x > 0 && MapControl.getHitType(x + Global.tileSize,y) == okHitType)
            pushDir = "right";
        else if (Global.player.perfectY == y + Global.tileSize && (Global.player.x < x + width * 0.35 && Global.player.x > x - width * 0.35) && Global.player.dir == "up" && Global.player.moveingDir.y < 0 && MapControl.getHitType(x,y - Global.tileSize) == okHitType)
            pushDir = "up";
        else if (Global.player.perfectY == y - Global.tileSize && (Global.player.x < x + width * 0.35 && Global.player.x > x - width * 0.35) && Global.player.dir == "down" && Global.player.moveingDir.y > 0 && MapControl.getHitType(x,y + Global.tileSize) == okHitType)
            pushDir = "down";
        else {
            pushing = false;
            pushTimer = 0;
        }
    }


    private function push():Void {
        if (!pushing && !pushStarted) {
            pushTimer = 0;
            return;
        }

        pushTimer++;
        if (pushTimer > pushTime) {
            pushStarted = true;
            MapControl.updateHitMap(x,y,0);
            allowCollisions = FlxObject.ANY;
        }

        if (pushStarted) {
            if (pushDir == "left")
                x -= pushSpeed;
            else if (pushDir == "right")
                x += pushSpeed;
            else if (pushDir == "down")
                y += pushSpeed;
            else if (pushDir == "up")
                y -= pushSpeed;
            accumulativePushPx += pushSpeed;
        }
        if (accumulativePushPx >= Global.tileSize) {
            endPush();
        }
    }

    private function endPush():Void {
        pushing = false;
        pushStarted = false;
        pushTimer = 0;
        accumulativePushPx = 0;
        pushDir = "";
        x = Math.round(x/Global.tileSize) * Global.tileSize;
        y = Math.round(y/Global.tileSize) * Global.tileSize + Global.mapyTSD - Global.tileSize;
        MapControl.updateHitMap(x,y,1);
        allowCollisions = FlxObject.NONE;
    }

}