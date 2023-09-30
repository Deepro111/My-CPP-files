#include<iostream>
using namespace std;

void printArray(int arr[], int n){
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }cout<<endl;
}

void insertionSort(int arr[], int n){
        for(int i=1; i<n; i++){
            int store = arr[i];
                 int j=i-1;
            for(; j>=0; j--){
                if(arr[j]>store){
                    arr[j+1] = arr[j];
                }
                else{
                    break;
                }
            }
            arr[j+1] = store;
            }
        }


int main(){

    int arr[7] = {4,5,1,3,2,9,0};
    printArray(arr, 7);
    insertionSort(arr, 7);
    printArray(arr, 7);
    return 0;
}