package ;

import flixel.FlxObject;
import flixel.FlxSprite;

class GameObject extends FlxSprite
{

    public var primeForDeath:Bool;
    public var entering:Bool = true;
    public var uniqueCollideAction:Bool = false;

    // moving direction & speed
    private var xChange:Float = 0;
    private var yChange:Float = 0;

	public function new(X:Float, Y:Float)
	{
		super(X, Y);
        allowCollisions = FlxObject.NONE;
	}


	override public function update():Void
	{
        super.update();

        if(!Global.changingScreens && entering) {
            entering = false;
            scrollEndIni();
        }

        if(Global.changingScreens && !entering)
            primeForDeath = true;

        if (primeForDeath && !Global.changingScreens)
            destroy();
	}



    var cx:Float;   // check x
    var cy:Float;   // check y
    private function hitSides(simple:Bool = false):Bool {
        cx = x;
        cy = y;
        if (xChange > 0)
            cx += width;

        if (simple) {
            cy += height * 0.5;
            if (MapControl.getHitType(cx + xChange, cy) == 1)
                return true;
            return false;
        }

        cy += height * 0.1;
        if (MapControl.getHitType(cx + xChange, cy) == 1)
            return true;
        cy += height * 0.4;
        if (MapControl.getHitType(cx + xChange, cy) == 1)
            return true;
        cy += height * 0.4;
        if (MapControl.getHitType(cx + xChange, cy) == 1)
            return true;
        return false;

    }
    private function hitVert(simple:Bool = false):Bool {
        cx = x;
        cy = y + height * 0.3;
        if (yChange > 0)
            cy = y + height * .95;

        if (simple) {
            cx += width * 0.5;
            if (MapControl.getHitType(cx, cy + yChange) == 1)
                return true;
            return false;
        }

        cx += width * 0.1;
        if (MapControl.getHitType(cx, cy + yChange) == 1)
            return true;
        cx += width * 0.4;
        if (MapControl.getHitType(cx, cy + yChange) == 1)
            return true;
        cx += width * 0.4;
        if (MapControl.getHitType(cx, cy + yChange) == 1)
            return true;
        return false;
    }

    public function collide(p:Player):Void {}

    public function scrollEndIni():Void {}
}