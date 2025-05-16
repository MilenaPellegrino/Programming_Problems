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
ll sumDIg(ll x) {
    ll res = 0;
    while (x > 0) {
        res += x % 10;
        x /= 10;
    }
    return res;
}

struct Tree {
    typedef ll T;
    typedef ll L; // T: data type, L: lazy type
    // neutrals
    constexpr static T tneut = 0;
    constexpr static L lneut = -1;
    T f(T a, T b) { return a + b; } // operation
    // new st according to lazy
    //T apply(T v, L l, ll s, ll e) {
       // if (l == lneut) return v;
      //  return sumDIg(v); // apply sum of digits
   // }
    T apply(T v, L l) {
       if (l == lneut) return v;
       return sumDIg(v); // apply sum of digits
   }
    // cumulative effect of lazy
    L comb(L a, L b) { return b == lneut ? a : b; }
    ll n;
    vector<T> st;
    vector<L> lazy;
    Tree(ll n) : n(n), st(4 * n, tneut), lazy(4 * n, lneut) {}
    Tree(vector<T> &a) : n(a.size()), st(4 * n), lazy(4 * n, lneut) {
        init(1, 0, n, a);
    }
    void init(ll k, ll s, ll e, vector<T> &a) {
        lazy[k] = lneut;
        if (s + 1 == e) {
            st[k] = a[s];
            return;
        }
        ll m = (s + e) / 2;
        init(2 * k, s, m, a), init(2 * k + 1, m, e, a);
        st[k] = f(st[2 * k], st[2 * k + 1]);
    }
    void push(ll k, ll s, ll e) {
        if (lazy[k] == lneut) return; // if neutral, nothing to do
        st[k] = apply(st[k], lazy[k]);
        if (s + 1 < e) { // propagate to children
            lazy[2 * k] = comb(lazy[2 * k], lazy[k]);
            lazy[2 * k + 1] = comb(lazy[2 * k + 1], lazy[k]);
        }
        lazy[k] = lneut; // clear node lazy
    }
    void upd(ll k, ll s, ll e, ll a, ll b) {
        push(k, s, e);
        if (s >= b || e <= a) return;
        if (s >= a && e <= b) {
            lazy[k] = 0; // mark this node to apply sumDIg
            push(k, s, e);
            return;
        }
        ll m = (s + e) / 2;
        upd(2 * k, s, m, a, b), upd(2 * k + 1, m, e, a, b);
        st[k] = f(st[2 * k], st[2 * k + 1]);
    }
    T query(ll k, ll s, ll e, ll a, ll b) {
        if (s >= b || e <= a) return tneut;
        push(k, s, e);
        if (s >= a && e <= b) return st[k];
        ll m = (s + e) / 2;
        return f(query(2 * k, s, m, a, b), query(2 * k + 1, m, e, a, b));
    }
    void upd(ll a, ll b) { upd(1, 0, n, a, b); }
    T query(ll a, ll b) { return query(1, 0, n, a, b); }
};

void solve(){
	ll n, q; cin>>n>>q;
    vi a(n);
    fore(i, 0, n)cin>>a[i];
    Tree st(a);
    fore(i, 0, q){
        ll op; cin>>op;
        if(op==1){
            ll l, r; cin>>l>>r;
            st.upd(l, r);
         } else {
            ll x; cin>>x;
        }
        cout<<a<<endl;
    }

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
