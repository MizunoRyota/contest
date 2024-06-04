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
	VECTOR	velocity;		// ˆÚ“®—Í.
	VECTOR	dir;			// ‰ñ“]•ûŒü.

	// Ã“I’è”.
	static const float Speed;
	static const float Scale;

};

