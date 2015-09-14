#pragma once

#include "StandardInclude.hpp"

// �X�V������\���C���^�[�t�F�C�X�N���X�ł�
class IUpdateable
{
public:
	virtual ~IUpdateable() { }

	// �X�V��
	virtual string UpdateId() = 0;

	// �X�V
	virtual void Update() = 0;
};