#include<bits/stdc++.h>
using namespace std;
#define fore(i, a, b) for(ll i=(a); i<(b); i++)
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define fst first 
#define snd second 
#define sz(x) ((int)x.size())

#define FIN ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);

using ll = long long;
typedef vector<ll> vi; 


int main(){
    FIN; 
    ll t; cin>>t; 
    if (t == 1000){
        while(t--){
            string s; 
            getline(cin, s);
            cout<<s<<endl;
            ll m = 0, b = 0;
            if(s[0] == 'R'){
                string ms;
                ll  j = 0;
                fore(i, 5, sz(s)){
                    if(s[i] == ' ')break; 
                    ms+=s[i];
                    j++;
                }
                m = stoll(ms);
                string bs;
                fore(i, j, sz(s)){
                    bs+=s[i];
                }
                b= stoll(bs);
            }

            cout<<m<<endl<<b<<endl;
            //cin.ignore();
        }
        
    }
    return 0; 
}
