#include<bits/stdc++.h>
using namespace std;
#define fore(i, a, b) for(ll i=(a); i<(b); i++)
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define fst first 
#define snd second 
#define sz(x) ((int)x.size())

#define FIN ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);

using ll = long long;
typedef vector<ll> vi; 

// 5
// planta1 -> 1 1 1
// planta2 -> 1 1 2
// planta3 -> 1 1 3
// planta4 -> 2 3 5
// planta5 -> 2 2 4

// planta1 = max{2, 2, 0} = 2 
// plant2 = max(2, 2, 0) = 2 
// planta3 = max(2, 2, 0) = 2
// planta4 = max(1, 0, 0) = 1
// planta5 = max(1, 0, 0) = 1

int main(){FIN; 

    ll t; cin>>t; 
    
    while(t--){
        ll n; cin>>n; 
        ll a[n][3];

        fore(i, 0, n){
            cin>>a[i][0]>>a[i][1]>>a[i][2];
        }
        map<ll, ll> x, y, z;
        vi res(n);
        fore(i, 0, n) {
            x[a[i][0]]++;
            y[a[i][1]]++;
            z[a[i][2]]++;
        }

        fore(i, 0, n) {
            ll aa = x[a[i][0]] - 1;
            ll bb = y[a[i][1]] - 1;
            ll cc = z[a[i][2]] - 1;

            ll resu = max({aa, bb, cc});
            res[i] = resu;
        }
        // fore(i, 0, n){
        //     cout<<res[i]<<" ";
        // }
        
        vi freq(n+1, 0);
        fore(i,0, n){
            freq[res[i]]++;
        }

        vi ans(n, 0);
        ll mins = 0;
        fore(k,0,n){
            if(k > 0) mins += freq[k-1];
            ans[k] = mins;
        }
        fore(k,0,n)cout<<ans[k]<<" ";
        cout << "\n";
    }

    return 0; 
}
