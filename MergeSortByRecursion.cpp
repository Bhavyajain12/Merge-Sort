#include<iostream>
using namespace std;
void Merge(int* arr, int start, int end)
{
    int mid=start+(end-start)/2;

    int Len1=mid-start+1;
    int Len2=end-mid;

    int* first=new int[Len1];
    int* Second=new int[Len2];

    //copying elements in array
    int MainArrayIndex=start ;
    for(int i=0;i<Len1;i++)
    {
        first[i]=arr[MainArrayIndex++];
    }
     MainArrayIndex=mid+1;
    for(int i=0;i<Len2;i++)
    {
        Second[i]=arr[MainArrayIndex++];
    }

    //merge two sorted arrays
    int index1=0;
    int index2=0;
    MainArrayIndex=start;
    while(index1<Len1 && index2<Len2)
    {
        if(first[index1]<Second[index2])
        {
            arr[MainArrayIndex++]=first[index1++];
        }
        else
        {
            arr[MainArrayIndex++]=Second[index2++];
        }
    }
    while(index1<Len1)
        {
            arr[MainArrayIndex++]=first[index1++];
        }
        while(index2<Len2)
        {
            arr[MainArrayIndex++]=Second[index2++];
        }
        delete []first;
        delete []Second;
}
void MergeSort(int* arr, int start, int end)
{
    //base condition
    if(start>=end)
    {
        return;
    }

    int mid=start+(end-start)/2;

    //sort left part
    MergeSort(arr,start,mid);

    //sort right part
    MergeSort(arr,mid+1,end);

    //merge
    Merge(arr,start,end);
}
int main()
{
    int n;
    cin>>n;
    int* arr=new int[n];
    cout<<"Enter Numbers :"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<endl;
    cout<<"Before Merge Sort "<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    MergeSort(arr,0,n-1);
    cout<<"After Merge Sort "<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}
