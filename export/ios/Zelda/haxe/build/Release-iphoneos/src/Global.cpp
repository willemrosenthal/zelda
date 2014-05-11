#include <hxcpp.h>

#ifndef INCLUDED_Global
#include <Global.h>
#endif
#ifndef INCLUDED_flixel_FlxBasic
#include <flixel/FlxBasic.h>
#endif
#ifndef INCLUDED_flixel_FlxObject
#include <flixel/FlxObject.h>
#endif
#ifndef INCLUDED_flixel_group_FlxGroup
#include <flixel/group/FlxGroup.h>
#endif
#ifndef INCLUDED_flixel_group_FlxTypedGroup
#include <flixel/group/FlxTypedGroup.h>
#endif
#ifndef INCLUDED_flixel_interfaces_IFlxDestroyable
#include <flixel/interfaces/IFlxDestroyable.h>
#endif
#ifndef INCLUDED_flixel_interfaces_IFlxPooled
#include <flixel/interfaces/IFlxPooled.h>
#endif
#ifndef INCLUDED_flixel_tile_FlxTilemap
#include <flixel/tile/FlxTilemap.h>
#endif
#ifndef INCLUDED_flixel_util_FlxPoint
#include <flixel/util/FlxPoint.h>
#endif

Void Global_obj::__construct()
{
HX_STACK_FRAME("Global","new",0x2136c3f5,"Global.new","Global.hx",52,0xfa68b11b)
HX_STACK_THIS(this)
{
}
;
	return null();
}

//Global_obj::~Global_obj() { }

Dynamic Global_obj::__CreateEmpty() { return  new Global_obj; }
hx::ObjectPtr< Global_obj > Global_obj::__new()
{  hx::ObjectPtr< Global_obj > result = new Global_obj();
	result->__construct();
	return result;}

Dynamic Global_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Global_obj > result = new Global_obj();
	result->__construct();
	return result;}

bool Global_obj::ini;

::flixel::util::FlxPoint Global_obj::zeroPoint;

int Global_obj::tileSize;

Array< int > Global_obj::gameTileSize;

Float Global_obj::gameHeight;

Float Global_obj::gameWidth;

bool Global_obj::mouseEnabled;

int Global_obj::firstTouchId;

int Global_obj::secondTouchId;

bool Global_obj::moveTouched;

::flixel::util::FlxPoint Global_obj::firstTouch;

::flixel::util::FlxPoint Global_obj::firstTouchTo;

Float Global_obj::gameZoom;

::flixel::group::FlxGroup Global_obj::game;

Array< int > Global_obj::c;

Array< int > Global_obj::n;

Array< ::Dynamic > Global_obj::cMap;

::flixel::tile::FlxTilemap Global_obj::tMap;

bool Global_obj::changingScreens;

::String Global_obj::nextDir;

::flixel::util::FlxPoint Global_obj::move;

bool Global_obj::UIopen;

Array< ::Dynamic > Global_obj::levels;

Void Global_obj::levelStart( ){
{
		HX_STACK_FRAME("Global","levelStart",0x2fb32949,"Global.levelStart","Global.hx",48,0xfa68b11b)
		HX_STACK_LINE(48)
		::Global_obj::ini = true;
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Global_obj,levelStart,(void))


Global_obj::Global_obj()
{
}

Dynamic Global_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"c") ) { return c; }
		if (HX_FIELD_EQ(inName,"n") ) { return n; }
		break;
	case 3:
		if (HX_FIELD_EQ(inName,"ini") ) { return ini; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"game") ) { return game; }
		if (HX_FIELD_EQ(inName,"cMap") ) { return cMap; }
		if (HX_FIELD_EQ(inName,"tMap") ) { return tMap; }
		if (HX_FIELD_EQ(inName,"move") ) { return move; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"UIopen") ) { return UIopen; }
		if (HX_FIELD_EQ(inName,"levels") ) { return levels; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"nextDir") ) { return nextDir; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"tileSize") ) { return tileSize; }
		if (HX_FIELD_EQ(inName,"gameZoom") ) { return gameZoom; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"zeroPoint") ) { return zeroPoint; }
		if (HX_FIELD_EQ(inName,"gameWidth") ) { return gameWidth; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"gameHeight") ) { return gameHeight; }
		if (HX_FIELD_EQ(inName,"firstTouch") ) { return firstTouch; }
		if (HX_FIELD_EQ(inName,"levelStart") ) { return levelStart_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"moveTouched") ) { return moveTouched; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"gameTileSize") ) { return gameTileSize; }
		if (HX_FIELD_EQ(inName,"mouseEnabled") ) { return mouseEnabled; }
		if (HX_FIELD_EQ(inName,"firstTouchId") ) { return firstTouchId; }
		if (HX_FIELD_EQ(inName,"firstTouchTo") ) { return firstTouchTo; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"secondTouchId") ) { return secondTouchId; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"changingScreens") ) { return changingScreens; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Global_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"c") ) { c=inValue.Cast< Array< int > >(); return inValue; }
		if (HX_FIELD_EQ(inName,"n") ) { n=inValue.Cast< Array< int > >(); return inValue; }
		break;
	case 3:
		if (HX_FIELD_EQ(inName,"ini") ) { ini=inValue.Cast< bool >(); return inValue; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"game") ) { game=inValue.Cast< ::flixel::group::FlxGroup >(); return inValue; }
		if (HX_FIELD_EQ(inName,"cMap") ) { cMap=inValue.Cast< Array< ::Dynamic > >(); return inValue; }
		if (HX_FIELD_EQ(inName,"tMap") ) { tMap=inValue.Cast< ::flixel::tile::FlxTilemap >(); return inValue; }
		if (HX_FIELD_EQ(inName,"move") ) { move=inValue.Cast< ::flixel::util::FlxPoint >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"UIopen") ) { UIopen=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"levels") ) { levels=inValue.Cast< Array< ::Dynamic > >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"nextDir") ) { nextDir=inValue.Cast< ::String >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"tileSize") ) { tileSize=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"gameZoom") ) { gameZoom=inValue.Cast< Float >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"zeroPoint") ) { zeroPoint=inValue.Cast< ::flixel::util::FlxPoint >(); return inValue; }
		if (HX_FIELD_EQ(inName,"gameWidth") ) { gameWidth=inValue.Cast< Float >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"gameHeight") ) { gameHeight=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"firstTouch") ) { firstTouch=inValue.Cast< ::flixel::util::FlxPoint >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"moveTouched") ) { moveTouched=inValue.Cast< bool >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"gameTileSize") ) { gameTileSize=inValue.Cast< Array< int > >(); return inValue; }
		if (HX_FIELD_EQ(inName,"mouseEnabled") ) { mouseEnabled=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"firstTouchId") ) { firstTouchId=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"firstTouchTo") ) { firstTouchTo=inValue.Cast< ::flixel::util::FlxPoint >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"secondTouchId") ) { secondTouchId=inValue.Cast< int >(); return inValue; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"changingScreens") ) { changingScreens=inValue.Cast< bool >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Global_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("ini"),
	HX_CSTRING("zeroPoint"),
	HX_CSTRING("tileSize"),
	HX_CSTRING("gameTileSize"),
	HX_CSTRING("gameHeight"),
	HX_CSTRING("gameWidth"),
	HX_CSTRING("mouseEnabled"),
	HX_CSTRING("firstTouchId"),
	HX_CSTRING("secondTouchId"),
	HX_CSTRING("moveTouched"),
	HX_CSTRING("firstTouch"),
	HX_CSTRING("firstTouchTo"),
	HX_CSTRING("gameZoom"),
	HX_CSTRING("game"),
	HX_CSTRING("c"),
	HX_CSTRING("n"),
	HX_CSTRING("cMap"),
	HX_CSTRING("tMap"),
	HX_CSTRING("changingScreens"),
	HX_CSTRING("nextDir"),
	HX_CSTRING("move"),
	HX_CSTRING("UIopen"),
	HX_CSTRING("levels"),
	HX_CSTRING("levelStart"),
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo *sMemberStorageInfo = 0;
#endif

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Global_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(Global_obj::ini,"ini");
	HX_MARK_MEMBER_NAME(Global_obj::zeroPoint,"zeroPoint");
	HX_MARK_MEMBER_NAME(Global_obj::tileSize,"tileSize");
	HX_MARK_MEMBER_NAME(Global_obj::gameTileSize,"gameTileSize");
	HX_MARK_MEMBER_NAME(Global_obj::gameHeight,"gameHeight");
	HX_MARK_MEMBER_NAME(Global_obj::gameWidth,"gameWidth");
	HX_MARK_MEMBER_NAME(Global_obj::mouseEnabled,"mouseEnabled");
	HX_MARK_MEMBER_NAME(Global_obj::firstTouchId,"firstTouchId");
	HX_MARK_MEMBER_NAME(Global_obj::secondTouchId,"secondTouchId");
	HX_MARK_MEMBER_NAME(Global_obj::moveTouched,"moveTouched");
	HX_MARK_MEMBER_NAME(Global_obj::firstTouch,"firstTouch");
	HX_MARK_MEMBER_NAME(Global_obj::firstTouchTo,"firstTouchTo");
	HX_MARK_MEMBER_NAME(Global_obj::gameZoom,"gameZoom");
	HX_MARK_MEMBER_NAME(Global_obj::game,"game");
	HX_MARK_MEMBER_NAME(Global_obj::c,"c");
	HX_MARK_MEMBER_NAME(Global_obj::n,"n");
	HX_MARK_MEMBER_NAME(Global_obj::cMap,"cMap");
	HX_MARK_MEMBER_NAME(Global_obj::tMap,"tMap");
	HX_MARK_MEMBER_NAME(Global_obj::changingScreens,"changingScreens");
	HX_MARK_MEMBER_NAME(Global_obj::nextDir,"nextDir");
	HX_MARK_MEMBER_NAME(Global_obj::move,"move");
	HX_MARK_MEMBER_NAME(Global_obj::UIopen,"UIopen");
	HX_MARK_MEMBER_NAME(Global_obj::levels,"levels");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Global_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(Global_obj::ini,"ini");
	HX_VISIT_MEMBER_NAME(Global_obj::zeroPoint,"zeroPoint");
	HX_VISIT_MEMBER_NAME(Global_obj::tileSize,"tileSize");
	HX_VISIT_MEMBER_NAME(Global_obj::gameTileSize,"gameTileSize");
	HX_VISIT_MEMBER_NAME(Global_obj::gameHeight,"gameHeight");
	HX_VISIT_MEMBER_NAME(Global_obj::gameWidth,"gameWidth");
	HX_VISIT_MEMBER_NAME(Global_obj::mouseEnabled,"mouseEnabled");
	HX_VISIT_MEMBER_NAME(Global_obj::firstTouchId,"firstTouchId");
	HX_VISIT_MEMBER_NAME(Global_obj::secondTouchId,"secondTouchId");
	HX_VISIT_MEMBER_NAME(Global_obj::moveTouched,"moveTouched");
	HX_VISIT_MEMBER_NAME(Global_obj::firstTouch,"firstTouch");
	HX_VISIT_MEMBER_NAME(Global_obj::firstTouchTo,"firstTouchTo");
	HX_VISIT_MEMBER_NAME(Global_obj::gameZoom,"gameZoom");
	HX_VISIT_MEMBER_NAME(Global_obj::game,"game");
	HX_VISIT_MEMBER_NAME(Global_obj::c,"c");
	HX_VISIT_MEMBER_NAME(Global_obj::n,"n");
	HX_VISIT_MEMBER_NAME(Global_obj::cMap,"cMap");
	HX_VISIT_MEMBER_NAME(Global_obj::tMap,"tMap");
	HX_VISIT_MEMBER_NAME(Global_obj::changingScreens,"changingScreens");
	HX_VISIT_MEMBER_NAME(Global_obj::nextDir,"nextDir");
	HX_VISIT_MEMBER_NAME(Global_obj::move,"move");
	HX_VISIT_MEMBER_NAME(Global_obj::UIopen,"UIopen");
	HX_VISIT_MEMBER_NAME(Global_obj::levels,"levels");
};

#endif

Class Global_obj::__mClass;

void Global_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("Global"), hx::TCanCast< Global_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics
#ifdef HXCPP_VISIT_ALLOCS
    , sVisitStatics
#endif
#ifdef HXCPP_SCRIPTABLE
    , sMemberStorageInfo
#endif
);
}

void Global_obj::__boot()
{
	tileSize= (int)16;
	gameTileSize= Array_obj< int >::__new().Add((int)0).Add((int)0);
	firstTouchId= (int)-1;
	secondTouchId= (int)-1;
	c= Array_obj< int >::__new().Add((int)0).Add((int)0);
	n= Array_obj< int >::__new().Add((int)0).Add((int)0);
	move= ::flixel::util::FlxPoint_obj::__new((int)0,(int)0);
	UIopen= false;
	levels= Array_obj< ::Dynamic >::__new().Add(Array_obj< int >::__new().Add((int)0).Add((int)1).Add((int)2).Add((int)3)).Add(Array_obj< int >::__new().Add((int)4).Add((int)5).Add((int)6).Add((int)7)).Add(Array_obj< int >::__new().Add((int)8).Add((int)9).Add((int)10).Add((int)11));
}

