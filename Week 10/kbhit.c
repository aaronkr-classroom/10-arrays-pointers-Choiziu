// kbhit.c

#include <stdio.h>
#include <conio.h>

int main(void) {
	int ch;

	printf("Press any key to see ASCII value (ESC to quit):\n");

	while (1) {
		if (_kbhit()) {
			ch = _getch();

			if (ch == 27) {
				printf("ESC pressed! Exiting...");
				break;
			}

			// 츨력 가능한 키
			if (ch >= 32&& ch <= 126) {
				printf("Key: %c, ASCII: %d\n", ch, ch);
			}
			// 출력 불가능 키 (F1~F12, 등)
			else {
				printf("ASCII: %d\n", ch);
			}
		}
	}

	return 0;
}