#include "DxLib.h"

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	ChangeWindowMode(TRUE);//�E�B���h�E���[�h�ɐݒ�
	DxLib_Init();//DX���C�u��������������
	SetDrawScreen(DX_SCREEN_BACK); //�`���𗠉�ʂɐݒ�

	int GrHandle = LoadGraph("img/profile3D.jpg");//�������փ��[�h


	int x = 50;

	while (TRUE)
	{
		
		//	�E�C���h�E�̃��b�Z�[�W������
		//����x�������ꂽ�烋�[�v�𔲂���
		if (ProcessMessage() != 0)
		{
			break;
		}
		


		//Esc�������ꂽ�烋�[�v�𔲂���
		if (CheckHitKey(KEY_INPUT_ESCAPE) == 1)
		{
			break;
		}


		x++;



		ClearDrawScreen();// ��ʂ�����
		DrawGraph(x, 50, GrHandle, TRUE);//�������Ƀ��[�h�������\��
		ScreenFlip(); //����ʂ�\��ʂɔ��f

	}

	//WaitKey();//�L�[���͑҂�
	DxLib_End();//DX���C�u�����I������
	return 0;
}