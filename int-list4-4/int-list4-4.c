//���͂��ꂽ�����񂓂̑Ó������`�F�b�N

int check(const char s[])
{
	if (strlen(s) != 4)	//������̒������S�łȂ�
		return 1;
	for (int i = 0; i < 4; i++) {
		if (!isdigit(s[i]))
			return 2;	//�����ȊO�̕������܂܂�Ă���
		for (int j = 0; j < i; j++)
			if (s[i] == s[j])
				return 3;	//����̐������܂܂�Ă���
	}

	return 0;	//������͑Ó�
}