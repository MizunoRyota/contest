#include<vector>
#include "DxLib.h"
#include"skydome.h"
#include "Player.h"
#include "Map.h"
#include "Camera.h"

/// <summary>
/// ���C���֐�
/// </summary>
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	
	// �c�w���C�u��������������
	if (DxLib_Init() == -1)
	{
		return -1;	// �G���[���N�����璼���ɏI��
	}
	// ��ʃ��[�h�̃Z�b�g
	ChangeWindowMode(TRUE);
	SetGraphMode(1600, 900, 16);

	SetDrawScreen(DX_SCREEN_BACK);	// ����ʂ�`��Ώۂɂ���
	SetUseZBufferFlag(TRUE);		// �y�o�b�t�@���g�p����
	SetWriteZBufferFlag(TRUE);		// �y�o�b�t�@�ւ̏������݂��s��
	SetUseBackCulling(TRUE);		// �o�b�N�J�����O���s��

	// ����
	Camera* camera = new Camera();
	Player* player = new Player();
	Skydome* skydome = new Skydome();
	Map* map = new Map();


	// �G�X�P�[�v�L�[��������邩�E�C���h�E��������܂Ń��[�v
	LONGLONG frameTime = 0;
	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{
		frameTime = GetNowHiPerformanceCount();
		// �v���C���[����.
		player->Update();

		// TODO: �萔�Ȃ̂ł��������̈ʒu�Ɉړ�������
		// �}�b�v�`�b�v�̃T�C�Y
		map->Update();
		camera->Update(player->GetPos());

		// ��ʂ�����������
		ClearDrawScreen();

		// �`��
		skydome->SkydomeDraw();
		map->Draw();
		player->Draw();

		// �f�o�b�O�`��
		// XYZ��
		float lineSize = 300.0f;
		DrawLine3D(VGet(-lineSize, 0, 0), VGet(lineSize, 0, 0), GetColor(255, 0, 0));
		DrawLine3D(VGet(0, -lineSize, 0), VGet(0, lineSize, 0), GetColor(0, 255, 0));
		DrawLine3D(VGet(0, 0, -lineSize), VGet(0, 0, lineSize), GetColor(0, 0, 255));

		// ����ʂ̓��e��\��ʂɔ��f������
		ScreenFlip();

		// �G��60fps�Œ�
		while ((GetNowHiPerformanceCount() - frameTime) < 16667) {}
	}

	// ��n��
	delete(player);
	delete(camera);
	delete(map);

	// �c�w���C�u�����̌�n��
	DxLib_End();

	// �\�t�g�̏I��
	return 0;
}