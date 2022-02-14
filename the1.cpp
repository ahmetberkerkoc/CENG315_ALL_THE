#include <iostream>
#include <fstream>
#include <random>
#include <ctime>



using namespace std;

void print(int *array,int N){
	for(int i=0;i<N;i++){
	cout<<array[i]<<" ";
	}
	cout<<endl;
}

void Swap(int &a,int &b){ 
	int temp;
	temp=a;
	a=b;
	b=temp;
}


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


int main(){
    int size=256;
    long int comparision=0;
    long int swap=0;
    //int arr[1] = {5};
    //int arr[2] = {20,5};
    
    int arr[256] ={3977,
21668,
27290,
5656,
13295,
36,
22088,
24519,
10998,
12309,
21410,
23408,
2840,
2972,
28044,
10101,
31740,
21326,
31636,
12606,
6464,
18665,
15061,
31370,
29301,
16194,
28186,
18690,
19563,
26239,
18759,
29716,
1967,
10374,
11253,
17662,
20563,
10678,
28509,
7465,
31469,
16852,
19319,
22201,
13026,
328,
5987,
4962,
24037,
5769,
26887,
28029,
22714,
10198,
22522,
16219,
28992,
29991,
26528,
29913,
16814,
22115,
23703,
6964,
20765,
27091,
338,
8991,
7495,
1751,
7684,
2323,
29070,
18647,
10176,
22503,
12096,
18045,
27358,
14752,
27417,
18721,
13472,
2698,
1033,
6277,
16406,
8840,
5944,
11971,
27198,
18600,
30024,
26755,
29040,
1274,
31962,
1393,
17401,
17571,
32339,
3311,
8711,
1069,
3296,
27398,
5829,
29729,
24759,
22947,
3270,
19416,
11936,
27136,
423,
16014,
6324,
16992,
7408,
18104,
7269,
25599,
11836,
15255,
8639,
3401,
22170,
25870,
4078,
3146,
24882,
433,
2815,
5478,
3884,
29470,
16107,
29258,
23245,
1168,
23505,
7458,
30179,
32689,
10115,
7180,
1892,
944,
18500,
12493,
27730,
21140,
11472,
12484,
32737,
2256,
13725,
6428,
11996,
29463,
865,
13125,
23109,
30321,
3796,
23972,
19772,
16015,
28087,
19593,
18977,
9819,
26901,
22370,
29437,
3796,
18633,
9775,
4382,
6169,
30784,
21302,
2,
28867,
26752,
21752,
16247,
12152,
21353,
17507,
28927,
27326,
17467,
21321,
17529,
780,
2393,
1809,
6142,
21287,
29517,
2989,
20234,
15020,
1291,
13004,
9436,
14056,
31098,
29520,
32287,
32240,
16944,
32002,
32201,
20462,
25469,
13444,
24900,
29370,
20908,
11144,
26572,
2986,
13189,
26944,
18712,
19370,
11799,
5909,
32572,
8591,
7604,
26012,
26574,
26280,
24636,
15814,
71,
14742,
5279,
4695,
16813,
31582,
29597,
26009,
24431,
8893,
9680,
22353,
28049,
22972,
15085,
20210,
12808,
6531};
    int call;
    //arr[8] = 10;
    //insertionSort(arr, comparision, swap, size);
    //mergeSort(arr,0,size-1);
    //selectionSort(arr,size);
    //bubleSort(arr,size);
    //quickSort(arr,0,8);
    //call=crossMergeSort(arr,comparision,size);
    call=sillySort(arr,comparision,swap,size);
    cout<< "Comparision: "<< comparision << endl;
    cout<< "Swap: "<<swap<<endl;
    cout<<"Call: "<<call<<endl;
    print(arr,size);



    return 0;
}