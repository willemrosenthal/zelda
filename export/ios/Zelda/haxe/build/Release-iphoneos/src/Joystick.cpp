#include <hxcpp.h>

#ifndef INCLUDED_Global
#include <Global.h>
#endif
#ifndef INCLUDED_Joystick
#include <Joystick.h>
#endif
#ifndef INCLUDED_flash_Lib
#include <flash/Lib.h>
#endif
#ifndef INCLUDED_flash_display_DisplayObject
#include <flash/display/DisplayObject.h>
#endif
#ifndef INCLUDED_flash_display_DisplayObjectContainer
#include <flash/display/DisplayObjectContainer.h>
#endif
#ifndef INCLUDED_flash_display_IBitmapDrawable
#include <flash/display/IBitmapDrawable.h>
#endif
#ifndef INCLUDED_flash_display_InteractiveObject
#include <flash/display/InteractiveObject.h>
#endif
#ifndef INCLUDED_flash_display_MovieClip
#include <flash/display/MovieClip.h>
#endif
#ifndef INCLUDED_flash_display_Sprite
#include <flash/display/Sprite.h>
#endif
#ifndef INCLUDED_flash_display_Stage
#include <flash/display/Stage.h>
#endif
#ifndef INCLUDED_flash_events_EventDispatcher
#include <flash/events/EventDispatcher.h>
#endif
#ifndef INCLUDED_flash_events_IEventDispatcher
#include <flash/events/IEventDispatcher.h>
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
#ifndef INCLUDED_flixel_input_mouse_FlxMouse
#include <flixel/input/mouse/FlxMouse.h>
#endif
#ifndef INCLUDED_flixel_input_mouse_FlxMouseButton
#include <flixel/input/mouse/FlxMouseButton.h>
#endif
#ifndef INCLUDED_flixel_interfaces_IFlxDestroyable
#include <flixel/interfaces/IFlxDestroyable.h>
#endif
#ifndef INCLUDED_flixel_interfaces_IFlxInput
#include <flixel/interfaces/IFlxInput.h>
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

Void Joystick_obj::__construct(Float X,Float Y,Float RingSize)
{
HX_STACK_FRAME("Joystick","new",0xd084dbce,"Joystick.new","Joystick.hx",8,0x21141762)
HX_STACK_THIS(this)
HX_STACK_ARG(X,"X")
HX_STACK_ARG(Y,"Y")
HX_STACK_ARG(RingSize,"RingSize")
{
	HX_STACK_LINE(23)
	this->multiplier = (int)2;
	HX_STACK_LINE(22)
	this->gameZoom = (int)1;
	HX_STACK_LINE(21)
	this->mouseDown = false;
	HX_STACK_LINE(19)
	this->hyp = (int)0;
	HX_STACK_LINE(18)
	this->yDif = (int)0;
	HX_STACK_LINE(17)
	this->xDif = (int)0;
	HX_STACK_LINE(14)
	this->mouseMaxX = (int)70;
	HX_STACK_LINE(13)
	this->mouseMaxY = (int)70;
	HX_STACK_LINE(12)
	this->moveSpeed = (int)1;
	HX_STACK_LINE(11)
	this->moveIgnoreRange = (int)4;
	HX_STACK_LINE(10)
	this->maxDistance = (int)38;
	HX_STACK_LINE(26)
	super::__construct(X,Y,null());
	HX_STACK_LINE(27)
	this->gameZoom = ::Global_obj::gameZoom;
	HX_STACK_LINE(28)
	::flixel::util::FlxPoint _g = ::flixel::util::FlxPoint_obj::__new(X,Y);		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(28)
	this->originPoint = _g;
	HX_STACK_LINE(29)
	::flixel::util::FlxPoint _g1 = ::flixel::util::FlxPoint_obj::__new((int)0,(int)0);		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(29)
	this->moveDirs = _g1;
	HX_STACK_LINE(31)
	this->loadGraphic(HX_CSTRING("assets/images/joystick.png"),false,(int)20,(int)20,null(),null());
	HX_STACK_LINE(32)
	Float _g2 = this->get_height();		HX_STACK_VAR(_g2,"_g2");
	HX_STACK_LINE(32)
	Float _g3 = (_g2 * 0.5);		HX_STACK_VAR(_g3,"_g3");
	HX_STACK_LINE(32)
	this->offset->set_y(_g3);
	HX_STACK_LINE(33)
	Float _g4 = this->get_width();		HX_STACK_VAR(_g4,"_g4");
	HX_STACK_LINE(33)
	Float _g5 = (_g4 * 0.5);		HX_STACK_VAR(_g5,"_g5");
	HX_STACK_LINE(33)
	this->offset->set_x(_g5);
	HX_STACK_LINE(35)
	Float _g6 = this->get_width();		HX_STACK_VAR(_g6,"_g6");
	HX_STACK_LINE(35)
	Float _g7 = (_g6 * 0.5);		HX_STACK_VAR(_g7,"_g7");
	HX_STACK_LINE(35)
	Float _g8 = ((RingSize * 0.5) - _g7);		HX_STACK_VAR(_g8,"_g8");
	HX_STACK_LINE(35)
	this->maxDistance = _g8;
}
;
	return null();
}

//Joystick_obj::~Joystick_obj() { }

Dynamic Joystick_obj::__CreateEmpty() { return  new Joystick_obj; }
hx::ObjectPtr< Joystick_obj > Joystick_obj::__new(Float X,Float Y,Float RingSize)
{  hx::ObjectPtr< Joystick_obj > result = new Joystick_obj();
	result->__construct(X,Y,RingSize);
	return result;}

Dynamic Joystick_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Joystick_obj > result = new Joystick_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2]);
	return result;}

Void Joystick_obj::update( ){
{
		HX_STACK_FRAME("Joystick","update",0xb982d35b,"Joystick.update","Joystick.hx",38,0x21141762)
		HX_STACK_THIS(this)
		HX_STACK_LINE(39)
		this->super::update();
		struct _Function_1_1{
			inline static bool Block( ){
				HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","Joystick.hx",41,0x21141762)
				{
					HX_STACK_LINE(41)
					::flixel::input::mouse::FlxMouseButton _this = ::flixel::FlxG_obj::mouse->_leftButton;		HX_STACK_VAR(_this,"_this");
					HX_STACK_LINE(41)
					return (bool((_this->current == (int)2)) || bool((_this->current == (int)-2)));
				}
				return null();
			}
		};
		HX_STACK_LINE(41)
		if (((bool(_Function_1_1::Block()) && bool(!(this->mouseDown))))){
			HX_STACK_LINE(42)
			this->mouseDown = true;
		}
		struct _Function_1_2{
			inline static bool Block( ){
				HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","Joystick.hx",43,0x21141762)
				{
					HX_STACK_LINE(43)
					::flixel::input::mouse::FlxMouseButton _this = ::flixel::FlxG_obj::mouse->_leftButton;		HX_STACK_VAR(_this,"_this");
					HX_STACK_LINE(43)
					return (bool((_this->current == (int)-1)) || bool((_this->current == (int)-2)));
				}
				return null();
			}
		};
		HX_STACK_LINE(43)
		if ((_Function_1_2::Block())){
			HX_STACK_LINE(44)
			this->mouseDown = false;
		}
		HX_STACK_LINE(47)
		if ((this->noMove())){
			HX_STACK_LINE(48)
			return null();
		}
		HX_STACK_LINE(50)
		if ((!(this->mouseDown))){
			HX_STACK_LINE(51)
			this->set_x(this->originPoint->x);
			HX_STACK_LINE(52)
			this->set_y(this->originPoint->y);
			HX_STACK_LINE(53)
			::Global_obj::move->set_x((int)0);
			HX_STACK_LINE(54)
			::Global_obj::move->set_y((int)0);
			HX_STACK_LINE(55)
			return null();
		}
		HX_STACK_LINE(58)
		::flixel::util::FlxPoint _g = this->calculateJoystick();		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(58)
		::Global_obj::move = _g;
	}
return null();
}


::flixel::util::FlxPoint Joystick_obj::calculateJoystick( ){
	HX_STACK_FRAME("Joystick","calculateJoystick",0xbb47f830,"Joystick.calculateJoystick","Joystick.hx",61,0x21141762)
	HX_STACK_THIS(this)
	HX_STACK_LINE(62)
	Float _g = ::flash::Lib_obj::get_current()->get_stage()->get_mouseX();		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(62)
	Float _g1 = (Float(_g) / Float(this->gameZoom));		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(62)
	Float _g2 = (this->originPoint->x - _g1);		HX_STACK_VAR(_g2,"_g2");
	HX_STACK_LINE(62)
	this->xDif = _g2;
	HX_STACK_LINE(63)
	Float _g3 = ::flash::Lib_obj::get_current()->get_stage()->get_mouseY();		HX_STACK_VAR(_g3,"_g3");
	HX_STACK_LINE(63)
	Float _g4 = (Float(_g3) / Float(this->gameZoom));		HX_STACK_VAR(_g4,"_g4");
	HX_STACK_LINE(63)
	Float _g5 = (this->originPoint->y - _g4);		HX_STACK_VAR(_g5,"_g5");
	HX_STACK_LINE(63)
	this->yDif = _g5;
	HX_STACK_LINE(65)
	if (((this->multiplier > (int)1))){
		HX_STACK_LINE(66)
		Float _g6 = ::Math_obj::abs((this->xDif * this->xDif));		HX_STACK_VAR(_g6,"_g6");
		HX_STACK_LINE(66)
		Float _g7 = ::Math_obj::abs((this->yDif * this->yDif));		HX_STACK_VAR(_g7,"_g7");
		HX_STACK_LINE(66)
		Float _g8 = (_g6 + _g7);		HX_STACK_VAR(_g8,"_g8");
		HX_STACK_LINE(66)
		Float _g9 = ::Math_obj::sqrt(_g8);		HX_STACK_VAR(_g9,"_g9");
		HX_STACK_LINE(66)
		this->hyp = _g9;
		HX_STACK_LINE(67)
		this->positionJostick();
		HX_STACK_LINE(68)
		hx::MultEq(this->xDif,this->multiplier);
		HX_STACK_LINE(69)
		hx::MultEq(this->yDif,this->multiplier);
	}
	else{
		HX_STACK_LINE(71)
		this->positionJostick();
	}
	HX_STACK_LINE(73)
	this->moveDirs->set_x((int)0);
	HX_STACK_LINE(74)
	this->moveDirs->set_y((int)0);
	HX_STACK_LINE(76)
	if (((this->xDif == (int)0))){
		HX_STACK_LINE(77)
		this->moveDirs->set_x((int)0);
		HX_STACK_LINE(78)
		if (((this->yDif > (int)0))){
			HX_STACK_LINE(79)
			this->moveDirs->set_y((int)-1);
		}
		HX_STACK_LINE(80)
		if (((this->yDif < (int)0))){
			HX_STACK_LINE(81)
			this->moveDirs->set_y((int)1);
		}
		HX_STACK_LINE(82)
		return this->moveDirs;
	}
	HX_STACK_LINE(85)
	if (((this->yDif == (int)0))){
		HX_STACK_LINE(86)
		this->moveDirs->set_y((int)0);
		HX_STACK_LINE(87)
		if (((this->xDif > (int)0))){
			HX_STACK_LINE(88)
			this->moveDirs->set_x((int)-1);
		}
		HX_STACK_LINE(89)
		if (((this->xDif < (int)0))){
			HX_STACK_LINE(90)
			this->moveDirs->set_x((int)1);
		}
		HX_STACK_LINE(91)
		return this->moveDirs;
	}
	HX_STACK_LINE(94)
	Float _g10 = ::Math_obj::abs((this->xDif * this->xDif));		HX_STACK_VAR(_g10,"_g10");
	HX_STACK_LINE(94)
	Float _g11 = ::Math_obj::abs((this->yDif * this->yDif));		HX_STACK_VAR(_g11,"_g11");
	HX_STACK_LINE(94)
	Float _g12 = (_g10 + _g11);		HX_STACK_VAR(_g12,"_g12");
	HX_STACK_LINE(94)
	Float _g13 = ::Math_obj::sqrt(_g12);		HX_STACK_VAR(_g13,"_g13");
	HX_STACK_LINE(94)
	this->hyp = _g13;
	HX_STACK_LINE(96)
	if (((this->hyp < this->moveIgnoreRange))){
		HX_STACK_LINE(97)
		return this->moveDirs;
	}
	HX_STACK_LINE(99)
	Float _g14 = ::Math_obj::abs(this->hyp);		HX_STACK_VAR(_g14,"_g14");
	HX_STACK_LINE(99)
	if (((_g14 < this->maxDistance))){
		HX_STACK_LINE(100)
		this->moveDirs->set_x(((Float(this->hyp) / Float(this->maxDistance)) * (((this->xDif * ((Float(this->moveSpeed) / Float(this->hyp)))) * (int)-1))));
		HX_STACK_LINE(101)
		this->moveDirs->set_y(((Float(this->hyp) / Float(this->maxDistance)) * (((this->yDif * ((Float(this->moveSpeed) / Float(this->hyp)))) * (int)-1))));
		HX_STACK_LINE(102)
		return this->moveDirs;
	}
	HX_STACK_LINE(105)
	this->moveDirs->set_x(((this->xDif * ((Float(this->moveSpeed) / Float(this->hyp)))) * (int)-1));
	HX_STACK_LINE(106)
	this->moveDirs->set_y(((this->yDif * ((Float(this->moveSpeed) / Float(this->hyp)))) * (int)-1));
	HX_STACK_LINE(108)
	return this->moveDirs;
}


HX_DEFINE_DYNAMIC_FUNC0(Joystick_obj,calculateJoystick,return )

Void Joystick_obj::positionJostick( ){
{
		HX_STACK_FRAME("Joystick","positionJostick",0x30950930,"Joystick.positionJostick","Joystick.hx",111,0x21141762)
		HX_STACK_THIS(this)
		HX_STACK_LINE(112)
		Float _g = ::Math_obj::abs(this->hyp);		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(112)
		if (((_g < this->maxDistance))){
			HX_STACK_LINE(113)
			Float _g1 = ::flash::Lib_obj::get_current()->get_stage()->get_mouseX();		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(113)
			Float _g2 = (Float(_g1) / Float(this->gameZoom));		HX_STACK_VAR(_g2,"_g2");
			HX_STACK_LINE(113)
			this->set_x(_g2);
			HX_STACK_LINE(114)
			Float _g3 = ::flash::Lib_obj::get_current()->get_stage()->get_mouseY();		HX_STACK_VAR(_g3,"_g3");
			HX_STACK_LINE(114)
			Float _g4 = (Float(_g3) / Float(this->gameZoom));		HX_STACK_VAR(_g4,"_g4");
			HX_STACK_LINE(114)
			this->set_y(_g4);
		}
		else{
			HX_STACK_LINE(117)
			this->set_x(((((Float(this->maxDistance) / Float(this->hyp)) * this->xDif) * (int)-1) + this->originPoint->x));
			HX_STACK_LINE(118)
			this->set_y(((((Float(this->maxDistance) / Float(this->hyp)) * this->yDif) * (int)-1) + this->originPoint->y));
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Joystick_obj,positionJostick,(void))

bool Joystick_obj::noMove( ){
	HX_STACK_FRAME("Joystick","noMove",0x4a737144,"Joystick.noMove","Joystick.hx",122,0x21141762)
	HX_STACK_THIS(this)
	HX_STACK_LINE(123)
	if ((::Global_obj::UIopen)){
		HX_STACK_LINE(124)
		this->resetJoystick();
		HX_STACK_LINE(125)
		this->mouseDown = false;
		HX_STACK_LINE(126)
		return true;
	}
	HX_STACK_LINE(129)
	if (((bool((bool((::flixel::FlxG_obj::mouse->y > (this->originPoint->y + this->mouseMaxY))) || bool((::flixel::FlxG_obj::mouse->y < (this->originPoint->y - this->mouseMaxY))))) || bool(((bool((::flixel::FlxG_obj::mouse->x > (this->originPoint->x + this->mouseMaxX))) || bool((::flixel::FlxG_obj::mouse->x < (this->originPoint->x - this->mouseMaxX))))))))){
		HX_STACK_LINE(130)
		this->resetJoystick();
		HX_STACK_LINE(131)
		return true;
	}
	HX_STACK_LINE(134)
	if ((::Global_obj::changingScreens)){
		HX_STACK_LINE(135)
		::Global_obj::move->set_x((int)0);
		HX_STACK_LINE(136)
		::Global_obj::move->set_y((int)0);
	}
	HX_STACK_LINE(139)
	return false;
}


HX_DEFINE_DYNAMIC_FUNC0(Joystick_obj,noMove,return )

Void Joystick_obj::resetJoystick( ){
{
		HX_STACK_FRAME("Joystick","resetJoystick",0x122fae99,"Joystick.resetJoystick","Joystick.hx",142,0x21141762)
		HX_STACK_THIS(this)
		HX_STACK_LINE(143)
		this->set_x(this->originPoint->x);
		HX_STACK_LINE(144)
		this->set_y(this->originPoint->y);
		HX_STACK_LINE(145)
		::Global_obj::move->set_x((int)0);
		HX_STACK_LINE(146)
		::Global_obj::move->set_y((int)0);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Joystick_obj,resetJoystick,(void))


Joystick_obj::Joystick_obj()
{
}

void Joystick_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Joystick);
	HX_MARK_MEMBER_NAME(maxDistance,"maxDistance");
	HX_MARK_MEMBER_NAME(moveIgnoreRange,"moveIgnoreRange");
	HX_MARK_MEMBER_NAME(moveSpeed,"moveSpeed");
	HX_MARK_MEMBER_NAME(mouseMaxY,"mouseMaxY");
	HX_MARK_MEMBER_NAME(mouseMaxX,"mouseMaxX");
	HX_MARK_MEMBER_NAME(originPoint,"originPoint");
	HX_MARK_MEMBER_NAME(xDif,"xDif");
	HX_MARK_MEMBER_NAME(yDif,"yDif");
	HX_MARK_MEMBER_NAME(hyp,"hyp");
	HX_MARK_MEMBER_NAME(moveDirs,"moveDirs");
	HX_MARK_MEMBER_NAME(mouseDown,"mouseDown");
	HX_MARK_MEMBER_NAME(gameZoom,"gameZoom");
	HX_MARK_MEMBER_NAME(multiplier,"multiplier");
	::flixel::FlxSprite_obj::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void Joystick_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(maxDistance,"maxDistance");
	HX_VISIT_MEMBER_NAME(moveIgnoreRange,"moveIgnoreRange");
	HX_VISIT_MEMBER_NAME(moveSpeed,"moveSpeed");
	HX_VISIT_MEMBER_NAME(mouseMaxY,"mouseMaxY");
	HX_VISIT_MEMBER_NAME(mouseMaxX,"mouseMaxX");
	HX_VISIT_MEMBER_NAME(originPoint,"originPoint");
	HX_VISIT_MEMBER_NAME(xDif,"xDif");
	HX_VISIT_MEMBER_NAME(yDif,"yDif");
	HX_VISIT_MEMBER_NAME(hyp,"hyp");
	HX_VISIT_MEMBER_NAME(moveDirs,"moveDirs");
	HX_VISIT_MEMBER_NAME(mouseDown,"mouseDown");
	HX_VISIT_MEMBER_NAME(gameZoom,"gameZoom");
	HX_VISIT_MEMBER_NAME(multiplier,"multiplier");
	::flixel::FlxSprite_obj::__Visit(HX_VISIT_ARG);
}

Dynamic Joystick_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"hyp") ) { return hyp; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"xDif") ) { return xDif; }
		if (HX_FIELD_EQ(inName,"yDif") ) { return yDif; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"update") ) { return update_dyn(); }
		if (HX_FIELD_EQ(inName,"noMove") ) { return noMove_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"moveDirs") ) { return moveDirs; }
		if (HX_FIELD_EQ(inName,"gameZoom") ) { return gameZoom; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"moveSpeed") ) { return moveSpeed; }
		if (HX_FIELD_EQ(inName,"mouseMaxY") ) { return mouseMaxY; }
		if (HX_FIELD_EQ(inName,"mouseMaxX") ) { return mouseMaxX; }
		if (HX_FIELD_EQ(inName,"mouseDown") ) { return mouseDown; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"multiplier") ) { return multiplier; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"maxDistance") ) { return maxDistance; }
		if (HX_FIELD_EQ(inName,"originPoint") ) { return originPoint; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"resetJoystick") ) { return resetJoystick_dyn(); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"moveIgnoreRange") ) { return moveIgnoreRange; }
		if (HX_FIELD_EQ(inName,"positionJostick") ) { return positionJostick_dyn(); }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"calculateJoystick") ) { return calculateJoystick_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Joystick_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"hyp") ) { hyp=inValue.Cast< Float >(); return inValue; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"xDif") ) { xDif=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"yDif") ) { yDif=inValue.Cast< Float >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"moveDirs") ) { moveDirs=inValue.Cast< ::flixel::util::FlxPoint >(); return inValue; }
		if (HX_FIELD_EQ(inName,"gameZoom") ) { gameZoom=inValue.Cast< Float >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"moveSpeed") ) { moveSpeed=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"mouseMaxY") ) { mouseMaxY=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"mouseMaxX") ) { mouseMaxX=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"mouseDown") ) { mouseDown=inValue.Cast< bool >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"multiplier") ) { multiplier=inValue.Cast< Float >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"maxDistance") ) { maxDistance=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"originPoint") ) { originPoint=inValue.Cast< ::flixel::util::FlxPoint >(); return inValue; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"moveIgnoreRange") ) { moveIgnoreRange=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Joystick_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("maxDistance"));
	outFields->push(HX_CSTRING("moveIgnoreRange"));
	outFields->push(HX_CSTRING("moveSpeed"));
	outFields->push(HX_CSTRING("mouseMaxY"));
	outFields->push(HX_CSTRING("mouseMaxX"));
	outFields->push(HX_CSTRING("originPoint"));
	outFields->push(HX_CSTRING("xDif"));
	outFields->push(HX_CSTRING("yDif"));
	outFields->push(HX_CSTRING("hyp"));
	outFields->push(HX_CSTRING("moveDirs"));
	outFields->push(HX_CSTRING("mouseDown"));
	outFields->push(HX_CSTRING("gameZoom"));
	outFields->push(HX_CSTRING("multiplier"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsFloat,(int)offsetof(Joystick_obj,maxDistance),HX_CSTRING("maxDistance")},
	{hx::fsInt,(int)offsetof(Joystick_obj,moveIgnoreRange),HX_CSTRING("moveIgnoreRange")},
	{hx::fsFloat,(int)offsetof(Joystick_obj,moveSpeed),HX_CSTRING("moveSpeed")},
	{hx::fsFloat,(int)offsetof(Joystick_obj,mouseMaxY),HX_CSTRING("mouseMaxY")},
	{hx::fsFloat,(int)offsetof(Joystick_obj,mouseMaxX),HX_CSTRING("mouseMaxX")},
	{hx::fsObject /*::flixel::util::FlxPoint*/ ,(int)offsetof(Joystick_obj,originPoint),HX_CSTRING("originPoint")},
	{hx::fsFloat,(int)offsetof(Joystick_obj,xDif),HX_CSTRING("xDif")},
	{hx::fsFloat,(int)offsetof(Joystick_obj,yDif),HX_CSTRING("yDif")},
	{hx::fsFloat,(int)offsetof(Joystick_obj,hyp),HX_CSTRING("hyp")},
	{hx::fsObject /*::flixel::util::FlxPoint*/ ,(int)offsetof(Joystick_obj,moveDirs),HX_CSTRING("moveDirs")},
	{hx::fsBool,(int)offsetof(Joystick_obj,mouseDown),HX_CSTRING("mouseDown")},
	{hx::fsFloat,(int)offsetof(Joystick_obj,gameZoom),HX_CSTRING("gameZoom")},
	{hx::fsFloat,(int)offsetof(Joystick_obj,multiplier),HX_CSTRING("multiplier")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("maxDistance"),
	HX_CSTRING("moveIgnoreRange"),
	HX_CSTRING("moveSpeed"),
	HX_CSTRING("mouseMaxY"),
	HX_CSTRING("mouseMaxX"),
	HX_CSTRING("originPoint"),
	HX_CSTRING("xDif"),
	HX_CSTRING("yDif"),
	HX_CSTRING("hyp"),
	HX_CSTRING("moveDirs"),
	HX_CSTRING("mouseDown"),
	HX_CSTRING("gameZoom"),
	HX_CSTRING("multiplier"),
	HX_CSTRING("update"),
	HX_CSTRING("calculateJoystick"),
	HX_CSTRING("positionJostick"),
	HX_CSTRING("noMove"),
	HX_CSTRING("resetJoystick"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Joystick_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Joystick_obj::__mClass,"__mClass");
};

#endif

Class Joystick_obj::__mClass;

void Joystick_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("Joystick"), hx::TCanCast< Joystick_obj> ,sStaticFields,sMemberFields,
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

void Joystick_obj::__boot()
{
}

