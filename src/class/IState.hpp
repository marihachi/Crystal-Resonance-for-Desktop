#pragma once

// �Q�[���̏�ʂ�\���܂�
class IState
{
public:
	virtual ~IState() {}
	virtual void Update() = 0;
	virtual void Draw() = 0;
};