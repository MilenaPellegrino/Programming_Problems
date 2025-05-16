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

ll f(ll x){
    ll ans = 1;
    while(x>0){
        ans *= x %10;
        x /=10;
    }
    return ans;
}

void solve(){
    ll n; cin>>n;  
    ll ans = 0;
    ans = max(ans, f(n));  // mult de todos  ans = 0

    string s = to_string(n); 
    ll ans_aux = 1;
    fore(i, 0, sz(s) - 1){  // Le sacamos el primer digitos porque somos re capos y ponemos los otros en 9
        ans_aux *= 9; 
    }
    ans = max(ans, ans_aux); 
    // Aca viene la parte heavy del programa, vamo a ver que onda 
    fore(i, 0, sz(s)){
        //db(ans);
        if(s[i] == '0') continue;  // si es 0 es un boludo 

        string saux = s;  // vamo a laburar con algo igual pa no modifica nuestro s
        saux[i] = s[i] - 1; 
        fore(j, i+1, sz(saux)){
            saux[j] = '9';
        }  
        ll a = stoll(saux); 
        ans = max(ans, f(a)); 

    }
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
