//���قȂ�4�̐����̕��т𐶐����Ĕz��x�Ɋi�[

void make4digits(int x[])
{
	for (int i = 0; i < 4; i++) {
		int j, val;
		do {
			val = rand() % 10;	//0�`9�̗���
			for (j = 0; j < i; j++)	//���ɓ����Ă��邩
				if (val == x[j])
					break;
		} while (j < i);	//�d�����Ȃ��l��������܂ŌJ��Ԃ�
		x[i] = val;
	}
}