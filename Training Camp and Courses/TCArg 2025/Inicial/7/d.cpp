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
        ll n; cin>>n; 
        vector<vector<ll>> vi(n, vector<ll>(n));
        fore(i, 0, n){
            fore(j, 0, n){
                cin>>vi[i][j];
            }
        }
        ll dp[16]; 
        dp[0] = 0;
        fore(i,1,16){
            dp[i] = 1e18;
        }
        fore(i, 0, n){
            fore(j, 0, n){
                ll x = vi[i][j]; 
                ll m = 0; 


                ll topcorner = 1; //0001;
                ll toprightcorner = 2; //0010;
                ll bottomcorner = 4; //0100;
                ll bottomrightcorner = 8; //1000;
                if(abs(i-0)<= n/2 && abs(j-0) <=n/2) m |= topcorner;
                if(abs(i-0)<= n/2 && abs(j-(n-1)) <=n/2) m |= toprightcorner;
                if(abs(i-(n-1))<= n/2 && abs(j-0) <=n/2) m |= bottomcorner;
                if(abs(i-(n-1))<= n/2 && abs(j-(n-1)) <=n/2) m |= bottomrightcorner;

                fore(k, 0, 16){
                    dp[k | m] = min(dp[k | m], dp[k] + x);
                }
            }
        }
        cout<<dp[15]<<"\n";
    }

    return 0;
}