#ifndef INCLUDED_PlayState
#define INCLUDED_PlayState

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <flixel/FlxState.h>
HX_DECLARE_CLASS0(Joystick)
HX_DECLARE_CLASS0(PlayState)
HX_DECLARE_CLASS0(Player)
HX_DECLARE_CLASS1(flixel,FlxBasic)
HX_DECLARE_CLASS1(flixel,FlxObject)
HX_DECLARE_CLASS1(flixel,FlxSprite)
HX_DECLARE_CLASS1(flixel,FlxState)
HX_DECLARE_CLASS2(flixel,group,FlxGroup)
HX_DECLARE_CLASS2(flixel,group,FlxTypedGroup)
HX_DECLARE_CLASS2(flixel,interfaces,IFlxDestroyable)
HX_DECLARE_CLASS2(flixel,tile,FlxTilemap)


class HXCPP_CLASS_ATTRIBUTES  PlayState_obj : public ::flixel::FlxState_obj{
	public:
		typedef ::flixel::FlxState_obj super;
		typedef PlayState_obj OBJ_;
		PlayState_obj();
		Void __construct();

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< PlayState_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~PlayState_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("PlayState"); }

		int mapHeight;
		int mapWidth;
		int gHight;
		int gWidth;
		Float mapx;
		Float mapy;
		::flixel::tile::FlxTilemap levelMap;
		::String mapData;
		::String tileSet;
		::flixel::tile::FlxTilemap nextMap;
		::String nextData;
		::String nextSet;
		::String nextDir;
		Float xScrollSpeed;
		Float yScrollSpeed;
		Float pSSx;
		Float pSSy;
		Float scrollTotalFrames;
		int counter;
		::flixel::group::FlxGroup map;
		::flixel::group::FlxGroup hud;
		::flixel::group::FlxGroup border;
		::flixel::FlxSprite joystickBG;
		::Joystick joystick;
		::flixel::FlxSprite tBox;
		::flixel::FlxSprite bBox;
		::flixel::FlxSprite rBox;
		::flixel::FlxSprite lBox;
		::flixel::FlxSprite blackBox;
		Array< ::Dynamic > bars;
		Float gameZoom;
		::Player player;
		virtual Void create( );

		virtual Void config( );
		Dynamic config_dyn();

		virtual Void buildMap( );
		Dynamic buildMap_dyn();

		virtual Void buildNextMap( );
		Dynamic buildNextMap_dyn();

		virtual Void setupHud( );
		Dynamic setupHud_dyn();

		virtual Void destroy( );

		virtual Void update( );

		virtual Void moveScreens( );
		Dynamic moveScreens_dyn();

		virtual Void finishSroll( );
		Dynamic finishSroll_dyn();

		virtual Void touchEdge( ::flixel::FlxSprite Player,::flixel::FlxSprite Edge);
		Dynamic touchEdge_dyn();

		Array< int > dataArray;
		Array< ::Dynamic > finalArray;
		int arrayPlaceCounter;
		virtual Void convertMapData( );
		Dynamic convertMapData_dyn();

		virtual Void buildHitMap( );
		Dynamic buildHitMap_dyn();

		virtual int isItSolid( int n);
		Dynamic isItSolid_dyn();

		virtual Void traceMaps( );
		Dynamic traceMaps_dyn();

};


#endif /* INCLUDED_PlayState */ 
