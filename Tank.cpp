#include "Tank.h"
#include "Engine/Model.h"
#include "Engine/Input.h"
#include "Engine/Camera.h"

//�R���X�g���N�^
Tank::Tank(GameObject * parent)
	: GameObject(parent, "Tank"), hModel_(-1)
{
}

//�f�X�g���N�^
Tank::~Tank()
{
}

//������
void Tank::Initialize()
{
	//���f���f�[�^�̃��[�h
	hModel_ = Model::Load("TankBody.fbx");
	assert(hModel_ >= 0);
}

//�X�V
void Tank::Update()
{
	XMVECTOR move = { 0.0f, 0.0f, 0.1f, 0.0f };

	//��]
	XMMATRIX  mY;
	mY = XMMatrixRotationY(XMConvertToRadians(transform_.rotate_.vecY));   //����30����]������s��
	move = XMVector3TransformCoord(move, mY);  //�x�N�g�����s��ɓK��������


	//�O�i
	if (Input::IsKey(DIK_W))
	{
		transform_.position_ += move;
	}

	//��]
	if (Input::IsKey(DIK_A))
	{
		transform_.rotate_.vecY -= 3.0f;
	}
	if (Input::IsKey(DIK_D))
	{
		transform_.rotate_.vecY += 3.0f;
	}
	Camera::SetTarget(transform_.position_);
}

//�`��
void Tank::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

//�J��
void Tank::Release()
{
}
