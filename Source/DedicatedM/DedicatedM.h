// DedicatedM.h

#pragma once

#include "CoreMinimal.h"

#pragma region NetLogging

DEDICATEDM_API DECLARE_LOG_CATEGORY_EXTERN(LogDMNet, Log, All);

#define NETMODE_TCHAR ((GetNetMode() == ENetMode::NM_Client) ? *FString::Printf(TEXT("Client%02d"), UE::GetPlayInEditorID()) : ((GetNetMode() == ENetMode::NM_Standalone) ? TEXT("StandAlone") : TEXT("Server")))
#define FUNCTION_TCHAR (ANSI_TO_TCHAR(__FUNCTION__))
#define DM_LOG_NET(LogCategory, Verbosity, Format, ...) UE_LOG(LogCategory, Verbosity, TEXT("[%s] %s | %s"), NETMODE_TCHAR, FUNCTION_TCHAR, *FString::Printf(Format, ##__VA_ARGS__))

#pragma endregion