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

str s,ans;
int k;
set <str> sub;
set <str> :: iterator itr;
void getlength(int x){
    if(x<=s.size()){
        str temp = "";
        for(int i=0;i<x;i++){
            temp += s[i];
        }
        sub.insert(temp);
        for(int i=x;i<s.size();i++){
            temp.replace(0,1,"");
            temp+=s[i];
            sub.insert(temp);
        }


    }

}
int main(){
	//IO();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>s;
    cin>>k;
    for(int i=1;i<=5;i++)getlength(i);
    int idx = 0;
    for(itr=sub.begin();itr!=sub.end();itr++){
        idx++;
        if(idx==k){ans=*itr;break;}
    }
    cout<<ans<<newl;
}