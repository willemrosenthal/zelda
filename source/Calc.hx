package ;
import flixel.util.FlxPoint;
import flixel.FlxG;

class Calc {

	static public function randomOnScreen(Padding:Float=0,PaddingY:Float=0):FlxPoint
	{
		var pos:FlxPoint = new FlxPoint((FlxG.width - Padding) * Math.random() + Padding * 0.5, (FlxG.height - PaddingY) * Math.random() + PaddingY * 0.5);
		return pos;
	}

	static public function plusOrMinus(Value:Float=1):Float
	{
		return ((Math.round(Math.random()) * 2) - 1) * Value;
	}

    static public function existInArray(Ar:Array<Dynamic>, Value:Dynamic):Bool {
        for (n in 0...Ar.length -1) {
            if (Ar[n] == Value)
                return true;
        }
        return false;
    }

	public function new() {
	}
}
