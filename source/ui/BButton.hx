package ui;

class BButton extends Button
{

	public function new(X:Float, Y:Float)
	{
		super(X, Y, "assets/images/ui/b.png",27,27);
	}


	override public function update():Void
	{
        super.update();

        name = "b";

        if (down)
            Global.b = true;
        else Global.b = false;
	}
}