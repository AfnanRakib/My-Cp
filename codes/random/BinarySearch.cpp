#include <bits/stdc++.h>
using namespace std;

int Binary_Search(vector<int> A, int n, int key)
{
    int l,h,m;
    l=0;
    h=n-1;
    while (l<=h)
    {
        m=(l+h)/2;
        if(A[m]==key)
            return m;
        else if(A[m]<key)
            l=m+1;
        else
            h=m-1;
    }
    return -1;
}

int Lower_Bound(vector<int> A, int n, int key)
{
    int l,h,m,lb;
    l=0;
    h=n-1;
    while (l<=h)
    {
        m=(l+h)/2;
        if(A[m]<key)
            l=m+1;
        else if(A[m]>=key){
            lb=m;
            h=m-1;
        }
    }
    return lb;
}

int Upper_Bound(vector<int> A, int n, int key)
{
    int l,h,m,ub;
    l=0;
    h=n-1;
    while (l<=h)
    {
        m=(l+h)/2;
        if(A[m]<=key)
            l=m+1;
        else if(A[m]>key){
            ub=m;
            h=m-1;
        }
    }
    return ub;
}

int main()
{
    int size,key;
    cin >> size >> key;
    vector<int> A(size);
    for (int i = 0; i < size ; i++)
    {
        cin >> A[i];
    }
    int res =Binary_Search(A, size, key);
    cout<<"item found at index: "<< res <<endl;

    res = Lower_Bound(A, size, key);
    cout<<"Lower Bound: "<< res <<endl;

    res = Upper_Bound(A, size, key);
    cout<<"Upper Bound: "<< res <<endl;

    return 0;
}
