#pragma once

#include "../StandardInclude.hpp"
#include "../EntityInclude.hpp"
#include "../HelperInclude.hpp"

class MenuItemStyle
{
private:
	int _Color;
	bool _IsFill;
	int _TextColor;

public:
	MenuItemStyle() { }

	MenuItemStyle(int color, bool isFill, int textColor)
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

class MenuItem
{
private:
	Rect _Box;
	string _Text;
	Point _TextLocation;
	int _FontHandle;
	MenuItemStyle _NormalStyle;
	MenuItemStyle _HoverStyle;

public:
	MenuItem() { }

	// 新しいインスタンスを初期化します
	MenuItem(Rect box, string text, Point textLocation, int fontHandle, MenuItemStyle normalStyle, MenuItemStyle hoverStyle)
	{
		_Box = box;
		_Text = text;
		_TextLocation = textLocation;
		_FontHandle = fontHandle;
		_NormalStyle = normalStyle;
		_HoverStyle = hoverStyle;
	}

	// 描画します
	void Draw()
	{
		MenuItemStyle style;

		if (!VerifyOnMouse())
			style = _NormalStyle;
		else
			style = _HoverStyle;

		SetDrawBlendMode(DX_BLENDMODE_ALPHA, (int)(255 * 0.7));
		_Box.Draw(style.Color(), style.IsFill());
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

		DrawStringToHandle(_TextLocation.GetX(), _TextLocation.GetY(), _Text.c_str(), style.TextColor(), _FontHandle);
	}

	// 項目上にマウスポインタがあるかどうかを検証します
	bool VerifyOnMouse()
	{
		auto mp = InputHelper::GetInstance().MousePos;
		auto p1 = _Box.GetLocationLeftTop();
		auto p2 = _Box.GetLocationRightBottom();

		return mp >= p1 && mp <= p2;
	}

	// メニュー項目を構築します
	static MenuItem BuildMenuItem(Point centerPosition, Size boxSize, const char *text, int fontHandle, MenuItemStyle normalStyle, MenuItemStyle hoverStyle)
	{
		auto rect = Rect(centerPosition - boxSize.GetWidthHeightAsPoint() / 2, boxSize);
		auto textSize = Size(GetDrawStringWidthToHandle(text, strlen(text), fontHandle), 25);
		auto textLocation = centerPosition - textSize.GetWidthHeightAsPoint() / 2;

		return MenuItem(rect, text, textLocation, fontHandle, normalStyle, hoverStyle);
	}
};