#include<stdio.h>
#include<iostream>
using namespace std;

int max(int a, int b)
{
    return (a>b)? a : b;
}

int knapSack(int W, int wt[], int val[], int n)
{
    if( (n == 0) || (W == 0) )
        return 0;
    
    if(W<wt[n-1])
        return knapSack(W, wt, val, n-1);
    else
        return max( knapSack(W-wt[n-1], wt, val, n-1)+val[n-1], knapSack(W, wt, val, n-1) );
}

int main()
{
    int n;
    
    cout<<"Enter the value of n"<<endl;
    cin>>n;
    
    int wt[n], val[n];
    
    for(int i=0;i<n;i++)
    {
        cout<<"Enter the weight"<<endl;
        cin>>wt[i];

        cout<<"Enter the value"<<endl;
        cin>>val[i];
    }

    int W;
    cout<<"Enter the value of W"<<endl;
    cin>>W;

    cout<<"The maximum value possible is: "<<knapSack(W, wt, val, n)<<endl;
    
    return 0;
}
