#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 9;
vector<pair<pair<int,int>,pair<int,int>>>tree(4*N+1);
const int p1 = 137, mod1 = 127657753, p2 = 277, mod2 = 987654319;
int power(long long n, long long k, int mod) {
  int ans = 1 % mod; n %= mod; if (n < 0) n += mod;
  while (k) {
    if (k & 1) ans = (long long) ans * n % mod;
    n = (long long) n * n % mod;
    k >>= 1;
  }
  return ans;
}

int ip1, ip2;
pair<int, int> pw[N], ipw[N];
void prec() {
  pw[0] =  {1, 1};
  for (int i = 1; i < N; i++) {
    pw[i].first = 1LL * pw[i - 1].first * p1 % mod1;
    pw[i].second = 1LL * pw[i - 1].second * p2 % mod2;
  }
  ip1 = power(p1, mod1 - 2, mod1);
  ip2 = power(p2, mod2 - 2, mod2);
  ipw[0] =  {1, 1};
  for (int i = 1; i < N; i++) {
    ipw[i].first = 1LL * ipw[i - 1].first * ip1 % mod1;
    ipw[i].second = 1LL * ipw[i - 1].second * ip2 % mod2;
  }
}

pair<int, int> string_hash(string s) {
  int n = s.size();
  pair<int, int> hs({0, 0});
  for (int i = 0; i < n; i++) {
    hs.first += 1LL * s[i] * pw[i].first % mod1;
    hs.first %= mod1;
    hs.second += 1LL * s[i] * pw[i].second % mod2;
    hs.second %= mod2;
  }
  return hs;
}
vector<pair<int,int>> build(string s) {
  int n = s.size();
  vector<pair<int,int>>pref(n+1,{0,0});
  for (int i = 0; i < n; i++) {
    pref[i].first = 1LL * s[i] * pw[i].first % mod1;
    if (i) pref[i].first = (pref[i].first + pref[i - 1].first) % mod1;
    pref[i].second = 1LL * s[i] * pw[i].second % mod2;
    if (i) pref[i].second = (pref[i].second + pref[i - 1].second) % mod2;
  }
  return pref;
}
pair<int, int> get_hash(int i, int j,vector<pair<int,int>>&pref) {
  pair<int, int> hs({0, 0});
  hs.first = pref[j].first;
  if (i) hs.first = (hs.first - pref[i - 1].first + mod1) % mod1;
  hs.first = 1LL * hs.first * ipw[i].first % mod1;
  hs.second = pref[j].second;
  if (i) hs.second = (hs.second - pref[i - 1].second + mod2) % mod2;
  hs.second = 1LL * hs.second * ipw[i].second % mod2;
  return hs;
}
pair<pair<int,int>,pair<int,int>> jog(pair<pair<int,int>,pair<int,int>>a,pair<pair<int,int>,pair<int,int>>b){
  return {{(a.first.first+b.first.first)%mod1,(a.first.second+b.first.second)%mod2},{(a.second.first+b.second.first)%mod1,(a.second.second+b.second.second)%mod2}};
}
void built(int indx,int l,int r,string &a,string &a1){
    if(l==r){
        tree[indx].first={1LL * a[l] * pw[l].first % mod1,1LL * a[l] * pw[l].second % mod2};
        tree[indx].second={1LL * a1[l] * pw[l].first % mod1,1LL * a1[l] * pw[l].second % mod2};
    }else{
       int mid=(l+r)/2;
       int left=2*indx,right=2*indx+1;
       built(left,l,mid,a,a1);
       built(right,mid+1,r,a,a1);
       tree[indx]=jog(tree[left],tree[right]);
    }
}
pair<pair<int,int>,pair<int,int>> query (int indx,int l,int r,int l1,int r1){
    if(r1<l || r<l1)return {{0,0},{0,0}};
  if(l1<=l && r1>=r)return tree[indx];
  else{
    int mid=(l+r)/2;
    return jog(query(2*indx+1,mid+1,r,l1,r1),query(2*indx,l,mid,l1,r1));
  }
}
void update(int indx,int l,int r,int l1,int r1,int up,string &a,string &a1){
    if(r1<l || r<l1) return;
   if(l==r){
    if(up==1){
        tree[indx].first.first=1LL * a[l] * pw[l].first % mod1;
        tree[indx].first.second=1LL * a[l] * pw[l].second % mod2;
    }else{
        tree[indx].second.first=1LL * a1[l] * pw[l].first % mod1;
        tree[indx].second.second=1LL * a1[l] * pw[l].second % mod2;
    }
   }else{
      int mid=(l+r)/2;
      update(2*indx,l,mid,l1,r1,up,a,a1);
      update(2*indx+1,mid+1,r,l1,r1,up,a,a1);
      tree[indx]=jog(tree[2*indx],tree[2*indx+1]);
   }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  prec();
  int n,q;
  cin>>n>>q;
  string a;
  cin>>a;
  string a1=a;
  reverse(a.begin(),a.end());
  built(1,0,n-1,a1,a);
  while(q--){
    int type;
    cin>>type;
    if(type==1){
        int pos;
        char c;
        cin>>pos>>c;
        --pos;
        a1[pos]=c;
        a[n-1-pos]=c;
        update(1,0,n-1,pos,pos,1,a1,a);
        update(1,0,n-1,n-1-pos,n-1-pos,2,a1,a);
    }else{
       int l,r;
       cin>>l>>r;
       --l,--r;
       pair<pair<int,int>,pair<int,int>>ans=query(1,0,n-1,l,r);
       pair<pair<int,int>,pair<int,int>>ans1=query(1,0,n-1,n-1-r,n-1-l);
       ans.first={1ll*ans.first.first*ipw[l].first%mod1,1ll*ans.first.second*ipw[l].second%mod2};
       ans1.second={1ll*ans1.second.first*ipw[n-1-r].first%mod1,1ll*ans1.second.second*ipw[n-1-r].second%mod2};
       if(ans.first==ans1.second)cout<<"YES"<<endl;
       else cout<<"NO"<<endl;
    }
  }

}

//https://cses.fi/problemset/task/2420
