#pragma once
#include "framework.h"
#include "Addresses.h"
#define Log(msg) printf("%s\n", msg)

namespace Tick {

	inline void (*TickFlush_OG)(UNetDriver* Driver, float DeltaSeconds);
	inline void TickFlush(UNetDriver* Driver, float DeltaSeconds)
	{
		if (Driver->ReplicationDriver)
		{
			Funcs::ServerReplicateActors(Driver->ReplicationDriver, DeltaSeconds);
		}

		return TickFlush_OG(Driver, DeltaSeconds);
	}

//	inline float GetMaxTickRate()
//	{
	//	return 30.f;
//	}

	void Hooks() 
	{

		Hook(ImageBase + Addresses::TickFlush, TickFlush, (void**)&TickFlush_OG);
		//MH_CreateHook((LPVOID)(ImageBase + Addresses::GetMaxTickRate), GetMaxTickRate, nullptr);
		Log("[LEGACY] Hooking Tick");
	}
}