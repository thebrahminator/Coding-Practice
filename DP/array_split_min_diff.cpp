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

int findMin(int sumTotal, int sumCalculated, int arr[], int i)
{
    if(i==0)
        return abs( (sumTotal-sumCalculated) - sumCalculated);

    return min( findMin(sumTotal, sumCalculated+arr[i-1], arr, i-1), findMin(sumTotal, sumCalculated, arr, i-1)); 
}

int main()
{
    int n;
    cout<<"Enter the total number of elements"<<endl;
    cin>>n;

    int arr[n];
    cout<<"Enter the elements of the array"<<endl;
    for(int i=0;i<n;i++)
        cin>>arr[i];

    int sumTotal=0, sumCalculated=0;

    for(int i=0;i<n;i++)
        sumTotal = sumTotal + arr[i];

    cout<<"The minimum difference is: "<<findMin(sumTotal, 0, arr, n);
    cout<<endl;
}
