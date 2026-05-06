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
        fore(i,0,n){
            cin>>ks[i];
        }
        sort(all(ks));

        ll a,b,c;
        fore(i,0,m){
            cin>>a>>b>>c;
            if(c<=0 || b < sqrt(a*c)){
                cout<<"NO\n";
                continue;
            }
            cout<<"YES\n";
            double k1,k2;
            k1 = b - 2* sqrt(a*c);
            k2 = 2* sqrt(a*c) - b;

            ll l = -1, r = n;
            bool b=false;
            while (r - l > 1) {
                ll m = (l + r) / 2;
                if (ks[m] > k2) {
                    r = m;
                } else if (ks[m] < k1) {
                    l = m; // a[l] <= a[m] <= k < a[r]
                } else {
                    cout<<ks[m]<<"\n";
                    b=true;
                    break;
                }
            }
            l++; r--;
            if(!b){
                if(l>0 && l<n && ks[l]<=k2 && ks[l]>=k1){
                    cout<<ks[l]<<"\n";
                } else if(r>0 && r<n && ks[r]<=k2 && ks[r]>=k1){
                    cout<<ks[r]<<"\n";
                }
            }


        }

    }

    return 0;
}