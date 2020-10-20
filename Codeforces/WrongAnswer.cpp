#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
ll n,k,x,xt,sum,ab;
vector<ll> ans;
int main(){
    cin>>k;
//    if(k<=1000000){n=3;}
//    else if(k<=10000000){n=101;}
//    else if(k<=100000000){n=1001;}
//    else if(k<1000000000){n=1999;}
//    else{n=2000;}
//
//    xt = k/(n-1);
//    xt++;
//    for(int i=xt;i<=xt+n;i++){
//        if((i+k)%n==0){x=i;break;}
//    }
//    ll sum = (x+k)/n;
//    ll ab = x-sum;
    //cout<<x<<" "<<sum<<" "<<ab<<endl;
    if(k==1000000000){
        n=2000;
        xt = k/(n-1);
        xt++;
        for(int i=xt;i<=xt+n;i++){
            if((i+k)%n==0){x=i;break;}
        }
        sum = (x+k)/n;
        ab = x-sum;
    }
    else{

        for(int i=3;i<=2000;i+=2){
            n = i;
            xt = k/(n-1);
            xt++;
            for(int j=xt;j<=xt+n;j++){
                if((j+k)%n==0){x=j;break;}
            }
            if(x>1000000){continue;}
            sum = (x+k)/n;
            ab = x-sum;
            if (((n-1)/2)>ab)continue;
            else break;
        }

    }
    if(n==2000){
        n--;
        for(int i=1;i<=(n-1)/2;i++){
            ans.push_back(1);
            ans.push_back(-2);
        }
        ll m = (n-1)/2;
        ans.push_back  (-1*(ab-m));
        ans.push_back(x);
        n++;
    }
    else{
        for(int i=1;i<=(n-1)/2;i++){
            ans.push_back(1);
            ans.push_back(-2);
        }
        ll m = (n-1)/2;
        ans[ans.size()-1] -= ab-m;
        ans.push_back(x);
    }
    cout<<n<<endl;
    for(int i=0;i<ans.size();i++){
        if(i==0)cout<<ans[i];
        else{cout<<" "<<ans[i];}
    }
}
