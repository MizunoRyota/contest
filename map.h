#pragma once
#include <vector>
#include"DxLib.h"
class Map
{
public:
	Map();
	~Map();

	void Update();
	void Draw();

private:
	int		mapHandle;	// モデルハンドル.
	VECTOR	pos;			// ポジション.

};

