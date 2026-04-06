#include<bits/stdc++.h> 
using namespace std; 

#define fore(i, a, b) for(ll i =(a); i<(b); i++)
#define all(x) (x).begin(), (x).end()
#define pb push_back 
#define fst first
#define snd second
#define sz(x) ((int)x.size())

#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0); 

using ll = long long; 
typedef vector<ll> vi; 


int main(){
    FIN;
    string s;cin>>s;
    stack<char>  st;
    st.push(s[0]);
    fore(i,1,s.size()){
        if(!st.empty() && st.top()==s[i]){
            st.pop();
        } else {
            st.push(s[i]);
        }
    }
    vector<char> sn;
    while(!st.empty()){
        sn.pb(st.top());
        st.pop();
    }

    reverse(all(sn));
    fore(i,0,sn.size()){
        cout<<sn[i];
    }
    cout<<"\n";
    return 0;
}
