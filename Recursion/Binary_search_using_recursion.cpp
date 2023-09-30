#include<iostream>
using namespace std;

int BinarySearch(int arr[], int s ,int e, int n, int k){
    if(n == 0 || n == 1){
        return arr[0];
    }

    int mid = e - (s + e)/2;
    while(s<=e){
    if(k == arr[mid]){
        return mid;
    }
    if(k > arr[mid]){
       BinarySearch(arr, mid+1, e,n,k);
    }
    else if(k < arr[mid]){
        BinarySearch(arr, s, mid-1,n,k);
    }
}
}

int main(){

    int arr[] = {9,7,6,8,4};

   int ans = BinarySearch(arr, 0 , 4, 5, 7);

    cout<<ans;
    
    return 0;
}