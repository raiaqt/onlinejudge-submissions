// 11450

#include <cstdio>
#include <iostream>

using namespace std;

int priceCap, categories;
int modelCount[20];
int garmentPrice[20][20];
bool valid;

int memo[20][201];

int getMaxPrice(int priceCap, int categoryIndex) {
    if (categoryIndex == categories) {
        valid = true;
        return 0;
    }
    
    if (memo[categoryIndex][priceCap] == -1) {
        int maxPrice = 0;
        for (int i = 0; i < modelCount[categoryIndex]; i++) {
            int remaining = priceCap - garmentPrice[categoryIndex][i];
            if (remaining >= 0) {
                int price = getMaxPrice(remaining, categoryIndex + 1) + garmentPrice[categoryIndex][i];
                if (price > maxPrice) {
                    maxPrice = price;
                }
            }
        }
        memo[categoryIndex][priceCap] = maxPrice;
        return maxPrice;
    } else {
        return memo[categoryIndex][priceCap];
    }
}

int main() {
    int T;
    scanf("%d", &T);
    
    for (int t = 0; t < T; t++) {
        scanf("%d %d", &priceCap, &categories);
        
        for (int c = 0; c < categories; c++) {
            scanf("%d", &modelCount[c]);
            
            for (int m = 0; m < modelCount[c]; m++) {
                scanf("%d", &garmentPrice[c][m]);
            }
        }
        
        for (int i = 0; i < categories; i++) {
            for (int j = 0; j <= priceCap; j++) {
                memo[i][j] = -1;
            } 
        }
        valid = false;
        int result = getMaxPrice(priceCap, 0);
        if (!valid) {
            printf("no solution\n");
        } else {
            printf("%d\n", result);
        }
    }
   
   return 0;
}
