#include<bits/stdc++.h> 
using namespace std;

#define fore(i, a, b) for(ll i =(a); i<(b); i++)
#define all(x) (x).begin(), (x).end()
#define pb push_back 
#define fst first 
#define snd second
#define sz(x) ((int)x.size())

#define  FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0); 

using ll = long long; 
typedef vector<ll> vi;
int main(){
    FIN;
    ll t; cin>>t; 
    while(t--){
        ll n; cin>>n; 
        vi a(n); fore(i, 0, n)cin>>a[i];
        vi freq(n+1, 0);
        vector<vector<ll>> defreq(n+1); 
        fore(i, 0, n){
            freq[a[i]]++;
        }

        ll mex = -1;
        fore(i, 0, sz(freq)){
            if(freq[i] == 0){mex = i; break;}
        }
        if(mex == -1)mex = n+1;
        //cout<<mex<<endl;
        fore(i, 0, mex+1){
            defreq[freq[i]].pb(i);
        }
        vi res;
        set<ll> mexpos; 

        // k=0 -> puedo mex = i?
        fore(i, 0, mex+1){
            if(i<= (n) && freq[i]<= 0){
                mexpos.insert(i);
            }
        }
        res.pb(sz(mexpos));
        // for (ll elem : mexpos){
        //     cout<<elem<<" ";
        // }
        // cout<<endl;
        // fore(i, 0, sz(res)){
        //     cout<<res[i]<<" ";
        // }
        // cout<<endl;
        // mexpos.clear();
        // // k=1 -> puedo mex = i? 
        // fore(i, 0, n-1){
        //     if(i<= (n-1) && freq[i]<= 1){
        //         mexpos.insert(i);
        //     }
        // }
        //res.pb(sz(mexpos)); 

        fore(i, 1, n+1){
            //mexpos.clear();
            ll sacar =  n - i + 1;
            mexpos.erase(sacar);
            for(ll k : defreq[i]){
                if(k <= mex && k <= n-i){
                    mexpos.insert(k);
                }
            }
            res.pb(sz(mexpos));
            //res.pb(sz(mexpos));
        }


        fore(i, 0, sz(res)){
            cout<<res[i]<<" ";
        }
        cout<<"\n";

    }

    
    return 0;
}