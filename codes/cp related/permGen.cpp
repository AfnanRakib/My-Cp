#include<bits/stdc++.h>
using namespace std;

#define INF      1e18+9
#define PI       acos(-1.0)
#define ll       long long
#define ull      unsigned long long
#define sp       ' '
#define vi       vector<int>
#define vll      vector<long long>
#define all(x)   (x).begin(), (x).end()
#define pb       push_back
#define pf       push_front
#define fi       first
#define se       second
#define CY       cout<<"YES\n";
#define CN       cout<<"NO\n";
#define tc    \
    int t;    \
    cin >> t; \
    while (t--)
#define fora(cn)        for(auto &x : (cn))
#define lff1(i,a,b)     for(ll i=a-1;i<=b-1;i++)
#define rlff1(i,b,a)    for(ll i=b-1;i>=a-1;i--)
#define ff(i,n)         for(ll i=0;i<n;i++)
#define ff1(i,n)        for(ll i=1;i<=n;i++)

#define asc(v)      sort(v.begin(), v.end()) //vectors,pairs,tuples,string"
#define dsc(v)      sort(v.begin(), v.end(), greater<int>())

bool cmp(pair<string, int>& a,pair<string, int>& b){
    return a.second < b.second;
}
vector<vector<int>> a;
void permuteGen(vi &s,int n, int i){ //call by: subGen(v,n-1,0);
    if(i==n){
        a.pb(s);
        ff(i,s.size()){
            cout<<s[i]<<sp;
        }
        cout<<endl;
    }
    else{
        for(int j=i;j<=n;j++){
            swap(s[j],s[i]);
            permuteGen(s,n,i+1);
            swap(s[j],s[i]);
        }
    }
}
int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

    ios_base:: sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    
    vi v;
    int n=4;
    for(ll i=1;i<=n;i++){
        v.pb(i);
    }
    permuteGen(v,n-1,0);
    return 0;
}