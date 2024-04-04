/*
    Md. Rakib Hasan
    id: 20210204027

sample input:
5
1 rakib 4
2 tajrin 4
3 rafin 4
4 prerona 3
5 dipto 3.5

output:
4 prerona 3
5 dipto 3.5
3 rafin 4
1 rakib 4
2 tajrin 4
*/

#include <bits/stdc++.h>
using namespace std;

struct student
{
    int id;
    string name;
    double cgpa;
} stu;

vector<student> A;

void NameSort(int n){
    for(int i=0; i<n;i++)
    {
        int j=i+1;
        while((j<n) && (A[i].cgpa==A[j].cgpa)){
            if(A[i].name>A[j].name)
                swap(A[i],A[j]);
            j++;
        }
    }
}

void Merge(int low,int mid, int hi)
{
    int m=mid-low+1;
    int n=hi-mid;
    student l[m+1],r[n+1];
    for(int i=0; i<m; i++)
        l[i]=A[low+i];
    for(int j=0; j<n; j++)
        r[j]=A[mid+j+1];

    stu.id = 0;
    stu.name = " ";
    stu.cgpa = DBL_MAX; //for descending DBL_MIN
    l[m] = stu;
    r[n] = stu;

    int i=0,j=0;
    for(int k=low; k<=hi; k++)
    {
        if(l[i].cgpa<=r[j].cgpa) //for descending >=
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

void MergeSort(int low, int high)
{
    if (low < high){
        int mid = (low + high) / 2;
        MergeSort(low, mid);
        MergeSort(mid + 1, high);
        Merge(low, mid, high);
    }
}

int main()
{
    int size;
    cin>>size;
    for(int i=0; i<size; i++)
    {
        cin>>stu.id>>stu.name>>stu.cgpa;
        A.push_back(stu);
    }
    MergeSort(0,size-1);
    NameSort(size);
    cout<<"After Sorting******************"<<endl;
    for(int i=0; i<size; i++)
        cout<<A[i].id<<" "<<A[i].name<<" "<<A[i].cgpa<<endl;
    return 0;
}
