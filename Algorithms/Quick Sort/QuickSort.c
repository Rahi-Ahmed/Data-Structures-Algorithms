
// an element is in the sorted position if all the elements on the left hand side should be smaller and all the elements on right side (after the element) should be bigger than that element
// 10 80 90 60 30 20 (10 is in the sorted position)
// 6 3 5 4 2 1 9 (9 is in the sorted position)
// 4 6 7 10 16 12 13 14 (10 is in the sorted position)
// Quick Sort follows divide and conquer strategies

#include <stdio.h>

int partition(int a[], int p, int q) {
    int pivot = a[p];
    int i = p - 1;
    int j = q + 1;

    while(i < j){
        do{
            i++;
        }while(a[i] < pivot);

        do{
            j--;
        }while(a[j] > pivot);

        if(i < j){
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }

    }

    return j;
}

void quick_sort(int list[], int p, int q) {
    if (p < q) {
        int r = partition(list, p, q);
        quick_sort(list, p, r);
        quick_sort(list, r + 1, q);
    }
}

void print_array(int a[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int main() {
    int listSize;
    printf("Enter the size of the array: ");
    scanf("%d", &listSize);

    int a[listSize];
    printf("Enter the elements of the array: ");
    for(int i = 0; i < listSize; i++){
        scanf("%d", &a[i]);
    }

    quick_sort(a, 0, listSize - 1);
    print_array(a, listSize);

    return 0;
}
