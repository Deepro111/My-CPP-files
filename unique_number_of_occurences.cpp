#include<iostream>
using namespace std;

bool unique(int arr[], int n){
    int count[10] ={};
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(arr[i]==arr[j]){
                count[i]++;
            }
    if(count[i]==count[j]){
        return 1;
    }

        }
    }
        return 0;
}

int main(){

    int arr[8]={1,1,9,2,3,4,5,6};
    if (unique){
        cout<<"true";
    }
    else{
        cout<<"false";
    }
   
     unique(arr, 8);
    
    return 0;
}