#include<iostream>
using namespace std;

int main(){
    int n;
    cin >> n ;

    int i = 1;
    while(i <= n){

        // Print Space (1st triangle)
        int space = n-i;
        while(space){
            cout << " ";
            space--;
        }

        // Print 2nd triangle
        int j = 1;
        while(j <= i){
            cout << j;
            j++;
        }

        // Print 3rd triangle
        int start = i-1;
        while(start){
            cout << start;
            start--;
        }
           
          cout << endl;
          i++; 

    }
    return 0;
}