#pragma once
#include "Engine/GameObject.h"


//Tankシーンを管理するクラス
class Tank: public GameObject
{
	int hModel_;    //モデル番号

	//移動処理//引数なし//戻値なし
	void Move();
	//高さを地面に合わせる//引数なし//戻値なし
	void FitHeightToGround();
public:
	//コンストラクタ
	//引数：parent  親オブジェクト（SceneManager）
	Tank(GameObject* parent);

	//デストラクタ
	~Tank();

	//初期化
	void Initialize() override;

	//更新
	void Update() override;


	//描画
	void Draw() override;

	//開放
	void Release() override;
};