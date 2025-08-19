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

/*
- Busco la tira mas larga, (me guardo el resultado)
- GUardo la posicion de i de la tira 
- Recorro ese i 
- Recorro (resultado/2) y el siguiente son las coordenadas a retornar

*/
void solve(){
    ll n; cin>>n; ll m; cin>>m;
    vector<vector<char>> a(n, vector<char>(m));
    vector<string> b(n);
    fore(i, 0, n){
        string s; cin>>s;
        b[i] = s;
    }
    fore(i, 0, n){
        string ai  = b[i];
        fore(j, 0, sz(ai)){
            char bi = ai[j];
            a[i][j] = bi;
        }
    }
    ll maxact = 0;
    ll totact = 0;
    ll posi = 0;
    fore(i, 0, n){
        totact = 0;
        fore(j, 0, m){
            //cout<<a[i][j]<<" ";
            if(a[i][j] == '#'){
                totact++;
                //cout<<"entro"<<endl;
            }
        }
        //cout<<endl;
        if(totact>maxact){
            maxact = totact;
            posi = i;
        }
    }
    ll cont = 0;
    ll res = (maxact/2)+1;
    //db(maxact); db(cont); db(res); db(posi); 
    fore(j, 0, m){
        if(a[posi][j]=='#'){
            cont++;
            if(cont == res){
                cout<<posi+1<<" "<<j+1<<"\n";
                return;
            }
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
