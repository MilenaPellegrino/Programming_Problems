#include<bits/stdc++.h>
using namespace std;
#define fore(i,a,b) for(ll i=(a);i<(b);i++)
#define rof(i, a, b) for(ll i=(b);i>(a);i--)
#define forn(e,c) for(const auto &e : (c))
#define db(x) cout<<#x<< " = "<<(x)<<endl
#define RAYA cout<<"=============="<<"\n"
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

set<char> letters = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
set<char> numbers = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
set<ll> nums = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
string YES = "YES\n"; 
string NO = "NO\n";

void solve(){
    ll n; cin>>n;
    ll m; cin>>m;
    vi a(n); fore(i, 0, n)cin>>a[i]; 
    vi b(m+1); fore(i, 0, m)cin>>b[i];
    
    // SE PUEDE 

    ll cont = 0;
    ll i = 0, j = 0;
    while(i<n && j <m){
        if(a[i] >= b[j]){
            i++; 
            j++; 
            cont++;
        }else{
            i++;
        }
    }
    if(cont == m){
        pri(0);
        return;
    }

    // HAY QUE AGREGAR 
    // IDEA -> Eliminar algun b y que se pueda hacer el greedy 
    vi f(m), r(m);

    // f(m) -> Gasta donde se llega en a cuando se hace el greedy de izq a der. COn esto puedo saber el final del recorrido si elimino una flor 

    // r(m) -> Es lo mismo solo que es el inico del recorrido
    // Greedy desde la izquierda: 
    i = 0; 
    fore(j, 0, m){
        while(i<n && a[i] < b[j]){
            i++;
        }

        // Hasta que posicion llegamos: 
        f[j] = i;

        i++;
    }

    // Greedy desde la derecha: 
    i = n - 1;
    for(ll j = m-1; j>= 0; j--){
        while(i>=0 && a[i] < b[j]){
            i--;
        }
        r[j] = i;

        i--;

    }
    
    // Buscamos que b[i] podemos eliminar (el minimo b[i])
    ll res = 1e9 + 10;
    fore(j, 0, m){
        ll ant = f[j-1];
        if(j == 0){
            ant = -1;
        }

        ll sig = r[j+1];
        if(j== m-1){
            sig = n;
        }
        if(ant<sig){
            res = min(res, b[j]);
        }
    }

    if(res!= 1e9+10){
        pri(res);
    }else{
        pri(-1);
    }
    return;
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
