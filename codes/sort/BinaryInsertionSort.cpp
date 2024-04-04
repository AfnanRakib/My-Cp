#include <bits/stdc++.h>
using namespace std;

vector<int> A;

int BinarySearch(int low, int high, int key)
{
    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (key == A[mid])
            return mid + 1;

        if (key > A[mid])
            low = mid + 1;
        else
            high = mid - 1;
    }

    if (key > A[low])
        return low + 1;
    else
        return low;
}

void InsertionSort(int n)
{
    for(int i=1;i<n;i++){
        int key=A[i];
        int j=i-1;
        int pos=BinarySearch(0,j,key);
        while (j >= pos)
        {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = key;
    }
}

int main()
{
    int size;
    cin >> size;
    for (int i = 0; i < size ; i++)
    {
        int x;
        cin >> x;
        A.push_back(x);
    }
    InsertionSort(size);
    for (int i = 0; i < size ; i++){
        cout<<A[i]<<" ";
    }
}
