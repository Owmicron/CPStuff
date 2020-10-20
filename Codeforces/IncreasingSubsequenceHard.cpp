#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
deque<int> q;
int n,last,ans,a[300000],l,r;
str s;
int main(){
    last=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    l=1;r=n;
    while(l<=r){
        if(a[l]<=last && a[r]<=last){break;}
        else{
            if(a[l] < a[r]){
                if(a[l] > last){last=a[l];l++;s+="L";ans++;}
                else {last=a[r];r--;s+="R";ans++;}
            }
            else if(a[r] < a[l]){
                if(a[r] > last){last=a[r];r--;s+="R";ans++;}
                else {last=a[l];l++;s+="L";ans++;}
            }
            else if(a[l]==a[r]){
                int x,y;
                x=1;
                y=1;
                for(int i=l+1;i<=r;i++){
                    if(a[i]>a[i-1]){x++;}
                    else{break;}
                }
                for(int i=r-1;i>=l;i--){
                    if(a[i]>a[i+1]){y++;}
                    else{break;}
                }
                if(x>y){
                    for(int i=1;i<=x;i++){
                        s+="L";ans++;
                    }
                }
                else{
                    for(int i=1;i<=y;i++){
                        s+="R";ans++;
                    }
                }
                l=r+1;
            }
        }
    }
    cout<<s.size()<<endl;
    cout<<s;

}
