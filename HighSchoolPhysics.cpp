#include <cstdio>

int main() {
	int v, t;

	while (scanf("%d %d", &v, &t) != EOF) {
	    int p;
	    if (t == 0) {
	        p = 0;
	    } else {
    		int t2 = (t * 2) * (t * 2);
    		p = ((t2 * v) / t) / 2;
	    }
		printf("%d\n", p);
	}

	return 0;
}
