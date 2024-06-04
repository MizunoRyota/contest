#pragma once

class Player;

/// <summary>
/// カメラ
/// </summary>
class Camera
{
public:
	Camera();							// コンストラクタ.
	~Camera();							// デストラクタ.

	void Update(const VECTOR playerpos);	// 更新.

	// ポジションのgetter/setter.
	const VECTOR& GetPos() const { return pos; }

private:
	VECTOR	pos;			// ポジション.
};
