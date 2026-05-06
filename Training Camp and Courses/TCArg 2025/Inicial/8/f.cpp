#include<bits/stdc++.h> 
using namespace std; 

#define fore(i, a, b) for(ll i=(a); i<(b);i++)
#define all(x) (X).begin(), (x).end()
#define pb push_back 
#define fst first 
#define snd second 
#define sz(x) ((int)x.size())

#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using ll = long long;
typedef vector<ll> vi; 

int main(){
    FIN; 
    ll a, b, c, n; cin>>a>>b>>c>>n; 
    ll sum = a + b - c; 
    ll ans = n - sum;
    if(ans<= 0 || a<0 || b<0 || c<0 || sum -c<0 || c>a || c>b){
        cout<<-1<<"\n";
    }else{
        cout<<ans<<"\n";
    }
    return 0; 
}