#pragma once

#include "../StandardInclude.hpp"
#include "../EntityInclude.hpp"

// ��`��\���܂�
class Rect
{
private:
	Size _Size;
	Point _Location;

public:
	Rect() { }

	// �V�����C���X�^���X�����������܂�
	Rect(Point location, Size size)
	{
		_Location = location;
		_Size = size;
	}

	// ��`�̍���̍��W���擾���܂�
	Point LocationLeftTop()
	{
		return _Location;
	}

	// ��`�̉E���̍��W���擾���܂�
	Point LocationRightBottom()
	{
		return Point(
			_Location.X() + _Size.Width(),
			_Location.Y() + _Size.Height());
	}

	// ��`�̃T�C�Y���擾���܂�
	Size Size()
	{
		return _Size;
	}

	// ��`��`�悵�܂�
	void Draw(unsigned int color, bool fillFlag)
	{
		Point location1 = LocationLeftTop();
		Point location2 = LocationRightBottom();

		DrawBox(
			location1.X(), location1.Y(),
			location2.X(), location2.Y(),
			color,
			fillFlag ? 1 : 0);
	}
};