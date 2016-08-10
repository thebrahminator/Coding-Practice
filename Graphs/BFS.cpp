#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<string.h>
#include<list>
#include<vector>
#include<string>
#include<stack>
#include<limits.h>
using namespace std;

class Graph{
    int V;
    list<int> *adj;
    public:
    Graph(int v);
    void addEdge(int v, int w);
    void BFS(int s);
};

Graph::Graph(int v)
{
    this->V = v;
    adj = new list<int>[V];
}
