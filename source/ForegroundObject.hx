package ;

import flixel.FlxObject;

class ForegroundObject extends GameObject
{
	public function new(X:Float, Y:Float, No:Int, Sheet:String, Solid:Bool = false, Animate:Array<Int> = null, FrameRate:Int = 6)
	{
		super(X, Y);

        loadGraphic(Sheet, true, Global.tileSize,Global.tileSize);
        if (Animate != null)
            animation.add("Basic", Animate,FrameRate);
        else animation.add("Basic", [No]);

        if (Solid)
            allowCollisions = FlxObject.ANY;
        else allowCollisions = FlxObject.NONE;

        animation.play("Basic");
	}
}