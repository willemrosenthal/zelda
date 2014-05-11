#include <hxcpp.h>

#ifndef INCLUDED_Global
#include <Global.h>
#endif
#ifndef INCLUDED_Joystick
#include <Joystick.h>
#endif
#ifndef INCLUDED_PlayState
#include <PlayState.h>
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
#ifndef INCLUDED_flixel_FlxState
#include <flixel/FlxState.h>
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
#ifndef INCLUDED_flixel_tile_FlxTilemap
#include <flixel/tile/FlxTilemap.h>
#endif
#ifndef INCLUDED_openfl_Assets
#include <openfl/Assets.h>
#endif

Void PlayState_obj::__construct()
{
HX_STACK_FRAME("PlayState","new",0xf8bf96cf,"PlayState.new","PlayState.hx",26,0xb30d7781)
HX_STACK_THIS(this)
{
	HX_STACK_LINE(274)
	this->arrayPlaceCounter = (int)0;
	HX_STACK_LINE(67)
	this->gameZoom = (int)3;
	HX_STACK_LINE(50)
	this->counter = (int)0;
	HX_STACK_LINE(49)
	this->scrollTotalFrames = (int)100;
	HX_STACK_LINE(44)
	this->nextDir = HX_CSTRING("none");
	HX_STACK_LINE(41)
	this->nextMap = ::flixel::tile::FlxTilemap_obj::__new();
	HX_STACK_LINE(37)
	this->levelMap = ::flixel::tile::FlxTilemap_obj::__new();
	HX_STACK_LINE(36)
	this->mapy = (int)0;
	HX_STACK_LINE(35)
	this->mapx = (int)0;
	HX_STACK_LINE(31)
	this->mapWidth = (int)10;
	HX_STACK_LINE(30)
	this->mapHeight = (int)10;
	HX_STACK_LINE(75)
	super::__construct(null());
	HX_STACK_LINE(76)
	this->config();
}
;
	return null();
}

//PlayState_obj::~PlayState_obj() { }

Dynamic PlayState_obj::__CreateEmpty() { return  new PlayState_obj; }
hx::ObjectPtr< PlayState_obj > PlayState_obj::__new()
{  hx::ObjectPtr< PlayState_obj > result = new PlayState_obj();
	result->__construct();
	return result;}

Dynamic PlayState_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< PlayState_obj > result = new PlayState_obj();
	result->__construct();
	return result;}

Void PlayState_obj::create( ){
{
		HX_STACK_FRAME("PlayState","create",0x82220fed,"PlayState.create","PlayState.hx",80,0xb30d7781)
		HX_STACK_THIS(this)
		HX_STACK_LINE(81)
		this->super::create();
		HX_STACK_LINE(83)
		::flixel::group::FlxGroup _g = ::flixel::group::FlxGroup_obj::__new(null());		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(83)
		this->map = _g;
		HX_STACK_LINE(84)
		this->map->set_maxSize((int)2);
		HX_STACK_LINE(85)
		this->add(this->map);
		HX_STACK_LINE(87)
		this->buildMap();
		HX_STACK_LINE(89)
		::Player _g1 = ::Player_obj::__new((int)30,(int)30);		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(89)
		this->player = _g1;
		HX_STACK_LINE(90)
		this->add(this->player);
		HX_STACK_LINE(92)
		this->setupHud();
	}
return null();
}


Void PlayState_obj::config( ){
{
		HX_STACK_FRAME("PlayState","config",0xcde4ffb3,"PlayState.config","PlayState.hx",96,0xb30d7781)
		HX_STACK_THIS(this)
		HX_STACK_LINE(97)
		this->gHight = (::Global_obj::tileSize * this->mapHeight);
		HX_STACK_LINE(98)
		this->gWidth = (::Global_obj::tileSize * this->mapWidth);
		HX_STACK_LINE(99)
		this->xScrollSpeed = (int)4;
		HX_STACK_LINE(100)
		this->yScrollSpeed = (int)4;
		HX_STACK_LINE(101)
		this->pSSx = (this->xScrollSpeed * ((Float(((this->mapWidth - 0.8))) / Float(this->mapWidth))));
		HX_STACK_LINE(102)
		this->pSSy = (this->yScrollSpeed * ((Float(((this->mapHeight - 0.8))) / Float(this->mapHeight))));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(PlayState_obj,config,(void))

Void PlayState_obj::buildMap( ){
{
		HX_STACK_FRAME("PlayState","buildMap",0x02761f3f,"PlayState.buildMap","PlayState.hx",106,0xb30d7781)
		HX_STACK_THIS(this)
		HX_STACK_LINE(107)
		this->mapData = ((HX_CSTRING("assets/levels/") + ::Global_obj::levels->__get(::Global_obj::c->__get((int)0)).StaticCast< Array< int > >()->__get(::Global_obj::c->__get((int)1))) + HX_CSTRING(".txt"));
		HX_STACK_LINE(108)
		this->tileSet = HX_CSTRING("assets/tilesets/1.png");
		HX_STACK_LINE(112)
		::String _g = ::openfl::Assets_obj::getText(this->mapData);		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(112)
		this->levelMap->loadMap(_g,this->tileSet,::Global_obj::tileSize,::Global_obj::tileSize,(int)0,(int)0,null(),null());
		HX_STACK_LINE(113)
		this->levelMap->set_x(this->mapx);
		HX_STACK_LINE(114)
		this->levelMap->set_y(this->mapy);
		HX_STACK_LINE(115)
		this->map->add(this->levelMap);
		HX_STACK_LINE(116)
		this->convertMapData();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(PlayState_obj,buildMap,(void))

Void PlayState_obj::buildNextMap( ){
{
		HX_STACK_FRAME("PlayState","buildNextMap",0xd2cf398c,"PlayState.buildNextMap","PlayState.hx",120,0xb30d7781)
		HX_STACK_THIS(this)
		HX_STACK_LINE(121)
		this->nextData = ((HX_CSTRING("assets/levels/") + ::Global_obj::levels->__get(::Global_obj::n->__get((int)0)).StaticCast< Array< int > >()->__get(::Global_obj::n->__get((int)1))) + HX_CSTRING(".txt"));
		HX_STACK_LINE(122)
		this->nextSet = HX_CSTRING("assets/tilesets/1.png");
		HX_STACK_LINE(124)
		::String _g = ::openfl::Assets_obj::getText(this->nextData);		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(124)
		this->nextMap->loadMap(_g,this->nextSet,::Global_obj::tileSize,::Global_obj::tileSize,(int)0,(int)0,null(),null());
		HX_STACK_LINE(126)
		if (((this->nextDir == HX_CSTRING("up")))){
			HX_STACK_LINE(127)
			this->nextMap->set_x(this->levelMap->x);
			HX_STACK_LINE(128)
			this->nextMap->set_y((this->levelMap->y - this->gHight));
		}
		HX_STACK_LINE(130)
		if (((this->nextDir == HX_CSTRING("right")))){
			HX_STACK_LINE(131)
			this->nextMap->set_x((this->levelMap->x + this->gWidth));
			HX_STACK_LINE(132)
			this->nextMap->set_y(this->levelMap->y);
		}
		HX_STACK_LINE(134)
		if (((this->nextDir == HX_CSTRING("down")))){
			HX_STACK_LINE(135)
			this->nextMap->set_x(this->levelMap->x);
			HX_STACK_LINE(136)
			this->nextMap->set_y((this->levelMap->y + this->gHight));
		}
		HX_STACK_LINE(138)
		if (((this->nextDir == HX_CSTRING("left")))){
			HX_STACK_LINE(139)
			this->nextMap->set_x((this->levelMap->x - this->gWidth));
			HX_STACK_LINE(140)
			this->nextMap->set_y(this->levelMap->y);
		}
		HX_STACK_LINE(143)
		this->nextMap->set_visible(true);
		HX_STACK_LINE(145)
		this->map->add(this->nextMap);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(PlayState_obj,buildNextMap,(void))

Void PlayState_obj::setupHud( ){
{
		HX_STACK_FRAME("PlayState","setupHud",0xd1eb4d6b,"PlayState.setupHud","PlayState.hx",148,0xb30d7781)
		HX_STACK_THIS(this)
		HX_STACK_LINE(150)
		::flixel::group::FlxGroup _g = ::flixel::group::FlxGroup_obj::__new(null());		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(150)
		this->border = _g;
		HX_STACK_LINE(151)
		this->add(this->border);
		HX_STACK_LINE(153)
		::flixel::FlxSprite _g1 = ::flixel::FlxSprite_obj::__new((int)0,(int)-8,HX_CSTRING("assets/images/bar_h.png"));		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(153)
		this->tBox = _g1;
		HX_STACK_LINE(154)
		this->border->add(this->tBox);
		HX_STACK_LINE(156)
		::flixel::FlxSprite _g2 = ::flixel::FlxSprite_obj::__new((int)-8,(int)0,HX_CSTRING("assets/images/bar_v.png"));		HX_STACK_VAR(_g2,"_g2");
		HX_STACK_LINE(156)
		this->lBox = _g2;
		HX_STACK_LINE(157)
		this->border->add(this->lBox);
		HX_STACK_LINE(159)
		::flixel::FlxSprite _g3 = ::flixel::FlxSprite_obj::__new((int)0,(this->gHight + (int)8),HX_CSTRING("assets/images/bar_h.png"));		HX_STACK_VAR(_g3,"_g3");
		HX_STACK_LINE(159)
		this->bBox = _g3;
		HX_STACK_LINE(160)
		this->border->add(this->bBox);
		HX_STACK_LINE(162)
		::flixel::FlxSprite _g4 = ::flixel::FlxSprite_obj::__new((this->gWidth + (int)8),(int)0,HX_CSTRING("assets/images/bar_v.png"));		HX_STACK_VAR(_g4,"_g4");
		HX_STACK_LINE(162)
		this->rBox = _g4;
		HX_STACK_LINE(163)
		this->border->add(this->rBox);
		HX_STACK_LINE(166)
		::flixel::group::FlxGroup _g5 = ::flixel::group::FlxGroup_obj::__new(null());		HX_STACK_VAR(_g5,"_g5");
		HX_STACK_LINE(166)
		this->hud = _g5;
		HX_STACK_LINE(167)
		this->add(this->hud);
		HX_STACK_LINE(169)
		Float joyPosX = (::Global_obj::gameWidth * 0.3);		HX_STACK_VAR(joyPosX,"joyPosX");
		HX_STACK_LINE(170)
		Float joyPosY = (::Global_obj::gameHeight * 0.82);		HX_STACK_VAR(joyPosY,"joyPosY");
		HX_STACK_LINE(173)
		::flixel::FlxSprite _g6 = ::flixel::FlxSprite_obj::__new((int)0,(this->gHight + this->levelMap->y),HX_CSTRING("assets/images/blackbox.png"));		HX_STACK_VAR(_g6,"_g6");
		HX_STACK_LINE(173)
		this->blackBox = _g6;
		HX_STACK_LINE(174)
		this->hud->add(this->blackBox);
		HX_STACK_LINE(176)
		::flixel::FlxSprite _g7 = ::flixel::FlxSprite_obj::__new(joyPosX,joyPosY,HX_CSTRING("assets/images/joystick_ring.png"));		HX_STACK_VAR(_g7,"_g7");
		HX_STACK_LINE(176)
		this->joystickBG = _g7;
		HX_STACK_LINE(177)
		{
			HX_STACK_LINE(177)
			::flixel::FlxSprite _g8 = this->joystickBG;		HX_STACK_VAR(_g8,"_g8");
			HX_STACK_LINE(177)
			Float _g81 = this->joystickBG->get_width();		HX_STACK_VAR(_g81,"_g81");
			HX_STACK_LINE(177)
			Float _g9 = (_g81 * 0.5);		HX_STACK_VAR(_g9,"_g9");
			HX_STACK_LINE(177)
			Float _g10 = (_g8->x - _g9);		HX_STACK_VAR(_g10,"_g10");
			HX_STACK_LINE(177)
			_g8->set_x(_g10);
		}
		HX_STACK_LINE(178)
		{
			HX_STACK_LINE(178)
			::flixel::FlxSprite _g8 = this->joystickBG;		HX_STACK_VAR(_g8,"_g8");
			HX_STACK_LINE(178)
			Float _g11 = this->joystickBG->get_height();		HX_STACK_VAR(_g11,"_g11");
			HX_STACK_LINE(178)
			Float _g12 = (_g11 * 0.5);		HX_STACK_VAR(_g12,"_g12");
			HX_STACK_LINE(178)
			Float _g13 = (_g8->y - _g12);		HX_STACK_VAR(_g13,"_g13");
			HX_STACK_LINE(178)
			_g8->set_y(_g13);
		}
		HX_STACK_LINE(179)
		this->hud->add(this->joystickBG);
		HX_STACK_LINE(181)
		Float _g14 = this->joystickBG->get_width();		HX_STACK_VAR(_g14,"_g14");
		HX_STACK_LINE(181)
		::Joystick _g15 = ::Joystick_obj::__new(joyPosX,joyPosY,_g14);		HX_STACK_VAR(_g15,"_g15");
		HX_STACK_LINE(181)
		this->joystick = _g15;
		HX_STACK_LINE(182)
		this->hud->add(this->joystick);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(PlayState_obj,setupHud,(void))

Void PlayState_obj::destroy( ){
{
		HX_STACK_FRAME("PlayState","destroy",0x6ec756e9,"PlayState.destroy","PlayState.hx",192,0xb30d7781)
		HX_STACK_THIS(this)
		HX_STACK_LINE(192)
		this->super::destroy();
	}
return null();
}


Void PlayState_obj::update( ){
{
		HX_STACK_FRAME("PlayState","update",0x8d182efa,"PlayState.update","PlayState.hx",197,0xb30d7781)
		HX_STACK_THIS(this)
		HX_STACK_LINE(198)
		this->super::update();
		HX_STACK_LINE(201)
		::flixel::FlxG_obj::overlap(this->player,this->border,this->touchEdge_dyn(),null());
		HX_STACK_LINE(203)
		if (((::Global_obj::changingScreens == true))){
			HX_STACK_LINE(204)
			this->moveScreens();
		}
	}
return null();
}


Void PlayState_obj::moveScreens( ){
{
		HX_STACK_FRAME("PlayState","moveScreens",0x0c0149e5,"PlayState.moveScreens","PlayState.hx",207,0xb30d7781)
		HX_STACK_THIS(this)
		HX_STACK_LINE(208)
		if (((this->nextDir == HX_CSTRING("up")))){
			HX_STACK_LINE(209)
			{
				HX_STACK_LINE(209)
				::flixel::tile::FlxTilemap _g = this->levelMap;		HX_STACK_VAR(_g,"_g");
				HX_STACK_LINE(209)
				_g->set_y((_g->y + this->yScrollSpeed));
			}
			HX_STACK_LINE(210)
			{
				HX_STACK_LINE(210)
				::flixel::tile::FlxTilemap _g = this->nextMap;		HX_STACK_VAR(_g,"_g");
				HX_STACK_LINE(210)
				_g->set_y((_g->y + this->yScrollSpeed));
			}
			HX_STACK_LINE(211)
			{
				HX_STACK_LINE(211)
				::Player _g = this->player;		HX_STACK_VAR(_g,"_g");
				HX_STACK_LINE(211)
				_g->set_y((_g->y + this->pSSy));
			}
			HX_STACK_LINE(212)
			if (((this->levelMap->y >= this->gHight))){
				HX_STACK_LINE(213)
				this->finishSroll();
			}
		}
		HX_STACK_LINE(215)
		if (((this->nextDir == HX_CSTRING("down")))){
			HX_STACK_LINE(216)
			{
				HX_STACK_LINE(216)
				::flixel::tile::FlxTilemap _g = this->levelMap;		HX_STACK_VAR(_g,"_g");
				HX_STACK_LINE(216)
				_g->set_y((_g->y - this->yScrollSpeed));
			}
			HX_STACK_LINE(217)
			{
				HX_STACK_LINE(217)
				::flixel::tile::FlxTilemap _g = this->nextMap;		HX_STACK_VAR(_g,"_g");
				HX_STACK_LINE(217)
				_g->set_y((_g->y - this->yScrollSpeed));
			}
			HX_STACK_LINE(218)
			{
				HX_STACK_LINE(218)
				::Player _g = this->player;		HX_STACK_VAR(_g,"_g");
				HX_STACK_LINE(218)
				_g->set_y((_g->y - this->pSSy));
			}
			HX_STACK_LINE(219)
			if (((this->levelMap->y <= -(this->gHight)))){
				HX_STACK_LINE(220)
				this->finishSroll();
			}
		}
		HX_STACK_LINE(222)
		if (((this->nextDir == HX_CSTRING("left")))){
			HX_STACK_LINE(223)
			{
				HX_STACK_LINE(223)
				::flixel::tile::FlxTilemap _g = this->levelMap;		HX_STACK_VAR(_g,"_g");
				HX_STACK_LINE(223)
				_g->set_x((_g->x + this->xScrollSpeed));
			}
			HX_STACK_LINE(224)
			{
				HX_STACK_LINE(224)
				::flixel::tile::FlxTilemap _g = this->nextMap;		HX_STACK_VAR(_g,"_g");
				HX_STACK_LINE(224)
				_g->set_x((_g->x + this->xScrollSpeed));
			}
			HX_STACK_LINE(225)
			{
				HX_STACK_LINE(225)
				::Player _g = this->player;		HX_STACK_VAR(_g,"_g");
				HX_STACK_LINE(225)
				_g->set_x((_g->x + this->pSSx));
			}
			HX_STACK_LINE(226)
			if (((this->levelMap->x >= (this->gWidth - this->mapx)))){
				HX_STACK_LINE(227)
				this->finishSroll();
			}
		}
		HX_STACK_LINE(229)
		if (((this->nextDir == HX_CSTRING("right")))){
			HX_STACK_LINE(230)
			{
				HX_STACK_LINE(230)
				::flixel::tile::FlxTilemap _g = this->levelMap;		HX_STACK_VAR(_g,"_g");
				HX_STACK_LINE(230)
				_g->set_x((_g->x - this->xScrollSpeed));
			}
			HX_STACK_LINE(231)
			{
				HX_STACK_LINE(231)
				::flixel::tile::FlxTilemap _g = this->nextMap;		HX_STACK_VAR(_g,"_g");
				HX_STACK_LINE(231)
				_g->set_x((_g->x - this->xScrollSpeed));
			}
			HX_STACK_LINE(232)
			{
				HX_STACK_LINE(232)
				::Player _g = this->player;		HX_STACK_VAR(_g,"_g");
				HX_STACK_LINE(232)
				_g->set_x((_g->x - this->pSSx));
			}
			HX_STACK_LINE(233)
			if (((this->levelMap->x <= (-(this->gWidth) + this->mapx)))){
				HX_STACK_LINE(234)
				this->finishSroll();
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(PlayState_obj,moveScreens,(void))

Void PlayState_obj::finishSroll( ){
{
		HX_STACK_FRAME("PlayState","finishSroll",0xb317118c,"PlayState.finishSroll","PlayState.hx",239,0xb30d7781)
		HX_STACK_THIS(this)
		HX_STACK_LINE(240)
		::Global_obj::changingScreens = false;
		HX_STACK_LINE(241)
		::Global_obj::c = ::Global_obj::n;
		HX_STACK_LINE(242)
		this->nextMap->set_visible(false);
		HX_STACK_LINE(243)
		this->buildMap();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(PlayState_obj,finishSroll,(void))

Void PlayState_obj::touchEdge( ::flixel::FlxSprite Player,::flixel::FlxSprite Edge){
{
		HX_STACK_FRAME("PlayState","touchEdge",0x44ce1b4b,"PlayState.touchEdge","PlayState.hx",246,0xb30d7781)
		HX_STACK_THIS(this)
		HX_STACK_ARG(Player,"Player")
		HX_STACK_ARG(Edge,"Edge")
		HX_STACK_LINE(247)
		if ((::Global_obj::changingScreens)){
			HX_STACK_LINE(248)
			return null();
		}
		HX_STACK_LINE(250)
		::Global_obj::changingScreens = true;
		HX_STACK_LINE(252)
		if (((Edge == this->tBox))){
			HX_STACK_LINE(253)
			this->nextDir = HX_CSTRING("up");
			HX_STACK_LINE(254)
			(::Global_obj::n[(int)0])--;
		}
		else{
			HX_STACK_LINE(256)
			if (((Edge == this->bBox))){
				HX_STACK_LINE(257)
				this->nextDir = HX_CSTRING("down");
				HX_STACK_LINE(258)
				(::Global_obj::n[(int)0])++;
			}
			else{
				HX_STACK_LINE(260)
				if (((Edge == this->rBox))){
					HX_STACK_LINE(261)
					this->nextDir = HX_CSTRING("right");
					HX_STACK_LINE(262)
					(::Global_obj::n[(int)1])++;
				}
				else{
					HX_STACK_LINE(264)
					if (((Edge == this->lBox))){
						HX_STACK_LINE(265)
						this->nextDir = HX_CSTRING("left");
						HX_STACK_LINE(266)
						(::Global_obj::n[(int)1])--;
					}
				}
			}
		}
		HX_STACK_LINE(268)
		::Global_obj::nextDir = this->nextDir;
		HX_STACK_LINE(269)
		this->buildNextMap();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(PlayState_obj,touchEdge,(void))

Void PlayState_obj::convertMapData( ){
{
		HX_STACK_FRAME("PlayState","convertMapData",0x44f0ab24,"PlayState.convertMapData","PlayState.hx",275,0xb30d7781)
		HX_STACK_THIS(this)
		HX_STACK_LINE(276)
		Array< int > _g = Array_obj< int >::__new();		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(276)
		this->dataArray = _g;
		HX_STACK_LINE(277)
		this->arrayPlaceCounter = (int)0;
		HX_STACK_LINE(278)
		Array< int > _g1 = this->levelMap->getData(null());		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(278)
		this->dataArray = _g1;
		HX_STACK_LINE(280)
		Array< ::Dynamic > _g2 = Array_obj< ::Dynamic >::__new();		HX_STACK_VAR(_g2,"_g2");
		HX_STACK_LINE(280)
		this->finalArray = _g2;
		HX_STACK_LINE(281)
		{
			HX_STACK_LINE(281)
			int _g11 = (int)0;		HX_STACK_VAR(_g11,"_g11");
			HX_STACK_LINE(281)
			int _g3 = this->mapHeight;		HX_STACK_VAR(_g3,"_g3");
			HX_STACK_LINE(281)
			while((true)){
				HX_STACK_LINE(281)
				if ((!(((_g11 < _g3))))){
					HX_STACK_LINE(281)
					break;
				}
				HX_STACK_LINE(281)
				int n = (_g11)++;		HX_STACK_VAR(n,"n");
				HX_STACK_LINE(282)
				Array< int > _g31 = Array_obj< int >::__new();		HX_STACK_VAR(_g31,"_g31");
				HX_STACK_LINE(282)
				this->finalArray->push(_g31);
				HX_STACK_LINE(283)
				{
					HX_STACK_LINE(283)
					int _g32 = (int)0;		HX_STACK_VAR(_g32,"_g32");
					HX_STACK_LINE(283)
					int _g21 = this->mapWidth;		HX_STACK_VAR(_g21,"_g21");
					HX_STACK_LINE(283)
					while((true)){
						HX_STACK_LINE(283)
						if ((!(((_g32 < _g21))))){
							HX_STACK_LINE(283)
							break;
						}
						HX_STACK_LINE(283)
						int q = (_g32)++;		HX_STACK_VAR(q,"q");
						HX_STACK_LINE(284)
						this->finalArray->__get(n).StaticCast< Array< int > >()->push(this->dataArray->__get(this->arrayPlaceCounter));
						HX_STACK_LINE(285)
						(this->arrayPlaceCounter)++;
					}
				}
			}
		}
		HX_STACK_LINE(288)
		::Global_obj::cMap = this->finalArray;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(PlayState_obj,convertMapData,(void))


PlayState_obj::PlayState_obj()
{
}

void PlayState_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(PlayState);
	HX_MARK_MEMBER_NAME(mapHeight,"mapHeight");
	HX_MARK_MEMBER_NAME(mapWidth,"mapWidth");
	HX_MARK_MEMBER_NAME(gHight,"gHight");
	HX_MARK_MEMBER_NAME(gWidth,"gWidth");
	HX_MARK_MEMBER_NAME(mapx,"mapx");
	HX_MARK_MEMBER_NAME(mapy,"mapy");
	HX_MARK_MEMBER_NAME(levelMap,"levelMap");
	HX_MARK_MEMBER_NAME(mapData,"mapData");
	HX_MARK_MEMBER_NAME(tileSet,"tileSet");
	HX_MARK_MEMBER_NAME(nextMap,"nextMap");
	HX_MARK_MEMBER_NAME(nextData,"nextData");
	HX_MARK_MEMBER_NAME(nextSet,"nextSet");
	HX_MARK_MEMBER_NAME(nextDir,"nextDir");
	HX_MARK_MEMBER_NAME(xScrollSpeed,"xScrollSpeed");
	HX_MARK_MEMBER_NAME(yScrollSpeed,"yScrollSpeed");
	HX_MARK_MEMBER_NAME(pSSx,"pSSx");
	HX_MARK_MEMBER_NAME(pSSy,"pSSy");
	HX_MARK_MEMBER_NAME(scrollTotalFrames,"scrollTotalFrames");
	HX_MARK_MEMBER_NAME(counter,"counter");
	HX_MARK_MEMBER_NAME(map,"map");
	HX_MARK_MEMBER_NAME(hud,"hud");
	HX_MARK_MEMBER_NAME(border,"border");
	HX_MARK_MEMBER_NAME(joystickBG,"joystickBG");
	HX_MARK_MEMBER_NAME(joystick,"joystick");
	HX_MARK_MEMBER_NAME(tBox,"tBox");
	HX_MARK_MEMBER_NAME(bBox,"bBox");
	HX_MARK_MEMBER_NAME(rBox,"rBox");
	HX_MARK_MEMBER_NAME(lBox,"lBox");
	HX_MARK_MEMBER_NAME(blackBox,"blackBox");
	HX_MARK_MEMBER_NAME(bars,"bars");
	HX_MARK_MEMBER_NAME(gameZoom,"gameZoom");
	HX_MARK_MEMBER_NAME(player,"player");
	HX_MARK_MEMBER_NAME(dataArray,"dataArray");
	HX_MARK_MEMBER_NAME(finalArray,"finalArray");
	HX_MARK_MEMBER_NAME(arrayPlaceCounter,"arrayPlaceCounter");
	::flixel::FlxState_obj::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void PlayState_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(mapHeight,"mapHeight");
	HX_VISIT_MEMBER_NAME(mapWidth,"mapWidth");
	HX_VISIT_MEMBER_NAME(gHight,"gHight");
	HX_VISIT_MEMBER_NAME(gWidth,"gWidth");
	HX_VISIT_MEMBER_NAME(mapx,"mapx");
	HX_VISIT_MEMBER_NAME(mapy,"mapy");
	HX_VISIT_MEMBER_NAME(levelMap,"levelMap");
	HX_VISIT_MEMBER_NAME(mapData,"mapData");
	HX_VISIT_MEMBER_NAME(tileSet,"tileSet");
	HX_VISIT_MEMBER_NAME(nextMap,"nextMap");
	HX_VISIT_MEMBER_NAME(nextData,"nextData");
	HX_VISIT_MEMBER_NAME(nextSet,"nextSet");
	HX_VISIT_MEMBER_NAME(nextDir,"nextDir");
	HX_VISIT_MEMBER_NAME(xScrollSpeed,"xScrollSpeed");
	HX_VISIT_MEMBER_NAME(yScrollSpeed,"yScrollSpeed");
	HX_VISIT_MEMBER_NAME(pSSx,"pSSx");
	HX_VISIT_MEMBER_NAME(pSSy,"pSSy");
	HX_VISIT_MEMBER_NAME(scrollTotalFrames,"scrollTotalFrames");
	HX_VISIT_MEMBER_NAME(counter,"counter");
	HX_VISIT_MEMBER_NAME(map,"map");
	HX_VISIT_MEMBER_NAME(hud,"hud");
	HX_VISIT_MEMBER_NAME(border,"border");
	HX_VISIT_MEMBER_NAME(joystickBG,"joystickBG");
	HX_VISIT_MEMBER_NAME(joystick,"joystick");
	HX_VISIT_MEMBER_NAME(tBox,"tBox");
	HX_VISIT_MEMBER_NAME(bBox,"bBox");
	HX_VISIT_MEMBER_NAME(rBox,"rBox");
	HX_VISIT_MEMBER_NAME(lBox,"lBox");
	HX_VISIT_MEMBER_NAME(blackBox,"blackBox");
	HX_VISIT_MEMBER_NAME(bars,"bars");
	HX_VISIT_MEMBER_NAME(gameZoom,"gameZoom");
	HX_VISIT_MEMBER_NAME(player,"player");
	HX_VISIT_MEMBER_NAME(dataArray,"dataArray");
	HX_VISIT_MEMBER_NAME(finalArray,"finalArray");
	HX_VISIT_MEMBER_NAME(arrayPlaceCounter,"arrayPlaceCounter");
	::flixel::FlxState_obj::__Visit(HX_VISIT_ARG);
}

Dynamic PlayState_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"map") ) { return map; }
		if (HX_FIELD_EQ(inName,"hud") ) { return hud; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"mapx") ) { return mapx; }
		if (HX_FIELD_EQ(inName,"mapy") ) { return mapy; }
		if (HX_FIELD_EQ(inName,"pSSx") ) { return pSSx; }
		if (HX_FIELD_EQ(inName,"pSSy") ) { return pSSy; }
		if (HX_FIELD_EQ(inName,"tBox") ) { return tBox; }
		if (HX_FIELD_EQ(inName,"bBox") ) { return bBox; }
		if (HX_FIELD_EQ(inName,"rBox") ) { return rBox; }
		if (HX_FIELD_EQ(inName,"lBox") ) { return lBox; }
		if (HX_FIELD_EQ(inName,"bars") ) { return bars; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"gHight") ) { return gHight; }
		if (HX_FIELD_EQ(inName,"gWidth") ) { return gWidth; }
		if (HX_FIELD_EQ(inName,"border") ) { return border; }
		if (HX_FIELD_EQ(inName,"player") ) { return player; }
		if (HX_FIELD_EQ(inName,"create") ) { return create_dyn(); }
		if (HX_FIELD_EQ(inName,"config") ) { return config_dyn(); }
		if (HX_FIELD_EQ(inName,"update") ) { return update_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"mapData") ) { return mapData; }
		if (HX_FIELD_EQ(inName,"tileSet") ) { return tileSet; }
		if (HX_FIELD_EQ(inName,"nextMap") ) { return nextMap; }
		if (HX_FIELD_EQ(inName,"nextSet") ) { return nextSet; }
		if (HX_FIELD_EQ(inName,"nextDir") ) { return nextDir; }
		if (HX_FIELD_EQ(inName,"counter") ) { return counter; }
		if (HX_FIELD_EQ(inName,"destroy") ) { return destroy_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"mapWidth") ) { return mapWidth; }
		if (HX_FIELD_EQ(inName,"levelMap") ) { return levelMap; }
		if (HX_FIELD_EQ(inName,"nextData") ) { return nextData; }
		if (HX_FIELD_EQ(inName,"joystick") ) { return joystick; }
		if (HX_FIELD_EQ(inName,"blackBox") ) { return blackBox; }
		if (HX_FIELD_EQ(inName,"gameZoom") ) { return gameZoom; }
		if (HX_FIELD_EQ(inName,"buildMap") ) { return buildMap_dyn(); }
		if (HX_FIELD_EQ(inName,"setupHud") ) { return setupHud_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"mapHeight") ) { return mapHeight; }
		if (HX_FIELD_EQ(inName,"touchEdge") ) { return touchEdge_dyn(); }
		if (HX_FIELD_EQ(inName,"dataArray") ) { return dataArray; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"joystickBG") ) { return joystickBG; }
		if (HX_FIELD_EQ(inName,"finalArray") ) { return finalArray; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"moveScreens") ) { return moveScreens_dyn(); }
		if (HX_FIELD_EQ(inName,"finishSroll") ) { return finishSroll_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"xScrollSpeed") ) { return xScrollSpeed; }
		if (HX_FIELD_EQ(inName,"yScrollSpeed") ) { return yScrollSpeed; }
		if (HX_FIELD_EQ(inName,"buildNextMap") ) { return buildNextMap_dyn(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"convertMapData") ) { return convertMapData_dyn(); }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"scrollTotalFrames") ) { return scrollTotalFrames; }
		if (HX_FIELD_EQ(inName,"arrayPlaceCounter") ) { return arrayPlaceCounter; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic PlayState_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"map") ) { map=inValue.Cast< ::flixel::group::FlxGroup >(); return inValue; }
		if (HX_FIELD_EQ(inName,"hud") ) { hud=inValue.Cast< ::flixel::group::FlxGroup >(); return inValue; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"mapx") ) { mapx=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"mapy") ) { mapy=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"pSSx") ) { pSSx=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"pSSy") ) { pSSy=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"tBox") ) { tBox=inValue.Cast< ::flixel::FlxSprite >(); return inValue; }
		if (HX_FIELD_EQ(inName,"bBox") ) { bBox=inValue.Cast< ::flixel::FlxSprite >(); return inValue; }
		if (HX_FIELD_EQ(inName,"rBox") ) { rBox=inValue.Cast< ::flixel::FlxSprite >(); return inValue; }
		if (HX_FIELD_EQ(inName,"lBox") ) { lBox=inValue.Cast< ::flixel::FlxSprite >(); return inValue; }
		if (HX_FIELD_EQ(inName,"bars") ) { bars=inValue.Cast< Array< ::Dynamic > >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"gHight") ) { gHight=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"gWidth") ) { gWidth=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"border") ) { border=inValue.Cast< ::flixel::group::FlxGroup >(); return inValue; }
		if (HX_FIELD_EQ(inName,"player") ) { player=inValue.Cast< ::Player >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"mapData") ) { mapData=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"tileSet") ) { tileSet=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"nextMap") ) { nextMap=inValue.Cast< ::flixel::tile::FlxTilemap >(); return inValue; }
		if (HX_FIELD_EQ(inName,"nextSet") ) { nextSet=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"nextDir") ) { nextDir=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"counter") ) { counter=inValue.Cast< int >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"mapWidth") ) { mapWidth=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"levelMap") ) { levelMap=inValue.Cast< ::flixel::tile::FlxTilemap >(); return inValue; }
		if (HX_FIELD_EQ(inName,"nextData") ) { nextData=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"joystick") ) { joystick=inValue.Cast< ::Joystick >(); return inValue; }
		if (HX_FIELD_EQ(inName,"blackBox") ) { blackBox=inValue.Cast< ::flixel::FlxSprite >(); return inValue; }
		if (HX_FIELD_EQ(inName,"gameZoom") ) { gameZoom=inValue.Cast< Float >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"mapHeight") ) { mapHeight=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"dataArray") ) { dataArray=inValue.Cast< Array< int > >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"joystickBG") ) { joystickBG=inValue.Cast< ::flixel::FlxSprite >(); return inValue; }
		if (HX_FIELD_EQ(inName,"finalArray") ) { finalArray=inValue.Cast< Array< ::Dynamic > >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"xScrollSpeed") ) { xScrollSpeed=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"yScrollSpeed") ) { yScrollSpeed=inValue.Cast< Float >(); return inValue; }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"scrollTotalFrames") ) { scrollTotalFrames=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"arrayPlaceCounter") ) { arrayPlaceCounter=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void PlayState_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("mapHeight"));
	outFields->push(HX_CSTRING("mapWidth"));
	outFields->push(HX_CSTRING("gHight"));
	outFields->push(HX_CSTRING("gWidth"));
	outFields->push(HX_CSTRING("mapx"));
	outFields->push(HX_CSTRING("mapy"));
	outFields->push(HX_CSTRING("levelMap"));
	outFields->push(HX_CSTRING("mapData"));
	outFields->push(HX_CSTRING("tileSet"));
	outFields->push(HX_CSTRING("nextMap"));
	outFields->push(HX_CSTRING("nextData"));
	outFields->push(HX_CSTRING("nextSet"));
	outFields->push(HX_CSTRING("nextDir"));
	outFields->push(HX_CSTRING("xScrollSpeed"));
	outFields->push(HX_CSTRING("yScrollSpeed"));
	outFields->push(HX_CSTRING("pSSx"));
	outFields->push(HX_CSTRING("pSSy"));
	outFields->push(HX_CSTRING("scrollTotalFrames"));
	outFields->push(HX_CSTRING("counter"));
	outFields->push(HX_CSTRING("map"));
	outFields->push(HX_CSTRING("hud"));
	outFields->push(HX_CSTRING("border"));
	outFields->push(HX_CSTRING("joystickBG"));
	outFields->push(HX_CSTRING("joystick"));
	outFields->push(HX_CSTRING("tBox"));
	outFields->push(HX_CSTRING("bBox"));
	outFields->push(HX_CSTRING("rBox"));
	outFields->push(HX_CSTRING("lBox"));
	outFields->push(HX_CSTRING("blackBox"));
	outFields->push(HX_CSTRING("bars"));
	outFields->push(HX_CSTRING("gameZoom"));
	outFields->push(HX_CSTRING("player"));
	outFields->push(HX_CSTRING("dataArray"));
	outFields->push(HX_CSTRING("finalArray"));
	outFields->push(HX_CSTRING("arrayPlaceCounter"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsInt,(int)offsetof(PlayState_obj,mapHeight),HX_CSTRING("mapHeight")},
	{hx::fsInt,(int)offsetof(PlayState_obj,mapWidth),HX_CSTRING("mapWidth")},
	{hx::fsInt,(int)offsetof(PlayState_obj,gHight),HX_CSTRING("gHight")},
	{hx::fsInt,(int)offsetof(PlayState_obj,gWidth),HX_CSTRING("gWidth")},
	{hx::fsFloat,(int)offsetof(PlayState_obj,mapx),HX_CSTRING("mapx")},
	{hx::fsFloat,(int)offsetof(PlayState_obj,mapy),HX_CSTRING("mapy")},
	{hx::fsObject /*::flixel::tile::FlxTilemap*/ ,(int)offsetof(PlayState_obj,levelMap),HX_CSTRING("levelMap")},
	{hx::fsString,(int)offsetof(PlayState_obj,mapData),HX_CSTRING("mapData")},
	{hx::fsString,(int)offsetof(PlayState_obj,tileSet),HX_CSTRING("tileSet")},
	{hx::fsObject /*::flixel::tile::FlxTilemap*/ ,(int)offsetof(PlayState_obj,nextMap),HX_CSTRING("nextMap")},
	{hx::fsString,(int)offsetof(PlayState_obj,nextData),HX_CSTRING("nextData")},
	{hx::fsString,(int)offsetof(PlayState_obj,nextSet),HX_CSTRING("nextSet")},
	{hx::fsString,(int)offsetof(PlayState_obj,nextDir),HX_CSTRING("nextDir")},
	{hx::fsFloat,(int)offsetof(PlayState_obj,xScrollSpeed),HX_CSTRING("xScrollSpeed")},
	{hx::fsFloat,(int)offsetof(PlayState_obj,yScrollSpeed),HX_CSTRING("yScrollSpeed")},
	{hx::fsFloat,(int)offsetof(PlayState_obj,pSSx),HX_CSTRING("pSSx")},
	{hx::fsFloat,(int)offsetof(PlayState_obj,pSSy),HX_CSTRING("pSSy")},
	{hx::fsFloat,(int)offsetof(PlayState_obj,scrollTotalFrames),HX_CSTRING("scrollTotalFrames")},
	{hx::fsInt,(int)offsetof(PlayState_obj,counter),HX_CSTRING("counter")},
	{hx::fsObject /*::flixel::group::FlxGroup*/ ,(int)offsetof(PlayState_obj,map),HX_CSTRING("map")},
	{hx::fsObject /*::flixel::group::FlxGroup*/ ,(int)offsetof(PlayState_obj,hud),HX_CSTRING("hud")},
	{hx::fsObject /*::flixel::group::FlxGroup*/ ,(int)offsetof(PlayState_obj,border),HX_CSTRING("border")},
	{hx::fsObject /*::flixel::FlxSprite*/ ,(int)offsetof(PlayState_obj,joystickBG),HX_CSTRING("joystickBG")},
	{hx::fsObject /*::Joystick*/ ,(int)offsetof(PlayState_obj,joystick),HX_CSTRING("joystick")},
	{hx::fsObject /*::flixel::FlxSprite*/ ,(int)offsetof(PlayState_obj,tBox),HX_CSTRING("tBox")},
	{hx::fsObject /*::flixel::FlxSprite*/ ,(int)offsetof(PlayState_obj,bBox),HX_CSTRING("bBox")},
	{hx::fsObject /*::flixel::FlxSprite*/ ,(int)offsetof(PlayState_obj,rBox),HX_CSTRING("rBox")},
	{hx::fsObject /*::flixel::FlxSprite*/ ,(int)offsetof(PlayState_obj,lBox),HX_CSTRING("lBox")},
	{hx::fsObject /*::flixel::FlxSprite*/ ,(int)offsetof(PlayState_obj,blackBox),HX_CSTRING("blackBox")},
	{hx::fsObject /*Array< ::Dynamic >*/ ,(int)offsetof(PlayState_obj,bars),HX_CSTRING("bars")},
	{hx::fsFloat,(int)offsetof(PlayState_obj,gameZoom),HX_CSTRING("gameZoom")},
	{hx::fsObject /*::Player*/ ,(int)offsetof(PlayState_obj,player),HX_CSTRING("player")},
	{hx::fsObject /*Array< int >*/ ,(int)offsetof(PlayState_obj,dataArray),HX_CSTRING("dataArray")},
	{hx::fsObject /*Array< ::Dynamic >*/ ,(int)offsetof(PlayState_obj,finalArray),HX_CSTRING("finalArray")},
	{hx::fsInt,(int)offsetof(PlayState_obj,arrayPlaceCounter),HX_CSTRING("arrayPlaceCounter")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("mapHeight"),
	HX_CSTRING("mapWidth"),
	HX_CSTRING("gHight"),
	HX_CSTRING("gWidth"),
	HX_CSTRING("mapx"),
	HX_CSTRING("mapy"),
	HX_CSTRING("levelMap"),
	HX_CSTRING("mapData"),
	HX_CSTRING("tileSet"),
	HX_CSTRING("nextMap"),
	HX_CSTRING("nextData"),
	HX_CSTRING("nextSet"),
	HX_CSTRING("nextDir"),
	HX_CSTRING("xScrollSpeed"),
	HX_CSTRING("yScrollSpeed"),
	HX_CSTRING("pSSx"),
	HX_CSTRING("pSSy"),
	HX_CSTRING("scrollTotalFrames"),
	HX_CSTRING("counter"),
	HX_CSTRING("map"),
	HX_CSTRING("hud"),
	HX_CSTRING("border"),
	HX_CSTRING("joystickBG"),
	HX_CSTRING("joystick"),
	HX_CSTRING("tBox"),
	HX_CSTRING("bBox"),
	HX_CSTRING("rBox"),
	HX_CSTRING("lBox"),
	HX_CSTRING("blackBox"),
	HX_CSTRING("bars"),
	HX_CSTRING("gameZoom"),
	HX_CSTRING("player"),
	HX_CSTRING("create"),
	HX_CSTRING("config"),
	HX_CSTRING("buildMap"),
	HX_CSTRING("buildNextMap"),
	HX_CSTRING("setupHud"),
	HX_CSTRING("destroy"),
	HX_CSTRING("update"),
	HX_CSTRING("moveScreens"),
	HX_CSTRING("finishSroll"),
	HX_CSTRING("touchEdge"),
	HX_CSTRING("dataArray"),
	HX_CSTRING("finalArray"),
	HX_CSTRING("arrayPlaceCounter"),
	HX_CSTRING("convertMapData"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(PlayState_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(PlayState_obj::__mClass,"__mClass");
};

#endif

Class PlayState_obj::__mClass;

void PlayState_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("PlayState"), hx::TCanCast< PlayState_obj> ,sStaticFields,sMemberFields,
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

void PlayState_obj::__boot()
{
}

