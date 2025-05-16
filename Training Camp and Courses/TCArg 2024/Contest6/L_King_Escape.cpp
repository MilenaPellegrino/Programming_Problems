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

void solve(){
	ll n; cin>>n;
    ll x, y; cin>>x>>y;
    ll a, b; cin>>a>>b;
    ll c, d; cin>>c>>d;
    // fila reina ma arriba 
    bool flag1 = (x>a) && (x>c);
    // fila reina mas abajo
    bool flag2 = (x<a) && (x<c);
    bool res1= flag1 || flag2;

    // col reina ma a la derecha
    bool f1 =  (y>b) && (y>d);
    bool f2 = (y<b) && (y<d);

    bool res2 = f1 || f2;

    bool ans = res1 && res2;
    if(ans){
        pri("YES");
    } else {
        pri("NO");
    }
}
 
int main(){
    FIN; 
    int t = 1;
    //int t; cin>>t; 
    while(t--){
		solve();
	}
    return 0;
}
