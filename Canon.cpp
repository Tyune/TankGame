#include "Canon.h"
#include "Engine/Model.h"

//�R���X�g���N�^
Canon::Canon(GameObject * parent)
	:GameObject(parent, "Canon"), hModel_(-1)
{
}



//������
void Canon ::Initialize()
{
	//���f���f�[�^�̃��[�h��ԏ㕔
	hModel_ = Model::Load("TankHead.fbx");
	assert(hModel_ >= 0);
}

//�X�V
void Canon::Update()
{
}

//�`��
void Canon::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

//�J��
void Canon::Release()
{
}