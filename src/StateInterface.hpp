﻿#pragma once

#include "StandardInclude.hpp"

// ゲームの場面を表すインターフェイスクラスです
class StateInterface
{
public:
	virtual ~StateInterface() {}

	// 場面名を取得します
	virtual string StateName() = 0;

	// 更新(ターゲット時のみ)
	virtual void Update() = 0;

	// 描画(常時)
	virtual void Draw() = 0;
};