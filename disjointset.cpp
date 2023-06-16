#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#define ll long long
#define vi vector<int>
using namespace std;
class disJointSet
{
private:
    vector<int> rank, parent;

public:
    disJointSet(int n)
    {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
        }
    }
    int find(int n)
    {
        if (parent[n] == n)
        {
            return n;
        }
        return parent[n] = find(parent[n]);
    }
    void unionByRank(int u, int v)
    {
        int rootu = find(u);
        int rootv = find(v);
        if (rootu==rootv) return;
        if (rank[rootu] < rank[rootv])
        {
            parent[rootu] = rootv;
        }
        else if (rank[rootu] > rank[rootv])
        {
            parent[rootv] = rootu;
        }
        else
        {
            parent[rootv] = rootu;
            rank[rootu]++;
        }
    }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    disJointSet set(6);
    set.unionByRank(1, 6);
    set.unionByRank(2, 5);
    set.unionByRank(3, 4);
    set.unionByRank(2, 4);
    set.unionByRank(1, 2);
    cout << set.find(6) << endl;
    cout << set.find(5) << endl;
    cout << set.find(4) << endl;
    return 0;
}