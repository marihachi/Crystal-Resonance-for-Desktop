#pragma once

#include "../StandardInclude.hpp"
#include "../EntityInclude.hpp"

class MenuItem
{
public:
	// ��`�ł�
	Rect Box;

	// ������ł�
	string Text;

	// ������̈ʒu�ł�
	Point TextLocation;

	MenuItem() { }

	// �V�����C���X�^���X�����������܂�
	MenuItem(Rect box, string text, Point textRelativeLocation)
	{
		Box = box;
		Text = text;
		TextLocation = textRelativeLocation;
	}

	void Draw(int boxColor, int textColor, int fontHandle)
	{
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, (int)(255 * 0.7));
		Box.Draw(boxColor, false);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

		DrawStringToHandle(TextLocation.GetX(), TextLocation.GetY(), Text.c_str(), textColor, fontHandle);
	}

	// ���j���[���ڂ��\�z���܂�
	static MenuItem BuildMenuItem(Point centerPosition, Size boxSize, const char *text, int fontHandle)
	{
		Rect rect(centerPosition - boxSize.GetWidthHeightAsPoint() / 2, boxSize);
		Size textSize(GetDrawStringWidthToHandle(text, strlen(text), fontHandle), 25);
		auto textLocation = centerPosition - textSize.GetWidthHeightAsPoint() / 2;
		return MenuItem(rect, text, textLocation);
	}
};