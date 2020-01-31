#include "Tank.h"
#include "Engine/Model.h"
#include "Engine/Input.h"
#include "Engine/Camera.h"

//コンストラクタ
Tank::Tank(GameObject * parent)
	: GameObject(parent, "Tank"), hModel_(-1)
{
}

//デストラクタ
Tank::~Tank()
{
}

//初期化
void Tank::Initialize()
{
	//モデルデータのロード
	hModel_ = Model::Load("TankBody.fbx");
	assert(hModel_ >= 0);
}

//更新
void Tank::Update()
{
	XMVECTOR move = { 0.0f, 0.0f, 0.1f, 0.0f };

	//回転
	XMMATRIX  mY;
	mY = XMMatrixRotationY(XMConvertToRadians(transform_.rotate_.vecY));   //軸で30°回転させる行列
	move = XMVector3TransformCoord(move, mY);  //ベクトルを行列に適応させる


	//前進
	if (Input::IsKey(DIK_W))
	{
		transform_.position_ += move;
	}

	//回転
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

//描画
void Tank::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

//開放
void Tank::Release()
{
}
