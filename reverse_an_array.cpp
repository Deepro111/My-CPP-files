#include <iostream>
using namespace std;

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

void reverse(int arr[], int n)
{
    for (int i = 0; i < n / 2; i++)
    {

        swap(arr[i], arr[n - i - 1]);
    }
}

int main()
{

    int arr[8] = {1, 2, 3, 4, 5, 6, 7, 8};
    
    reverse(arr, 8);
    printArray(arr, 8);
    return 0;
}