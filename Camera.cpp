#include "DxLib.h"
#include <vector>
#include "Map.h"
#include "Player.h"
#include "Camera.h"

/// <summary>
/// コンストラクタ
/// </summary>
Camera::Camera()
{
	//奥行0.1～1000までをカメラの描画範囲とする
	SetCameraNearFar(0.1f, 1000.0f);

	pos = VGet(0, 0, 0);
}

/// <summary>
/// デストラクタ
/// </summary>
Camera::~Camera()
{
	// 処理なし.
}

/// <summary>
/// 更新
/// </summary>
void Camera::Update(const VECTOR playerpos)
{
    // TODO:z軸上で、プレイヤーから一定距離離れた状態でプレイヤーを常に見続けるよう位置調整
// カメラに位置を反映.
//pos = VGet(0, 20, playerpos.z-30);
    SetCameraPositionAndTarget_UpVecY(pos, playerpos);

    // lerpを使用して実装.
    // lerp(VECTOR a, VECTOR b, float t)は
    // answer = a + ((b-a) * t)
    // answer = start + ((end - start) * t)
    VECTOR   targetPos = VGet(playerpos.x, playerpos.y+0.1, playerpos.z -3);     // b 
    VECTOR   aimPos = VSub(targetPos, pos);              // (b-a)
    VECTOR   scalsepos = VScale(aimPos, 0.5);         // ((b-a) * t)
    pos = VAdd(pos, scalsepos);         // a + ((b-a) * t)
}