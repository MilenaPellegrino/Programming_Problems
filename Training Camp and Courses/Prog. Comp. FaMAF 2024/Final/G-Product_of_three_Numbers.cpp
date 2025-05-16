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
12345 = 3 * 5 * 823
12345 = a * b * c 

c > b > a 
a < b < c 
 c-  max 
 b - min 


*/
void solve(){
	ll n; cin>>n; 
	set<int> ds; 
    // set_name.count (element); 
    /*
    fore(i, 2, n){
        if(n % i == 0) {
            n /= i;
			ds.insert(i);
			//n /= i;
			break;
		}
    }
    fore(i, 2, n){
        if(n % i == 0 ) {
            n /= i;
			ds.insert(i);
			//n /= i;
			break;
		}
    }
    */
	for(ll i = 2; i * i <= n; ++i) {
		if(n % i == 0 && !ds.count(i)) {
            //cout<<n<<"\n";
            n /= i;
			ds.insert(i);
			//n /= i;
			break;
		}
	}
    /*
    
    12345
4115
YES
3 5 823
*/
   // cout<<n<<endl;
	for (int i = 2; i * i <= n; ++i) {
		if (n % i == 0 && !ds.count(i)) {
                n /= i;
				ds.insert(i);
				break;
			}
		}
    /*
        for ( auto elem : ds){
        cout<<elem<<" "}
    */
   // cout<<n<<endl;
   // cout<<ds.count(n); ev dupl
    if (sz(ds) >= 2 && !ds.count(n)){
        cout<<"YES\n"; 
        for(auto elem: ds)cout<<elem<<" ";
        cout<<n<<"\n";
    } else {
        cout<<"NO\n";
    }
    //cout<<"\n";
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
