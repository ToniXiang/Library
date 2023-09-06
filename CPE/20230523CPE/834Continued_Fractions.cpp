#include<iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    double a,b;
    while (cin>>a>>b)
    {
        double val=a/b;
        string r=to_string((int)val)+";";
        val-=(int)val;
        val=1/val;
        while (val-(int)val<=0.999999999)
        {
            r+=to_string((int)val)+",";
            val-=(int)val;
            val=1/val;
        }
        if(!r.empty())r.erase(r.end()-1);
        cout<<"["+r+"]"<<endl;
    }
    return 0;
}