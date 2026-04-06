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

vector <pair<ll,ll>> fact(ll n){
    vector <pair<ll,ll>> res;
    for(ll i=2; i*i <=n; i++){
        if(n%i==0){
            res.pb({i,0});
            while(n%i==0){
                n /= i;
                res.back().second++;
            }
        }
    }
    if(n>1)res.pb({n,1});
    return res;
}

vector <ll> divi(ll n){
    vector <ll> res;
    for (ll i=1; i*i<=n;i++){
        if(n%i == 0){
            res.pb(i);
            if(i!= n/i){res.pb(n/i);}
        }
    }
    return res;
}

int main(){
    FIN;
    ll t;cin>>t;
    fore(k,0,t){
        ll p, q;
        cin>>p>>q;
        if(p % q != 0){
            cout<<p<<"\n";
        } else {
            ll algo = p/q;
            vector <ll> f = divi(q);
            sort(all(f));
            reverse(all(f));
            ll can=0;
            fore(i,0,f.size()){
                can = f[i]*algo;
                if (can % q != 0) break;
            }
            cout<<can<<"\n";
        }

    }

    return 0;
}