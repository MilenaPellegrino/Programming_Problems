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
   string s[8];
   ll c[8];
   map<ll,string> nom;
   fore(i,0,8){
    cin>>s[i]>>c[i];
    nom[c[i]]=s[i];
   }
   ll q1=max(c[0],c[1]);
   ll q2=max(c[2],c[3]);
   ll q3=max(c[4],c[5]);
   ll q4 =max(c[6],c[7]);
   ll f1=max(q1,q2);
   ll f2=max(q3,q4);
   if(f1>f2){
    cout<<nom[f1]<<" beats "<<nom[f2]<<"\n";
   }else{
    cout<<nom[f2]<<" beats "<<nom[f1]<<"\n";
   }
   return 0;
}