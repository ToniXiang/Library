//AC (0.2s, 2.3MB)
#include<iostream>
#include<map>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;
void sieve(int n, vector<bool>& is_prime) {
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= n; ++i) {
        if (is_prime[i]) {
            for (int j = i * i; j <= n; j += i) {
                is_prime[j] = false;
            }
        }
    }
}
void deal(int& tmp,int val,map<int,int>& m){
    while (tmp%val==0)
    {
        m[val]++;
        tmp/=val;
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<bool> is_prime(n + 1, true);
    sieve(n, is_prime);
    map<int,int> m;
    for(int i=2;i<=n;i++){
        if(is_prime[i]){
            m[i]=1;
            continue;
        }
        int tmp = i;
        deal(tmp, 2, m);
        deal(tmp, 3, m);
        for (int j = 5; j * j <= tmp; j += 6) {
            deal(tmp, j, m);
            deal(tmp, j + 2, m);
        }
        if (tmp > 1) {
            m[tmp]++;
        }
    }
    int rd = 1;
    auto it = m.begin();
    while (it != m.end()) {
        auto next_it = std::next(it);
        if (next_it != m.end() && it->second == next_it->second) {
            rd++;
        } else {
            std::cout << (rd == 1 ? "" : std::to_string(rd) + "*") << it->second << " ";
            rd = 1;
        }
        it = next_it;
    }
    return 0;
}