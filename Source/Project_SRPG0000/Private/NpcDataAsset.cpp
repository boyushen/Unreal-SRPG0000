// Fill out your copyright notice in the Description page of Project Settings.


#include "NpcDataAsset.h"

#if WITH_EDITOR
#include "Misc/MessageDialog.h"
#include "UObject/Package.h"
#include "EditorReimportHandler.h"
#include "FileHelpers.h"
#endif

#define LOCTEXT_NAMESPACE "Inport"

/*
* TODO:
* �l�b�g���Q�Ƃ��Ď����I��DATATable into DataAsset������ł����A���W���[����ǉ����Ȃ��Ƃ����Ȃ��̂ŁA
* ���΂炭�f�[�^��ϊ������ɂ��܂�
*/
void UNpcDataAsset::Build()
{
#if WITH_EDITORONLY_DATA

	// �f�[�^�e�[�u���̐ݒ�`�F�b�N
	if (DataTable == nullptr)
	{
		const FText TitleText = LOCTEXT("Title", "WarningMassege");
		FMessageDialog::Open(EAppMsgType::Ok, LOCTEXT("Message", "DataTable is Null !!"), &TitleText);
		return;
	}

	// �f�[�^�e�[�u���̌^�`�F�b�N
	if (!DataTable->GetRowStruct()->IsChildOf(FNpcScriptDataTableRow::StaticStruct()))
	{
		const FText TitleText = LOCTEXT("Title", "WarningMassege");
		FMessageDialog::Open(EAppMsgType::Ok, LOCTEXT("Message", "DataTable type does not match !!"), &TitleText);
		return;
	}

	//TArray<UPackage*> PackagesToSave;

	// �f�[�^�e�[�u�������C���|�[�g
	//if (FReimportManager::Instance()->Reimport(DataTable))
	//{
		// ���C���|�[�g�ɐ��������f�[�^�e�[�u����ۑ��Ώۂɒǉ�
		//PackagesToSave.Add(DataTable->GetOutermost());
	//}

	scriptItems.Empty();

	// �f�[�^�e�[�u���̍s�̗v�f��z��Ŏ擾
	TArray<FName> RowNames = DataTable->GetRowNames();
	// �s�̐��������[�v
	for (auto RowName : RowNames)
	{
		// �P�s���̍\���̂��擾
		FNpcScriptDataTableRow* TableRow = DataTable->FindRow< FNpcScriptDataTableRow >(RowName, FString());

		// ���ۂɃQ�[����Ŏg���₷���悤�Ƀf�[�^�����H����
		FNpcScriptDataTableRow TableData;
		//CharacterData.RowName = RowName.ToString();
		TableData.SId = TableRow->SId;
		TableData.SituationId = TableRow->SituationId;
		TableData.Conversation = TableRow->Conversation;

		// Map�ɒǉ�����
		scriptItems.Add(TableData);
	}

	// �f�[�^�A�Z�b�g�ɕҏW�t���O��ǉ�
	MarkPackageDirty();

	// �f�[�^�A�Z�b�g��ۑ��Ώۂɒǉ�
	//PackagesToSave.Add(GetOutermost());

	// �֘A�A�Z�b�g��S�ĕۑ��iSourceControl�g�p���̓`�F�b�N�A�E�g���邩���b�Z�[�W�E�B���h�E���o���j
	// �t�@�C���ҏW�t���O�iDirty)���t���Ă���݂̂̂�ۑ��Ώۂɂ������̂ő�������true
	// �ۑ�����ۂɊm�F�̃��b�Z�[�W�E�B���h�E���o���Ȃ��ꍇ�͑�������false�ɂ���
	//FEditorFileUtils::PromptForCheckoutAndSave(PackagesToSave, true, true);

#endif
}
#undef LOCTEXT_NAMESPACE

