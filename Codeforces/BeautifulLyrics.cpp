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

vector < pair < pair<int,char> , str > > v,sisa;
int n;
bool isvowel(char x){
    if(x=='a' || x=='i' || x=='o' || x=='u' || x=='e')return true;
    return false;
}
void construct (str s){
    int vc = 0;
    char lv = 'x';
    for(int i=0;i<s.size();i++){
        if(isvowel(s[i])){vc++;lv=s[i];}
    }
    v.pb (mp( mp(vc,lv) , s));
}
stack < pair<str,str> > perf,good;
vector < pair < pair <str,str> , pair <str,str> > > ans;
int main(){
	//IO();
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);
    cin>>n;
    for(int i=0;i<n;i++){
        str word;
        cin>>word;
        construct(word);
    }
    sort(v.begin(),v.end());

    int idx=0;
    while(idx<v.size()){
        if(idx+1<v.size()){
            int b1,b2;
            b1 = idx;
            b2 = idx+1;
            if(v[b1].fi == v[b2].fi){
                perf.push(mp(v[b1].se,v[b2].se));
                idx+=2;
            }
            else if(v[b1].ff == v[b2].ff){
                if(idx + 2 < v.size()){
                    int b3 = idx + 2;
                    if(v[b2].fi == v[b3].fi){
                        sisa.pb( v[b1] );
                        idx ++;
                    }
                    else{
                        good.push(mp(v[b1].se,v[b2].se));
                        idx += 2;
                    }
                }
                else {
                    good.push(mp(v[b1].se,v[b2].se));
                    idx+=2;
                }
            }
            else { sisa.pb(v[idx]) ;idx++;}
        }
        else{
            sisa.pb(v[idx]);
            break;
        }
    }
    idx = 0;
    while(idx+1<sisa.size()){
        int b1 = idx;
        int b2 = idx+1;
        if(sisa[b1].ff == sisa[b2].ff){
            good.push(mp(sisa[b1].se,sisa[b2].se));
            idx+=2;
        }
        else idx++;
    }

//    while(!perf.empty()){
//        cout<<perf.top().fi<<" "<<perf.top().se<<newl;
//        perf.pop();
//    }
//    while(!good.empty()){
//        cout<<good.top().fi<<" "<<good.top().se<<newl;
//        good.pop();
//    }

    while(!perf.empty()){
        if(!good.empty()){
            str w11,w12,w21,w22;
            w12 = perf.top().fi;
            w22 = perf.top().se;
            w11 = good.top().fi;
            w21 = good.top().se;
            perf.pop();
            good.pop();
            ans.pb ( mp ( mp(w11,w12) , mp(w21,w22) ) );
        }
        else{
            if(perf.size()>1){
                str w11,w12,w21,w22;
                w12 = perf.top().fi;
                w22 = perf.top().se;
                perf.pop();
                w11 = perf.top().fi;
                w21 = perf.top().se;
                perf.pop();
                ans.pb ( mp ( mp(w11,w12) , mp(w21,w22) ) );
            }
            else{
                break;
            }
        }
    }

    cout<<ans.size()<<newl;
    for(int i=0;i<ans.size();i++){
        cout<<ans[i].ff<<" "<<ans[i].fs<<newl;
        cout<<ans[i].sf<<" "<<ans[i].ss<<newl;
    }
}
