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

int q;
int ns[30],nt[30],np[30];
str s,t,p;
bool issubs(str a, str b, int x, int y){
    if(x<0)return true;
    if(y<0)return false;

    if(a[x]==b[y]){
        return issubs(a,b,x-1,y-1);
    }
    else{
        return issubs(a,b,x,y-1);
    }

}
int main(){

//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>q;
    for(int cases=1;cases<=q;cases++){
        cin>>s;
        cin>>t;
        cin>>p;
        for(int i=0;i<t.size();i++){
            int num = numerize(t[i]);
            nt[num]++;
        }

        for(int i=0;i<s.size();i++){
            int num = numerize(s[i]);
            ns[num]++;
        }

        for(int i=0;i<p.size();i++){
            int num = numerize(p[i]);
            np[num]++;
        }

        bool valid = true;
        valid = issubs(s,t,s.size()-1,t.size()-1);

        if(valid){
            for(int i=1;i<=26;i++){
                ns[i] += np[i];
            }
            for(int i=1;i<=26;i++){
                if(ns[i]>=nt[i]){continue;}
                else{valid=false;break;}
            }
        }

        if(valid)cout<<"YES\n";
        else{cout<<"NO\n";}

        for(int i=0;i<=27;i++){
            ns[i]=0;np[i]=0;nt[i]=0;
        }

    }

}
