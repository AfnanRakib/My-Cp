#include<bits/stdc++.h>
using namespace std;
/*
4
5
2 3
3 4
4 5
5 6
0       0       0       0       0       0
0       0       3       3       3       3
0       0       3       4       4       7
0       0       3       4       5       7
0       0       3       4       5       7
1 1 0 0
*/
void knapsack(vector<vector<int>> &V, vector<pair<int,int>> b, int W, int n)
{
    for(int i=0; i<=W; i++)//first row 0
        V[0][i] = 0;
    for(int i = 0; i <= n; i++)//first col 0
        V[i][0] = 0;
    for(int i=1; i<=n; i++){//row traverse
        for(int w=1; w<=W; w++){//col traverse
            int wi=b[i].first;
            int bi=b[i].second;
            if(wi<=w){//current item weight <= current bag capacity
                if(bi + V[i-1][w-wi] > V[i-1][w])//check if getting more benefit
                    V[i][w] = bi + V[i-1][w-wi];
                else
                    V[i][w] = V[i-1][w];
            }
            else
                V[i][w] = V[i-1][w];
        }
    }
}

void find_item(vector<vector<int>> &V,vector<pair<int, int>> b, int W, int n)
{
    vector<bool> item(n+1);//item taking flag array
    int i=n,j=W;
    while(i != 0){
        if(V[i][j] != V[i-1][j]){//if value changes in current row then take it
            item[i]=true;
            j=j-b[i].first;//update remaining capacity
            i=i-1;//update remaining item
        }
        else
            i=i-1;
    }
    for(int i=1; i<=n; i++)
        cout<<item[i]<<" ";
}

int main()
{
    int n,w;
    cout<<"Item number: ";
    cin>>n;
    cout<<"Capacity of knapsack: ";
    cin>>w;

    vector<pair<int,int>> b(n+1);//weight,benefit
    vector<vector<int>> V(n+1,vector<int> (w+1));//v matrix row=item+1, col=capacity+1

    cout<<"Weight,Price" << endl;
    for(int i=1; i<=n; i++){
        int x,y;
        cin>>x>>y;
        b[i]={x,y};
    }
    knapsack(V,b,w,n);
    //print matrix
    for(int i=0; i<=n; i++){
        for(int j=0; j<=w; j++)
            cout<<V[i][j]<<"\t";
        cout<<endl;
    }
    //print item taking array
    find_item(V,b,w,n);
}
