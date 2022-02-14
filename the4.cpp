#include <iostream>




using namespace std;


void print(int array[],int N){
	for(int i=0;i<N;i++){
	cout<<array[i]<<" ";
	}
	cout<<endl;
}



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



int main(){
    int N=10;
    int arr2[N]={32, 51, 51, 92, 54, 90, 13, 69, 20, 6};
    int *array=arr2;
    int number_of_calls;
    int mem2[N]={-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
    int *mem=mem2;
    int max;
    int fun=2;
    //cin>>fun;
    if(fun==0){
        max= recursive_sln(N-1,array,number_of_calls);
        cout<<"Input Array: "<<endl;
        print(array,N);
        cout<<endl;
        cout<<"Call: "<<number_of_calls;
        cout<<endl;
        cout<<"Max: "<<max;
    }
    else if(fun==1){
        max= memoization_sln(N-1,array,mem);
        cout<<"Input Array: "<<endl;
        print(array,N);
        cout<<endl;
        cout<<"Output Mem: "<<endl;
        print(mem,N);
        cout<<endl;
        cout<<"Call: "<<number_of_calls;
        cout<<endl;
        cout<<"Max: "<<max;
    }
     else if(fun==2){
        max= dp_sln(N,array,mem);
        cout<<"Input Array: "<<endl;
        print(array,N);
        cout<<endl;
        cout<<"Output Mem: "<<endl;
        print(mem,N);
        cout<<endl;
        cout<<"Call: "<<number_of_calls;
        cout<<endl;
        cout<<"Max: "<<max;
    }
    
    


    return 0;
}