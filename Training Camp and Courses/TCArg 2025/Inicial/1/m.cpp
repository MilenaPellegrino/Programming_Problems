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

bool sepuede(vi a, ll j, ll i, ll x){
    ll mins = a[i];
    ll ans = mins * (i-j+1);
    return ans >= x;
}
int main(){
    FIN;
    ll t; cin>>t; 
    while(t--){
        ll n, x; cin>>n>>x; 
        vi a(n);
        fore(i, 0, n)cin>>a[i];
        sort(all(a), greater<ll>());
        //reverse(all(a));

        //fore(i, 0, n)cout<<minim[i]<<endl;
        ll j = 0, cont = 0;
        fore(i, 0, n){
            ll mins = a[i]; 
            ll ans = mins * (i - j + 1);
            if(ans>=x){
                cont++;
                j= i+1;
            }
            // if(sepuede(a, j, i, x)){
            //     cont++;
            //     j = i+1;
            // }
        }
        cout<<cont<<"\n";
    }

    return 0;
}