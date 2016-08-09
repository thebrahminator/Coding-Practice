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
    bool isCyclicUtil(int v, bool visited[], bool *rs);
    public:
    Graph(int V);
    void addEdge(int v, int w);
    bool isCyclic();
};

Graph::Graph(int V)
{
    this->V=V;
    adj = new list<int>[V];
}

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
}

bool Graph::isCyclicUtil(int v, bool visited[], bool *recursionStack)
{
    if(visited[v]==false)
    {
        visited[v] = true;
        recursionStack[v] = true;

        list<int>::iterator i;
        for(i=adj[v].begin(); i!=adj[v].end(); i++)
        {
            if(!visited[*i] && isCyclicUtil(*i, visited, recursionStack))
                return true;
            else if(recursionStack[*i])
                return true;
        }
    }
    recursionStack[v] = false;
    return false;
}

bool Graph::isCyclic()
{
    bool *visited = new bool[V];
    bool *recursionStack = new bool[V];

    for(int i=0;i<V;i++)
    {
        visited[i] = false;
        recursionStack[i] = false;
    }

    for(int i=0;i<V;i++)
    {
        if(isCyclicUtil(i, visited, recursionStack))
            return true;
    }
    return false;
}

int main()
{
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
    
    if(g.isCyclic())
        cout<<"The graph contains Cycles"<<endl;
    else
        cout<<"The graph doesn't contain cycles"<<endl;

    return 0;
}
