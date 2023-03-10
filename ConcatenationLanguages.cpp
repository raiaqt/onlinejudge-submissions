#include <cstdio>

struct Node {
    char* word1;
    char* word2;
    struct Node* next;
    
    Node(char* w1, char* w2) {
        word1 = w1;
        word2 = w2;
        next = 0;
    }
};

struct List {
    struct Node* head;
    struct Node* tail;
    
    void addNode(char* w1, char* w2) {
        struct Node* newNode = new Node(w1, w2);
        if (head == 0) {
            head = newNode;
        } else {
            tail->next = newNode;
        }
        tail = newNode;
    }
    
    // TO DO: fix
    bool isSame(char* w1, char* w2, char* n1, char* n2) {
        for (int i = 0; i < max; i++) {
            if (word1[i] != word2[i]) {
                return false;
            }
        }
        return true;
    }
    
    bool nodeExists(char* w1, char* w2) {
        struct Node* curr = head;
        while (curr != 0) {
            if (isSame(w1, w2, curr->w1, curr->w2)) {
                return true;
            }
        }
        return false;
    }
};

const int max = 11;
const int size = 4519747;
struct List** concatSet;
char** set1;
char** set2;

int getHash(char* word1, char* word2) {
    int mult = 1;
    int m = 7;
    int hash = 0;
    
    int i = 0;
    while (word1[i] != '\0') {
        hash += ((word1[i++] - 'a') * mult) % size;
        mult = (mult * m) % size;
    }
    i = 0;
    while (word2[i] != '\0') {
        hash += ((word2[i++] - 'a') * mult) % size;
        mult = (mult * m) % size;
    }
    
    return hash;
}

int main() {
    int T, M, N;
    scanf("%d", &T);
    
    for (int t = 0; t < T; t++) {
        scanf("%d %d", &M, &N);
        set1 = new char*[M];
        set2 = new char*[N];
        concatSet = new List*[size];
        
        for (int i = 0; i < size; i++) {
            concatSet[i] = new List();
        }
        for (int m = 0; m < M; m++) {
            set1[m] = new char[max];
            scanf("%s", set1[m]);
        }
        for (int n = 0; n < N; n++) {
            set2[n] = new char[max];
            scanf("%s", set2[n]);
        }
        
        for (int m = 0; m < M; m++) {
            for (int n = 0; n < N; n++) {
                int hash = getHash(set1[m], set2[n]);
                struct Node* curr = concatSet[hash]->head;
                
                if (curr == 0) {
                    concatSet[hash]->addNode(set1[m], set2[n]);
                } else {
                    // TO DO: add to set size if does not exist yet
                }
            }
        }
    }
    
    printf("done");
    return 0;
}