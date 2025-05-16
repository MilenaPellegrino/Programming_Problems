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
7 3
1 5 16 18 7 2 10
b a a  a  a c  a

a = {5, 16, 18, 7, 10}
b = {1}
c = {2}

ans = 1 + 2 + 18 + 16 + 10 + 7 

[1,3,4,5,6,7]
  with the total damage 1+16+18+7+2+10=54
.

*/
void solve(){
	ll n, k; cin>>n>>k;
    vi a(n);
    fore(i, 0, n)cin>>a[i];
    string s; cin>>s;
    vi aux;
    ll ans = 0;
    ll i = 0;
    while (i < n) {
        char act = s[i];
        vi dam;
        while (i < n && s[i] == act) {
            dam.pb(a[i]);
            ++i;
        }
        sort(all(dam), greater<ll>()); // Ordenar en orden descendente

        // Tomar hasta k golpes de este botón
        for (ll j = 0; j < min(static_cast<ll>(k), static_cast<ll>(dam.size())); ++j) {
            ans += dam[j];
        }
    }
    // fore(i, 0, n){
    //     if(s[i] == s[i+1]){  // Vemos si es el mismo boton
    //         aux.pb(a[i]);
    //         aux.pb(a[i+1]);
    //         i++; 
    //     }  else if (s[i] == s[i-1] && i == n-1){
    //         aux.pb(a[i]);
    //     }
    //     if (s[i]!= s[i+1] || f == n-1){  // joya se cambio de boton
    //         if(sz(aux) == 0){
    //             ans += a[i];
    //             continue;
    //         }
    //         sort(all(aux), greater<ll>());
    //         //cout<<aux<<endl;
    //         ll maxs = 0;
    //         if(sz(aux)>k){
    //             maxs = k;
    //         } else {
    //             maxs = sz(aux);
    //         }
    //         //ll maxs = max(sz(aux), k);
    //         fore(i, 0, maxs)ans+= aux[i];
    //         aux.clear();
    //         //ans += a[i];
    //         //cout<<"entre"<<endl;
    //     }
    //           //  cout<<"Arreglo act: "<<aux<<endl;
    //     //cout<<"It: "<<i<<endl;
    //    // db(ans);
    //     f++;
    // }
    pri(ans);
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
