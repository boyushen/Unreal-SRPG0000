// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "UIManagerInterface.generated.h"

/**
 * 
 */
UINTERFACE(Blueprintable)
class UUIManagerInterface : public UInterface
{
    GENERATED_BODY()
	
};
class IUIManagerInterface
{
    GENERATED_BODY()

    public:
        UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "UIManager")
        void OpenUI(FName uiName);
        UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "UIManager")
        void CloseUI(FName uiName, bool needDestoryUI);
        /** Add interface function declarations here */
};