/**
 *    author:  ApuYe
 *    created: 12.01.2024
**/
#include<bits/stdc++.h>
#define iamspeed ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl '\n'
using namespace std;
typedef long long int ll;
const ll modd=1e9+7;
const ll N=1e6+5;
ll x,y,z,n,m,k,w,sum,ans,cnt,cnt2,res,mn,mx,t,tt,q,i,j;
string s,ss;
int main()
{
    ll n;
    cin>>n;
    ll a[n],m[n],M,M1[n],x,M1_inv[n];
    M=1;
    for(ll i=0; i<n; i++)
    {
        cin>>m[i]>>a[i];
        M*=m[i];
    }
    for(ll i=0; i<n; i++)
    {
        M1[i]=M/m[i];
        ll y=(M1[i]*a[i])%M,z=0;
        ///use extended gcd or (euler's totient + mod expo) to find mod inverse for practice purpose
        for(ll j=1;; j++)
        {
            ll ans=(M1[i]*j)%m[i];
            z=(z+y)%M;
            if(ans==1)
            {
                M1_inv[i]=j;
                break;
            }
        }
        ///cerr<<m[i]<<' '<<a[i]<<' '<<M1[i]<<' '<<M1_inv[i]<<a[i]*M1[i]*M1_inv[i]<<endl;
    }
    x=0;
    for(ll i=0; i<n; i++)
    {
        for(j=1;j<=M1_inv[i];j++)
        {
           x=(x+(M1[i]*a[i])%M)%M;  ///x=(x+(((M1[i]*a[i])%M)*M1_inv[i])%M)%M may cause overflow.
        }                           ///that's why I used a loop inside.
    }
    cout<<x<<endl;


    return 0;
}
