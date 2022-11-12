#include <iostream>
using namespace std;

int findsqrt(int n)
{
    int s = 0;
    int e = n;
    int mid = s + (e - s) / 2;
    int ans = -1;
    while (s <= e)
    {
        int square = mid * mid;
        if (square == n)
        {
            return mid;
        }
        else if (square < n)
        {
            ans = mid;
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }

        mid = s + (e - s) / 2;
    }
    return ans;
}

double completesqrt(int n, int precision, int answer){
        double factor = 1;
        double ans = answer;

        for(int i=0; i<precision; i++){
            factor = factor/10;
            for(double j=ans; j*j<n; j+=factor){
                ans = j;
        }
}
    return ans;
}

int main()
{
    int n;
    cout<<"Enter the number you want square root of : "<<endl;
    cin>>n;
    int answer = findsqrt(n);

    cout <<"Square Root of entered number is : " << completesqrt(n, 5, answer);

    return 0;
}