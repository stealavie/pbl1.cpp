
#include <stdio.h>
#include <stdlib.h>

#define M 10
#define N 10

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
    if (*n == M * N) {
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

void leastCost(int cost[M][N], int supply[M], int demand[N], int m, int n) {
    Node heap[M * N];
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
    int cost[M][N] = {{19, 30, 50, 10},
                      {70, 30, 40, 60},
                      {40, 8, 70, 20}};
    int supply[M] = {7, 9, 18};
    int demand[N] = {5, 8, 7, 14};

    leastCost(cost, supply, demand, 3, 4);

    return 0;
}

