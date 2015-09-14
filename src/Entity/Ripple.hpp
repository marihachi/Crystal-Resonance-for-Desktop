#pragma once

#include "../StandardInclude.hpp"
#include "../EntityInclude.hpp"

// �g��
class Ripple
{
private:
	Point _Location;
	int _Radius;

public:
	// �V�����C���X�^���X�����������܂�
	Ripple(Point location, int radius = 0)
	{
		_Location = location;
		_Radius = radius;
	}

	int Radius()
	{
		return _Radius;
	}

	void AddRadius(int value)
	{
		_Radius += value;
	}

	void Draw()
	{
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, (int)(255 * 0.5));
		DrawCircle(_Location.X(), _Location.Y(), _Radius, 0xffffff, 0);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	}
};