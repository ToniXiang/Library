#include <iostream>
#include <vector>
#include <queue>
#include <sstream>
#include <math.h>
using namespace std;
struct Data
{
    int pos, d, u, del;
};
bool cmp(const Data &a, const Data &b)
{
    return a.pos > b.pos;
}
typedef vector<Data> vd;
using pq_type = priority_queue<Data, vd, decltype(&cmp)>;
struct Node
{
    int seg, arr;
    Node *left, *right;
    Node() : seg(0), arr(0), left(nullptr), right(nullptr) {}
} *root = nullptr;
Node *build(int left, int right)
{
    Node *node = new Node();
    if (left != right)
    {
        int mid = left + (right - left) / 2;
        node->left = build(left, mid);
        node->right = build(mid + 1, right);
    }
    return node;
}

void update(Node* id, int left, int right, int query_left, int query_right, int del)
{
    if (query_left <= left && right <= query_right)
    {
        id->arr += del;
        if (id->arr > 0)
        {
            id->seg = right - left + 1;
        }
        else
        {
            id->seg = (left != right) ? id->left->seg + id->right->seg : 0;
        }
        return;
    }

    int mid = left + (right - left) / 2;
    if (query_left <= mid)
    {
        update(id->left, left, mid, query_left, query_right, del);
    }
    if (mid < query_right)
    {
        update(id->right, mid + 1, right, query_left, query_right, del);
    }

    if (id->arr == 0)
    {
        id->seg = id->left->seg + id->right->seg;
    }
    else
    {
        id->seg = right - left + 1;
    }
}
void deleteTree(Node* node) {
    if(!node)return;
    deleteTree(node->left);
    deleteTree(node->right);
    delete node;
}
int main()
{
    ios::sync_with_stdio(false);
    pq_type pq(&cmp);
    int left, down, right, up;
    string s;
    while (getline(cin, s))
    {
        if (s.empty())
            break;
        istringstream iss(s);
        iss >> left >> down >> right >> up;
        pq.push({left, down + 1, up, 1});
        pq.push({right, down + 1, up, -1});
    }

    root = build(1, 1E6);

    int pre = 0;
    long long ans = 0;
    while (pq.size() > 0)
    {
        Data cur = pq.top();
        pq.pop();
        if (cur.pos != pre)
        {
            ans += 1LL * (cur.pos - pre) * root->seg;
            pre = cur.pos;
        }
        update(root, 1, 1E6, cur.d, cur.u, cur.del);
    }
    cout << ans << endl;
    deleteTree(root);
    return 0;
}