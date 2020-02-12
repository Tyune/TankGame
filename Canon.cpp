#include "Canon.h"
#include "Engine/Model.h"

//コンストラクタ
Canon::Canon(GameObject * parent)
	:GameObject(parent, "Canon"), hModel_(-1)
{
}



//初期化
void Canon ::Initialize()
{
	//モデルデータのロード戦車上部
	hModel_ = Model::Load("TankHead.fbx");
	assert(hModel_ >= 0);
}

//更新
void Canon::Update()
{
}

//描画
void Canon::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

//開放
void Canon::Release()
{
}