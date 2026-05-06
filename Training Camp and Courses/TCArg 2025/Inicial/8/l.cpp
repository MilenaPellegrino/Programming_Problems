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
        ll n, m; cin>>n>>m; 
        vi c(n); vi g(n); fore(i, 0, n){cin>>c[i];g[i]=c[i];}
        vector<pair<ll,ll>> b(m); 

        fore(i, 0, m){
            ll x, y; cin>>x>>y;
            y--; 
            b[i].fst = x; 
            b[i].snd = y; 
        }
        sort(all(b));
        ll kr = 0;
        ll i =0;//estaciones
        vi bb;
        fore(i, 0, m){
            bb.pb(b[i].snd);
        }
        set<ll> s;
        fore(i,0,n){
            s.insert(i);
        }
        fore(i,0,m){
            if(s.count(b[i].snd)!=0){
                s.erase(b[i].snd);
            };
        }
        for(auto in:s){
            bb.pb(ss);
        }
        fore(j, 0, m){
            if(i>=m){break;}
            if(b[i].fst<=g[b[j].snd]+kr){
                kr=b[i].fst;
                g[b[j].snd]-=b[i].fst-kr;
                g[b[i].snd]=c[b[i].snd];
                i++;
            }else{
                kr+=g[b[j].snd];
                g[b[j].snd]=0;
            }
        }
        fore(i,0,n){
            kr+=g[i];
        }
    }
    return 0; 
}