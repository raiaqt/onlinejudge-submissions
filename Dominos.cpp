// 11504

// IN PROGRESS

#include <cstdio>

struct Node {
	int val;
	struct Node* next;
};

struct List {
	struct Node* head;
	struct Node* tail;

	void addNode(int v) {
		struct Node* n = new Node;
		n->val = v;
		if (head == 0) {
			head = n;
		} else {
			tail->next = n;
		}
		tail = n;
	}
};

int T, N, M, x, y;
struct List** adjList;
bool* visited;
bool* stacked;
int* stack;
int cap;
int* id;
int* low;
int ctr;
int moves;

int min(int a, int b) {
	return a < b ? a : b;
}

void dfs(int n) {
	//printf("%d\n", n);
	stack[cap++] = n;
	stacked[n] = true;
	visited[n] = true;
	id[n] = ctr;
	low[n] = ctr++;

	// visit all unvisited neighbors
	struct Node* curr = adjList[n]->head;
	while (curr != 0) {
		int adj = curr->val;
		if (!visited[adj]) {
			dfs(adj);
		}
		if (stacked[adj]) {
			low[n] = min(low[adj], low[n]);
		}

		curr = curr->next;
	}

	if (id[n] == low[n]) {
		while(cap > 0) {
			int pop = stack[--cap];
			stacked[pop] = false;
			low[pop] = id[n];
			if (pop == n) {
				break;
			}
		}
		printf("n %d\n", n);
		moves++;
	}

}

int main() {

	scanf("%d", &T);

	for (int t = 0; t < T; t++) {
		scanf("%d %d", &N, &M);

		adjList = new List*[++N];		// 1-indexed
		visited = new bool[N];
		stacked = new bool[N];
		stack = new int[N];
		cap = 0;
		id = new int[N];
		low = new int[N];
		ctr = 0;
		moves = 0;

		for (int n = 0; n < N; n++) {
			adjList[n] = new List;
		}

		for (int m = 0; m < M; m++) {
			scanf("%d %d", &x, &y);
			adjList[x]->addNode(y);
		}
	}

	for (int i = 1; i <= N; i++) {
		if (!visited[i]) {
			dfs(i);
		}
	}

	printf("%d", moves);

	return 0;
}
