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
* ネットを参照して自動的にDATATable into DataAssetをするですが、モジュールを追加しないといけないので、
* しばらくデータを変換だけにします
*/
void UNpcDataAsset::Build()
{
#if WITH_EDITORONLY_DATA

	// データテーブルの設定チェック
	if (DataTable == nullptr)
	{
		const FText TitleText = LOCTEXT("Title", "WarningMassege");
		FMessageDialog::Open(EAppMsgType::Ok, LOCTEXT("Message", "DataTable is Null !!"), &TitleText);
		return;
	}

	// データテーブルの型チェック
	if (!DataTable->GetRowStruct()->IsChildOf(FNpcScriptDataTableRow::StaticStruct()))
	{
		const FText TitleText = LOCTEXT("Title", "WarningMassege");
		FMessageDialog::Open(EAppMsgType::Ok, LOCTEXT("Message", "DataTable type does not match !!"), &TitleText);
		return;
	}

	//TArray<UPackage*> PackagesToSave;

	// データテーブルをリインポート
	//if (FReimportManager::Instance()->Reimport(DataTable))
	//{
		// リインポートに成功したデータテーブルを保存対象に追加
		//PackagesToSave.Add(DataTable->GetOutermost());
	//}

	scriptItems.Empty();

	// データテーブルの行の要素を配列で取得
	TArray<FName> RowNames = DataTable->GetRowNames();
	// 行の数だけループ
	for (auto RowName : RowNames)
	{
		// １行分の構造体を取得
		FNpcScriptDataTableRow* TableRow = DataTable->FindRow< FNpcScriptDataTableRow >(RowName, FString());

		// 実際にゲーム上で使いやすいようにデータを加工する
		FNpcScriptDataTableRow TableData;
		//CharacterData.RowName = RowName.ToString();
		TableData.SId = TableRow->SId;
		TableData.SituationId = TableRow->SituationId;
		TableData.Conversation = TableRow->Conversation;

		// Mapに追加する
		scriptItems.Add(TableData);
	}

	// データアセットに編集フラグを追加
	MarkPackageDirty();

	// データアセットを保存対象に追加
	//PackagesToSave.Add(GetOutermost());

	// 関連アセットを全て保存（SourceControl使用時はチェックアウトするかメッセージウィンドウを出す）
	// ファイル編集フラグ（Dirty)が付いてるもののみを保存対象にしたいので第一引数はtrue
	// 保存する際に確認のメッセージウィンドウを出さない場合は第二引数をfalseにする
	//FEditorFileUtils::PromptForCheckoutAndSave(PackagesToSave, true, true);

#endif
}
#undef LOCTEXT_NAMESPACE

