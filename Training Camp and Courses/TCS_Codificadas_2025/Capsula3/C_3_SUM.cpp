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
    vi a(n); fore(i, 0, n)cin>>a[i];

    vi cant(11, 0); 
    fore(i, 0, n){
        ll nums = a[i]; 
        string sact = to_string(nums); 
        char ult = sact[sz(sact)-1]; 
        ll num = ult - '0';
        cant[num]++;
    }
    //cout<<"SE ROMPIO"<<endl;
    vector<array<ll, 3>> b;
    // Combianciones entre 3 elementos que el ultimo digitos sea 3 
    ll tot = 0;
    //ll l=0;
    fore(i, 0, 10){
        fore(j, 0 ,10){
            fore(k, 0, 10){
                ll sum = i + j + k;
                string res = to_string(sum);
                if(res[sz(res)-1] == '3'){
                    //cout<<i<<" "<<j<<" "<<k<<"\n";
                    //tot++;
                    b.pb({i, j, k});
                    //l++;
                }
            }
        }
    }
    //cout<<"NO FUNCIONA "<<endl;
    vi cant2(11, 0); 
    
    // recorro mi b, y veo si la combinacion esta en mi cant
    //cout<<cant<<endl;
    // cant = [ 0 3 1 0 0 0 0 0 0 0 0 ]
    // b =[[1, 2, 3], [4, 5, 6]] 
    fore(i, 0, sz(b)){
        cant2 = cant;
        ll a1 = b[i][0]; 
        ll a2 = b[i][1];
        ll a3 = b[i][2];
        //db(a1); db(a2); db(a3);
        //cout<<cant2<<endl;
        if(cant2[a1]>0){
            //cout<<"entro aca1"<<endl;
            cant2[a1]--;
            if(cant2[a2]>0){
                //cout<<"entro aca tmb"<<endl;
                cant2[a2]--;
                if(cant2[a3]>0){
                    //cout<<"entro aca bro"<<endl;
                    cout<<"YES\n";
                    return;
                }
            }
        }
    }
    //cout<<"QUE VERGA DE PROGRAMA "<<endl;
    cout<<"NO\n";
    return;
    //db(tot);
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
