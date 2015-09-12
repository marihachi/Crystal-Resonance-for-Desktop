#pragma once

#include "../StandardInclude.hpp"

#include "../Entity/Point.hpp"

static class InputHelper
{
public:
	// �L�[�{�[�h�̓��͎���
	static int KeyState[256];

	// �L�[�{�[�h�̓��͎��Ԃ�
	static void UpdateKeyInputTime()
	{
		char state[256];
		GetHitKeyStateAll(state);

		for (int i = 0; i < 256; i++)
		{
			if (state[i] == 1)
				KeyState[i]++;
			else
				KeyState[i] = 0;
		}
	}

	// 0: ���{�^��, 1: �E�{�^��, 2: ��]��
	static int MouseState[3];

	static Point MousePos;

	// �}�E�X�̓��͏��
	static void UpdateMouseInputTime()
	{
		int buf = GetMouseInput();

		if ((buf & MOUSE_INPUT_LEFT) != 0)
			MouseState[0]++;
		else
			MouseState[0] = 0;

		if ((buf & MOUSE_INPUT_RIGHT) != 0)
			MouseState[1]++;
		else
			MouseState[1] = 0;

		int temp[2];
		GetMousePoint(&temp[0], &temp[1]);
		MousePos = Point(temp[0], temp[1]);

		// �I�[�o�[�t���[�h�~����
		if (MouseState[2] > 2147483600 || MouseState[2] < -2147483600)
			MouseState[2] = (int)(MouseState[2] / fabs((float)MouseState[2]));

		// �t�����ɓ��������烊�Z�b�g�i�r���Ō�����ς����Ƃ��ɕK�v�Ȉړ��ʂ𓙂������邽�߁j
		auto wheelRotVol = GetMouseWheelRotVol();

		if ((MouseState[2] > 0 && wheelRotVol < 0) || (MouseState[2] < 0 && wheelRotVol > 0))
			MouseState[2] = 0;

		MouseState[2] += wheelRotVol;
	}
};