#include <stdio.h>

void insertion_sort(int a[], int n){

    // Using While loop
//    int i = 1;
//    while (i < n){
//        int temp = a[i];
//        int j = i;
//        while(j > 0 && a[j-1] > temp){
//            a[j] = a[j-1];
//            j--;
//        }
//        a[j] = temp;
//        i++;
//    }

    // using for loop
    for(int i = 1; i < n; i++){
        int temp = a[i];
        int j;
        for(j = i; j > 0 && a[j-1] > temp; j--){
            a[j] = a[j-1];
        }
        a[j] = temp;
    }

    for(int i = 0; i < n; i++){
        printf("%d ", a[i]);
    }
}

int main(){
    int a[5] = {3, 1, 5, 4, 2};

   insertion_sort(a, 5);

}