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
    static public var mapy:Float;

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

    static public var xScrollSpeed:Float;
    static public var yScrollSpeed:Float;

    //buttons
    static public var a:Bool;
    static public var b:Bool;
    static public var start:Bool;

    //multitouch
    static public var T1id:Int = -1;
    static public var T1:FlxPoint;
    static public var T1Use:String = "";
    static public var T2id:Int = -1;
    static public var T2:FlxPoint;
    static public var T2Use:String = "";




	static public var move:FlxPoint = new FlxPoint(0,0);

	static public var UIopen:Bool = false;

    static public var levels:Array<Array<String>> = [
        ["0-0","0-1","0-2","0-3"],
        ["1-0","1-1","1-2","1-3"],
        ["2-0","2-1","2-2","2-3"]
    ];


	static public function levelStart():Void
	{
		ini = true;
	}
}
