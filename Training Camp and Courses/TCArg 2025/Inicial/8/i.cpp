#include<bits/stdc++.h> 
using namespace std; 

#define fore(i, a, b) for(ll i=(a); i<(b);i++)
#define all(x) (X).begin(), (x).end()
#define pb push_back 
#define fst first 
#define snd second 
#define sz(x) ((int)x.size())

#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using ll = long long;
typedef vector<ll> vi; 

int main(){
    FIN; 

    ll t;cin>>t;
    while(t--){
        ll n,k; cin>>n>>k;
        fore(i,0,n){
            if (i%3==0) cout << "a";
            if (i%3==1) cout << "b";
            if (i%3==2) cout << "c";
        }
        cout << "\n";
    }

    return 0; 
}