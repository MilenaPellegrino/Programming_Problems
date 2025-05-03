#include<bits/stdc++.h>
using namespace std;
#define fore(i,a,b) for(ll i=(a);i<(b);i++)
#define rof(i, a, b) for(ll i=(b);i>(a);i--)
#define forn(e,c) for(const auto &e : (c))
#define db(x) cout<<#x<< " = "<<(x)<<endl
#define sz(x) ((int)x.size())
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define pp pop_back
#define mp make_pair
#define fst first
#define snd second
#define str string
#define pri(x) cout << (x) << "\n"
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0); 
using ll = long long;
using pii = pair<int,int>;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<char> vc;

template<class T>ostream&operator<<(ostream&o,vector<T>const&v){o<<"[ ";for(auto const&x:v)o<<x<<" ";return o<<"]";}


/*
n = 2
x = 1


a = [a1, a2, a3, ... , an]
a1 XOR x2 XOR a3 XOR ... XOR an = x 

XOR: 
iguales -> 0 
diferentes -> 1 


*/
void solve(){
    ll n; cin>>n;
    ll x; cin>>x; 

    bitset<64> bin(x); 
    bitset<64> unob(1); 
    bitset<64> resb(1);
    vi res; 
    fore(i, 0, sz(bin)){
        ll pib = bin[i]; 
        ll piu = unob[i]; 
        if (pib == 1  && piu == 0){
            res.pb(1);
        } else if (pib == 1 && piu == 1){
            res.pb(0);
        } else if (pib == 0 && piu == 0){
            res.pb(0);
        } else if (pib == 0 && piu == 1){
            res.pb(1);
        }
    }
    fore(i, 0, sz(bin)){
        resb[i] = res[i];
    }
    ll num = resb.to_ulong();
    pri(num + 1);
}

int main(){
    FIN; 
    //int t = 1;
    int t; cin>>t; 
    while(t--){
        solve();
    }
    return 0;
}