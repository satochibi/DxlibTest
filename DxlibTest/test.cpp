#include "DxLib.h"

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	ChangeWindowMode(TRUE), DxLib_Init(), SetDrawScreen(DX_SCREEN_BACK);//ウィンドウモード変更と初期化と裏画面設定

	int GrHandle = LoadGraph("img/profile3D.jpg");//メモリへロード


	int x = 50;

	while (ScreenFlip()==0 && ProcessMessage()==0 && ClearDrawScreen() == 0)
	{
		//Escが押されたらループを抜ける
		if (CheckHitKey(KEY_INPUT_ESCAPE) == 1)
		{
			break;
		}

		//裏絵画
		DrawGraph(x, 50, GrHandle, TRUE);//メモリにロードしたやつを表示
		DrawGraph(x/2, 100, GrHandle, TRUE);//メモリにロードしたやつを表示
		DrawGraph(x/4, 150, GrHandle, TRUE);//メモリにロードしたやつを表示

		//計算
		x++;
	}

	//WaitKey();//キー入力待ち
	DxLib_End();//DXライブラリ終了処理
	return 0;
}