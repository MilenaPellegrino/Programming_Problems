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

/*
YO LO QUE HAGO ES ELIMINAR EL ELEMENTO MAXIMO 
TENGO QUE ADEMAS DE BUSCAR EL ELEMENTO MAXIMO,
LA CANTIDAD DE ESOS ELEMENTOS QUE HAY EN CADA COSA 
POR EJEMPLO: 
1 2 3 2
3 2 1 3
2 1 3 2

EN ESTO LO OPTIMO ES RESTAR EN LA COLUMNA 3 Y LA FILA 2 
PERO SEGUN MI ALGORITMO LO QUE HACE ES RESTAR EN LA FILA 1 Y LA COLUMNA 1 
LO QUE SEGUN YO IMPRIMO 3 PERO EN REALIDAD ES 2 
*/
void solve(){
    ll n; cin>>n;
    ll m; cin>>m; 
    vvi a(n, vi(m));
    fore(i, 0, n){
        fore(j, 0, m){
            cin>>a[i][j];
        }
    }

    ll filam = -1; 
    ll colm = -1;
    ll maxf = -1;
    ll maxc = -1; 

    // fore(i, 0, n){
    //     fore(j, 0, m){
    //         cout<<a[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    // buscamos el maximo en las filas: 
    fore(i, 0, n){
        ll maxfa = -1;
        fore(j, 0, m){
            maxfa = max(maxfa, a[i][j]);
        }
        if(maxfa > maxf){
            maxf = maxfa;
            filam = i;
        }
    }
    // cout<<endl<<endl;

    // restamos este valor maximo: 
    fore(j, 0, m){
        a[filam][j] = a[filam][j] - 1;
    }

    // fore(i, 0, n){
    //     fore(j, 0, m){
    //         cout<<a[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    // buscamos el maximo en las columnas: 
    fore(j, 0, m){
        ll maxca = -1;
        fore(i, 0, n){
            maxca = max(maxca, a[i][j]);
        }
        if(maxca > maxc){
            maxc = maxca;
            colm = j;
        }
    }

    fore(i, 0, n){
        a[i][colm] = a[i][colm] - 1;
    }
    a[filam][colm] = a[filam][colm] + 1;
    ll maxv = 0;
    fore(i, 0, n){
        fore(j, 0, m){
            maxv = max(maxv, a[i][j]);
        }
    }
    cout<<maxv<<"\n";

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