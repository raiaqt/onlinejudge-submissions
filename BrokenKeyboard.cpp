#include <cstdio>

struct Node {
	char c;
	struct Node *next;

	Node(char in) {
		c = in;
		next = 0;
	}
};

struct Node *head;
struct Node *tail;
struct Node *pointer;

void insertToPointer(char in) {
	struct Node *newNode = new Node(in);
	newNode->next = pointer->next;
	pointer->next = newNode;
	pointer = newNode;

	if (newNode->next == 0) {
		tail = newNode;
	}
}

int main() {

	const int max = 100005;
	char *inputText;
	inputText = new char[max];

	while(scanf("%s", inputText) != EOF) {
		struct Node *startNode = new Node('a');
		head = startNode;
		tail = startNode;
		pointer = startNode;

		int i = 0;
		while (inputText[i] != '\0') {
			char in = inputText[i++];
			if (in == '[') {
				pointer = head;
			} else if (in == ']') {
				pointer = tail;
			} else {
				insertToPointer(in);
			}
		}

		struct Node *curr = head->next;
		while (curr != 0) {
			printf("%c", curr->c);
			curr = curr->next;
		}
		printf("\n");
		inputText = new char[max];
	}

	return 0;
}
