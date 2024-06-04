#include "DxLib.h"
#include <vector>
#include "Map.h"
#include "Player.h"
#include "Camera.h"

/// <summary>
/// �R���X�g���N�^
/// </summary>
Camera::Camera()
{
	//���s0.1�`1000�܂ł��J�����̕`��͈͂Ƃ���
	SetCameraNearFar(0.1f, 1000.0f);

	pos = VGet(0, 0, 0);
}

/// <summary>
/// �f�X�g���N�^
/// </summary>
Camera::~Camera()
{
	// �����Ȃ�.
}

/// <summary>
/// �X�V
/// </summary>
void Camera::Update(const VECTOR playerpos)
{
    // TODO:z����ŁA�v���C���[�����苗�����ꂽ��ԂŃv���C���[����Ɍ�������悤�ʒu����
// �J�����Ɉʒu�𔽉f.
//pos = VGet(0, 20, playerpos.z-30);
    SetCameraPositionAndTarget_UpVecY(pos, playerpos);

    // lerp���g�p���Ď���.
    // lerp(VECTOR a, VECTOR b, float t)��
    // answer = a + ((b-a) * t)
    // answer = start + ((end - start) * t)
    VECTOR   targetPos = VGet(playerpos.x, playerpos.y+0.1, playerpos.z -3);     // b 
    VECTOR   aimPos = VSub(targetPos, pos);              // (b-a)
    VECTOR   scalsepos = VScale(aimPos, 0.5);         // ((b-a) * t)
    pos = VAdd(pos, scalsepos);         // a + ((b-a) * t)
}