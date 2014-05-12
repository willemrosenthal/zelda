package ;
import flixel.util.FlxPoint;
import flixel.group.FlxGroup;
import flixel.tile.FlxTilemap;

class Global {

	static public var ini:Bool;

	static public var zeroPoint:FlxPoint;

    static public var tileSize:Int = 16;
    static public var gameTileSize:Array<Int> = [0,0];
    static public var gameHeight:Float;
    static public var gameWidth:Float;

	static public var mouseEnabled:Bool;
	static public var firstTouchId:Int = -1;
	static public var secondTouchId:Int = -1;
	static public var moveTouched:Bool;
	static public var firstTouch:FlxPoint;
	static public var firstTouchTo:FlxPoint;

	static public var gameZoom:Float;
	static public var game:FlxGroup;

    static public var c:Array<Int> = [0,0];
    static public var n:Array<Int> = [0,0];
	static public var cMap:Array<Array<Int>>;   // current level
    static public var hMap:Array<Array<Int>>;   // hit map
    static public var tMap:FlxTilemap;   // current level
    static public var changingScreens:Bool;
    static public var nextDir:String;   // direction of next screen


	static public var move:FlxPoint = new FlxPoint(0,0);

	static public var UIopen:Bool = false;

    static public var levels:Array<Array<Int>> = [
        [0,1,2,3],
        [4,5,6,7],
        [8,9,10,11]
    ];


	static public function levelStart():Void
	{
		ini = true;
	}


	public function new() {
	}
}
