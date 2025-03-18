#include<iostream>
using namespace std;
typedef long long ll;
int main() {
    ios_base::sync_with_stdio(false);
    ll s,d;
	while(cin>>s>>d){
		//if s = 3 =>	1 morining in -> 3 evening out
		while(d>0){
			d-=s;
			s++;
		}
		cout<<s-1<<endl;
	}
    return 0;
}
// 1. 任何一天只能住一個旅行團
// 2. n 個人的旅行團在一早就住進旅館，然後在 n 天後的晚上離開。
// 3. 除了第一個旅行團之外，每個剛來的旅行團的人數都比上一個旅行團多一人。
// 題目：輸出某一天住在這家旅館的旅行團的人數有多少人
// 1 6
// 1 2 3 4 5 6
// 1 2 2 3 3 3
//
// 3 10
// 1 2 3 4 5 6 7 8 9 10
// 3 3 3 4 4 4 4 5 5 5