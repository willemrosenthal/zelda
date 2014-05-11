#include <hxcpp.h>

#ifndef INCLUDED_Calc
#include <Calc.h>
#endif
#ifndef INCLUDED_Global
#include <Global.h>
#endif
#ifndef INCLUDED_Player
#include <Player.h>
#endif
#ifndef INCLUDED_flixel_FlxBasic
#include <flixel/FlxBasic.h>
#endif
#ifndef INCLUDED_flixel_FlxG
#include <flixel/FlxG.h>
#endif
#ifndef INCLUDED_flixel_FlxObject
#include <flixel/FlxObject.h>
#endif
#ifndef INCLUDED_flixel_FlxSprite
#include <flixel/FlxSprite.h>
#endif
#ifndef INCLUDED_flixel_animation_FlxAnimation
#include <flixel/animation/FlxAnimation.h>
#endif
#ifndef INCLUDED_flixel_animation_FlxAnimationController
#include <flixel/animation/FlxAnimationController.h>
#endif
#ifndef INCLUDED_flixel_animation_FlxBaseAnimation
#include <flixel/animation/FlxBaseAnimation.h>
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
#ifndef INCLUDED_haxe_Log
#include <haxe/Log.h>
#endif
#ifndef INCLUDED_hxMath
#include <hxMath.h>
#endif

Void Player_obj::__construct(Float X,Float Y)
{
HX_STACK_FRAME("Player","new",0x8d5554f3,"Player.new","Player.hx",7,0xa27fc9dd)
HX_STACK_THIS(this)
HX_STACK_ARG(X,"X")
HX_STACK_ARG(Y,"Y")
{
	HX_STACK_LINE(13)
	this->cAnim = HX_CSTRING("down");
	HX_STACK_LINE(12)
	this->dir = HX_CSTRING("down");
	HX_STACK_LINE(10)
	this->maxSpeed = (int)80;
	HX_STACK_LINE(17)
	super::__construct(X,Y,null());
	HX_STACK_LINE(19)
	this->loadGraphic(HX_CSTRING("assets/images/player.png"),true,(int)16,(int)16,null(),null());
	HX_STACK_LINE(20)
	this->animation->add(HX_CSTRING("down"),Array_obj< int >::__new().Add((int)0).Add((int)1),(int)6,null());
	HX_STACK_LINE(21)
	this->animation->add(HX_CSTRING("left"),Array_obj< int >::__new().Add((int)2).Add((int)3),(int)6,null());
	HX_STACK_LINE(22)
	this->animation->add(HX_CSTRING("up"),Array_obj< int >::__new().Add((int)4).Add((int)5),(int)6,null());
	HX_STACK_LINE(23)
	this->animation->add(HX_CSTRING("right"),Array_obj< int >::__new().Add((int)6).Add((int)7),(int)6,null());
	HX_STACK_LINE(24)
	this->animation->add(HX_CSTRING("stop_down"),Array_obj< int >::__new().Add((int)0),null(),null());
	HX_STACK_LINE(25)
	this->animation->add(HX_CSTRING("stop_left"),Array_obj< int >::__new().Add((int)2),null(),null());
	HX_STACK_LINE(26)
	this->animation->add(HX_CSTRING("stop_up"),Array_obj< int >::__new().Add((int)4),null(),null());
	HX_STACK_LINE(27)
	this->animation->add(HX_CSTRING("stop_right"),Array_obj< int >::__new().Add((int)6),null(),null());
	HX_STACK_LINE(29)
	::flixel::util::FlxPoint _g = ::flixel::util::FlxPoint_obj::__new(null(),null());		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(29)
	this->speed = _g;
}
;
	return null();
}

//Player_obj::~Player_obj() { }

Dynamic Player_obj::__CreateEmpty() { return  new Player_obj; }
hx::ObjectPtr< Player_obj > Player_obj::__new(Float X,Float Y)
{  hx::ObjectPtr< Player_obj > result = new Player_obj();
	result->__construct(X,Y);
	return result;}

Dynamic Player_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Player_obj > result = new Player_obj();
	result->__construct(inArgs[0],inArgs[1]);
	return result;}

Void Player_obj::update( ){
{
		HX_STACK_FRAME("Player","update",0xf1f8df56,"Player.update","Player.hx",34,0xa27fc9dd)
		HX_STACK_THIS(this)
		HX_STACK_LINE(35)
		this->super::update();
		HX_STACK_LINE(37)
		this->speed->set_x((int)0);
		HX_STACK_LINE(38)
		this->speed->set_y((int)0);
		HX_STACK_LINE(40)
		if ((::Global_obj::changingScreens)){
			HX_STACK_LINE(41)
			this->animation->play(::Global_obj::nextDir,null(),null());
			HX_STACK_LINE(42)
			return null();
		}
		HX_STACK_LINE(46)
		if (((bool((::Global_obj::move->x != (int)0)) || bool((::Global_obj::move->y != (int)0))))){
			HX_STACK_LINE(48)
			this->speed->set_x((::Global_obj::move->x * this->maxSpeed));
			HX_STACK_LINE(49)
			this->speed->set_y((::Global_obj::move->y * this->maxSpeed));
		}
		HX_STACK_LINE(53)
		if (((bool((::Global_obj::move->x == (int)0)) || bool((::Global_obj::move->y == (int)0))))){
			HX_STACK_LINE(55)
			this->animation->play((HX_CSTRING("stop_") + this->cAnim),null(),null());
		}
		HX_STACK_LINE(57)
		Float _g = ::Math_obj::abs(this->speed->x);		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(57)
		Float _g1 = ::Math_obj::abs(this->speed->y);		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(57)
		if (((_g > _g1))){
			HX_STACK_LINE(59)
			if (((this->speed->x > (int)0))){
				HX_STACK_LINE(60)
				this->animation->play(HX_CSTRING("right"),null(),null());
			}
			HX_STACK_LINE(61)
			if (((this->speed->x < (int)0))){
				HX_STACK_LINE(62)
				this->animation->play(HX_CSTRING("left"),null(),null());
			}
			struct _Function_2_1{
				inline static ::flixel::animation::FlxAnimation Block( hx::ObjectPtr< ::Player_obj > __this){
					HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","Player.hx",63,0xa27fc9dd)
					{
						HX_STACK_LINE(63)
						::flixel::animation::FlxAnimationController _this = __this->animation;		HX_STACK_VAR(_this,"_this");
						HX_STACK_LINE(63)
						::flixel::animation::FlxAnimation anim = null();		HX_STACK_VAR(anim,"anim");
						HX_STACK_LINE(63)
						if (((bool((bool((_this->_curAnim != null())) && bool((_this->_curAnim->delay > (int)0)))) && bool(((bool(_this->_curAnim->looped) || bool(!(_this->_curAnim->finished)))))))){
							HX_STACK_LINE(63)
							anim = _this->_curAnim;
						}
						HX_STACK_LINE(63)
						return anim;
					}
					return null();
				}
			};
			HX_STACK_LINE(63)
			this->cAnim = (_Function_2_1::Block(this))->name;
		}
		else{
			HX_STACK_LINE(65)
			Float _g2 = ::Math_obj::abs(this->speed->x);		HX_STACK_VAR(_g2,"_g2");
			HX_STACK_LINE(65)
			Float _g3 = ::Math_obj::abs(this->speed->y);		HX_STACK_VAR(_g3,"_g3");
			HX_STACK_LINE(65)
			if (((_g2 < _g3))){
				HX_STACK_LINE(67)
				if (((this->speed->y > (int)0))){
					HX_STACK_LINE(68)
					this->animation->play(HX_CSTRING("down"),null(),null());
				}
				HX_STACK_LINE(69)
				if (((this->speed->y < (int)0))){
					HX_STACK_LINE(70)
					this->animation->play(HX_CSTRING("up"),null(),null());
				}
				struct _Function_3_1{
					inline static ::flixel::animation::FlxAnimation Block( hx::ObjectPtr< ::Player_obj > __this){
						HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","Player.hx",71,0xa27fc9dd)
						{
							HX_STACK_LINE(71)
							::flixel::animation::FlxAnimationController _this = __this->animation;		HX_STACK_VAR(_this,"_this");
							HX_STACK_LINE(71)
							::flixel::animation::FlxAnimation anim = null();		HX_STACK_VAR(anim,"anim");
							HX_STACK_LINE(71)
							if (((bool((bool((_this->_curAnim != null())) && bool((_this->_curAnim->delay > (int)0)))) && bool(((bool(_this->_curAnim->looped) || bool(!(_this->_curAnim->finished)))))))){
								HX_STACK_LINE(71)
								anim = _this->_curAnim;
							}
							HX_STACK_LINE(71)
							return anim;
						}
						return null();
					}
				};
				HX_STACK_LINE(71)
				this->cAnim = (_Function_3_1::Block(this))->name;
			}
		}
		HX_STACK_LINE(74)
		{
			HX_STACK_LINE(74)
			::Player _g2 = hx::ObjectPtr<OBJ_>(this);		HX_STACK_VAR(_g2,"_g2");
			HX_STACK_LINE(74)
			_g2->set_x((_g2->x + (this->speed->x * ::flixel::FlxG_obj::elapsed)));
		}
		HX_STACK_LINE(75)
		{
			HX_STACK_LINE(75)
			::Player _g2 = hx::ObjectPtr<OBJ_>(this);		HX_STACK_VAR(_g2,"_g2");
			HX_STACK_LINE(75)
			_g2->set_y((_g2->y + (this->speed->y * ::flixel::FlxG_obj::elapsed)));
		}
		HX_STACK_LINE(77)
		Float _g4 = this->get_height();		HX_STACK_VAR(_g4,"_g4");
		HX_STACK_LINE(77)
		Float _g5 = (_g4 * 0.5);		HX_STACK_VAR(_g5,"_g5");
		HX_STACK_LINE(77)
		Float _g6 = (this->x + _g5);		HX_STACK_VAR(_g6,"_g6");
		HX_STACK_LINE(77)
		Float _g7 = this->get_height();		HX_STACK_VAR(_g7,"_g7");
		HX_STACK_LINE(77)
		Float _g8 = (_g7 * 0.5);		HX_STACK_VAR(_g8,"_g8");
		HX_STACK_LINE(77)
		Float _g9 = (this->y + _g8);		HX_STACK_VAR(_g9,"_g9");
		HX_STACK_LINE(77)
		int _g10 = ::Calc_obj::getTileType(_g6,_g9);		HX_STACK_VAR(_g10,"_g10");
		HX_STACK_LINE(77)
		::haxe::Log_obj::trace(_g10,hx::SourceInfo(HX_CSTRING("Player.hx"),77,HX_CSTRING("Player"),HX_CSTRING("update")));
	}
return null();
}



Player_obj::Player_obj()
{
}

void Player_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Player);
	HX_MARK_MEMBER_NAME(maxSpeed,"maxSpeed");
	HX_MARK_MEMBER_NAME(speed,"speed");
	HX_MARK_MEMBER_NAME(dir,"dir");
	HX_MARK_MEMBER_NAME(cAnim,"cAnim");
	::flixel::FlxSprite_obj::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void Player_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(maxSpeed,"maxSpeed");
	HX_VISIT_MEMBER_NAME(speed,"speed");
	HX_VISIT_MEMBER_NAME(dir,"dir");
	HX_VISIT_MEMBER_NAME(cAnim,"cAnim");
	::flixel::FlxSprite_obj::__Visit(HX_VISIT_ARG);
}

Dynamic Player_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"dir") ) { return dir; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"speed") ) { return speed; }
		if (HX_FIELD_EQ(inName,"cAnim") ) { return cAnim; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"update") ) { return update_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"maxSpeed") ) { return maxSpeed; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Player_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"dir") ) { dir=inValue.Cast< ::String >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"speed") ) { speed=inValue.Cast< ::flixel::util::FlxPoint >(); return inValue; }
		if (HX_FIELD_EQ(inName,"cAnim") ) { cAnim=inValue.Cast< ::String >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"maxSpeed") ) { maxSpeed=inValue.Cast< Float >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Player_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("maxSpeed"));
	outFields->push(HX_CSTRING("speed"));
	outFields->push(HX_CSTRING("dir"));
	outFields->push(HX_CSTRING("cAnim"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsFloat,(int)offsetof(Player_obj,maxSpeed),HX_CSTRING("maxSpeed")},
	{hx::fsObject /*::flixel::util::FlxPoint*/ ,(int)offsetof(Player_obj,speed),HX_CSTRING("speed")},
	{hx::fsString,(int)offsetof(Player_obj,dir),HX_CSTRING("dir")},
	{hx::fsString,(int)offsetof(Player_obj,cAnim),HX_CSTRING("cAnim")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("maxSpeed"),
	HX_CSTRING("speed"),
	HX_CSTRING("dir"),
	HX_CSTRING("cAnim"),
	HX_CSTRING("update"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Player_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Player_obj::__mClass,"__mClass");
};

#endif

Class Player_obj::__mClass;

void Player_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("Player"), hx::TCanCast< Player_obj> ,sStaticFields,sMemberFields,
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

void Player_obj::__boot()
{
}

