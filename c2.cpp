#include <stdio.h>
#include <stdlib.h>
#include<limits.h>

typedef struct node {
    int i;
    int j;
    int cost;
} Node;

void swap(Node *a, Node *b) {
    Node temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(Node heap[], int n, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && heap[left].cost < heap[smallest].cost) {
        smallest = left;
    }

    if (right < n && heap[right].cost < heap[smallest].cost) {
        smallest = right;
    }

    if (smallest != i) {
        swap(&heap[i], &heap[smallest]);
        heapify(heap, n, smallest);
    }
}

void push(Node heap[], int *n, Node newNode) {
    if (*n == INT_MAX) {
        return;
    }

    (*n)++;
    int i = *n - 1;
    heap[i] = newNode;

    while (i != 0 && heap[(i - 1) / 2].cost > heap[i].cost) {
        swap(&heap[(i - 1) / 2], &heap[i]);
        i = (i - 1) / 2;
    }
}

Node pop(Node heap[], int *n) {
    if (*n == 0) {
        return (Node){-1, -1, -1};
    }

    Node root = heap[0];
    heap[0] = heap[*n - 1];
    (*n)--;

    heapify(heap, *n, 0);

    return root;
}

void leastCost(int **cost, int *supply, int *demand, int m, int n) {
    Node heap[m*n];
    int size = 0;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (cost[i][j] != -1) {
                push(heap, &size, (Node){i, j, cost[i][j]});
            }
        }
    }

    int totalCost = 0;
printf("DUONG DI TOI UU SU DUNG PHUONG PHAP CUOC PHI NHO NHAT:\n");
    while (size > 0) {
        Node temp = pop(heap, &size);

        if (supply[temp.i] > 0 && demand[temp.j] > 0) {
            int x = supply[temp.i] < demand[temp.j] ? supply[temp.i] : demand[temp.j];
            totalCost += x * temp.cost;

            supply[temp.i] -= x;
            demand[temp.j] -= x;

            printf("x[%d][%d] = %d\n", temp.i + 1, temp.j + 1, x);
        }
    }

    printf("Total cost: %d\n", totalCost);
}
//O(m*n*log(m*n)
int main() {
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
	    	  char filename[100];
//    printf("Nhap ten tep tin: ");
//    scanf("%s", filename);

    FILE *file = fopen("D:/New folder/in.in", "r");
    if (file == NULL)
    {
        printf("Khong the mo tep tin %s\n", filename);
        exit(1);
    }

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
	}
	}
    return 0;
}
