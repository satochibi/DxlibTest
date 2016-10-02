#include "DxLib.h"

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	ChangeWindowMode(TRUE), DxLib_Init(), SetDrawScreen(DX_SCREEN_BACK);//ウィンドウモード変更と初期化と裏画面設定

	int GrHandle00 = LoadGraph("img/01.png");//メモリへロード
	int GrHandle01 = LoadGraph("img/02.png");


	int x = 50;

	while (ScreenFlip()==0 && ProcessMessage()==0 && ClearDrawScreen() == 0)
	{
		//Escが押されたらループを抜ける
		if (CheckHitKey(KEY_INPUT_ESCAPE) == 1)
		{
			break;
		}

		//裏絵画
		DrawGraph(x/2, 100, GrHandle00, TRUE);//メモリにロードしたやつを表示
		DrawGraph(x, 50, GrHandle01, TRUE);//メモリにロードしたやつを表示


		//計算
		x++;
	}

	//WaitKey();//キー入力待ち
	DxLib_End();//DXライブラリ終了処理
	return 0;
}