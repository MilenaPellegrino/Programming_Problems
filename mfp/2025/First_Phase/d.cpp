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

const double PI = 3.14159265359;

void solve() {
    ll r[4];
    cin>>r[1]>>r[2]>>r[3]; 
    r[0] = -1;
    ll n, q; cin>>n>>q; 
    while(q--){
        ll c1, l1, c2, l2; cin>>c1>>l1>>c2>>l2; 

        // Caso especial 
        if(c1 == c2 && l1 == l2){
            cout<<fixed<<setprecision(10)<<0.0<<"\n"; 
            continue;
        }

        double dif_lineas = min(abs(l1 - l2), n-abs(l1 - l2)); // Circular 
        double angl = dif_lineas * (2.0 * PI / n);


        if (c1 == c2){
            // caso donde tamo en el mismo circulo, pero hay que movermos por su circun
            cout << fixed<<setprecision(10)<<angl * r[c1] << "\n";
        } else {

            // Caso 1: simplemente la linea recta 
            if(l1 == l2){
                double res = abs(r[c1] - r[c2]);
                cout<<fixed<< setprecision(10) << res <<"\n";
                continue;
            }

            // Caso 2: UN mix de frutas

            double cas1 = angl * r[c1] + abs(r[c2] - r[c1]); 
            double cas2 = angl * r[c2] + abs(r[c2] - r[c1]);

            double mins = min(cas1, cas2);

            cout<<fixed<<setprecision(10)<<mins<<"\n";
        }
        //ll dist_derec = r[c2] - r[c1];
        //db(dist_derec);
        //cout<<fixed<<setprecision(10)<<dist_circ<<"\n";
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