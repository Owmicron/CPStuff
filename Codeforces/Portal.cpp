#include<bits/stdc++.h>
using namespace std;
int n,jlh,tanya,flag,nilai[10];
void rek(int l,int r){
	if(r-l>0){
		cout<<r-l+1;
		for(int i=l;i<=r;i++)cout<<" "<<i;
		cout<<endl;
		cout.flush();
		cin>>jlh;
		tanya++;
		if(jlh==1){
			rek(l,(l+r)/2);
			if(flag==0)rek(((l+r)/2)+1,r);
		}
		else if(jlh==2){
			rek(l,(l+r)/2);
			if(flag<2)rek(((l+r)/2)+1,r);
		}
	}
	else if(l==r && flag<2){
		cout<<1<<" "<<l<<endl;
		cout.flush();
		cin>>jlh;
		tanya++;
		if(jlh==1){
			flag++;
			nilai[flag]=l;
		}
	}
}
int main(){
	cin>>n;
	rek(1,n/2);
	if(flag!=2)rek((n/2)+1,n);
	if(tanya<16){
		for(int i=tanya;i<16;i++){
			cout<<0<<endl;
			cout.flush();
			cin>>jlh;
		}
	}
	cout<<nilai[1]<<" "<<nilai[2]<<endl;
}
