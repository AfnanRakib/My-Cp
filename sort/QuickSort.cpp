#include <bits/stdc++.h>
using namespace std;

vector<int> A;

int Partition(int low, int hi){
    int pivot=A[low];
    int i=low;
    int j=hi;
    while(i<j){//i jtkkn j er choto ttkkn traverse
        while(A[i]<=pivot)//pivot theke boro value pelei stop
            i++; //for descending >=
        while(A[j]>pivot)//pivot theke choto value pelei stop
            j--; //for descending <
        if(i<j)//i j er chaite choto hole swap boro hole
//loop theke ber hoye pivot er sathe swap
            swap(A[i],A[j]);
    }
    swap(A[low],A[j]);
    // basicallly pivot jodi low k dhori tkn
    //pivot bad diye er dan side e pivot er chaite choto theke
//aste aste pivot er chaite boro er dike jai erkm sajabo
    //sajano complete hole i&j jekhane cross korbe okhanei pivot bosbe
    //eivabe pivot tar perfect position e bosbe
    return j;//eita pivot er position etar maddhome partition hobe 2 side e
}

void QuickSort(int low,int hi){
    if(low<hi){
        int pos=Partition(low,hi);
        QuickSort(low,pos-1);
        QuickSort(pos+1,hi);
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
    QuickSort(0,size-1);
    for (int i = 0; i < size ; i++){
        cout<<A[i]<<" ";
    }
    return 0;
}
