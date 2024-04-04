#include <bits/stdc++.h>
using namespace std;

vector<int> A;

void Merge(int low,int mid, int hi)
{
    int m=mid-low+1;
    int n=hi-mid;
    int l[m+1],r[n+1];
    for(int i=0; i<m; i++)
        l[i]=A[low+i];
    for(int j=0; j<n; j++)
        r[j]=A[mid+j+1];
    l[m]=INT_MAX; //for descending INT_MIN
    r[n]=INT_MAX; //for descending INT_MIN
    int i=0,j=0;
    for(int k=low; k<=hi; k++)
    {
        if(l[i]<=r[j]) //for descending >=
        {
            A[k]=l[i];
            i++;
        }
        else
        {
            A[k]=r[j];
            j++;
        }
    }
}

void MergeSort(int low, int hi)
{
    //if(low==hi) return;
    //eivabeo base condition dewa jabe mane low r hi equal means sob element break sesh
    if(low<hi)
    {
        int mid=(hi+low)/2;
        MergeSort(low,mid);
        MergeSort(mid+1,hi);
        Merge(low,mid,hi);
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
    MergeSort(0,size-1);
    for (int i = 0; i < size ; i++)
    {
        cout<<A[i]<<" ";
    }
}
