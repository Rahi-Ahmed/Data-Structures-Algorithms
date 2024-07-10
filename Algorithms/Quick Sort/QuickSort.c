
// an element is in the sorted position if all the elements on the left hand side should be smaller and all the elements on right side (after the element) should be bigger than that element
// 10 80 90 60 30 20 (10 is in the sorted position)
// 6 3 5 4 2 1 9 (9 is in the sorted position)
// 4 6 7 10 16 12 13 14 (10 is in the sorted position)
// Quick Sort follows divide and conquer strategies

#include <stdio.h>

int partition(int a[], int low, int high){
    int pivot = a[low];
    int i = low + 1;
    int j = high;

    while(1){
        while(a[i] <= pivot && i <= high){
            i++;
        }
        while(a[j] > pivot && j >= low){
            j--;
        }
        if(i < j){
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }else{
            break;
        }
    }

    int temp = a[low];
    a[low] = a[j];
    a[j] = temp;

    return j;
}

void quick_sort(int a[], int low, int high){
    if(low < high){
        int j = partition(a, low, high);
        quick_sort(a, low, j-1);
        quick_sort(a, j+1, high);
    }
}

void print_array(int a[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int main(void){
    int a[] = {10, 16, 8, 12, 15, 6, 3, 9, 5};
    int n = sizeof(a) /sizeof(a[0]);

    quick_sort(a, 0, n-1);
    print_array(a, n);



}

