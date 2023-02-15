#include "heap.h"


HeapNode heap[256];
int heapSize;



void bubbleUp(int pos);
void bubbleDown(int pos);

void bubbleUp(int pos) {
    if (pos <= heapSize && pos/2 > 0) {
        if (heap[pos].freq < heap[pos/2].freq) {
            HeapNode temp = heap[pos];
            heap[pos] = heap[pos/2];
            heap[pos/2] = temp;
            bubbleUp(pos/2);
        }
    }
}

void bubbleDown(int pos) {
    if (pos > 0 && pos <= heapSize) {
        int min = pos;
        if (2*pos <= heapSize && heap[2*pos].freq < heap[min].freq) {
            min = 2 * pos;
        }
        if (2*pos+1 <= heapSize && heap[2*pos+1].freq < heap[min].freq) {
            min = 2 * pos + 1;
        }

        if (min != pos) {
            HeapNode temp = heap[pos];
            heap[pos] = heap[min];
            heap[min] = temp;
            bubbleDown(min);
        }
    }
}

 
/*Initialize Heap*/
void heapInit() {
    heapSize = 0;
    heap[0].c = 0;
    heap[0].t_node = NULL;
    heap[0].freq = 0;
}

/* 
 * To insert a new node into the heap 
 * 1. The size of the heap is increased by 1
 * 2. The new element is inserted as the last element of the heap 
 * 3. Sift up the new element (swim/bubble up operation) until the heap property has been reestablished.
 */
void HeapInsert(char c, huffman_tree_node *t, int freq) {
    heapSize++;
    heap[heapSize].c = c;
    heap[heapSize].t_node = t;
    heap[heapSize].freq = freq;
    bubbleUp(heapSize);
}
 
/* 
 * heap[1] is the root of the heap and contains the minimum node. To remove root, 
 * 1. the content of heap[1] is copies to an return struct. 
 * 2. the last element of the heap heap[heapSize] is copied to the root.
 * 3. the size of the heap is decreased by 1. 
 * 4. sift down the new root (sink/tri operation) to reestablish the heap property.
 * 5. return the old heap[1] stored in the return struct/
 * Note that, heap[0] is NOT used in this heap implementation 
 */
HeapNode DeleteMin() {
    HeapNode output = heap[1];
    heap[1] = heap[heapSize];
    heapSize--;
    bubbleDown(1);
    return output;
}
 
void heapPrint()  {
    int  i;
    printf("\n----------------\n  HEAP BEGIN\n-----------------\n");
    for (i = 1; i <= heapSize; i++) {
        printf("%d ", heap[i].c);
	if(isprint(heap[i].c)) 
		printf("(%c)", heap[i].c);
	else 
		printf("(--)");
        printf("%d\n", heap[i].freq);
    }
    printf("\n----------------\n  HEAP END\n-----------------\n");
}



/****************************************************************
 *
 * Debuggine Code for the heap data structure
 * Compile this code with 
 *
****************************************************************/

#ifdef TEST
int main() {
    heapInit();

        HeapInsert('a', NULL, 44);
        HeapInsert('b', NULL, 32);
        HeapInsert('d', NULL, 99);
        HeapInsert('f', NULL, 43);
        HeapInsert('u', NULL, 51);
        HeapInsert('y', NULL, 1);

    heapPrint();

    DeleteMin();
    heapPrint();

    DeleteMin();
    heapPrint();
    
    return 0;
}
#endif // TEST
