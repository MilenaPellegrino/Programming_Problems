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
    ll n, a, b; cin>>n>>a>>b;
    vi ab(n); 
    fore(i, 0, n)cin>>ab[i];
    ll i = 0, j = n-1;
    ll prim = ab[i], ult = ab[j];
    ll mins = min(a, b);
    ll ans =0;
    while(i<= j){
        prim = ab[i]; 
        ult = ab[j];
        if (prim  == ult && (prim == 0 || prim == 1)){
            i++; 
            j--;
        } else if (prim == ult && prim ==2){
            ans+= mins+mins; 
            i++; 
            j--;
        }else if(prim != ult && (prim == 2 || ult ==2)){
            if(prim == 1 || ult == 1){
                ans+=b; 
            }else if (prim == 0 || ult == 0){
                ans += a; 
            }
            i++; 
            j--;
        } else if (prim!= ult && (prim == 1 || prim == 0)){
            cout<<-1<<"\n";
            return 0;
        }
    }
    cout<<ans<<"\n";
    return 0; 
}