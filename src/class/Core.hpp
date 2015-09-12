#pragma once

#include "DxLib.h"
#include <string>

using namespace std;

class Core
{
public: static Core &GetInstance(void) { static Core instance; return instance; }
private: Core(void) { }

public:
	// �󋵂�\���܂��B
	enum State{
		None,
		Title,
		GameMain,
		Result,
		Setting
	};

	State StateNumber = State::None;

	// �C���X�^���X�����������܂�
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

		StateNumber = State::Title;

		return true;
	}

	// ���t���[���Ăяo���K�v�������{�������Ăяo���܂�
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

	// �C���X�^���X��j�����܂�
	bool Finalize()
	{
		DxLib_End();
		return true;
	}
};