#include <stdio.h>
#include <limits.h>
#define M 10
#define N 10

int min(int a, int b) {
    return (a < b) ? a : b;
}

void leastCost(int cost[M][N], int supply[M], int demand[N], int m, int n) {
    int i, j, minCost = 0;
    int alloc[M][N] = {0};
    printf("DUONG DI TOI UU SU DUNG PHUONG PHAP CUOC PHI NHO NHAT:\n");
    while (1) {
        int minVal = INT_MAX;
        int minRow, minCol;

        for (i = 0; i < m; i++) {
            for (j = 0; j < n; j++) {
                if (supply[i] > 0 && demand[j] > 0 && cost[i][j] < minVal) {
                    minVal = cost[i][j];
                    minRow = i;
                    minCol = j;
                }
            }
        }

        if (minVal == INT_MAX) break;

        alloc[minRow][minCol] = min(supply[minRow], demand[minCol]);
        supply[minRow] -= alloc[minRow][minCol];
        demand[minCol] -= alloc[minRow][minCol];
        minCost += alloc[minRow][minCol] * cost[minRow][minCol];
         printf("x[%d][%d]=%d\n",minRow+1,minCol+1, alloc[minRow][minCol]);
    }

//    printf("DUONG DI TOI UU SU DUNG PHUONG PHAP CUOC PHI NHO NHAT:\n");
//    for (i = 0; i < m; i++) {
//        for (j = 0; j < n; j++) {
//            printf("%d ", alloc[i][j]);
//        }
//        printf("\n");
//    }

    printf("CUOC PHI NHO NHAT LA: %d\n", minCost);
}
//O(m*n*(m+n-1))
int main() {
    int cost[M][N] = {{19, 30, 50, 10},
                      {70, 30, 40, 60},
                      {40, 8, 70, 20}};
    int supply[M] = {7, 9, 18};
    int demand[N] = {5, 8, 7, 14};
    

    leastCost(cost, supply, demand, 3, 4);

    return 0;
}
