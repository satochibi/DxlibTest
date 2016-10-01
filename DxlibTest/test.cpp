#include "DxLib.h"

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	ChangeWindowMode(TRUE);//ウィンドウモードに設定
	DxLib_Init();//DXライブラリ初期化処理
	SetDrawScreen(DX_SCREEN_BACK); //描画先を裏画面に設定

	int GrHandle = LoadGraph("img/profile3D.jpg");//メモリへロード


	int x = 50;

	while (TRUE)
	{
		
		//	ウインドウのメッセージを処理
		//もしxが押されたらループを抜ける
		if (ProcessMessage() != 0)
		{
			break;
		}
		


		//Escが押されたらループを抜ける
		if (CheckHitKey(KEY_INPUT_ESCAPE) == 1)
		{
			break;
		}


		x++;



		ClearDrawScreen();// 画面を消す
		DrawGraph(x, 50, GrHandle, TRUE);//メモリにロードしたやつを表示
		ScreenFlip(); //裏画面を表画面に反映

	}

	//WaitKey();//キー入力待ち
	DxLib_End();//DXライブラリ終了処理
	return 0;
}