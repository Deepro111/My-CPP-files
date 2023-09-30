#include <iostream>
using namespace std;

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

void BubbleSort(int arr[], int n)
{

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] > arr[j])
                swap(arr[i], arr[j]);
        }
    }
}

int main()
{

    int arr[9] = {9, 1, 1, 6, 4, 3, 8, 5, 2};

    BubbleSort(arr, 9);
    printArray(arr, 9);

    return 0;
}