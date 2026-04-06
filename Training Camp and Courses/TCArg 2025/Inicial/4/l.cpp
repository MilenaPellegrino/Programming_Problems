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
    FIN; string s;
    cin>>s;
    vector<string> names = {"Danil", "Olya", "Slava", "Ann", "Nikita"};
    ll c=0;
    fore(i, 0, sz(s)) {
        if(s[i]=='D') {
            if(i<sz(s)-4){
                if(s[i+1]=='a' && s[i+2]=='n' && s[i+3]=='i' && s[i+4]=='l'){
                    c++;
                }
            }
        }
        if(s[i]=='O') {
            if(i<sz(s)-3){
                if(s[i+1]=='l' && s[i+2]=='y' && s[i+3]=='a'){
                    c++;
                }
            }
        }
        if(s[i]=='S') {
            if(i<sz(s)-4){
                if(s[i+1]=='l' && s[i+2]=='a' && s[i+3]=='v' && s[i+4]=='a'){
                    c++;
                }
            }
        }
        if(s[i]=='A') {
            if(i<sz(s)-2){
                if(s[i+1]=='n' && s[i+2]=='n'){
                    c++;
                }
            }
        }
        if(s[i]=='N') {
            if(i<sz(s)-5){
                if(s[i+1]=='i' && s[i+2]=='k' && s[i+3]=='i' && s[i+4]=='t' && s[i+5]=='a'){
                    c++;
                }
            }
        }
    }
    if (c!=1){
        cout<<"No\n";
    } else {
        cout<<"Yes\n";
    }
    return 0; 
}
