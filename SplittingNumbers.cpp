// 11933

#include <cstdio>

int main() {
	int N;
	scanf("%d", &N);

	while(N != 0) {
		int a = 0;
		int b = 0;
		bool odd = true;
		for (int i = 0; i < 31; i++) {
			int one = 1 << i;
			if (N & one) {
				if (odd) {
					a = a | one;
				} else {
					b = b | one;
				}
				odd = !odd;
			}
		}
		printf("%d %d\n", a, b);
		scanf("%d", &N);
	}
	return 0;
}
