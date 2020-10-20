#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int,int> vii;
typedef vector<ll,ll> vll;
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
bool exist[20];
str s;
int mn;
vector<int> num;
int main(){
    cin>>s;
    mn = 1000;
    for(int i=0;i<s.size()-2;i++){
        int a,b,c;
        a = int(s[i] - '0');
        b = int(s[i+1] - '0');
        c = int(s[i+2] - '0');
        mn = min(mn, abs(753 - (100*a + 10*b + c)) );
    }
    cout<<mn<<endl;

}
