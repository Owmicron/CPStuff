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
int xa,xb,xc,xd,ya,yb,yc,yd;
int main(){
    cin>>xa>>ya>>xb>>yb;
    xc = xb; yc = yb;
    int x,y;
    x = abs(xb-xa);
    y = abs(yb-ya);
    if(yb>=ya && xb>=xa){xc-=y; yc+=x;}
    else if(yb<=ya && xb>=xa){xc+=y; yc+=x;}
    else if(yb>=ya && xb<=xa){xc-=y; yc-=x;}
    else if(yb<=ya && xb<=xa){xc+=y; yc-=x;}
    yd = yc;
    xd = xc;

    xd += xa-xb;
    yd += ya-yb;

    printf("%d %d %d %d\n",xc,yc,xd,yd);
}
