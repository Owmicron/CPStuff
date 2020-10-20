#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector <pii> vpii;
typedef vector <pll> vpll;
typedef map <str,int> mapsi;
typedef map <str,int> :: iterator mapsitr;
typedef set <int> si;
typedef set <int> :: iterator sitr;
typedef set <ll> :: iterator sltr;
#define mset multiset
typedef mset <int> msi;
typedef mset <ll> msll;
typedef mset <int> :: iterator msitr;
typedef mset <ll> :: iterator msltr;
#define mp make_pair
#define pb push_back
#define pob pop_back
#define fi first
#define se second
#define fs first.second
#define ss second.second
#define ff first.first
#define sf second.first
int n;
str s[200];
set<str> w;
int main(){
    cin>>n;
    bool valid=true;
    for(int i=1;i<=n;i++){
        cin>>s[i];
        if(i==1){w.insert(s[i]);}
        else{
            if(w.count(s[i])){valid=false;}
            else if(s[i][0] != s[i-1][s[i-1].size()-1] ){valid=false;}
            else{
                w.insert(s[i]);
            }
        }
    }
    if(valid)cout<<"Yes\n";
    else cout<<"No\n";


}
