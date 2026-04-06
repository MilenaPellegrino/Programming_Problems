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
    ll n; cin>>n; ll m; cin>>m;
    vector<string> mat(n); 
    fore(i, 0, n){
        string s; cin>>s;
        mat[i] = s;
    } 
    // idea = fijarse siu  hay una linea toda entera vertical 
    //PASOS 
    // 1 Buscar la ultima columna, de la primera que tenga un *  
    // 2 revisar para cada fila donde haya un *, si la ultimaa columna tiene un *
    // si todas tienen, entonces es un 3, sino es un 2 


    // 1 - buscamos la primer fila qeu tenga un *
    ll primfila = 0; 
    fore(i, 0, n){
        bool enc = false;
        for(auto c : mat[i]){
            if(c=='*'){
                primfila = i;
                enc = true;
                break;
            }
        }
        if(enc)break;
    }
    //db(primfila);

    // 2 - recorremos hasta la ultima columna que tiene * de la primer fila
    ll ultcol = -1; 
    for(ll i = m-1; i>=0; i--){
        if(mat[primfila][i] == '*'){
            ultcol = i;
            break;
        }
        //ultcol--;
    }

    //db(ultcol);

    // 3 - para cada fla siguiente a partir de la primfila, verificamos qeu en la ultcol haya un * 

    bool estres = true; 
    fore(i, primfila, n){
        if(mat[i][ultcol] != '*'){
            estres = false; 
            break;
        }
    }

    // CREO QUE EL ERROR ES QUE CON UNA SOLA LINEA VERTICAL NO TENGO TODOS LOS CASOS PARA TRES, YA QUE PUEDE SER DOS, PORQUE  TIENE DOS LINEAS 
    ll cantv = 0;
    fore(j, 0, m){
        ll cont = 0;
        fore(i, 0, n){
            if(mat[i][j] == '*')cont++;
            else cont = 0;
            // if(cont>=2){
            //     cantv++;
            //     break;
            // }
                        if(cont>=3){
                cantv++;
                break;
            }
        }
    }
    // if(cantv == 1 || estres){

    // }
    if(cantv == 1){
        cout<<"Triple Corolla Flower"<<"\n";
    }else{
        cout<<"Double Petal Flower"<<"\n";
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