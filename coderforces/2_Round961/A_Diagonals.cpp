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

ll f(ll n, ll k){
    if(k==0)return 0;
    vi dig;
    for (ll d = 2; d <= 2 * n; ++d) {
        if (d <= n + 1) {
            dig.pb(d - 1);
        } else {
            dig.pb(2 * n + 1 - d);
        }
    }
    sort(all(dig), greater<>());
    ll oc = 0;
    for (ll capacity : dig) {
        if (k <= 0) {
            break;
        }
        oc += 1;
        k -= capacity;
    }

    return oc;
}
void solve(){
    ll n, k; cin>>n>>k;
    ll res = f(n, k);
    pri(res);
   // ll dig = 2 * (n-1) + 1;
    // if(k==0){
    //     pri(0);
    //     return;
    // }
    // ll dig = 0;
    // while(k>0){
    //     dig++;
    //     k-=1;
    //     if(k>0){
    //         k-= (dig-1);
    //     }
    // }
    // if(k>=dig){
    //     pri(dig);
    //     return;
    // }
    // ll cont = 1;
    // k-= n;
    // ll i = n-1;
    // ll act = 0;
    // while(k>0){
    //     if(act == 0){
    //         k-=i;
    //         cont++;
    //         act++;
    //     } else{
    //         k-=i;
    //         cont++;
    //         act = 0;
    //         i--;
    //     }
    // }
    // pri(cont);
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
