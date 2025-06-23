#include<stdio.h>
#include<stdbool.h>
// 有只龟叫插冒龟（插入、冒泡，归并），它很稳；基（基数）你太稳，希尔不稳

// 插排：n/n^2/n^2
void insert_sort(int arr[], int len){
    for (int i = 1; i < len; i++){
        int temp = arr[i];
        int j = i-1;
        while(j >= 0 && arr[j] > temp){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = temp;
    }
}

// 折半插排:n/n^2/n^2
void binary_insert_sort(int arr[], int len){
    for (int i = 1; i < len; i++){
        int target = arr[i];
        int left = 0;
        int right = i-1;
        if (target > arr[right]) continue;
        while(left <= right){       // 易错
            int middle = (left + right)/2;
            if (arr[middle] <= target) left = middle+1;
            else right = middle-1;
        }
        for(; i > right; i--){
            arr[i] = arr[i-1];
        }
        arr[left] = target;
    }
}

// 希尔排序：n/n^2/n^1.3
void shell_sort(int arr[], int len){
    for (int d = len/2; d >= 1; d/=2){      // 增量
        for (int i = 0; i < d; i++){        // 组间遍历
            for (int j = i+d; j < len; j+=d){       // 组内遍历
                int temp = arr[j];
                int k = j-d;
                while(k >= 0 && arr[k] > temp){
                    arr[k+d] = arr[k];
                    k -= d;
                }
                arr[k+d] = temp;
            }
        }
    }
}

// 冒泡排序：n/n^2/n^2
void bubble_sort(int arr[], int len){
    for(int i = 0; i < len; i++){
        bool flag = true;
        for (int j = 0; j < len-1-i; j++){
            if (arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                flag = false;
            }
        }
        if (flag) return;
    }
}

// 快速排序：
int partition(int arr[], int left, int right){
    int pivot = arr[right];
    int i = left-1;
    for (int j = left; j <= right; j++){
        if (arr[j] > pivot) continue;
        i++;
        int temp = arr[j];
        arr[j] = arr[i];
        arr[i] = temp;
    }
    return i;
}
void quick_sort(int arr[], int left, int right){
    if (right > left){
        int pi = partition(arr, left, right);
        quick_sort(arr, left, pi-1);
        quick_sort(arr, pi+1, right);
    }
}

// 选择排序
void select_sort(int arr[], int len){   // 在剩余数组中选最小的
    for (int i = 0; i < len-1; i++){
        int min = i;
        for (int j = i+1; j < len; j++){
            if (arr[min] > arr[j]) min = j;
        }
        if (min != i){
            int temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
        }
    }
}

// 树形选择排序

// 推排序



int main(){
    int arr[] = {10, 8, 11, 7, 4, 12, 9, 6, 5, 3, 2, 1};
    quick_sort(arr, 0, sizeof(arr) / sizeof(arr[0])-1);
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}