#pragma once

#include "../StandardInclude.hpp"
#include "../EntityInclude.hpp"

#include "../StateInterface.hpp"

class GameMusicSelect : public StateInterface
{
public: static GameMusicSelect &GetInstance(void) { static auto instance = GameMusicSelect(); return instance; }
private: GameMusicSelect() { }

public:
	// ��ʖ����擾���܂�
	string StateName()
	{
		return "MusicSelect";
	}

	// �X�V(�^�[�Q�b�g���̂�)
	void Update()
	{

	}

	// �`��(�펞)
	void Draw(StateEventArgs e)
	{
		if (e.IsActive())
		{
			DrawString(0, 0, "MusicSelect", 0);
		}
	}
};