#include<iostream>
using namespace std;

int main(){
    
     int n;
     cin >> n;

     int i = 1;

     while(i <= n){
       // Firstly, Print the space required
        int space = n-i;
        while(space){
            cout << " ";
            space = space - 1;
        }

        // Now Print stars
        int j = 1;
        while(j <= i){
            cout << "*";
            j++;
        }
        cout << endl;
        i++;
     }

    return 0;
}