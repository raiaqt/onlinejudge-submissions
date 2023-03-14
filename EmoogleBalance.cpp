// 12279

#include <cstdio>

int main() {
	int N;

	scanf("%d", &N);

	int t = 1;
	while (N != 0) {

		int supposed = 0;
		int actual = 0;

		for (int i = 0; i < N; i++) {
			int in;
			scanf("%d", &in);

			if (in == 0) {
				actual++;
			} else {
				supposed++;
			}
		}

		printf("Case %d: %d\n", t++, supposed - actual);

		scanf("%d", &N);
	}
	return 0;
}
