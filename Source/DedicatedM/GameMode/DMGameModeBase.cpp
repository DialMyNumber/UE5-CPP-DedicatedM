// DMGameModeBase.cpp

#include "DMGameModeBase.h"

#include "DedicatedM/DedicatedM.h"

ADMGameModeBase::ADMGameModeBase()
{
	DM_LOG_NET(LogDMNet, Log, TEXT("Game Mode Test"));
}

void ADMGameModeBase::PreLogin(const FString& Options, const FString& Address, const FUniqueNetIdRepl& UniqueId, FString& ErrorMessage)
{
	DM_LOG_NET(LogDMNet, Log, TEXT("Login Begin"));

	Super::PreLogin(Options, Address, UniqueId, ErrorMessage);

	// ErrorMessage = TEXT("The server is currently full. Please try again later.");
	// ErrorMessage에 유효한 내용이 있으면 로그인 중인 플레이어의 연결이 거부되고
	// 거부된 플레이어는 StandAlone NetMode로 동작함

	DM_LOG_NET(LogDMNet, Log, TEXT("Login End"));
}
