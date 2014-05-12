package ui;

import flixel.FlxG;
import flixel.FlxSprite;
import flixel.util.FlxPoint;
import flixel.FlxObject;

class Joystick extends FlxSprite {

	public var maxDistance:Float = 38;
	public var moveIgnoreRange:Int = 8;
	public var moveSpeed:Float = 1;
    public var mouseMaxY:Float = 70;
    public var mouseMaxX:Float = 70;

	private var originPoint:FlxPoint;
	private var xDif:Float = 0;
	private var yDif:Float = 0;
	private var hyp:Float = 0;
	private var moveDirs:FlxPoint;
	private var mouseDown:Bool = false;
	private var gameZoom:Float = 1;
    private var multiplier:Float = 2;

    private var mousex:Float;
    private var mousey:Float;

	public function new(X:Float, Y:Float, RingSize:Float) {
		super(X, Y);
		gameZoom = Global.gameZoom;
		originPoint = new FlxPoint(X,Y);
		moveDirs = new FlxPoint(0,0);

		loadGraphic("assets/images/joystick.png", false, 20,20);
		offset.y = height * 0.5;
		offset.x = width * 0.5;

        maxDistance = RingSize * 0.5 - width * 0.5;
        mouseMaxY = RingSize * 0.7;
        mouseMaxX = RingSize * 0.7;
	}

	override public function update():Void {
		super.update();
        /*
		if (FlxG.mouse.justPressed && !mouseDown)
			mouseDown = true;
		if (FlxG.mouse.justReleased)
			mouseDown = false;
        */

		if (noMove())
		   return;


		if (!mouseDown) {
			x = originPoint.x;
			y = originPoint.y;
			Global.move.x = 0;
			Global.move.y = 0;
			return;
		}

		Global.move = calculateJoystick();
	}

	private function calculateJoystick():FlxPoint {
		xDif = originPoint.x - mousex;
		yDif = originPoint.y - mousey;

        if (multiplier > 1) {
            hyp = Math.sqrt(Math.abs(xDif*xDif) + Math.abs(yDif*yDif));
            positionJostick();
            xDif *= multiplier;
            yDif *= multiplier;
        }
        else positionJostick();

		moveDirs.x = 0;
		moveDirs.y = 0;

		if (xDif==0) {
			moveDirs.x = 0;
            if (yDif > 0)
			    moveDirs.y = -1;
            if (yDif < 0)
                moveDirs.y = 1;
			return moveDirs;
		}

        if (yDif==0) {
            moveDirs.y = 0;
            if (xDif > 0)
                moveDirs.x = -1;
            if (xDif < 0)
                moveDirs.x = 1;
            return moveDirs;
        }

		hyp = Math.sqrt(Math.abs(xDif*xDif) + Math.abs(yDif*yDif));

		if (hyp < moveIgnoreRange)
			return moveDirs;

		if (Math.abs(hyp) < maxDistance) {
			moveDirs.x = hyp/maxDistance * (xDif * (moveSpeed/hyp) * -1);
			moveDirs.y = hyp/maxDistance * (yDif * (moveSpeed/hyp) * -1);
			return moveDirs;
		}

		moveDirs.x = xDif * (moveSpeed/hyp) * -1;
		moveDirs.y = yDif * (moveSpeed/hyp) * -1;

		return moveDirs;
	}

	private function positionJostick():Void {
		if (Math.abs(hyp) < maxDistance) {
			x = mousex;
			y = mousey;
		}
		else {
			x = maxDistance/hyp * xDif * -1 + originPoint.x;
			y = maxDistance/hyp * yDif * -1 + originPoint.y;
		}
	}

	private function noMove():Bool {
		if (Global.UIopen) {
            resetJoystick();
            mouseDown = false;
		    return true;
		}

        /*
        if ((FlxG.mouse.y > originPoint.y + mouseMaxY || FlxG.mouse.y < originPoint.y - mouseMaxY) || (FlxG.mouse.x > originPoint.x + mouseMaxX || FlxG.mouse.x < originPoint.x - mouseMaxX)) {
            resetJoystick();
		    return true;
        }
        */

        if (!findMouse()) {
            resetJoystick();
            return true;
        }

        if (Global.changingScreens) {
            Global.move.x = 0;
            Global.move.y = 0;
        }

        return false;
	}

    private function resetJoystick():Void {
        x = originPoint.x;
        y = originPoint.y;
        Global.move.x = 0;
        Global.move.y = 0;
    }


    private function findMouse():Bool {
        mouseDown = false;
        if (Global.T1id != -1 && checkForUse(1) && Global.T1.x > originPoint.x - mouseMaxX && Global.T1.x < originPoint.x + mouseMaxX && Global.T1.y > originPoint.y - mouseMaxY && Global.T1.y < originPoint.y + mouseMaxY) {
            mousex = Global.T1.x;
            mousey = Global.T1.y;
            Global.T1Use = "joy";
            mouseDown = true;
            return true;
        }
        else if (Global.T2id != -1 && checkForUse(2) && Global.T2.x > originPoint.x - mouseMaxX && Global.T2.x < originPoint.x + mouseMaxX && Global.T2.y > originPoint.y - mouseMaxY && Global.T2.y < originPoint.y + mouseMaxY) {
            mousex = Global.T2.x;
            mousey = Global.T2.y;
            Global.T2Use = "joy";
            mouseDown = true;
            return true;
        }
        else if (Global.T1id == -1 && Global.T2id == -1) {
            mousex = FlxG.mouse.x / gameZoom;
            mousey = FlxG.mouse.y / gameZoom;
            return true;
        }
        return false;
    }

    private function checkForUse(TouchNo:Int):Bool {
        if (TouchNo == 1) {
            if (Global.T1Use == "joy")
                return true;
            if (Global.T2Use == "joy")
                return false;
            if (Global.T3Use == "joy")
                return false;
            if (Global.T1Use == "")
                return true;
        }
        if (TouchNo == 2) {
            if (Global.T2Use == "joy")
                return true;
            if (Global.T1Use == "joy")
                return false;
            if (Global.T3Use == "joy")
                return false;
            if (Global.T2Use == "")
                return true;
        }
        if (TouchNo == 3) {
            if (Global.T3Use == "joy")
                return true;
            if (Global.T1Use == "joy")
                return false;
            if (Global.T2Use == "joy")
                return false;
            if (Global.T3Use == "")
                return true;
        }
        return false;
    }
}