#include "DxLib.h"

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	ChangeWindowMode(TRUE), DxLib_Init(), SetDrawScreen(DX_SCREEN_BACK);//�E�B���h�E���[�h�ύX�Ə������Ɨ���ʐݒ�

	int GrHandle00 = LoadGraph("img/01.png");//�������փ��[�h
	int GrHandle01 = LoadGraph("img/02.png");


	int x = 50;

	while (ScreenFlip()==0 && ProcessMessage()==0 && ClearDrawScreen() == 0)
	{
		//Esc�������ꂽ�烋�[�v�𔲂���
		if (CheckHitKey(KEY_INPUT_ESCAPE) == 1)
		{
			break;
		}

		//���G��
		DrawGraph(x/2, 100, GrHandle00, TRUE);//�������Ƀ��[�h�������\��
		DrawGraph(x, 50, GrHandle01, TRUE);//�������Ƀ��[�h�������\��


		//�v�Z
		x++;
	}

	//WaitKey();//�L�[���͑҂�
	DxLib_End();//DX���C�u�����I������
	return 0;
}