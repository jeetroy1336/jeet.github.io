#include<iostream>
using namespace std;

void insertionSort(int arr[], int n){
    
    for (int i = 1; i < n; i++){

        int j = i-1;    int key = arr[i];

        while(j >= 0){

            if (arr[j] > key){
                arr[j+1] = arr[j];  j--;
            }
            else{
                break;
            }
        }
        arr[j+1] = key;
    }   
}
int main(){
    
    int arr[5] = { 4, 1, 3, 9, 7};
    insertionSort(arr, 5);
    
    for (int i = 0; i < 5; i++){
        cout<<arr[i] <<" ";
    }
}
