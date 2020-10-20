#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
ll a,b;
ll ask(ll quest,ll left,ll right){
    if(a>0 && b>0){return 0;}
    if(quest>0){

        cout<<(right/2)-left+1;
        for(ll i=left;i<=right/2;i++){
            cout<<" "<<i;
        }
        cout<<endl;

        ll ans;
        cin>>ans;
        if(a==0 || b==0){
        if((right/2)-left == 0){
            if(ans == 1){
                if(a == 0){a = left;}
                else if(b == 0){b = left;}
            }
        }
        if(ans>0){
            ask(quest - 1, left , right/2);
        }

            cout<<right-((right/2)+1);
            for(ll i=(right/2)+1;i<=right;i++){
                cout<<" "<<i;
            }
            cout<<endl;
            cin>>ans;
            if(right-(right/2) == 0){
                if(ans == 1){
                    if(a == 0){a = right;}
                    else if(b == 0){b = right;}
                }
            }
            if(ans>0){
                if((right-((right/2)))>0){ask(quest - 1, (right/2)+1 , right);}
            }
        }

}
}
int main(){
    ll n;
    cin>>n;
    ll quest = 16;
    ask(quest,1,n);
}
