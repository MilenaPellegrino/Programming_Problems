#include<bits/stdc++.h>
using namespace std;
#define fore(i,a,b) for(int i=(a);i<(b);i++)
#define forr(i, a, b) for(int i=(b);i>(a);i--)
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
using pll = pair<ll,ll>;
using vii = vector<int>;
using vi = vector<ll>;
using vpi = vector<pii>;
template<class T>ostream&operator<<(ostream&o,vector<T>const&v){o<<"[ ";for(auto const&x:v)o<<x<<" ";return o<<"]";}

set<char> letters = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'}; 
set<char> numbers = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'}; 

bool mas_10(string s){
    return sz(s)>10;
}

bool let_dig(string s){
    bool let = false; 
    bool num = false; 
    fore(i, 0, sz(s)){
        if(letters.count(s[i])) let = true;
        if(numbers.count(s[i])) num = true;
    }
    return let && num;
}

bool dig_dsp(string s){
    bool let = false; 
    fore(i, 0, sz(s)){
        if(letters.count(s[i]))let = true;
        if(numbers.count(s[i]) && let)return false;
    }
    return true;
}


bool dig_ord(string s){
    fore(i, 0, sz(s)-1){
        if(s[i]>s[i+1] )return false;
    }
    return true;
}

bool let_ord(string s){
    fore(i, 0, sz(s)-1){
        if(s[i]>s[i+1])return false;
    }
    return true;
}

void solve(){
	ll n; cin>>n; 
    while(n--){
        string s; cin>>s; 
        string nums; 
        string letts; 
        fore(i, 0, sz(s)){
            if(letters.count(s[i]))letts+= s[i];
        } 
        fore(i, 0, sz(s)){
            if(numbers.count(s[i]))nums += s[i];
        }
        bool uno = mas_10(s); 
        bool dos = let_dig(s);
        bool tres = dig_dsp(s); 
        bool cuatro = dig_ord(nums); 
        bool cinco = let_ord(letts); 
        //db(uno); db(dos); db(tres); db(cuatro); db(cinco);
        bool res = uno && dos && tres && cuatro && cinco; 
        if(res){
            cout<<"S"<<"\n";
        } else{
            cout<<"N"<<"\n";
        }
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
