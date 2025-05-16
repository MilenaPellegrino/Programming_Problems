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

// BINARY SEARCH

// Verificar si podes encontrar tres rangos de longitud 2t que cumbra a todos los clientes
bool can(ll t, vi &a){
    ll irang = 0; // Comenzamos con el primer cliente
    ll workers = 1;  // Comenzamos asignado el trabajador 1

    fore(i, 0, sz(a)){
        if(a[i] > a[irang] + 2 * t){  // Si la difs es mayor que 2t necesitamos otro trabajador para ese rango
            irang = i;
            workers++;
        }
    }
    //db(workers);
    return workers <= 3;  // Si necesitamos mas de  3 trabajadores no podemos hacerlo en ese tiempo
}
void solve(){
	ll n; cin>>n; 
    vi a(n);
    fore(i, 0, n)cin>>a[i];
    sort(all(a));

    // Busqueda binaria de toda la vida 
    ll l = 0, r = 1e9;
    //cout<<a<<endl;
    //db(r);
    while (l < r) {
        ll mid = (l + r) >> 1;   // div por dos 
        //db(l); db(r); db(mid);
        //db(can);
        if (can(mid, a)) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    pri(r);
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
