// 10334

#include <cstdio>

int main() {
	const int max = 1005;
	const int digit = 300;
	int N;
	char fib[max][digit];

	for (int i = 0; i < max; i++) {
		for (int j = 0; j < max; j++) {
			fib[j][j] = 0;
		}
	}

	fib[0][digit - 1] = 1;
	fib[1][digit - 1] = 2;

	for (int i = 2; i < max; i++) {
		int carry = 0;
		for (int j = digit - 1; j >= 0; j--) {
			int sum = fib[i - 1][j] + fib[i - 2][j] + carry;
			carry = 0;
			if (sum > 9) {
				sum -= 10;
				carry = 1;
			}
			fib[i][j] = sum;
		}
	}


	int in = scanf("%d", &N);
	while (in == 1) {
		int j = 0;
		while (fib[N][j] == 0) j++;
		for (int i = j; i < digit; i++) {
			printf("%d", fib[N][i]);
		}
		printf("\n");
		in = scanf("%d", &N);
	}
	return 0;
}
