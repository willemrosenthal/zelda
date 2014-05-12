package ui;

import flixel.FlxBasic;
import flash.display.Sprite;
import flixel.util.FlxPoint;
import flash.events.TouchEvent;
import flixel.FlxCamera;
import flixel.FlxG;
import flash.ui.MultitouchInputMode;
import flash.ui.Multitouch;
class MultitouchField extends FlxBasic
{

	private var ignoreRange:Float = 28;

	public function new()
	{
        super();
		Multitouch.inputMode = MultitouchInputMode.TOUCH_POINT;

        FlxG.stage.addEventListener(TouchEvent.TOUCH_BEGIN, onBegin);
        FlxG.stage.addEventListener(TouchEvent.TOUCH_MOVE, onMove);
        FlxG.stage.addEventListener(TouchEvent.TOUCH_END, onEnd);
	}

	private function onBegin(e:TouchEvent):Void
	{
		if (Global.T1id != -1 && Global.T2id != -1 && Global.T3id != -1)
			return;

		if (Global.T1id == -1)
		{
			Global.T1id = e.touchPointID;
			Global.T1 = new FlxPoint(e.stageX / Global.gameZoom,e.stageY / Global.gameZoom);
		}
		else if (Global.T1id != -1 && e.touchPointID != Global.T1id && Global.T2id == -1)
		{
			//if (e.stageX < Global.firstTouchTo.x + ignoreRange && e.stageX > Global.firstTouchTo.x - ignoreRange && e.stageY < Global.firstTouchTo.y + ignoreRange && e.stageY > Global.firstTouchTo.y - ignoreRange)
				//return;
			Global.T2id = e.touchPointID;
            Global.T2 = new FlxPoint(e.stageX / Global.gameZoom,e.stageY / Global.gameZoom);
		}
	}


	private function onMove(e:TouchEvent):Void
	{
		if (e.touchPointID == Global.T1id)  {
            Global.T1.x = e.stageX / Global.gameZoom;
            Global.T1.y = e.stageY / Global.gameZoom;
        }
        if (e.touchPointID == Global.T2id)  {
            Global.T2.x = e.stageX / Global.gameZoom;
            Global.T2.y = e.stageY / Global.gameZoom;
        }
	}

	private function onEnd(e:TouchEvent):Void
	{
		if (e.touchPointID == Global.T1id)
		{
			Global.T1id = -1;
			Global.T1 = new FlxPoint(-10,-10);
            Global.T1Use = "";
		}
		else if (e.touchPointID == Global.T2id)
		{
            Global.T2id = -1;
            Global.T2 = new FlxPoint(-10,-10);
            Global.T2Use = "";
		}
	}

	override public function kill():Void
	{
        FlxG.stage.removeEventListener(TouchEvent.TOUCH_BEGIN, onBegin);
        FlxG.stage.removeEventListener(TouchEvent.TOUCH_MOVE, onMove);
        FlxG.stage.removeEventListener(TouchEvent.TOUCH_END, onEnd);
	}
}
