#pragma once
#include "DxLib.h"
#include"map.h"

/// <summary>
/// プレイヤークラス
/// </summary>
class Player final
{
public:
	Player();				// コンストラクタ.
	~Player();				// デストラクタ.

	void Update();			// 更新.
	void Draw();			// 描画.

	// モデルハンドルの取得.
	int GetModelHandle() const { return modelHandle; }

	const VECTOR& GetPos() const { return pos; }
	const VECTOR& GetDir() const { return dir; }

private:
	const float CaupsuleHigh = 0.3f;
	const float CapusuleLow = 0.1f;
	VECTOR CapsulePos1, CapsulePos2;//当たり判定用のカプセル
	MV1_COLL_RESULT_POLY_DIM HitPolyDim;
	int		modelHandle;	// モデルハンドル.
	float TotalTime, PlayTime;
	int AttachIndex;
	float AnimTime;
	VECTOR	pos;			// ポジション.
	VECTOR	velocity;		// 移動力.
	VECTOR	dir;			// 回転方向.
	// 静的定数.
	static const float Speed;
	static const float Scale;
};
