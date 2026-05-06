#include<bits/stdc++.h> 
using namespace std; 

#define fore(i, a, b) for(ll i=(a);i<(b); i++)
#define all(x) (x).begin(), (x).end()
#define pb push_back 
#define fst first 
#define snd second 
#define sz(x) ((int)x.size())
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using ll = long long; 
typedef vector<ll> vi;
 
int main(){FIN;
   ll n; cin>>n; 
   vector<string> gu;
   while(n--){
    string s; cin>>s; 
    gu.pb(s);
   }
   fore(i, 0, sz(gu)){
          cout<<"dfdsaf"<<endl;
    vi a(30, 0);
    fore(i, 0, sz(s)){
        ll posi = s[i] - 'a' + 1; 
        a[posi]++; 
    }
    cout<<"aaaaaa"<<endl;
    bool flag = false;
    string res; 
    fore(i, 0, sz(a)){
        if(a[i] == 0){
            char c = 'a' + i;
            res += c;
            flag = true;
        }
    }
    cout<<"bbbb"<<endl;
    cout<<res<<endl;
    fore(i, 0, sz(a)){
        if(a[i]!= 0){
            char c = 'a' + i;
            res += c;
        }
    }
cout<<"cccc"<<endl;
    if(flag){
        cout<<"YES\n"; 
        cout<<res<<"\n";
    }else{
        cout<<"NO\n";
    }


   }
   return 0;
}