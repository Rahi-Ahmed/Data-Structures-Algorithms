
// If a Node is at index i
// It's left child is at 2*i
// It's right child is at 2*i+1
// It's parent is at floor(i/2)

// Full Binary Tree: a binary tree with the maximum number of nodes. It has 2^h - 1 node (h = height)

// Complete Binary Tree: There is no gap in array representation of a binary tree from starting to end
// Every Full Binary Tree is Complete Binary Tree, but not every Complete Binary Tree is Full Binary Tree
// The height of a complete binary tree is log(n)

// Heap is a complete binary tree, every nodes having their value greater than or equal to their descendents called max heap (50 30 20 15 10 8 16)
// Min heap is the opposite of max heap. (10 30 20 35 40 32 25)
// Inserting heap takes 0(1) to log(n)

/* Heap Sort has two steps
 * 1. Create a heap
 * 2. Delete all the elements from the heap
 */

// Heap is a faster data structure for priority queue


#include <stdio.h>

void heap_creation(int a[], int n){
    int i = 1;
    while(i < n){
        int j = i;
        while(j >= 0){
            if(a[(j-1)/2] < a[j]){
                int temp = a[(j-1)/2];
                a[(j-1)/2] = a[j];
                a[j] = temp;
            }
            j--;
        }
        i++;
    }
}

//void delete_heap(int a[], int n){
//    int i = 0;
//    int j = 0;
//    while(j < n){
//        int temp = a[i];
//        a[i] = a[n-j-1];
//        a[n-j-1] = temp;
//        heap_creation(a, n-j-2);
//        j++;
//    }
//}

void heap_sort(int a[], int n){
    int i = n-1;
        do {
            int temp = a[0];
            a[0] = a[i];
            a[i] = temp;
            heap_creation(a, i);
            i--;
        }while (i > 0);
}

int main(void){
    int a[] = {12, 10, 20, 19, 8, 7, 15 };
    int n = sizeof(a)/sizeof(a[0]);

    heap_creation(a, n);
    //delete_heap(a, n);
    heap_sort(a, n);

    for(int k = 0; k < n; k++){
        printf("%d ", a[k]);
    }
}
