#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<bits/stdc++.h>
#define ll long long
using namespace std;
class Graph
{
    public:
    void insert(int u,int v,int e);
    void buildcomponents();
    int returnsize();
    long long int findcost();
    Graph(int x);
    int val1;
    int val2;
    private:
    int n;
    vector<vector<pair<int,int>>> V;
    void DFS(int i,bool flag);
    vector<bool> b;
    vector<int> visited;
    long long int cost(const vector<int> &vv);
    vector<vector<int>> components;
    long long  int counter,counter1;
};
