#pragma once
#include "DxLib.h"
#include"map.h"

/// <summary>
/// �v���C���[�N���X
/// </summary>
class Player final
{
public:
	Player();				// �R���X�g���N�^.
	~Player();				// �f�X�g���N�^.

	void Update();			// �X�V.
	void Draw();			// �`��.

	// ���f���n���h���̎擾.
	int GetModelHandle() const { return modelHandle; }

	const VECTOR& GetPos() const { return pos; }
	const VECTOR& GetDir() const { return dir; }

private:
	const float CaupsuleHigh = 0.3f;
	const float CapusuleLow = 0.1f;
	VECTOR CapsulePos1, CapsulePos2;//�����蔻��p�̃J�v�Z��
	MV1_COLL_RESULT_POLY_DIM HitPolyDim;
	int		modelHandle;	// ���f���n���h��.
	float TotalTime, PlayTime;
	int AttachIndex;
	float AnimTime;
	VECTOR	pos;			// �|�W�V����.
	VECTOR	velocity;		// �ړ���.
	VECTOR	dir;			// ��]����.
	// �ÓI�萔.
	static const float Speed;
	static const float Scale;
};
