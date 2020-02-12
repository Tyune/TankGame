#include "Tank.h"
#include "Engine/Model.h"
#include "Engine/Input.h"
#include "Engine/Camera.h"
#include "Ground.h"

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
	Move();

	FitHeightToGround();
}

//������n�ʂɍ��킹��
void Tank::FitHeightToGround()
{
	//�n�ʂɓY�킹��
	Ground* pGround = (Ground*)FindObject("Ground");    //�X�e�[�W�I�u�W�F�N�g��T��
	int hGroundModel = pGround->GetModelHandle();    //���f���ԍ����擾

	RayCastData data;
	data.start = transform_.position_;   //���C�̔��ˈʒu
	data.start.vecY = 0.0f,   //���C�̔��ˈʒu

		data.dir = XMVectorSet(0, -1, 0, 0); //���C�̕���
	Model::RayCast(hGroundModel, &data); //���C�𔭎�

										 //���C������������
	if (data.hit)
	{
		//���̕��ʒu��������
		transform_.position_.vecY = -data.dist;
	}
}

//�ړ�����
void Tank::Move() 
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

	XMVECTOR camVec = { 0.0f,8.0f,-10.0f };
	XMMatrixRotationY(XMConvertToRadians(transform_.rotate_.vecY));
	camVec = XMVector3TransformCoord(camVec, mY);  //�x�N�g�����s��ɓK��������
	Camera::SetPosition(transform_.position_ + camVec);

	
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
