#include<bits/stdc++.h> 
using namespace std; 

#define fore(i, a, b) for(ll i =(a); i<(b); i++)
#define all (x) (x).begin(), (x).end()
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
        ll x1, y1, x2, y2; cin>>x1>>y1>>x2>>y2; 
        ll a = abs(x2 -x1);
        ll b = abs(y2 - y1); 
        if(a!=0 && b!=0){
            cout<<a+b+2<<"\n";
        }else{
            cout<<a+b<<"\n";
        }
    }

    return 0;
}
