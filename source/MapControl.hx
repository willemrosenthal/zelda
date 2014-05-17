package ;
import flixel.util.FlxPoint;
import flixel.FlxG;
import openfl.Assets;

class MapControl {

    static public var pt:FlxPoint;
    static public function getTileType(X:Float, Y:Float):Int {
        pt = getTilePos(X,Y - Global.mapy);
        if (Global.cMap.length > pt.y && Global.cMap[Std.int(pt.y)].length > pt.x)
            return Global.cMap[Std.int(pt.y)][Std.int(pt.x)];
        else return -1;
    }
    static public function getHitType(X:Float, Y:Float):Int  {
        pt = getTilePos(X,Y - Global.mapy);
        if (Global.hMap.length > pt.y && Global.hMap[Std.int(pt.y)].length > pt.x)
            return Global.hMap[Std.int(pt.y)][Std.int(pt.x)];
        else return -1;
    }

    static public function getTileValue(X:Float, Y:Float):FlxPoint {
        return new FlxPoint(X/Global.tileSize, Y/Global.tileSize);
    }

    static public function getTilePos(X:Float, Y:Float):FlxPoint {
        return new FlxPoint(X/Global.tileSize, Y/Global.tileSize);
    }

    static public function mapInterpretor(MapData:Dynamic):Array<Array<String>> {
        if (!Assets.exists(MapData))
            return null;

        var unsplitRows:Array<String> = Assets.getText(MapData).split("\n");
        var finalArray:Array<Array<String>> = new Array();

        for (n in 0...unsplitRows.length -1) {
            var row:Array<String> = unsplitRows[n].split(",");
            finalArray.push(row);
        }
        return finalArray;
    }



    static public function updateHitMap(X:Float, Y:Float, Val:Int):Void {
        pt = getTilePos(X,Y - Global.mapy);
        // besure the spot exists
        if (Global.hMap.length > pt.y && Global.hMap[Std.int(pt.y)].length > pt.x) {
            Global.hMap[Std.int(pt.y)][Std.int(pt.x)] = Val;
        }
    }


	public function new() {
	}
}
