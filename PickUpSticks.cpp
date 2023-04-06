// 11686

#include <cstdio>

struct Node {
	int id;
	struct Node* next;

	Node(int i) {
		id = i;
		next = 0;
	}
};

struct List {
	struct Node* head;
	struct Node* tail;

	List() {
		head = 0;
		tail = 0;
	}

	void addNode(int i) {
		struct Node* n = new Node(i);
		if (head == 0) {
			head = n;
		} else {
			tail->next = n;
		}
		tail = n;
	}
};


int N, M, a, b;
struct List** adjList;
bool* visited;
bool* hasParent;
int* stack;
int cap;

void dfs(int u) {
	visited[u] = true;

	struct Node* curr = adjList[u]->head;
	while (curr != 0) {
		int v = curr->id;

		if (!visited[v]) {
			dfs(v);
		}
		curr = curr->next;
	}

	stack[cap++] = u;
}

void solve() {
	adjList = new List*[N + 1];
	visited = new bool[N + 1];
	hasParent = new bool[N + 1];
	stack = new int[N + 10];
	cap = 0;

	for (int i = 0; i < N + 1; i++) {
		adjList[i] = new List();
	}


	for (int i = 0; i < M; i++) {
		scanf("%d %d", &a, &b);

		adjList[a]->addNode(b);
		hasParent[b] = true;
	}

	for (int i = 1; i < N + 1; i++) {
		if (!hasParent[i] && !visited[i]) {
			dfs(i);
		}
	}

	if (cap < N) {
		printf("IMPOSSIBLE\n");
	} else {
		for (int i = N - 1; i >= 0; i--) {
			printf("%d\n", stack[i]);
		}
	}
}

int main() {
	scanf("%d %d", &N, &M);

	while (N + M > 0) {
		solve();
		scanf("%d %d", &N, &M);
	}
}
