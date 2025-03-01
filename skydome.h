#pragma once
#include <vector>
#include<DxLib.h>

class Skydome
{
public:
	Skydome();
	~Skydome();
	void SkydomeUpdate();
	void SkydomeDraw();
private:
	int SkydomeModel;
	VECTOR pos;
	VECTOR	velocity;		// 移動力.
	VECTOR	dir;			// 回転方向.

	// 静的定数.
	static const float Speed;
	static const float Scale;

};

