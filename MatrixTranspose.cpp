#include <cstdio>

struct Element {
    int row;
    int col;
    int val;
    
    Element(int r, int c, int v) {
        row = r;
        col = c;
        val = v;
    }
};

int main() {
    const int max = 1005;
    struct Element** list;
    int size;
    int rows, cols;
    
    size = 0;
    list = new Element*[max];
    
    while (scanf("%d %d", &rows, &cols) != EOF) {
        for (int i = 1; i <= rows; i++) {
            int rowElements;
            int *rowCols;
            
            scanf("%d", &rowElements);
            rowCols = new int[rowElements];
            for (int j = 0; j < rowElements; j++) {
                scanf("%d", &rowCols[j]);
            }
            for (int j = 0; j < rowElements; j++) {
                int elementVal;
                scanf("%d", &elementVal);
                struct Element* newElement = new Element(i, rowCols[j], elementVal);
                list[size++] = newElement;
            }
        }
        
        // reconstruct sparse matrix representation
        
        // count all columns per row
        int *colRowCount = new int[cols];
        int *colSize = new int[cols];
        int **colRows = new int*[cols];
        int **colElements = new int*[cols];
        
        for (int i = 0; i < cols; i++) {
            colRowCount[i] = 0;
            colSize[i] = 0;
        }
        for (int i = 0; i < size; i++) {
            int j = list[i]->col - 1;
            colRowCount[j]++;
        }
        
        for (int i = 0; i < cols; i++) {
            colRows[i] = new int[colRowCount[i]];
            colElements[i] = new int[colRowCount[i]];
        }
        
        for (int i = 0; i < size; i++) {
            int c = list[i]->col - 1;
            int r = list[i]->row;
            int v = list[i]->val;
            
            colRows[c][colSize[c]] = r;
            colElements[c][colSize[c]++] = v;
        }
        
        printf("%d %d\n", cols, rows);
        
        for (int i = 0; i < cols; i++) {
            printf("%d", colRowCount[i]);
            for (int j = 0; j < colRowCount[i]; j++) {
                printf(" %d", colRows[i][j]);
            }
            printf("\n");
            
            for (int j = 0; j < colRowCount[i]; j++) {
                printf("%d", colElements[i][j]);
                if (j < colRowCount[i] - 1) {
                    printf(" ");
                }
            }
            printf("\n");
        }
        size = 0;
        list = new Element*[max];
    }
    
    return 0;
}