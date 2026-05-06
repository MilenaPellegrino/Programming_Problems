#include <bits/stdc++.h> 
using namespace std; 
 
#define fore(i, a, b) for(ll i=(a);i<(b); i++)
#define all(x) (x).begin(), (x).end()
#define pb push_back 
#define fst first 
#define snd second 
#define sz(x) ((ll)x.size())
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using ll = long long; 
typedef vector<ll> vi;
 
int main(){FIN;

    ll t; cin >> t;while(t--)
{
    ll n, sum=0; cin>>n;

    vi v;
    ll l=1;
    ll i=0;

    while(sum<n){
        v.pb(l*(l+1)/2);
        if(sum + v[i]>n) break;
        sum+=v[i];
        l = 2*l + 1;
        // cout << v[i] << "\n";
        i++;
    }

    if(n==1){
    cout << 1 << "\n";
}
    else if (sum==n) {
        cout << sz(v) << "\n";
    } else {
        cout << sz(v) -1 << "\n";}
    }

   
   return 0;
}