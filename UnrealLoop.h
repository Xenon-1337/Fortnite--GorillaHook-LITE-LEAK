#pragma once
#include "UnrealClasses.h"
#include <cstdint>

#define M_PI 3.14159265358979323846264338327950288419716939937510582f
#define D2R(d) (d / 180.f) * M_PI
#define MAX_SEGMENTS 180

UCanvas* static_canvas;

UnrealStructs::FLinearColor getColorFromTier(BYTE Tier) {
	UnrealStructs::FLinearColor color = { 255.f, 255.f, 255.f, 1 };

	if (Tier == 1)
		color = { 255.f, 255.f, 255.f, 1 };
	else if (Tier == 2)
		color = { 0.0f, 255.f, 0.0f, 1 };
	else if (Tier == 3)
		color = { 0.f, 1.f, 1.f, 1 };
	else if (Tier == 4)
		color = { 0.8f, 0.f, 0.8f, 1.f };
	else if (Tier == 5)
		color = { 1.f, 1.f, 0.f, 1 };

	return color;
}

wchar_t* s2ws(const std::string& s)
{
	int len;
	int slength = (int)s.length() + 1;
	len = MultiByteToWideChar(CP_ACP, 0, s.c_str(), slength, 0, 0);
	wchar_t* buf = new wchar_t[len];
	MultiByteToWideChar(CP_ACP, 0, s.c_str(), slength, buf, len);
	wchar_t* r(buf);
	delete[] buf;
	return r;
}

std::string WideToAnsi(const wchar_t* inWide)
{
	static char outAnsi[0x1000];

	int i = 0;
	for (; inWide[i / 2] != L'\0'; i += 2)
		outAnsi[i / 2] = ((const char*)inWide)[i];
	outAnsi[i / 2] = '\0';

	return outAnsi;
}

void __forceinline WideToAnsi(wchar_t* inWide, char* outAnsi)
{
	int i = 0;
	for (; inWide[i / 2] != L'\0'; i += 2)
		outAnsi[i / 2] = ((const char*)inWide)[i];
	outAnsi[i / 2] = '\0';
}

void __forceinline AnsiToWide(char* inAnsi, wchar_t* outWide)
{
	int i = 0;
	for (; inAnsi[i] != '\0'; i++)
		outWide[i] = (wchar_t)(inAnsi)[i];
	outWide[i] = L'\0';
}

std::wstring AnsiToWide(const char* inAnsi)
{
	static wchar_t outWide[0x1000];

	int i = 0;
	for (; inAnsi[i] != '\0'; i++)
		outWide[i] = (wchar_t)(inAnsi)[i];
	outWide[i] = L'\0';

	return outWide;
}

namespace Colors
{
	UnrealStructs::FLinearColor AliceBlue = { 0.941176534f, 0.972549081f, 1.000000000f, 1.000000000f };
	UnrealStructs::FLinearColor AntiqueWhite = { 0.980392218f, 0.921568692f, 0.843137324f, 1.000000000f };
	UnrealStructs::FLinearColor Aqua = { 0.000000000f, 1.000000000f, 1.000000000f, 1.000000000f };
	UnrealStructs::FLinearColor Aquamarine = { 0.498039246f, 1.000000000f, 0.831372619f, 1.000000000f };
	UnrealStructs::FLinearColor Azure = { 0.941176534f, 1.000000000f, 1.000000000f, 1.000000000f };
	UnrealStructs::FLinearColor Beige = { 0.960784376f, 0.960784376f, 0.862745166f, 1.000000000f };
	UnrealStructs::FLinearColor Bisque = { 1.000000000f, 0.894117713f, 0.768627524f, 1.000000000f };
	UnrealStructs::FLinearColor Black = { 0.000000000f, 0.000000000f, 0.000000000f, 1.000000000f };
	UnrealStructs::FLinearColor BlanchedAlmond = { 1.000000000f, 0.921568692f, 0.803921640f, 1.000000000f };
	UnrealStructs::FLinearColor Blue = { 0.000000000f, 0.000000000f, 1.000000000f, 1.000000000f };
	UnrealStructs::FLinearColor BlueViolet = { 0.541176498f, 0.168627456f, 0.886274576f, 1.000000000f };
	UnrealStructs::FLinearColor Brown = { 0.647058845f, 0.164705887f, 0.164705887f, 1.000000000f };
	UnrealStructs::FLinearColor BurlyWood = { 0.870588303f, 0.721568644f, 0.529411793f, 1.000000000f };
	UnrealStructs::FLinearColor CadetBlue = { 0.372549027f, 0.619607866f, 0.627451003f, 1.000000000f };
	UnrealStructs::FLinearColor Chartreuse = { 0.498039246f, 1.000000000f, 0.000000000f, 1.000000000f };
	UnrealStructs::FLinearColor Chocolate = { 0.823529482f, 0.411764741f, 0.117647067f, 1.000000000f };
	UnrealStructs::FLinearColor Coral = { 1.000000000f, 0.498039246f, 0.313725501f, 1.000000000f };
	UnrealStructs::FLinearColor CornflowerBlue = { 0.392156899f, 0.584313750f, 0.929411829f, 1.000000000f };
	UnrealStructs::FLinearColor Cornsilk = { 1.000000000f, 0.972549081f, 0.862745166f, 1.000000000f };
	UnrealStructs::FLinearColor Crimson = { 0.862745166f, 0.078431375f, 0.235294133f, 1.000000000f };
	UnrealStructs::FLinearColor Cyan = { 0.000000000f, 1.000000000f, 1.000000000f, 1.000000000f };
	UnrealStructs::FLinearColor DarkBlue = { 0.000000000f, 0.000000000f, 0.545098066f, 1.000000000f };
	UnrealStructs::FLinearColor DarkCyan = { 0.000000000f, 0.545098066f, 0.545098066f, 1.000000000f };
	UnrealStructs::FLinearColor DarkGoldenrod = { 0.721568644f, 0.525490224f, 0.043137256f, 1.000000000f };
	UnrealStructs::FLinearColor DarkGray = { 0.662745118f, 0.662745118f, 0.662745118f, 1.000000000f };
	UnrealStructs::FLinearColor DarkGreen = { 0.000000000f, 0.392156899f, 0.000000000f, 1.000000000f };
	UnrealStructs::FLinearColor DarkKhaki = { 0.741176486f, 0.717647076f, 0.419607878f, 1.000000000f };
	UnrealStructs::FLinearColor DarkMagenta = { 0.545098066f, 0.000000000f, 0.545098066f, 1.000000000f };
	UnrealStructs::FLinearColor DarkOliveGreen = { 0.333333343f, 0.419607878f, 0.184313729f, 1.000000000f };
	UnrealStructs::FLinearColor DarkOrange = { 1.000000000f, 0.549019635f, 0.000000000f, 1.000000000f };
	UnrealStructs::FLinearColor DarkOrchid = { 0.600000024f, 0.196078449f, 0.800000072f, 1.000000000f };
	UnrealStructs::FLinearColor DarkRed = { 0.545098066f, 0.000000000f, 0.000000000f, 1.000000000f };
	UnrealStructs::FLinearColor DarkSalmon = { 0.913725555f, 0.588235319f, 0.478431404f, 1.000000000f };
	UnrealStructs::FLinearColor DarkSeaGreen = { 0.560784340f, 0.737254918f, 0.545098066f, 1.000000000f };
	UnrealStructs::FLinearColor DarkSlateBlue = { 0.282352954f, 0.239215702f, 0.545098066f, 1.000000000f };
	UnrealStructs::FLinearColor DarkSlateGray = { 0.120f, 0.120f, 0.120f, 1.000000000f };
	UnrealStructs::FLinearColor DarkTurquoise = { 0.000000000f, 0.807843208f, 0.819607913f, 1.000000000f };
	UnrealStructs::FLinearColor DarkViolet = { 0.580392182f, 0.000000000f, 0.827451050f, 1.000000000f };
	UnrealStructs::FLinearColor DeepPink = { 1.000000000f, 0.078431375f, 0.576470613f, 1.000000000f };
	UnrealStructs::FLinearColor DeepSkyBlue = { 0.000000000f, 0.749019623f, 1.000000000f, 1.000000000f };
	UnrealStructs::FLinearColor DimGray = { 0.411764741f, 0.411764741f, 0.411764741f, 1.000000000f };
	UnrealStructs::FLinearColor DodgerBlue = { 0.117647067f, 0.564705908f, 1.000000000f, 1.000000000f };
	UnrealStructs::FLinearColor Firebrick = { 0.698039234f, 0.133333340f, 0.133333340f, 1.000000000f };
	UnrealStructs::FLinearColor FloralWhite = { 1.000000000f, 0.980392218f, 0.941176534f, 1.000000000f };
	UnrealStructs::FLinearColor ForestGreen = { 0.133333340f, 0.545098066f, 0.133333340f, 1.000000000f };
	UnrealStructs::FLinearColor Fuchsia = { 1.000000000f, 0.000000000f, 1.000000000f, 1.000000000f };
	UnrealStructs::FLinearColor Gainsboro = { 0.862745166f, 0.862745166f, 0.862745166f, 1.000000000f };
	UnrealStructs::FLinearColor GhostWhite = { 0.972549081f, 0.972549081f, 1.000000000f, 1.000000000f };
	UnrealStructs::FLinearColor Gold = { 1.000000000f, 0.843137324f, 0.000000000f, 1.000000000f };
	UnrealStructs::FLinearColor Goldenrod = { 0.854902029f, 0.647058845f, 0.125490203f, 1.000000000f };
	UnrealStructs::FLinearColor Gray = { 0.501960814f, 0.501960814f, 0.501960814f, 1.000000000f };
	UnrealStructs::FLinearColor Green = { 0.000000000f, 0.501960814f, 0.000000000f, 1.000000000f };
	UnrealStructs::FLinearColor GreenYellow = { 0.678431392f, 1.000000000f, 0.184313729f, 1.000000000f };
	UnrealStructs::FLinearColor Honeydew = { 0.941176534f, 1.000000000f, 0.941176534f, 1.000000000f };
	UnrealStructs::FLinearColor HotPink = { 1.000000000f, 0.411764741f, 0.705882370f, 1.000000000f };
	UnrealStructs::FLinearColor IndianRed = { 0.803921640f, 0.360784322f, 0.360784322f, 1.000000000f };
	UnrealStructs::FLinearColor Indigo = { 0.294117659f, 0.000000000f, 0.509803951f, 1.000000000f };
	UnrealStructs::FLinearColor Ivory = { 1.000000000f, 1.000000000f, 0.941176534f, 1.000000000f };
	UnrealStructs::FLinearColor Khaki = { 0.941176534f, 0.901960850f, 0.549019635f, 1.000000000f };
	UnrealStructs::FLinearColor Lavender = { 0.901960850f, 0.901960850f, 0.980392218f, 1.000000000f };
	UnrealStructs::FLinearColor LavenderBlush = { 1.000000000f, 0.941176534f, 0.960784376f, 1.000000000f };
	UnrealStructs::FLinearColor LawnGreen = { 0.486274540f, 0.988235354f, 0.000000000f, 1.000000000f };
	UnrealStructs::FLinearColor LemonChiffon = { 1.000000000f, 0.980392218f, 0.803921640f, 1.000000000f };
	UnrealStructs::FLinearColor LightBlue = { 0.678431392f, 0.847058892f, 0.901960850f, 1.000000000f };
	UnrealStructs::FLinearColor LightCoral = { 0.941176534f, 0.501960814f, 0.501960814f, 1.000000000f };
	UnrealStructs::FLinearColor LightCyan = { 0.878431439f, 1.000000000f, 1.000000000f, 1.000000000f };
	UnrealStructs::FLinearColor LightGoldenrodYellow = { 0.980392218f, 0.980392218f, 0.823529482f, 1.000000000f };
	UnrealStructs::FLinearColor LightGreen = { 0.564705908f, 0.933333397f, 0.564705908f, 1.000000000f };
	UnrealStructs::FLinearColor LightGray = { 0.827451050f, 0.827451050f, 0.827451050f, 1.000000000f };
	UnrealStructs::FLinearColor LightPink = { 1.000000000f, 0.713725507f, 0.756862819f, 1.000000000f };
	UnrealStructs::FLinearColor LightSalmon = { 1.000000000f, 0.627451003f, 0.478431404f, 1.000000000f };
	UnrealStructs::FLinearColor LightSeaGreen = { 0.125490203f, 0.698039234f, 0.666666687f, 1.000000000f };
	UnrealStructs::FLinearColor LightSkyBlue = { 0.529411793f, 0.807843208f, 0.980392218f, 1.000000000f };
	UnrealStructs::FLinearColor LightSlateGray = { 0.466666698f, 0.533333361f, 0.600000024f, 1.000000000f };
	UnrealStructs::FLinearColor LightSteelBlue = { 0.690196097f, 0.768627524f, 0.870588303f, 1.000000000f };
	UnrealStructs::FLinearColor LightYellow = { 1.000000000f, 1.000000000f, 0.878431439f, 1.000000000f };
	UnrealStructs::FLinearColor Lime = { 0.000000000f, 1.000000000f, 0.000000000f, 1.000000000f };
	UnrealStructs::FLinearColor LimeGreen = { 0.196078449f, 0.803921640f, 0.196078449f, 1.000000000f };
	UnrealStructs::FLinearColor Linen = { 0.980392218f, 0.941176534f, 0.901960850f, 1.000000000f };
	UnrealStructs::FLinearColor Magenta = { 1.000000000f, 0.000000000f, 1.000000000f, 1.000000000f };
	UnrealStructs::FLinearColor Maroon = { 0.501960814f, 0.000000000f, 0.000000000f, 1.000000000f };
	UnrealStructs::FLinearColor MediumAquamarine = { 0.400000036f, 0.803921640f, 0.666666687f, 1.000000000f };
	UnrealStructs::FLinearColor MediumBlue = { 0.000000000f, 0.000000000f, 0.803921640f, 1.000000000f };
	UnrealStructs::FLinearColor MediumOrchid = { 0.729411781f, 0.333333343f, 0.827451050f, 1.000000000f };
	UnrealStructs::FLinearColor MediumPurple = { 0.576470613f, 0.439215720f, 0.858823597f, 1.000000000f };
	UnrealStructs::FLinearColor MediumSeaGreen = { 0.235294133f, 0.701960802f, 0.443137288f, 1.000000000f };
	UnrealStructs::FLinearColor MediumSlateBlue = { 0.482352972f, 0.407843173f, 0.933333397f, 1.000000000f };
	UnrealStructs::FLinearColor MediumSpringGreen = { 0.000000000f, 0.980392218f, 0.603921592f, 1.000000000f };
	UnrealStructs::FLinearColor MediumTurquoise = { 0.282352954f, 0.819607913f, 0.800000072f, 1.000000000f };
	UnrealStructs::FLinearColor MediumVioletRed = { 0.780392230f, 0.082352944f, 0.521568656f, 1.000000000f };
	UnrealStructs::FLinearColor MidnightBlue = { 0.098039225f, 0.098039225f, 0.439215720f, 1.000000000f };
	UnrealStructs::FLinearColor MintCream = { 0.960784376f, 1.000000000f, 0.980392218f, 1.000000000f };
	UnrealStructs::FLinearColor MistyRose = { 1.000000000f, 0.894117713f, 0.882353008f, 1.000000000f };
	UnrealStructs::FLinearColor Moccasin = { 1.000000000f, 0.894117713f, 0.709803939f, 1.000000000f };
	UnrealStructs::FLinearColor NavajoWhite = { 1.000000000f, 0.870588303f, 0.678431392f, 1.000000000f };
	UnrealStructs::FLinearColor Navy = { 0.000000000f, 0.000000000f, 0.501960814f, 1.000000000f };
	UnrealStructs::FLinearColor OldLace = { 0.992156923f, 0.960784376f, 0.901960850f, 1.000000000f };
	UnrealStructs::FLinearColor Olive = { 0.501960814f, 0.501960814f, 0.000000000f, 1.000000000f };
	UnrealStructs::FLinearColor OliveDrab = { 0.419607878f, 0.556862772f, 0.137254909f, 1.000000000f };
	UnrealStructs::FLinearColor Orange = { 1.000000000f, 0.647058845f, 0.000000000f, 1.000000000f };
	UnrealStructs::FLinearColor OrangeRed = { 1.000000000f, 0.270588249f, 0.000000000f, 1.000000000f };
	UnrealStructs::FLinearColor Orchid = { 0.854902029f, 0.439215720f, 0.839215755f, 1.000000000f };
	UnrealStructs::FLinearColor PaleGoldenrod = { 0.933333397f, 0.909803987f, 0.666666687f, 1.000000000f };
	UnrealStructs::FLinearColor PaleGreen = { 0.596078455f, 0.984313786f, 0.596078455f, 1.000000000f };
	UnrealStructs::FLinearColor PaleTurquoise = { 0.686274529f, 0.933333397f, 0.933333397f, 1.000000000f };
	UnrealStructs::FLinearColor PaleVioletRed = { 0.858823597f, 0.439215720f, 0.576470613f, 1.000000000f };
	UnrealStructs::FLinearColor PapayaWhip = { 1.000000000f, 0.937254965f, 0.835294187f, 1.000000000f };
	UnrealStructs::FLinearColor PeachPuff = { 1.000000000f, 0.854902029f, 0.725490212f, 1.000000000f };
	UnrealStructs::FLinearColor Peru = { 0.803921640f, 0.521568656f, 0.247058839f, 1.000000000f };
	UnrealStructs::FLinearColor Pink = { 1.000000000f, 0.752941251f, 0.796078503f, 1.000000000f };
	UnrealStructs::FLinearColor Plum = { 0.866666734f, 0.627451003f, 0.866666734f, 1.000000000f };
	UnrealStructs::FLinearColor PowderBlue = { 0.690196097f, 0.878431439f, 0.901960850f, 1.000000000f };
	UnrealStructs::FLinearColor Purple = { 0.501960814f, 0.000000000f, 0.501960814f, 1.000000000f };
	UnrealStructs::FLinearColor Red = { 1.f, 0.f, 0.f, 1.f };
	UnrealStructs::FLinearColor RosyBrown = { 0.737254918f, 0.560784340f, 0.560784340f, 1.000000000f };
	UnrealStructs::FLinearColor RoyalBlue = { 0.254901975f, 0.411764741f, 0.882353008f, 1.000000000f };
	UnrealStructs::FLinearColor SaddleBrown = { 0.545098066f, 0.270588249f, 0.074509807f, 1.000000000f };
	UnrealStructs::FLinearColor Salmon = { 0.980392218f, 0.501960814f, 0.447058856f, 1.000000000f };
	UnrealStructs::FLinearColor SandyBrown = { 0.956862807f, 0.643137276f, 0.376470625f, 1.000000000f };
	UnrealStructs::FLinearColor SeaGreen = { 0.180392161f, 0.545098066f, 0.341176480f, 1.000000000f };
	UnrealStructs::FLinearColor SeaShell = { 1.000000000f, 0.960784376f, 0.933333397f, 1.000000000f };
	UnrealStructs::FLinearColor Sienna = { 0.627451003f, 0.321568638f, 0.176470593f, 1.000000000f };
	UnrealStructs::FLinearColor Silver = { 0.752941251f, 0.752941251f, 0.752941251f, 1.000000000f };
	UnrealStructs::FLinearColor SkyBlue = { 0.529411793f, 0.807843208f, 0.921568692f, 1.000000000f };
	UnrealStructs::FLinearColor SlateBlue = { 0.415686309f, 0.352941185f, 0.803921640f, 1.000000000f };
	UnrealStructs::FLinearColor SlateGray = { 0.720, 0.720, 0.720, 1.000000000f };
	UnrealStructs::FLinearColor Snow = { 1.000000000f, 0.980392218f, 0.980392218f, 1.000000000f };
	UnrealStructs::FLinearColor SpringGreen = { 0.000000000f, 1.000000000f, 0.498039246f, 1.000000000f };
	UnrealStructs::FLinearColor SteelBlue = { 0.274509817f, 0.509803951f, 0.705882370f, 1.000000000f };
	UnrealStructs::FLinearColor Tan = { 0.823529482f, 0.705882370f, 0.549019635f, 1.000000000f };
	UnrealStructs::FLinearColor Teal = { 0.000000000f, 0.501960814f, 0.501960814f, 1.000000000f };
	UnrealStructs::FLinearColor Thistle = { 0.847058892f, 0.749019623f, 0.847058892f, 1.000000000f };
	UnrealStructs::FLinearColor Tomato = { 1.000000000f, 0.388235331f, 0.278431386f, 1.000000000f };
	UnrealStructs::FLinearColor Transparent = { 0.000000000f, 0.000000000f, 0.000000000f, 0.000000000f };
	UnrealStructs::FLinearColor Turquoise = { 0.250980407f, 0.878431439f, 0.815686345f, 1.000000000f };
	UnrealStructs::FLinearColor Violet = { 0.933333397f, 0.509803951f, 0.933333397f, 1.000000000f };
	UnrealStructs::FLinearColor Wheat = { 0.960784376f, 0.870588303f, 0.701960802f, 1.000000000f };
	UnrealStructs::FLinearColor White = { 1.000000000f, 1.000000000f, 1.0f, 1.000000000f };
	UnrealStructs::FLinearColor WhiteSmoke = { 0.960784376f, 0.960784376f, 0.960784376f, 1.000000000f };
	UnrealStructs::FLinearColor Yellow = { 1.000000000f, 1.000000000f, 0.000000000f, 1.000000000f };
	UnrealStructs::FLinearColor YellowGreen = { 0.603921592f, 0.803921640f, 0.196078449f, 1.000000000f };
};

void Pasted_line(Vector2 one, Vector2 two, UnrealStructs::FLinearColor color)
{
	static_canvas->K2_DrawLine(one, two, 1, color);
}

void Pasted_lineThick(Vector2 one, Vector2 two, UnrealStructs::FLinearColor color)
{
	static_canvas->K2_DrawLine(one, two, 2, color);
}

void Pasted_PointArray(size_t count, Vector2* ary, UnrealStructs::FLinearColor color)
{
	for (size_t i = 1; i < count; ++i)
		Pasted_line(ary[i - 1], ary[i], color);
}

int myceilf(float num)
{
	int inum = (int)num;
	if (num == (float)inum) {
		return inum;
	}
	return inum + 1;
}

void Pasted_CircleOutline(Vector2 pos, int r, UnrealStructs::FLinearColor outline)
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

	Pasted_PointArray(seg, points, outline);
}

namespace G
{
	bool EspWeapon = false;
	bool RefreshEach1s = true;
	bool Snaplines = true;
	bool CornerBox = true;

	bool NoBloom = false;
	bool NoSpread = false;

	bool AntiAim = false;

	bool VehicleFly = false; bool VehicleTp = false;

	bool NoClip = false;

	bool Norevive = false;

	bool AimWhileJumping = false;

	float CornerBoxThicc = 1.7f;
	float RedDistance = 40.0f;
	float CornerBoxScale = 0.20;
	bool PunktierSnaplines = false;
	float PunktierPower = 16.6f;
	bool SnaplinesIn50m = false;
	bool Baim = false;
	bool Crosshair = true;
	bool AimbotFovCircle = false;
	float SkeletonThicc = 1.0f;
	bool VisibleCheck = false;
	float PlayerBoxThicc = 1.0f;
	bool WeakSpotAimbot = true;

	bool PlayerSpeedBalls = false;

	bool ProjectileTpEnable = true;
	bool ShowTimeConsumed = true;
	float Smooth = 0.3;
	bool CollisionDisableOnAimbotKey = true;

	float CamFovValue = 0;
	bool CameraFovChanger = false;

	bool PlayerFly = false;

	bool FlyingCars = false;
	bool UseEngineW2S = true;
	bool Chests = true;
	bool TpPrisonersEnable = true;
	bool DrawSelf = true;
	bool LootWeapons = true;
	bool AimbotUseRightButton = false;
	int JumpScale = 1;
	bool Projectiles = true; bool pSilent = false; bool StickySilent = false; bool pMem = true;
	int TpTimeInterval = 250;
	float LootTier = 1;
	bool LootMelee = true;
	bool bAllowedTp = true;
	bool Outline = true;
	bool Skeletons = true;
	bool EspPlayerName = true;
	bool EspLoot = true;
	bool EspRifts = false;
	bool EspSupplyDrops = false;
	bool EspTraps = false;
	bool EspVehicles = false;
	bool Healthbars = true;
	bool LootHeals = true;
	bool LootAttachments = true;
	bool LootAmmo = false;
	bool EspBox = true;
	bool LootEquipment = true;
	bool TpLootAndCorpses = true;
	bool Spinbot = false;
	bool TpZombiesEnable = true;
	bool EnableHack = true;
	bool LootFood = true;
	bool LootWear = true;
	bool TpAnimalsEnable = true;
	bool TpSentriesEnable = true;
	uintptr_t MmBase;
	bool TimeSpeedhackEnable = false;
	bool MovSpeedhackEnable = true;
	int MovSpeedhackScale = 2;
	bool AimbotEnable = true;
	bool EspSentries = true;
	bool EspZombies = false;
	bool EspPlayers = true;
	bool EspCorpses = true;
	bool EspAnimals = true;
	bool EspDrones = true;

	bool Head = true;
	bool Neck = true;
	bool Chest = true;
	bool Pelvis = true;

	int Aimkey;
	float RenderDist = 200;
	float ChestsRdist = 200;
	float VehicleRdist = 200;
	float ProjectileRdist = 200;
	float AimbotDist = 200;
	bool AimbotTargetPlayers = true;
	bool AimbotTargetZombies;
	float LootRenderDist = 200;
	int IconScale = 21;
	bool LootEnable = false;
	bool AimbotTargetDrones;
	bool OnlyWeapons = true;
	uintptr_t MmSize;
	bool AimbotTargetAnimals;
	uintptr_t CurrentTime;
	bool AimbotTargetSentries;
	int ItemRarityLevel = 7;
	uintptr_t LastTimePEHookCalled;
	float AimFovValue = 360.f;
	bool NoRecoil = false;
	bool InfAmmo = false;

}

void DrawLine(UCanvas* Canvas, Vector2 position1, Vector2 position2, UnrealStructs::FLinearColor color, int thickness = 1, bool screenCheck = false)
{
	if (screenCheck && Utils->IsInScreen(position1) && Utils->IsInScreen(position2))
		Canvas->K2_DrawLine(position1, position2, thickness, color);
	else if (!screenCheck)
		Canvas->K2_DrawLine(position1, position2, thickness, color);
}

void DrawCorneredBox(UCanvas* Canvas, Vector2 position, Vector2 size, int thickness, UnrealStructs::FLinearColor colora) {

	if (!Utils->IsInScreen(position)) return;

	float lineW = (size.x / 4);
	float lineH = (size.y / 4);

	//corners
	DrawLine(Canvas, Vector2(position.x, position.y), Vector2(position.x, position.y + lineH), colora, thickness);
	DrawLine(Canvas, Vector2(position.x, position.y), Vector2(position.x + lineW, position.y), colora, thickness);
	DrawLine(Canvas, Vector2(position.x + size.x - lineW, position.y), Vector2(position.x + size.x, position.y), colora, thickness);
	DrawLine(Canvas, Vector2(position.x + size.x, position.y), Vector2(position.x + size.x, position.y + lineH), colora, thickness);
	DrawLine(Canvas, Vector2(position.x, position.y + size.y - lineH), Vector2(position.x, position.y + size.y), colora, thickness);
	DrawLine(Canvas, Vector2(position.x, position.y + size.y), Vector2(position.x + lineW, position.y + size.y), colora, thickness);
	DrawLine(Canvas, Vector2(position.x + size.x - lineW, position.y + size.y), Vector2(position.x + size.x, position.y + size.y), colora, thickness);
	DrawLine(Canvas, Vector2(position.x + size.x, position.y + size.y - lineH), Vector2(position.x + size.x, position.y + size.y), colora, thickness);
}

Vector3 OriginalLocation;
Vector3 OriginalRotation;

APlayerController* PlayerController;

AFortPawn* TargetPawn;
AFortPawn* LocalPawn;
Vector3 o_CamRot;
Vector3 o_CamLoc;
PVOID(*GetWeaponStats)(PVOID) = nullptr;
static float OriginalReloadTime = 0.f;
static float OriginalReloadScale = 0.f;
static float OriginalChargeDownsights = 0.f;
static bool OriginalReloadOnce = true;

bool isSpinning = false;

void(*o_GetViewPoint)(uintptr_t, UnrealStructs::FMinimalViewInfo*, BYTE) = nullptr;
void hk_GetViewPoint(uintptr_t this_LocalPlayer, UnrealStructs::FMinimalViewInfo* OutViewInfo, BYTE StereoPass)
{
	o_GetViewPoint(this_LocalPlayer, OutViewInfo, StereoPass);

	if (Utils->isValidPointer(uintptr_t(LocalPawn)))
	{
		if (G::AimbotEnable) {
			if (G::pMem)
			{
				if (GetAsyncKeyState(VK_RBUTTON))
				{
					OutViewInfo->Rotation = OriginalRotation;
				}
			}

			if (G::StickySilent)
			{
				if (GetAsyncKeyState(VK_RBUTTON))
				{
					OutViewInfo->Location = OriginalLocation;
				}
			}

			if (G::pSilent)
			{
				if (GetAsyncKeyState(VK_RBUTTON))
				{
					OutViewInfo->Location = OriginalLocation;
					OutViewInfo->Rotation = OriginalRotation;
				}
			}

			if (G::CameraFovChanger)
			{
				OutViewInfo->FOV = G::CamFovValue;
			}
		}
		

	}
}

void SetControlRotation(Vector3 NewRotation, bool bResetCamera = false)
{
	auto SetControlRotation_ = (*(void(__fastcall**)(uintptr_t Controller, Vector3 NewRotation, bool bResetCamera))((uintptr_t*)(PlayerController + 0x710)));
}

void(*o_GetPlayerViewPoint)(uintptr_t, Vector3*, Vector3*) = nullptr;
void hk_GetPlayerViewPoint(uintptr_t this_PlayerController, Vector3* Location, Vector3* Rotation) {
	o_GetPlayerViewPoint(this_PlayerController, Location, Rotation);

	o_CamLoc = *Location;

	OriginalLocation = *Location;
	OriginalRotation = *Rotation;

	

	if (Utils->isValidPointer(uintptr_t(LocalPawn)))
	{
		o_CamLoc = *Location;

		OriginalLocation = *Location;
		OriginalRotation = *Rotation;

		if (G::AimbotEnable) {
			if (G::StickySilent)
			{
				if (GetAsyncKeyState(VK_RBUTTON))
				{
					auto rootHead = TargetPawn->GetBone(68);
					Vector3 camloc = *Location;
					Vector3 VectorPos;
					VectorPos.x = rootHead.x - camloc.x;
					VectorPos.y = rootHead.y - camloc.y;
					VectorPos.z = rootHead.z - camloc.z;
					float distance = (double)(sqrtf(VectorPos.x * VectorPos.x + VectorPos.y * VectorPos.y + VectorPos.z * VectorPos.z));
					Vector3 rot;
					rot.x = -((acosf(VectorPos.z / distance) * (float)(180.0f / 3.14159265358979323846264338327950288419716939937510)) - 90.f);
					rot.y = atan2f(VectorPos.y, VectorPos.x) * (float)(180.0f / 3.14159265358979323846264338327950288419716939937510);
					rot.z = 0;
					*Rotation = rot;
				}
			}

			if (G::pSilent)
			{
				if (GetAsyncKeyState(VK_RBUTTON))
				{
					auto rootHead = TargetPawn->GetBone(68);
					Vector3 camloc = *Location;
					Vector3 VectorPos;
					VectorPos.x = rootHead.x - camloc.x;
					VectorPos.y = rootHead.y - camloc.y;
					VectorPos.z = rootHead.z - camloc.z;
					float distance = (double)(sqrtf(VectorPos.x * VectorPos.x + VectorPos.y * VectorPos.y + VectorPos.z * VectorPos.z));
					Vector3 rot;
					rot.x = -((acosf(VectorPos.z / distance) * (float)(180.0f / 3.14159265358979323846264338327950288419716939937510)) - 90.f);
					rot.y = atan2f(VectorPos.y, VectorPos.x) * (float)(180.0f / 3.14159265358979323846264338327950288419716939937510);
					rot.z = 0;
					*Rotation = rot;
				}
			}
			if (G::pMem)
			{
				if (GetAsyncKeyState(VK_RBUTTON))
				{
					auto rootHead = TargetPawn->GetBone(68);
					Vector3 camloc = *Location;
					Vector3 VectorPos;
					VectorPos.x = rootHead.x - camloc.x;
					VectorPos.y = rootHead.y - camloc.y;
					VectorPos.z = rootHead.z - camloc.z;
					float distance = (double)(sqrtf(VectorPos.x * VectorPos.x + VectorPos.y * VectorPos.y + VectorPos.z * VectorPos.z));
					Vector3 rot;
					rot.x = -((acosf(VectorPos.z / distance) * (float)(180.0f / 3.14159265358979323846264338327950288419716939937510)) - 90.f);
					rot.y = atan2f(VectorPos.y, VectorPos.x) * (float)(180.0f / 3.14159265358979323846264338327950288419716939937510);
					rot.z = 0;
					*Rotation = rot;
				}
			}
		}
	
		
	

		if (G::Spinbot)
		{
			if (GetAsyncKeyState(VK_SHIFT))
			{
				Vector3 random = { };
				random.x = 0;
				random.y = rand();
				random.z = 0;
				*Rotation = random;
			}
		}

	}
}

PVOID SpreadCaller = nullptr;
BOOL(*Spread)(PVOID a1, float* a2, float* a3);
BOOL SpreadHook(PVOID a1, float* a2, float* a3)
{
	auto LocalPawn = ((UWorld*)(*(uintptr_t*)(UnrealCache::ScannedPattern::UWorld)))->OwningGameInstance()->LocalPlayers()->LocalPlayer()->PlayerController()->LocalPawn();
	if (LocalPawn)
	{
		if (LocalPawn->CurrentWeapon())
		{
			if (G::NoSpread && _ReturnAddress() == SpreadCaller && GetAsyncKeyState(VK_RBUTTON)) {
				return 0;
			}
			if (G::NoSpread && _ReturnAddress() == SpreadCaller && GetAsyncKeyState(VK_LBUTTON)) {
				return 0;
			}
		}
	}
	return Spread(a1, a2, a3);
}

float closestActorDist = FLT_MAX;
AFortPawn* closestActor = nullptr;

void CheatLoop()
{
	//MessageBox(0, L"loop start", 0, 0);
	auto GWorld = ((UWorld*)(*(uintptr_t*)(UnrealCache::ScannedPattern::UWorld)));
	if (!GWorld) return;

	auto OwningGameInstance = GWorld->OwningGameInstance();
	if (!OwningGameInstance) return;

	PlayerController = OwningGameInstance->LocalPlayers()->LocalPlayer()->PlayerController();
	if (!PlayerController) return;

	auto PlayerCamera = PlayerController->PlayerCameraManager();
	if (!PlayerCamera) return;

	LocalPawn = (AFortPawn*)PlayerController->LocalPawn();

	if (G::AimbotFovCircle)
	{
		Pasted_CircleOutline(Vector2(width / 2, height / 2), (G::AimFovValue * PlayerCamera->GetFOVAngle()) / 5, Colors::White);
	}

	if (LocalPawn)
	{
		if (G::Crosshair)
		{
			static_canvas->K2_DrawLine(Vector2(width / 2 + 11, height / 2), Vector2(width / 2 + 1.f, height / 2), 1, Colors::Red);
			static_canvas->K2_DrawLine(Vector2(width / 2 - 10, height / 2), Vector2(width / 2 - 1.f, height / 2), 1, Colors::Red);
			static_canvas->K2_DrawLine(Vector2(width / 2, height / 2 + 10), Vector2(width / 2, height / 2), 1, Colors::Red);
			static_canvas->K2_DrawLine(Vector2(width / 2, height / 2 - 11), Vector2(width / 2, height / 2), 1, Colors::Red);
		}
	}

	auto levels = GWorld->Levels();
	//MessageBox(0, L"go", 0, 0);
	for (int a = 0; a < levels.Num(); a++)
	{
		auto level = levels[a];
		if (!level) continue;

		auto actors = levels[a]->ActorArray();

		for (int i = 0; i < actors.Num(); i++)
		{
			auto actor = actors[i];
			if (!actor || actor == LocalPawn)
				continue;

			if (actor->IsA(UnrealCache::ScannedObjects::Classes::FortPlayerPawnAthena))
			{
				
				//MessageBox(0, L"before", 0, 0);
				auto Hea = actor->GetBone(68);
				//MessageBox(0, L"good", 0, 0);
				auto Head = PlayerController->WorldToScreen(Hea);
				//MessageBox(0, L"better", 0, 0);

				auto Top = PlayerController->WorldToScreen({ Hea.x, Hea.y, Hea.z + 20 });
				auto Bottom = PlayerController->WorldToScreen(actor->GetBone(0));

				float TextOffset_Top = Top.y;
				float TextOffset_Bottom = Bottom.y;

				UnrealStructs::FLinearColor BoxColor = UnrealStructs::FLinearColor(1.f, 0.f, 0.f, 1.f);

				UnrealStructs::FLinearColor SkeletonColor = UnrealStructs::FLinearColor(0.f, 1.f, 1.f, 1.f);

				auto dx = Head.x - (width / 2);
				auto dy = Head.y - (height / 2);
				auto dist = sqrtf(dx * dx + dy * dy);

				if (dist < (G::AimFovValue * PlayerCamera->GetFOVAngle()) / 5 && dist < closestActorDist) {
					closestActorDist = dist;
					closestActor = actor;
					TargetPawn = actor;
				}
				//MessageBox(0, L"1", 0, 0);
				if (LocalPawn)
				{
					if (G::VisibleCheck)
					{
						//bool Visible = PlayerController->LineOfSightTo(actor);
						 bool Visible = true;
						if (Visible)
						{
							BoxColor = UnrealStructs::FLinearColor(1.f, 0.f, 0.f, 1.f);
						}
						else
						{
							BoxColor = UnrealStructs::FLinearColor(1.f, 1.f, 1.f, 1.f);
						}
					}

					if (G::PunktierSnaplines)
					{
						auto headDD = PlayerController->WorldToScreen(TargetPawn->GetBone(68));
						if (headDD.x != 0 && headDD.y != 0 || headDD.x == 0 && headDD.y == 0)
						{
							DrawLine(static_canvas, Vector2(width / 2, height / 2), headDD, Colors::Red, 1.f, true);
						}
					}
				}
				//MessageBox(0, L"2", 0, 0);
				if (G::EspBox)
				{
					float Height = Bottom.y - Top.y;
					float Width = Height * 0.65;

					Vector2 min;
					min.x = Bottom.x + Width / 2;
					min.y = Bottom.y;

					Vector2 max;
					max.x = Top.x - Width / 2;
					max.y = Top.y;

					Vector2 size;
					size.x = min.x - max.x;
					size.y = min.y - max.y;


					DrawCorneredBox(static_canvas, max, size, 2.97f, BoxColor);
				}
				//MessageBox(0, L"3", 0, 0);
				if (G::Skeletons)
				{
					auto head = Head;
					auto neck = PlayerController->WorldToScreen(actor->GetBone(66));
					auto rightChest = PlayerController->WorldToScreen(actor->GetBone(8));
					auto leftChest = PlayerController->WorldToScreen(actor->GetBone(37));
					auto leftShoulder = PlayerController->WorldToScreen(actor->GetBone(38));
					auto rightShoulder = PlayerController->WorldToScreen(actor->GetBone(9));
					auto leftElbow = PlayerController->WorldToScreen(actor->GetBone(94));
					auto rightElbow = PlayerController->WorldToScreen(actor->GetBone(10));
					auto leftWrist = PlayerController->WorldToScreen(actor->GetBone(62));
					auto rightWrist = PlayerController->WorldToScreen(actor->GetBone(33));
					auto pelvis = PlayerController->WorldToScreen(actor->GetBone(2));
					auto leftAss = PlayerController->WorldToScreen(actor->GetBone(76));
					auto rightAss = PlayerController->WorldToScreen(actor->GetBone(69));
					auto leftKnee = PlayerController->WorldToScreen(actor->GetBone(77));
					auto rightKnee = PlayerController->WorldToScreen(actor->GetBone(70));
					auto leftAnkle = PlayerController->WorldToScreen(actor->GetBone(78));
					auto rightAnkle = PlayerController->WorldToScreen(actor->GetBone(71));

					DrawLine(static_canvas, head, neck, SkeletonColor, 1.5f, true);
					DrawLine(static_canvas, neck, leftShoulder, SkeletonColor, 1.5f, true);
					DrawLine(static_canvas, neck, rightShoulder, SkeletonColor, 1.5f, true);
					DrawLine(static_canvas, leftShoulder, leftElbow, SkeletonColor, 1.5f, true);
					DrawLine(static_canvas, rightShoulder, rightElbow, SkeletonColor, 1.5f, true);
					DrawLine(static_canvas, leftElbow, leftWrist, SkeletonColor, 1.5f, true);
					DrawLine(static_canvas, rightElbow, rightWrist, SkeletonColor, 1.5f, true);
					DrawLine(static_canvas, neck, pelvis, SkeletonColor, 1.5f, true);
					DrawLine(static_canvas, pelvis, leftAss, SkeletonColor, 1.5f, true);
					DrawLine(static_canvas, pelvis, rightAss, SkeletonColor, 1.5f, true);
					DrawLine(static_canvas, leftAss, leftKnee, SkeletonColor, 1.5f, true);
					DrawLine(static_canvas, rightAss, rightKnee, SkeletonColor, 1.5f, true);
					DrawLine(static_canvas, leftKnee, leftAnkle, SkeletonColor, 1.5f, true);
					DrawLine(static_canvas, rightKnee, rightAnkle, SkeletonColor, 1.5f, true);
				}

				if (G::EspPlayerName)
				{
					auto PlayerState = actor->PlayerState();
					if (PlayerState)
					{
						TextOffset_Top -= static_canvas->K2_TextSize(PlayerState->GetPlayerName()).y + 5;
						Vector2 calculation = Vector2(Top.x, TextOffset_Top);
						if (Utils->IsInScreen(calculation))
							static_canvas->K2_DrawText(calculation, Colors::Yellow, PlayerState->GetPlayerName().c_str(), true, false);
					}

					static char distanceesp[128];
					static wchar_t wdistanceesp[128];
					sprintf(distanceesp, xorstr("%0.1d m"), (int)(actor->RootComponent()->RelativeLocation().DistanceFrom(o_CamLoc) / 100));
					AnsiToWide(distanceesp, wdistanceesp);

					int NameYes = 5;

					if (G::EspPlayerName)
					{
						NameYes = 10;
					}

					TextOffset_Top -= static_canvas->K2_TextSize(UnrealStructs::FString(wdistanceesp)).y + NameYes;
					Vector2 calculation = Vector2(Top.x, TextOffset_Top);
					if (Utils->IsInScreen(calculation))
						static_canvas->K2_DrawText(calculation, Colors::Red, wdistanceesp, true, false);
				}

				if (LocalPawn)
				{
					if (G::EspWeapon)
					{
						auto weapon = *(uintptr_t*)((uintptr_t)actor + 0x790);
						if (Utils->isValidPointer(weapon))
						{
							auto wdata = *(uintptr_t*)(weapon + 0x3D8);
							if (wdata)
							{
								auto name = *(UnrealStructs::FText*)(wdata + 0x90);
								auto tier = *(UINT8*)(wdata + 0x74);
								auto naam = name.Get();
								if (naam && tier > 0)
								{
									if (naam[0] != 'H' && naam[1] != 'a')
									{
										TextOffset_Bottom -= static_canvas->K2_TextSize(naam).y - 20;
										Vector2 calculation = Vector2(Bottom.x, TextOffset_Bottom);
										if (Utils->IsInScreen(calculation))
											static_canvas->K2_DrawText(calculation,getColorFromTier(tier), naam, true, false);
									}
								}
							}
						}
					}

					if (G::LootAmmo)
					{
						auto WeaponEnemy = actor->CurrentWeapon();
						if (Utils->isValidPointer((uintptr_t)WeaponEnemy))
						{
							auto weaponAmmo = std::to_string(WeaponEnemy->GetMagazineAmmoCount());
							auto weaponAmmoMax = std::to_string(WeaponEnemy->GetBulletsPerClip());
							std::string ammodevider = "/";

							int NameYes = 20;

							if (G::EspWeapon)
							{
								NameYes = 25;
							}

							TextOffset_Bottom -= static_canvas->K2_TextSize(UnrealStructs::FString(s2ws(weaponAmmo + ammodevider + weaponAmmoMax))).y - NameYes;
							Vector2 calculation = Vector2(Bottom.x, TextOffset_Bottom);
							if (Utils->IsInScreen(calculation))
								static_canvas->K2_DrawText(calculation, Colors::Yellow, s2ws(weaponAmmo + ammodevider + weaponAmmoMax), true, false);
						}
					}

					if (G::AimWhileJumping) {
						LocalPawn->WriteAimWhileJumping();
					}

					if (G::VehicleFly) {
						AFortPawn* CurrentVehicle = LocalPawn->GetVehicle();
						Vector3 CarRelativeLocation = CurrentVehicle->RootComponent()->RelativeLocation();
						if (GetAsyncKeyState(0x57)) {
							CurrentVehicle->K2_TeleportTo(CarRelativeLocation, OriginalRotation);
						}
					}

					if (G::VehicleTp) {
						if (GetAsyncKeyState(VK_SHIFT)) {
							AFortPawn* CurrentVehicle = LocalPawn->GetVehicle();
							CurrentVehicle->K2_SetActorLocation(TargetPawn->RootComponent()->RelativeLocation(), false, true);
						}
					}

					if (G::InfAmmo)
					{
						*(float*)(LocalPawn->CurrentWeapon() + 0xA4C) = 0;
						*(float*)(LocalPawn->CurrentWeapon() + 0xA50) = 0;
						*(float*)(LocalPawn->CurrentWeapon() + 0xA54) = 0;

						*(float*)(LocalPawn->CurrentWeapon() + 0xA4C) = 1;
						*(float*)(LocalPawn->CurrentWeapon() + 0xA50) = 1;
						*(float*)(LocalPawn->CurrentWeapon() + 0xA54) = 1;
					}


					if (G::PlayerSpeedBalls)
					{
						if (GetAsyncKeyState(VK_SHIFT))
						{
							*(float*)(LocalPawn + 0x64) = 50000;
						}
						else
						{
							*(float*)(LocalPawn + 0x64) = 1;
						}
					}
				}
			}

			if (G::ProjectileTpEnable)
			{
				if (closestActor)
				{
					if (actor->IsA(UnrealCache::ScannedObjects::Classes::FortProjectileBase))
					{
						if (wcsstr(actor->ObjectName(), xorstr(L"B_Prj_Bullet_Sniper")))
						{
							actor->K2_SetActorLocation(closestActor->GetBone(68), false, true);
						}
					}
				}
			}

			if (G::EspLoot)
			{
				if (actor->IsA(UnrealCache::ScannedObjects::Classes::FortPickup))
				{
					int dist = actor->RootComponent()->RelativeLocation().DistanceFrom(o_CamLoc) / 100;

					if (dist > G::LootRenderDist)
						continue;

					auto Definition = actor->ItemDefinition();
					if (Definition)
					{
						auto ItemPos = PlayerController->WorldToScreen(actor->RootComponent()->RelativeLocation());
						BYTE tier = Definition->Tier();
						auto name = *(UnrealStructs::FText*)(Definition + 0x90);
						auto naam = name.Get();
						if (naam && tier > 0)
						{
							if (naam[0] != 'H' && naam[1] != 'a')
							{
								if (Utils->IsInScreen(ItemPos))
									static_canvas->K2_DrawText(ItemPos, getColorFromTier(tier), naam, true, false);
							}
						}
					}
				}
			}
			//MessageBox(0, L"4", 0, 0);
		}
	}
}