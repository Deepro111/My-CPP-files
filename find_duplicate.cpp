#include<iostream>
using namespace std;

int main(){
    int arr[2] = {1,3};
    int ans = 0;

    for(int i=0; i<2; i++){
        ans = ans^arr[i];
    }

    for(int i=1; i<=2; i++){
        ans = ans^i;
    }

    cout<<ans;
    return 0;
}