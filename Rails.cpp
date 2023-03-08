#include <cstdio>

int main() {
	int N;
	int *permutation;

	scanf("%d", &N);

	while (N != 0) {
		permutation = new int[N];
		int first;

		scanf("%d", &first);
		while(first != 0) {
			permutation[0] = first;

			for (int i = 1; i < N; i++) {
				scanf("%d", &permutation[i]);
			}

			// solve
			int j = 0;
			int *stack = new int[N];
			int top = 0;
			int counter = 1;

			bool impossible = false;
			while (j < N) {
				if (top > 0 && permutation[j] == stack[top - 1]) {
					top--;
					j++;
				} else {
					stack[top++] = counter++;
				}

				if (counter > N + 1) {
					impossible = true;
					break;
				}
			}

			printf("%s\n", impossible ? "No" : "Yes");

			scanf("%d", &first);
		}
		printf("\n");
		scanf("%d", &N);


	}

	return 0;
}
