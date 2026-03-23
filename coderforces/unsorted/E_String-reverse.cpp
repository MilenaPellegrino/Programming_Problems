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

const ll MAXN = 2e5 + 10;
ll ft[MAXN+1];
void upd(ll i0, ll v){ 
	for(ll i=i0+1;i<=MAXN;i+=i&-i)ft[i]+=v;
}
ll get(ll i0){
	ll r=0;
	for(ll i=i0;i;i-=i&-i)r+=ft[i];
	return r;
}
ll get_sum(ll i0, ll i1){
	return get(i1)-get(i0);
}

void solve(){
    ll n; cin>>n; 
    string s; cin>>s;

    // Voy a guardar las posiciones en donde aparece cada letra. 
    // EJEMPLO: "ABA"
    // pos[0] = "0, 2"
    // pos[1] = "1"

    queue<ll> pos[26];
    fore(i, 0, n) {
        pos[s[i] - 'a'].push(i);
    }

    // El string t va a ser el objetivo, el reverso al que queremos contarles las inversiones 
    string t = s;
    reverse(all(t));
    // t = "ABA"

    // Necesito crear un arreglo de numeros eqwuivalentes a las letras
    // para poder usar el fenwick tree  para contar cuantos swaps necesito apra ordenar ese arreglo 

    /*
        n = 3
        i = 0
        char_idx = t[0] = 'a' - 'a' = 0 
        target_indices[0] = pos[0].front() = 0
        pos[0].pop() => pos[0] = "2"

        i=1 
        char_idx = t[1] = 'b' - 'a' = 1
        target_indices[1] = pos[1].front() = 1 
        pos[1].pop() => pos[1] = " "

        i=2 
        char_idx = t[2] = 'a' - 'a' = 0
        target_indices[2] = pos[0].front() = 2 
        pos[0].pop() => pos[0] = " "   
        
        => target_indices = [0, 1, 2]
    */

    vi target_indices(n);
    fore(i, 0, n) {
        ll char_idx = t[i] - 'a';
        target_indices[i] = pos[char_idx].front();
        pos[char_idx].pop();
    }

    // Contamos inversiones con el Fenwick Tree

    ll swaps = 0;
    fore(i, 0, n) {
        ll original_pos = target_indices[i];
        swaps += (i - get(original_pos));

        upd(original_pos, 1);

    }
    cout<<swaps<<endl;

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
