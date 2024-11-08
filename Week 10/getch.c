// getch.c
#include <stdio.h>
#include <conio.h> // MS의 표준 C 런타임 라이브러리
int main(void) {

	char input_data;
	int	count = 1;
	printf("Enter chars('q','Q', or ESC to quit):\n");

	// DRY = Don't Repeat Yourself
	while (1) {
		if (_kbhit()) { // 키보드 치는 함수
			input_data = _getch(); // 한 개의 문자를 입력 받음

			// 'q','Q', (ESC) 입력하면 종료
			if (input_data == 'q' || input_data == 'Q' || input_data == 27) {
				printf("\nExiting program...\n");
				break;
			}
			rewind(stdin);// 표준 입력 버퍼에 있는 모든 입력 값을 제거
			printf("input %d: %c\n", count++, input_data);
		}
	}

	return 0;
}