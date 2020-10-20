#include<bits/stdc++.h>
using namespace std;
void hand(int n){
    int x=n;
    for(int i=0;i<=n;i++){
        for(int j=1;j<=x;j++)
            cout<<"  ";

        int c=i;
        for(int j=0;j<=c;j++){
            cout<<j;
            if(i!=0){cout<<" ";}
        }
        c--;
        for(int j=c;j>=0;j--){
            cout<<j;
            if(j>0){cout<<" ";}
        }

        x--;
        cout<<"\n";
    }

    x=1;
    for(int i=n-1;i>=0;i--){
        for(int j=1;j<=x;j++)
            cout<<"  ";

        int c=i;
        for(int j=0;j<=c;j++){
            cout<<j;
            if(i!=0){cout<<" ";}
        }
        c--;
        for(int j=c;j>=0;j--){
            cout<<j;
            if(j>0){cout<<" ";}
        }

        x++;
        cout<<"\n";
    }

}
int n;
int main(){
    cin>>n;
    hand(n);
}
