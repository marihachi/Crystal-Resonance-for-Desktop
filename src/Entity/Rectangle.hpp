#include "../StandardInclude.hpp"
#include "../EntityInclude.hpp"

// ��`��\���܂�
class Rectangle
{
private:
	Size _Size;
	Point _Location;

public:
	// �V�����C���X�^���X�����������܂�
	Rectangle(Point location, Size size)
	{
		_Location = location;
		_Size = size;
	}

	// ��`�̍���̍��W���擾���܂�
	Point GetLocationLeftTop()
	{
		return _Location;
	}

	// ��`�̉E���̍��W���擾���܂�
	Point GetLocationRightBottom()
	{
		return Point(
			_Location.GetX() + _Size.GetWidth(),
			_Location.GetY() + _Size.GetHeight());
	}

	// ��`�̃T�C�Y���擾���܂�
	Size GetSize()
	{
		return _Size;
	}

	// ��`��`�悵�܂�
	void Draw(unsigned int color, bool fillFlag)
	{
		Point location1 = GetLocationLeftTop();
		Point location2 = GetLocationRightBottom();

		DrawBox(
			location1.GetX(), location1.GetY(),
			location2.GetX(), location2.GetY(),
			color,
			fillFlag ? 1 : 0);
	}
};