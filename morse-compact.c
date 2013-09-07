#include <windows.h>
const char *morse[] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."}, *s;
main(int argc, char *argv[]) {
	int c, sound = argc < 2 || !strstr(argv[1], "-n"), len, i, k = puts("Hit enter to begin transmission");
	while ((c = getchar()) != -1) {
		(c == '\n' || c == ' ') ? (sound ? Sleep(350) : 0), putchar('\n') : 0;
		if (sound) for (i = 0, s = (isalpha(c) ? morse[toupper(c)-'A'] : ""), len = strlen(s); i < len; ++i)
				Beep(820, s[i] == '-' ? 150 : 50), putchar(s[i]), Sleep(50);
		else printf("%s", (isalpha(c) ? morse[toupper(c)-'A'] : ""));
		c != '\n' && c != ' ' ? putchar(' ') : 0, sound ? Sleep(150) : 0;}}
