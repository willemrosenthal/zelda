package ui;

import flixel.FlxG;
import flixel.FlxSprite;

class Button extends FlxSprite
{

    private var mouseDown:Bool = false;
    private var mousex:Float;
    private var mousey:Float;

    public var name:String = "button";
    public var down:Bool = false;
    public var bleedSize:Float = 5;


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

        if (mousex > x - bleedSize && mousex < x + width + bleedSize && mousey > y - bleedSize && mousey < y + height + bleedSize) {
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

        if (Global.T1id != -1 && (Global.T1Use == "" || Global.T1Use == name) && Global.T1.x > x - bleedSize && Global.T1.x < x + width + bleedSize && Global.T1.y > y - bleedSize && Global.T1.y < y + height + bleedSize) {
            mousex = Global.T1.x;
            mousey = Global.T1.y;
            Global.T1Use = name;
            return;
        }
        if (Global.T2id != -1 && (Global.T2Use == "" || Global.T2Use == name) && Global.T2.x > x - bleedSize && Global.T2.x < x + width + bleedSize && Global.T2.y > y - bleedSize && Global.T2.y < y + height + bleedSize) {
            mousex = Global.T2.x;
            mousey = Global.T2.y;
            Global.T2Use = name;
            return;
        }
    }
}