#include<bits/stdc++.h> 
using namespace std; 

#define fore(i, a, b) for(ll i=(a); i<(b);i++)
#define all(x) (x).begin(), (x).end()
#define pb push_back 
#define fst first
#define snd second
#define sz(x) ((int)x.size())

#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0); 

using ll = long long; 
typedef vector<ll> vi; 

int main(){
    FIN;

    ll t; cin>>t;
    while(t--){
        ll n, s; cin>>n;
        s=0; n=n*2;
        vi v(n);
        fore(i,0,n){
            cin>>v[i];
        }
        sort(all(v));
        for(ll i=(0); i<(n);i+=2){
            s+=v[i];
        }
        cout<<s<<"\n";
    }
    

    return 0;
}