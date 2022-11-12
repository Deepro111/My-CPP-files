#include <iostream>
using namespace std;

int triplet(int arr[], int n, int k)
{

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            for (int m = j + 1; m < n; m++)
            {
                int sum = arr[i] + arr[j] + arr[m];

                if (sum == k)
                {
                    return sum;
                }
            }
        }
    }
    return -1;
}

int main()
{

    int arr[8] = {4, 3, 6, 7, 2, 0, 9, 7};

    int trp = triplet(arr, 8, 16);

    cout << trp;

    return 0;
}