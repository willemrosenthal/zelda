package ;

import flixel.FlxSprite;

class GameObject extends FlxSprite
{

    public var primeForDeath:Bool;
    public var entering:Bool = true;

	public function new(X:Float, Y:Float)
	{
		super(X, Y);
	}


	override public function update():Void
	{
        super.update();

        if(!Global.changingScreens && entering)
            entering = false;

        if(Global.changingScreens && !entering)
            primeForDeath = true;

        if (primeForDeath && !Global.changingScreens)
            destroy();
	}

}