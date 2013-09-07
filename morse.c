#include <stdio.h>
#include <windows.h>

const char *morsedata[] = {
	".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---",
	"-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-",
	"..-", "...-", ".--", "-..-", "-.--", "--.."
};

#define DOT 50
#define DASH (DOT * 3)
#define FREQ 820
#define getmorse(c) (isalpha(c) ? morsedata[toupper(c)-'A'] : "")

int main(int argc, char *argv[]) {
	int ch;
	int sound = argc < 2 || !strstr(argv[1], "-n");
	puts("Hit enter to begin transmission");

	while ((ch = getchar()) != -1) {
		const char *morse;
		int len, i;
		if (ch == '\n' || ch == ' ') {
			if (sound)
				Sleep(350);
			putchar('\n');
			continue;
		}

		morse = getmorse(ch);
		if (sound) {
			len = strlen(morse);
			for (i = 0; i < len; ++i) {
				switch (morse[i]) {
					case '-':
						Beep(FREQ, DASH);
						break;
					case '.':
						Beep(FREQ, DOT);
						break;
				}
				putchar(morse[i]);
				Sleep(DOT);
			}
		} else
			printf("%s", morse);

		putchar(' ');
		if (sound)
			Sleep(150);
	}
}
