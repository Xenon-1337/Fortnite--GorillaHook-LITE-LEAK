#pragma once
#include "stdafx.h"
#include "UnrealLoop.h"

using PostRoutine = void(*)(uintptr_t _this, uintptr_t canvas);
PostRoutine PostRoutineDown = 0;

bool ShowMenu = 1;

class UControl
{
public:

	Vector2 Origin;
	Vector2 Size;
	bool* BoundBool = nullptr;
	bool bIsMenuTabControl;
	bool bIsRangeSlider;
	int RangeValueMin;
	int RangeValueMax;
	int* pBoundRangeValue;
	int BoundMenuTabIndex;

	bool ContainsPoint(Vector2 pt)
	{
		auto extent = Origin + Size;
		return (pt.x > Origin.x && pt.y > Origin.y && pt.x < extent.x&& pt.y < extent.y);
	}
};

std::vector<UControl>* g_ControlBoundsList;

void drawFilledRect(const Vector2& initial_pos, float w, float h, const UnrealStructs::FLinearColor& color);

void RegisterButtonControl(const Vector2 initial_pos, float w, float h, const UnrealStructs::FLinearColor color, int tabIndex = -1, bool* boundBool = nullptr)
{
	drawFilledRect(initial_pos, w, h, color);
	UControl bounds;
	bounds.Origin = initial_pos;
	bounds.Size = { w, h };
	if (tabIndex != -1)
	{
		bounds.bIsMenuTabControl = true;
		bounds.BoundMenuTabIndex = tabIndex;
	}
	else
	{
		bounds.BoundBool = boundBool;
		bounds.bIsMenuTabControl = false;
	}
	g_ControlBoundsList->push_back(bounds);
}

void drawRect(const Vector2 initial_pos, float w, float h, const UnrealStructs::FLinearColor color, float thickness = 1.f);

void RegisterButtonControlRect(const Vector2 initial_pos, float w, float h, const UnrealStructs::FLinearColor color, int tabIndex = -1, bool* boundBool = nullptr)
{
	drawRect(initial_pos, w, h, color, 1.f);
	UControl bounds;
	bounds.Origin = initial_pos;
	bounds.Size = { w, h };
	if (tabIndex != -1)
	{
		bounds.bIsMenuTabControl = true;
		bounds.BoundMenuTabIndex = tabIndex;
	}
	else
	{
		bounds.BoundBool = boundBool;
		bounds.bIsMenuTabControl = false;
	}
	g_ControlBoundsList->push_back(bounds);
}


void S2(Vector2 sp, UnrealStructs::FLinearColor color, const wchar_t* string)
{
	static_canvas->K2_DrawText(sp, color, string);
}

Vector2 g_Clientarea;

Vector2 g_MenuInitialPos = { 100, 100 };

static int g_MenuIndex = 2;





UnrealStructs::FLinearColor SkeetMenuOutline = Colors::Black;




int g_MenuW = 700;
int g_MenuH = 470;





struct keys




{
	bool mouse[4] = {};
	bool key[256] = {};
	float mouse_wheel = 0.f;
	int16_t mouseX = 0;
	int16_t mouseY = 0;
};




keys* k;





wchar_t* s2wc(const char* c)
{
	const size_t cSize = strlen(c) + 1;
	wchar_t* wc = new wchar_t[cSize];
	mbstowcs(wc, c, cSize);

	return wc;
}





void MenuDrawTabs()
{
	std::vector<const wchar_t*> pTabs;

	wchar_t strAimbot[7];
	memcpy(strAimbot, (L"Aimbot"), 7 * 2);

	wchar_t strVisuals[7];
	memcpy(strVisuals, (L"Visuals"), 8 * 2);

	wchar_t strMods[7];
	memcpy(strMods, (L"Mods"), 5 * 2);

	wchar_t strMisc[7];
	memcpy(strMisc, (L"Misc"), 5 * 2);

	pTabs.push_back(strAimbot);
	pTabs.push_back(strVisuals);
	pTabs.push_back(strMods);
	pTabs.push_back(strMisc);

	auto inp = g_MenuInitialPos + Vector2({ 20, 35 });

	static char logo_buff[256];
	static wchar_t logo_buff_wide[256];
	sprintf(logo_buff, "GorillaHook LITE Free - Life Is One! - BuildDate: " __DATE__ " " __TIME__);
	AnsiToWide(logo_buff, logo_buff_wide);
	drawFilledRect(g_MenuInitialPos, 724, 25, Colors::Red);
	static_canvas->K2_DrawText(g_MenuInitialPos + Vector2({ 5, 4 }), Colors::Black , logo_buff_wide, false);

	auto tabsz = (g_MenuW - 40) / pTabs.size();
	tabsz -= 2;
	Vector2 ip = inp + Vector2(2, 2);

	auto i = 0;
	for (int fuck = 0; fuck < pTabs.size(); fuck++)
	{
		auto tab = pTabs.at(fuck);

		auto clr2 = Colors::DarkRed;

		POINT tellerwäscher;
		GetCursorPos(&tellerwäscher);

		bool hover = tellerwäscher.x > ip.x && tellerwäscher.x < (ip.x + tabsz) && tellerwäscher.y > ip.y && tellerwäscher.y < (ip.y + 22);

		if (hover)
		{
			clr2 = Colors::DarkSlateGray;

		}

		if (g_MenuIndex == i)
		{
			clr2 = Colors::DarkSlateGray;

		}

		RegisterButtonControl(ip, tabsz - 10, 25, clr2, i);
		RegisterButtonControlRect(ip, tabsz - 10, 25, Colors::White, i);

		static_canvas->K2_DrawText({ ip.x + tabsz / 2 - (lstrlenW((LPCWSTR)tab) * 10) / 2, ip.y + 5 }, Colors::White, tab, false);

		ip.x += tabsz + 10;
		i++;
	}

	g_Clientarea = inp + Vector2(0, 35);
}







void MenuSlider(Vector2 sp, const wchar_t* text, int* shittobind, int min, int max);







void RegisterSliderControl(Vector2 initial_pos, float w, float h, const UnrealStructs::FLinearColor Color, int* boundShit, int min, int max)
{
	drawFilledRect(initial_pos, w, h, Color);
	UControl bounds;
	initial_pos.y -= 10;
	h += 10;
	bounds.Origin = initial_pos;
	bounds.Size = { w, h };
	bounds.BoundMenuTabIndex = 0;
	bounds.bIsMenuTabControl = false;
	bounds.pBoundRangeValue = boundShit;
	bounds.RangeValueMin = min;
	bounds.RangeValueMax = max;
	bounds.bIsRangeSlider = true;
	g_ControlBoundsList->push_back(bounds);
}





float g_SliderScale;





int active_hotkey = -1;
bool already_pressed = false;
int elements_count = 0;






std::string VirtualKeyCodeToString(UCHAR virtualKey)
{
	UINT scanCode = MapVirtualKey(virtualKey, MAPVK_VK_TO_VSC);

	if (virtualKey == VK_LBUTTON)
	{
		return ("MOUSE0");
	}
	if (virtualKey == VK_RBUTTON)
	{
		return ("MOUSE1");
	}
	if (virtualKey == VK_MBUTTON)
	{
		return ("MBUTTON");
	}
	if (virtualKey == VK_XBUTTON1)
	{
		return ("XBUTTON1");
	}
	if (virtualKey == VK_XBUTTON2)
	{
		return ("XBUTTON2");
	}

	CHAR szName[128];
	int result = 0;
	switch (virtualKey)
	{
	case VK_LEFT: case VK_UP: case VK_RIGHT: case VK_DOWN:
	case VK_RCONTROL: case VK_RMENU:
	case VK_LWIN: case VK_RWIN: case VK_APPS:
	case VK_PRIOR: case VK_NEXT:
	case VK_END: case VK_HOME:
	case VK_INSERT: case VK_DELETE:
	case VK_DIVIDE:
	case VK_NUMLOCK:
		scanCode |= KF_EXTENDED;
	default:
		result = GetKeyNameTextA(scanCode << 16, szName, 128);
	}

	return szName;
}







void MenuSlider(Vector2 sp, const wchar_t* text, int* shittobind, int min, int max)
{
	g_SliderScale = 462;//g_MenuW * 0.5;

	sp.y += 30;
	RegisterSliderControl(sp + g_Clientarea, g_SliderScale, 4, Colors::Black, shittobind, min, max);
	auto sp1 = sp + g_Clientarea + Vector2((*shittobind) * ((g_SliderScale) / (max - min)), 0);
	auto sp2 = sp1;
	sp2.y -= 5;
	sp1.y += 5;

	auto textpos = g_Clientarea + sp + Vector2({ 0, -26 });

	static_canvas->K2_DrawLine(sp1, sp2, 5, SkeetMenuOutline);
}

void Render_Key(Vector2& loc_ref, const wchar_t* name, bool* on);

void Render_Slider(const wchar_t* name, float minimum, float maximum, float* val, Vector2* loc);

void Render_Toggle(Vector2& loc_ref, const wchar_t* name, bool* on);

bool RBUTTON = true;





void MenuDrawItemsFor(int index)
{
	if (index == 0)
	{
		auto loc = g_Clientarea;
		Render_Toggle(loc, L"Enable Aimbot", &G::AimbotEnable);
		loc.y = loc.y + 10;
		loc.y = loc.y + 10;
		Render_Slider(L"Aimbot Smooth", 0, 20, &G::Smooth, &loc);
		loc.y = loc.y + 10;
		loc.y = loc.y + 10;
		Render_Slider(L"Aimbot Fov", 0, 360, &G::AimFovValue, &loc);
		loc.y = loc.y + 10;
		loc.y = loc.y + 10;
		Render_Slider(L"Aimbot Max Distance", 0, 500, &G::AimbotDist, &loc);
		auto nextloc = g_Clientarea;
		nextloc.x += g_MenuW / 3 + 25;
		static_canvas->K2_DrawText(nextloc, Colors::White, L"  Aimbot Bone: ", false);
		nextloc.y = nextloc.y + 10;
		nextloc.y = nextloc.y + 10;
		Render_Toggle(nextloc, L"Head", &G::Head);
		if (G::Head)
		{
			G::Neck = false;
			G::Chest = false;
			G::Pelvis = false;
		}
		Render_Toggle(nextloc, L"Neck", &G::Neck);
		if (G::Neck)
		{
			G::Head = false;
			G::Chest = false;
			G::Pelvis = false;
		}
		Render_Toggle(nextloc, L"Chest", &G::Chest);
		if (G::Chest)
		{
			G::Head = false;
			G::Neck = false;
			G::Pelvis = false;
		}
		Render_Toggle(nextloc, L"Pelvis", &G::Pelvis);
		if (G::Pelvis)
		{
			G::Head = false;
			G::Neck = false;
			G::Chest = false;
		}
		auto nextnextloc = g_Clientarea;
		nextnextloc.x += g_MenuW / 2 + 105;
		static_canvas->K2_DrawText(nextnextloc, Colors::White, L"  RISK: ", false);
		nextnextloc.y = nextnextloc.y + 10;
		nextnextloc.y = nextnextloc.y + 10;
		Render_Toggle(nextnextloc, L"Memory", &G::pMem);
		Render_Toggle(nextnextloc, L"Silent V2 (Stick Perfect)", &G::pSilent);
		Render_Toggle(nextnextloc, L"Silent V3 (Stick Stick)", &G::StickySilent);
		if (G::StickySilent || G::pSilent)
		{
			Render_Toggle(nextnextloc, L"Spinbot (Buggy)", &G::Spinbot);
			Render_Toggle(nextnextloc, L"Reset Camera Rotation", &G::Baim);
		}

	}
	if (index == 1)
	{
		auto loc = g_Clientarea;
		static_canvas->K2_DrawText(loc, Colors::White, L"  Environment: ", false);
		loc.y = loc.y + 10;
		loc.y = loc.y + 10;
		Render_Toggle(loc, L"Loot", &G::EspLoot);
		loc.y = loc.y + 10;
		loc.y = loc.y + 10;
		Render_Slider(L"Loot Max Distance", 0, 1000, &G::LootRenderDist, &loc);
		loc.y = loc.y + 10;
		loc.y = loc.y + 10;
		Render_Slider(L"Chest Max Distance", 0, 1000, &G::ChestsRdist, &loc);
		loc.y = loc.y + 10;
		loc.y = loc.y + 10;
		Render_Toggle(loc, L"Vehicles", &G::EspVehicles);
		loc.y = loc.y + 10;
		Render_Slider(L"Vehicles Max Distance", 0, 1000, &G::VehicleRdist, &loc);
		loc.y = loc.y + 10;
		loc.y = loc.y + 10;
		Render_Toggle(loc, L"Projectiles/Traps", &G::Projectiles);
		auto nextloc = g_Clientarea;
		nextloc.x += g_MenuW / 3 + 25;
		static_canvas->K2_DrawText(nextloc, Colors::White, L"  Players: ", false);
		nextloc.y = nextloc.y + 10;
		nextloc.y = nextloc.y + 10;
		Render_Toggle(nextloc, L"Box", &G::EspBox);
		Render_Toggle(nextloc, L"Name", &G::EspPlayerName);
		Render_Toggle(nextloc, L"Skeleton", &G::Skeletons);
		Render_Toggle(nextloc, L"Weapon/Active Item", &G::EspWeapon);
		auto nextnextloc = g_Clientarea;
		nextnextloc.x += g_MenuW / 2 + 105;
		static_canvas->K2_DrawText(nextnextloc, Colors::Black, L"  Misc: ", false);
		nextnextloc.y = nextnextloc.y + 10;
		nextnextloc.y = nextnextloc.y + 10;
		Render_Toggle(nextnextloc, L"Aimbot Indicators", &G::PunktierSnaplines);
		Render_Toggle(nextnextloc, L"Aimbot FOV Circle", &G::AimbotFovCircle);
		Render_Toggle(nextnextloc, L"Crosshair", &G::Crosshair);
		Render_Toggle(nextnextloc, L"Visibility Check", &G::VisibleCheck);
	}
	if (index == 2)
	{
		auto loc = g_Clientarea;
		Render_Toggle(loc, L"Anti Aim", &G::AntiAim);
		Render_Toggle(loc, L"No Bloom", &G::NoBloom);
		Render_Toggle(loc, L"No Spread", &G::NoSpread);
		Render_Toggle(loc, L"Vehicle Fly", &G::VehicleFly);
		Render_Toggle(loc, L"Vehicle TP To Player (L-Shift) (Doesnt Work With Vehicle Flight)", &G::VehicleTp);
		Render_Toggle(loc, L"Vehicle Memes (L-Shift) (Doesnt Work With Vehicle TP)", &G::PlayerSpeedBalls);
		Render_Toggle(loc, L"Instant Revive", &G::Norevive);
		Render_Toggle(loc, L"Aim While Jumping", &G::AimWhileJumping);
		Render_Toggle(loc, L"Instant Reload", &G::InfAmmo);
		Render_Toggle(loc, L"Teleport To Players Within 4m (10 With Pickaxe) Or Teleport Downed Players To You.", &G::NoClip);
		Render_Toggle(loc, L"Camera FOV Changer", &G::CameraFovChanger);
		Render_Slider(L"", 0, 180, &G::CamFovValue, &loc);
		loc.y = loc.y + 10;
		Render_Toggle(loc, L"Sniper Bullet Teleport", &G::ProjectileTpEnable);
		//Render_Toggle(loc, L"Player Fly", &G::PlayerFly);
	}
	if (index == 3)
	{
		auto loc = g_Clientarea;
		loc.x += 35.f;
		static_canvas->K2_DrawText(loc, Colors::White, L"Luksius#0001 (ONLY HELP QUESTIONS)", false);
	}

}





void drawRect(const Vector2 initial_pos, float w, float h, const UnrealStructs::FLinearColor color, float thickness)
{
	static_canvas->K2_DrawLine(initial_pos, Vector2(initial_pos.x + w, initial_pos.y), thickness, color);
	static_canvas->K2_DrawLine(initial_pos, Vector2(initial_pos.x, initial_pos.y + h), thickness, color);
	static_canvas->K2_DrawLine(Vector2(initial_pos.x + w, initial_pos.y), Vector2(initial_pos.x + w, initial_pos.y + h), thickness, color);
	static_canvas->K2_DrawLine(Vector2(initial_pos.x, initial_pos.y + h), Vector2(initial_pos.x + w, initial_pos.y + h), thickness, color);
}

void drawFilledRect(const Vector2& initial_pos, float w, float h, const UnrealStructs::FLinearColor& color)
{
	for (float i = 0.f; i < h; i += 1.f)
		static_canvas->K2_DrawLine(Vector2(initial_pos.x, initial_pos.y + i), Vector2(initial_pos.x + w, initial_pos.y + i), 1.f, color);
}

int g_MX = 0;
int g_MY = 0;

void Render_Line(Vector2 one, Vector2 two, UnrealStructs::FLinearColor color)
{
	static_canvas->K2_DrawLine(one, two, 1, color);
}

void Render_Circle(Vector2 pos, int r, UnrealStructs::FLinearColor color)
{
	float circum = M_PI * 2.f * r;
	int seg = myceilf(circum);

	if (seg > MAX_SEGMENTS) seg = MAX_SEGMENTS;

	float theta = 0.f;
	float step = 180.f / seg;

	for (size_t i = 0; i < seg; ++i)
	{
		theta = i * step;
		auto delta = Vector2(round(r * sin(D2R(theta))), round(r * cos(D2R(theta))));
		Render_Line(pos + delta, pos - delta, color);
	}
}

void Render_Clear(Vector2 one, Vector2 two, UnrealStructs::FLinearColor color)
{
	for (auto x = one.x; x < two.x; x += 1.f)
	{
		static_canvas->K2_DrawLine(Vector2(x, one.y), Vector2(x, two.y), 1, color);
	}
}


void Render_PointArray(size_t count, Vector2* ary, UnrealStructs::FLinearColor color)
{
	for (size_t i = 1; i < count; ++i)
		Render_Line(ary[i - 1], ary[i], color);
}

void Render_CircleOutline(Vector2 pos, int r, UnrealStructs::FLinearColor outline)
{
	float circum = M_PI * 2.f * r;
	int seg = myceilf(circum);

	if (seg > MAX_SEGMENTS) seg = MAX_SEGMENTS;

	float theta = 0.f;
	float step = 360.f / seg;

	Vector2 points[MAX_SEGMENTS] = {};

	for (size_t i = 0; i < seg; ++i)
	{
		theta = i * step;
		points[i] = Vector2(pos.x + roundf(r * sin(D2R(theta))), pos.y + roundf(r * cos(D2R(theta))));
	}

	Render_PointArray(seg, points, outline);
}

void Render_CircleOutlined(Vector2 pos, int r, UnrealStructs::FLinearColor fill, UnrealStructs::FLinearColor outline)
{
	Render_Circle(pos, r, fill);
	Render_CircleOutline(pos, r, outline);
}

void Render_MenuText(const wchar_t* text, UnrealStructs::FLinearColor col, Vector2 loc, bool centered)
{
	//	ctx->Canvas->K2_DrawText(ctx->menu_font(), _X(L"Colors"), FVector2D(tabx + tab_width / 2.f - 2.f, menu_y + 31), (i == tab_index) ? FLinearColor(1.f, 1.f, 1.f, 1.f) : menu_color1, 1.f, FLinearColor(), FVector2D(), true, true, true, FLinearColor(0, 0, 0, 1.f));
	static_canvas->K2_DrawText(loc, col, text, false);
}

void Render_Hotkey(Vector2& loc_ref, int* key)
{
	auto loc = &loc_ref;

	auto niggerballs = Vector2{ 125, 30 };

	POINT GetMiouseopPio;
	GetCursorPos(&GetMiouseopPio);

	drawFilledRect(Vector2(loc->x, loc->y), niggerballs.x, niggerballs.y, Colors::Red);

	bool hover = GetMiouseopPio.x > loc->x && GetMiouseopPio.x < (loc->x + 64) && GetMiouseopPio.y > loc->y && GetMiouseopPio.y < (loc->y + 20);

	if (hover && GetAsyncKeyState(VK_LBUTTON) & 1)
	{
		*key = !*key;
	}

	Render_MenuText(s2wc((char*)VirtualKeyCodeToString(*key).c_str()), Colors::Black, { loc->x + niggerballs.x / 2 - (lstrlenW((LPCWSTR)VirtualKeyCodeToString(*key).c_str()) * 10) / 2, loc->y + 5 }, false);

	if (hover)
	{
		if (GetAsyncKeyState(VK_LBUTTON))
		{
			already_pressed = true;
			active_hotkey = elements_count;

			//Queue Fix
			for (int code = 0; code < 255; code++)
				if (GetAsyncKeyState(code)) {}
		}
	}
	else
	{
		if (GetAsyncKeyState(VK_LBUTTON))
		{
			active_hotkey = -1;
		}
	}

	loc->y += 20.0f;
}

void MwMenuDraw()
{
	drawFilledRect(g_MenuInitialPos, 725 - 2, g_MenuH - 2, Colors::Black);
	MenuDrawTabs();
	MenuDrawItemsFor(g_MenuIndex);
	POINT GetMiouseopPio;
	GetCursorPos(&GetMiouseopPio);
	drawFilledRect({ (float)GetMiouseopPio.x - 2, (float)GetMiouseopPio.y - 1 }, 6, 6, Colors::Black);
}


void Render_Slider(const wchar_t* name, float minimum, float maximum, float* val, Vector2* loc)
{
	//auto menu_color1 = FLinearColor(0.8f, 0.f, 0.4f, 1.f);
	auto kinda_white = UnrealStructs::FLinearColor(0.8f, 0.8f, 0.8f, 1.f);

	constexpr float _width = 135;

	////ctx->Canvas->K2_DrawText(ctx->menu_font(), name, FVector2D(loc->X + 6, loc->Y + 10), FLinearColor(255, 255, 255, 255), 1.f, FLinearColor(), FVector2D(), false, true, true, FLinearColor(0, 0, 0, 255));
	POINT GetMiouseopPio;
	GetCursorPos(&GetMiouseopPio);

	bool hover = GetMiouseopPio.x > loc->x && GetMiouseopPio.x < (loc->x + _width) && GetMiouseopPio.y > loc->y && GetMiouseopPio.y < (loc->y + 30);
	if (hover && GetAsyncKeyState(VK_LBUTTON))
	{
		float ratio = (float)(GetMiouseopPio.x - loc->x) / _width;
		if (ratio < 0.f) ratio = 0.f;
		if (ratio > 1.f) ratio = 1.f;
		*val = minimum + ((maximum - minimum) * ratio);
	}

	int xpos = ((*val - minimum) / (maximum - minimum)) * _width;
	loc->y += 24.f;

	wchar_t wstrAAA[16] = {};
	char __strAAA[16] = {};
	sprintf(__strAAA, "%0.2f", minimum);
	AnsiToWide(__strAAA, wstrAAA);

	wchar_t wstrAA[16] = {};
	char __strAA[16] = {};
	sprintf(__strAA, "%0.2f", maximum);
	AnsiToWide(__strAA, wstrAA);

	Render_MenuText(wstrAAA, Colors::White, Vector2(loc->x + 6, loc->y + 6), false);  //Minimum

	Render_MenuText(wstrAA, Colors::White, Vector2(loc->x + _width - 6, loc->y + 6), false);  //Maximum

	drawFilledRect(Vector2(loc->x + xpos - 10, loc->y + 10), 55, 40, Colors::Black);

	drawFilledRect(*loc, _width, 3, Colors::White);

	drawFilledRect(Vector2(loc->x, loc->y), _width, 3, kinda_white);

	drawFilledRect(Vector2(loc->x + xpos, loc->y - 5), 5, 12, Colors::White);

	loc->y -= 24.f;

	wchar_t wstr[16] = {};
	char __str[16] = {};
	sprintf(__str, "%0.2f", *val);
	AnsiToWide(__str, wstr);
	////ctx->Canvas->K2_DrawText(ctx->menu_font(), FString(wstr), FVector2D(loc->X + _width - 20.f, loc->Y + 10), FLinearColor(255, 255, 255, 255), 1.f, FLinearColor(), FVector2D(), false, true, false, FLinearColor());

	Render_MenuText(wstr, Colors::White, Vector2(loc->x + xpos, loc->y + 35), false);

	Render_MenuText(name, Colors::White, Vector2(loc->x + 6, loc->y), false);

	loc->y += 35.0f;
	loc->y += 13.0f;
}

void Render_Toggle(Vector2& loc_ref, const wchar_t* name, bool* on)
{
	auto loc = &loc_ref;

	POINT NEGGAAA;
	GetCursorPos(&NEGGAAA);

	if (NEGGAAA.x > loc_ref.x && NEGGAAA.y > loc_ref.y)
		if (NEGGAAA.x < loc_ref.x + 15 && NEGGAAA.y < loc_ref.y + 15)
			if (GetAsyncKeyState(VK_LBUTTON) & 1)
				*on = !*on;

	drawFilledRect(Vector2(loc->x + 5, loc->y + 5), 15, 15, Colors::SlateGray);

	if (*on)
	{
		drawFilledRect(Vector2(loc->x + 7.5, loc->y + 7.5), 8.5, 8.5, Colors::DarkRed);
	}

	Render_MenuText(name, Colors::White, Vector2(loc->x + 30, loc->y + 5), false);

	loc->y += 20.0f;
}

HWND GHGameWindow = 0;
WNDPROC G_oWndProcUnsafe = 0;

int g_ScreenWidth = 0;
int g_ScreenHeight = 0;

using tCallWindowProcW = decltype(&CallWindowProcW);
tCallWindowProcW fnCallWindowProcW;

LRESULT
WINAPI
myCallWindowProcW(
	_In_ WNDPROC lpPrevWndFunc,
	_In_ HWND hWnd,
	_In_ UINT Msg,
	_In_ WPARAM wParam,
	_In_ LPARAM lParam)
{
	return fnCallWindowProcW(lpPrevWndFunc, hWnd, Msg, wParam, lParam);
}


bool HOOKED = true;
#define GET_X_LPARAM(lp)                        ((int)(short)LOWORD(lp))
#define GET_Y_LPARAM(lp)                        ((int)(short)HIWORD(lp))

int g_MenuDragStartX = 0;
int g_MenuDragStartY = 0;

bool bDragging = 0;

void WndProcHandler(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	//if (!IsSliding)
	{
		switch (msg)
		{
		case WM_LBUTTONDOWN:
		case WM_RBUTTONDOWN:
		case WM_MBUTTONDOWN:
		{
			int button = 0;
			//if (msg == WM_LBUTTONDOWN) button = 0;
			if (msg == WM_RBUTTONDOWN) button = 1;
			if (msg == WM_MBUTTONDOWN) button = 2;
			k->mouse[button] = true;
			return;
		}
		case WM_LBUTTONUP:
		case WM_RBUTTONUP:
		case WM_MBUTTONUP:
		{
			int button = 0;
			//if (msg == WM_LBUTTONUP) button = 0;
			if (msg == WM_RBUTTONUP) button = 1;
			if (msg == WM_MBUTTONUP) button = 2;
			k->mouse[button] = false;
			return;
		}
		case WM_MOUSEWHEEL:
			k->mouse_wheel += GET_WHEEL_DELTA_WPARAM(wParam) > 0 ? +1.0f : -1.0f;
			return;
		case WM_MOUSEMOVE:
			k->mouseX = (signed short)(lParam);
			k->mouseY = (signed short)(lParam >> 16);
			return;
		case WM_KEYDOWN:
		case WM_SYSKEYDOWN:
			if (wParam < 256)
				k->key[wParam] = true;
			return;
		case WM_KEYUP:
		case WM_SYSKEYUP:
			if (wParam < 256)
				k->key[wParam] = false;
			return;
		}
	}
}

void MenuProcessClick(int x, int y)
{
	//if (!IsSliding)
	{
		if (g_ControlBoundsList && ShowMenu)
		{
			//dprintf(E("g_ControlBounds list size %d"), g_ControlBoundsList->size());
			for (auto fuck = 0; fuck < g_ControlBoundsList->size(); fuck++)
			{
				auto bi = g_ControlBoundsList->at(fuck);
				if (bi.ContainsPoint({ (float)x, (float)y }))
				{
					if (bi.bIsMenuTabControl)
					{
						g_MenuIndex = bi.BoundMenuTabIndex;
					}
					else if (bi.BoundBool)
					{
						*bi.BoundBool = !*bi.BoundBool;

						//if ((bi.BoundBool == &g_Russian) && *bi.BoundBool
						//	&& (g_Chineese || g_Korean)) // wanna enable russian but chineese is enabled
						//{
						//	g_Korean = false;
						//	g_Chineese = false;
						//}
						//else if ((bi.BoundBool == &g_Chineese) && *bi.BoundBool && (g_Russian || g_Korean))
						//{
						//	g_Korean = false;
						//	g_Russian = false;
						//}
						//else if ((bi.BoundBool == &g_Korean) && *bi.BoundBool && (g_Chineese || g_Russian))
						//{
						//	g_Russian = false;
						//	g_Chineese = false;
						//}
					}
					else if (bi.pBoundRangeValue)
					{
						auto how_far_clicked = g_MX - bi.Origin.x;
						if (how_far_clicked <= 0)
							continue;

						how_far_clicked *= (bi.RangeValueMax - bi.RangeValueMin) / (g_SliderScale);

						auto delta = how_far_clicked - *bi.pBoundRangeValue;
						auto willbe = *bi.pBoundRangeValue + delta;
						if (willbe >= bi.RangeValueMin && willbe <= bi.RangeValueMax)
							*bi.pBoundRangeValue = willbe;
					}
				}
			}
		}
	}
}


bool IsInMenu(int x, int y)
{
	return (x >= g_MenuInitialPos.x) && (x <= g_MenuInitialPos.x + g_MenuW) && (y >= g_MenuInitialPos.y) && (y <= g_MenuInitialPos.y + g_MenuH);
}


LRESULT HkWndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	auto x = 0;
	auto y = 0;

	if (!HOOKED)
		goto fok_u;

	if (!k)
	{
		auto fuck_cpp = new uint8_t[sizeof(keys)];
		k = (keys*)fuck_cpp;
	}

	WndProcHandler(hWnd, msg, wParam, lParam);

	switch (msg)
	{

	case WM_SIZE:
		if (wParam != SIZE_MINIMIZED)
		{
			RECT rect;
			if (GHGameWindow && GetWindowRect(GHGameWindow, &rect))
			{
				g_ScreenWidth = rect.right - rect.left;
				g_ScreenHeight = rect.bottom - rect.top;
			}
		}
		break;

	case WM_MOUSEMOVE:
		//if (!IsSliding)
	{
		g_MX = GET_X_LPARAM(lParam);
		g_MY = GET_Y_LPARAM(lParam);
		if (bDragging)
		{
			auto newX = g_MenuInitialPos.x + g_MX - g_MenuDragStartX;
			auto newY = g_MenuInitialPos.y + g_MY - g_MenuDragStartY;
			if (newX >= g_ScreenWidth - g_MenuW)
				newX = g_ScreenWidth - g_MenuW;
			if (newY >= g_ScreenHeight - g_MenuH)
				newY = g_ScreenHeight - g_MenuH;
			if (newX <= 0)
				newX = 0;
			if (newY <= 0)
				newY = 0;

			g_MenuInitialPos.x = newX;
			g_MenuInitialPos.y = newY;
			g_MenuDragStartX = g_MX;
			g_MenuDragStartY = g_MY;
		}
	}
	break;

	case WM_LBUTTONUP:
		//if (!IsSliding)
	{
		bDragging = false;
		x = GET_X_LPARAM(lParam);
		y = GET_Y_LPARAM(lParam);
		//dprintf(E("Processing un-click at %d %d"), x, y);
		MenuProcessClick(x, y);
	}
	break;

	case WM_LBUTTONDOWN:
		//if (!IsSliding)
	{
		if (IsInMenu(GET_X_LPARAM(lParam), GET_Y_LPARAM(lParam)))
		{
			bDragging = true;
			g_MenuDragStartX = GET_X_LPARAM(lParam);
			g_MenuDragStartY = GET_Y_LPARAM(lParam);

			//dprintf(E("Processing click at %d %d"), g_MenuDragStartX, g_MenuDragStartY);
		}
	}
	break;
	}

	if (msg == WM_KEYUP)
	{
		auto nVirtKey = (int)wParam;
		if (nVirtKey == VK_INSERT)
		{
			ShowMenu = !ShowMenu;
		}
		else if (nVirtKey == VK_PRIOR)
		{
			if (G::LootTier != 5)
				G::LootTier++;
		}
		else if (nVirtKey == VK_NEXT)
		{
			if (G::LootTier != 1)
				G::LootTier--;
		}
		else if (nVirtKey == VK_NUMPAD5)
		{
#ifdef GLOBAL_UNLOAD_FLAG
			HOOKED = false;
#endif
		}
		else if (nVirtKey == VK_F1)
		{
			G::Chests = !G::Chests;
		}
		else if (nVirtKey == VK_F2)
		{
			G::CollisionDisableOnAimbotKey = !G::CollisionDisableOnAimbotKey;
		}
	}

	if (ShowMenu && (msg == WM_LBUTTONDOWN || msg == WM_LBUTTONUP || msg == WM_LBUTTONDBLCLK || msg == WM_MOUSEMOVE))
	{
		if (IsInMenu(GET_X_LPARAM(lParam), GET_Y_LPARAM(lParam)))
			return 0x0;
	}

fok_u:

	return myCallWindowProcW(G_oWndProcUnsafe, hWnd, msg, wParam, lParam);
}

void HookWndProcUnsafe()
{
	G_oWndProcUnsafe = reinterpret_cast<WNDPROC>(SetWindowLongPtr(GHGameWindow, GWLP_WNDPROC, reinterpret_cast<LONG_PTR>(HkWndProc)));
}

void InitializeWindowData()
{
	g_ControlBoundsList = new std::vector<UControl>();
	RECT rect;
	GHGameWindow = FindWindowA("UnrealWindow", 0);

	if (GetWindowRect(GHGameWindow, &rect))
	{
		g_ScreenWidth = rect.right - rect.left;
		g_ScreenHeight = rect.bottom - rect.top;
	}

	fnCallWindowProcW = CallWindowProcW;

}


void MainMenu(uintptr_t this_, uintptr_t Canvas)
{
	static_canvas = (UCanvas*)Canvas;

	if (g_ControlBoundsList && g_ControlBoundsList->size())
		g_ControlBoundsList->clear();
	else
		g_ControlBoundsList = new std::vector<UControl>();

	CheatLoop();

	if (ShowMenu)
	{
		MwMenuDraw();
	}

	return PostRoutineDown(this_, Canvas);
}

void VirtualTableFunctionSwap(void* VTable, void* FunctionToSwap, void** pOriginal, int Index)
{
	DWORD Old;

	void* pVTableFunction = (void*)((uint64_t)VTable + Index);
	*pOriginal = *(PVOID*)(pVTableFunction);

	VirtualProtectEx((HANDLE)-1, pVTableFunction, 8, PAGE_EXECUTE_READWRITE, &Old);
	*(PVOID*)pVTableFunction = FunctionToSwap;
	VirtualProtectEx((HANDLE)-1, pVTableFunction, 8, Old, &Old);
}

#define RELATIVEGAY(addr, size) ((uintptr_t)((UINT_PTR)(addr) + *(PINT)((UINT_PTR)(addr) + ((size) - sizeof(INT))) + (size)))

//MessageBox(0, L"kk", 0, 0);
//	auto SpreadAddr = Utils->PatternScan(Utils->GetGameBase(), xorstr("E8 ? ? ? ? 48 8D 4B 28 E8 ? ? ? ? 48 8B C8"), 5, 1);

//	auto SpreadCallerSig = (PVOID)(Utils->PatternScan(Utils->GetGameBase(), xorstr("0F 57 D2 48 8D 4C 24 ? 41 0F 28 CC E8 ? ? ? ? 48 8B 4D B0 0F 28 F0 48 85 C9"), 0, 0));
//	SpreadCaller = SpreadCallerSig;
	//MessageBox(0, L"apread", 0, 0);
void MenuHook()
{
	
	width = GetSystemMetrics(0);
	height = GetSystemMetrics(1);
	InitializeWindowData();
	
	HookWndProcUnsafe();


	auto LocalPlayer = ((UWorld*)(*(uintptr_t*)(UnrealCache::ScannedPattern::UWorld)))->OwningGameInstance()->LocalPlayers()->LocalPlayer();
	
	auto UViewportClient = *(uintptr_t*)(uintptr_t(LocalPlayer) + 0x70);


	//MessageBox(0, L"before", 0, 0);
	void** PostRender_VTable = *(void***)(UViewportClient);
	DWORD OldProtection;
	VirtualProtect(&PostRender_VTable[108], 8, PAGE_EXECUTE_READWRITE, &OldProtection);
	PostRoutineDown = decltype(PostRoutineDown)(PostRender_VTable[108]);
	PostRender_VTable[108] = &MainMenu;
	VirtualProtect(&PostRender_VTable[108], 8, OldProtection, &OldProtection);
	//MessageBox(0, L"render", 0, 0);

	auto GetViewPoint_VFTable = *(uintptr_t*)(uintptr_t(LocalPlayer));
	VirtualTableFunctionSwap((void*)GetViewPoint_VFTable, hk_GetViewPoint, (void**)&o_GetViewPoint, 0x358);  //GetViewInfo //old 0x368

	auto GetPlayerViewPoint_VFTable = *(uintptr_t*)(uintptr_t(LocalPlayer->PlayerController()));
	auto GetPlayerViewPoint_addr = *(uintptr_t*)(GetPlayerViewPoint_VFTable + 0x7A0); //GetPlayerViewpoint

	MH_Initialize();

	MH_CreateHook((PVOID)GetPlayerViewPoint_addr, hk_GetPlayerViewPoint, reinterpret_cast<PVOID*>(&o_GetPlayerViewPoint));
	MH_EnableHook((PVOID)GetPlayerViewPoint_addr);
	//MessageBox(0, L"done", 0, 0);
//	MessageBox(0, L"hk_GetPlayerViewPoint", 0, 0);
//	MH_CreateHook((PVOID)SpreadAddr, SpreadHook, reinterpret_cast<PVOID*>(&Spread));
	//MH_EnableHook((PVOID)SpreadAddr);
}