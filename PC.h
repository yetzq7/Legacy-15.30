#pragma once
#include "framework.h"
#include "Addresses.h"


// idk  what i did here
namespace PC {

	inline APawn* SpawnDefaultPawnFor(AFortGameModeAthena* GameMode, AFortPlayerControllerAthena* PC, AActor* StartSpot)
	{
		auto Transform = StartSpot->GetTransform();

		return GameMode->SpawnDefaultPawnAtTransform(PC, Transform);

		Log("[LEGACY] Hooking PC");
	}

	void Hooks() {
		MH_CreateHook((LPVOID)(ImageBase + Addresses::SpawnDefaultPawnFor), PC::SpawnDefaultPawnFor, nullptr);
	}
}

