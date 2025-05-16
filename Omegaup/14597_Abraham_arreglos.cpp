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
    ll n; cin >> n;
    vi a(n); fore(i, 0, n) cin >> a[i];
    ll m; cin >> m;
    vi b(m); fore(i, 0, m) cin >> b[i];

    ll i = 0, j = 0;
    ll sumA = 0, sumB = 0;
    ll ans = 0;

    while (i < n || j < m) {
        if (sumA == sumB) {
            ans++;
            if (i < n) sumA = a[i++];
            if (j < m) sumB = b[j++];
        } else if (sumA < sumB) {
            if (i < n) sumA += a[i++];
            else break; 
        } else {
            if (j < m) sumB += b[j++];
            else break; 
        }
    }

    if (sumA == sumB) {
        pri(ans);
    } else {
        pri(-1);
    }
}

int main() {
    FIN;
    int t = 1;
    //int t; cin >> t; 
    while (t--) {
        solve();
    }
    return 0;
}