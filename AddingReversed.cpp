// 713

#include <cstdio>

int main() {
	const int max = 205;
	int T;
	char* A;
	char* B;

	scanf("%d", &T);

	for (int t = 0; t < T; t++) {
		A = new char[max];
		B = new char[max];

		scanf("%s %s", A, B);

		int x = 0;
		int y = 0;
		int aLast = x;
		int bLast = y;

		while (A[x] != '\0') {
			if (A[x] != '0')
				aLast = x;
			x++;
		}

		while (B[y] != '\0') {
			if (B[y] != '0')
				bLast = y;
			y++;
		}

		int carry = 0;
		bool zeroes = true;
		for (int i = 0; i <= aLast || i <= bLast; i++) {
			int a = i <= aLast ? A[i] - '0' : 0;
			int b = i <= bLast ? B[i] - '0' : 0;
			int s = a + b + carry;
			if (s >= 10) {
				s -= 10;
				carry = 1;
			} else {
				carry = 0;
			}
			if (s > 0) {
				zeroes = false;
			}
			if (!zeroes) {
				printf("%d", s);
			}
		}
		if (carry > 0)
			printf("%d", carry);
		printf("\n");
	}
	return 0;
}
