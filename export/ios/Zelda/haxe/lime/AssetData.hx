package lime;


import lime.utils.Assets;


class AssetData {

	private static var initialized:Bool = false;
	
	public static var library = new #if haxe3 Map <String, #else Hash <#end LibraryType> ();
	public static var path = new #if haxe3 Map <String, #else Hash <#end String> ();
	public static var type = new #if haxe3 Map <String, #else Hash <#end AssetType> ();	
	
	public static function initialize():Void {
		
		if (!initialized) {
			
			path.set ("assets/data/data-goes-here.txt", "assets_data_data_goes_here_txt");
			type.set ("assets/data/data-goes-here.txt", Reflect.field (AssetType, "text".toUpperCase ()));
			path.set ("assets/images/bar_h.png", "assets_images_bar_h_png");
			type.set ("assets/images/bar_h.png", Reflect.field (AssetType, "image".toUpperCase ()));
			path.set ("assets/images/bar_v.png", "assets_images_bar_v_png");
			type.set ("assets/images/bar_v.png", Reflect.field (AssetType, "image".toUpperCase ()));
			path.set ("assets/images/black.png", "assets_images_black_png");
			type.set ("assets/images/black.png", Reflect.field (AssetType, "image".toUpperCase ()));
			path.set ("assets/images/blackbox.png", "assets_images_blackbox_png");
			type.set ("assets/images/blackbox.png", Reflect.field (AssetType, "image".toUpperCase ()));
			path.set ("assets/images/images-go-here.txt", "assets_images_images_go_here_txt");
			type.set ("assets/images/images-go-here.txt", Reflect.field (AssetType, "text".toUpperCase ()));
			path.set ("assets/images/joystick.png", "assets_images_joystick_png");
			type.set ("assets/images/joystick.png", Reflect.field (AssetType, "image".toUpperCase ()));
			path.set ("assets/images/joystick_big.png", "assets_images_joystick_big_png");
			type.set ("assets/images/joystick_big.png", Reflect.field (AssetType, "image".toUpperCase ()));
			path.set ("assets/images/joystick_ring.png", "assets_images_joystick_ring_png");
			type.set ("assets/images/joystick_ring.png", Reflect.field (AssetType, "image".toUpperCase ()));
			path.set ("assets/images/joystick_ring_big.png", "assets_images_joystick_ring_big_png");
			type.set ("assets/images/joystick_ring_big.png", Reflect.field (AssetType, "image".toUpperCase ()));
			path.set ("assets/images/player.png", "assets_images_player_png");
			type.set ("assets/images/player.png", Reflect.field (AssetType, "image".toUpperCase ()));
			path.set ("assets/levels/0.txt", "assets_levels_0_txt");
			type.set ("assets/levels/0.txt", Reflect.field (AssetType, "text".toUpperCase ()));
			path.set ("assets/levels/1.txt", "assets_levels_1_txt");
			type.set ("assets/levels/1.txt", Reflect.field (AssetType, "text".toUpperCase ()));
			path.set ("assets/levels/10.txt", "assets_levels_10_txt");
			type.set ("assets/levels/10.txt", Reflect.field (AssetType, "text".toUpperCase ()));
			path.set ("assets/levels/11.txt", "assets_levels_11_txt");
			type.set ("assets/levels/11.txt", Reflect.field (AssetType, "text".toUpperCase ()));
			path.set ("assets/levels/2.txt", "assets_levels_2_txt");
			type.set ("assets/levels/2.txt", Reflect.field (AssetType, "text".toUpperCase ()));
			path.set ("assets/levels/3.txt", "assets_levels_3_txt");
			type.set ("assets/levels/3.txt", Reflect.field (AssetType, "text".toUpperCase ()));
			path.set ("assets/levels/4.txt", "assets_levels_4_txt");
			type.set ("assets/levels/4.txt", Reflect.field (AssetType, "text".toUpperCase ()));
			path.set ("assets/levels/5.txt", "assets_levels_5_txt");
			type.set ("assets/levels/5.txt", Reflect.field (AssetType, "text".toUpperCase ()));
			path.set ("assets/levels/6.txt", "assets_levels_6_txt");
			type.set ("assets/levels/6.txt", Reflect.field (AssetType, "text".toUpperCase ()));
			path.set ("assets/levels/7.txt", "assets_levels_7_txt");
			type.set ("assets/levels/7.txt", Reflect.field (AssetType, "text".toUpperCase ()));
			path.set ("assets/levels/8.txt", "assets_levels_8_txt");
			type.set ("assets/levels/8.txt", Reflect.field (AssetType, "text".toUpperCase ()));
			path.set ("assets/levels/9.txt", "assets_levels_9_txt");
			type.set ("assets/levels/9.txt", Reflect.field (AssetType, "text".toUpperCase ()));
			path.set ("assets/music/music-goes-here.txt", "assets_music_music_goes_here_txt");
			type.set ("assets/music/music-goes-here.txt", Reflect.field (AssetType, "text".toUpperCase ()));
			path.set ("assets/sounds/sounds-go-here.txt", "assets_sounds_sounds_go_here_txt");
			type.set ("assets/sounds/sounds-go-here.txt", Reflect.field (AssetType, "text".toUpperCase ()));
			path.set ("assets/tilesets/1.png", "assets_tilesets_1_png");
			type.set ("assets/tilesets/1.png", Reflect.field (AssetType, "image".toUpperCase ()));
			path.set ("assets/tilesets/2.png", "assets_tilesets_2_png");
			type.set ("assets/tilesets/2.png", Reflect.field (AssetType, "image".toUpperCase ()));
			path.set ("assets/sounds/beep.ogg", "assets_sounds_beep_ogg");
			type.set ("assets/sounds/beep.ogg", Reflect.field (AssetType, "sound".toUpperCase ()));
			path.set ("assets/sounds/flixel.ogg", "assets_sounds_flixel_ogg");
			type.set ("assets/sounds/flixel.ogg", Reflect.field (AssetType, "sound".toUpperCase ()));
			path.set ("__manifest__", "manifest");
			type.set ("__manifest__", Reflect.field (AssetType, "text".toUpperCase ()));
			
			
			initialized = true;
			
		} //!initialized
		
	} //initialize
	
	
} //AssetData
