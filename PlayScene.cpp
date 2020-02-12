#include "PlayScene.h"
#include "Tank.h"
#include "Ground.h"
#include "Canon.h"


//�R���X�g���N�^
PlayScene::PlayScene(GameObject * parent)
	: GameObject(parent, "PlayScene")
{
}

//������
void PlayScene::Initialize()
{
	Instantiate<Tank>(this);
	Instantiate<Ground>(this);
	Instantiate<Canon>(this);
}

//�X�V
void PlayScene::Update()
{
}

//�`��
void PlayScene::Draw()
{
}

//�J��
void PlayScene::Release()
{
}