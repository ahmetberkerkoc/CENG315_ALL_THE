
#include <iostream>
#include <fstream>
#include <random>
#include <ctime>



using namespace std;


void print(unsigned short* array,int N){
	for(int i=0;i<N;i++){
	cout<<array[i]<<" ";
	}
	cout<<endl;
}
//You may write your own helper functions here



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

//You may write your own helper functions here

int main(){
    int size=256;
    long int comparision=0;
    long int swap=0;
    double avg_dist=0;
    double  max_dist=0; 
    
   
    unsigned short arr[256] ={3977,
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


    /*
    int size=8;
    long int comparision=0;
    long int swap=0;
    double avg_dist=0;
    double  max_dist=0; 
    bool hoare=true;
    unsigned short* arr = new unsigned short [size];
    arr[0] = 2;
	arr[1] = 1;
	arr[2] = 14;
	arr[3] = 6;
	arr[4] = 3;
	arr[5] = 0;
	arr[6] = 99;
    arr[7] = 3;
    */
    //arr[8] = 0;
    //insertionSort(arr, comparision, swap, size);
    //mergeSort(arr,0,size-1);
    //selectionSort(arr,size);
    //bubleSort(arr,size);
    bool hoare=false;
    quickSort(arr,swap,avg_dist,max_dist,hoare,size);
    //quickSort3(arr,swap,comparision,size);
    cout<< "max dist: "<< max_dist << endl;
    cout<< "avg_dist: "<< avg_dist << endl;
    cout<< "Comparision "<< comparision << endl;
    cout<< "Swap: "<<swap<<endl;
    print(arr,size);



    return 0;
}