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


void solve() {
    ll n, t;
    cin >> n >> t;
    vi a(n);
    fore(i, 0, n) cin >> a[i];

    ll tiempoAcumulado = 0;
    ll explorado = 0;
    ll tiempoMaximo = 0;
    ll l = 0;
    fore(i, 0, n) {
        tiempoAcumulado += (a[i] * 2);
        while (tiempoAcumulado > t) {
            tiempoAcumulado -= (a[l++] * 2);
        }
        if (i - l + 1>= explorado) {
            explorado = i - l + 1;
            tiempoMaximo = max(tiempoMaximo, tiempoAcumulado);
        }
    }
    cout << explorado << " " << t - tiempoMaximo << "\n";
}

int main() {
    FIN;
    solve();
    return 0;
}