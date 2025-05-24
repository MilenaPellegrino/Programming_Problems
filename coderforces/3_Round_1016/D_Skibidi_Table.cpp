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

// Función recursiva para obtener el valor en la posición (x, y)
ll getValue(int n, ll x, ll y) {
    if (n == 0) return 1; // Caso base: tabla 1x1 tiene solo el número 1

    ll half = 1LL << (n - 1);         // Mitad del tamaño actual
    ll blockSize = 1LL << (2 * (n - 1)); // Cantidad de valores en cada cuadrante

    if (x <= half && y <= half) {
        // Cuadrante 0: arriba izquierda
        return getValue(n - 1, x, y);
    } else if (x <= half && y > half) {
        // Cuadrante 1: arriba derecha
        return blockSize + getValue(n - 1, x, y - half);
    } else if (x > half && y <= half) {
        // Cuadrante 2: abajo izquierda
        return 2 * blockSize + getValue(n - 1, x - half, y);
    } else {
        // Cuadrante 3: abajo derecha
        return 3 * blockSize + getValue(n - 1, x - half, y - half);
    }
}

// Función recursiva para obtener la posición (x, y) que contiene el valor d
pair<ll, ll> getCoordinates(int n, ll d) {
    if (n == 0) return {1, 1}; // Caso base: única posición posible

    ll half = 1LL << (n - 1);         // Mitad del tamaño actual
    ll blockSize = 1LL << (2 * (n - 1)); // Cantidad de valores por cuadrante

    if (d <= blockSize) {
        // Cuadrante 0: arriba izquierda
        return getCoordinates(n - 1, d);
    } else if (d <= 2 * blockSize) {
        // Cuadrante 1: arriba derecha
        auto [x, y] = getCoordinates(n - 1, d - blockSize);
        return {x, y + half};
    } else if (d <= 3 * blockSize) {
        // Cuadrante 2: abajo izquierda
        auto [x, y] = getCoordinates(n - 1, d - 2 * blockSize);
        return {x + half, y};
    } else {
        // Cuadrante 3: abajo derecha
        auto [x, y] = getCoordinates(n - 1, d - 3 * blockSize);
        return {x + half, y + half};
    }
}

void solve(){
    ll n; cin>>n;
    ll q; cin>>q;
    cin.ignore();
    while(q--){
        string s; 
        getline(cin, s);
        if (s == "->"){
            ll x, y; cin>>x>>y; 
            // Special case: 
            if (n==0){
                cout<<1<<"\n";
                continue;
            }
            ll res = getValue(n, x, y);
            pri(res);
        } else {  // case <-
            ll num; cin>>num;
            pair<ll, ll> res = getCoordinates(n, num);
            cout<<res.fst<<" "<<res.snd<<"\n";
        }
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