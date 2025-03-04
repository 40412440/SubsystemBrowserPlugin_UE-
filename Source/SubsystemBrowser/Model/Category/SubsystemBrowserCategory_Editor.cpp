﻿// Copyright 2022, Aquanox.

#include "Model/Category/SubsystemBrowserCategory_Editor.h"

#include "Misc/EngineVersionComparison.h"
#include "Editor.h"
#include "EditorSubsystem.h"

FSubsystemCategory_Editor::FSubsystemCategory_Editor()
{
	Name = TEXT("EditorSubsystemCategory");
	SettingsName = TEXT("Editor");
	Label = NSLOCTEXT("SubsystemBrowser", "SubsystemBrowser_Editor", "Editor Subsystems");
	SortOrder = 200;
}

UClass* FSubsystemCategory_Editor::GetSubsystemClass() const
{
	return UEditorSubsystem::StaticClass();
}

void FSubsystemCategory_Editor::Select(UWorld* InContext, TArray<UObject*>& OutData) const
{
	if (GEditor)
	{
#if UE_VERSION_OLDER_THAN(5, 5, 0)
		return OutData.Append(GEditor->GetEditorSubsystemArray<UEditorSubsystem>());
#else
		return OutData.Append(GEditor->GetEditorSubsystemArrayCopy<UEditorSubsystem>());
#endif
	}
}
