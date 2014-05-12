package ui;

class AButton extends Button
{

	public function new(X:Float, Y:Float)
	{
		super(X, Y, "assets/images/ui/a.png",27,27);
	}


	override public function update():Void
	{
        super.update();

        name = "a";

        if (down)
            Global.a = true;
        else Global.a = false;
	}
}