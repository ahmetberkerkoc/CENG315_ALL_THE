#include "the1.h"


//You can add your own helper functions

int sillySort(int* arr, long &comparison, long & swap, int size) 
{

    int num_of_calls=1;
	
	int temp;
	if(size<4){
        if(size<=1)
            return num_of_calls;
        else{
            comparison++;
            if(arr[0]>arr[1]){
                swap++;
                temp=arr[0];
                arr[0]=arr[1];
                arr[1]=temp;
            }   
            return num_of_calls;
        }
    }
    num_of_calls+=sillySort(arr,comparison,swap,size/2);
    num_of_calls+=sillySort(&arr[size/4],comparison,swap,size/2);
    num_of_calls+=sillySort(&arr[size/2],comparison,swap,size/2);
    num_of_calls+=sillySort(arr,comparison,swap,size/2);
    num_of_calls+=sillySort(&arr[size/4],comparison,swap,size/2);
    num_of_calls+=sillySort(arr,comparison,swap,size/2);
	
	return num_of_calls;
}
void merge(int *arr,int start1,int end1,int start2,int end2,long &comparision,int *total_arr,int k){
    int i,j,p,t;

    int size1 = end1 - start1 +1;
    int size2 = end2- start2 +1;
    int total = size1+size2;
    int  *arr1 = new int[size1];
    int *arr2 = new int[size2];
    
    for(i=0;i<size1;i++){
        arr1[i] = arr[start1+i];
    }
    for(i=0;i<size2;i++){
        arr2[i] = arr[start2+i];
    }

    i=0;
    j=0;
    

    while(i<size1 && j<size2){
        comparision++;
        if(arr1[i]<=arr2[j]){
            total_arr[k] =arr1[i];
            i++;
        }
        else{
            total_arr[k] =arr2[j];
            j++;
        }
        k++;
    }
    if(i<size1){
        for(p=i;p<size1;p++){
            total_arr[k] = arr1[p];
            k++;
        }
    }
    else{
        for(p=j;p<size2;p++){
            total_arr[k]=arr2[p];
            k++;
        }
    }



}

int crossMergeSort(int *arr, long &comparison, int size)
{
	
	//print(arr,size);
    int num_of_calls=1;
    int temp;
	if(size<4){
        if(size<=1)
            return num_of_calls;
        else{
            comparison++;
            if(arr[0]>arr[1]){
                
                temp=arr[0];
                arr[0]=arr[1];
                arr[1]=temp;
            }   
            return num_of_calls;
        }
    }
    else if(size>=4){
        num_of_calls+=crossMergeSort(arr,comparison,size/4);
        num_of_calls+=crossMergeSort(&arr[size/4],comparison,size/4);
        num_of_calls+=crossMergeSort(&arr[size/2],comparison,size/4);
        num_of_calls+=crossMergeSort(&arr[3*size/4],comparison,size/4);
    }
    int *h1 = new int[size];
    

    merge(arr,0,(size/4)-1,size/2,(3*size/4)-1,comparison,h1,0);
    merge(arr,size/4,(size/2)-1,(3*size/4),size-1,comparison,h1,size/2);
    merge(h1,0,size/2-1,size/2,size-1,comparison,arr,0);
	// Your code here
	
	return num_of_calls;
}