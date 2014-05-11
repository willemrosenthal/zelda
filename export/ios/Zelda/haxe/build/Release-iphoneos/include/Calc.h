#ifndef INCLUDED_Calc
#define INCLUDED_Calc

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS0(Calc)
HX_DECLARE_CLASS2(flixel,interfaces,IFlxDestroyable)
HX_DECLARE_CLASS2(flixel,interfaces,IFlxPooled)
HX_DECLARE_CLASS2(flixel,util,FlxPoint)


class HXCPP_CLASS_ATTRIBUTES  Calc_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Calc_obj OBJ_;
		Calc_obj();
		Void __construct();

	public:
		inline void *operator new( size_t inSize, bool inContainer=false)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< Calc_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~Calc_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		::String __ToString() const { return HX_CSTRING("Calc"); }

		static ::flixel::util::FlxPoint randomOnScreen( hx::Null< Float >  Padding,hx::Null< Float >  PaddingY);
		static Dynamic randomOnScreen_dyn();

		static Float plusOrMinus( hx::Null< Float >  Value);
		static Dynamic plusOrMinus_dyn();

		static ::flixel::util::FlxPoint pt;
		static int getTileType( Float X,Float Y);
		static Dynamic getTileType_dyn();

		static ::flixel::util::FlxPoint getTileValue( Float X,Float Y);
		static Dynamic getTileValue_dyn();

		static ::flixel::util::FlxPoint getTilePos( Float X,Float Y);
		static Dynamic getTilePos_dyn();

};


#endif /* INCLUDED_Calc */ 
