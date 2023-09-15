#include<iostream>
#include<math.h>
using namespace std;
const double pi=2*acos(0);
int main() {
    ios_base::sync_with_stdio(false);
    double d,l;
    while(cin>>d>>l){
        //sqrt((L/2)^2-(D/2)^2)
        double low=sqrt(l*l/4-d*d/4)/2;
        double high=l;
        printf("%.3f\n",pi*low*high);
    }
    return 0;
}