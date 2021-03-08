// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "InputEventUserWidgetBase.generated.h"

/**
 * 
 */
UCLASS()
class PROJECT_SRPG0000_API UInputEventUserWidgetBase : public UUserWidget
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintImplementableEvent , Category = "Input")
		void OnClickUp();
	UFUNCTION(BlueprintImplementableEvent, Category = "Input")
		void OnClickDown();
	UFUNCTION(BlueprintImplementableEvent, Category = "Input")
		void OnClickRight();
	UFUNCTION(BlueprintImplementableEvent, Category = "Input")
		void OnClickLeft();
	UFUNCTION(BlueprintImplementableEvent, Category = "Input")
		void OnClickConfirm();
	UFUNCTION(BlueprintImplementableEvent, Category = "Input")
		void OnClickCancel();

	bool Initialize() override;
	bool RigisterInputAction();
	
};
