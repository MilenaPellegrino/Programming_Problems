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

   ll t; cin >>t;
   while(t--){

      ll n,count=0; string s; cin >>n>>s;
      bool al = s == "Alice";
      vi v(n);
      fore(i,0,n){
         cin>>v[i];
         count+= (i+1 != v[i]);
      }

      if(n==2){
         cout << "Alice\n";
         continue;
      }

      if(n>=4){
         if(al && count==2){
            cout << "Alice\n";
         }else{
            cout << "Bob\n";
         }
         
      } else {
         if((al && count==2) || (!al && count>2)){
            cout << "Alice\n";
         }else{
            cout << "Bob\n";
         }
      }


   }

   
   return 0;
}