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
int n,s,X,x[200000],g;
vector <int> sel;
int gcd (int a, int b){
    if(a<b)swap(a,b);
    while(a%b > 0){
        int c = a%b;
        a = b;
        b = c;
    }
    return b;
}
int main(){
    cin>>n>>X;
    for(int i=1;i<=n;i++){
        cin>>x[i];
    }
    x[n+1]=X;
    n++;
    sort(x+1,x+n+1);
    for(int i=2;i<=n;i++){
        sel.pb (x[i]-x[i-1]);
    }
    int g=sel[0];
    for(int i=1;i<sel.size();i++){
        g = gcd(g,sel[i]);
    }
    cout<<g<<endl;





}
