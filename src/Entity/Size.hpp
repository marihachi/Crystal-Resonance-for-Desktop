// �T�C�Y��\���܂�
class Size
{
private:
	int Width;
	int Height;

public:
	Size();

	// �V�����C���X�^���X�����������܂�
	Size(int width, int height)
	{
		Width = width;
		Height = height;
	}

	Size operator * (Size& a)
	{
		return Size(Width * a.GetWidth(), Height * a.GetHeight());
	}

	Size operator / (Size& a)
	{
		return Size(Width / a.GetWidth(), Height / a.GetHeight());
	}

	Size operator * (int a)
	{
		return Size(Width * a, Height * a);
	}

	Size operator / (int a)
	{
		return Size(Width / a, Height / a);
	}

	operator Point()
	{
		return Point(Width, Height);
	}

	// �����擾���܂�
	int GetWidth()
	{
		return Width;
	}

	// ������ݒ肵�܂�
	int GetHeight()
	{
		return Height;
	}

	// ����ݒ肵�܂�
	void SetWidth(int value)
	{
		Width = value;
	}

	// ������ݒ肵�܂�
	void SetHeight(int value)
	{
		Height = value;
	}


	// ���ɒl�����Z���܂�
	void AddWidth(int value)
	{
		Width += value;
	}

	// �����ɒl�����Z���܂�
	void AddHeight(int value)
	{
		Height += value;
	}
};