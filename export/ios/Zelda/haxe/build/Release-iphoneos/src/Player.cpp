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
	HX_STACK_LINE(22)
	super::__construct(X,Y,null());
	HX_STACK_LINE(24)
	this->loadGraphic(HX_CSTRING("assets/images/player.png"),true,(int)16,(int)17,null(),null());
	HX_STACK_LINE(25)
	this->animation->add(HX_CSTRING("down"),Array_obj< int >::__new().Add((int)0).Add((int)1),(int)6,null());
	HX_STACK_LINE(26)
	this->animation->add(HX_CSTRING("left"),Array_obj< int >::__new().Add((int)2).Add((int)3),(int)6,null());
	HX_STACK_LINE(27)
	this->animation->add(HX_CSTRING("up"),Array_obj< int >::__new().Add((int)4).Add((int)5),(int)6,null());
	HX_STACK_LINE(28)
	this->animation->add(HX_CSTRING("right"),Array_obj< int >::__new().Add((int)6).Add((int)7),(int)6,null());
	HX_STACK_LINE(29)
	this->animation->add(HX_CSTRING("stop_down"),Array_obj< int >::__new().Add((int)0),null(),null());
	HX_STACK_LINE(30)
	this->animation->add(HX_CSTRING("stop_left"),Array_obj< int >::__new().Add((int)2),null(),null());
	HX_STACK_LINE(31)
	this->animation->add(HX_CSTRING("stop_up"),Array_obj< int >::__new().Add((int)4),null(),null());
	HX_STACK_LINE(32)
	this->animation->add(HX_CSTRING("stop_right"),Array_obj< int >::__new().Add((int)6),null(),null());
	HX_STACK_LINE(34)
	::flixel::util::FlxPoint _g = ::flixel::util::FlxPoint_obj::__new(null(),null());		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(34)
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
		HX_STACK_FRAME("Player","update",0xf1f8df56,"Player.update","Player.hx",39,0xa27fc9dd)
		HX_STACK_THIS(this)
		HX_STACK_LINE(40)
		this->super::update();
		HX_STACK_LINE(42)
		this->speed->set_x((int)0);
		HX_STACK_LINE(43)
		this->speed->set_y((int)0);
		HX_STACK_LINE(45)
		if ((::Global_obj::changingScreens)){
			HX_STACK_LINE(46)
			this->animation->play(::Global_obj::nextDir,null(),null());
			HX_STACK_LINE(47)
			return null();
		}
		HX_STACK_LINE(51)
		if (((bool((::Global_obj::move->x != (int)0)) || bool((::Global_obj::move->y != (int)0))))){
			HX_STACK_LINE(53)
			this->speed->set_x((::Global_obj::move->x * this->maxSpeed));
			HX_STACK_LINE(54)
			this->speed->set_y((::Global_obj::move->y * this->maxSpeed));
		}
		HX_STACK_LINE(58)
		if ((this->knock)){
			HX_STACK_LINE(60)
			this->animation->play(this->cAnim,null(),null());
		}
		else{
			HX_STACK_LINE(62)
			if (((bool((::Global_obj::move->x == (int)0)) || bool((::Global_obj::move->y == (int)0))))){
				HX_STACK_LINE(64)
				this->animation->play((HX_CSTRING("stop_") + this->cAnim),null(),null());
			}
			else{
				HX_STACK_LINE(66)
				Float _g = ::Math_obj::abs(this->speed->x);		HX_STACK_VAR(_g,"_g");
				HX_STACK_LINE(66)
				Float _g1 = ::Math_obj::abs(this->speed->y);		HX_STACK_VAR(_g1,"_g1");
				HX_STACK_LINE(66)
				if (((_g > _g1))){
					HX_STACK_LINE(68)
					if (((this->speed->x > (int)0))){
						HX_STACK_LINE(69)
						this->animation->play(HX_CSTRING("right"),null(),null());
					}
					HX_STACK_LINE(70)
					if (((this->speed->x < (int)0))){
						HX_STACK_LINE(71)
						this->animation->play(HX_CSTRING("left"),null(),null());
					}
					struct _Function_4_1{
						inline static ::flixel::animation::FlxAnimation Block( hx::ObjectPtr< ::Player_obj > __this){
							HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","Player.hx",72,0xa27fc9dd)
							{
								HX_STACK_LINE(72)
								::flixel::animation::FlxAnimationController _this = __this->animation;		HX_STACK_VAR(_this,"_this");
								HX_STACK_LINE(72)
								::flixel::animation::FlxAnimation anim = null();		HX_STACK_VAR(anim,"anim");
								HX_STACK_LINE(72)
								if (((bool((bool((_this->_curAnim != null())) && bool((_this->_curAnim->delay > (int)0)))) && bool(((bool(_this->_curAnim->looped) || bool(!(_this->_curAnim->finished)))))))){
									HX_STACK_LINE(72)
									anim = _this->_curAnim;
								}
								HX_STACK_LINE(72)
								return anim;
							}
							return null();
						}
					};
					HX_STACK_LINE(72)
					this->cAnim = (_Function_4_1::Block(this))->name;
				}
				else{
					HX_STACK_LINE(74)
					Float _g2 = ::Math_obj::abs(this->speed->x);		HX_STACK_VAR(_g2,"_g2");
					HX_STACK_LINE(74)
					Float _g3 = ::Math_obj::abs(this->speed->y);		HX_STACK_VAR(_g3,"_g3");
					HX_STACK_LINE(74)
					if (((_g2 < _g3))){
						HX_STACK_LINE(76)
						if (((this->speed->y > (int)0))){
							HX_STACK_LINE(77)
							this->animation->play(HX_CSTRING("down"),null(),null());
						}
						HX_STACK_LINE(78)
						if (((this->speed->y < (int)0))){
							HX_STACK_LINE(79)
							this->animation->play(HX_CSTRING("up"),null(),null());
						}
						struct _Function_5_1{
							inline static ::flixel::animation::FlxAnimation Block( hx::ObjectPtr< ::Player_obj > __this){
								HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","Player.hx",80,0xa27fc9dd)
								{
									HX_STACK_LINE(80)
									::flixel::animation::FlxAnimationController _this = __this->animation;		HX_STACK_VAR(_this,"_this");
									HX_STACK_LINE(80)
									::flixel::animation::FlxAnimation anim = null();		HX_STACK_VAR(anim,"anim");
									HX_STACK_LINE(80)
									if (((bool((bool((_this->_curAnim != null())) && bool((_this->_curAnim->delay > (int)0)))) && bool(((bool(_this->_curAnim->looped) || bool(!(_this->_curAnim->finished)))))))){
										HX_STACK_LINE(80)
										anim = _this->_curAnim;
									}
									HX_STACK_LINE(80)
									return anim;
								}
								return null();
							}
						};
						HX_STACK_LINE(80)
						this->cAnim = (_Function_5_1::Block(this))->name;
					}
				}
			}
		}
		HX_STACK_LINE(86)
		this->xChange = (this->speed->x * ::flixel::FlxG_obj::elapsed);
		HX_STACK_LINE(87)
		this->yChange = (this->speed->y * ::flixel::FlxG_obj::elapsed);
		HX_STACK_LINE(89)
		this->stopAtEdges();
		HX_STACK_LINE(92)
		if ((this->hitSides())){
			HX_STACK_LINE(93)
			this->xChange = (int)0;
		}
		HX_STACK_LINE(94)
		if ((this->hitVert())){
			HX_STACK_LINE(95)
			this->yChange = (int)0;
		}
		HX_STACK_LINE(98)
		{
			HX_STACK_LINE(98)
			::Player _g = hx::ObjectPtr<OBJ_>(this);		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(98)
			_g->set_x((_g->x + this->xChange));
		}
		HX_STACK_LINE(99)
		{
			HX_STACK_LINE(99)
			::Player _g = hx::ObjectPtr<OBJ_>(this);		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(99)
			_g->set_y((_g->y + this->yChange));
		}
	}
return null();
}


bool Player_obj::hitSides( ){
	HX_STACK_FRAME("Player","hitSides",0x4d9dba36,"Player.hitSides","Player.hx",110,0xa27fc9dd)
	HX_STACK_THIS(this)
	HX_STACK_LINE(111)
	this->cx = this->x;
	HX_STACK_LINE(112)
	this->cy = this->y;
	HX_STACK_LINE(113)
	if (((this->xChange > (int)0))){
		HX_STACK_LINE(114)
		Float _g = this->get_width();		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(114)
		hx::AddEq(this->cx,_g);
	}
	HX_STACK_LINE(116)
	Float _g1 = this->get_height();		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(116)
	Float _g2 = (_g1 * 0.3);		HX_STACK_VAR(_g2,"_g2");
	HX_STACK_LINE(116)
	hx::AddEq(this->cy,_g2);
	HX_STACK_LINE(117)
	int _g3 = ::Calc_obj::getHitType((this->cx + this->xChange),this->cy);		HX_STACK_VAR(_g3,"_g3");
	HX_STACK_LINE(117)
	if (((_g3 == (int)1))){
		HX_STACK_LINE(118)
		return true;
	}
	HX_STACK_LINE(119)
	Float _g4 = this->get_height();		HX_STACK_VAR(_g4,"_g4");
	HX_STACK_LINE(119)
	Float _g5 = (_g4 * 0.3);		HX_STACK_VAR(_g5,"_g5");
	HX_STACK_LINE(119)
	hx::AddEq(this->cy,_g5);
	HX_STACK_LINE(120)
	int _g6 = ::Calc_obj::getHitType((this->cx + this->xChange),this->cy);		HX_STACK_VAR(_g6,"_g6");
	HX_STACK_LINE(120)
	if (((_g6 == (int)1))){
		HX_STACK_LINE(121)
		return true;
	}
	HX_STACK_LINE(122)
	Float _g7 = this->get_height();		HX_STACK_VAR(_g7,"_g7");
	HX_STACK_LINE(122)
	Float _g8 = (_g7 * 0.3);		HX_STACK_VAR(_g8,"_g8");
	HX_STACK_LINE(122)
	hx::AddEq(this->cy,_g8);
	HX_STACK_LINE(123)
	int _g9 = ::Calc_obj::getHitType((this->cx + this->xChange),this->cy);		HX_STACK_VAR(_g9,"_g9");
	HX_STACK_LINE(123)
	if (((_g9 == (int)1))){
		HX_STACK_LINE(124)
		return true;
	}
	HX_STACK_LINE(125)
	return false;
}


HX_DEFINE_DYNAMIC_FUNC0(Player_obj,hitSides,return )

bool Player_obj::hitVert( ){
	HX_STACK_FRAME("Player","hitVert",0x0dcc96b7,"Player.hitVert","Player.hx",128,0xa27fc9dd)
	HX_STACK_THIS(this)
	HX_STACK_LINE(129)
	this->cx = this->x;
	HX_STACK_LINE(130)
	this->cy = this->y;
	HX_STACK_LINE(131)
	if (((this->yChange > (int)0))){
		HX_STACK_LINE(132)
		Float _g = this->get_height();		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(132)
		hx::AddEq(this->cy,_g);
	}
	HX_STACK_LINE(134)
	Float _g1 = this->get_width();		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(134)
	Float _g2 = (_g1 * 0.1);		HX_STACK_VAR(_g2,"_g2");
	HX_STACK_LINE(134)
	hx::AddEq(this->cx,_g2);
	HX_STACK_LINE(135)
	int _g3 = ::Calc_obj::getHitType(this->cx,(this->cy + this->yChange));		HX_STACK_VAR(_g3,"_g3");
	HX_STACK_LINE(135)
	if (((_g3 == (int)1))){
		HX_STACK_LINE(136)
		return true;
	}
	HX_STACK_LINE(137)
	Float _g4 = this->get_width();		HX_STACK_VAR(_g4,"_g4");
	HX_STACK_LINE(137)
	Float _g5 = (_g4 * 0.4);		HX_STACK_VAR(_g5,"_g5");
	HX_STACK_LINE(137)
	hx::AddEq(this->cx,_g5);
	HX_STACK_LINE(138)
	int _g6 = ::Calc_obj::getHitType(this->cx,(this->cy + this->yChange));		HX_STACK_VAR(_g6,"_g6");
	HX_STACK_LINE(138)
	if (((_g6 == (int)1))){
		HX_STACK_LINE(139)
		return true;
	}
	HX_STACK_LINE(140)
	Float _g7 = this->get_width();		HX_STACK_VAR(_g7,"_g7");
	HX_STACK_LINE(140)
	Float _g8 = (_g7 * 0.4);		HX_STACK_VAR(_g8,"_g8");
	HX_STACK_LINE(140)
	hx::AddEq(this->cx,_g8);
	HX_STACK_LINE(141)
	int _g9 = ::Calc_obj::getHitType(this->cx,(this->cy + this->yChange));		HX_STACK_VAR(_g9,"_g9");
	HX_STACK_LINE(141)
	if (((_g9 == (int)1))){
		HX_STACK_LINE(142)
		return true;
	}
	HX_STACK_LINE(143)
	return false;
}


HX_DEFINE_DYNAMIC_FUNC0(Player_obj,hitVert,return )

Void Player_obj::stopAtEdges( ){
{
		HX_STACK_FRAME("Player","stopAtEdges",0x0092a354,"Player.stopAtEdges","Player.hx",147,0xa27fc9dd)
		HX_STACK_THIS(this)
		HX_STACK_LINE(150)
		if (((bool((bool((this->xChange < (int)0)) && bool(((Float(((this->x + this->xChange))) / Float(::Global_obj::tileSize)) < (int)0)))) && bool((::Global_obj::c->__get((int)1) == (int)0))))){
			HX_STACK_LINE(151)
			this->xChange = (int)0;
		}
		struct _Function_1_1{
			inline static bool Block( hx::ObjectPtr< ::Player_obj > __this){
				HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","Player.hx",153,0xa27fc9dd)
				{
					HX_STACK_LINE(153)
					Float _g = __this->get_width();		HX_STACK_VAR(_g,"_g");
					HX_STACK_LINE(153)
					Float _g1 = (__this->x + _g);		HX_STACK_VAR(_g1,"_g1");
					HX_STACK_LINE(153)
					Float _g2 = (_g1 + __this->xChange);		HX_STACK_VAR(_g2,"_g2");
					HX_STACK_LINE(153)
					Float _g3 = (Float(_g2) / Float(::Global_obj::tileSize));		HX_STACK_VAR(_g3,"_g3");
					HX_STACK_LINE(153)
					return (_g3 > ::Global_obj::gameTileSize->__get((int)0));
				}
				return null();
			}
		};
		HX_STACK_LINE(153)
		if (((  (((  (((this->xChange > (int)0))) ? bool(_Function_1_1::Block(this)) : bool(false) ))) ? bool((::Global_obj::c->__get((int)1) == (::Global_obj::levels->__get((int)0).StaticCast< Array< ::String > >()->length - (int)1))) : bool(false) ))){
			HX_STACK_LINE(154)
			this->xChange = (int)0;
		}
		HX_STACK_LINE(156)
		if (((bool((bool((this->yChange < (int)0)) && bool(((Float(((this->y + this->yChange))) / Float(::Global_obj::tileSize)) < (int)0)))) && bool((::Global_obj::c->__get((int)0) == (int)0))))){
			HX_STACK_LINE(157)
			this->yChange = (int)0;
		}
		struct _Function_1_2{
			inline static bool Block( hx::ObjectPtr< ::Player_obj > __this){
				HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","Player.hx",159,0xa27fc9dd)
				{
					HX_STACK_LINE(159)
					Float _g4 = __this->get_height();		HX_STACK_VAR(_g4,"_g4");
					HX_STACK_LINE(159)
					Float _g5 = (__this->y + _g4);		HX_STACK_VAR(_g5,"_g5");
					HX_STACK_LINE(159)
					Float _g6 = (_g5 + __this->yChange);		HX_STACK_VAR(_g6,"_g6");
					HX_STACK_LINE(159)
					Float _g7 = (Float(_g6) / Float(::Global_obj::tileSize));		HX_STACK_VAR(_g7,"_g7");
					HX_STACK_LINE(159)
					return (_g7 > ::Global_obj::gameTileSize->__get((int)1));
				}
				return null();
			}
		};
		HX_STACK_LINE(159)
		if (((  (((  (((this->yChange > (int)0))) ? bool(_Function_1_2::Block(this)) : bool(false) ))) ? bool((::Global_obj::c->__get((int)0) == (::Global_obj::levels->length - (int)1))) : bool(false) ))){
			HX_STACK_LINE(160)
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
	HX_MARK_MEMBER_NAME(knock,"knock");
	HX_MARK_MEMBER_NAME(cx,"cx");
	HX_MARK_MEMBER_NAME(cy,"cy");
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
	HX_VISIT_MEMBER_NAME(knock,"knock");
	HX_VISIT_MEMBER_NAME(cx,"cx");
	HX_VISIT_MEMBER_NAME(cy,"cy");
	::flixel::FlxSprite_obj::__Visit(HX_VISIT_ARG);
}

Dynamic Player_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 2:
		if (HX_FIELD_EQ(inName,"cx") ) { return cx; }
		if (HX_FIELD_EQ(inName,"cy") ) { return cy; }
		break;
	case 3:
		if (HX_FIELD_EQ(inName,"dir") ) { return dir; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"speed") ) { return speed; }
		if (HX_FIELD_EQ(inName,"cAnim") ) { return cAnim; }
		if (HX_FIELD_EQ(inName,"knock") ) { return knock; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"update") ) { return update_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"xChange") ) { return xChange; }
		if (HX_FIELD_EQ(inName,"yChange") ) { return yChange; }
		if (HX_FIELD_EQ(inName,"hitVert") ) { return hitVert_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"maxSpeed") ) { return maxSpeed; }
		if (HX_FIELD_EQ(inName,"hitSides") ) { return hitSides_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"stopAtEdges") ) { return stopAtEdges_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Player_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 2:
		if (HX_FIELD_EQ(inName,"cx") ) { cx=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"cy") ) { cy=inValue.Cast< Float >(); return inValue; }
		break;
	case 3:
		if (HX_FIELD_EQ(inName,"dir") ) { dir=inValue.Cast< ::String >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"speed") ) { speed=inValue.Cast< ::flixel::util::FlxPoint >(); return inValue; }
		if (HX_FIELD_EQ(inName,"cAnim") ) { cAnim=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"knock") ) { knock=inValue.Cast< bool >(); return inValue; }
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
	outFields->push(HX_CSTRING("knock"));
	outFields->push(HX_CSTRING("cx"));
	outFields->push(HX_CSTRING("cy"));
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
	{hx::fsBool,(int)offsetof(Player_obj,knock),HX_CSTRING("knock")},
	{hx::fsFloat,(int)offsetof(Player_obj,cx),HX_CSTRING("cx")},
	{hx::fsFloat,(int)offsetof(Player_obj,cy),HX_CSTRING("cy")},
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
	HX_CSTRING("knock"),
	HX_CSTRING("update"),
	HX_CSTRING("cx"),
	HX_CSTRING("cy"),
	HX_CSTRING("hitSides"),
	HX_CSTRING("hitVert"),
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

