package ;

import ui.Button;
class BButton extends Button
{

	public function new(X:Float, Y:Float)
	{
		super(X, Y, "assets/images/ui/start.png",28,8);
	}


	override public function update():Void
	{
        super.update();

        if (down)
            Global.start = true;
        else Global.start = false;
	}
}