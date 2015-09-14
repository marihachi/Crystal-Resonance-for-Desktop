#pragma once

#include "../StandardInclude.hpp"
#include "../EntityInclude.hpp"
#include "../HelperInclude.hpp"

// �{�^���̃X�^�C����\���܂�
class ButtonStyle
{
private:
	int _Color;
	bool _IsFill;
	int _TextColor;

public:
	ButtonStyle() { }

	// �V�����C���X�^���X�����������܂�
	ButtonStyle(int color, bool isFill, int textColor)
	{
		_Color = color;
		_IsFill = isFill;
		_TextColor = textColor;
	}

	int Color()
	{
		return _Color;
	}

	bool IsFill()
	{
		return _IsFill;
	}

	int TextColor()
	{
		return _TextColor;
	}
};

// �l�p�`�ƕ����񂩂�\�������{�^����\���܂�
class Button
{
private:
	Rect _Box;
	string _Text;
	Point _TextLocation;
	int _FontHandle;
	ButtonStyle _NormalStyle;
	ButtonStyle _HoverStyle;

public:
	Button() { }

	// �V�����C���X�^���X�����������܂�
	Button(Rect box, string text, Point textLocation, int fontHandle, ButtonStyle normalStyle, ButtonStyle hoverStyle)
	{
		_Box = box;
		_Text = text;
		_TextLocation = textLocation;
		_FontHandle = fontHandle;
		_NormalStyle = normalStyle;
		_HoverStyle = hoverStyle;
	}

	// �{�^����`�悵�܂�
	void Draw()
	{
		ButtonStyle style;

		if (!IsOnMouse())
			style = _NormalStyle;
		else
			style = _HoverStyle;

		SetDrawBlendMode(DX_BLENDMODE_ALPHA, (int)(255 * 0.7));
		_Box.Draw(style.Color(), style.IsFill());
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

		DrawStringToHandle(_TextLocation.X(), _TextLocation.Y(), _Text.c_str(), style.TextColor(), _FontHandle);
	}

	// ���ڏ�Ƀ}�E�X�|�C���^�����邩�ǂ��������؂��܂�
	bool IsOnMouse()
	{
		auto mp = InputHelper::GetInstance().MousePos;
		auto p1 = _Box.LocationLeftTop();
		auto p2 = _Box.LocationRightBottom();

		return mp >= p1 && mp <= p2;
	}

	// �{�^�����\�z���ăC���X�^���X�𐶐����܂�
	static Button BuildButton(Point centerPosition, Size boxSize, const char *text, int fontHandle, ButtonStyle normalStyle, ButtonStyle hoverStyle)
	{
		auto rect = Rect(centerPosition - boxSize.GetWidthHeightAsPoint() / 2, boxSize);
		auto textSize = Size(GetDrawStringWidthToHandle(text, strlen(text), fontHandle), 25);
		auto textLocation = centerPosition - textSize.GetWidthHeightAsPoint() / 2;

		return Button(rect, text, textLocation, fontHandle, normalStyle, hoverStyle);
	}
};