#include<iostream>
using namespace std;

void printArray(int arr[], int n){
    for(int i=0; i<n; i++){
        cout<< arr[i] <<" ";
    }
}

void swapAlternate(int arr[], int size){
    for(int i=0; i<size; i+=2){
        if(i+1<size){
            int temp = arr[i];
            arr[i] = arr[i+1];
            arr[i+1] = temp;
        }
    }
}

int main(){
    int arr[7] = {6,8,0,4,2,9,7};

    swapAlternate(arr, 7);
    printArray(arr, 7);

    return 0;
}