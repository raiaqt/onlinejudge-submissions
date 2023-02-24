// 10264

#include <iostream>
#include <cstdio>

int pow (int base, int exp) {
	int res = 1;
	for (int i = 0; i < exp; i++) {
		res *= base;
	}
	return res;
}

int main() {
	int N;
	int corner[32800];
	int sums[32800];

	while(scanf("%d", &N) == 1) {
		int maxSum = 0;
		int C = pow(2, N);
		for (int c = 0; c < C; c++) {
			scanf("%d", &corner[c]);
		}

		for (int c = 0; c < C; c++) {
			int sum = corner[c];
			for (int i = 0; i < N; i++) {
				bool isOff = (c & 1 << i) == 0;

				int neighbor;
				if (isOff) {
					neighbor = c | 1 << i;
				} else {
					neighbor = c & ~(1 << i);
				}
				sum += corner[neighbor];
			}
			sums[c] = sum;
		}

		for (int c = 0; c < C; c++) {

					for (int i = 0; i < N; i++) {
						bool isOff = (c & 1 << i) == 0;

						int n;
						if (isOff) {
							n = c | 1 << i;

						} else {
							n = c & ~(1 << i);

						}
						int total = sums[c] + sums[n] - corner[c] - corner[n];
						if (total > maxSum) maxSum = total;
					}
				}
		printf("%d\n", maxSum);
	}

	return 0;
}
