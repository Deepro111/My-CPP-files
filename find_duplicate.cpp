#include<iostream>
using namespace std;

int main(){
    int arr[9] = {8,7,2,5,4,7,1,3,6};
    int ans = 0;

    for(int i=0; i<9; i++){
        ans = ans^arr[i];
    }

    for(int i=1; i<9; i++){
        ans = ans^i;
    }

    cout<<ans;
    return 0;
}