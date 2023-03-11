// 11614

#include <cstdio>

bool canFillRows(long d, long n) {
	if (d > 2000000000)
		return false;
	long sum = (d * (d + 1));
	return sum <= n * 2;
}

int main() {
	int T;
	scanf("%d", &T);
	for (int t = 0; t < T; t++) {
		long N;
		scanf("%ld", &N);

		long high = N;
		long low = 0;

		while (high - low > 1) {
			long mid = (high + low) >> 1;
			if (canFillRows(mid, N)) {
				low = mid;
			} else {
				high = mid;
			}
		}

		printf("%ld\n", canFillRows(high, N) ? high : low);
	}
	return 0;
}
