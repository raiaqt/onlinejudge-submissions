// 11799

#include <cstdio>

int main() {
	int T, N;

	scanf("%d", &T);

	for (int t = 1; t <= T; t++) {
		scanf("%d", &N);

		int maxSpeed = 0;
		int currSpeed;

		for (int i = 0; i < N; i++) {
			scanf("%d", &currSpeed);

			if (currSpeed > maxSpeed)
				maxSpeed = currSpeed;
		}

		printf("Case %d: %d\n", t, maxSpeed);
	}
	return 0;
}
