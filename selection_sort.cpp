#include<iostream>
using namespace std;

void printArray(int arr[], int n){
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
}

void selectionSort(int arr[], int n){
    for(int i=0; i<n-1; i++){
    int minIndex = i;



  for(int j= i+1; j<n; j++){
        if(arr[j] < arr[minIndex])
        minIndex = j;
        //swap(arr[j], arr[minIndex]);
  }

     swap(arr[i], arr[minIndex]);
    }

}

int main(){

    int arr[5] = {3,1,9,5,2};

     selectionSort(arr, 5);
     printArray(arr, 5);
    
    return 0;
}