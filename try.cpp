// #include<iostream>
// #include<vector>
// using namespace std;

// int main(){
//     int maxi = INT_MIN;
//     int mini = INT_MAX;
//     vector<int> salary;

//     salary.push_back(8000);
//     salary.push_back(9000);
//     salary.push_back(2000);
//     salary.push_back(3000);
//     salary.push_back(6000);
//     salary.push_back(1000);
    
//      for(int i=0; i<salary.size(); i++){
//             cout<<salary[i]<<" ";
//             maxi = max(maxi, salary[i]);
//             mini = min(mini, salary[i]);
//         }cout<<endl;

//         cout<<maxi<<" "<<mini<<endl;

//         int sum = 0;
//         int count = 0;
//         for(int i=0; i<salary.size(); i++){
//             if(salary[i] != mini || salary[i] != maxi){
//                 sum+=salary[i];
//                 count++;
//             }
//         }

//         double ans = sum/4;

//         cout<<ans;
//     return 0;
// }
 
#include<iostream>
using namespace std;

int main(){

    int arr1[3][2] = {{2,6}, {3,1}, {1,0}};
    int arr2[2][3] = {{5,1,7}, {1,4,9}};
    int arr3[3][3] = {0};

    int element = 0;

    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            for(int k=0; k<2; k++){
                element+=arr1[i][k]*arr2[k][j];
                arr3[i][j] = element;
                
            }
            element = 0;
        }
    }

    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            cout<<arr3[i][j]<<" ";
        }
        cout<<endl;
    }
}
