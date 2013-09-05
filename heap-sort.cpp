#include<iostream>
using namespace std;
void heapify(int *a,int sizee)
{
    for(int i=sizee/2-1;i>=0;--i)
    {
        int par=a[i];
        int j=i;
        bool heap=false;
        while(!heap && 2*(j+1)<=sizee)
        {
            int k=2*(j+1)-1;
            if(k<sizee-1)
            {
                if(a[k+1]>a[k])k=k+1;
            }
            if(par>a[k])
                heap=true;
            else
            {
                a[j]=a[k];
                j=k;
            }
        }
        a[j]=par;

    }
}
void swapp(int *a,int start,int ele_no)
{
    int temp=a[start];
    a[start]=a[ele_no];
    a[ele_no]=temp;
}
void heapsort(int *a,int sizee)
{
    heapify(a,sizee);
    for(int i=1;i<sizee;++i)
    {
        swapp( a,0,sizee-i);
        heapify(a,sizee-i);
    }
}

int main()
{
    int a[]={2,9,7,6,5,8};
    heapsort(a,6);
    for(int i=0;i<6;++i)
        cout<<a[i]<<"\t";
}
