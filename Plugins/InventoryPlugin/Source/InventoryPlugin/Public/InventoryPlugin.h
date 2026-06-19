// InventoryPlugin.h

#pragma once

#include "Modules/ModuleManager.h"

class FInventoryPluginModule : public IModuleInterface
{
public:

	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
};