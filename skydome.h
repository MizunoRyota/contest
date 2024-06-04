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
	VECTOR	velocity;		// �ړ���.
	VECTOR	dir;			// ��]����.

	// �ÓI�萔.
	static const float Speed;
	static const float Scale;

};

