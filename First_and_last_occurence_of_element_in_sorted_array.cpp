#include<iostream>
using namespace std;

int firstOcc(int arr[], int n, int key){

    int start = 0, end = n-1;
    int mid = start + (end - start) / 2;
    int ans = -1;

    while(start<=end){

        if(arr[mid] == key){
            ans = mid;
            end = mid - 1;
        }
        else if(key > arr[mid]){
            start = mid+1;
        }

        else{
            end = mid - 1;
        }
        mid = start + (end - start) / 2;

       

    } 
     return ans;
}

int lastOcc(int arr[], int n, int key){

    int start = 0, end = n-1;
    int mid = start + (end - start) / 2;
    int ans = -1;

    while(start<=end){

        if(arr[mid] == key){
            ans = mid;
           start = mid + 1;
        }
        else if(key > arr[mid]){
            start = mid+1;
        }

        else{
            end = mid - 1;
        }
        mid = start + (end - start) / 2;

       

    } 
     return ans;
}


int main(){
    int arr[8] = {1,2,4,4,4,4,6,8};

    int foccurence = firstOcc(arr, 8, 4);
    int loccurence = lastOcc(arr, 8, 4);

    cout<<"The first occurence of 4 is at index "<<foccurence<<endl;
    cout<<"The last occurence of 4 is at index "<<loccurence;
    
    return 0;
}