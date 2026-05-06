#include<bits/stdc++.h> 
using namespace std; 

#define fore(i, a, b) for(ll i=(a);i<(b); i++)
#define all(x) (x).begin(), (x).end()
#define pb push_back 
#define fst first 
#define snd second 
#define sz(x) ((int)x.size())
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
typedef vector<ll> vi;
 
int main(){FIN;

   string s,sh,sm; cin>>s;
   ll a; cin>>a;
   ll hh,mm;
   sh = "";
   sm = "";
   sh+=s[0];
   sh+=s[1];
   sm+=s[3];
   sm+=s[4];
   hh = stoll(sh);
   mm = stoll(sm);

   if((((mm+a)/60)+hh)%24 <10){
      cout << "0"<< (((mm+a)/60)+hh)%24;
   } else {
      cout << (((mm+a)/60)+hh)%24;

   }

   if((mm+a)%60 <10){
   cout << ":0" << (mm+a)%60 << "\n";

   }else{
      cout << ":" << (mm+a)%60 << "\n";
   }

   
   
   return 0;
}