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
int identity[40];
int f[40];
str s,t,a,b;
int main(){
    cin>>s>>t;
    int idx = 0;
    for(int i=0;i<s.size();i++){
        int x = int(s[i]-'a')+1;
        if(f[x]==0){
            f[x]++;
            idx ++;
            identity[x] = idx;
        }
    }
    for(int i=0;i<s.size();i++){
        int x = int(s[i]-'a')+1;
        a += char(identity[x]+'0');
    }

    for(int i=0;i<=30;i++){
        f[i]=0;
    }

    idx=0;
    for(int i=0;i<t.size();i++){
        int x = int(t[i]-'a')+1;
        if(f[x]==0){
            f[x]++;
            idx ++;
            identity[x] = idx;
        }
    }

    for(int i=0;i<t.size();i++){
        int x = int(t[i]-'a')+1;
        b += char(identity[x]+'0');
    }
    if(a==b)cout<<"Yes\n";
    else cout<<"No\n";

}
