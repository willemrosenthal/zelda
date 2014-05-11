package ;

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

	public function new(X:Float, Y:Float, RingSize:Float) {
		super(X, Y);
		gameZoom = Global.gameZoom;
		originPoint = new FlxPoint(X,Y);
		moveDirs = new FlxPoint(0,0);

		loadGraphic("assets/images/joystick.png", false, 20,20);
		offset.y = height * 0.5;
		offset.x = width * 0.5;

        maxDistance = RingSize * 0.5 - width * 0.5;
        mouseMaxY = RingSize * 0.86;
        mouseMaxX = RingSize * 0.86;
	}

	override public function update():Void {
		super.update();

		if (FlxG.mouse.justPressed && !mouseDown)
			mouseDown = true;
		if (FlxG.mouse.justReleased)
			mouseDown = false;


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
		xDif = originPoint.x - FlxG.stage.mouseX / gameZoom;
		yDif = originPoint.y - FlxG.stage.mouseY / gameZoom;

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
			x = FlxG.stage.mouseX / gameZoom;
			y = FlxG.stage.mouseY / gameZoom;
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

        if ((FlxG.mouse.y > originPoint.y + mouseMaxY || FlxG.mouse.y < originPoint.y - mouseMaxY) || (FlxG.mouse.x > originPoint.x + mouseMaxX || FlxG.mouse.x < originPoint.x - mouseMaxX)) {
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
}