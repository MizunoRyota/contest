#include "Player.h"
#include "DxLib.h"

// �ÓI�萔
// ���x�i1=1m�A60fps�Œ�Ƃ��āA����10km�j
// 10000m �� ���� �� �� �� �b �� �t���[��
const float Player::Speed = static_cast<float>(10000.0 / 60.0 / 60.0 / 60.0);
const float Player::Scale = 0.002f;		// �X�P�[��

/// <summary>
/// �R���X�g���N�^
/// </summary>
Player::Player()
	: modelHandle(-1)
{
	// �R�c���f���̓ǂݍ���
	modelHandle = MV1LoadModel("data/model/player/player.mv1");
	AttachIndex = MV1AttachAnim(modelHandle, 1, -1, FALSE);
	AnimTime = MV1GetAttachAnimTotalTime(modelHandle, AttachIndex);
	// �A�^�b�`�����A�j���[�V�����̑��Đ����Ԃ��擾����
	TotalTime = MV1GetAttachAnimTotalTime(modelHandle, AttachIndex);
	// �Đ����Ԃ̏�����
	PlayTime = 0.0f;
	pos = VGet(0, 0, 0);
	velocity = VGet(0, 0, 0);
	dir = VGet(0, 0, 1);
}

/// <summary>
/// �f�X�g���N�^
/// </summary>
Player::~Player()
{
	// ���f���̃A�����[�h.
	MV1DeleteModel(modelHandle);
}

/// <summary>
/// �X�V
/// </summary>
void Player::Update()
{
	// �L�[���͎擾
	int Key = GetJoypadInputState(DX_INPUT_KEY_PAD1);

	// �Đ����Ԃ�i�߂�
	PlayTime += 1.0f;

	// �Đ����Ԃ��A�j���[�V�����̑��Đ����ԂɒB������Đ����Ԃ��O�ɖ߂�
	if (PlayTime >= TotalTime)
	{
		PlayTime = 0.0f;
	}

	// �P���ɕ����]��
	dir = VGet(0, 0, 0);
	if (Key & PAD_INPUT_UP)
	{
		dir = VAdd(dir, VGet(0, 1, 0));
	}
	else if (Key & PAD_INPUT_DOWN)
	{
		dir = VAdd(dir, VGet(0, -1, 0));
	}
	if (Key & PAD_INPUT_RIGHT)
	{
		dir = VAdd(dir, VGet(1, 0, 0));
		// ��]
		MV1SetRotationXYZ(modelHandle, VGet(0.0f, -90.0f, 0.0f));
	}
	else if (Key & PAD_INPUT_LEFT)
	{
		dir = VAdd(dir, VGet(-1, 0, 0));
		// ��]
		MV1SetRotationXYZ(modelHandle, VGet(0.0f, 90.0f, 0.0f));
	}

	// �[�����Z����
	if (VSquareSize(dir) > 0)
	{
		// ���K��
		dir = VNorm(dir);
	}

	// �|�W�V�������X�V.
	velocity = VScale(dir, Speed);
	pos = VAdd(pos, velocity);

	// �͂������I������x���V�e�B�̕����Ƀf�B���N�V�����𒲐�.
	if (VSize(velocity) != 0)
	{
		dir = VNorm(velocity);
	}
	//printfDx("%f %f %f\n", dir.x, dir.y, dir.z);

	// 3D���f���̃X�P�[������
	MV1SetScale(modelHandle, VGet(Scale, Scale, Scale));

	// �RD���f���̃|�W�V�����ݒ�
	MV1SetPosition(modelHandle, pos);

	//�J�v�Z���̃|�W�V�����ݒ�
	CapsulePos1 = VGet(pos.x, pos.y+CapusuleLow, pos.z);
	CapsulePos2 = VGet(pos.x, pos.y+CaupsuleHigh, pos.z);
	


	//3d���f���̃A�j���[�V�����̃Z�b�g
	MV1SetAttachAnimTime(modelHandle, AttachIndex, PlayTime);

}

/// <summary>
/// �`��
/// </summary>
void Player::Draw()
{
	// �R�c���f���̕`��
	MV1DrawModel(modelHandle);
	// �J�v�Z���̕`��
	DrawCapsule3D(CapsulePos1, CapsulePos2, 0.1f, 4, GetColor(255, 255, 0), GetColor(255, 255, 255), FALSE);
}