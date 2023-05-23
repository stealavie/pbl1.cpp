#include <stdio.h>
#include<stdlib.h>
#include <limits.h>
int min(int a, int b) {
    return (a < b) ? a : b;
}

void leastCost(int **cost,int *supply,int *demand, int m, int n) {
    int i, j, minCost = 0;
    int alloc[m][n] = {0};
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
     for (int i=0; i<m; i++)
        free(cost[i]);
    free(cost);
    free(supply);
    free(demand);
    printf("CUOC PHI NHO NHAT LA: %d\n", minCost);
}

int main() 
{
        while(1)
		{
        	printf ("-----------------------------------\n");
        	printf ("1.Doc tu file\n");
        	printf ("2.Nhap tu ban phim\n");
        	printf("nhap lua chon cua ban\n");
        	printf ("-----------------------------------\n");
        	int lc;scanf ("%d",&lc);
        	if (lc==2)
			{
        	printf ("NHAP SO DIEM CUNG VA CAU:\n");
			int m,n;scanf ("%d%d",&m,&n);
        	printf ("nhap ma tran cuoc phi\n");
        	int **cost;
	        cost=(int **)malloc(m * sizeof(int *));
            for (int i=0; i<m; i++)
               cost[i] = (int *)malloc(n * sizeof(int));
            for (int i = 0; i <  m; i++)
		 {
                for (int j = 0; j < n; j++)
                   scanf ("%d",&cost[i][j]);
    }  
            printf ("nhap so luong cung");
            int *supply;
            supply = (int *)malloc(m * sizeof(int));
            for (int i=0; i<m; i++) scanf("%d",&supply[i]);
            printf ("nhap so luong cau"); 
			int *demand;
            demand = (int *)malloc(n * sizeof(int));
            for (int i=0; i<n; i++) scanf("%d",&demand[i]);
			leastCost(cost,supply,demand,m,n);
		}
		else if (lc==1){
	    	//  char filename[100];
//    printf("Nhap ten tep tin: ");
//    scanf("%s", filename);

    FILE *file = fopen("D:/New folder/in.in", "r");//thay doi file 
//     if (file == NULL)
//     {
//         printf("Khong the mo tep tin %s\n", filename);
//         exit(1);
//     }

      int  m,n;
    fscanf(file,"%d%d",&m,&n);
     int **cost;
	        cost=(int **)malloc(m * sizeof(int *));
            for (int i=0; i<m; i++)
               cost[i] = (int *)malloc(n * sizeof(int));
        for (int i=0;i<m;i++)
        {
        	for (int j=0;j<n;j++) fscanf (file,"%d",&cost[i][j]);
		}
		 int *supply;
            supply = (int *)malloc(m * sizeof(int));
		for (int i=0;i<m;i++) fscanf (file,"%d",&supply[i]);
		 int *demand;
            demand = (int *)malloc(n * sizeof(int));
		for (int j=0;j<n;j++) fscanf (file,"%d",&demand[j]);
		leastCost(cost,supply,demand,m,n);
	} else if (lc==0) break;
	}
    return 0;
}
