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
    ll n; cin>>n; ll k; cin>>k;
    vector<string> base(n); 
    fore(i, 0, n){
        string s; cin>>s; 
        base[i] = s;
    }
    //cout<<base<<endl;
    // hacemos lo q dice el problema de una manera iterativa 
    vector<string> res; 
    res = base;
    fore(ii, 2, k+1){
        ll tamact = sz(res);
        //db(tamact);
        ll tamx = tamact * n;
        //ll tamy = 
        // rellenar con "." para hacer el reemplazo bien DIOSSS ESTO ANDABA MAL
        vector<string> sigi(tamx, string(tamx, '.'));
        //vector<string> sigi(tamx, string(tamx, '#'));
        fore(i, 0, tamact){
            fore(j, 0, tamact){
                //RAYA
                if(res[i][j] == '#'){
                    // hacemos el reemplazo con la base
                    fore(l, 0, n){
                        // RAYA
                        fore(p, 0, n){
                            ll posx = (i * n) + l;
                            ll posy = (j * n) + p;
                            //db(posx);
                            //db(posy);
                            // RAYA;
                            sigi[posx][posy] = base[l][p];
                        }
                    }
                }
            }
        }
        //ii += sz(sigi); 
        //ii += tamx;
                // fore(i, 0, sz(res)){
        //     cout<<sigi[i]<<endl;
        // }
        res = sigi;
        // fore(i, 0, sz(res)){
        //     cout<<res[i]<<endl;
        // }
        //db(res);
    }

    fore(i, 0, sz(res)){
        cout<<res[i]<<"\n";
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