package ;
import flixel.util.FlxPoint;
import flixel.FlxG;
import openfl.Assets;

class MapControl {

    static public var pt:FlxPoint;
    static public function getTileType(X:Float, Y:Float):Int {
        pt = getTilePos(X,Y - Global.mapy);
        if (arrayLocExists(pt.x,pt.y))
            return Global.cMap[Std.int(pt.y)][Std.int(pt.x)];
        else return -1;
    }
    static public function getHitType(X:Float, Y:Float):Int  {
        pt = getTilePos(X,Y - Global.mapy);
        if (arrayLocExists(pt.x,pt.y))
            return Global.hMap[Std.int(pt.y)][Std.int(pt.x)];
        else return -1;
    }

    static public function getNextTileType(X:Float, Y:Float, Xover:Int, Yover:Int):Int {
        pt = getTilePos(X + (Global.tileSize * Xover),Y - Global.mapy + (Global.tileSize * Yover));
        if (arrayLocExists(pt.x,pt.y))
            return Global.cMap[Std.int(pt.y)][Std.int(pt.x)];
        else return -1;
    }
    static public function getNextHitType(X:Float, Y:Float, Xover:Int, Yover:Int):Int  {
        pt = getTilePos(X + (Global.tileSize * Xover),Y - Global.mapy + (Global.tileSize * Yover));
        if (arrayLocExists(pt.x,pt.y))
            return Global.hMap[Std.int(pt.y)][Std.int(pt.x)];
        else return -1;
    }

    static public function getTilePos(X:Float, Y:Float):FlxPoint {
        return new FlxPoint(Std.int(X/Global.tileSize), Std.int(Y/Global.tileSize));
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
        if (arrayLocExists(pt.x,pt.y))
            Global.hMap[Std.int(pt.y)][Std.int(pt.x)] = Val;
    }

    static public function arrayLocExists(Col:Float,Row:Float):Bool {
        if (Global.hMap.length > Row && Row >= 0 && Global.hMap[Std.int(Row)].length > Col && Col >= 0)
            return true;
        return false;
    }


	public function new() {
	}
}
