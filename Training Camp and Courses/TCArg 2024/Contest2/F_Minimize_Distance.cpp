#include<bits/stdc++.h>
using namespace std;
#define fore(i,a,b) for(ll i=(a);i<(b);i++)
#define rof(i, a, b) for(ll i=(a);i>=(b);i--)
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

void solve(){
    ll n, k; cin>>n>>k;
    vi a(n);
    fore(i, 0, n) cin >> a[i];
    sort(all(a)); 
    
    ll ans = 0;
    
    vi pos, neg;
    
    // Separamos en los cosas negativos y positivos
    fore(i, 0, n) {
        if (a[i] < 0) neg.pb(-a[i]);
        else pos.pb(a[i]);
    }
    
    // Negativos
    for (ll i = 0; i < sz(neg); i += k) {
        ans += 2 * neg[i];
    }
    
    // Positivos
    for (ll i = sz(pos) - 1; i >= 0; i -= k) {
        ans += 2 * pos[i];
    }
    
    // Restar la mayor distancia 
    if (!neg.empty() && !pos.empty()) {
        ans -= max(neg[0], pos[sz(pos) - 1]);
    } else if (!neg.empty()) {
        ans -= neg[0];
    } else if (!pos.empty()) {
        ans -= pos[sz(pos) - 1];
    }
    
    pri(ans);
}

int main(){
    FIN;
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}