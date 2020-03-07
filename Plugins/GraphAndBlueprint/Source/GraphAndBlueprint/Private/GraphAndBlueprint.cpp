// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "GraphAndBlueprint.h"
#include "GraphAndBlueprintStyle.h"
#include "GraphAndBlueprintCommands.h"
#include "LevelEditor.h"
#include "Widgets/Docking/SDockTab.h"
#include "Widgets/Layout/SBox.h"
#include "EdGraph/EdGraph.h"
#include "GraphEditor.h"
#include "EdGraph/EdGraphSchema.h"
#include "TestGraphSchema.h"
#include "Widgets/Text/STextBlock.h"

#include "Framework/MultiBox/MultiBoxBuilder.h"
#include "MyGraphPanelNodeFactory.h"

static const FName GraphAndBlueprintTabName("GraphAndBlueprint");

#define LOCTEXT_NAMESPACE "FGraphAndBlueprintModule"

void FGraphAndBlueprintModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
	
	FGraphAndBlueprintStyle::Initialize();
	FGraphAndBlueprintStyle::ReloadTextures();

	FGraphAndBlueprintCommands::Register();
	
	PluginCommands = MakeShareable(new FUICommandList);

	PluginCommands->MapAction(
		FGraphAndBlueprintCommands::Get().OpenPluginWindow,
		FExecuteAction::CreateRaw(this, &FGraphAndBlueprintModule::PluginButtonClicked),
		FCanExecuteAction());
		
	FLevelEditorModule& LevelEditorModule = FModuleManager::LoadModuleChecked<FLevelEditorModule>("LevelEditor");
	
	{
		TSharedPtr<FExtender> MenuExtender = MakeShareable(new FExtender());
		MenuExtender->AddMenuExtension("WindowLayout", EExtensionHook::After, PluginCommands, FMenuExtensionDelegate::CreateRaw(this, &FGraphAndBlueprintModule::AddMenuExtension));

		LevelEditorModule.GetMenuExtensibilityManager()->AddExtender(MenuExtender);
	}
	
	{
		TSharedPtr<FExtender> ToolbarExtender = MakeShareable(new FExtender);
		ToolbarExtender->AddToolBarExtension("Settings", EExtensionHook::After, PluginCommands, FToolBarExtensionDelegate::CreateRaw(this, &FGraphAndBlueprintModule::AddToolbarExtension));
		
		LevelEditorModule.GetToolBarExtensibilityManager()->AddExtender(ToolbarExtender);
	}
	
	FGlobalTabmanager::Get()->RegisterNomadTabSpawner(GraphAndBlueprintTabName, FOnSpawnTab::CreateRaw(this, &FGraphAndBlueprintModule::OnSpawnPluginTab))
		.SetDisplayName(LOCTEXT("FGraphAndBlueprintTabTitle", "GraphAndBlueprint"))
		.SetMenuType(ETabSpawnerMenuType::Hidden);

	FEdGraphUtilities::RegisterVisualNodeFactory(MakeShareable(new FMyGraphPanelNodeFactory()));
}

void FGraphAndBlueprintModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
	FGraphAndBlueprintStyle::Shutdown();

	FGraphAndBlueprintCommands::Unregister();

	FGlobalTabmanager::Get()->UnregisterNomadTabSpawner(GraphAndBlueprintTabName);
}

TSharedRef<SDockTab> FGraphAndBlueprintModule::OnSpawnPluginTab(const FSpawnTabArgs& SpawnTabArgs)
{
	FText WidgetText = FText::Format(
		LOCTEXT("WindowWidgetText", "Add code to {0} in {1} to override this window's contents"),
		FText::FromString(TEXT("FGraphAndBlueprintModule::OnSpawnPluginTab")),
		FText::FromString(TEXT("GraphAndBlueprint.cpp"))
		);

	if (GraphObject != nullptr)
	{
		GraphObject->ConditionalBeginDestroy();
		GraphObject = nullptr;
	}

	GraphObject = NewObject<UEdGraph>();
	GraphObject->AddToRoot();
	GraphObject->Schema = UMyGraphSchena::StaticClass();
	GraphEditorslate=SNew(SGraphEditor)
		.GraphToEdit(GraphObject);

	
	return SNew(SDockTab)
		.TabRole(ETabRole::NomadTab)
		[
			// Put your tab content here!
			SNew(SBox)
			.HAlign(HAlign_Fill)
			.VAlign(VAlign_Fill)
			[
				GraphEditorslate.ToSharedRef()
				
			]
		];
}

void FGraphAndBlueprintModule::PluginButtonClicked()
{
	FGlobalTabmanager::Get()->InvokeTab(GraphAndBlueprintTabName);
}

void FGraphAndBlueprintModule::AddMenuExtension(FMenuBuilder& Builder)
{
	Builder.AddMenuEntry(FGraphAndBlueprintCommands::Get().OpenPluginWindow);
}

void FGraphAndBlueprintModule::AddToolbarExtension(FToolBarBuilder& Builder)
{
	Builder.AddToolBarButton(FGraphAndBlueprintCommands::Get().OpenPluginWindow);
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FGraphAndBlueprintModule, GraphAndBlueprint)