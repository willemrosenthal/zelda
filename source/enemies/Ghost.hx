package enemies;

class Ghost extends Enemy
{
	public function new(X:Float, Y:Float)
	{
		super(X, Y);
        health = 3;
        damage = 1;

        loadGraphic("assets/images/enemies/ghost.png", true, 16, 16);

        animation.add("Basic", [0,1],3);
        animation.add("Hurt", [2,3],15);
        animation.play("Basic");
	}

    override public function update():Void
    {
        super.update();

        if (dontUpdate)
            return;
    }
}