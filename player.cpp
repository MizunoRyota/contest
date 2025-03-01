#include "Player.h"
#include "DxLib.h"

// 静的定数
// 速度（1=1m、60fps固定として、時速10km）
// 10000m ÷ 時間 ÷ 分 ÷ 秒 ÷ フレーム
const float Player::Speed = static_cast<float>(10000.0 / 60.0 / 60.0 / 60.0);
const float Player::Scale = 0.002f;		// スケール

/// <summary>
/// コンストラクタ
/// </summary>
Player::Player()
	: modelHandle(-1)
{
	// ３Ｄモデルの読み込み
	modelHandle = MV1LoadModel("data/model/player/player.mv1");
	AttachIndex = MV1AttachAnim(modelHandle, 1, -1, FALSE);
	AnimTime = MV1GetAttachAnimTotalTime(modelHandle, AttachIndex);
	// アタッチしたアニメーションの総再生時間を取得する
	TotalTime = MV1GetAttachAnimTotalTime(modelHandle, AttachIndex);
	// 再生時間の初期化
	PlayTime = 0.0f;
	pos = VGet(0, 0, 0);
	velocity = VGet(0, 0, 0);
	dir = VGet(0, 0, 1);
}

/// <summary>
/// デストラクタ
/// </summary>
Player::~Player()
{
	// モデルのアンロード.
	MV1DeleteModel(modelHandle);
}

/// <summary>
/// 更新
/// </summary>
void Player::Update()
{
	// キー入力取得
	int Key = GetJoypadInputState(DX_INPUT_KEY_PAD1);

	// 再生時間を進める
	PlayTime += 1.0f;

	// 再生時間がアニメーションの総再生時間に達したら再生時間を０に戻す
	if (PlayTime >= TotalTime)
	{
		PlayTime = 0.0f;
	}

	// 単純に方向転換
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
		// 回転
		MV1SetRotationXYZ(modelHandle, VGet(0.0f, -90.0f, 0.0f));
	}
	else if (Key & PAD_INPUT_LEFT)
	{
		dir = VAdd(dir, VGet(-1, 0, 0));
		// 回転
		MV1SetRotationXYZ(modelHandle, VGet(0.0f, 90.0f, 0.0f));
	}

	// ゼロ除算避け
	if (VSquareSize(dir) > 0)
	{
		// 正規化
		dir = VNorm(dir);
	}

	// ポジションを更新.
	velocity = VScale(dir, Speed);
	pos = VAdd(pos, velocity);

	// 力をかけ終わったベロシティの方向にディレクションを調整.
	if (VSize(velocity) != 0)
	{
		dir = VNorm(velocity);
	}
	//printfDx("%f %f %f\n", dir.x, dir.y, dir.z);

	// 3Dモデルのスケール決定
	MV1SetScale(modelHandle, VGet(Scale, Scale, Scale));

	// ３Dモデルのポジション設定
	MV1SetPosition(modelHandle, pos);

	//カプセルのポジション設定
	CapsulePos1 = VGet(pos.x, pos.y+CapusuleLow, pos.z);
	CapsulePos2 = VGet(pos.x, pos.y+CaupsuleHigh, pos.z);
	


	//3dモデルのアニメーションのセット
	MV1SetAttachAnimTime(modelHandle, AttachIndex, PlayTime);

}

/// <summary>
/// 描画
/// </summary>
void Player::Draw()
{
	// ３Ｄモデルの描画
	MV1DrawModel(modelHandle);
	// カプセルの描画
	DrawCapsule3D(CapsulePos1, CapsulePos2, 0.1f, 4, GetColor(255, 255, 0), GetColor(255, 255, 255), FALSE);
}