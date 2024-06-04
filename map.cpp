#include<vector>
#include "Map.h"
#include "DxLib.h"
Map::Map()
{
    mapHandle = MV1LoadModel("data/model/map/stage.mv1");
    pos = VGet(0, -0.5, 0);
    // �RD���f���̃|�W�V�����ݒ�
    MV1SetPosition(mapHandle, pos);
    // ���f���S�̂̃R���W���������\�z
    MV1SetupCollInfo(mapHandle, -1, 8, 8, 8);
}

Map::~Map()
{
}

void Map::Update()
{
    
}

void Map::Draw()
{

    MV1DrawModel(mapHandle);

}