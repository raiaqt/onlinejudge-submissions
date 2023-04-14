// 13148

#include <cstdio>

int main() {
	int nums[21] = {1, 64, 729, 4096, 15625, 46656, 117649, 262144, 531441,
			1000000, 1771561, 2985984, 4826809, 7529536, 11390625, 16777216, 24137569, 34012224,
			47045881, 64000000, 85766121};
	int N;
	scanf("%d", &N);

	while (N != 0) {
		bool special = false;

		for (int i = 0; i < 21; i++) {
			if (N == nums[i]) {
				special = true;
			}
		}

		printf("%s\n", special ? "Special" : "Ordinary");

		scanf("%d", &N);
	}
    return 0;
}
