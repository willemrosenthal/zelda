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


    static public var pt:FlxPoint;
    static public function getTileType(X:Float, Y:Float):Int
    {
        pt = getTilePos(X,Y - Global.mapy);
        if (Global.cMap.length > pt.y && Global.cMap[Std.int(pt.y)].length > pt.x)
            return Global.cMap[Std.int(pt.y)][Std.int(pt.x)];
        else return -1;
    }
    static public function getHitType(X:Float, Y:Float):Int
    {
        pt = getTilePos(X,Y - Global.mapy);
        if (Global.hMap.length > pt.y && Global.hMap[Std.int(pt.y)].length > pt.x)
            return Global.hMap[Std.int(pt.y)][Std.int(pt.x)];
        else return -1;
    }

    static public function getTileValue(X:Float, Y:Float):FlxPoint
    {
        return new FlxPoint(X/Global.tileSize, Y/Global.tileSize);
    }

    static public function getTilePos(X:Float, Y:Float):FlxPoint
    {
        return new FlxPoint(X/Global.tileSize, Y/Global.tileSize);
    }

	public function new() {
	}
}
