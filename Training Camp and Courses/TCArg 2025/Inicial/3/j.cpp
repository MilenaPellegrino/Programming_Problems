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
    ll n; cin>>n; 
    string sant; 
    cin>>sant; 
    ll maxs = sz(sant);
    fore(i, 0, n-1){
        string s; cin>>s; 
        ll cont = 0; 
        fore(j, 0, sz(s)){
            if(s[j] == sant[j]){
                cont++;
            }else{
                break;
            }
        }
        //sant = s;
        maxs = min(maxs, cont);
    }
    cout<<maxs<<"\n";
    return 0;
}
