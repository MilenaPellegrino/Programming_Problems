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

// 3 5
// CAPTURA 1 10
// CAPTURA 2 6
// ROBO 3 1 4
// CAPTURA 3 2
// ROBO 2 1 10

void solve(){
    ll n; cin>>n;
    ll m; cin>>m; 
    cin.ignore();
    vi a(n+1, 0);
    vi caps(n+1, 0);
    while(m--){
        string s; 
        getline(cin, s);
        stringstream ss(s);
        string word; 
        ss>>word;

        // cout<<s<<endl;
        // cout<<s[6]<<" "<<s[7]<<" "<<s[8]<<" "<<s[9]<<" "<<s[10]<<" "<<endl;
        if(word == "CAPTURA"){ // captura
            ll parti, cant;
            ss>>parti>>cant;
            //db(parti); db(cant);
            a[parti] += cant;
            caps[parti]++;
            // string word; 
            // ll parti,  cant;            
            // ll parti = s[8] - '0'; 
            // //ll parti = stoi(s[8]);
            // ll cant = s[10] - '0';
            // //ll cant = stoi(s[10]);
            // db(parti); db(cant);
        }else{ // robo
            ll parti, roboa, cant;
            ss >> parti >> roboa >> cant;
            ll robs = min(cant, a[roboa]);
            //db(parti); db(roboa); db(cant);
            a[parti] += robs; 
            a[roboa] -= robs;
        }

    }
    ll win = 1;
    fore(i, 2, n+1){
        if(a[i] > a[win]){
            win = i;
        }else if(a[i] == a[win]){
            if(caps[i] > caps[win]){
                win = i;
            } else if (caps[i] == caps[win]){
                if(i<win){
                    win = i;
                }
            }
        }
    }
    cout<<win<<"\n";
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