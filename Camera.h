#pragma once

class Player;

/// <summary>
/// �J����
/// </summary>
class Camera
{
public:
	Camera();							// �R���X�g���N�^.
	~Camera();							// �f�X�g���N�^.

	void Update(const VECTOR playerpos);	// �X�V.

	// �|�W�V������getter/setter.
	const VECTOR& GetPos() const { return pos; }

private:
	VECTOR	pos;			// �|�W�V����.
};
