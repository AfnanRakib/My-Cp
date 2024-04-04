#include<bits/stdc++.h>
using namespace std;
#define INF 1e5

/*
5 9
1 2 3
1 5 -4
1 3 8
2 4 1
2 5 7
3 2 4
4 3 -5
4 1 2
5 4 6
1 2
Final DIstance Matrix:
0       1       -3      2       -4
3       0       -4      1       -1
7       4       0       5       3
2       -1      -5      0       -2
8       5       1       6       0
FInal Predecessor Matrix:
-1      3       4       5       1
4       -1      4       2       1
4       3       -1      2       1
4       3       4       -1      1
4       3       4       5       -1
What path you want?:
1 2
Path: 1 5 4 3 2
Cost: 1
*/

vector<vector<int>> pre(100, vector<int>(100, -1));
vector<vector<int>> dist(100, vector<int>(100, INF));

void go(int src,int dest){
    if (src==dest)
        cout<<src<<" ";
    else if (pre[src][dest]==-1)
        cout<<"There is no path from "<< src <<"->"<<dest<< endl;
    else{
        go(src, pre[src][dest]);
        cout<<dest<<" ";
    }
}
void floyd_warshell(int n)
{
    for (int k = 1; k <= n; k++){
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= n; j++){
                if (dist[i][j] > dist[i][k] + dist[k][j]){
                    dist[i][j] = dist[i][k] + dist[k][j];
                    pre[i][j] = pre[k][j];
                }
            }
        }
    }
}

int main()
{
    int node,edge;
    cin>>node>>edge;
    for (int i=1;i<=node;++i){
        dist[i][i]=0;
    }
    cout<<"Source : Destination : Weight"<<endl;
    for(int i=1;i<=edge;i++){
        int s, d, w;
        cin>>s>>d>>w;
        dist[s][d]=w;
        pre[s][d]=s;
    }
    floyd_warshell(node);
    cout<<"Final DIstance Matrix:"<<endl;
    for (int i=1;i<=node;++i){
        for (int j=1;j<=node;++j){
            if (dist[i][j]==INF)
                cout<<"INF\t";
            else
                cout << dist[i][j] << "\t";
        }
        cout << endl;
    }
    cout<<"FInal Predecessor Matrix:"<<endl;
    for (int i=1;i<=node;++i){
        for (int j=1;j<=node;++j){
            cout << pre[i][j] << "\t";
        }
        cout << endl;
    }
    cout<<"What path you want?:"<<endl;
    int src,dest;
    cin>>src>>dest;
    cout<<"Path: ";
    go(src,dest);
    cout<<endl<<"Cost: "<<dist[src][dest];
    return 0;
}
