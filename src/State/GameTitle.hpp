﻿#pragma once

#include "../StandardInclude.hpp"
#include "../EntityInclude.hpp"

#include "../StateInterface.hpp"

class GameTitle : public StateInterface
{
public: static GameTitle &GetInstance(void) { static auto instance = GameTitle(); return instance; }
private: GameTitle() { }

private:
	bool IsInitial = true;
	int logoHandle;

public:
	// 場面名を取得します
	string StateName()
	{
		return "Title";
	}

	// 更新(ターゲット時のみ)
	void Update()
	{
		if (IsInitial)
		{
			IsInitial = false;

			logoHandle = LoadGraph("Image/logo.png", 1);
		}
	}

	// 描画(常時)
	void Draw()
	{
		if (Core::GetInstance().GetNowStateName() == StateName())
		{
			int temp[2];
			GetGraphSize(logoHandle, &temp[0], &temp[1]);
			Point imageRightBottom = Point(temp[0], temp[1]);

			Point screenRightBottom = (Point)Core::GetInstance().ScreenSize;

			Point location = screenRightBottom / 2 - imageRightBottom / 2;
			location.AddY(-150);

			DrawGraph(location.GetX(), location.GetY(), logoHandle, 1);
		}
	}
};