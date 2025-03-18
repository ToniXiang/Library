#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
	vector<int>v;
	for(int i=1;i*i<(int)1E5;i++){
		v.push_back(i*i);
	}
	int a,b;
	while(cin>>a>>b){
		if(a==0&&b==0)break;
		//排序陣列中第 i 個大於等於目標的位置
		auto it1=lower_bound(v.begin(),v.end(),a);
		int left=distance(v.begin(),it1);
		//排序陣列中第 i 個小於等於目標的位置
		auto it2=upper_bound(v.begin(),v.end(),b);
		int right=distance(v.begin(),it2);
		cout<<right-left<<endl;
	}
	return 0;
}
// 二分搜尋法
// 題目：找出在 a ~ b 之間有幾個完全平方數
// 1 4 9 16 25 36 49 64 81 100