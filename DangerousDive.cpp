// 12650

#include <cstdio>

int main() {
	int N, R;
	bool returned[10005];
	int volunteer;

	while (scanf("%d %d", &N, &R) != EOF) {

		for (int i = 1; i <= N; i++) {
			returned[i] = false;
		}

		for (int i = 0; i < R; i++) {
			scanf("%d", &volunteer);
			returned[volunteer] = true;
		}

		if (N == R) {
			printf("*");
		} else {
			for (int i = 1; i <= N; i++) {
				if (!returned[i]) {
					printf("%d ", i);
				}
			}
		}

		printf("\n");
	}
	return 0;
}
