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
typedef map <int , int> mint;
typedef map <ll , ll> mll;
typedef set <int> si;
typedef set <ll> sll;
typedef si :: iterator sitr;
typedef si :: reverse_iterator rsitr;
typedef sll :: iterator sltr;
typedef sll :: reverse_iterator rsltr;
#define mset multiset

typedef mset <int> msi;
typedef mset <ll> msll;
typedef msi :: iterator msitr;
typedef msi :: reverse_iterator msritr;
typedef msll :: iterator msltr;
typedef msll :: reverse_iterator mslritr;

#define mp make_pair
#define pb push_back
#define pob pop_back
#define pf push_front
#define pof pop_front
#define fi first
#define se second
#define fs first.second
#define ss second.second
#define ff first.first
#define sf second.first
#define newl '\n'

char to_upper (char x){
    if( 97 <= int(x) && int(x) <= 126)return char(x-32);
    else if( 65 <= int(x) && int(x) <= 90)return x;
}
char to_lower (char x){
    if( 97 <= int(x) && int(x) <= 126)return x;
    else if( 65 <= int(x) && int(x) <= 90)return char(x+32);
}
int numerize (char x){
    if(48 <= int(x) && int(x) <= 57)return int(x-'0');
    else if( 97 <= int(x) && int(x) <= 126)return int(x-96);
    else if( 65 <= int(x) && int(x) <= 90)return int(x-64);
}
// end of Template

ll a[200000],n,sel,dua,tiga;
map <int,int> f;
map <int,int> :: iterator itr;
bool sj;
int main(){

//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
        f[a[i]]++;
        if(f[a[i]]>=2){dua++;}
        if(f[a[i]]>=3){tiga++;}
    }
    sort(a,a+n);

    if(f[0]>=2){sj=false;}
    else if(dua>1){sj=false;}
    else if(tiga>0){sj=false;}
    else {
        sj = true;
        for(itr = f.begin();itr != f.end(); itr++){
            int x,y;
            x = itr->fi;
            if(f[x]>=2 && f[x-1]>=1){sj=false;break;}
        }

        if(sj){
            for(int i=0;i<n;i++){
                sel += a[i] - i;
            }
            if(sel%2==0){sj=false;}
        }
    }
    if(sj)cout<<"sjfnb\n";
    else cout<<"cslnb\n";


}

