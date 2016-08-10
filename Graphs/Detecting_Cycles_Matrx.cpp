#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<string.h>
#include<list>
#include<vector>
#include<string>
#include<stack>
#include<limits.h>

#define MAX 100
using namespace std;

int adj[MAX][MAX];

bool isCyclic(int e, int n, bool visited[], bool recStack[])
{
    visited[e]=true;
    recStack[e]=true;

    for(int i=0;i<n;i++)
    {
        if(adj[e][i]==1)
        {
            if(!visited[i] && isCyclic(i,n,visited,recStack))
            {
                return true;
            }

            else if(recStack[i]==1)
            {
                return true;
            }
        }
    }
    recStack[e]=false;
    return false;

}

int main()
{   
    bool cycle=false;

    int n;
    cout<<"Enter the number of nodes"<<endl;
    cin>>n;

    bool visited[n+1];
    bool recStack[n+1];
    memset(visited, 0, sizeof(int)*n);
    //memset(recStack, 0, sizeof(int)*n);
    //memset(adj, 0, sizeof(int)*n*n);
    /*
       int n;
       cout<<"Enter the number of nodes"<<endl;
       cin>>n;
       */  
    for(int i=0;i<n;i++)
    {
        visited[i]=false;
        recStack[i]=false;
    }
    cout<<"Enter the contents of the adjacency Matrix"<<endl;
    int i,j;
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            cin>>adj[i][j];

    for(int i=0;i<n;i++)
    {
        if(!visited[i])
        {
            cycle = isCyclic(i,n,visited,recStack);
        }
        if(cycle)
            break;
    }

    if(cycle)
        cout<<"Cycle is present"<<endl;
    else
        cout<<"No cycles present"<<endl;
}
