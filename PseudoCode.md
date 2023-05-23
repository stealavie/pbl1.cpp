# pbl1.cpp
\\ham leastCost
\\cach 1: tim kiem tham lam su dung ma tran
FUNCTION leastCost(cost[][], supply[], demand[], m, n)
    minCost = 0
    alloc[m][n] = {0}
    WHILE true
        minVal = INT_MAX
        FOR i = 0 to m-1
            FOR j = 0 to n-1
                IF supply[i] > 0 AND demand[j] > 0 AND cost[i][j] < minVal
                    minVal = cost[i][j]
                    minRow = i
                    minCol = j
                ENDIF
            ENDFOR
        ENDFOR

        IF minVal == INT_MAX THEN break

        alloc[minRow][minCol] = MIN(supply[minRow], demand[minCol])
        supply[minRow] -= alloc[minRow][minCol]
        demand[minCol] -= alloc[minRow][minCol]
        minCost += alloc[minRow][minCol] * cost[minRow][minCol]
    ENDWHILE

    FREE(cost)
    FREE(supply)
    FREE(demand)
    PRINT minCost
ENDFUNCTION




//cach 2: su dung thuat toan heap

FUNCTION leastCost(cost[][], supply[], demand[], m, n)
    CREATE heap of size m*n
    size = 0

    FOR i = 0 to m-1
        FOR j = 0 to n-1
            IF cost[i][j] != -1
                PUSH (Node){i, j, cost[i][j]} to heap
            ENDIF
        ENDFOR
    ENDFOR

    minCost = 0
   
    WHILE size > 0
        temp = POP from heap

        IF supply[temp.i] > 0 AND demand[temp.j] > 0
            x = MIN(supply[temp.i], demand[temp.j])
            minCost += x * temp.cost

            supply[temp.i] -= x
            demand[temp.j] -= x

            PRINT 
        ENDIF
    ENDWHILE

    PRINT minCost
ENDFUNCTION


\\cac ham lien quan
\\ham heapify

FUNCTION heapify(heap[], n, i)
    smallest = i
    left = 2 * i + 1
    right = 2 * i + 2

    IF left < n AND heap[left].cost < heap[smallest].cost
        smallest = left
    ENDIF

    IF right < n AND heap[right].cost < heap[smallest].cost
        smallest = right
    ENDIF

    IF smallest != i
        SWAP heap[i] and heap[smallest]
        heapify(heap, n, smallest)
    ENDIF
ENDFUNCTION


\\ham push

FUNCTION push(heap[], n, newNode)
    IF n == INT_MAX THEN return

    n = n + 1
    i = n - 1
    heap[i] = newNode

    WHILE i != 0 AND heap[(i - 1) / 2].cost > heap[i].cost
        SWAP heap[(i - 1) / 2] and heap[i]
        i = (i - 1) / 2
    ENDWHILE
ENDFUNCTION

\\ham pop

Sure! Here is the pseudo code for the pop function:

FUNCTION pop(heap[], n)
    IF n == 0 THEN return (-1, -1, -1)

    root = heap[0]
    heap[0] = heap[n - 1]
    n = n - 1

    heapify(heap, n, 0)

    return root
ENDFUNCTION
