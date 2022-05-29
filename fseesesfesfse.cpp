#include "stdafx.h"
#include "UnrealMenu.h"
#include "xorstr.hpp"


void InitObjects()
{
    UnrealCache::ScannedObjects::K2_DrawLine = (UnrealClasses::UObject*)UnrealObjects::FindObject(xorstr(L"Engine.Canvas.K2_DrawLine"));
    if (!UnrealCache::ScannedObjects::K2_DrawLine) MessageBox(0, L"K2_DrawLine", 0, 0);

    UnrealCache::ScannedObjects::K2_DrawBox = (UnrealClasses::UObject*)UnrealObjects::FindObject(xorstr(L"Engine.Canvas.K2_DrawBox"));
    if (!UnrealCache::ScannedObjects::K2_DrawBox) MessageBox(0, L"K2_DrawBox", 0, 0);

    UnrealCache::ScannedObjects::Font = (UnrealClasses::UObject*)UnrealObjects::FindObject(xorstr(L"/Engine/EngineFonts/Roboto.Roboto"));
    if (!UnrealCache::ScannedObjects::Font) MessageBox(0, L"Font", 0, 0);

    UnrealCache::ScannedObjects::K2_DrawText = (UnrealClasses::UObject*)UnrealObjects::FindObject(xorstr(L"Engine.Canvas.K2_DrawText"));
    if (!UnrealCache::ScannedObjects::K2_DrawText) MessageBox(0, L"K2_DrawText", 0, 0);

    UnrealCache::ScannedObjects::K2_TextSize = (UnrealClasses::UObject*)UnrealObjects::FindObject(xorstr(L"Engine.Canvas.K2_TextSize"));
    if (!UnrealCache::ScannedObjects::K2_TextSize) MessageBox(0, L"K2_TextSize", 0, 0);

    UnrealCache::ScannedObjects::K2_SetActorLocation = (UnrealClasses::UObject*)UnrealObjects::FindObject(xorstr(L"Engine.Actor.K2_SetActorLocation"));
    if (!UnrealCache::ScannedObjects::K2_SetActorLocation) MessageBox(0, L"K2_SetActorLocation", 0, 0);

    UnrealCache::ScannedObjects::GetPlayerName = (UnrealClasses::UObject*)UnrealObjects::FindObject(xorstr(L"Engine.PlayerState.GetPlayerName"));
    if (!UnrealCache::ScannedObjects::GetPlayerName) MessageBox(0, L"GetPlayerName", 0, 0);

    UnrealCache::ScannedObjects::IsDBNO = (UnrealClasses::UObject*)UnrealObjects::FindObject(xorstr(L"FortniteGame.FortPawn.IsDBNO"));
    if (!UnrealCache::ScannedObjects::IsDBNO) MessageBox(0, L"IsDBNO", 0, 0);

    UnrealCache::ScannedObjects::GetCameraLocation = (UnrealClasses::UObject*)UnrealObjects::FindObject(xorstr(L"Engine.PlayerCameraManager.GetCameraLocation"));
    if (!UnrealCache::ScannedObjects::GetCameraLocation) MessageBox(0, L"GetCameraLocation", 0, 0);

    UnrealCache::ScannedObjects::GetVehicle = (UnrealClasses::UObject*)UnrealObjects::FindObject(xorstr(L"FortniteGame.FortPlayerPawn.GetVehicle"));
    if (!UnrealCache::ScannedObjects::GetVehicle) MessageBox(0, L"GetVehicle", 0, 0);

    UnrealCache::ScannedObjects::K2_TeleportTo = (UnrealClasses::UObject*)UnrealObjects::FindObject(xorstr(L"Engine.Actor.K2_TeleportTo"));
    if (!UnrealCache::ScannedObjects::K2_TeleportTo) MessageBox(0, L"K2_TeleportTo", 0, 0);

    UnrealCache::ScannedObjects::Classes::FortPlayerPawnAthena = (UnrealClasses::UObject*)UnrealObjects::FindObject(xorstr(L"FortniteGame.FortPlayerPawnAthena"));
    if (!UnrealCache::ScannedObjects::Classes::FortPlayerPawnAthena) MessageBox(0, L"FortPlayerPawnAthena", 0, 0);

    UnrealCache::ScannedObjects::Classes::FortPickup = (UnrealClasses::UObject*)UnrealObjects::FindObject(xorstr(L"FortniteGame.FortPickupAthena"));
    if (!UnrealCache::ScannedObjects::Classes::FortPickup) MessageBox(0, L"FortPickup", 0, 0);
}


void InitMain()
{
    UnrealCache::ScannedPattern::UWorld = (uintptr_t)Utils->PatternScan(UnrealCache::ScannedPattern::Base, xorstr("48 89 05 ? ? ? ? 48 8B 4B 78"), 7, true); //UPDATED
    MessageBox(0, L"UWorld", 0, 0);
    UnrealClasses::objects = (UnrealClasses::GObjects*)Utils->PatternScan(UnrealCache::ScannedPattern::Base, xorstr("48 8B 05 ? ? ? ? 48 8B 0C C8 48 8B 04 D1"), 7, true);
    MessageBox(0, L"objects", 0, 0);
    UnrealCache::ScannedPattern::GetBoneMatrix = (uintptr_t)Utils->PatternScan(UnrealCache::ScannedPattern::Base, xorstr("E8 ? ? ? ? 0F 10 40 68"), 5, true); //UPDATED
    MessageBox(0, L"bonemfs", 0, 0);
    UnrealCache::ScannedPattern::ProjectWorldToScreen = (uintptr_t)Utils->PatternScan(UnrealCache::ScannedPattern::Base, xorstr("E8 ? ? ? ? 4C 8D 5C 24 ? 41 88 06 49 8B 5B 20 49 8B 73 30 49 8B 7B 38"), 5, true);
    MessageBox(0, L"w2s", 0, 0);
    UnrealCache::ScannedPattern::FreeFn = (uintptr_t)Utils->PatternScan((uintptr_t)Utils->GetGameBase(), xorstr("48 85 C9 0F 84 ? ? ? ? 53 48 83 EC 20 48 89 7C 24 30 48 8B D9 48 8B 3D ? ? ? ? 48 85 FF 0F 84 ? ? ? ? 48 8B 07 4C 8B 40 30 48 8D 05 ? ? ? ? 4C 3B C0"), 0, false); //UPDATED
    MessageBox(0, L"freefn", 0, 0);
    UnrealCache::ScannedPattern::GetNameByIndex = (uintptr_t)Utils->PatternScan((uintptr_t)Utils->GetGameBase(), xorstr("48 89 5C 24 ? 48 89 74 24 ? ? ? ? ? ? ? ? 48 81 EC ? ? ? ? 48 8B 05 ? ? ? ? 48 33 C4 48 89 84 24 ? ? ? ? ? ? 4C 8B F2"), 0, false); //UPDATED
    MessageBox(0, L"getnamebyfag", 0, 0);
    InitObjects();
    MenuHook();
}

bool _stdcall DllMain(HMODULE module, DWORD reason, LPVOID reserved)
{
    if (reason == DLL_PROCESS_ATTACH)
    {
        system(xorstr("start https://discord.gg/FcBUjm9mVZ"));
        InitMain();
    }

    return TRUE;
}