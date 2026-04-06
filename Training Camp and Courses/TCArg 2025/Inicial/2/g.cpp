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
int main(){
    FIN;
    ll a; cin>>a; 
    vi b(a); fore(i, 0, a)cin>>b[i];
    ll maxs = b[a-1];
    reverse(all(b));
    ll ans = maxs;
    ll i = 1;
    ll act = maxs;
    while(act >0 && i<a){
        ans += min(act - 1, b[i]);
        act = min(act - 1, b[i]);
        // cout<<"ans"<<ans<<endl;
        // cout<<"act"<<act<<endl;
        i++;
    }
    // fore(i, 0, b.size()){
    //     cout<<b[i]<<" ";
    // }
    cout<<ans<<endl;

    return 0;
}