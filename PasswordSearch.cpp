// 902

#include <cstdio>

const int cap = 50000;

struct Node {
	char* key;
	int value;
	struct Node* next;

	Node (char* p) {
		key = p;
		value = 1;
		next = 0;
	}
};

struct LinkedList {
	struct Node* head;
	struct Node* tail;

	LinkedList () {
		head = 0;
		tail = 0;
	}

	void addNode (char* p) {
		struct Node* n = new Node(p);
		if (head == 0) {
			head = n;
		} else {
			tail->next = n;
		}
		tail = n;
	}
};

struct HashMap {
	struct LinkedList** map;

	HashMap () {
		map = new LinkedList*[cap];
	}

	int getHash(char* p) {
		int m = 7;
		int hash = 0;
		int mult = 1;

		int i = 0;
		while (p[i] != '\0') {
			int charCount = ((p[i] - 'a') * mult) % cap;
			hash = (hash + charCount) % cap;
			mult = (mult * m) % cap;
			i++;
		}
		return hash % cap;
	}

	bool isSame(char* p1, char* p2) {
		int i = 0;
		while (p1[i] != '\0' && p2[1] != '\0' && p1[i] == p2[i])
			i++;
		return p1[i] == p2[i];
	}

	int addCount(char* p) {
		int hash = getHash(p);
		if (!map[hash]) {
			struct LinkedList* ll = new LinkedList();
			ll->addNode(p);
			map[hash] = ll;
			return 1;
		}
		struct Node* curr = map[hash]->head;
		while (curr != 0) {
			if (isSame(p, curr->key)) {
				curr->value++;
				return curr->value;
			}
			curr = curr->next;
		}

		map[hash]->addNode(p);
		return 1;
	}

	int getCount(char* p) {
		int hash = getHash(p);
		struct Node* curr = map[hash]->head;
		while (curr != 0) {
			if (isSame(p, curr->key)) {
				return curr->value;
			}
			curr = curr->next;
		}
		return 0;
	}
};

int main() {
	int size = 0;
	char* message = new char[1000000];
	scanf("%d", &size);
	while (scanf("%d", &size) != EOF) {
		scanf("%s", message);
		struct HashMap* hashMap = new HashMap();
		int maxCount = 0;
		char* password;

		if (size == 0) {
			printf("\n");
		} else {
			int i = 0;
			while (message[i + size - 1] != '\0') {
				char* p = new char[size + 5];
				for (int j = 0; j < size; j++) {
					p[j] = message[i + j];
				}
				int newCount = hashMap->addCount(p);
				if (newCount > maxCount) {
					maxCount = newCount;
					password = p;
				}
				i++;
			}

			printf("%s\n", password);
		}
	}

	return 0;
}
