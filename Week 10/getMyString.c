// getMyString.c
#include<stdio.h>
#define MAX_CH 20

int getMyString(char buffer[], int limit);

int main(void) {
	char input_str[MAX_CH];
	int state; // ����ڿ��� �ִ� MAX_CH������ �Է� �ްڴٰ� ������
	
	state = getMyString(input_str, MAX_CH);

	if (state==1) printf("input: %s\n", input_str);
	else printf("input: %s -> out of range\n", input_str);
	
	return 0;
}

int getMyString(char buffer[], int limit) {
	int i;
	for (i = 0; i < limit; i++) {
		buffer[i] == getchar();
		if (buffer[i] == '\n') {
			buffer[i] = 0; //ENTER Ű ��ġ�� 0�� �־� ���ڿ� �ϼ�
			return 1; // ���������� �Է��� �Ϸ��
		}
	}
	buffer[i] = 0;
	rewind(stdin);
	return 0; // �Է� �ʰ� ������ �߻������� �˸�
}

void isCanceled(char input_str[]) {
	// ��ȯ���� NULL�� �ƴ϶�� ���ڿ���
	// �Է� �޾Ƽ� input_str�� ����
	if (NULL != gets(input_str)) {
		// getMyString()
		printf("input: %s\n", input_str);
	}
	else {
		printf("input -> CANCELED!\n");
	}
}