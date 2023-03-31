// 11577

#include <cstdio>

int main() {
	int T;
	scanf("%d", &T);

	for (int t = 0; t < T; t++) {
		char text[205];
		char temp;
		scanf("%c%[^\n]", &temp, text);

		int max = 0;
		int* count = new int[26];

		int i = 0;
		while (text[i] != '\0') {
			int symbol = text[i++];
			int letter = -1;

			if (symbol >= 'A' && symbol <= 'Z') {
				letter = symbol - 'A';
				count[letter]++;
			} else if (symbol >= 'a' && symbol <= 'z') {
				letter = symbol - 'a';
				count[letter]++;
			}

			if (letter >= 0 && count[letter] > max) {
				max = count[letter];
			}
		}

		for (int i = 0; i < 26; i++) {
			if (count[i] == max) {
				printf("%c", i + 'a');
			}
		}
		printf("\n");
	}
	return 0;
}
