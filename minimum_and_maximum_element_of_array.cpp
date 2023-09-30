#include<iostream>
using namespace std;

int main(){

    int arr[6] = {3 ,2, 1, 56, 1000, 167};

    int max = 0;
    int min = arr[0];
    
    for(int i=0; i<6; i++){
        if(arr[i]>max) 
        max = arr[i];
    }
    for(int i=0; i<6; i++){
        if(arr[i]<min) 
        min = arr[i];
    }

    cout<<max<<endl<<min;
    
    
    return 0;
}