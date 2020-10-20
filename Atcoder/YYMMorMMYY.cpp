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
bool valida,validb;
str s;
str a,b;
int x,y;
int main(){
    cin>>s;
    x = ((int(s[0])-48)*10) + int((s[1])-48);
    y = ((int(s[2])-48)*10) + int((s[3])-48);

    if(x>=1 && x<=12){valida=true;}
    if(y>=1 && y<=12){validb=true;}

    if(valida && validb)printf("AMBIGUOUS\n");
    else if(valida && !validb)printf("MMYY\n");
    else if(!valida && validb)printf("YYMM\n");
    else if(!valida && !validb)printf("NA\n");
}
