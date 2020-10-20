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

ll over;
bool ov;
stack <ll> f;
ll m;
ll sum;
int l;
str com;
ll ign;
int main(){
	//IO();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    over = 1;
    for(int i=1;i<=32;i++){
        over*=2;
    }
    over -- ;

    cin>>l;
    m = 1;
    for(int i=1;i<=l;i++){
        cin>>com;

        if(com=="add"){
            ll p = m;
            if(p>over){ov=true;}
            if(ign>0){ov=true;}
            sum += p;
            //cout<<sum<<newl;
            if(sum>over){ov=true;}
        }
        else if(com=="for"){
            ll x;
            cin>>x;
            if (m*x > over || ign>0){ign++;}
            else {m*=x;}
            //cout<<m<<newl;
            f.push(x);
        }
        else if(com=="end"){
            if(ign == 0){
                m/=f.top();
            }
            else ign--;
           // cout<<m<<newl;
            f.pop();
        }
    }
    if(ov)cout<<"OVERFLOW!!!"<<newl;
    else cout<<sum<<newl;



}
