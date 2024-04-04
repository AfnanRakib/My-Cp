#include<bits/stdc++.h>
using namespace std;

vector<int>a(10);

void merge(vector<int>l,vector<int>r)
{
    int m =5,n =5;
    l.push_back(INT_MAX);
    r.push_back(INT_MAX);

    int i=0,j=0;

    for(int k =0; k < (m+n); k++)
    {
        if(l[i] <= r[j])
        {
            a[k] = l[i];
            i++;
        }
        else
        {
            a[k] = r[j];
            j++;
        }
    }
}

int main()
{
    vector<int>l;
    vector<int>r;

    int size =5;

    for (int i = 0; i < size ; i++)
    {
        int x;
        cin >> x;
        l.push_back(x);
    }
    for (int i = 0; i < size ; i++)
    {
        int x;
        cin >> x;
        r.push_back(x);
    }
    merge(l,r);
    for(int s = 0; s < a.size(); s++)
    {
        cout<<a[s]<<" ";
    }
    return 0;
}
