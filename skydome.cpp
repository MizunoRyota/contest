#include"skydome.h"

#include<DxLib.h>

Skydome::Skydome()
{
    // �R�c���f���̓ǂݍ���
    SkydomeModel = MV1LoadModel("data/model/Skydome/Sunny/Dome_X501.pmx");
    pos = VGet(0, 0, -50);
}

Skydome::~Skydome()
{
}

void Skydome::SkydomeUpdate()
{
    


}

void Skydome::SkydomeDraw()
{
    MV1SetPosition(SkydomeModel, pos);
    // �R�c���f���̕`��
    MV1DrawModel(SkydomeModel);
}