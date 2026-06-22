// InventoryLog.h

#pragma once

#include "CoreMinimal.h"

INVENTORYPLUGIN_API DECLARE_LOG_CATEGORY_EXTERN(InventoryLog, Log, All);

#define NETMODE_TCHAR \
((GetNetMode() == ENetMode::NM_Client) ? \
*FString::Printf(TEXT("Client%02d"), UE::GetPlayInEditorID()) : \
((GetNetMode() == ENetMode::NM_Standalone) ? TEXT("Standalone") : TEXT("Server")))

#define AUTH_TCHAR(Actor) \
((Actor && Actor->HasAuthority()) ? TEXT("Authority") : TEXT("Remote"))

#define ROLE_TCHAR(Actor) \
((Actor) ? \
*StaticEnum<ENetRole>()->GetNameStringByValue((int64)(Actor)->GetLocalRole()).RightChop(5) \
: TEXT("NoActor"))

#define FUNCTION_TCHAR (TEXT(__FUNCTION__))

#define INVEN_NET_LOG(LogCategory, Verbosity, Actor, Format, ...) \
UE_LOG(LogCategory, Verbosity, TEXT("[%s][%s][%s] %s | ") TEXT(Format), \
	NETMODE_TCHAR, \
	AUTH_TCHAR(Actor), \
	ROLE_TCHAR(Actor), \
	FUNCTION_TCHAR, \
	##__VA_ARGS__)

/*			Usage
INVEN_NET_LOG(InventoryLog, Warning, GetOwner(), "BeginPlay");
*/