// 12720

#include <cstdio>

int main() {
	const int max = 20005;
	const int m = 1000000007;
	int T;
	char* A;

	scanf("%d", &T);

	for (int t = 1; t <= T; t++) {
		A = new char[max];
		scanf("%s", A);

		int S = 0;
		int size = 0;
		while (A[size] != '\0')
			size++;

		int i = (size - 1) >> 1;
		int j = (size) >> 1;

		if (i == j) {
			S = A[i--] - '0';
			j++;
		}
		while (i >= 0 && j < size) {
			int removed1;
			int removed2;

			if (A[i] - '0' == 1) {
				removed1 = A[i--];
				removed2 = A[j++];
			} else {
				removed1 = A[j++];
				removed2 = A[i--];
			}

			removed1 = removed1 - '0';
			removed2 = removed2 - '0';

			S = S << 1;
			S = S | removed1;
			S = S % m;

			S = S << 1;
			S = S | removed2;
			S = S % m;
		}
		printf("Case #%d: %d\n", t, S);
	}

	return 0;
}
