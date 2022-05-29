#pragma once

namespace debug
{

	int i = 1;
	int i2 = 2;
	uintptr_t test1 = true;
	uintptr_t test2 = true;
	uintptr_t test3 = true;
	uintptr_t test4 = true;

	
}


namespace UnrealStructs
{
	
	struct FMatrix
	{
		double M[4][4];
	

	};
	static FMatrix* myMatrix = new FMatrix();

	template<class T>
	struct TArray
	{
		friend struct FString;

	public:
		inline TArray()
		{
			Data = nullptr;
			Count = Max = 0;
		};

		inline int Num() const
		{
			return Count;
		};

		inline T& operator[](int i)
		{
			return Data[i];
		};

		inline const T& operator[](int i) const
		{
			return Data[i];
		};

		inline bool IsValidIndex(int i) const
		{
			return i < Num();
		}

	private:
		T* Data;
		int32_t Count;
		int32_t Max;
	};

	struct FString : private TArray<wchar_t>
	{
		inline FString()
		{
		};

		FString(const wchar_t* other)
		{
			Max = Count = *other ? wcslen(other) + 1 : 0;

			if (Count)
			{
				Data = const_cast<wchar_t*>(other);
			}
		};

		inline bool IsValid() const
		{
			return Data != nullptr;
		}

		inline const wchar_t* c_str() const
		{
			return Data;
		}
	};

	struct FName
	{
		uint32_t ComparisonIndex;
		uint32_t DisplayIndex;
	};

	struct FKey
	{
		FName KeyName;
		unsigned char Padding_00[0x10];
	};

	struct FLinearColor
	{
		float R;
		float G;
		float B;
		float A;

		FLinearColor()
		{
			R = G = B = A = 0;
		}

		FLinearColor(float R, float G, float B, float A)
		{
			this->R = R;
			this->G = G;
			this->B = B;
			this->A = A;
		}
	};

	struct FRotator
	{
		double Pitch;
		double Yaw;
		double Roll;
	};

	struct FMinimalViewInfo {
		Vector3 Location;
		Vector3 Rotation;
		float FOV;
		float OrthoWidth;
		float OrthoNearClipPlane;
		float OrthoFarClipPlane;
		float AspectRatio;
	};

	class FTextData {
	public:
		char pad_0x0000[0x30];  //0x0000
		wchar_t* Name;          //0x0028 
		__int32 Length;         //0x0030 

	};

	struct FText {
		FTextData* Data;
		char UnknownData[0x10];

		wchar_t* Get() const {
			if (Data) {
				return Data->Name;
			}

			return nullptr;
		}
	};
}

namespace UnrealClasses
{
	class UClass {
	public:
		BYTE _padding_0[0x40];
		UClass* SuperClass;
	};

	class UObject {
	public:
		PVOID VTableObject;
		DWORD ObjectFlags;
		DWORD InternalIndex;
		UClass* Class;
		BYTE _padding_0[0x8];
		UObject* Outer;

		inline BOOLEAN IsA(PVOID parentClass)
		{
			for (auto super = this->Class; super; super = super->SuperClass)
				if (super == parentClass)
					return true;

			return false;
		}
	};

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
			return (pt.x > Origin.x && pt.y > Origin.y && pt.x < extent.x && pt.y < extent.y);
		}
	};

	class FUObjectItem {
	public:
		UObject* Object;
		DWORD Flags;
		DWORD ClusterIndex;
		DWORD SerialNumber;
		DWORD SerialNumber2;
	};

	class TUObjectArray {
	public:
		FUObjectItem* Objects[9];
	};

	class GObjects {
	public:
		TUObjectArray* ObjectArray;
		BYTE _padding_0[0xC];
		DWORD ObjectCount;
	};

	inline GObjects* objects = nullptr;
}

namespace UnrealCache
{
	namespace ScannedPattern
	{
		inline uintptr_t Base = 0;
		inline uintptr_t UWorld = 0;
		inline uintptr_t FreeFn = 0;
		inline uintptr_t GetNameByIndex = 0;
		inline uintptr_t LineSightOfTo = 0;
		inline uintptr_t GetBoneMatrix = 0;
		inline uintptr_t ProjectWorldToScreen = 0;
	}

	namespace ScannedObjects
	{
		inline UnrealClasses::UObject* Font = 0;
		inline UnrealClasses::UObject* K2_DrawLine = 0;
		inline UnrealClasses::UObject* K2_DrawBox = 0;
		inline UnrealClasses::UObject* K2_DrawText = 0;
		inline UnrealClasses::UObject* K2_TextSize = 0;

		inline UnrealClasses::UObject* K2_SetActorLocation = 0;
		inline UnrealClasses::UObject* GetPlayerName = 0;
		inline UnrealClasses::UObject* IsDBNO = 0;
		inline UnrealClasses::UObject* GetCameraLocation = 0;
		inline UnrealClasses::UObject* GetVehicle = 0;
		inline UnrealClasses::UObject* K2_TeleportTo = 0;

		namespace Classes
		{
			inline UnrealClasses::UObject* FortPlayerPawnAthena = 0;
			inline UnrealClasses::UObject* FortPickup = 0;
			inline UnrealClasses::UObject* FortProjectileBase = 0;
		}
	}
}

namespace UnrealObjects
{
	inline void FnFree(uintptr_t address)
	{
		if (!Utils->isValidPointer(address)) return;
		auto function = reinterpret_cast<void(__fastcall*)(__int64)>(UnrealCache::ScannedPattern::FreeFn);
		return function((__int64)address);
	}

	inline const wchar_t* GetNameByIndex(int idx)
	{
		std::wstring name = L"";

		if (!idx) return L"";

		auto function = reinterpret_cast<UnrealStructs::FString * (__fastcall*)(int* index, UnrealStructs::FString * res)>(UnrealCache::ScannedPattern::GetNameByIndex);

		int index = idx;

		UnrealStructs::FString fObjectName;
		function(&index, &fObjectName);

		if (!fObjectName.IsValid()) return L"";

		auto objectName = fObjectName.c_str();

		name = objectName;
		FnFree((uintptr_t)fObjectName.c_str());

		return name.c_str();
	}

	inline const wchar_t* GetObjectName(UnrealClasses::UObject* object)
	{
		std::wstring name = (L"");

		if (!object) return (L"");

		auto function = reinterpret_cast<UnrealStructs::FString * (__fastcall*)(int* index, UnrealStructs::FString * res)>(UnrealCache::ScannedPattern::GetNameByIndex);

		int index = *(int*)(reinterpret_cast<uint64_t>(object) + 0x18);

		UnrealStructs::FString fObjectName;
		function(&index, &fObjectName);

		if (!fObjectName.IsValid()) return (L"");

		auto objectName = fObjectName.c_str();

		name = objectName;
		FnFree((uintptr_t)fObjectName.c_str());

		return name.c_str();
	}

	inline const wchar_t* GetFullObjectName(UnrealClasses::UObject* object)
	{
		std::wstring name = (L"");

		for (auto i = 0; object; object = object->Outer, i++)
		{
			if (!object) return (L"");

			auto function = reinterpret_cast<UnrealStructs::FString * (__fastcall*)(int* index, UnrealStructs::FString * res)>(UnrealCache::ScannedPattern::GetNameByIndex);

			int index = *(int*)(reinterpret_cast<uint64_t>(object) + 0x18);

			UnrealStructs::FString fObjectName;
			function(&index, &fObjectName);

			if (!fObjectName.IsValid()) break;

			auto objectName = fObjectName.c_str();

			name = objectName + std::wstring(i > 0 ? (L".") : (L"")) + name;
			FnFree((uintptr_t)fObjectName.c_str());
		}

		return name.c_str();
	}

	inline void NumChunks(UnrealClasses::TUObjectArray* ObjectArray, int* start, int* end)
	{
		int cStart = 0, cEnd = 0;

		if (!cEnd)
		{
			while (true)
			{
				if (ObjectArray->Objects[cStart] == nullptr)
				{
					cStart++;
				}
				else
				{
					break;
				}
			}

			cEnd = cStart;
			while (true)
			{
				if (ObjectArray->Objects[cEnd] == nullptr)
				{
					break;
				}
				cEnd++;
			}
		}

		*start = cStart;
		*end = cEnd;
	}

	inline UnrealClasses::UObject* GetObjByIndex(UnrealClasses::TUObjectArray* ObjectArray, int32_t index)
	{
		int cStart = 0, cEnd = 0;
		int chunkIndex, chunkSize = 0xFFFF, chunkPos;
		UnrealClasses::FUObjectItem* Object;

		NumChunks(ObjectArray, &cStart, &cEnd);

		chunkIndex = index / chunkSize;
		if (chunkSize * chunkIndex != 0 &&
			chunkSize * chunkIndex == index)
		{
			chunkIndex--;
		}

		chunkPos = cStart + chunkIndex;
		if (chunkPos < cEnd)
		{
			Object = ObjectArray->Objects[chunkPos] + (index - chunkSize * chunkIndex);
			if (!Object) { return nullptr; }

			return Object->Object;
		}

		return nullptr;
	}


	inline const wchar_t* fix_objectname(const wchar_t* objname)
	{
		wchar_t* _4 = (wchar_t*)objname;

		for (int i = 0; i < wcslen(_4); i++)
		{
			if (_4[i] == L'_')
			{
				if (_4[i + 1] == L'0' ||
					_4[i + 1] == L'1' ||
					_4[i + 1] == L'2' ||
					_4[i + 1] == L'3' ||
					_4[i + 1] == L'4' ||
					_4[i + 1] == L'5' ||
					_4[i + 1] == L'6' ||
					_4[i + 1] == L'7' ||
					_4[i + 1] == L'8' ||
					_4[i + 1] == L'9')
					_4[i] = L'$';

				for (int idx = 1; idx < 7; idx++) {

					if (_4[i + idx] == L'.') break;

					if (_4[i + idx] == L'0' ||
						_4[i + idx] == L'1' ||
						_4[i + idx] == L'2' ||
						_4[i + idx] == L'3' ||
						_4[i + idx] == L'4' ||
						_4[i + idx] == L'5' ||
						_4[i + idx] == L'6' ||
						_4[i + idx] == L'7' ||
						_4[i + idx] == L'8' ||
						_4[i + idx] == L'9') {
						_4[i + idx] = L'$';
					}
				}

			}
		}

		std::wstring str = _4;
		str.erase(std::remove(str.begin(), str.end(), '$'), str.end());
		return str.c_str();
	}

	inline PVOID FindObject(const wchar_t* objectname)
	{
		for (auto index = 0x0; index < UnrealClasses::objects->ObjectCount; index++)
		{
			auto object = GetObjByIndex(UnrealClasses::objects->ObjectArray, index);
			const wchar_t* tmp_name = GetFullObjectName(object);
			const wchar_t* name = fix_objectname(tmp_name);

			if ((wcsstr(name, objectname)))
			{
				return object;
			}
		}

		return 0;
	}

	inline bool ProcessEvent(uintptr_t address, void* fnobject, void* parms)
	{
		if (!Utils->isValidPointer(address)) return false;
		auto index = *reinterpret_cast<void***>(address); if (!index) return false;
		auto fProcessEvent = static_cast<void(*)(void* address, void* fnobject, void* parms)>(index[0x4C]); if (!fProcessEvent) return false;
		fProcessEvent((void*)address, (void*)fnobject, (void*)parms);
		return true;
	}
}

class APlayerState {
public:
	uintptr_t TeamIndex() {
		if (!Utils->isValidPointer((uintptr_t)this)) return 0;
		return *(uintptr_t*)((uintptr_t)this + 0x1010);
	}

	UnrealStructs::FString GetPlayerName() {
		UnrealStructs::FString PlayerName;

		if (!this) return L"";

		UnrealObjects::ProcessEvent(uintptr_t(this), UnrealCache::ScannedObjects::GetPlayerName, &PlayerName);

		if (!PlayerName.IsValid()) return L"";

		return PlayerName;
	}
};

class AFortItemDefinition {
public:
	UnrealStructs::FText* DisplayName() {
		if (!Utils->isValidPointer((uintptr_t)this)) return {};
		return reinterpret_cast<UnrealStructs::FText*>(*(uintptr_t*)((uintptr_t)this + 0x90));
	}

	UINT8 Tier() {
		if (!Utils->isValidPointer((uintptr_t)this)) return 0;
		return *(UINT8*)((uintptr_t)this + 0x74);
	}
};

class AFortWeapon {
public:
	AFortItemDefinition* WeaponData() {
		if (!Utils->isValidPointer((uintptr_t)this)) return 0;
		return (AFortItemDefinition*)(*(uintptr_t*)((uintptr_t)this + 0x3D8));
	}

	int GetMagazineAmmoCount()
	{
		static PVOID fn = NULL;
		if (!fn)
			fn = UnrealObjects::FindObject(xorstr(L"FortniteGame.FortWeapon.GetMagazineAmmoCount"));

		struct
		{
			int                                                ReturnValue;
		}params;

		UnrealObjects::ProcessEvent(uintptr_t(this), fn, &params);

		return params.ReturnValue;
	}

	int GetBulletsPerClip()
	{
		static PVOID fn = NULL;
		if (!fn)
			fn = UnrealObjects::FindObject(xorstr(L"FortniteGame.FortWeapon.GetBulletsPerClip"));

		struct
		{
			int                                                ReturnValue;
		}params;

		UnrealObjects::ProcessEvent(uintptr_t(this), fn, &params);

		return params.ReturnValue;
	}

	bool WeaponDataIsValid()
	{
		static PVOID fn = NULL;
		if (!fn)
			fn = UnrealObjects::FindObject(xorstr(L"FortniteGame.FortWeapon.WeaponDataIsValid"));

		struct
		{
			bool                                                ReturnValue;
		}params;

		UnrealObjects::ProcessEvent(uintptr_t(this), fn, &params);

		return params.ReturnValue;
	}

};

class APlayerCameraManager {
public:
	Vector3 GetCameraLocation()
	{
		if (!Utils->isValidPointer((uintptr_t)this)) return { 0,0,0 };

		struct APlayerCameraManager_GetCameraLocation_Params
		{
			Vector3                                    ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
		};
		APlayerCameraManager_GetCameraLocation_Params params;

		UnrealObjects::ProcessEvent((uintptr_t)this, UnrealCache::ScannedObjects::GetCameraLocation, &params);

		return params.ReturnValue;
	}

	float GetFOVAngle()
	{
		static PVOID fn = NULL;
		if (!fn)
			fn = UnrealObjects::FindObject(xorstr(L"Engine.PlayerCameraManager.GetFOVAngle"));

		struct APlayerCameraManager_GetFOVAngle_Params
		{
			float                                              ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
		};

		APlayerCameraManager_GetFOVAngle_Params params;

		UnrealObjects::ProcessEvent((uintptr_t)this, fn, &params);

		return params.ReturnValue;
	}
};

class ARootComponent {
public:

	Vector3 RelativeLocation() {
		if (!Utils->isValidPointer((uintptr_t)this)) return { 0, 0, 0 };
		return *(Vector3*)((uintptr_t)this + 0x128);
	}
};

class UFortItemDefinition {
public:
	UnrealStructs::FText* DisplayName() {
		if (!Utils->isValidPointer(uintptr_t(this))) return 0;
		return reinterpret_cast<UnrealStructs::FText*>(*(uintptr_t*)((uintptr_t)this + 0x90));
	}

	BYTE Tier() {
		if (!Utils->isValidPointer(uintptr_t(this))) return false;
		return *(BYTE*)((uintptr_t)this + 0x74);
	}
};

class AFortPawn {
public:
	const wchar_t* ObjectName() {
		if (!Utils->isValidPointer((uintptr_t)this)) return (L"");
		return UnrealObjects::GetObjectName((UnrealClasses::UObject*)this);
	}

	uintptr_t Mesh() {
		if (!Utils->isValidPointer((uintptr_t)this)) return 0;
		return *(uintptr_t*)((uintptr_t)this + 0x2F0);
	}

	UFortItemDefinition* ItemDefinition() {
		if (!Utils->isValidPointer((uintptr_t)this)) return 0;
		return (UFortItemDefinition*)(*(uintptr_t*)((uintptr_t)this + (0x2F8 + 0x18)));
	}

	BOOL bAlreadySearched() {
		if (!Utils->isValidPointer((uintptr_t)this)) return 0;
		return ((*(BYTE*)((uintptr_t)this + 0xf61) >> 7) & 1); //BuildingContainer.bAlreadySearched
	}

	AFortWeapon* CurrentWeapon() {
		if (!Utils->isValidPointer((uintptr_t)this)) return 0;
		return (AFortWeapon*)(*(uintptr_t*)((uintptr_t)this + 0x790));
	}

	ARootComponent* RootComponent() {
		if (!Utils->isValidPointer((uintptr_t)this)) return 0;
		return (ARootComponent*)(*(uintptr_t*)((uintptr_t)this + 0x188));
	}

	APlayerState* PlayerState() {
		if (!Utils->isValidPointer((uintptr_t)this)) return 0;
		return (APlayerState*)(*(uintptr_t*)((uintptr_t)this + 0x290));
	}

	BOOL IsA(PVOID parentClass)
	{
		if (!Utils->isValidPointer(uintptr_t(this))) return false;

		UnrealClasses::UObject* object = (UnrealClasses::UObject*)this;
		for (auto super = object->Class; super; super = super->SuperClass)
			if (super == parentClass)
				return true;

		return false;
	}

	struct Gayniger {

	};

	BOOL K2_SetActorLocation(const Vector3 NewLocation, bool bSweep, bool bTeleport)
	{
		if (!Utils->isValidPointer((uintptr_t)this)) return 0;

		struct
		{
			Vector3			NewLocation;
			bool							bSweep;
			int								SweepHitResult;
			bool							bTeleport;
			bool							ReturnValue;
		} params;

		params.NewLocation = NewLocation;
		params.bSweep = bSweep;
		params.bTeleport = bTeleport;

		UnrealObjects::ProcessEvent((uintptr_t)this, UnrealCache::ScannedObjects::K2_SetActorLocation, &params);

		return params.ReturnValue;
	}

	Vector3 GetBone(int Id)
	{
		//if (!Utils->isValidPointer(uintptr_t(this))) MessageBox(0, L"kys", 0, 0);
		if (!Utils->isValidPointer(uintptr_t(this))) return { 0, 0, 0 };

		auto mesh = Mesh();
		if (!mesh) return { 0, 0, 0 };

		auto function = ((UnrealStructs::FMatrix * (__fastcall*)(uintptr_t, UnrealStructs::FMatrix*, int))(UnrealCache::ScannedPattern::GetBoneMatrix));
		function(mesh, UnrealStructs::myMatrix, Id);

		return { UnrealStructs::myMatrix->M[3][0], UnrealStructs::myMatrix->M[3][1], UnrealStructs::myMatrix->M[3][2] };
	}
	static bool GetBoneLocation1(uintptr_t CurrentActor, int id, Vector3* out)
	{
		uintptr_t mesh = *(uintptr_t*)(CurrentActor + 300);
		if (!mesh) return false;

		auto fGetBoneMatrix = ((UnrealStructs::FMatrix * (__fastcall*)(uintptr_t, UnrealStructs::FMatrix*, int))(UnrealCache::ScannedPattern::GetBoneMatrix));
		fGetBoneMatrix(mesh, UnrealStructs::myMatrix, id);

		out->x = UnrealStructs::myMatrix->M[3][0];
		out->y = UnrealStructs::myMatrix->M[3][1];
		out->z = UnrealStructs::myMatrix->M[3][2];

		return true;
	}

	bool IsDBNO()
	{
		if (!Utils->isValidPointer((uintptr_t)this)) return false;

		struct
		{
			bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
		} params;

		UnrealObjects::ProcessEvent(uintptr_t(this), UnrealCache::ScannedObjects::IsDBNO, &params);

		return params.ReturnValue;
	}

	void WriteAimWhileJumping()
	{
		*(bool*)(this + 0x4805) = true;
	}

	AFortPawn* GetVehicle() {

		if (!Utils->isValidPointer((uintptr_t)this)) return 0;
		uintptr_t result;

		UnrealObjects::ProcessEvent(uintptr_t(this), UnrealCache::ScannedObjects::GetVehicle, &result);

		return (AFortPawn*)result;
	}

	struct AActor_K2_TeleportTo_Params
	{
		Vector3										DestLocation;                                             // (Parm, ZeroConstructor, IsPlainOldData)
		Vector3										DestRotation;                                             // (Parm, ZeroConstructor, IsPlainOldData)
		bool										ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
	};

	BOOL K2_TeleportTo(const Vector3& DestLocation, const Vector3& DestRotation)
	{
		if (!Utils->isValidPointer((uintptr_t)this)) return 0;
		AActor_K2_TeleportTo_Params params;
		params.DestLocation = DestLocation;
		params.DestRotation = DestRotation;

		UnrealObjects::ProcessEvent((uintptr_t)this, UnrealCache::ScannedObjects::K2_TeleportTo, &params);

		return params.ReturnValue;
	}
};

class UCanvas {
public:

	int32_t SizeX() {
		if (!Utils->isValidPointer((uintptr_t)this)) return 0;
		return *(int32_t*)((uintptr_t)this + 0x40);
	}

	int32_t SizeY() {
		if (!Utils->isValidPointer((uintptr_t)this)) return 0;
		return *(int32_t*)((uintptr_t)this + 0x44);
	}

	void K2_DrawLine(Vector2 ScreenPositionA, Vector2 ScreenPositionB, float Thickness, UnrealStructs::FLinearColor RenderColor)
	{
		if (!Utils->isValidPointer((uintptr_t)this)) return;

		struct
		{
			Vector2                                   ScreenPositionA;                                          // (Parm, ZeroConstructor, IsPlainOldData)
			Vector2                                  ScreenPositionB;                                          // (Parm, ZeroConstructor, IsPlainOldData)
			float                                              Thickness;                                                // (Parm, ZeroConstructor, IsPlainOldData)
			UnrealStructs::FLinearColor                                RenderColor;                                              // (Parm, ZeroConstructor, IsPlainOldData)
		} params;

		params.ScreenPositionA = { ScreenPositionA.x, ScreenPositionA.y };
		params.ScreenPositionB = { ScreenPositionB.x, ScreenPositionB.y };
		params.Thickness = Thickness;
		params.RenderColor = { (float)RenderColor.R, (float)RenderColor.G, (float)RenderColor.B, (float)RenderColor.A };

		UnrealObjects::ProcessEvent(uintptr_t(this), UnrealCache::ScannedObjects::K2_DrawLine, &params);
	}

	void K2_DrawBox(Vector2 ScreenPosition, Vector2 ScreenSize, float Thickness, UnrealStructs::FLinearColor RenderColor)
	{
		if (!Utils->isValidPointer((uintptr_t)this)) return;

		struct
		{
			Vector2                                  ScreenPosition;                                           // (Parm, ZeroConstructor, IsPlainOldData)
			Vector2                                   ScreenSize;                                               // (Parm, ZeroConstructor, IsPlainOldData)
			float                                              Thickness;                                                // (Parm, ZeroConstructor, IsPlainOldData)
			UnrealStructs::FLinearColor                                RenderColor;                                              // (Parm, ZeroConstructor, IsPlainOldData)
		} params;

		params.ScreenPosition = { ScreenPosition.x, ScreenPosition.y };
		params.ScreenSize = { ScreenSize.x, ScreenSize.y };
		params.Thickness = Thickness;
		params.RenderColor = { (float)RenderColor.R, (float)RenderColor.G, (float)RenderColor.B, (float)RenderColor.A };

		UnrealObjects::ProcessEvent(uintptr_t(this), UnrealCache::ScannedObjects::K2_DrawBox, &params);
	}

	void K2_DrawText(Vector2 ScreenPosition, UnrealStructs::FLinearColor RenderColor, UnrealStructs::FString RenderText, bool bCentered = true, bool bOutlined = false)
	{
		if (!Utils->isValidPointer((uintptr_t)this)) return;

		struct
		{
			uintptr_t RenderFont;                                               // (Parm, ZeroConstructor, IsPlainOldData)
			UnrealStructs::FString                                     RenderText;                                               // (Parm, ZeroConstructor)
			Vector2                                   ScreenPosition;                                           // (Parm, ZeroConstructor, IsPlainOldData)
			Vector2                                   Scale;                                                    // (Parm, ZeroConstructor, IsPlainOldData)
			UnrealStructs::FLinearColor                                RenderColor;                                              // (Parm, ZeroConstructor, IsPlainOldData)
			float                                              Kerning;                                                  // (Parm, ZeroConstructor, IsPlainOldData)
			UnrealStructs::FLinearColor                                ShadowColor;                                              // (Parm, ZeroConstructor, IsPlainOldData)
			Vector2                                   ShadowOffset;                                             // (Parm, ZeroConstructor, IsPlainOldData)
			bool                                               bCentreX;                                                 // (Parm, ZeroConstructor, IsPlainOldData)
			bool                                               bCentreY;                                                 // (Parm, ZeroConstructor, IsPlainOldData)
			bool                                               bOutlined;                                                // (Parm, ZeroConstructor, IsPlainOldData)
			UnrealStructs::FLinearColor                                OutlineColor;                                             // (Parm, ZeroConstructor, IsPlainOldData)
		} params;

		params.RenderFont = uintptr_t(UnrealCache::ScannedObjects::Font);
		params.RenderText = RenderText;
		params.ScreenPosition = { ScreenPosition.x, ScreenPosition.y };
		params.Scale = { 1.f, 1.f };
		params.RenderColor = { (float)RenderColor.R, (float)RenderColor.G, (float)RenderColor.B, (float)RenderColor.A };
		params.Kerning = false;
		params.ShadowColor = { 0.f, 0.f, 0.f, 0.f };
		params.ShadowOffset = { ScreenPosition.x + 1.5f, ScreenPosition.y + 1.5f };

		if (bCentered)
		{
			params.bCentreX = true;
			params.bCentreY = true;
		}
		else
		{
			params.bCentreX = false;
			params.bCentreY = false;
		}

		params.bOutlined = bOutlined;
		params.OutlineColor = { 0.0f, 0.0f, 0.0f, 1.f };

		UnrealObjects::ProcessEvent(uintptr_t(this), UnrealCache::ScannedObjects::K2_DrawText, &params);
	}

	Vector2 K2_TextSize(UnrealStructs::FString RenderText)
	{
		if (!Utils->isValidPointer((uintptr_t)this)) return { 0, 0 };

		struct
		{
			uintptr_t RenderFont;                                               // (Parm, ZeroConstructor, IsPlainOldData)
			UnrealStructs::FString                                     RenderText;                                               // (Parm, ZeroConstructor)
			Vector2                                   Scale;                                                    // (Parm, ZeroConstructor, IsPlainOldData)
			Vector2                                   ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
		} params;

		params.RenderFont = uintptr_t(UnrealCache::ScannedObjects::Font);
		params.RenderText = RenderText;
		params.Scale = { 0.6f, 0.6f };

		UnrealObjects::ProcessEvent(uintptr_t(this), UnrealCache::ScannedObjects::K2_TextSize, &params);

		return { params.ReturnValue.x, params.ReturnValue.y };
	}
};

class APlayerController {
public:
	AFortPawn* LocalPawn() {
		if (!Utils->isValidPointer((uintptr_t)this)) return 0;
		return (AFortPawn*)(*(uintptr_t*)((uintptr_t)this + 0x310)); //updated
	}

	APlayerCameraManager* PlayerCameraManager() {
		if (!Utils->isValidPointer((uintptr_t)this)) return 0;
		return (APlayerCameraManager*)(*(uintptr_t*)(this + 0x328)); //updated
	}

	BOOLEAN LineOfSightTo(AFortPawn* Actor) {

		Vector3 ViewPoint = { 0,0,0 };

		auto LOSTo = reinterpret_cast<bool(__fastcall*)(APlayerController * PlayerController, AFortPawn * Actor, Vector3 * ViewPoint)>(UnrealCache::ScannedPattern::LineSightOfTo);

		return LOSTo(this, Actor, &ViewPoint);
	}

	Vector2 WorldToScreen(Vector3 WorldLocation)
	{
		/*if (!Utils->isValidPointer(uintptr_t(this))) MessageBox(0, L"kys2", 0, 0);*/
		if (!Utils->isValidPointer(uintptr_t(this))) return Vector2(0, 0);

		Vector2 Output;

		auto WorldToScreen = reinterpret_cast<bool(__fastcall*)(uintptr_t, Vector3, Vector2*, char)>(UnrealCache::ScannedPattern::ProjectWorldToScreen);
		WorldToScreen((uintptr_t)this, WorldLocation, &Output, (char)0);

		return { Output.x, Output.y };
	}
	static bool WorldToScreen1(uintptr_t PlayerController, Vector3 WorldLocation, Vector3* out)
	{
		auto WorldToScreen = reinterpret_cast<bool(__fastcall*)(uintptr_t pPlayerController, Vector3 vWorldPos, Vector3 * vScreenPosOut, char)>(UnrealCache::ScannedPattern::ProjectWorldToScreen);

		WorldToScreen((uintptr_t)PlayerController, WorldLocation, out, (char)0);

		if (out->x == 0 && out->y == 0 && out->z == 0) return false;
		else return true;
	}
};

class ULocalPlayer {
public:
	APlayerController* PlayerController() {
		if (!Utils->isValidPointer((uintptr_t)this)) return 0;
		return (APlayerController*)(*(uintptr_t*)((uintptr_t)this + 0x30)); //updated
	}
};

class ULocalPlayers {
public:
	ULocalPlayer* LocalPlayer() {
		if (!Utils->isValidPointer((uintptr_t)this)) return 0;
		return (ULocalPlayer*)(*(uintptr_t*)((uintptr_t)this));//updated
	}
};

class UGameInstance {
public:
	ULocalPlayers* LocalPlayers() {
		if (!Utils->isValidPointer((uintptr_t)this)) return 0;
		return (ULocalPlayers*)(*(uintptr_t*)((uintptr_t)this + 0x38));//updated
	}
};

class AActors {
public:
	AFortPawn* GetCurrentActor(int i) {
		if (!Utils->isValidPointer((uintptr_t)this)) return 0;
		return (AFortPawn*)(*(uintptr_t*)((uintptr_t)this + i * sizeof(uintptr_t)));
	}
};

class ULevel {
public:
	AActors* Actors() {
		if (!Utils->isValidPointer((uintptr_t)this)) return 0;
		return (AActors*)(*(uintptr_t*)((uintptr_t)this + 0x98)); //updated
	}

	INT ActorCount() {
		if (!Utils->isValidPointer((uintptr_t)this)) return 0;
		return (int)(*(uintptr_t*)((uintptr_t)this + 0xA0)); //updated
	}

	UnrealStructs::TArray<AFortPawn*> ActorArray() {
		if (!Utils->isValidPointer((uintptr_t)this)) return {};
		return *(UnrealStructs::TArray<AFortPawn*>*)((uintptr_t)this + 0x98); //updated
	}
};

class UWorld {
public:

	UGameInstance* OwningGameInstance() {
		if (!Utils->isValidPointer((uintptr_t)this)) return 0;
		return (UGameInstance*)(*(uintptr_t*)((uintptr_t)this + 0x1A8)); //updated
	}

	ULevel* PersistentLevel() {
		if (!Utils->isValidPointer((uintptr_t)this)) return 0;
		return (ULevel*)(*(uintptr_t*)((uintptr_t)this + 0x30)); //updated
	}

	UnrealStructs::TArray<ULevel*> Levels() {
		if (!Utils->isValidPointer((uintptr_t)this)) return {};
		return *(UnrealStructs::TArray<ULevel*>*)((uintptr_t)this + 0x160); //updated
	}
};
