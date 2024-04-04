#include <bits/stdc++.h>
using namespace std;

/*
4 3
0 1
1 2
2 3
false

4 4
0 1
1 2
2 3
3 0
true
*/
bool detect(int src, vector<int> adj[], int vis[]) {
    vis[src] = 1;
    // store <source node, parent node>
    queue<pair<int,int> > q;
    q.push(make_pair(src, -1));
    while(!q.empty()) {
      int node = q.front().first;
      int parent = q.front().second;
      q.pop();

      // go to all adjacent nodes
      for(auto adjacentNode: adj[node]) {
          // if adjacent node is unvisited
          if(!vis[adjacentNode]) {
              vis[adjacentNode] = 1;
              q.push(make_pair(adjacentNode, node));
          }
          // if adjacent node is visited and is not it's own parent node
          else if(parent != adjacentNode) {
              // yes it is a cycle
              return true;
          }
      }
    }
    // there's no cycle
    return false;
}

bool isCycle(int V, vector<int> adj[]) {
    // initialise them as unvisited
    int vis[V];
    for(int i = 0;i<V;i++)
        vis[i]=0;
    //these codes if the graph has multiple components
    for(int i = 0;i<V;i++) {
        if(!vis[i]) {
            if(detect(i, adj, vis)) return true;
        }
    }
    return false;
}


int main() {

    int n, m;
	cin >> n >> m;
	vector<int> adj[n];

	for(int i = 0;i<m;i++) {
	    int u, v;
	    cin >> u >> v;
	    adj[u].push_back(v);
	    adj[v].push_back(u);
	}

    if(isCycle(n, adj))
        cout << "true";
    else
        cout << "false";
    return 0;
}
