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

ll fact(ll n){
    ll res = 1;
    fore(i, 1, n+1){
        res *= i;
    }
    return res;
}

void solve(){
    ll n; cin>>n;
    ll d; cin>>d;
    vi res; 

    if(n>7){
        n=7;
    }
    ll facts = fact(n);
    vi odds = {1, 3, 5, 7, 9};

    for(ll divs : odds){
        if(divs==1){
            res.pb(1);}
        if (divs == 3 || divs == 9) {
                // Para divisor 3 o 9, la suma de los dígitos es d * n!
                long long sum = d * n_fact;
                if (sum % divs == 0) {
                    cout << divisor << " ";
                }
        } else if (divs == 5) {
                // Para divisor 5, el número debe terminar en 0 o 5
            if (d == 5) {
                    cout << "5 ";
                }
        } else if (divisor == 7) {
                // Para divisor 7, usamos la propiedad de que si n >= 3, el número es divisible por 7
            if (n >= 3 || d == 7) {
                    cout << "7 ";
                }
            }
        }
    }
    res.pb(1);  //  All numbers are divisible by 1

    vi odds = {1, 3, 5, 7, 9};

    if(d%3 == 0 || n>=3){  // Div by 3
        res.pb(3);
    }

    if(d == 5){  // Div by 5
        res.pb(5);
    }

    if(d == 7 || n >= 3){  // Div by 7
        res.pb(7);
    }

    if(d%9 == 0 || n>=6){  // Div by 9
        res.pb(9);
    }
    fore(i, 0, sz(res)){
        cout<<res[i]<<" ";
    }
    cout<<"\n";
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