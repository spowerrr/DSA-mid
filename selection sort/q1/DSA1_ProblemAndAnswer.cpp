#include<bits/stdc++.h>
using namespace std;
void selection_sort_name(vector<char>&v,int n)
{
    for(int i=0; i<n-1; i++)
    {
        int minIndex=i;
        for(int j=i+1; j<n; j++)
        {
            if(v[minIndex]>v[j])
            {
                minIndex=j;
            }

        }
        swap(v[minIndex],v[i]);
    }
    for(int i=0; i<n; i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<"\n";
}

void selection_sort_ProductsNumber(vector<int>&a,int n)
{
    for(int i=0; i<n-1; i++)
    {
        int minIndex=i;
        for(int j=i+1; j<n; j++)
        {
            if(a[minIndex]>a[j])
            {
                minIndex=j;
            }

        }
        swap(a[minIndex],a[i]);
    }
    for(int i=0; i<n; i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<"\n";
}
int main()
{
    int n;
    cin>>n;
    vector<char>v(n);
    for(int i=0; i<n; i++)
    {
        cin>>v[i];
    }
    vector<int>a(n);
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
    }
    selection_sort_name(v,n);
    selection_sort_ProductsNumber(a,n);

    return 0;
}

