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
    string s = to_string(n); 
    char fst_pos = s[0]; 
    ll tam = sz(s);
    string nums = ""; 

    ll cantno = 0;
    // special case
    // fore(i, 0, sz(s)){
    //     if(s[i]!='0'){
    //         cantno++;
    //     }
    // }
    // if(cantno<=1){
    //     cout<<0<<"\n";
    //     return 0; 
    // }
    if(fst_pos == '9'){
        nums+= '1'; 
        nums+= '0';
    }else{nums += fst_pos + 1;} 
    fore(i, 1, tam){
        nums += '0';
    }
    //cout<<nums<<endl;
    ll num = stoll(nums);
    ll res = num - n;
    cout<<res<<"\n";
    

    
    return 0;
 }