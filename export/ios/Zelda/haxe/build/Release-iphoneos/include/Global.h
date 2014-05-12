#ifndef INCLUDED_Global
#define INCLUDED_Global

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS0(Global)
HX_DECLARE_CLASS1(flixel,FlxBasic)
HX_DECLARE_CLASS1(flixel,FlxObject)
HX_DECLARE_CLASS2(flixel,group,FlxGroup)
HX_DECLARE_CLASS2(flixel,group,FlxTypedGroup)
HX_DECLARE_CLASS2(flixel,interfaces,IFlxDestroyable)
HX_DECLARE_CLASS2(flixel,interfaces,IFlxPooled)
HX_DECLARE_CLASS2(flixel,tile,FlxTilemap)
HX_DECLARE_CLASS2(flixel,util,FlxPoint)


class HXCPP_CLASS_ATTRIBUTES  Global_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Global_obj OBJ_;
		Global_obj();
		Void __construct();

	public:
		inline void *operator new( size_t inSize, bool inContainer=false)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< Global_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~Global_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		::String __ToString() const { return HX_CSTRING("Global"); }

		static bool ini;
		static ::flixel::util::FlxPoint zeroPoint;
		static int tileSize;
		static Array< int > gameTileSize;
		static Float gameHeight;
		static Float gameWidth;
		static bool mouseEnabled;
		static int firstTouchId;
		static int secondTouchId;
		static bool moveTouched;
		static ::flixel::util::FlxPoint firstTouch;
		static ::flixel::util::FlxPoint firstTouchTo;
		static Float gameZoom;
		static ::flixel::group::FlxGroup game;
		static Array< int > c;
		static Array< int > n;
		static Array< ::Dynamic > cMap;
		static Array< ::Dynamic > hMap;
		static ::flixel::tile::FlxTilemap tMap;
		static bool changingScreens;
		static ::String nextDir;
		static ::flixel::util::FlxPoint move;
		static bool UIopen;
		static Array< ::Dynamic > levels;
		static Void levelStart( );
		static Dynamic levelStart_dyn();

};


#endif /* INCLUDED_Global */ 
