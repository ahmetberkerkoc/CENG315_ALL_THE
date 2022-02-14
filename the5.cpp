#include "the5.h"
// do not add extra libraries here

/*
W: the width of the field
L: the length of the field
partitions: 2D Boolean array for partitions, if a partition of w x l exists then partitions[x][y] is true.
numberOfCalls/numberOfIterations: method specific control parameter
*/
int min(int x, int y){
    return (x<y)?x:y;
}
int min3(int x,int y,int z){
    int temp;
    if(x<y)
        temp=x;
    else
        temp=y;
    if(temp<z)
        return temp;
    else 
        return z;
}

int recursiveMethod(int W, int L, bool** partitions, int* numberOfCalls){
	int x;
    int M,N;
    int miny,miny2,minz,minz2;
    (*numberOfCalls)++;
	if(W==0||L==0)
		return 0;
    if(partitions[W][L])
        return 0;
    x = W*L;
    miny=W*L+1;
    for (M=1;M<=W/2;M++){
        miny2 = recursiveMethod(W-M,L,partitions,numberOfCalls) + recursiveMethod(M,L,partitions,numberOfCalls);
        if(miny2<miny)
            miny=miny2;
    }
    minz =W*L+1;
    for (N=1;N<=L/2;N++){
        minz2= recursiveMethod(W,L-N,partitions,numberOfCalls) + recursiveMethod(W,N,partitions,numberOfCalls);
        if(minz2<minz)
            minz=minz2;
    }
    

    return min3(x,miny,minz);
	
	
	// this is a dummy return value. YOU SHOULD CHANGE THIS!
}

int afterMemorization_array(int W,int L, bool** partitions, int* numberOfCalls,int** mem,int &big){
    int x;
	int M,N;
	int miny,miny2,minz,minz2;
	(*numberOfCalls)++;
	if(W==0||L==0)
		return 0;
    if(partitions[W][L])
        return 0;
	if(mem[W][L]!=big){
		return mem[W][L];	
	}
		
	else{
		x = W*L;
		miny=W*L+1;
		for (M=1;M<=W/2;M++){
        miny2 = afterMemorization_array(W-M,L,partitions,numberOfCalls,mem,big) + afterMemorization_array(M,L,partitions,numberOfCalls,mem,big);
        if(miny2<miny)
            miny=miny2;
    	}
    	minz =W*L+1;
		for (N=1;N<=L/2;N++){
			minz2= afterMemorization_array(W,L-N,partitions,numberOfCalls,mem,big) + afterMemorization_array(W,N,partitions,numberOfCalls,mem,big);
			if(minz2<minz)
				minz=minz2;
		}
		mem[W][L] = min3(x,miny,minz);
		return mem[W][L];
	}

}

int memoizationMethod(int W, int L, bool** partitions, int* numberOfCalls){
    (*numberOfCalls)++;
	int big = W*L+1;
	int** mem = new int*[W+1];
	for(int i = 0; i < W+1; i++){
		mem[i] = new int [L+1];
		for (int j = 0; j < L+1; j++){
			mem[i][j] = big;
		}
 	}
	return afterMemorization_array(W,L,partitions,numberOfCalls,mem,big);
}

int bottomUpMethod(int W, int L, bool** partitions, int* numberOfIterations){
	int x,i,j;
	int M,N;
	int big=W*L+1;
	int miny,miny2,minz,minz2;
	int** mem = new int*[W+1];
	for( i = 0; i < W+1; i++){
		mem[i] = new int [L+1];
		for ( j = 0; j < L+1; j++){
			mem[i][j] = big;
		}
 	}
	for(i=1;i<W+1;i++){
		for(j=1;j<L+1;j++){
			if(partitions[i][j]){
			    mem[i][j]=0;
			    continue;
			}
			x = i*j;
			miny=i*j+1;
			
			for (M=1;M<=i;M++){
				(*numberOfIterations)++;
				miny2 = mem[i-M][j] + mem[M][j];
				if(miny2<miny)
					miny=miny2;
			}
			
			minz =i*j+1;
			for (N=1;N<=j;N++){
				(*numberOfIterations)++;
				minz2 = mem[i][j-N] + mem[i][N];
				if(minz2<minz)
					minz=minz2;
			}
			
			mem[i][j] = min3(x,miny,minz);
		}
	}
		

	 return mem[W][L];
}
