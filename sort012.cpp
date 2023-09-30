#include<iostream>
using namespace std;
void printArray(int arr[], int n){
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
}

void sortArray(int arr[], int n){
    int c1 = 0, c2 = 0, c3 = 0;

    for(int i=0; i<n; i++){
       if(arr[i] == 0) c1++;
       if(arr[i] == 1) c2++;
       if(arr[i] == 2) c3++;
    }
}

int main(){
    int arr[9] = {0,1,1,0,2,2,2,0,2};
    sortArray(arr, 9);
    printArray(arr, 9);

    return 0;
}