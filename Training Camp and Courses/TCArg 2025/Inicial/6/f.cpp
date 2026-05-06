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
   
    ll t; cin>>t; 
    while(t--){
        string s; cin>>s; 
        vector<pair<ll,ll>> chars(30);
        fore(i,0,30){
            chars[i]={0,i};
        }
        for(auto c : s){
            cout << c-'a' << "\n";
            chars[c-'a'].fst++;
        }
        sort(all(chars));

        ll distintos, idx;
        fore(i,0,30){
            cout << chars[i].fst << " " << chars[i].snd << "\n";
            if(chars[i].fst==0){
                idx=i+1;
            }
            else{
                distintos=30-i;
                break;
            }
        }

        
        if(distintos==1){
            if (chars[idx].fst==1){
                cout <<"YES\n" << static_cast<char>(chars[idx].snd + 'a') <<"\n";
            } else {
                cout <<"NO\n";
            }
        }

        if(distintos==2){
            if (chars[idx].fst + chars[idx+1].fst == 3){
                cout <<"YES\n";
                string ss = "";
                ss += static_cast<char>(chars[idx].snd + 'a');
                ss += static_cast<char>(chars[idx+1].snd + 'a');
                ss += static_cast<char>(chars[idx+1].snd + 'a');
                cout <<reverse(all(s))<<"\n";
            } else {
                cout <<"NO\n";
            }
        }
        
        // map<char, ll> mp; 
        // for(char ss:s){
        //     mp[ss]++;
        // }
        // bool flag = false; 
        // for(const auto& pair : mp) {
            
        // }
    }
   return 0;
}