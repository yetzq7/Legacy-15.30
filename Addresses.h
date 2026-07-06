#pragma once
#include "framework.h"

namespace Addresses {
	inline uint64_t GetNetMode = 0x52EC180;
	inline uint64_t GIsClient = 0x96BC1CC;
	inline uint64_t GIsServer = 0x96BC1CD;
	inline uint64_t KickPlayer = 0x4E87860;
	inline uint64_t InitListen = 0x118FD70;
	inline uint64_t SetWorld = 0x4FEEB90;
	inline uint64_t ActorNetMode = 0x4BE4E90;//No Need to worry if this is 0x0
	inline uint64_t ChangeGameSessionId = 0x2746000;//No Need to worry if this is 0x0
	inline uint64_t ApplyCharacterCustomization = 0x2CEAF20;//No Need to worry if this is 0x0
	inline uint64_t CreateNetDriver = 0x5285050;
	inline uint64_t ServerReplicateActors = 0x176C2E0;
	inline uint64_t TickFlush = 0x4FF0070;
	inline uint64_t ReadyToStartMatch = 0x21321A0;
	inline uint64_t SpawnDefaultPawnFor = 0x213E880;
	inline uint64_t ServerAcknowledgePossesion = 0x50F3550;
	inline uint64_t DispatchRequest = 0x12506F0;
	//inline uint64_t GetMaxTickRate = ;
	inline std::vector<uint64_t> NullFuncs = { 0x2746000, 0x4e87860 };
	inline std::vector<uint64_t> RetTrueFuncs = {  };
}