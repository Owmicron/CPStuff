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

str s;
int d;
deque <int> q[6];
stack < pair <pii,int> > z;
void clean (int l, int r){
    for(int i=1;i<=3;i++){
        bool valid = true;
        while(!q[i].empty()){
            if(q[i].front()<=l)q[i].pof();
            else{break;}
        }
        while(!q[i].empty()){
            if(q[i].back()>=r)q[i].pob();
            else{break;}
        }
    }
}
deque<char> ans;
void solve(){
    pii f[5];

    while(d>0){
        for(int i=1;i<=3;i++){
            int num = -1;
            if(!q[i].empty())num = abs(q[i].front() - q[i].back());
//            cout<<q[i].size()<<" "<<i<<" "<<num<<newl;
            f[i] = mp(num,i);
        }
        sort(f+1,f+1+3);
        int lef,righ;
        if(f[3].fi>=0){
            lef = q[f[3].se].front();
            righ = q[f[3].se].back();
            clean(lef,righ);
            z.push( mp (mp(lef,righ) , f[3].se) );
        }
        else break;
        //d-=2;

    }

}
int main(){

//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]=='a')q[1].pb(i);
        else if(s[i]=='b')q[2].pb(i);
        else if(s[i]=='c')q[3].pb(i);
    }
    d = s.size()/2;

    solve();
    while(!z.empty()){
        int lef = z.top().ff;
        int righ = z.top().fs;
        char c = char(z.top().se + 96);
//        cout<<lef<<" "<<righ<<" "<<c<<newl;
        if(lef==righ){ans.pf(c);}
        else{ans.pf(c);ans.pb(c);}

        z.pop();
    }
    while(!ans.empty()){
        cout<<ans.front();
        ans.pof();
    }cout<<newl;
}
