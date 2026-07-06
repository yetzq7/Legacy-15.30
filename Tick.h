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

	void Hooks() 
	{

		Hook(ImageBase + Addresses::TickFlush, TickFlush, (void**)&TickFlush_OG);
		Log("[LEGACY] Hooking Tick");
	}
}