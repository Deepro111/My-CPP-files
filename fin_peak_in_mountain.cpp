#include <iostream>
using namespace std;

int peak(int arr[], int n)
{

    int start = 0;
    int end = n - 1;
    int mid = start + (end - start) / 2;

    while (start <= end)
    {

        if (arr[mid] < arr[mid + 1])
        {
            start = mid + 1;
        }
        else
        {
            start = mid;
        }
        mid = start + (end - start) / 2;
    }
    return start;
}

int main()
{

    cout<<"Hello";

    int arr[5] = {0,1,2,1,0};


   int mountain = peak(arr, 5);
    cout<<mountain;

   
    

    return 0;
}