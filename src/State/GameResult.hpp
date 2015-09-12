﻿#pragma once

#include "../StandardInclude.hpp"

#include "../StateInterface.hpp"

class GameResult : public StateInterface
{
public: static GameResult &GetInstance(void) { static auto instance = GameResult(); return instance; }
private: GameResult() { }

public:
	// 場面名を取得します
	string StateName()
	{
		return "Result";
	}

	// 更新(ターゲット時のみ)
	void Update()
	{

	}

	// 描画(常時)
	void Draw()
	{
		if (Core::GetInstance().GetNowStateName() == StateName())
		{
			DrawString(0, 0, "Result", 0);
		}
	}
};