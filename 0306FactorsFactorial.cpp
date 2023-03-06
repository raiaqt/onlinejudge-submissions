// 160

#include <cstdio>
using namespace std;

int main() {
	const int max = 105;
	int num;
	int factors[max][max];
	bool isPrime[max];
	int primes[max];
	int primeSize = 0;

	for (int i = 0; i < max; i++) {
		for (int j = 0; j < max; j++) {
			factors[i][j] = 0;
		}
		isPrime[i] = true;
		primes[i] = 0;
	}

	for (int i = 2; i < max; i++) {
		// if prime, propagate
		if (isPrime[i]) {
			primes[primeSize++] = i;	// add to list of primes
			factors[i][i] = 1;			// i exists once in i;
			int multiplier = 2;
			int multiple = multiplier * i;

			while (multiple < max) {
				factors[multiple][i] = factors[multiplier][i] + 1;

				isPrime[multiple] = false;
				multiple = i * ++multiplier;
			}
		}
	}
	for (int i = 2; i < max; i++) {
		for (int j = 0; j < primeSize; j++) {
			int prime = primes[j];
			factors[i][prime] += factors[i - 1][prime];
		}
	}

	scanf("%d", &num);

	while (num != 0) {
		for (int i = 0; i < primeSize; i++) {
			int output = factors[num][primes[i]];
			if (output == 0) break;
			printf("%d ", output);
		}
		printf("\n");
		scanf("%d", &num);
	}
	return 0;
}
