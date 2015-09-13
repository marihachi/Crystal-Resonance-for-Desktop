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

	Point operator * (Point& a)
	{
		return Point(X * a.GetX(), Y * a.GetY());
	}

	Point operator / (Point& a)
	{
		return Point(X / a.GetX(), Y / a.GetY());
	}

	Point operator * (int a)
	{
		return Point(X * a, Y * a);
	}

	Point operator / (int a)
	{
		return Point(X / a, Y / a);
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

	// Y���W���擾���܂�
	int GetY()
	{
		return Y;
	}

	// X���W��ݒ肵�܂�
	void SetX(int value)
	{
		X = value;
	}

	// Y���W��ݒ肵�܂�
	void SetY(int value)
	{
		Y = value;
	}

	// X���W�ɒl�����Z���܂�
	void AddX(int value)
	{
		X += value;
	}

	// Y���W�ɒl�����Z���܂�
	void AddY(int value)
	{
		Y += value;
	}
};