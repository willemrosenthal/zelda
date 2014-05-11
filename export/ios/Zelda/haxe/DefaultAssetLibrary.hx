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
		
		
		#elseif html5
		
		
		
		#else
		
		#if (windows || mac || linux)
		
		var loadManifest = false;
		loadManifest = true;
		loadManifest = true;
		loadManifest = true;
		loadManifest = true;
		loadManifest = true;
		loadManifest = true;
		loadManifest = true;
		loadManifest = true;
		loadManifest = true;
		loadManifest = true;
		loadManifest = true;
		loadManifest = true;
		loadManifest = true;
		loadManifest = true;
		loadManifest = true;
		loadManifest = true;
		loadManifest = true;
		loadManifest = true;
		loadManifest = true;
		loadManifest = true;
		loadManifest = true;
		loadManifest = true;
		loadManifest = true;
		loadManifest = true;
		loadManifest = true;
		loadManifest = true;
		loadManifest = true;
		loadManifest = true;
		loadManifest = true;
		loadManifest = true;
		
		
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

































#elseif html5

































#elseif (windows || mac || linux)




#end
