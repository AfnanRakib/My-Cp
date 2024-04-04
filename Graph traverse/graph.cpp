#include <bits/stdc++.h>
using namespace std;

/*
5 6
1 2 11
2 3 12
1 3 13
2 4 14
3 4 15
3 5 16
*/

int main(){
    int node,edge;
    cin>>node>>edge;
    vector<vector<int> > v_node(node+1);
    vector<vector<int> > weight(node+1);

    for(int i=1;i<edge+1;i++){
        int a,b,w;
        cin>>a>>b>>w;
        v_node[a].push_back(b);
        weight[a].push_back(w);
        v_node[b].push_back(a);
        weight[b].push_back(w);
    }
    for(int i=1;i<node+1;i++){
        cout<<i<<" -> ";
        for(int j=0;j<v_node[i].size();j++){
            cout<<v_node[i][j]<<' ';
        }
        cout<<endl;
        cout<<"Weights: ";
        for(int j=0;j<weight[i].size();j++){
            cout<<weight[i][j]<<' ';
        }
        cout<<endl;
    }
    return 0;
}
