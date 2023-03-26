// 729

#include <cstdio>

char* bitString;
int N, H;

void createString(int remaining, int size) {
	if (size == N) {
		printf("%s\n", bitString);
		return;
	}

	if (size + remaining < N) {
		bitString[size] = '0';
		createString(remaining, size + 1);
	}

	if (remaining > 0) {
		bitString[size] = '1';
		createString(remaining - 1, size + 1);
	}
}

int main() {
	int T;

	scanf("%d", &T);

	for (int t = 0; t < T; t++) {
		scanf("%d %d", &N, &H);

		bitString = new char[N + 1];
		createString(H, 0);

		if (t < T - 1) {
			printf("\n");
		}
	}
	return 0;
}
