#include <hxcpp.h>

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
	HX_STACK_LINE(20)
	super::__construct(X,Y,null());
	HX_STACK_LINE(22)
	this->loadGraphic(HX_CSTRING("assets/images/player.png"),true,(int)16,(int)16,null(),null());
	HX_STACK_LINE(23)
	this->animation->add(HX_CSTRING("down"),Array_obj< int >::__new().Add((int)0).Add((int)1),(int)6,null());
	HX_STACK_LINE(24)
	this->animation->add(HX_CSTRING("left"),Array_obj< int >::__new().Add((int)2).Add((int)3),(int)6,null());
	HX_STACK_LINE(25)
	this->animation->add(HX_CSTRING("up"),Array_obj< int >::__new().Add((int)4).Add((int)5),(int)6,null());
	HX_STACK_LINE(26)
	this->animation->add(HX_CSTRING("right"),Array_obj< int >::__new().Add((int)6).Add((int)7),(int)6,null());
	HX_STACK_LINE(27)
	this->animation->add(HX_CSTRING("stop_down"),Array_obj< int >::__new().Add((int)0),null(),null());
	HX_STACK_LINE(28)
	this->animation->add(HX_CSTRING("stop_left"),Array_obj< int >::__new().Add((int)2),null(),null());
	HX_STACK_LINE(29)
	this->animation->add(HX_CSTRING("stop_up"),Array_obj< int >::__new().Add((int)4),null(),null());
	HX_STACK_LINE(30)
	this->animation->add(HX_CSTRING("stop_right"),Array_obj< int >::__new().Add((int)6),null(),null());
	HX_STACK_LINE(32)
	::flixel::util::FlxPoint _g = ::flixel::util::FlxPoint_obj::__new(null(),null());		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(32)
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
		HX_STACK_FRAME("Player","update",0xf1f8df56,"Player.update","Player.hx",37,0xa27fc9dd)
		HX_STACK_THIS(this)
		HX_STACK_LINE(38)
		this->super::update();
		HX_STACK_LINE(40)
		this->speed->set_x((int)0);
		HX_STACK_LINE(41)
		this->speed->set_y((int)0);
		HX_STACK_LINE(43)
		if ((::Global_obj::changingScreens)){
			HX_STACK_LINE(44)
			this->animation->play(::Global_obj::nextDir,null(),null());
			HX_STACK_LINE(45)
			return null();
		}
		HX_STACK_LINE(49)
		if (((bool((::Global_obj::move->x != (int)0)) || bool((::Global_obj::move->y != (int)0))))){
			HX_STACK_LINE(51)
			this->speed->set_x((::Global_obj::move->x * this->maxSpeed));
			HX_STACK_LINE(52)
			this->speed->set_y((::Global_obj::move->y * this->maxSpeed));
		}
		HX_STACK_LINE(56)
		if (((bool((::Global_obj::move->x == (int)0)) || bool((::Global_obj::move->y == (int)0))))){
			HX_STACK_LINE(58)
			this->animation->play((HX_CSTRING("stop_") + this->cAnim),null(),null());
		}
		HX_STACK_LINE(60)
		Float _g = ::Math_obj::abs(this->speed->x);		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(60)
		Float _g1 = ::Math_obj::abs(this->speed->y);		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(60)
		if (((_g > _g1))){
			HX_STACK_LINE(62)
			if (((this->speed->x > (int)0))){
				HX_STACK_LINE(63)
				this->animation->play(HX_CSTRING("right"),null(),null());
			}
			HX_STACK_LINE(64)
			if (((this->speed->x < (int)0))){
				HX_STACK_LINE(65)
				this->animation->play(HX_CSTRING("left"),null(),null());
			}
			struct _Function_2_1{
				inline static ::flixel::animation::FlxAnimation Block( hx::ObjectPtr< ::Player_obj > __this){
					HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","Player.hx",66,0xa27fc9dd)
					{
						HX_STACK_LINE(66)
						::flixel::animation::FlxAnimationController _this = __this->animation;		HX_STACK_VAR(_this,"_this");
						HX_STACK_LINE(66)
						::flixel::animation::FlxAnimation anim = null();		HX_STACK_VAR(anim,"anim");
						HX_STACK_LINE(66)
						if (((bool((bool((_this->_curAnim != null())) && bool((_this->_curAnim->delay > (int)0)))) && bool(((bool(_this->_curAnim->looped) || bool(!(_this->_curAnim->finished)))))))){
							HX_STACK_LINE(66)
							anim = _this->_curAnim;
						}
						HX_STACK_LINE(66)
						return anim;
					}
					return null();
				}
			};
			HX_STACK_LINE(66)
			this->cAnim = (_Function_2_1::Block(this))->name;
		}
		else{
			HX_STACK_LINE(68)
			Float _g2 = ::Math_obj::abs(this->speed->x);		HX_STACK_VAR(_g2,"_g2");
			HX_STACK_LINE(68)
			Float _g3 = ::Math_obj::abs(this->speed->y);		HX_STACK_VAR(_g3,"_g3");
			HX_STACK_LINE(68)
			if (((_g2 < _g3))){
				HX_STACK_LINE(70)
				if (((this->speed->y > (int)0))){
					HX_STACK_LINE(71)
					this->animation->play(HX_CSTRING("down"),null(),null());
				}
				HX_STACK_LINE(72)
				if (((this->speed->y < (int)0))){
					HX_STACK_LINE(73)
					this->animation->play(HX_CSTRING("up"),null(),null());
				}
				struct _Function_3_1{
					inline static ::flixel::animation::FlxAnimation Block( hx::ObjectPtr< ::Player_obj > __this){
						HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","Player.hx",74,0xa27fc9dd)
						{
							HX_STACK_LINE(74)
							::flixel::animation::FlxAnimationController _this = __this->animation;		HX_STACK_VAR(_this,"_this");
							HX_STACK_LINE(74)
							::flixel::animation::FlxAnimation anim = null();		HX_STACK_VAR(anim,"anim");
							HX_STACK_LINE(74)
							if (((bool((bool((_this->_curAnim != null())) && bool((_this->_curAnim->delay > (int)0)))) && bool(((bool(_this->_curAnim->looped) || bool(!(_this->_curAnim->finished)))))))){
								HX_STACK_LINE(74)
								anim = _this->_curAnim;
							}
							HX_STACK_LINE(74)
							return anim;
						}
						return null();
					}
				};
				HX_STACK_LINE(74)
				this->cAnim = (_Function_3_1::Block(this))->name;
			}
		}
		HX_STACK_LINE(80)
		this->xChange = (this->speed->x * ::flixel::FlxG_obj::elapsed);
		HX_STACK_LINE(81)
		this->yChange = (this->speed->y * ::flixel::FlxG_obj::elapsed);
		HX_STACK_LINE(83)
		this->stopAtEdges();
		HX_STACK_LINE(85)
		{
			HX_STACK_LINE(85)
			::Player _g2 = hx::ObjectPtr<OBJ_>(this);		HX_STACK_VAR(_g2,"_g2");
			HX_STACK_LINE(85)
			_g2->set_x((_g2->x + this->xChange));
		}
		HX_STACK_LINE(86)
		{
			HX_STACK_LINE(86)
			::Player _g2 = hx::ObjectPtr<OBJ_>(this);		HX_STACK_VAR(_g2,"_g2");
			HX_STACK_LINE(86)
			_g2->set_y((_g2->y + this->yChange));
		}
	}
return null();
}


Void Player_obj::stopAtEdges( ){
{
		HX_STACK_FRAME("Player","stopAtEdges",0x0092a354,"Player.stopAtEdges","Player.hx",92,0xa27fc9dd)
		HX_STACK_THIS(this)
		HX_STACK_LINE(95)
		if (((bool((bool((this->xChange < (int)0)) && bool(((Float(((this->x + this->xChange))) / Float(::Global_obj::tileSize)) < (int)0)))) && bool((::Global_obj::c->__get((int)1) == (int)0))))){
			HX_STACK_LINE(96)
			this->xChange = (int)0;
		}
		struct _Function_1_1{
			inline static bool Block( hx::ObjectPtr< ::Player_obj > __this){
				HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","Player.hx",98,0xa27fc9dd)
				{
					HX_STACK_LINE(98)
					Float _g = __this->get_width();		HX_STACK_VAR(_g,"_g");
					HX_STACK_LINE(98)
					Float _g1 = (__this->x + _g);		HX_STACK_VAR(_g1,"_g1");
					HX_STACK_LINE(98)
					Float _g2 = (_g1 + __this->xChange);		HX_STACK_VAR(_g2,"_g2");
					HX_STACK_LINE(98)
					Float _g3 = (Float(_g2) / Float(::Global_obj::tileSize));		HX_STACK_VAR(_g3,"_g3");
					HX_STACK_LINE(98)
					return (_g3 > ::Global_obj::gameTileSize->__get((int)0));
				}
				return null();
			}
		};
		HX_STACK_LINE(98)
		if (((  (((  (((this->xChange > (int)0))) ? bool(_Function_1_1::Block(this)) : bool(false) ))) ? bool((::Global_obj::c->__get((int)1) == (::Global_obj::levels->__get((int)0).StaticCast< Array< int > >()->length - (int)1))) : bool(false) ))){
			HX_STACK_LINE(99)
			this->xChange = (int)0;
		}
		HX_STACK_LINE(101)
		if (((bool((bool((this->yChange < (int)0)) && bool(((Float(((this->y + this->yChange))) / Float(::Global_obj::tileSize)) < (int)0)))) && bool((::Global_obj::c->__get((int)0) == (int)0))))){
			HX_STACK_LINE(102)
			this->yChange = (int)0;
		}
		struct _Function_1_2{
			inline static bool Block( hx::ObjectPtr< ::Player_obj > __this){
				HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","Player.hx",104,0xa27fc9dd)
				{
					HX_STACK_LINE(104)
					Float _g4 = __this->get_height();		HX_STACK_VAR(_g4,"_g4");
					HX_STACK_LINE(104)
					Float _g5 = (__this->y + _g4);		HX_STACK_VAR(_g5,"_g5");
					HX_STACK_LINE(104)
					Float _g6 = (_g5 + __this->yChange);		HX_STACK_VAR(_g6,"_g6");
					HX_STACK_LINE(104)
					Float _g7 = (Float(_g6) / Float(::Global_obj::tileSize));		HX_STACK_VAR(_g7,"_g7");
					HX_STACK_LINE(104)
					return (_g7 > ::Global_obj::gameTileSize->__get((int)1));
				}
				return null();
			}
		};
		HX_STACK_LINE(104)
		if (((  (((  (((this->yChange > (int)0))) ? bool(_Function_1_2::Block(this)) : bool(false) ))) ? bool((::Global_obj::c->__get((int)0) == (::Global_obj::levels->length - (int)1))) : bool(false) ))){
			HX_STACK_LINE(105)
			this->yChange = (int)0;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Player_obj,stopAtEdges,(void))


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
	HX_MARK_MEMBER_NAME(xChange,"xChange");
	HX_MARK_MEMBER_NAME(yChange,"yChange");
	::flixel::FlxSprite_obj::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void Player_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(maxSpeed,"maxSpeed");
	HX_VISIT_MEMBER_NAME(speed,"speed");
	HX_VISIT_MEMBER_NAME(dir,"dir");
	HX_VISIT_MEMBER_NAME(cAnim,"cAnim");
	HX_VISIT_MEMBER_NAME(xChange,"xChange");
	HX_VISIT_MEMBER_NAME(yChange,"yChange");
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
	case 7:
		if (HX_FIELD_EQ(inName,"xChange") ) { return xChange; }
		if (HX_FIELD_EQ(inName,"yChange") ) { return yChange; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"maxSpeed") ) { return maxSpeed; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"stopAtEdges") ) { return stopAtEdges_dyn(); }
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
	case 7:
		if (HX_FIELD_EQ(inName,"xChange") ) { xChange=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"yChange") ) { yChange=inValue.Cast< Float >(); return inValue; }
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
	outFields->push(HX_CSTRING("xChange"));
	outFields->push(HX_CSTRING("yChange"));
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
	{hx::fsFloat,(int)offsetof(Player_obj,xChange),HX_CSTRING("xChange")},
	{hx::fsFloat,(int)offsetof(Player_obj,yChange),HX_CSTRING("yChange")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("maxSpeed"),
	HX_CSTRING("speed"),
	HX_CSTRING("dir"),
	HX_CSTRING("cAnim"),
	HX_CSTRING("xChange"),
	HX_CSTRING("yChange"),
	HX_CSTRING("update"),
	HX_CSTRING("stopAtEdges"),
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

