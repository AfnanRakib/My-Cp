#include<bits/stdc++.h>
#define iamspeed ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl '\n'
using namespace std;
typedef long long int ll;
const ll N=1e6+5;
ll n,m,k,w,sum,ans,cnt,cnt2,res,mn,mx,t,tt,q,i,j;
string s,ss;
int egcd(int a, int b, int& x, int& y)
{
    if (b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }
    int d = egcd(b, a % b, x, y);
    int z=x;
    x = y;
    y = z - y * (a / b);
    return d;
}

int main()
{
    iamspeed


    ///modular inverse of 'a' using extended euclidean algorithm
    int a,p;
    cin>>a>>p;
    int x,y;
    int gcd=egcd(a,p,x,y);
    if(gcd!=1)
    {
        cout<<" modular inverse of "<<a<<" doesn't exist\n";
    }
    else
    {

        ///when x<0, you need to make it positive. but negative x is a valid modular inverse too which doesn't break the conditions.
        if(x<0)
        {
            x%=p;
            x+=p;
            x%=p;
            y=(a*x-1)/p;
        }
        cout<<" modular inverse of "<<a<<" = "<<x<<endl;
    }
    ///To find modular inverse of 'a', extended euclidean works for any value of 'a' and 'p' if they are relatively COPRIME meanwhile modular exponentiation only works when 'p' is a PRIME.

    /* Notes:
       When, ax≡1=a^(p-1)[mod p] ; 'x' is the modular inverse of 'a' in modulo 'p'.
       => ax=py+1
       => ax+p(-y)=1 (here, 1=g) according to Bezout's lemma algorithm
       now find the x and y.
       this way we can find the modular inverse of 'a'.
    */


    return 0;
}

