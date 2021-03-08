// Fill out your copyright notice in the Description page of Project Settings.


#include "InputEventUserWidgetBase.h"


bool UInputEventUserWidgetBase::Initialize()
{
	bool result = UUserWidget::Initialize();
	if (!result) { return false; }
	
	//virtual bool Initialize();
	FOnInputAction _DelegateUp;
	_DelegateUp.BindUFunction(this, "OnClickUp");
	ListenForInputAction("Up", EInputEvent::IE_Released, false, _DelegateUp);

	FOnInputAction _DelegateDown;
	_DelegateDown.BindUFunction(this, "OnClickDown");
	ListenForInputAction("Down", EInputEvent::IE_Released, false, _DelegateDown);

	FOnInputAction _DelegateRight;
	_DelegateRight.BindUFunction(this, "OnClickRight");
	ListenForInputAction("Right", EInputEvent::IE_Released, false, _DelegateRight);

	FOnInputAction _DelegateLeft;
	_DelegateLeft.BindUFunction(this, "OnClickUpLeft");
	ListenForInputAction("Left", EInputEvent::IE_Released, false, _DelegateLeft);

	FOnInputAction _DelegateConfirm;
	_DelegateConfirm.BindUFunction(this, "OnClickConfirm");
	ListenForInputAction("Confirm", EInputEvent::IE_Released, false, _DelegateConfirm);

	FOnInputAction _DelegateCancel;
	_DelegateCancel.BindUFunction(this, "OnClickCancel");
	ListenForInputAction("Cancel", EInputEvent::IE_Released, false, _DelegateCancel);
	return true;
}
