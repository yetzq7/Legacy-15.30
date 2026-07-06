#pragma once

#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers
// Windows Header Files
#include <windows.h>
#include <thread>
#include <iostream>
#include <vector>
#include <string>
#include <cstdint>
#include <map>
#include <Windows.h>
#include "SDK/SDK.hpp"
using namespace SDK;
#include "Minhook.h"

static void Hook(uint64_t Address, void* Detour, void** OG)
{
	MH_CreateHook(reinterpret_cast<LPVOID>(Address), Detour, OG);
	MH_EnableHook(reinterpret_cast<LPVOID>(Address));
}