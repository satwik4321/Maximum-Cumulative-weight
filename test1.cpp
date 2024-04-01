#include<bits/stdc++.h>
using namespace std;
#include<stdio.h>
#include<stdlib.h>

int iterativeMaxWeight(int n,int arr[]){
    int sum;
    int maxs=0;
    int first;
    int last;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            sum=0;
            for(int k=i;k<=j;k++){
                sum=sum+arr[k];
            }
            if(sum>maxs){ 
                maxs=sum;
                first=i;
                last=j;
            }
        }
    }
    return maxs;
} 
int crossingMax(int arr[],int low,int mid,int high){
    int s=0;
    int maxL,maxR,maxM,m1,m2;
    maxL=maxR=INT_MIN;
    for(int i=mid;i<=high;i++){
        s=s+arr[i];
        if(s>maxR) maxR=s;
    }
    s=0;
    for(int i=mid;i>=low;i--){
        s=s+arr[i];
        if(s>maxL) maxL=s;
    }
    printf("%d %d",maxL,maxR);
    maxM=maxL+maxR-arr[mid];
    return __max(__max(maxL,maxR),maxM);
}
int recursiveMaxWeight(int arr[], int low, int high){

if (low==high) return arr[low];
if (low>high) return INT_MIN;
int mid=(low+high)/2;
int m1=recursiveMaxWeight(arr,low,mid-1);
int m2=recursiveMaxWeight(arr,mid+1,high);
int m3=__max(m1,m2);
int m4=crossingMax(arr,low,mid,high);
return __max(m3,m4);
}

int optimalMaxWeight(int arr[],int n){
    const int MIN = -1e9;
    int s1=MIN;
    int s2=0;
    for(int i=0;i<n;i++){
       s2=s2+arr[i];
       if(s2>s1) s1=s2;
       if(s2<0) s2=0;
    }
    return s1;
}

int main()
{
int n;
int max=500;
int arr[max];
printf("Enter the testSize of array:");
scanf("%d",&n);
if(n==0){ 
    printf("The maximum cumulative weight is 0");
    exit(0);
        }
printf("Enter %d elements:",n);
for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
int ans1=iterativeMaxWeight(n,arr); /*iterativeMaxWeight uses naive approach to find the maximum cumulative weight*/
int ans2=recursiveMaxWeight(arr,0,n-1); /*recursiveMaxWeight uses divide and conquer approach to find the maximum cumulative weight*/
int ans3=optimalMaxWeight(arr,n);
if(ans1<0) ans1=0;
if(ans2<0) ans2=0;
printf("The maximum cumulative weight is %d\n",ans1);
printf("The maximum cumulative weight is %d\n",ans2);
printf("The maximum cumulative weight is %d",ans3);
return 0;
}