//mathFormulas.c
#include <stdio.h>
#include <stdlib.h> // atoi()�Լ� ���� -> arrayToInt()�ۼ�
#include <ctype.h> // isdigit()�Լ� ���� -> numCheck()�ۼ�

int numCheck(char ch) {
	return ch >= '0' && ch <= '9'; // 1�̳� 0��ȯ
}
int check0p(char op) {
	return op == '+' || op == '-' ||
		op == '*' || op == '/';
}
int arrayToInt(char str[]) {
	int i = 0, num = 0;

	// ���ڿ��� �ݺ��ϰ� ��� ���ڰ� ���ڷ� ����
	while (str[i] != '\0') {
		// �������� Ȯ���ϱ�
		if (numCheck(str[i])) { // 1
			num = num * 10 + (str[i] - '0'); // ASCII 48 ���� �Ǽ��� ����
		}
		else { // 0
			break;
		}
		i++; // ���� ���ڷ� �̵�
	}
	return num;
}

int main(void) {
	char input[100],
		numStr1[50],
		numStr2[50],
		operator='\0'; // ������ NULL�� �ʱ�ȭ�ϱ�
	int i = 0, // ���� �Է��� ���ڿ��� �ε���
		j = 0; // �ް���� ������ �ε���
	
	// ����ڿ��� ���� �Լ� �ޱ� (��: 12+34)
	printf("Enter a simple math formula (12+34):\n");
	fgets(input, sizeof(input), stdin);

	// #1: ù��° ���ڸ� �����ϱ�
	while (input[i] != '\0' && numCheck(input[i])) {
		numStr1[j++] = input[i++];
	}
	numStr1[j] = '\0';

	// #2: ���� �����ڸ� ã��
	if (check0p(input[i])) { // 1
		operator = input[i++];
	}
	else {
		printf("Error: Invalid operator!\n");
		return 1; // main �Լ� ���� �־ ����
	}

	j = 0; // �ι�° ���ڸ� �ޱ����� �ʱ�ȭ �ϱ�

	// #3: �ι�° ���ڸ� �����ϱ� 
	while (input[i] != '\0' && numCheck(input[i])) {
		numStr2[j++] = input[i++];
	}
	numStr2[j] = '\0';

	/*
	�� :
	input = "123+456"
	numStr1 = "123"
	operator = '+'
	numStr2 = "456"
	*/

	// �� numStr�� ���ڷ� �����ϱ�
	int num1 = arrayToInt(numStr1);
	int num2 = arrayToInt(numStr2);
	int result = 0;

	// ����ϱ�
	switch (operator) {
	case '+':
		result = num1 + num2;
		break;
	case '-':
		result = num1 - num2;
		break;
	case '*':
		result = num1 * num2;
		break;
	case '/':
		if (num2 != 0)
			result = num1 / num2;
		else{
			printf("Error: Division by 0!\n");
		return 1; // ���� �߻�!
	}
		break;
	default:
		printf("Error: Invalid operator. Use +,-,*,/.\n");
		return 1; // ���� �߻�!
	}

	printf("Result: %d %c %d = %d\n", num1, operator, num2, result);

	return 0; // main �Լ��� ���� ���� ����
}