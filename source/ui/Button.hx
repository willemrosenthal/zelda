package ui;

import flixel.FlxG;
import flixel.FlxSprite;

class Button extends FlxSprite
{

    private var mouseDown:Bool = false;
    private var touch:String = "";
    private var mousex:Float;
    private var mousey:Float;

    public var name:String = "button";
    public var down:Bool = false;


	public function new(X:Float, Y:Float, Graphic:String, Width:Int, Height:Int)
	{
		super(X, Y);

        loadGraphic(Graphic, true, Width,Height);
        animation.add("up", [0]);
        animation.add("down", [1]);
	}


	override public function update():Void
	{
        super.update();

        findMouse();

        if (mousex > x && mousex < x + width && mousey > y && mousey < y + height) {
            down = true;
            animation.play("down");
            trace(Global.T1.x);
        }
        else {
            down = false;
            animation.play("up");
        }
	}



    private function findMouse():Void {
        mousex = 0;
        mousey = 0;

        if (Global.T1id != -1 && (Global.T1Use == "" || Global.T1Use == name) && Global.T1.x > x && Global.T1.x < x + width && Global.T1.y > y && Global.T1.y < y + height) {
            mousex = Global.T1.x;
            mousey = Global.T1.y;
            Global.T1Use = name;
            return;
        }
        if (Global.T2id != -1 && (Global.T2Use == "" || Global.T2Use == name) && Global.T2.x > x && Global.T2.x < x + width && Global.T2.y > y && Global.T2.y < y + height) {
            mousex = Global.T2.x;
            mousey = Global.T2.y;
            Global.T2Use = name;
            return;
        }
    }
}