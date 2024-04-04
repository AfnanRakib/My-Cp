#include <bits/stdc++.h>
using namespace std;

void Insertion_Sort(vector<int>& A, int n)
{
    for(int i=1;i<n;i++){
        int key=A[i];
        int j=i-1;
        while (A[j] < key && j >= 0){
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
    vector<int> A(size);
    for (int i = 0; i < size ; i++){
        cin >> A[i];
    }
    Insertion_Sort(A, size);
    for (int i = 0; i < A.size(); i++){
        cout << A[i] << ' ';
    }
    cout << endl;
}
