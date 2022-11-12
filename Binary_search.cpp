#include <iostream>
using namespace std;

int binarysearch(int arr[], int n, int key)
{
    int start = 0;
    int end = n - 1;

    int mid = start + (end - start) / 2; // finding mid element

    while (start <= end)
    {
        if (arr[mid] == key)
        {               // this is our first condition, if we found our key's match here only
            return mid; // we will simply return from here only
        }

        // Another possible conditions if we didn't find our match in above condition only

        if (key > arr[mid])
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }

        mid = start + (end - start) / 2; // updating our middle element
    }

    return -1;
}

int main()
{

    int arr[8] = {1,3,4,5,6,7,8,9};
    int key;
    cin>>key;

    int Index = binarysearch(arr, 8, key);

    cout << "Index of "<< key <<" is " << Index;

    return 0;
}