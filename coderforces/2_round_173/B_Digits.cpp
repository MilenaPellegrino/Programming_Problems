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

ll MAXN = 1000000000 + 1;
vi factorials(MAXN);

ll fact(int n) {
    if (n == 0 || n == 1) return 1;
    if (factorials[n] != 0) return factorials[n];  // Si ya está calculado, devuelvo el resultado

    factorials[n] = n * fact(n - 1);  // Memorizo el resultado
    return factorials[n];
}


void solve(){
    ll n; cin>>n;
    ll d; cin>>d;
    vi res; 
    res.pb(1);  //  All numbers are divisible by 1

    ll num = fact(n) * d; 
    
    if(num%3 == 0){  // Div by 3
        res.pb(3);
    }

    if(d == 5 || d == 0){  // Div by 5
        res.pb(5);
    }

    if(num%7 == 0){  // Div by 7
        res.pb(7);
    }

    if(num%9 == 0){  // Div by 9
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