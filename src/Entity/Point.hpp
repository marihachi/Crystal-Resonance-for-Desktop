// ���W��\���܂�
class Point
{
private:
	int X;
	int Y;

public:
	Point();

	// �V�����C���X�^���X�����������܂�
	Point(int x, int y)
	{
		X = x;
		Y = y;
	}

	Point operator + (Point& a)
	{
		return Point(X + a.GetX(), Y + a.GetY());
	}

	Point operator - (Point& a)
	{
		return Point(X - a.GetX(), Y - a.GetY());
	}

	Point operator += (Point& a)
	{
		X += a.GetX();
		Y += a.GetY();
		return *this;
	}

	Point operator -= (Point& a)
	{
		X -= a.GetX();
		Y -= a.GetY();
		return *this;
	}

	// X���W���擾���܂�
	int GetX()
	{
		return X;
	}

	// X���W��ݒ肵�܂�
	void SetX(int value)
	{
		X = value;
	}

	// Y���W���擾���܂�
	int GetY()
	{
		return Y;
	}
	// Y���W��ݒ肵�܂�
	void SetY(int value)
	{
		Y = value;
	}
};