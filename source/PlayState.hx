package;

import flixel.FlxBasic;
import ui.MultitouchField;
import ui.Joystick;
import ui.AButton;
import ui.BButton;
import flixel.FlxSprite;
import flixel.FlxG;
import flixel.FlxSprite;
import flixel.FlxState;

import flixel.FlxG;
import flixel.FlxState;
import flixel.FlxSprite;
import flixel.group.FlxGroup;
import flixel.tile.FlxTilemap;
import openfl.Assets;

import gameObjects.ForegroundObject;

/**
 * A FlxState which can be used for the actual gameplay.
 */
class PlayState extends FlxState
{


    private var mapHeight:Int = 10;
    private var mapWidth:Int = 10;
    private var gHight:Int;
    private var gWidth:Int;

    private var mapx:Float = 0;
    private var mapy:Float = 24;
    private var hudyAdjust:Float = 10;
    private var levelMap:FlxTilemap = new FlxTilemap();
    private var mapData:String;
    private var mapObjectData:String;
    private var tileSet:String;
    private var tileSetObjects:String;
    private var mapObjArray:Array<Array<String>>;

    private var nextMap:FlxTilemap = new FlxTilemap();
    private var nextData:String;
    private var nextSet:String;
    private var nextDir:String = "none";
    private var xScrollSpeed:Float;
    private var yScrollSpeed:Float;
    private var pSSx:Float;
    private var pSSy:Float;
    private var scrollTotalFrames:Float = 100;
    private var counter:Int = 0;


    public var map:FlxGroup;
    public var enemeis:FlxGroup;
    public var objects:FlxGroup;
    public var groundObjects:FlxGroup;
    public var hud:FlxGroup;
    public var border:FlxGroup;

    private var joystickBG:FlxSprite;
    private var joystick:Joystick;
    private var tBox:FlxSprite;
    private var bBox:FlxSprite;
    private var rBox:FlxSprite;
    private var lBox:FlxSprite;
    private var blackBox:FlxSprite;
    private var bars:Array<FlxSprite>;

    private var a:AButton;
    private var b:BButton;
    private var hudTest:FlxSprite;
    private var mtf:MultitouchField;


    private var gameZoom:Float = 4;

    public var player:Player;



    public function new()
    {
        super();
        config();
    }

	override public function create():Void
	{
		super.create();

        map = new FlxGroup();
        map.maxSize = 2;
        add(map);

        buildMap();

        groundObjects = new FlxGroup();
        add(groundObjects);

        player = new Player(4.5 * Global.tileSize,3.5 * Global.tileSize);
        add(player);
        Global.player = player;

        enemeis = new FlxGroup();
        add(enemeis);

        objects = new FlxGroup();
        add(objects);



        setupHud();
	}

    private function config():Void
    {
        gHight = Global.tileSize * mapHeight;
        gWidth = Global.tileSize * mapWidth;
        Global.gameTileSize = [mapWidth,mapHeight];
        Global.mapy = mapy;
        Global.mapyTSD = mapy - Global.tileSize;
        xScrollSpeed = 5; //gWidth/scrollTotalFrames;
        yScrollSpeed = 5; //gHight/scrollTotalFrames;
        pSSx = xScrollSpeed * ((mapWidth - 0.7)/mapWidth);
        pSSy = yScrollSpeed * ((mapHeight - 0.7)/mapHeight);
        Global.xScrollSpeed = xScrollSpeed;
        Global.yScrollSpeed = yScrollSpeed;
    }

    function buildMap():Void
    {
        mapData = "assets/levels/" + Global.levels[Global.c[0]][Global.c[1]] + ".txt";
        tileSet = "assets/tilesets/1.png";

        //levelMap.tileScaleHack = 1.0;

        levelMap.loadMap(Assets.getText(mapData), tileSet, Global.tileSize, Global.tileSize, FlxTilemap.OFF,0);
        levelMap.x = mapx;
        levelMap.y = mapy;
        map.add(levelMap);
        convertMapData();
    }

    function buildNextMap():Void
    {
        nextData = "assets/levels/" + Global.levels[Global.n[0]][Global.n[1]] + ".txt";
        mapObjectData = "assets/levels/" + Global.levels[Global.n[0]][Global.n[1]] + "_obj.txt";
        nextSet = "assets/tilesets/1.png";
        tileSetObjects = "assets/tilesets/1_obj.png";

        nextMap.loadMap(Assets.getText(nextData), nextSet, Global.tileSize, Global.tileSize, FlxTilemap.OFF,0);

        if (nextDir == "up") {  // up
            nextMap.x = levelMap.x;
            nextMap.y = levelMap.y - gHight;
        }
        if (nextDir == "right") {  // rt
            nextMap.x = levelMap.x + gWidth;
            nextMap.y = levelMap.y;
        }
        if (nextDir == "down") {  // dn
            nextMap.x = levelMap.x;
            nextMap.y = levelMap.y + gHight;
        }
        if (nextDir == "left") {  // lf
            nextMap.x = levelMap.x - gWidth;
            nextMap.y = levelMap.y;
        }

        buildMapObjects();

        nextMap.visible = true;

        map.add(nextMap);
    }

    private function buildMapObjects():Void {
        mapObjArray = MapControl.mapInterpretor(mapObjectData);

        //var nextx:Float = nextMap.x;
        //var nexty:Float = nextMap.y;
        var oc:String = "";

        if (mapObjArray == null)
            return null;

        for (n in 0...mapObjArray.length -1) {
            for (q in 0...mapObjArray[n].length -1) {
                oc = gameObjectTypeChecker(mapObjArray[n][q]);
                if (mapObjArray[n][q] == "0")
                    continue;
                if (oc == "enemy")
                    objectAdder(mapObjArray[n][q], n, q, oc);

                if (oc == "worldObject")
                    objectAdder(mapObjArray[n][q], n, q, oc);

                if (oc == "fgObject")
                    objectAdder(mapObjArray[n][q], n, q, oc);
            }
        }
        //trace(objects.members[0].exists);
    }

    private function gameObjectTypeChecker(ObjectId:String):String {
        if (Std.parseInt(ObjectId) != null)
            return "fgObject";
        else if (ObjectId.charAt(0) == "e")
            return "enemy";
        else if (ObjectId.charAt(0) == "o")
            return "worldObject";
        return "none";
    }

    private function objectAdder(ObjNo:String, Row:Int, Col:Int, Type:String):Void {
        if (Type == "enemy") {
            enemeis.add(ObjectIndex.getEnemy(ObjNo, Col * Global.tileSize + nextMap.x, Row * Global.tileSize + nextMap.y));
            return;
        }
        if (Type == "worldObject") {
            groundObjects.add(ObjectIndex.getGameObject(ObjNo, Col * Global.tileSize + nextMap.x, Row * Global.tileSize + nextMap.y));
            return;
        }
        objects.add(new ForegroundObject(Col * Global.tileSize + nextMap.x, Row * Global.tileSize + nextMap.y, Std.parseInt(ObjNo), tileSetObjects));   // make game objec
    }


    private function setupHud():Void {
        // border
        border = new FlxGroup();
        add(border);

        tBox = new FlxSprite(0, -8 + mapy,"assets/images/ui/bar_h.png");
        border.add(tBox);

        lBox = new FlxSprite(-8, 0 + mapy,"assets/images/ui/bar_v.png");
        border.add(lBox);

        bBox = new FlxSprite(0, gHight + 8 + mapy,"assets/images/ui/bar_h.png");
        border.add(bBox);

        rBox = new FlxSprite(gWidth + 8, 0 + mapy,"assets/images/ui/bar_v.png");
        border.add(rBox);

        //hud
        hud = new FlxGroup();
        add(hud);

        var joyPosX:Float = Global.gameWidth * 0.27;
        var joyPosY:Float = Global.gameHeight * 0.78 + hudyAdjust;


        blackBox = new FlxSprite(0, gHight + levelMap.y,"assets/images/ui/blackbox.png");
        hud.add(blackBox);

        joystickBG = new FlxSprite(joyPosX, joyPosY,"assets/images/ui/joystick_ring.png");   //"assets/joystick_ring_big.png"
        joystickBG.x -=  joystickBG.width * 0.5;
        joystickBG.y -=  joystickBG.height * 0.5;
        hud.add(joystickBG);

        joystick = new Joystick(joyPosX, joyPosY, joystickBG.width);
        hud.add(joystick);

        a = new AButton(90,180 + hudyAdjust);
        hud.add(a);

        b = new BButton(120,210 + hudyAdjust);
        hud.add(b);

        hudTest = new FlxSprite(0, 0,"assets/images/ui/hud_test.png");
        hud.add(hudTest);

        mtf = new MultitouchField();
        add(mtf);
        //FlxG.stage.addChild(mtf);
    }


    /**
	 * Function that is called when this state is destroyed - you might want to
	 * consider setting all objects this state uses to null to help garbage collection.
	 */
    override public function destroy():Void
    {
        super.destroy();
    }


    override public function update():Void
    {
        super.update();


        FlxG.overlap(player, border, touchEdge);

        FlxG.collide(player, groundObjects, collideF);
        FlxG.collide(player, objects, collideF);
        FlxG.overlap(player, enemeis, collideF);

        if (Global.changingScreens == true)
            moveScreens();
    }

    private function collideF(player:Player, GmObject:FlxBasic):Void {
        var go:GameObject = cast(GmObject, GameObject);
        if (go.uniqueCollideAction)
            go.collide(player);
    }


    private function moveScreens():Void {
        if (nextDir == "up") {
            levelMap.y += yScrollSpeed;
            nextMap.y += yScrollSpeed;
            player.y += pSSy;
            if (levelMap.y >= gHight + mapy)
                finishSroll();
        }
        else if (nextDir == "down") {
            levelMap.y -= yScrollSpeed;
            nextMap.y -= yScrollSpeed;
            player.y -= pSSy;
            if (levelMap.y <= -gHight + mapy)
                finishSroll();
        }
        else if (nextDir == "left") {
            levelMap.x += xScrollSpeed;
            nextMap.x += xScrollSpeed;
            player.x += pSSx;
            if (levelMap.x >= gWidth - mapx)
                finishSroll();
        }
        else if (nextDir == "right") {
            levelMap.x -= xScrollSpeed;
            nextMap.x -= xScrollSpeed;
            player.x -= pSSx;
            if (levelMap.x <= -gWidth + mapx)
                finishSroll();
        }
        groundObjects.forEach(scrollOver);
        objects.forEach(scrollOver);
        enemeis.forEach(scrollOver);
    }



    private function scrollOver(GmObject:FlxBasic):Void {
        var go:GameObject = cast(GmObject, GameObject);
        if (Global.nextDir == "up")
            go.y += Global.yScrollSpeed;
        else if (Global.nextDir == "down")
            go.y -= Global.yScrollSpeed;
        else if (Global.nextDir == "right")
            go.x -= Global.xScrollSpeed;
        else if (Global.nextDir == "left")
            go.x += Global.xScrollSpeed;
    }

    private function finishSroll():Void {
        Global.c = Global.n;
        nextMap.visible = false;
        buildMap();
        Global.changingScreens = false;
    }

    private function touchEdge(Player:FlxSprite, Edge:FlxSprite):Void {
        if (Global.changingScreens)
            return;

        Global.changingScreens = true;

        if (Edge == tBox) {
            nextDir = "up";
            Global.n[0]--;
        }
        else if (Edge == bBox) {
            nextDir = "down";
            Global.n[0]++;
        }
        else if (Edge == rBox) {
            nextDir = "right";
            Global.n[1]++;
        }
        else if (Edge == lBox) {
            nextDir = "left";
            Global.n[1]--;
        }
        Global.nextDir = nextDir;
        buildNextMap();
    }

    private var dataArray:Array<Int>;
    private var finalArray:Array<Array<Int>>;
    private var arrayPlaceCounter:Int = 0;

    private function convertMapData():Void {
        dataArray = new Array();
        arrayPlaceCounter = 0;
        dataArray = levelMap.getData();

        finalArray = new Array();
        for (n in 0...mapHeight) {
            finalArray.push(new Array());
            for (q in 0...mapWidth) {
                finalArray[n].push(dataArray[arrayPlaceCounter]);
                arrayPlaceCounter++;
            }
        }
        Global.cMap = finalArray;
        buildHitMap();
    }

    private function buildHitMap():Void {
        Global.hMap = finalArray;
        for (n in 0...mapHeight) {
            for (q in 0...mapWidth) {
                Global.hMap[n][q] = isItSolid(Global.hMap[n][q]);
            }
        }
    }

    private function isItSolid(n:Int):Int {
        if ((n <= 5 && n > 0) || (n <= 15 && n > 10) || (n <= 25 && n > 20) || (n <= 35 && n > 30) || (n <= 45 && n > 40) || (n <= 55 && n > 50) || (n <= 65 && n > 60) || (n <= 75 && n > 70))
            return 0;
        return 1;
    }

    private function traceMaps():Void {
        trace("TILE MAP: ");
        for (m in 0...Global.cMap.length) {
            trace(Global.cMap[m]);
        }
        trace("");
        trace("HIT MAP: ");
        for (m in 0...Global.hMap.length) {
            trace(Global.hMap[m]);
        }
    }

}