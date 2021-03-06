#pragma once
#include "Engine/GameObject.h"


//Groundシーンを管理するクラス
class Ground : public GameObject
{
	int hModel_;    //モデル番号
public:
	//コンストラクタ
	//引数：parent  親オブジェクト（SceneManager）
	Ground(GameObject* parent);

	//初期化
	void Initialize() override;

	//更新
	void Update() override;

	//描画
	void Draw() override;

	//開放
	void Release() override;

	int GetModelHandle() { return hModel_; }
	//これで、地面クラスのGetModelHandle関数を呼べば、
	//hModel_に入っているモデル番号が返ってくる。


};