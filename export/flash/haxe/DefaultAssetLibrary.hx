package;


import flash.display.Bitmap;
import flash.display.BitmapData;
import flash.display.MovieClip;
import flash.text.Font;
import flash.media.Sound;
import flash.net.URLRequest;
import flash.utils.ByteArray;
import haxe.Unserializer;
import openfl.Assets;

#if (flash || js)
import flash.display.Loader;
import flash.events.Event;
import flash.net.URLLoader;
#end

#if ios
import openfl.utils.SystemPath;
#end


@:access(flash.media.Sound)
class DefaultAssetLibrary extends AssetLibrary {
	
	
	public static var className (default, null) = new Map <String, Dynamic> ();
	public static var path (default, null) = new Map <String, String> ();
	public static var type (default, null) = new Map <String, AssetType> ();
	
	public function new () {
		
		super ();
		
		#if flash
		
		className.set ("assets/data/data-goes-here.txt", __ASSET__assets_data_data_goes_here_txt);
		type.set ("assets/data/data-goes-here.txt", Reflect.field (AssetType, "text".toUpperCase ()));
		className.set ("assets/images/bar_h.png", __ASSET__assets_images_bar_h_png);
		type.set ("assets/images/bar_h.png", Reflect.field (AssetType, "image".toUpperCase ()));
		className.set ("assets/images/bar_v.png", __ASSET__assets_images_bar_v_png);
		type.set ("assets/images/bar_v.png", Reflect.field (AssetType, "image".toUpperCase ()));
		className.set ("assets/images/black.png", __ASSET__assets_images_black_png);
		type.set ("assets/images/black.png", Reflect.field (AssetType, "image".toUpperCase ()));
		className.set ("assets/images/blackbox.png", __ASSET__assets_images_blackbox_png);
		type.set ("assets/images/blackbox.png", Reflect.field (AssetType, "image".toUpperCase ()));
		className.set ("assets/images/images-go-here.txt", __ASSET__assets_images_images_go_here_txt);
		type.set ("assets/images/images-go-here.txt", Reflect.field (AssetType, "text".toUpperCase ()));
		className.set ("assets/images/joystick.png", __ASSET__assets_images_joystick_png);
		type.set ("assets/images/joystick.png", Reflect.field (AssetType, "image".toUpperCase ()));
		className.set ("assets/images/joystick_big.png", __ASSET__assets_images_joystick_big_png);
		type.set ("assets/images/joystick_big.png", Reflect.field (AssetType, "image".toUpperCase ()));
		className.set ("assets/images/joystick_ring.png", __ASSET__assets_images_joystick_ring_png);
		type.set ("assets/images/joystick_ring.png", Reflect.field (AssetType, "image".toUpperCase ()));
		className.set ("assets/images/joystick_ring_big.png", __ASSET__assets_images_joystick_ring_big_png);
		type.set ("assets/images/joystick_ring_big.png", Reflect.field (AssetType, "image".toUpperCase ()));
		className.set ("assets/images/player.png", __ASSET__assets_images_player_png);
		type.set ("assets/images/player.png", Reflect.field (AssetType, "image".toUpperCase ()));
		className.set ("assets/levels/0.txt", __ASSET__assets_levels_0_txt);
		type.set ("assets/levels/0.txt", Reflect.field (AssetType, "text".toUpperCase ()));
		className.set ("assets/levels/1.txt", __ASSET__assets_levels_1_txt);
		type.set ("assets/levels/1.txt", Reflect.field (AssetType, "text".toUpperCase ()));
		className.set ("assets/levels/10.txt", __ASSET__assets_levels_10_txt);
		type.set ("assets/levels/10.txt", Reflect.field (AssetType, "text".toUpperCase ()));
		className.set ("assets/levels/11.txt", __ASSET__assets_levels_11_txt);
		type.set ("assets/levels/11.txt", Reflect.field (AssetType, "text".toUpperCase ()));
		className.set ("assets/levels/2.txt", __ASSET__assets_levels_2_txt);
		type.set ("assets/levels/2.txt", Reflect.field (AssetType, "text".toUpperCase ()));
		className.set ("assets/levels/3.txt", __ASSET__assets_levels_3_txt);
		type.set ("assets/levels/3.txt", Reflect.field (AssetType, "text".toUpperCase ()));
		className.set ("assets/levels/4.txt", __ASSET__assets_levels_4_txt);
		type.set ("assets/levels/4.txt", Reflect.field (AssetType, "text".toUpperCase ()));
		className.set ("assets/levels/5.txt", __ASSET__assets_levels_5_txt);
		type.set ("assets/levels/5.txt", Reflect.field (AssetType, "text".toUpperCase ()));
		className.set ("assets/levels/6.txt", __ASSET__assets_levels_6_txt);
		type.set ("assets/levels/6.txt", Reflect.field (AssetType, "text".toUpperCase ()));
		className.set ("assets/levels/7.txt", __ASSET__assets_levels_7_txt);
		type.set ("assets/levels/7.txt", Reflect.field (AssetType, "text".toUpperCase ()));
		className.set ("assets/levels/8.txt", __ASSET__assets_levels_8_txt);
		type.set ("assets/levels/8.txt", Reflect.field (AssetType, "text".toUpperCase ()));
		className.set ("assets/levels/9.txt", __ASSET__assets_levels_9_txt);
		type.set ("assets/levels/9.txt", Reflect.field (AssetType, "text".toUpperCase ()));
		className.set ("assets/music/music-goes-here.txt", __ASSET__assets_music_music_goes_here_txt);
		type.set ("assets/music/music-goes-here.txt", Reflect.field (AssetType, "text".toUpperCase ()));
		className.set ("assets/sounds/sounds-go-here.txt", __ASSET__assets_sounds_sounds_go_here_txt);
		type.set ("assets/sounds/sounds-go-here.txt", Reflect.field (AssetType, "text".toUpperCase ()));
		className.set ("assets/tilesets/1.png", __ASSET__assets_tilesets_1_png);
		type.set ("assets/tilesets/1.png", Reflect.field (AssetType, "image".toUpperCase ()));
		className.set ("assets/tilesets/2.png", __ASSET__assets_tilesets_2_png);
		type.set ("assets/tilesets/2.png", Reflect.field (AssetType, "image".toUpperCase ()));
		className.set ("assets/sounds/beep.mp3", __ASSET__assets_sounds_beep_mp3);
		type.set ("assets/sounds/beep.mp3", Reflect.field (AssetType, "music".toUpperCase ()));
		className.set ("assets/sounds/flixel.mp3", __ASSET__assets_sounds_flixel_mp3);
		type.set ("assets/sounds/flixel.mp3", Reflect.field (AssetType, "music".toUpperCase ()));
		
		
		#elseif html5
		
		addExternal("assets/data/data-goes-here.txt", "text", "assets/data/data-goes-here.txt");
		addExternal("assets/images/bar_h.png", "image", "assets/images/bar_h.png");
		addExternal("assets/images/bar_v.png", "image", "assets/images/bar_v.png");
		addExternal("assets/images/black.png", "image", "assets/images/black.png");
		addExternal("assets/images/blackbox.png", "image", "assets/images/blackbox.png");
		addExternal("assets/images/images-go-here.txt", "text", "assets/images/images-go-here.txt");
		addExternal("assets/images/joystick.png", "image", "assets/images/joystick.png");
		addExternal("assets/images/joystick_big.png", "image", "assets/images/joystick_big.png");
		addExternal("assets/images/joystick_ring.png", "image", "assets/images/joystick_ring.png");
		addExternal("assets/images/joystick_ring_big.png", "image", "assets/images/joystick_ring_big.png");
		addExternal("assets/images/player.png", "image", "assets/images/player.png");
		addExternal("assets/levels/0.txt", "text", "assets/levels/0.txt");
		addExternal("assets/levels/1.txt", "text", "assets/levels/1.txt");
		addExternal("assets/levels/10.txt", "text", "assets/levels/10.txt");
		addExternal("assets/levels/11.txt", "text", "assets/levels/11.txt");
		addExternal("assets/levels/2.txt", "text", "assets/levels/2.txt");
		addExternal("assets/levels/3.txt", "text", "assets/levels/3.txt");
		addExternal("assets/levels/4.txt", "text", "assets/levels/4.txt");
		addExternal("assets/levels/5.txt", "text", "assets/levels/5.txt");
		addExternal("assets/levels/6.txt", "text", "assets/levels/6.txt");
		addExternal("assets/levels/7.txt", "text", "assets/levels/7.txt");
		addExternal("assets/levels/8.txt", "text", "assets/levels/8.txt");
		addExternal("assets/levels/9.txt", "text", "assets/levels/9.txt");
		addExternal("assets/music/music-goes-here.txt", "text", "assets/music/music-goes-here.txt");
		addExternal("assets/sounds/sounds-go-here.txt", "text", "assets/sounds/sounds-go-here.txt");
		addExternal("assets/tilesets/1.png", "image", "assets/tilesets/1.png");
		addExternal("assets/tilesets/2.png", "image", "assets/tilesets/2.png");
		addExternal("assets/sounds/beep.mp3", "music", "assets/sounds/beep.mp3");
		addExternal("assets/sounds/flixel.mp3", "music", "assets/sounds/flixel.mp3");
		
		
		#else
		
		#if (windows || mac || linux)
		
		var loadManifest = false;
		
		className.set ("assets/data/data-goes-here.txt", __ASSET__assets_data_data_goes_here_txt);
		type.set ("assets/data/data-goes-here.txt", Reflect.field (AssetType, "text".toUpperCase ()));
		
		className.set ("assets/images/bar_h.png", __ASSET__assets_images_bar_h_png);
		type.set ("assets/images/bar_h.png", Reflect.field (AssetType, "image".toUpperCase ()));
		
		className.set ("assets/images/bar_v.png", __ASSET__assets_images_bar_v_png);
		type.set ("assets/images/bar_v.png", Reflect.field (AssetType, "image".toUpperCase ()));
		
		className.set ("assets/images/black.png", __ASSET__assets_images_black_png);
		type.set ("assets/images/black.png", Reflect.field (AssetType, "image".toUpperCase ()));
		
		className.set ("assets/images/blackbox.png", __ASSET__assets_images_blackbox_png);
		type.set ("assets/images/blackbox.png", Reflect.field (AssetType, "image".toUpperCase ()));
		
		className.set ("assets/images/images-go-here.txt", __ASSET__assets_images_images_go_here_txt);
		type.set ("assets/images/images-go-here.txt", Reflect.field (AssetType, "text".toUpperCase ()));
		
		className.set ("assets/images/joystick.png", __ASSET__assets_images_joystick_png);
		type.set ("assets/images/joystick.png", Reflect.field (AssetType, "image".toUpperCase ()));
		
		className.set ("assets/images/joystick_big.png", __ASSET__assets_images_joystick_big_png);
		type.set ("assets/images/joystick_big.png", Reflect.field (AssetType, "image".toUpperCase ()));
		
		className.set ("assets/images/joystick_ring.png", __ASSET__assets_images_joystick_ring_png);
		type.set ("assets/images/joystick_ring.png", Reflect.field (AssetType, "image".toUpperCase ()));
		
		className.set ("assets/images/joystick_ring_big.png", __ASSET__assets_images_joystick_ring_big_png);
		type.set ("assets/images/joystick_ring_big.png", Reflect.field (AssetType, "image".toUpperCase ()));
		
		className.set ("assets/images/player.png", __ASSET__assets_images_player_png);
		type.set ("assets/images/player.png", Reflect.field (AssetType, "image".toUpperCase ()));
		
		className.set ("assets/levels/0.txt", __ASSET__assets_levels_0_txt);
		type.set ("assets/levels/0.txt", Reflect.field (AssetType, "text".toUpperCase ()));
		
		className.set ("assets/levels/1.txt", __ASSET__assets_levels_1_txt);
		type.set ("assets/levels/1.txt", Reflect.field (AssetType, "text".toUpperCase ()));
		
		className.set ("assets/levels/10.txt", __ASSET__assets_levels_10_txt);
		type.set ("assets/levels/10.txt", Reflect.field (AssetType, "text".toUpperCase ()));
		
		className.set ("assets/levels/11.txt", __ASSET__assets_levels_11_txt);
		type.set ("assets/levels/11.txt", Reflect.field (AssetType, "text".toUpperCase ()));
		
		className.set ("assets/levels/2.txt", __ASSET__assets_levels_2_txt);
		type.set ("assets/levels/2.txt", Reflect.field (AssetType, "text".toUpperCase ()));
		
		className.set ("assets/levels/3.txt", __ASSET__assets_levels_3_txt);
		type.set ("assets/levels/3.txt", Reflect.field (AssetType, "text".toUpperCase ()));
		
		className.set ("assets/levels/4.txt", __ASSET__assets_levels_4_txt);
		type.set ("assets/levels/4.txt", Reflect.field (AssetType, "text".toUpperCase ()));
		
		className.set ("assets/levels/5.txt", __ASSET__assets_levels_5_txt);
		type.set ("assets/levels/5.txt", Reflect.field (AssetType, "text".toUpperCase ()));
		
		className.set ("assets/levels/6.txt", __ASSET__assets_levels_6_txt);
		type.set ("assets/levels/6.txt", Reflect.field (AssetType, "text".toUpperCase ()));
		
		className.set ("assets/levels/7.txt", __ASSET__assets_levels_7_txt);
		type.set ("assets/levels/7.txt", Reflect.field (AssetType, "text".toUpperCase ()));
		
		className.set ("assets/levels/8.txt", __ASSET__assets_levels_8_txt);
		type.set ("assets/levels/8.txt", Reflect.field (AssetType, "text".toUpperCase ()));
		
		className.set ("assets/levels/9.txt", __ASSET__assets_levels_9_txt);
		type.set ("assets/levels/9.txt", Reflect.field (AssetType, "text".toUpperCase ()));
		
		className.set ("assets/music/music-goes-here.txt", __ASSET__assets_music_music_goes_here_txt);
		type.set ("assets/music/music-goes-here.txt", Reflect.field (AssetType, "text".toUpperCase ()));
		
		className.set ("assets/sounds/sounds-go-here.txt", __ASSET__assets_sounds_sounds_go_here_txt);
		type.set ("assets/sounds/sounds-go-here.txt", Reflect.field (AssetType, "text".toUpperCase ()));
		
		className.set ("assets/tilesets/1.png", __ASSET__assets_tilesets_1_png);
		type.set ("assets/tilesets/1.png", Reflect.field (AssetType, "image".toUpperCase ()));
		
		className.set ("assets/tilesets/2.png", __ASSET__assets_tilesets_2_png);
		type.set ("assets/tilesets/2.png", Reflect.field (AssetType, "image".toUpperCase ()));
		
		className.set ("assets/sounds/beep.mp3", __ASSET__assets_sounds_beep_mp3);
		type.set ("assets/sounds/beep.mp3", Reflect.field (AssetType, "music".toUpperCase ()));
		
		className.set ("assets/sounds/flixel.mp3", __ASSET__assets_sounds_flixel_mp3);
		type.set ("assets/sounds/flixel.mp3", Reflect.field (AssetType, "music".toUpperCase ()));
		
		
		#else
		
		var loadManifest = true;
		
		#end
		
		if (loadManifest) {
			try {
				
				#if blackberry
				var bytes = ByteArray.readFile ("app/native/manifest");
				#elseif tizen
				var bytes = ByteArray.readFile ("../res/manifest");
				#elseif emscripten
				var bytes = ByteArray.readFile ("assets/manifest");
				#else
				var bytes = ByteArray.readFile ("manifest");
				#end
				
				if (bytes != null) {
					
					bytes.position = 0;
					
					if (bytes.length > 0) {
						
						var data = bytes.readUTFBytes (bytes.length);
						
						if (data != null && data.length > 0) {
							
							var manifest:Array<AssetData> = Unserializer.run (data);
							
							for (asset in manifest) {
								
								if (!className.exists(asset.id)) {
									
									path.set (asset.id, asset.path);
									type.set (asset.id, asset.type);
									
								}
							}
						
						}
					
					}
				
				} else {
				
					trace ("Warning: Could not load asset manifest");
				
				}
			
			} catch (e:Dynamic) {
			
				trace ("Warning: Could not load asset manifest");
			
			}
		
		}
		
		#end
		
	}
	
	
	#if html5
	private function addEmbed(id:String, kind:String, value:Dynamic):Void {
		className.set(id, value);
		type.set(id, Reflect.field(AssetType, kind.toUpperCase()));
	}
	
	
	private function addExternal(id:String, kind:String, value:String):Void {
		path.set(id, value);
		type.set(id, Reflect.field(AssetType, kind.toUpperCase()));
	}
	#end
	
	
	public override function exists (id:String, type:AssetType):Bool {
		
		var assetType = DefaultAssetLibrary.type.get (id);
		
		#if pixi
		
		if (assetType == IMAGE) {
			
			return true;
			
		} else {
			
			return false;
			
		}
		
		#end
		
		if (assetType != null) {
			
			if (assetType == type || ((type == SOUND || type == MUSIC) && (assetType == MUSIC || assetType == SOUND))) {
				
				return true;
				
			}
			
			#if flash
			
			if ((assetType == BINARY || assetType == TEXT) && type == BINARY) {
				
				return true;
				
			} else if (path.exists (id)) {
				
				return true;
				
			}
			
			#else
			
			if (type == BINARY || type == null) {
				
				return true;
				
			}
			
			#end
			
		}
		
		return false;
		
	}
	
	
	public override function getBitmapData (id:String):BitmapData {
		
		#if pixi
		
		return BitmapData.fromImage (path.get (id));
		
		#elseif (flash)
		
		return cast (Type.createInstance (className.get (id), []), BitmapData);
		
		#elseif openfl_html5
		
		return BitmapData.fromImage (ApplicationMain.images.get (path.get (id)));
		
		#elseif js
		
		return cast (ApplicationMain.loaders.get (path.get (id)).contentLoaderInfo.content, Bitmap).bitmapData;
		
		#else
		
		if (className.exists(id)) return cast (Type.createInstance (className.get (id), []), BitmapData);
		else return BitmapData.load (path.get (id));
		
		#end
		
	}
	
	
	public override function getBytes (id:String):ByteArray {
		
		#if pixi
		
		return null;
		
		#elseif (flash)
		
		return cast (Type.createInstance (className.get (id), []), ByteArray);
		
		#elseif openfl_html5
		
		return null;
		
		#elseif js
		
		var bytes:ByteArray = null;
		var data = ApplicationMain.urlLoaders.get (path.get (id)).data;
		
		if (Std.is (data, String)) {
			
			bytes = new ByteArray ();
			bytes.writeUTFBytes (data);
			
		} else if (Std.is (data, ByteArray)) {
			
			bytes = cast data;
			
		} else {
			
			bytes = null;
			
		}

		if (bytes != null) {
			
			bytes.position = 0;
			return bytes;
			
		} else {
			
			return null;
		}
		
		#else
		
		if (className.exists(id)) return cast (Type.createInstance (className.get (id), []), ByteArray);
		else return ByteArray.readFile (path.get (id));
		
		#end
		
	}
	
	
	public override function getFont (id:String):Font {
		
		#if pixi
		
		return null;
		
		#elseif (flash || js)
		
		return cast (Type.createInstance (className.get (id), []), Font);
		
		#else
		
		if (className.exists(id)) {
			var fontClass = className.get(id);
			Font.registerFont(fontClass);
			return cast (Type.createInstance (fontClass, []), Font);
		} else return new Font (path.get (id));
		
		#end
		
	}
	
	
	public override function getMusic (id:String):Sound {
		
		#if pixi
		
		return null;
		
		#elseif (flash)
		
		return cast (Type.createInstance (className.get (id), []), Sound);
		
		#elseif openfl_html5
		
		var sound = new Sound ();
		sound.__buffer = true;
		sound.load (new URLRequest (path.get (id)));
		return sound; 
		
		#elseif js
		
		return new Sound (new URLRequest (path.get (id)));
		
		#else
		
		if (className.exists(id)) return cast (Type.createInstance (className.get (id), []), Sound);
		else return new Sound (new URLRequest (path.get (id)), null, true);
		
		#end
		
	}
	
	
	public override function getPath (id:String):String {
		
		#if ios
		
		return SystemPath.applicationDirectory + "/assets/" + path.get (id);
		
		#else
		
		return path.get (id);
		
		#end
		
	}
	
	
	public override function getSound (id:String):Sound {
		
		#if pixi
		
		return null;
		
		#elseif (flash)
		
		return cast (Type.createInstance (className.get (id), []), Sound);
		
		#elseif js
		
		return new Sound (new URLRequest (path.get (id)));
		
		#else
		
		if (className.exists(id)) return cast (Type.createInstance (className.get (id), []), Sound);
		else return new Sound (new URLRequest (path.get (id)), null, type.get (id) == MUSIC);
		
		#end
		
	}
	
	
	public override function getText (id:String):String {
		
		#if js
		
		var bytes:ByteArray = null;
		var data = ApplicationMain.urlLoaders.get (path.get (id)).data;
		
		if (Std.is (data, String)) {
			
			return cast data;
			
		} else if (Std.is (data, ByteArray)) {
			
			bytes = cast data;
			
		} else {
			
			bytes = null;
			
		}
		
		if (bytes != null) {
			
			bytes.position = 0;
			return bytes.readUTFBytes (bytes.length);
			
		} else {
			
			return null;
		}
		
		#else
		
		var bytes = getBytes (id);
		
		if (bytes == null) {
			
			return null;
			
		} else {
			
			return bytes.readUTFBytes (bytes.length);
			
		}
		
		#end
		
	}
	
	
	public override function isLocal (id:String, type:AssetType):Bool {
		
		#if flash
		
		if (type != AssetType.MUSIC && type != AssetType.SOUND) {
			
			return className.exists (id);
			
		}
		
		#end
		
		return true;
		
	}
	
	
	public override function loadBitmapData (id:String, handler:BitmapData -> Void):Void {
		
		#if pixi
		
		handler (getBitmapData (id));
		
		#elseif (flash || js)
		
		if (path.exists (id)) {
			
			var loader = new Loader ();
			loader.contentLoaderInfo.addEventListener (Event.COMPLETE, function (event:Event) {
				
				handler (cast (event.currentTarget.content, Bitmap).bitmapData);
				
			});
			loader.load (new URLRequest (path.get (id)));
			
		} else {
			
			handler (getBitmapData (id));
			
		}
		
		#else
		
		handler (getBitmapData (id));
		
		#end
		
	}
	
	
	public override function loadBytes (id:String, handler:ByteArray -> Void):Void {
		
		#if pixi
		
		handler (getBytes (id));
		
		#elseif (flash || js)
		
		if (path.exists (id)) {
			
			var loader = new URLLoader ();
			loader.addEventListener (Event.COMPLETE, function (event:Event) {
				
				var bytes = new ByteArray ();
				bytes.writeUTFBytes (event.currentTarget.data);
				bytes.position = 0;
				
				handler (bytes);
				
			});
			loader.load (new URLRequest (path.get (id)));
			
		} else {
			
			handler (getBytes (id));
			
		}
		
		#else
		
		handler (getBytes (id));
		
		#end
		
	}
	
	
	public override function loadFont (id:String, handler:Font -> Void):Void {
		
		#if (flash || js)
		
		/*if (path.exists (id)) {
			
			var loader = new Loader ();
			loader.contentLoaderInfo.addEventListener (Event.COMPLETE, function (event) {
				
				handler (cast (event.currentTarget.content, Bitmap).bitmapData);
				
			});
			loader.load (new URLRequest (path.get (id)));
			
		} else {*/
			
			handler (getFont (id));
			
		//}
		
		#else
		
		handler (getFont (id));
		
		#end
		
	}
	
	
	public override function loadMusic (id:String, handler:Sound -> Void):Void {
		
		#if (flash || js)
		
		/*if (path.exists (id)) {
			
			var loader = new Loader ();
			loader.contentLoaderInfo.addEventListener (Event.COMPLETE, function (event) {
				
				handler (cast (event.currentTarget.content, Bitmap).bitmapData);
				
			});
			loader.load (new URLRequest (path.get (id)));
			
		} else {*/
			
			handler (getMusic (id));
			
		//}
		
		#else
		
		handler (getMusic (id));
		
		#end
		
	}
	
	
	public override function loadSound (id:String, handler:Sound -> Void):Void {
		
		#if (flash || js)
		
		/*if (path.exists (id)) {
			
			var loader = new Loader ();
			loader.contentLoaderInfo.addEventListener (Event.COMPLETE, function (event) {
				
				handler (cast (event.currentTarget.content, Bitmap).bitmapData);
				
			});
			loader.load (new URLRequest (path.get (id)));
			
		} else {*/
			
			handler (getSound (id));
			
		//}
		
		#else
		
		handler (getSound (id));
		
		#end
		
	}
	
	
	public override function loadText (id:String, handler:String -> Void):Void {
		
		#if js
		
		if (path.exists (id)) {
			
			var loader = new URLLoader ();
			loader.addEventListener (Event.COMPLETE, function (event:Event) {
				
				handler (event.currentTarget.data);
				
			});
			loader.load (new URLRequest (path.get (id)));
			
		} else {
			
			handler (getText (id));
			
		}
		
		#else
		
		var callback = function (bytes:ByteArray):Void {
			
			if (bytes == null) {
				
				handler (null);
				
			} else {
				
				handler (bytes.readUTFBytes (bytes.length));
				
			}
			
		}
		
		loadBytes (id, callback);
		
		#end
		
	}
	
	
}


#if pixi
#elseif flash

@:keep class __ASSET__assets_data_data_goes_here_txt extends flash.utils.ByteArray { }
@:keep class __ASSET__assets_images_bar_h_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep class __ASSET__assets_images_bar_v_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep class __ASSET__assets_images_black_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep class __ASSET__assets_images_blackbox_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep class __ASSET__assets_images_images_go_here_txt extends flash.utils.ByteArray { }
@:keep class __ASSET__assets_images_joystick_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep class __ASSET__assets_images_joystick_big_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep class __ASSET__assets_images_joystick_ring_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep class __ASSET__assets_images_joystick_ring_big_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep class __ASSET__assets_images_player_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep class __ASSET__assets_levels_0_txt extends flash.utils.ByteArray { }
@:keep class __ASSET__assets_levels_1_txt extends flash.utils.ByteArray { }
@:keep class __ASSET__assets_levels_10_txt extends flash.utils.ByteArray { }
@:keep class __ASSET__assets_levels_11_txt extends flash.utils.ByteArray { }
@:keep class __ASSET__assets_levels_2_txt extends flash.utils.ByteArray { }
@:keep class __ASSET__assets_levels_3_txt extends flash.utils.ByteArray { }
@:keep class __ASSET__assets_levels_4_txt extends flash.utils.ByteArray { }
@:keep class __ASSET__assets_levels_5_txt extends flash.utils.ByteArray { }
@:keep class __ASSET__assets_levels_6_txt extends flash.utils.ByteArray { }
@:keep class __ASSET__assets_levels_7_txt extends flash.utils.ByteArray { }
@:keep class __ASSET__assets_levels_8_txt extends flash.utils.ByteArray { }
@:keep class __ASSET__assets_levels_9_txt extends flash.utils.ByteArray { }
@:keep class __ASSET__assets_music_music_goes_here_txt extends flash.utils.ByteArray { }
@:keep class __ASSET__assets_sounds_sounds_go_here_txt extends flash.utils.ByteArray { }
@:keep class __ASSET__assets_tilesets_1_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep class __ASSET__assets_tilesets_2_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep class __ASSET__assets_sounds_beep_mp3 extends flash.media.Sound { }
@:keep class __ASSET__assets_sounds_flixel_mp3 extends flash.media.Sound { }


#elseif html5
































#elseif (windows || mac || linux)


@:file("assets/data/data-goes-here.txt") class __ASSET__assets_data_data_goes_here_txt extends flash.utils.ByteArray {}
@:bitmap("assets/images/bar_h.png") class __ASSET__assets_images_bar_h_png extends flash.display.BitmapData {}
@:bitmap("assets/images/bar_v.png") class __ASSET__assets_images_bar_v_png extends flash.display.BitmapData {}
@:bitmap("assets/images/black.png") class __ASSET__assets_images_black_png extends flash.display.BitmapData {}
@:bitmap("assets/images/blackbox.png") class __ASSET__assets_images_blackbox_png extends flash.display.BitmapData {}
@:file("assets/images/images-go-here.txt") class __ASSET__assets_images_images_go_here_txt extends flash.utils.ByteArray {}
@:bitmap("assets/images/joystick.png") class __ASSET__assets_images_joystick_png extends flash.display.BitmapData {}
@:bitmap("assets/images/joystick_big.png") class __ASSET__assets_images_joystick_big_png extends flash.display.BitmapData {}
@:bitmap("assets/images/joystick_ring.png") class __ASSET__assets_images_joystick_ring_png extends flash.display.BitmapData {}
@:bitmap("assets/images/joystick_ring_big.png") class __ASSET__assets_images_joystick_ring_big_png extends flash.display.BitmapData {}
@:bitmap("assets/images/player.png") class __ASSET__assets_images_player_png extends flash.display.BitmapData {}
@:file("assets/levels/0.txt") class __ASSET__assets_levels_0_txt extends flash.utils.ByteArray {}
@:file("assets/levels/1.txt") class __ASSET__assets_levels_1_txt extends flash.utils.ByteArray {}
@:file("assets/levels/10.txt") class __ASSET__assets_levels_10_txt extends flash.utils.ByteArray {}
@:file("assets/levels/11.txt") class __ASSET__assets_levels_11_txt extends flash.utils.ByteArray {}
@:file("assets/levels/2.txt") class __ASSET__assets_levels_2_txt extends flash.utils.ByteArray {}
@:file("assets/levels/3.txt") class __ASSET__assets_levels_3_txt extends flash.utils.ByteArray {}
@:file("assets/levels/4.txt") class __ASSET__assets_levels_4_txt extends flash.utils.ByteArray {}
@:file("assets/levels/5.txt") class __ASSET__assets_levels_5_txt extends flash.utils.ByteArray {}
@:file("assets/levels/6.txt") class __ASSET__assets_levels_6_txt extends flash.utils.ByteArray {}
@:file("assets/levels/7.txt") class __ASSET__assets_levels_7_txt extends flash.utils.ByteArray {}
@:file("assets/levels/8.txt") class __ASSET__assets_levels_8_txt extends flash.utils.ByteArray {}
@:file("assets/levels/9.txt") class __ASSET__assets_levels_9_txt extends flash.utils.ByteArray {}
@:file("assets/music/music-goes-here.txt") class __ASSET__assets_music_music_goes_here_txt extends flash.utils.ByteArray {}
@:file("assets/sounds/sounds-go-here.txt") class __ASSET__assets_sounds_sounds_go_here_txt extends flash.utils.ByteArray {}
@:bitmap("assets/tilesets/1.png") class __ASSET__assets_tilesets_1_png extends flash.display.BitmapData {}
@:bitmap("assets/tilesets/2.png") class __ASSET__assets_tilesets_2_png extends flash.display.BitmapData {}
@:sound("/usr/lib/haxe/lib/flixel/3,3,3/assets/sounds/beep.mp3") class __ASSET__assets_sounds_beep_mp3 extends flash.media.Sound {}
@:sound("/usr/lib/haxe/lib/flixel/3,3,3/assets/sounds/flixel.mp3") class __ASSET__assets_sounds_flixel_mp3 extends flash.media.Sound {}


#end
