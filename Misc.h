#pragma once
#include "framework.h"
#include "Addresses.h"
#define Log(msg) printf("%s\n", msg)

namespace Misc {

	static inline void (*KickPlayerOG)(AGameSession*, AController*);
	static void KickPlayer(AGameSession*, AController*) {
		return;
	}

	void (*DispatchRequestOG)(__int64 a1, unsigned __int64* a2, int a3);
	void DispatchRequest(__int64 a1, unsigned __int64* a2, int a3)
	{
		return DispatchRequestOG(a1, a2, 3);
	}

	void Hooks()
	{
		MH_CreateHook((LPVOID)(ImageBase + Addresses::KickPlayer), KickPlayer, (LPVOID*)&KickPlayerOG);
		MH_CreateHook((LPVOID)(ImageBase + Addresses::DispatchRequest), DispatchRequest, (LPVOID*)&DispatchRequestOG);

		Log("[LEGACY] Hooking 67");
	}
}