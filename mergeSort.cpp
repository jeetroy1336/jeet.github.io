#include<iostream>
using namespace std;

void merge(int *arr, int start, int end){
    
    int mid = (start + end)/2;
    
    int size1 = mid - start + 1;
    int size2 = end - mid;
    
    int array1[size1];
    int array2[size2];
    
    int k1 = start;
    for (int i = 0; i < size1; i++){
        array1[i] = arr[k1++];
    }
    
    int k2 = mid+1;
    for (int i = 0; i < size2; i++){
        array2[i] = arr[k2++];
    }
    
    // merge arrays
    int i = 0, j = 0, k = start;
    
    while (i < size1 && j < size2){
        
        if (array1[i] < array2[j]){
            arr[k++] = array1[i++];
        }
        else{
            arr[k++] = array2[j++];
        }
    }
    
    while (i < size1){
        arr[k++] = array1[i++];
    }
    
    while (j < size2){
        arr[k++] = array2[j++];
    }
}

void mergeSort(int *arr, int start, int end){
    
    if (start >= end){
        return;
    }
    
    int mid = (start + end)/2;
    
    mergeSort(arr, start, mid);
    mergeSort(arr, mid+1, end);
    
    merge(arr, start, end);
}

void printArray (int *arr, int n){
    for (int i = 0; i < n; i++){
        cout<<arr[i] <<" ";
    }
}

int main(){
    
    int arr[10] = {56,78,90,12,23,435,43,32,21,66};
    
    mergeSort(arr, 0, 10);
    printArray(arr, 10);
    
    return 0;
}
