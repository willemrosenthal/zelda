package ;

import enemies.Ghost;

import gameObjects.PushBlock;


class ObjectIndex {

	static public function getEnemy(id:String, x:Float, y:Float):GameObject
	{
        if (id == "e1")
            return new Ghost(x,y);
        return null;
	}

	static public function getGameObject(id:String, x:Float, y:Float):GameObject
	{
		if (id == "o1")
            return new PushBlock(x,y);
        return null;
	}


}
