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
    ll m, q; cin>>m>>q;
    vi b(m); fore(i, 0, m)cin>>b[i]; // profesores
    vi a(q); fore(i, 0, q)cin>>a[i]; // david
    sort(all(b));
    // a la izquierda

    // a la derecha 

    // === entre medio 
    // busco el profe mas a la izquierda:
    //cout<<b<<endl;
    fore(i, 0, q){
       // db(a[i]);
        ll izq = 0, der = 0;
        ll res = 0;

        // me devuelve un iterado al primer elemento que no es menor que a[i] (>= a[i])
        auto it = lower_bound(all(b), a[i]);  
        // como yo quiero el mas cercano por la izquierda retrocedo uno 
       // db(*it);
        if(it == b.begin()){
            // no hay un numero menro o igual al profe 
            // por lo tanto david esta a la izquierda del todo
           // cout<<"entro aca"<<endl;
            //--it;
           // db(*it);
            res = (*it) - 1; 
           // db(res);
        }else if(it == b.end()){
            // no existe un numero mayor o igual al profe 
            // por lo tanto david esta a la derecha del todo 
           // cout<<"entro en este"<<endl;
            --it;
          //  db(*it);
            res = n-(*it);
          //  db(res);
        }else{
          //  cout<<"entro aqui"<<endl;
           // db(*it);
            der = *it;
           // db(der);
            --it;
            izq = *it;
          //  db(izq);
            //res = min(der - a[i], a[i] - izq);
            ll rest1 = der - a[i]; 
            ll rest2 = a[i] - izq;
            res = (rest1 + rest2)/2;
            //  db(res);
           // pri(res);
        }
        pri(res);
       // RAYA;
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
