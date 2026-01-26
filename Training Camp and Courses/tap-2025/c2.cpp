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
     

    // P = [3, 6, 1, 4, 2, 5]
    // S(P) = 3 (por 1, 3, 4)
    ll n = 1000;
    vi a; 
    vi tots;
    bool semi_fixed(vi a, ll i){
        return a[a[i] - 1] == i+1;
    }

    ll amn(vi a, ll n){
        ll cont = 0;
        cout<<endl;
        fore(i, 0, n){
            if(semi_fixed(a, i)){
                cout<<i+1<<"\n";
                cont++;
            }
        }
        return cont;
    }

    void rot(ll n){
        ll fstt = a[0];
        fore(i, 0, n-1){
            a[i] = a[i+1];
        }
        a[n-1] = fstt;
    }

    void rot2(ll n){
        ll fstt = tots[0];
        fore(i, 0, n-1){
            tots[i] = tots[i+1];
        }
        tots[n-1] = fstt;
    }
    void solve(){
        cin>>n; 
        ll res = 0;
        a.resize(n);
        tots.resize(n);
        fore(i, 0, n)cin>>a[i];
        fore(j, 0, n){
            cout<<"Rotation: "<<j;
            ll cant = amn(a, n);
            cout<<"Total: "<<cant<<"\n";
            tots[j] = cant;
            res+= cant;
            rot(n);
            cout<<"\n";
        
        }
        pri(res);
        cout<<"Permus: "<<endl;
        fore(i, 0, n){
            cout<<tots<<endl;
            rot2(n);
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