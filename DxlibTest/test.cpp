#include "DxLib.h"

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	ChangeWindowMode(TRUE), DxLib_Init(), SetDrawScreen(DX_SCREEN_BACK);//�E�B���h�E���[�h�ύX�Ə������Ɨ���ʐݒ�

	int GrHandle = LoadGraph("img/profile3D.jpg");//�������փ��[�h


	int x = 50;

	while (ScreenFlip()==0 && ProcessMessage()==0 && ClearDrawScreen() == 0)
	{
		//Esc�������ꂽ�烋�[�v�𔲂���
		if (CheckHitKey(KEY_INPUT_ESCAPE) == 1)
		{
			break;
		}

		//���G��
		DrawGraph(x, 50, GrHandle, TRUE);//�������Ƀ��[�h�������\��
		DrawGraph(x/2, 100, GrHandle, TRUE);//�������Ƀ��[�h�������\��
		DrawGraph(x/4, 150, GrHandle, TRUE);//�������Ƀ��[�h�������\��

		//�v�Z
		x++;
	}

	//WaitKey();//�L�[���͑҂�
	DxLib_End();//DX���C�u�����I������
	return 0;
}