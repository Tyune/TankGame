#pragma once
#include "Engine/GameObject.h"


//Canon�V�[�����Ǘ�����N���X
class Canon : public GameObject
{
	int hModel_;    //���f���ԍ�
public:
	//�R���X�g���N�^
	//�����Fparent  �e�I�u�W�F�N�g�iSceneManager�j
	Canon(GameObject* parent);

	//������
	void Initialize() override;

	

	//�X�V
	void Update() override;

	//�`��
	void Draw() override;

	//�J��
	void Release() override;

	int GetModelHandle() { return hModel_; }
	//����ŁA�n�ʃN���X��GetModelHandle�֐����Ăׂ΁A
	//hModel_�ɓ����Ă��郂�f���ԍ����Ԃ��Ă���B


};