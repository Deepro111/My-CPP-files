// #include<bits/stdc++.h>
// using namespace std;



// int main(){




// long long max_sum = -1;
// 	    long long cur_sum = 0;
// 	    int max_range_left = -1;
// 	    int max_range_right = -1;
// 	    int cur_range_left = 0;
// 	    int cur_range_right = 0;
// 	    while (cur_range_right < n) {
// 	        if (a[cur_range_right] < 0) {
// 	            cur_range_left = cur_range_right + 1;
// 	            cur_sum = 0;
// 	        } else {
// 	            cur_sum += (long long)a[cur_range_right];
// 	            if (cur_sum > max_sum) {
// 	                max_sum = cur_sum;
// 	                max_range_left = cur_range_left;
// 	                max_range_right = cur_range_right;
// 	            } else if (cur_sum == max_sum) {
// 	                if (cur_range_right + 1 - cur_range_left >
// 	                    max_range_right + 1 - max_range_left) {
// 	                    max_range_left = cur_range_left;
// 	                    max_range_right = cur_range_right;
// 	                }
// 	            }
// 	        }
// 	        cur_range_right++;
// 	    }
// 	    vector<int> ans;
// 	    if (max_range_left == -1 || max_range_right == -1) {
// 	        ans.push_back(-1);
// 	        return ans;
// 	    }

// 	    for (int i = max_range_left; i <= max_range_right; ++i) ans.push_back(a[i]);
	   


// }


#include<iostream>
#include<vector>
using namespace std;

int main(){
    string s = "1,2,3";
    cout<<s.size()<<endl;
   vector<int> ans((s.size())/2 + 1);

    for(auto i = 0; i<s.size(); i++){
        if(s[i]>='0'){
          ans.push_back(s[i]);
        }
    }
    return 0;
}