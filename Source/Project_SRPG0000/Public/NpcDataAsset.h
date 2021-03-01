// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "Engine/DataAsset.h"
#include "NpcDataAsset.generated.h"

/**
 *
 */
USTRUCT(BlueprintType)
struct PROJECT_SRPG0000_API FNpcScriptDataTableRow : public FTableRowBase
{
	GENERATED_USTRUCT_BODY()
	UPROPERTY(BlueprintReadWrite,EditAnywhere)
		int SId;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		int SituationId;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		TArray<FString> Conversation;
};
/**
 *
 */
UCLASS(BlueprintType)
class PROJECT_SRPG0000_API UNpcDataAsset : public UDataAsset
{
	GENERATED_BODY()
public:
#if WITH_EDITORONLY_DATA
	UPROPERTY(BlueprintReadOnly, EditAnywhere)
		class UDataTable* DataTable;
#endif
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
		TArray<FNpcScriptDataTableRow> scriptItems;
	// データ作成用の関数
	UFUNCTION(BlueprintCallable, meta = (CallInEditor = "true"))
		void Build();
};
