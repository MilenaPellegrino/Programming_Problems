#include<bits/stdc++.h> 
using namespace std; 
#define ll long long
#define vi vector<ll>
#define fore(i, a, b) for (ll i= a; i<(b); i++)
#define all(x) (x).begin(), (x).end()
#define pb push_back 
#define fst first
#define snd second 

#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)

int main(){FIN; 
    ll x; cin>>x; 
    ll ans = x/5; 
    if(x % 5 !=0 )ans++; 
    cout<<ans<<"\n";

    return 0;
}