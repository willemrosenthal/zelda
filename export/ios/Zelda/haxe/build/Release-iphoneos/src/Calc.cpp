#include <hxcpp.h>

#ifndef INCLUDED_Calc
#include <Calc.h>
#endif
#ifndef INCLUDED_Global
#include <Global.h>
#endif
#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_flixel_FlxG
#include <flixel/FlxG.h>
#endif
#ifndef INCLUDED_flixel_interfaces_IFlxDestroyable
#include <flixel/interfaces/IFlxDestroyable.h>
#endif
#ifndef INCLUDED_flixel_interfaces_IFlxPooled
#include <flixel/interfaces/IFlxPooled.h>
#endif
#ifndef INCLUDED_flixel_util_FlxPoint
#include <flixel/util/FlxPoint.h>
#endif
#ifndef INCLUDED_hxMath
#include <hxMath.h>
#endif

Void Calc_obj::__construct()
{
HX_STACK_FRAME("Calc","new",0x07c7e427,"Calc.new","Calc.hx",38,0x1b961d29)
HX_STACK_THIS(this)
{
}
;
	return null();
}

//Calc_obj::~Calc_obj() { }

Dynamic Calc_obj::__CreateEmpty() { return  new Calc_obj; }
hx::ObjectPtr< Calc_obj > Calc_obj::__new()
{  hx::ObjectPtr< Calc_obj > result = new Calc_obj();
	result->__construct();
	return result;}

Dynamic Calc_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Calc_obj > result = new Calc_obj();
	result->__construct();
	return result;}

::flixel::util::FlxPoint Calc_obj::randomOnScreen( hx::Null< Float >  __o_Padding,hx::Null< Float >  __o_PaddingY){
Float Padding = __o_Padding.Default(0);
Float PaddingY = __o_PaddingY.Default(0);
	HX_STACK_FRAME("Calc","randomOnScreen",0x3e0e4ea7,"Calc.randomOnScreen","Calc.hx",8,0x1b961d29)
	HX_STACK_ARG(Padding,"Padding")
	HX_STACK_ARG(PaddingY,"PaddingY")
{
		HX_STACK_LINE(9)
		Float _g = ::Math_obj::random();		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(9)
		Float _g1 = (((::flixel::FlxG_obj::width - Padding)) * _g);		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(9)
		Float _g2 = (_g1 + (Padding * 0.5));		HX_STACK_VAR(_g2,"_g2");
		HX_STACK_LINE(9)
		Float _g3 = ::Math_obj::random();		HX_STACK_VAR(_g3,"_g3");
		HX_STACK_LINE(9)
		Float _g4 = (((::flixel::FlxG_obj::height - PaddingY)) * _g3);		HX_STACK_VAR(_g4,"_g4");
		HX_STACK_LINE(9)
		Float _g5 = (_g4 + (PaddingY * 0.5));		HX_STACK_VAR(_g5,"_g5");
		HX_STACK_LINE(9)
		::flixel::util::FlxPoint pos = ::flixel::util::FlxPoint_obj::__new(_g2,_g5);		HX_STACK_VAR(pos,"pos");
		HX_STACK_LINE(10)
		return pos;
	}
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Calc_obj,randomOnScreen,return )

Float Calc_obj::plusOrMinus( hx::Null< Float >  __o_Value){
Float Value = __o_Value.Default(1);
	HX_STACK_FRAME("Calc","plusOrMinus",0x20042ada,"Calc.plusOrMinus","Calc.hx",14,0x1b961d29)
	HX_STACK_ARG(Value,"Value")
{
		HX_STACK_LINE(15)
		Float _g = ::Math_obj::random();		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(15)
		int _g1 = ::Math_obj::round(_g);		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(15)
		int _g2 = (_g1 * (int)2);		HX_STACK_VAR(_g2,"_g2");
		HX_STACK_LINE(15)
		int _g3 = (_g2 - (int)1);		HX_STACK_VAR(_g3,"_g3");
		HX_STACK_LINE(15)
		return (_g3 * Value);
	}
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Calc_obj,plusOrMinus,return )

::flixel::util::FlxPoint Calc_obj::pt;

int Calc_obj::getTileType( Float X,Float Y){
	HX_STACK_FRAME("Calc","getTileType",0x2cea8e85,"Calc.getTileType","Calc.hx",21,0x1b961d29)
	HX_STACK_ARG(X,"X")
	HX_STACK_ARG(Y,"Y")
	HX_STACK_LINE(22)
	::flixel::util::FlxPoint _g = ::Calc_obj::getTilePos(X,Y);		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(22)
	::Calc_obj::pt = _g;
	HX_STACK_LINE(23)
	if (((bool((::Global_obj::cMap->length > ::Calc_obj::pt->y)) && bool((::Global_obj::cMap->__get(::Std_obj::_int(::Calc_obj::pt->y)).StaticCast< Array< int > >()->length > ::Calc_obj::pt->x))))){
		HX_STACK_LINE(24)
		int _g1 = ::Std_obj::_int(::Calc_obj::pt->y);		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(24)
		Array< int > _g2 = ::Global_obj::cMap->__get(_g1).StaticCast< Array< int > >();		HX_STACK_VAR(_g2,"_g2");
		HX_STACK_LINE(24)
		int _g3 = ::Std_obj::_int(::Calc_obj::pt->x);		HX_STACK_VAR(_g3,"_g3");
		HX_STACK_LINE(24)
		return _g2->__get(_g3);
	}
	else{
		HX_STACK_LINE(25)
		return (int)0;
	}
	HX_STACK_LINE(23)
	return (int)0;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Calc_obj,getTileType,return )

::flixel::util::FlxPoint Calc_obj::getTileValue( Float X,Float Y){
	HX_STACK_FRAME("Calc","getTileValue",0x373f3546,"Calc.getTileValue","Calc.hx",30,0x1b961d29)
	HX_STACK_ARG(X,"X")
	HX_STACK_ARG(Y,"Y")
	HX_STACK_LINE(30)
	return ::flixel::util::FlxPoint_obj::__new((Float(X) / Float(::Global_obj::tileSize)),(Float(Y) / Float(::Global_obj::tileSize)));
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Calc_obj,getTileValue,return )

::flixel::util::FlxPoint Calc_obj::getTilePos( Float X,Float Y){
	HX_STACK_FRAME("Calc","getTilePos",0x58958429,"Calc.getTilePos","Calc.hx",35,0x1b961d29)
	HX_STACK_ARG(X,"X")
	HX_STACK_ARG(Y,"Y")
	HX_STACK_LINE(35)
	return ::flixel::util::FlxPoint_obj::__new((Float(X) / Float(::Global_obj::tileSize)),(Float(Y) / Float(::Global_obj::tileSize)));
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Calc_obj,getTilePos,return )


Calc_obj::Calc_obj()
{
}

Dynamic Calc_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 2:
		if (HX_FIELD_EQ(inName,"pt") ) { return pt; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"getTilePos") ) { return getTilePos_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"plusOrMinus") ) { return plusOrMinus_dyn(); }
		if (HX_FIELD_EQ(inName,"getTileType") ) { return getTileType_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"getTileValue") ) { return getTileValue_dyn(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"randomOnScreen") ) { return randomOnScreen_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Calc_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 2:
		if (HX_FIELD_EQ(inName,"pt") ) { pt=inValue.Cast< ::flixel::util::FlxPoint >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Calc_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("randomOnScreen"),
	HX_CSTRING("plusOrMinus"),
	HX_CSTRING("pt"),
	HX_CSTRING("getTileType"),
	HX_CSTRING("getTileValue"),
	HX_CSTRING("getTilePos"),
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo *sMemberStorageInfo = 0;
#endif

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Calc_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(Calc_obj::pt,"pt");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Calc_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(Calc_obj::pt,"pt");
};

#endif

Class Calc_obj::__mClass;

void Calc_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("Calc"), hx::TCanCast< Calc_obj> ,sStaticFields,sMemberFields,
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

void Calc_obj::__boot()
{
}

