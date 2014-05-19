package enemies;

import flixel.util.FlxPoint;
import flixel.FlxObject;

class Enemy extends GameObject
{
    public var damage:Int = 1;
    public var speed:Float = 0;
    public var invincible:Bool = false;
    public var dammageType:Array<String>; // types of dammage the monster is suceptable to
    public var knockBackDistance:Float = 5;

    private var damaged:Bool;
    private var afterDamageTimer:Int = 0;
    private var afterDamageTime:Int = 15;

	public function new(X:Float, Y:Float)
	{
		super(X, Y);
        uniqueCollideAction = true;
        allowCollisions = FlxObject.ANY;
	}

    override public function update():Void
    {
        super.update();

        if (dontUpdate)
            return;

        if (damaged) {
            animation.play("Hurt");
            afterDamageTimer++;
            if (afterDamageTimer == afterDamageTime) {
                damaged = false;
                afterDamageTimer = 0;
                animation.play("Basic");
            }

        }
    }

    public function takeDamage(Damage:Int, DamageType:String = ""):Void {
        if (dammageType != null && Calc.existInArray(dammageType,DamageType))
            return;
        health -= Damage;
        damaged = true;
        knockBack();
        if (health <= 0)
            enemyDeath(Damage);
    }

    public function knockBack():Void {
        if (knockBackDistance == 0)
            return;
        var kb:FlxPoint =  new FlxPoint(x - Global.player.x, y - Global.player.y);
        var kbDir:FlxPoint =  new FlxPoint(1,1);

        if (kb.x < 0)
            kbDir.x = -1;
        if (kb.y < 0)
            kbDir.y = -1;

        if (kb.x == 0) {
            kb.y = kbDir.y;
        }
        else if (kb.y == 0) {
            kb.x = kbDir.x;
        }
        else {
            kb.x = Math.abs(kb.x);
            kb.y = Math.abs(kb.y);

            if (kb.x > kb.y) {
                kb.y = 1/(kb.x/kb.y);
                kb.x = 1;
            }
            else if (kb.x < kb.y) {
                kb.x = 1/(kb.y/kb.x);
                kb.y = 1;
            }

            if (kb.x <= 1) {
                kb.x *= kbDir.x;
                kb.y = (1 - Math.abs(kb.x)) * kbDir.y;
            }
            else if (kb.x > 1) {
                kb.y = (kb.x - 1) * kbDir.y;
                kb.x = (1 - Math.abs(kb.y)) * kbDir.x;
            }
        }

        xChange = kb.x * knockBackDistance;
        yChange = kb.y * knockBackDistance;
    }

    /**
	 * Used for actions that happen upon the enemie's death
	 */
    public function enemyDeath(Damage:Int):Void {
        destroy();
    }

    override public function collide(p:Player):Void {
        takeDamage(0);
    }
}