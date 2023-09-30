#include<iostream>
using namespace std;

int getpivot(int arr[], int n){
    int s=0;
    int e = n-1;

    int mid = s + (e-s)/2;

    while(s<e){

        if(arr[mid] >= arr[0]){ // Here if our arr[mid] will be greater than or equal to arr[0]
            s = mid+1;         //then we will shift our start to mid+1 to go to another line which has pivot element
        }
        else{
            e = mid;  //if above condition is not true then we will shift our end to mid and not to "mid-1" to keep us on the line that contain pivot element
        }
        mid = s + (e-s)/2;
    }
    return s;   // Here we can also return s
}

int main(){

    int arr[4] = {11,13,15,17};

    cout<<"Pivot element is at index "<<getpivot(arr, 4)<<endl;
    
    return 0;
}