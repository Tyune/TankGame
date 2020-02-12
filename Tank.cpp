#include "Tank.h"
#include "Engine/Model.h"
#include "Engine/Input.h"
#include "Engine/Camera.h"
#include "Ground.h"

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
	Move();

	FitHeightToGround();
}

//高さを地面に合わせる
void Tank::FitHeightToGround()
{
	//地面に添わせる
	Ground* pGround = (Ground*)FindObject("Ground");    //ステージオブジェクトを探す
	int hGroundModel = pGround->GetModelHandle();    //モデル番号を取得

	RayCastData data;
	data.start = transform_.position_;   //レイの発射位置
	data.start.vecY = 0.0f,   //レイの発射位置

		data.dir = XMVectorSet(0, -1, 0, 0); //レイの方向
	Model::RayCast(hGroundModel, &data); //レイを発射

										 //レイが当たったら
	if (data.hit)
	{
		//その分位置を下げる
		transform_.position_.vecY = -data.dist;
	}
}

//移動処理
void Tank::Move() 
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

	XMVECTOR camVec = { 0.0f,8.0f,-10.0f };
	XMMatrixRotationY(XMConvertToRadians(transform_.rotate_.vecY));
	camVec = XMVector3TransformCoord(camVec, mY);  //ベクトルを行列に適応させる
	Camera::SetPosition(transform_.position_ + camVec);

	
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
