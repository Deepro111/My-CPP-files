#include<iostream>
using namespace std;
void printArray(int arr[], int n){
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
}

void sortArray(int arr[], int n){
    int left = 0, right = n-1;

    while(left<right){
        if(arr[left] == 0 && left<right){
             left++;
        }
        if(arr[right] == 2 && left<right){
            right--;
        }

    } 
      if(left<right && arr[left]!=0 || arr[right]!=2){
        arr[left] =1;
      }
}

int main(){
    int arr[9] = {0,1,1,0,2,2,2,0,2};
    sortArray(arr, 9);
    printArray(arr, 9);

    return 0;
}