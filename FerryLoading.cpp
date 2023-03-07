#include <cstdio>

int main() {
	int T, length, M;
	int lSize, rSize;
	int lCount, rCount;

	int carLength;
	char bank[5];

	scanf("%d", &T);

	for (int t = 0; t < T; t++) {
		length = 0;
		M = 0;
		lSize = 0;
		rSize = 0;
		lCount = 1;
		rCount = 1;
		scanf("%d %d", &length, &M);

		length *= 100;
		for (int m = 0; m < M; m++) {
			scanf("%d %s", &carLength, bank);
			if (bank[0] == 'l') {
				lSize += carLength;
				if (lSize > length) {
					lCount++;
					lSize = carLength;
				}
			} else {
				rSize += carLength;
				if (rSize > length) {
					rCount++;
					rSize = carLength;
				}
			}
		}

		int result;

		if (lCount > rCount) {
			result = (lCount * 2) - 1;
		} else {
			result = rCount * 2;
		}
		printf("%d\n", result);
	}

	return 0;
}
