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
    ll n; cin>> n;
    vi a(n), b(n);
    fore(i, 0, n)cin>>a[i];

    ll cnt = 0, cnt2 = 0;
    ll sum = 0, sum2 = 0;
    
    // COntar los factores de 2 iniciales 
    fore(i, 0, n){
        // Mas rapido

        // Contamos en el actual
        while (a[i] % 2 == 0){
            a[i] /= 2;
            cnt++;
        }

        // Contamos en el siguiente 
        ll j = i + 1;
        while (j % 2 == 0){
            j /= 2;
            cnt2++;
        }

        // Guardar los resultados
        a[i] = cnt;
        sum += cnt;
        sum2 += cnt2;
        b[i] = cnt2;

        // Restablecer contador
        cnt = 0;
        cnt2 = 0;
    }

    // Si ya es div (ya hay suf. fact. de dos)
    if (sum >= n){
        pri(0);
        return;
    }

    // Si no se puede con las incrementaciones 
    if (sum + sum2 < n){
        pri(-1);
        return;
    }

    // Ordenamos todos los incrementos al reves para maximizar 
    sort(all(b), greater());

    // Aplicamos la operacion hasta que se cumpla
    ll res = 0;
    fore(i, 0, n){
        res++;
        if (sum + b[i] >= n){
            pri(res);
            break;
        }
        sum += b[i];
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
