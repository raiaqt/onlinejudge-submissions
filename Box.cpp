// 1587

#include <cstdio>

int w[6];
int h[6];
bool used[6];

int a[3];
int b[3];
bool pUsed[3];

bool isSameRec(int i, int j) {
	if (w[i] == w[j] && h[i] == h[j]) return true;
	if (w[i] == h[j] && h[i] == w[j]) return true;
	return false;
}

bool isPossible() {
	// check if there are 3 pairs of same rectangles
	int p = 0;
	for (int i = 0; i < 6; i++) {
		for (int j = i + 1; j < 6; j++) {
			if (!used[i] && !used[j] && isSameRec(i, j)) {
				if (p == 0) {
					a[p] = w[i];
					b[p] = h[i];
				} else if (p == 1) {
					if (w[i] != a[0] && h[i] != b[0]) {
						a[p] = w[i];
						b[p] = h[i];
					} else {
						a[p] = h[i];
						b[p] = w[i];
					}
				} else {
					if (w[i] != a[0] && w[i] != a[1] && h[i] != b[0] && h[i] != b[1]) {
						a[p] = w[i];
						b[p] = h[i];
					} else {
						a[p] = h[i];
						b[p] = w[i];
					}
				}
				p++;
				used[i] = true;
				used[j] = true;
				break;
			}
		}
	}

	if (p < 3) {
		return false;
	}

	int s = 0;
	for (int i = 0; i < 3; i++) {
		bool hasSame = false;
		for (int j = 0; j < 3; j++) {
			if (i != j && a[i] == b[j]) {
				hasSame = true;
			}
		}
		if (hasSame) {
			s++;
		}
	}

	for (int i = 0; i < 3; i++) {
			bool hasSame = false;
			for (int j = 0; j < 3; j++) {
				if (i != j && b[i] == a[j]) {
					hasSame = true;
				}
			}
			if (hasSame) {
				s++;
			}
		}

	if (s < 6) {
		return false;
	}
	return true;
}
int main() {

    while (scanf("%d %d", &w[0], &h[0]) != EOF) {
    	for (int i = 1; i < 6; i++) {
    		scanf("%d %d", &w[i], &h[i]);
    	}

    	for (int i = 0; i < 6; i++) {
    		used[i] = false;
    		pUsed[i] = false;
    	}

    	printf("%s\n", isPossible() ? "POSSIBLE" : "IMPOSSIBLE");
    }

    return 0;
}
