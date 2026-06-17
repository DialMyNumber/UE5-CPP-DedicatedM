// Dedicated.cpp

#include "DedicatedM.h"
#include "Modules/ModuleManager.h"

IMPLEMENT_PRIMARY_GAME_MODULE( FDefaultGameModuleImpl, DedicatedM, "DedicatedM" );

#pragma region NetLogging

DEFINE_LOG_CATEGORY(LogDMNet);

#pragma endregion