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
    ll t; cin>>t; 
    while(true){
            string s; 
            ll m, b;
            cin>>s; 
            if(s=="WIN"){
                return 0;
            }else if (s == "LOSE"){
                return 0;
            }
            cin>>m>>b; 
            //cout<<s<<endl<<m<<endl<<b<<endl;
            if( b * 4 <= m ){
                cout<<"PLAY"<<endl;
            } else {
                cout<<"SKIP"<<endl;
            }
            
        }

    return 0; 
}
