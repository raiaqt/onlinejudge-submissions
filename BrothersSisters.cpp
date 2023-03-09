// 12571

#include <cstdio>

int getMax(int a, int b) {
	return a > b ? a : b;
}

int main() {
	const int M = 235;
	int T, N, Q;
	int *x;
	int **memo;
	int *max;

	scanf("%d", &T);
	for (int t = 0; t < T; t++) {
		scanf("%d %d", &N, &Q);

		x = new int[N];
		memo = new int*[N];
		max = new int[M];

		for (int i = 0; i < N; i++) {
			scanf("%d", &x[i]);
			memo[i] = new int[M];
		}

		for (int j = 0; j < Q; j++) {
			max[j] = 0;
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				max[j] = getMax(max[j], x[i] & j);
				memo[i][j] = max[j];
			}
		}

		for (int i = 0; i < Q; i++) {
			int a;
			scanf("%d", &a);

			printf("%d\n", memo[N - 1][a]);
		}
	}
	return 0;
}
