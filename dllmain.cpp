// dllmain.cpp : Defines the entry point for the DLL application.
#include "framework.h"
#include "Gamemode.h"
#include "Tick.h"
#include "NetMode.h"
#include "PC.h"
#include "Misc.h"

#define Log(msg) printf("%s\n", msg)

void Main() {
	AllocConsole();
	FILE* File = nullptr;
	freopen_s(&File, "CONOUT$", "w+", stdout);
	SetConsoleTitleA("Legacy 15.30 | Loading..");
	std::cout << "Legacy 15.30, made by yetzq" << "\n";
	MH_Initialize();
	Sleep(5000);
	Mode::Hooks();
	Net::Hooks();
	PC::Hooks();
	Tick::Hooks();
	Misc::Hooks();

	MH_EnableHook(MH_ALL_HOOKS);

	*reinterpret_cast<bool*>(ImageBase + Addresses::GIsClient) = false;
	*reinterpret_cast<bool*>(ImageBase + Addresses::GIsClient + 1) = true;

	UEngine::GetEngine()->GameViewport->World->OwningGameInstance->LocalPlayers.Remove(0);
	UKismetSystemLibrary::ExecuteConsoleCommand(UWorld::GetWorld(), L"open Apollo_Terrain", nullptr);
	//Log("[LEGACY] Loading Apollo..";
	std::cout << "[LEGACY] Loading Apollo..." << "\n";
}

void ReturnHook() {

	for (auto& NullFunc : Addresses::NullFuncs)
	{
		Hook(ImageBase + NullFunc, ReturnHook, nullptr);
	}
}

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
		std::thread(Main).detach();
        break;
    }
    return TRUE;
}