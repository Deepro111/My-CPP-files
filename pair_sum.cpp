#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector< vector<int> > ans;
    
    int arr[5] = {1,4,2,3,5};
    int s = 5;
    for(int i=0; i<5; i++){
        for(int j =i+1; j<5; j++){
            if(arr[i]+arr[j] == s){
                vector<int> temp;
                temp.push_back(min(arr[i], arr[j]));
                temp.push_back(max(arr[i], arr[j]));
                ans.push_back(temp);
            }
        }
    }
      cout<<ans;
    return 0;
}