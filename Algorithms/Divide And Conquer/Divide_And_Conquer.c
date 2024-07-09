#include <stdio.h>
#include <limits.h>
#include <math.h>

// Function to find the maximum subarray sum using divide and conquer
int sum(int a[], int l, int r) {
    if (l == r) {
        return a[l];
    }

    int mid = (l + r) / 2;

    int left_sum = sum(a, l, mid);
    int right_sum = sum(a, mid + 1, r);

    int left = INT_MIN, right = INT_MIN, sum = 0;

    for(int i = mid+1; i <= r; i++){
        sum += a[i];
        right = fmax(right, sum);
    }

    sum = 0;

    for(int i = mid; i >= l; i--){
        sum += a[i];
        left = fmax(left, sum);
    }

    int ans = fmax(left_sum, right_sum);
    return fmax(ans, left + right);
    //return fmax(ans, left + right);
}

int main() {
    int n;
    printf("Enter the length of the array: ");
    scanf("%d", &n);
    int a[n];

    printf("Enter the element of the array: ");
    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }

    int x = sum(a, 0, n);

    printf("Maximum Subarray Sum: %d\n", x);

    return 0;
}
