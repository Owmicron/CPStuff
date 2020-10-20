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

int q,n,k,c[4][4][200010],ans;
str s;
int conv (char x){
    if(x=='R')return 1;
    if(x=='G')return 2;
    if(x=='B')return 3;
}
void reset (){
    for(int i=1;i<=3;i++){
        for(int j=1;j<=3;j++){
            for(int z=1;z<=n;z++)c[i][j][z]=0;
        }
    }
}
void cop (int id){
    for(int i=1;i<=3;i++){
        for(int j=1;j<=3;j++){
            c[i][j][id] = c[i][j][id-1];
        }
    }
}
void RGB (int l, int r){
    int x,cor,one,two,three;
    //RGB
    one = 1; two = 2; three = 3;
    cor = 0;
    x = (l%3)+1;
    cor += c[one][x][r] - c[one][x][l-1];
    if(k>1){
        x = ((l+1)%3)+1;
        cor += c[two][x][r] - c[two][x][l-1];
    }
    if(k>2){
        x = ((l+2)%3)+1;
        cor += c[three][x][r] - c[three][x][l-1];
    }

    cor = (r-l+1)-cor;
    ans = min(ans,cor);

    //GBR
    one = 2; two = 3; three = 1;
    cor = 0;
    x = (l%3)+1;
    cor += c[one][x][r] - c[one][x][l-1];
    if(k>1){
        x = ((l+1)%3)+1;
        cor += c[two][x][r] - c[two][x][l-1];
    }
    if(k>2){
        x = ((l+2)%3)+1;
        cor += c[three][x][r] - c[three][x][l-1];
    }

    cor = (r-l+1)-cor;
    ans = min(ans,cor);

    //BRG
    one = 3; two = 1; three = 2;
    cor = 0;
    x = (l%3)+1;
    cor += c[one][x][r] - c[one][x][l-1];
    if(k>1){
        x = ((l+1)%3)+1;
        cor += c[two][x][r] - c[two][x][l-1];
    }
    if(k>2){
        x = ((l+2)%3)+1;
        cor += c[three][x][r] - c[three][x][l-1];
    }

    cor = (r-l+1)-cor;
    ans = min(ans,cor);


}
int main(){

//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>q;
    for(int cases=1;cases<=q;cases++){
        cin>>n>>k;
        cin>>s;
        ans = INT_MAX;
        for(int i=0;i<s.size();i++){
            int idx = i+1; int type = conv(s[i]); cop(idx);
            c[type][(idx%3)+1][idx]++;
        }

        int ki,ka;
        ki = 1;
        ka = k;
        while(ka<=n){
            RGB(ki,ka);
            ki++;ka++;
        }
        cout<<ans<<newl;
        reset();
    }
}
