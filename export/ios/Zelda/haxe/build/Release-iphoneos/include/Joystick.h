#ifndef INCLUDED_Joystick
#define INCLUDED_Joystick

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <flixel/FlxSprite.h>
HX_DECLARE_CLASS0(Joystick)
HX_DECLARE_CLASS1(flixel,FlxBasic)
HX_DECLARE_CLASS1(flixel,FlxObject)
HX_DECLARE_CLASS1(flixel,FlxSprite)
HX_DECLARE_CLASS2(flixel,interfaces,IFlxDestroyable)
HX_DECLARE_CLASS2(flixel,interfaces,IFlxPooled)
HX_DECLARE_CLASS2(flixel,util,FlxPoint)


class HXCPP_CLASS_ATTRIBUTES  Joystick_obj : public ::flixel::FlxSprite_obj{
	public:
		typedef ::flixel::FlxSprite_obj super;
		typedef Joystick_obj OBJ_;
		Joystick_obj();
		Void __construct(Float X,Float Y,Float RingSize);

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< Joystick_obj > __new(Float X,Float Y,Float RingSize);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~Joystick_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("Joystick"); }

		Float maxDistance;
		int moveIgnoreRange;
		Float moveSpeed;
		Float mouseMaxY;
		Float mouseMaxX;
		::flixel::util::FlxPoint originPoint;
		Float xDif;
		Float yDif;
		Float hyp;
		::flixel::util::FlxPoint moveDirs;
		bool mouseDown;
		Float gameZoom;
		Float multiplier;
		virtual Void update( );

		virtual ::flixel::util::FlxPoint calculateJoystick( );
		Dynamic calculateJoystick_dyn();

		virtual Void positionJostick( );
		Dynamic positionJostick_dyn();

		virtual bool noMove( );
		Dynamic noMove_dyn();

		virtual Void resetJoystick( );
		Dynamic resetJoystick_dyn();

};


#endif /* INCLUDED_Joystick */ 
