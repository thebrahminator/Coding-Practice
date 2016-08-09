#include<iostream>
#include<string.h>

using namespace std;

int max(int a, int b)
{
    return (a>b)? a: b;
}

int lcs(char X[], char Y[], int m, int n)
{
    if(m==0||n==0)
        return 0;
    
    if(X[m-1]==Y[n-1])
        return 1+lcs(X, Y, m-1, n-1);

    return max( lcs(X, Y, m-1, n) , lcs(X, Y, m, n-1) );
}

int main()
{
    int m, n;
    
    char X[100], Y[100];

    cin>>X;
    cin>>Y;

    m = strlen(X);
    n = strlen(Y);
    
    int LCS = lcs(X,Y,m,n);
    cout<<"The length of the LCS is: "<<LCS<<endl;
}
