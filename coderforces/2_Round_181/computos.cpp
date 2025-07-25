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

set<char> letters = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
set<char> numbers = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
set<ll> nums = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

bool esPrimo(ll num) {
    if (num <= 1) {
        return false;
    }
    for (ll i = 2; i * i <= num; ++i) {
        if (num % i == 0) {
            return false;  
        }
    }
    return true;  
}


vector<ll> factorizacionPrima(ll numero) {
    vector<ll> factores;

    if (numero <= 1) {
        return factores;
    }

    ll tempNumero = numero;
    for (ll d = 2; d * d <= tempNumero; ++d) {
        while (tempNumero % d == 0) {
            factores.push_back(d);
            tempNumero /= d;
        }
    }

    if (tempNumero > 1) {
        factores.push_back(tempNumero);
    }

    return factores;
}

void solve(){
    ll l, r;  cin>>l>>r; // 'l' es ignorado en esta corrección, solo se usa 'r'
    vi res;
    ll resu = 0;
    ll cantp = 0;
    vi nop;
    fore(i, l, r+1){
        if (esPrimo(i)){cantp++;}
        vector<ll> facs = factorizacionPrima(i);
        bool rest = true;
        fore(i, 0, sz(facs)){
            string s = to_string(facs[i]);
            if (sz(s) >= 2){
                res.pb(facs[i]);
            }else{
                //nop.pb(i);
                rest = false;
            }
        }

        if(rest){
            resu++;
        }else{
            nop.pb(i);
        }
    }
    cout<<res<<endl;
    pri(sz(res));
    db(resu);
    db(cantp);
    cout<<nop<<endl;
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
