//�q�b�g���u���[�̔���

void judge(const char s[], const int no[], int* hit, int* blow)
{
	*hit = *blow = 0;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (s[i] == '0' + no[j]) {	//��������v
				if (i == j)
					(*hit)++;		//�q�b�g�i�ʒu����v�j
				else
					(*blow)++;		//�u���[�i�ʒu���s��v�j
			}
		}
	}
}