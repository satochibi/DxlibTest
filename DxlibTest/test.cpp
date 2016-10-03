#include "DxLib.h"

#define PI 3.141592653


int Key[256];

int gpUpdateKey() {
	char tmpKey[256];
	GetHitKeyStateAll(tmpKey);
	for (int i = 0; i < 256; i++)
	{
		if (tmpKey[i] != 0)
		{
			Key[i]++;
		}
		else {
			Key[i] = 0;
		}
	}
	return 0;
}


int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	ChangeWindowMode(TRUE), DxLib_Init(), SetDrawScreen(DX_SCREEN_BACK);//�E�B���h�E���[�h�ύX�Ə������Ɨ���ʐݒ�

	int GrHandle00 = LoadGraph("img/01.png");//�������փ��[�h
	int GrHandle01 = LoadGraph("img/02.png");
	int image[16];
	LoadDivGraph("img/char.png", 16, 4, 4, 32, 32, image);//�摜�������[�h

	int SHandle = LoadSoundMem("snd/00.wav");

	int flame = 0;
	int x = 50;
	int y = 10;

	while (ScreenFlip()==0 && ProcessMessage()==0 && ClearDrawScreen() == 0 && gpUpdateKey() == 0)
	{
		//Esc�������ꂽ�烋�[�v�𔲂���
		if (Key[KEY_INPUT_ESCAPE] == 1)
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

		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);//�f�t�H���g

		
		int Col = GetColor(255, 255, 255);
		DrawFormatString(x, y, Col, "Point[%d, %d]", x, y);

		DrawFormatString(100, 100, Col, "%d", GetRand(4));//���� seed�͎����ŗ^������̂ōl�����Ȃ��Ă悢
		DrawFormatString(100, 150, Col, "flame: %d time:%.3f", flame, flame/60.0f);//���� seed�͎����ŗ^������̂ōl�����Ȃ��Ă悢



		if (flame % (60*5) == 0)
		{
			//PlaySoundMem(SHandle, DX_PLAYTYPE_BACK);//�Đ�
		}

		if (Key[KEY_INPUT_RIGHT] == 1)
		{
			x += 50;
		}


		DrawGraph(400, 400, image[flame%16], TRUE);

		//�v�Z
		//x++;
		y++;
		flame++;
	}

	//WaitKey();//�L�[���͑҂�
	DxLib_End();//DX���C�u�����I������
	return 0;
}