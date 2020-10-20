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

int l;
str s;
priority_queue <pii> q;
int dig1[200000],dig2[200000];
ll sum1(ll x){
    int idx;
    idx = 1;

    for(int i=x;i>=0;i--){
        int d = numerize(s[i]);
        dig1[idx] += d;
        idx ++;
    }

    idx = 1;
    for(int i=s.size()-1;i>x;i--){
        int d = numerize(s[i]);
        dig1[idx] += d;
        if(dig1[idx]>9){dig1[idx]%=10;dig1[idx+1]++;}
        idx++;
    }

    while(dig1[idx]>9){
        dig1[idx]%=10;
        dig1[idx+1]++;
        idx++;
    }

}
ll sum2(ll x){
    int idx;
    idx = 1;

    for(int i=x;i>=0;i--){
        int d = numerize(s[i]);
        dig2[idx] += d;
        idx ++;
    }

    idx = 1;
    for(int i=s.size()-1;i>x;i--){
        int d = numerize(s[i]);
        dig2[idx] += d;
        if(dig2[idx]>9){dig2[idx]%=10;dig2[idx+1]++;}
        idx++;
    }

    while(dig1[idx]>9){
        dig2[idx]%=10;
        dig2[idx+1]++;
        idx++;
    }
}
ll compare (){
    ll res = 1;
    for(int i=100100;i>=1;i--){
        if(dig1[i]<dig2[i]){res=1;break;}
        else if(dig2[i]<dig1[i]){res=2;break;}
    }
    return res;
}
int main(){
	//IO();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>l;
    cin>>s;

    for(int i=0;i<s.size()-1;i++){
        if(s[i+1]!='0'){

            int lef = i+1;
            int righ = l - lef;
            q.push(mp(-1*(abs(righ-lef)),i));
        }
    }

    if(l==1)cout<<s<<newl;
    else{
        int a,b,sa,sb;
        a = q.top().se;
        b = -1;
        sb = -1;
        sa = q.top().fi;
        q.pop();
        if(q.size()>0){
            b = q.top().se;
            sb = q.top().fi;
            q.pop();
        }

        ll big = 1;
        if(sa==sb){
            sum1(a);
            sum2(b);
            big = compare();

        }
        else{
            sum1(a);
        }

        if(big==1){
            bool cetak = false;
            for(int i=100100;i>=1;i--){
                if(dig1[i]>0){cetak=true;}
                if(cetak)cout<<dig1[i];
            }
        }
        else{
            bool cetak = false;
            for(int i=100100;i>=1;i--){
                if(dig2[i]>0){cetak=true;}
                if(cetak)cout<<dig2[i];
            }
        }


    }
}

