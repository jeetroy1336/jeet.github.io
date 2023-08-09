#include<iostream>
using namespace std;;

int binarySearch(int arr[],int n, int element){
    int lowerBound = 0;
    int upperBound = n-1;
    int index;

    while(lowerBound <= upperBound){
        int mid = (lowerBound + upperBound)/2;

        if (arr[mid] == element){
            index = mid;
            break;
        }
        else if (arr[mid] < element){
            lowerBound = mid+1;
        }
        else if (arr[mid] > element){
            upperBound = mid - 1;
        }
    }
    return index;
}
int main(){

    int n,element;
    cout<<"\nEnter the size of array: ";
    cin>>n;

    int arr[n];

    cout<<"Enter the elements of array: ";
    for (int i = 0;i < n;i++){
        cin>>arr[i];
    }
    cout<<"Enter the element you are searching for: ";
    cin>>element;

    cout<<"Element found on index : "<<binarySearch(arr,n,element);
    return 0;
}
