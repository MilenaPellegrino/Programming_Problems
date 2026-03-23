#include<bits/stdc++.h> 
using namespace std; 
#define ll long long
#define vi vector<ll>
#define fore(i, a, b) for (ll i= a; i<(b); i++)
#define all(x) (x).begin(), (x).end()
#define pb push_back 
#define fst first
#define snd second 


#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)

string constr(string s, ll a, ll n, ll t, ll o){
    string ans;
    for(char c : s){
        if(c == 'a'){
            ans += string(a, 'a');
        } else if(c == 'n'){
            ans += string(n, 'n');
        } else if(c == 't'){
            ans += string(t, 't');
        } else if(c == 'o'){
            ans += string(o, 'o');
        }
    }
    return ans;
}

pair<ll, string> steps(string s, string a) {
    ll cont = 0;

    fore(i, 0, s.size()) {
        if (a[i] != s[i]) {
            int j = i + 1;
            while (j < a.size() && a[j] != s[i]) j++;
            while (j > i) {
                swap(a[j], a[j-1]);
                cont++;
                j--;
            }
        }
    }

    return {cont, a};
}


int main(){
    FIN;
    ll t; cin>>t; 
    while(t--){
        string a; cin>>a; 
        transform(all(a), a.begin(), ::tolower);
        ll cnta = 0, cntn = 0, cnto = 0, cntt = 0; 
        fore(i, 0, a.size()){
            if(a[i] == 'a')cnta++; 
            else if (a[i] == 'n')cntn++;
            else if (a[i] == 't')cntt++;
            else if (a[i] == 'o')cnto++;
        }
        // cout<<a<<endl;
        string apermu; 
        if(cnta > 0 )apermu += 'a'; 
        if(cntn > 0 )apermu += 'n'; 
        if(cnto > 0 )apermu += 'o'; 
        if(cntt > 0 )apermu += 't'; 
        // cout<<apermu<<endl; 

        sort(all(apermu)); 
        pair<ll, string> ans;
        ans.fst = 0;
        ans.snd = "";
        do {
            // Permutacion i 
            
            string scons = constr(apermu, cnta, cntn, cntt, cnto);
            pair<ll, string> stepsaux = steps(scons, a);
            if(ans.fst <= stepsaux.fst){
                ans.fst = stepsaux.fst;
                // ans.snd = stepsaux.snd;
                ans.snd = scons;
            }
            // cout<<apermu<<" -> "<<scons<<endl;
        } while (next_permutation(apermu.begin(), apermu.end()));
        transform(all(ans.snd), (ans.snd).begin(), ::toupper);
        cout<<ans.snd<<"\n";
    }
        

    return 0;
}