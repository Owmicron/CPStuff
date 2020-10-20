#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
bool noz[101];
ll lz;
bool act;
string rev(string x){
    string r="";
    for(int i=x.size()-1;i>=0;i--){
        r+=x[i];
    }
    return r;
}
int main(){
    ll n,m,f_1[101],l_1[101];
    string s[101];
    cin>>n>>m;
    m+=2;
    for(int i=n;i>=1;i--){
        cin>>s[i];

        f_1[i]=s[i].find('1');
        l_1[i]=rev(s[i]).find('1');
        cout<<l_1[i]<<" ";
        if(f_1[i] > 300){f_1[i]=0;noz[i]=true;}
        else{
            if(!act){lz=i;act=true;}
        }
        if(l_1[i] > 300){l_1[i]=0;noz[i]=true;}
        else{
            if(!act){lz=i;act=true;}
        }
        l_1[i]=(m-1)-l_1[i];
        cout<<" "<<f_1[i]<<" "<<l_1[i]<<" "<<endl;
    }

    bool left=true;
    bool both=false;

    ll ans=0,x;
    for(int i=1;i<=lz;i++){
        if(both ){
            x=min(f_1[1] , (m-1)-l_1[i]);
            if(!noz[i]){ans+=x;
            both=false;}
        }
        else{

            if(left){
                if(!noz[i]){x=l_1[i];
                ans+=x;}
            }
            else{
                if(!noz[i]){x=f_1[i];
                ans+=(m-1-x);}
            }
        }

        if(i<lz){
            if(!noz[i]){if(x < m-1-x){left=true; ans+=x;}
            else if(x > m-1-x){left=false; ans+=m-1-x;}
            else{both=true; ans+=x;}}
            ans++;
        }
        cout<<ans<<endl;
    }
    cout<<ans;



}
