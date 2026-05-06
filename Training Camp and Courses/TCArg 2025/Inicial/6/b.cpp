#include<bits/stdc++.h> 
using namespace std; 

#define fore(i, a, b) for(ll i=(a);i<(b); i++)
#define all(x) (x).begin(), (x).end()
#define pb push_back 
#define fst first 
#define snd second 
#define sz(x) ((int)x.size())
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using ll = long long; 
typedef vector<ll> vi;

vector<ll> res;
void divi(ll n){
    for(ll i=1;i*i<=n;i++){
        if(n%i==0){
            res.pb(i);
            if(i!=n/i) res.pb(n/i);
        }
    }
}

int main(){FIN;
    ll n,k;
   cin>>n>>k;
   k--;
   divi(n);
   sort(all(res));
   if(res.size()<k+1){
    cout<<-1<<"\n";
   }else{
    cout<<res[k]<<"\n";
   }
   return 0;
}