#include "DxLib.h"

#define PI 3.141592653

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
		//DrawGraph(x/2, 200, GrHandle00, TRUE);//�������Ƀ��[�h�������\��
		//DrawGraph(x, 50, GrHandle01, TRUE);//�������Ƀ��[�h�������\��

		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);//�f�t�H���g
		DrawRotaGraph(x / 2, 200, 2.0, PI / 4, GrHandle00, TRUE);

		SetDrawBlendMode(DX_BLENDMODE_ALPHA, 128);//����
		DrawRotaGraph(x, 200, 1.0, 0.0, GrHandle00, TRUE);

		SetDrawBlendMode(DX_BLENDMODE_ADD, 255);//���Z
		DrawRotaGraph(x, 300, 1.0, 0.0, GrHandle00, TRUE);
		


		//�v�Z
		x++;
	}

	//WaitKey();//�L�[���͑҂�
	DxLib_End();//DX���C�u�����I������
	return 0;
}