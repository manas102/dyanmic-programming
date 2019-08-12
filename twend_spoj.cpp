#include<iostream>
#include<vector>

using namespace std;
using vi=vector<int>;
int greedyVsDp(vi &arr){//The first turn will be taken by the dp guy
	int n=arr.size();
	int dp[n][n]={0};
	int greedy[n][n]={0};
	for(int g=0;g<n;g++){//will help to cosider each subarray
		for(int i=0,j=g;j<n;i++,j++){
			int x=((i+2)<=j)?((arr[i+1]>=arr[j])?dp[i+2][j]:dp[i+1][j-1]):0;//if first element is selected
			int y=(i<=(j-2))?((arr[i]>=arr[j-1])?dp[i+1][j-1]:dp[i][j-2]):0;//if last element is selected
			if((x+arr[i])>=(y+arr[j])){
				dp[i][j]=x+arr[i];
				greedy[i][j]=0;
			}else{
				dp[i][j]=y+arr[j];
				greedy[i][j]=1;
			}
		}
	}
//	for(int i=0;i<n;i++){
//		for(int j=0;j<n;j++){
//			cout<<dp[i][j]<<" ";
//		}
//		cout<<"\n";
//	}
//	cout<<"--------------------------------\n";
//	for(int i=0;i<n;i++){
//		for(int j=0;j<n;j++){
//			cout<<greedy[i][j]<<" ";
//		}
//		cout<<"\n";
//	}
	int g=0;
	//to find the greedy count
	int i=0,j=n-1;
	while(i<=j){
		if(!greedy[i][j]){//first element is selected
			if(arr[i+1]>=arr[j]){//greedy approach select the max element of the ends
				g+=arr[i+1];
				i+=2;
			}else{
				g+=arr[j];
				i++;
				--j;
			}
		}else{
			if(arr[i]>=arr[j-1]){
				g+=arr[i];
				i++;
				--j;
			}else{
				g+=arr[j-1];
				j-=2;
			}
		}
	}
	return dp[0][n-1]-g;	
}
int main(){
	int t,game=1;
	cin>>t;
	while(t){
		vi v;
		for(int i=0;i<t;i++){
			int a;
			cin>>a;
			v.push_back(a);
		}
		cout<<"In game "<<game++<<", the greedy strategy might lose by as many as "<<greedyVsDp(v)<<" points.\n";
		cin>>t;
	}
	return 0;
}
