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

ll calc(ll a){
    ll x = (a/10) * 10;
    return x; 
}
int main(){
    FIN; 
    ll k, r; cin>>k>>r; 
    ll cien = (k/10) * 10;
    //cout<<cien<<endl;
    ll mult = 1; 
    ll cont = 0; 
    ll i = 0;
    while(true){
        cien = calc(k*mult);
        //cout<<"CIEN: "<<cien<<endl;
        //cout<<k * mult<<endl;
        if((cien + r) == (k * mult) || (cien == (k * mult))){
            break;
        }else{
            mult++; 
            cont++;
        }
        i++;
    }
    cout<<cont + 1<<"\n";
    return 0; 
}
