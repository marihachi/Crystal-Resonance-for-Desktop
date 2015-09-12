﻿#pragma once

#include "DxLib.h"
#include <string>

using namespace std;

class Core
{
public: static Core &GetInstance(void) { static Core instance; return instance; }
private: Core(void)
{
}

private:
	vector<IState*> StateList;
	string NowStateName;

public:
	// 場面を追加します
	void AddState(IState* state)
	{
		StateList.push_back(state);
	}

	// 現在の場面名を設定します
	void SetNowStateName(string nowStateName)
	{
		NowStateName = nowStateName;
	}

	// 現在の場面名を取得します
	string GetNowStateName()
	{
		return NowStateName;
	}

	// 対象場面のUpdateメソッドを呼び出します
	void UpdateTriger()
	{
		for (auto state : StateList)
			if (state->StateName() == NowStateName)
			{
				state->Update();
				return;
			}
		throw new exception("場面が見つかりませんでした。");
	}

	// 全ての場面のDrawメソッドを呼び出します
	void DrawTriger()
	{
		for (auto state : StateList)
			state->Draw();
	}

	// インスタンスを初期化します
	bool Initialize(string title, int sizeX, int sizeY, int backR, int backG, int backB)
	{
		SetMainWindowText((title + string(" - Initializing...")).c_str());

		SetGraphMode(sizeX, sizeY, 32);
		SetBackgroundColor(backR, backG, backB);
		ChangeWindowMode(true);

		if (DxLib_Init() == -1)
			return false;

		SetDrawScreen(DX_SCREEN_BACK);

		if (SetMainWindowText(title.c_str()) != 0)
			return false;

		return true;
	}

	// 毎フレーム呼び出す必要がある基本処理を呼び出します
	bool ProcessContext()
	{
		if (ScreenFlip() != 0)
			return false;

		if (ProcessMessage() != 0)
			return false;

		if (ClearDrawScreen() != 0)
			return false;

		return true;
	}



	// インスタンスを破棄します
	bool Finalize()
	{
		DxLib_End();
		return true;
	}
};