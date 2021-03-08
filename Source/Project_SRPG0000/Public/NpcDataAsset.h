// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "Engine/DataAsset.h"
#include "Engine/SkeletalMesh.h"
#include "NpcDataAsset.generated.h"

/**
 *NPC普段頭に浮かんでいるの会話コレクション
 * SID:リスト用
 * SituationId：どんな状況のID
 * Conversation　会話内容
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
 *NPC使われているのデータ集合
 * 会話コレクションデーター元
 * avatarパーツ
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
	UPROPERTY(BlueprintReadOnly, EditAnywhere)
		class USkeletalMesh* hair;
	UPROPERTY(BlueprintReadOnly, EditAnywhere)
		class USkeletalMesh* glove;
	UPROPERTY(BlueprintReadOnly, EditAnywhere)
		class USkeletalMesh* shoe;
	UPROPERTY(BlueprintReadOnly, EditAnywhere)
		class USkeletalMesh* headGears;
	UPROPERTY(BlueprintReadOnly, EditAnywhere)
		class USkeletalMesh* shoulderPad;
	UPROPERTY(BlueprintReadOnly, EditAnywhere)
		class USkeletalMesh* belt;
	UPROPERTY(BlueprintReadOnly, EditAnywhere)
		class USkeletalMesh* face;
	UPROPERTY(BlueprintReadOnly, EditAnywhere)
		class USkeletalMesh* cloth;
	// 会話コレクション転換
	UFUNCTION(BlueprintCallable, meta = (CallInEditor = "true"))
		void BuildConversation();
};
