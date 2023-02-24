// 11297

#include <cstdio>
#include <cmath>

using namespace std;

const int MAX_INT = 2147483647;
const int MIN_INT = -2147483647;
int tempSize;
int **input;
int N;
int segSize;
int **minSegTree;
int **maxSegTree;

void debug() {
	printf("minSegTree\n");
	for (int i = 0; i < segSize; i++) {
		for (int j = 0; j < segSize; j++) {
			printf("%d ", minSegTree[i][j]);
		}
		printf("\n");
	}
	printf("maxSegTree\n");
	for (int i = 0; i < segSize; i++) {
		for (int j = 0; j < segSize; j++) {
			printf("%d ", maxSegTree[i][j]);
		}
		printf("\n");
	}
	printf("array\n");
		for (int i = 0; i < tempSize; i++) {
			for (int j = 0; j < tempSize; j++) {
				printf("%d ", input[i][j]);
			}
			printf("\n");
		}
	printf("\n");
}

int solve(int a, int b, bool min) {
	if (min) return a < b ? a : b;
	return a > b ? a : b;
}

int setXTree(int i, int j, int **segTree, bool min) {
	if (j >= N) {
		if (j - N < tempSize && i - N < tempSize) {
			segTree[i][j] = input[i - N][j - N];
		} else {
			segTree[i][j] = min ? MAX_INT : MIN_INT;
		}
	} else {
		segTree[i][j] = solve(setXTree(i, j * 2, segTree, min), setXTree(i, (j * 2) + 1, segTree, min), min);
	}

	return segTree[i][j];
}

int setYTree(int i, int j, int **segTree, bool min) {
	if (i >= N) {
		if (i - N >= tempSize || j - N >= tempSize) {
			segTree[i][j] = min ? MAX_INT : MIN_INT;
		}
		return segTree[i][j];
	}

	segTree[i][j] = solve(setYTree(i * 2, j, segTree, min), setYTree((i * 2) + 1, j, segTree, min), min);
	return segTree[i][j];
}

void setTree() {
	for (int i = N; i < segSize; i++) {
		setXTree(i, 1, minSegTree, true);
		setXTree(i, 1, maxSegTree, false);
	}
	for (int j = 0; j < segSize; j++) {
		setYTree(1, j, minSegTree, true);
		setYTree(1, j, maxSegTree, false);
	}
}

void changeVal(int i, int j, int val) {
	int currX = N + i;
	int currY = N + j;
	minSegTree[currX][currY] = val;
	maxSegTree[currX][currY] = val;
	currX = currX >> 1;
	int currY2 = currY >> 1;
	while(currX != 0) {
		currY = currY2;
		while(currY != 0) {
			minSegTree[currX][currY] = solve(minSegTree[currX][currY], val, true);
			maxSegTree[currX][currY] = solve(maxSegTree[currX][currY], val, false);
			currY = currY >> 1;
		}
		currX = currX >> 1;
	}
}

int* getRes(int x1, int x2, int y1, int y2) {
	x1 += N;
	x2 += N;
	y1 += N;
	y2 += N;
	int* res = new int[2];
	res[0] = MAX_INT;
	res[1] = MIN_INT;

	int *xNodes = new int[N];
	int xCap = 0;

	int *yNodes = new int[N];
	int yCap = 0;

	while (x1 <= x2 && x1 != 0 && x2 != 0) {
		if (x1 & 1)
			xNodes[xCap++] = x1++;
		x1 = x1 >> 1;

		if (!(x2 & 1))
			xNodes[xCap++] = x2--;
		x2 = x2 >> 1;
	}
	if (x1 == x2) {
		xNodes[xCap++] = x1;
	}
	while (y1 <= y2 && y1 != 0 && y2 != 0) {
		if (y1 & 1)
			yNodes[yCap++] = y1++;
		y1 = y1 >> 1;

		if (!(y2 & 1))
			yNodes[yCap++] = y2--;
		y2 = y2 >> 1;
	}
	for (int i = 0; i < xCap; i++) {
		for (int j = 0; j < yCap; j++) {
			res[0] = solve(minSegTree[xNodes[i]][yNodes[j]], res[0], true);
			res[1] = solve(maxSegTree[xNodes[i]][yNodes[j]], res[1], false);
		}
	}

	return res;
}

int main() {

	scanf("%d", &tempSize);

	N = pow(2, ceil(log2(tempSize)));
	segSize = N * 2;

	minSegTree = new int*[segSize];
	maxSegTree = new int*[segSize];
	for (int i = 0; i < segSize; i++) {
		minSegTree[i] = new int[segSize];
		maxSegTree[i] = new int[segSize];
	}

	input = new int*[tempSize];
	for (int i = 0; i < tempSize; i++) {
		input[i] = new int[tempSize];
	}

	for (int i = 0; i < tempSize; i++) {
		for (int j = 0; j < tempSize; j++) {
			scanf("%d", &input[i][j]);
		}
	}
	setTree();
	int Q;

	scanf("%d", &Q);
	for (int q = 0; q < Q; q++) {
		char c[1];
		scanf("%s", &c);
		if (c[0] == 'q') {
			int x1, x2, y1, y2;
			scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
			int* res = new int[2];
			res = getRes(x1 - 1, x2 - 1, y1 - 1, y2 - 1);
			printf("%d %d\n", res[1], res[0]);
		} else {
			int x, y, v;
			scanf("%d %d %d", &x, &y, &v);
			changeVal(x - 1, y - 1, v);
			debug();
		}
	}

	return 0;
}
