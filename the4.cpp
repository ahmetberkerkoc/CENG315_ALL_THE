#include "the4.h"



int recursive_sln(int i, int*& arr, int &number_of_calls){ //direct recursive
    number_of_calls+=1;
    int x,y;
    int temp,t;
    if(i==0) return arr[0];
    if(i==1) return (arr[1]>arr[0]?arr[1]:arr[0]);
    if(i==2){
        if(arr[1]>arr[0])
            temp=arr[1];
        else 
            temp=arr[0];
        if(arr[2]>temp)
            return arr[2];
        else 
            return temp;
    }
    x=recursive_sln(i-3,arr,number_of_calls) + arr[i];
    
    y=recursive_sln(i-1,arr,number_of_calls);
    
    t=(x>y)?x:y;
        return t;
    //your code here

    //return 0; // this is a dummy return value. YOU SHOULD CHANGE THIS!
}



int memoization_sln(int i, int*& arr, int*& mem){ //memoization
    int x,y;
    int temp,rtemp;
    //for size is less than 3 
    if(i==0){
        mem[0]=arr[0];
        return mem[0];
    }
    else if(i==1){
        mem[0]=arr[0];
        mem[1]=(arr[1]>arr[0]?arr[1]:arr[0]);        
        return mem[1];
    }
     else if(i==2){
        mem[0]=arr[0];
        mem[1]=(arr[1]>arr[0]?arr[1]:arr[0]);
    //mem[2]
        if(arr[1]>arr[0])
            temp=arr[1];
        else 
            temp=arr[0];
        if(arr[2]>temp)
            mem[2]= arr[2];
        else 
            mem[2]= temp;

        return mem[2];

    }
    //for size is greater than 3 
    
    
    
    
    mem[0]=arr[0];
    
    mem[1]=(arr[1]>arr[0]?arr[1]:arr[0]);
    //mem[2]
    if(arr[1]>arr[0])
        temp=arr[1];
    else 
        temp=arr[0];
    if(arr[2]>temp)
        mem[2]= arr[2];
    else 
      mem[2]= temp;
        
    
    
    if((i-3>=3) && (mem[i-3]==-1))
        x=memoization_sln(i-3,arr,mem) +arr[i];
    else 
        x=mem[i-3] + arr[i];
    if((i-1>=3) && (mem[i-1]==-1))
        y=memoization_sln(i-1,arr,mem);
   else
        y=mem[i-1];
 
    mem[i]=(x>y)?x:y;
    
    
    //your code here

    return mem[i]; // this is a dummy return value. YOU SHOULD CHANGE THIS!
}



int dp_sln(int size, int*& arr, int*& mem){ //dynamic programming
    
    
    
    
    int temp,i;
    mem[0]=arr[0];
    mem[1]=(arr[1]>arr[0]?arr[1]:arr[0]);
    //mem[2]
    
    if(arr[1]>arr[0])
        temp=arr[1];
    else 
        temp=arr[0];
    if(arr[2]>temp)
        mem[2]= arr[2];
    else 
      mem[2]= temp;
    //your code here
    for(i=3;i<size;i++)
        mem[i] = (mem[i-3]+arr[i]>mem[i-1])?(mem[i-3]+arr[i]):mem[i-1];
    return mem[size-1]; // this is a dummy return value. YOU SHOULD CHANGE THIS!
}

