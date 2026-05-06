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

        ll n,m; cin>>n>>m;
        vi ks(n);
        vector<pair<double,double>> kparab(m);
        vector<bool> res(m);
        fore(i,0,n){
            cin>>ks[i];
        }
        sort(all(ks));

        ll a,b,c;
        fore(i,0,m){
            cin>>a>>b>>c;
            if(c<=0 || b < sqrt(a*c)){
                res[i]=false;
                continue;
            }
            res[i]=true;
            double k1,k2;
            kparab[i].fst = b - 2* sqrt(a*c);
            kparab[i].snd = 2* sqrt(a*c) - b;
        }

        

        while(i<n && j<m){

        }

    }

    return 0;
}