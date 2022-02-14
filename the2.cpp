#include "the2.h"

//You may write your own helper functions here
void Swap(unsigned short &a,unsigned short &b){ 
	int temp;
	temp=a;
	a=b;
	b=temp;
}


int partition(unsigned short* arr,int start, int end, long &swap, double & avg_dist, double & max_dist){
    int pivot = arr[end];
    int i=-1;
    int j;
    int distance;
    for(j=0;j<=end-1;j++){
        if(arr[j]>=pivot){
            i=i+1;
            Swap(arr[i],arr[j]);
            distance = j-i;
            swap++;
            
            if(distance<0)
                distance= -1*distance;
            avg_dist = (avg_dist*(swap-1) +distance)/swap;
            if(distance>max_dist)
                max_dist=distance;
        }
    }
    
    Swap(arr[i+1],arr[end]);
    distance = end-(i+1);
    swap++;
            
    if(distance<0)
        distance= -1*distance;
    avg_dist = (avg_dist*(swap-1) +distance)/swap;
    if(distance>max_dist)
        max_dist=distance;
    
    return i+1;

}

int HOARE(unsigned short* arr,int start, int end,long &swap, double & avg_dist, double & max_dist){
    int pivot = arr[end/2];
    int i=-1;
    int j=end-start+1;
    int distance;
    while (1)
    {
        j=j-1;
        while(arr[j]<pivot){
            j=j-1;
        }
            
        i=i+1;
        while (arr[i]>pivot)
        {
            i=i+1;
        }
        if(i<j){
            Swap(arr[i],arr[j]);
            distance=j-i;
            swap++;
            
            if(distance<0)
                distance= -1*distance;
            avg_dist = (avg_dist*(swap-1) +distance)/swap;
            if(distance>max_dist)
                max_dist=distance;
        }
        else
            return j;
        
    }
    
   
}

void quickSort(unsigned short* arr, long &swap, double & avg_dist, double & max_dist, bool hoare, int size)
{
    int p;
    if(size>1){
        if(hoare){
            p=HOARE(arr,0,size-1,swap,avg_dist,max_dist);
            quickSort(arr,swap,avg_dist,max_dist,hoare,p+1);
            quickSort(arr+p+1,swap,avg_dist,max_dist,hoare,size-1-p);
        }
            
        else{
            p=partition(arr,0,size-1,swap,avg_dist,max_dist);
            quickSort(arr,swap,avg_dist,max_dist,hoare,p);
            quickSort(arr+p+1,swap,avg_dist,max_dist,hoare,size-1-p);
        }
        

    }
}

void Swap_m_element(unsigned short* arr1,unsigned short* arr2,int m){
    int i,temp;
    for(i=0;i<m;i++){
        temp=arr1[i];
        arr1[i]=arr2[i];
        arr2[i] = temp;
    }
}
 
int* partition3way(unsigned short* arr,int start, int end,long &swap, long &comparison ){
    int *LR = new int[2];
    int i=0;
    int j=0;
    int p = end;
    int m;
    int size = end-start+1;

    while (i<p)
    {   
        
        if(arr[i]>arr[end]){
            comparison++;
            Swap(arr[i],arr[j]);
            swap++;
            i=i+1;
            j=j+1;
        }
        
        else if(arr[i]==arr[end]){
            comparison+=2;
            p=p-1;
            Swap(arr[i],arr[p]);
            swap++;
        }
        else {
            comparison+=2;
            i=i+1;
        }
            
        
    }
    if((p-j)>(size-p))
        m=size-p;
    else    
        m=p-j;
    Swap_m_element(arr+j,arr+size-m,m);
    swap=swap+m;
    LR[0]=j;
    LR[1]=p-j;

    return LR;
    
    

}

void quickSort3(unsigned short *arr, long &swap, long &comparison, int size) {
	
    //Your code here
    int *LR;
    if(size>1){
        LR = partition3way(arr,0,size-1,swap, comparison);
        quickSort3(arr,swap,comparison,*LR);
        quickSort3(arr+size-(*(LR+1)),swap,comparison,*(LR+1));


    }	
}