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
	int		mapHandle;	// ���f���n���h��.
	VECTOR	pos;			// �|�W�V����.

};

