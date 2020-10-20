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
//void IO(){
//	#ifndef ONLINE_JUDGE
//	    freopen("input.txt", "r", stdin);
//	    freopen("output.txt", "w", stdout);
//	#endif
//}
// end of Template

int a,b,r,c,mr,mc;
int wh,bl;
bool alt,black[600][600],habis;
void plus_white(){
    if(c>100){
        c = 1;
        black[r+2][1]=true;
        for(int i=1;i<=100;i++)black[r+3][i]=true;

        r+=4;
        mr = max(mr,r+3);
    }
    else{
        if(bl>=2 || (!habis && r>1 && bl==1) ){
            black[r+1][c]=true;
            black[r][c+1]=true;
            if(r==1)bl-=2;
            else{bl--;}

            if(bl==0)habis=true;
        }
        else if(bl==1){
            habis=true;
            black[r+1][c]=true;
            black[r][c+1]=true;
            black[r+1][c+1]=true;
        }
        else{
            wh--;
            bl = 1;
            black[r][c]=true;
            black[r+1][c]=true;
            black[r][c+1]=true;
            black[r+1][c+1]=true;
        }
        c+=2;
        mc = max(mc,c);

    }
}
int main(){
	//IO();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>a>>b;

    if(a>b){swap(a,b); alt = true;}
    r = 1;mr = 4;
    c = 1;mc = 1;

    wh = 1;
    bl = b;
    while(wh<a){
        wh++;
        plus_white();
    }

    while(!habis){
        r+=4;
        mr = max(mr,r+3);
        for(int i=1;i<=99;i+=2){
            black[r][i]=true;
            bl--;
            mc = max(i,mc);
            if(bl==0){habis=true;break;}
        }

    }
    mc++;

    mc=min(mc,100);
    mr=min(mr,100);

    cout<<mr<<" "<<mc<<newl;
    for(int i=1;i<=mr;i++){
        for(int j=1;j<=mc;j++){
            if(alt){black[i][j]=not black[i][j];}
            if(black[i][j]){cout<<"#";}
            else cout<<".";
        }
        cout<<newl;
    }
}
