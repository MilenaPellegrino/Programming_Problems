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

// SAQUE DE INTERNET (ED MI NOTEBBOOK) LA PLANTILLA PARA LA BUSQUEDA B INARIA EN LA RESPUESTA:
// LINK: https://github.com/MilenaPellegrino/Programming_Problems/tree/master/!book
ll n; ll k;
vector<pair<ll, ll>> bodeg;
bool can(ll mid, vi &per){
    ll i = 0;  // nuestra bodega actual 
    vi capact(k);
    fore(j, 0, sz(bodeg)){
        ll capa = bodeg[j].snd;
       capact[j] = capa;
    }
    // greedy de la binary search 
    fore(j, 0, sz(per)){
        // while(i<k){
        //     if(per[j]>bodeg[i].fst + mid){
        //         i++;
        //     }else if(capact[i] == 0){
        //         j++;
        //     }else{
        //         break;
        //     }
        while(i<k && (per[j]>bodeg[i].fst + mid || capact[i] == 0)){
            i++;
        }

        // verificacion del rango correcto :
        ll rest = abs(per[j] - bodeg[i].fst); 
        if(i==k)return false; // no hay ninguna bodega a donde meter a la persona
        if(rest > mid)return false; 


        // // if(i==k)return false; // no hay ninguna bodega a donde meter a la persona

        capact[i]--;
        
    }
    return true;
}
void solve(){
    cin>>n>>k;
    //ll n; cin>>n; ll k; cin>>k;
    vi p(n); fore(i, 0, n)cin>>p[i];
    vi b(k); fore(i, 0, k)cin>>b[i];
    vi c(k); fore(i, 0, k)cin>>c[i];
    //vector<pair<ll, ll>> bodeg(k);
    bodeg.resize(k);
    // (pos, capa)
    fore(i, 0, k){
        ll pos = b[i];
        ll cap = c[i];
        bodeg[i] = {pos, cap};
    }
    sort(all(p)); 
    sort(all(bodeg));

    ll l = 0, r = 1e9 + 10; 
    ll res = -1;
    while(l<= r){
        ll mid = (l + r) / 2;
        if(can(mid, p)){
            res =mid;
            r = mid - 1;
        }else{
            l = mid + 1;
        }
    }
    pri(res);
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