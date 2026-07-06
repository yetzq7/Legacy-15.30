#pragma once
#include "framework.h"
#include "Addresses.h"

#define Log(msg) printf("%s\n", msg)

namespace Net
{
	int (*GetNetMode_OG)(void*);

	int GetNetMode(void* a1)
	{
		return GetNetMode_OG(a1);
	}

	void Hooks()
	{
		MH_CreateHook((LPVOID)(ImageBase + Addresses::GetNetMode), GetNetMode, (LPVOID*)&GetNetMode_OG);

		Log("[LEGACY] Hooking Netmode");
	}
	
}