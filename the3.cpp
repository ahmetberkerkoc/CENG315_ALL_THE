

#include <iostream>



// do not add extra libraries here


/*
    arr       : array to be sorted, in order to get points this array should contain be in sorted state before returning
    ascending : true for ascending, false for descending 
    n         : number of elements in the array
    l         : the number of characters used in counting sort at each time
    
    you can use ceil function from cmath
    
*/




long long int translate(std::string arr){
    long long int r=0;
    long long int pow=1;
    int leng = arr.length() ;
    int i;
    for(i=leng-1;i>=0;i--){
        r = r + (arr[i]-65)*pow;
        pow=pow*26;  
    }
    

    return r;
}

long long int pow(long long int l){
    long long int res=26;
    while(l>1){
        res *=26;
        l--;
    }
    return res;
}
void countSort(std::string arr[],int size,long long int ex,bool ascending,int &iter,int l,int &c){
    std::string B[size];
    c++;
    int leng = arr[0].length();
    long long int i,temp;
    long long int mul;
    if((leng-c*l)<0)
        mul = pow(leng-(c-1)*l);
    else
        mul= pow(l);
    long long int C[mul] = {0};
    long long int index;

    for(i=0;i<size;i++){
        iter++;
        temp = translate(arr[i]);
        index = (temp/ex)%mul;
        C[index] +=1;
    }
    for(i=1;i<mul;i++){
        iter++;
        C[i] += C[i-1];
    }
    for(i=size-1;i>=0;i--){
        iter++;
        temp = translate(arr[i]);
        index = (temp/ex)%mul;
        B[C[index]-1] =arr[i];
         C[index] -=1;
    }

    for(i=0;i<size;i++){
        iter++;
        arr[i] = B[i];
    }
    

    //print(arr,size);
}


void countSort_d(std::string arr[],int size,long long int ex,bool ascending,int &iter,int l,int &c){
   std::string B[size];
    c++;
    int leng = arr[0].length();
    long long int i,temp;
    long long int mul;
    if((leng-c*l)<0)
        mul = pow(leng-(c-1)*l);
    else
        mul= pow(l);
    long long int C[mul] = {0};
    long long int index;
    
    for(i=0;i<size;i++){
        iter++;
        temp = translate(arr[i]);
        C[mul-1-(temp/ex)%mul] +=1;
    }
    for(i=1;i<mul;i++){
        iter++;
        C[i] += C[i-1];
    }
    for(i=size-1;i>=0;i--){
        iter++;
        temp = translate(arr[i]);
        //index = (temp/ex)%mul;
        B[C[mul-1-(temp/ex)%mul]-1] =arr[i];
        C[mul-1-(temp/ex)%mul] -=1;
    }

    for(i=0;i<size;i++){
        iter++;
        arr[i] = B[i];
    }
    

    //print(arr,size);
}



int radixSort(std::string arr[], bool ascending, int n, int l){
    int i;
    int leng = arr[0].length();
    int iter=0;
    long long int ex=1;
    int c=0;
     for(i=0;i<leng;i=i+l){
         iter++;
         if(ascending)
            countSort(arr,n,ex,ascending,iter,l,c);
         else
            countSort_d(arr,n,ex,ascending,iter,l,c);
         ex *=pow(l); 
     }
    return iter;
}


void print(std::string array[],int N){
	for(int i=0;i<N;i++){
	std::cout<<array[i]<<" ";
	}
	std::cout<<std::endl;
}




int main(){
    //int size = 200;
    //int size =7;
    int size = 10;
    //int size=4;
    //std::string arr[size] = {"AAA", "ABC", "ABA", "CCB"};
    //std::string arr[size] = {"BAAA", "AABC", "CDBA", "CACB", "ABAB", "ACAB", "CBCB"};
    std::string arr[size] = { "NWLRBBMQBHCD", "ARZOWKKYHIDD", "QSCDXRJMOWFR", "XSJYBLDBEFSA", "RCBYNECDYGGX", "XPKLORELLNMP", "APQFWKHOPKMC", "OQHNWNKUEWHS", "QMGBBUQCLJJI", "VSWMDKQTBXIX" };
    //std::string arr[size]{ "YOALTQJSVVEX", "KQDKMAPCFPRK", "FXMIQZWPPYCK", "ONDJIJGSBKEN", "KURSLIEQHQYY", "SWPJVRUJEZVO", "IBJJNNYAHRUS", "CYKJPJHJHWSC", "PMMVNJMXKVGY", "IGASYUMCSXLJ", "IVSPTLSJZGGN", "PSKBNTBYZBSZ", "VEBQDPZLKUDD", "FXOEFVTUPGXF", "ZBFACXCABFQF", "URSGLVKSSAZX", "XSTNYRSZUXAW", "WEYZJQGEIZMV", "UWOPZNMWHGJI", "ZDHTCJRANQAX", "GGDQFPOCOCRN", "RDJYLVGMAQHF", "ZZFNRFKZMNQR", "EEVSIMHBSTZD", "OIQQAZVZYBMR", "GYRSLHMSNHKX", "WUYONZTBJLRJ", "LPJJQVBWUURH", "DFBQOOPKINYV", "OUYYFRHQGQCW", "ODVKZMTCRVSF", "JHQTWQOKMOIS", "FSIOKKMAPHKO", "TGQMDKSOTKHR", "CXCPLMHSERIR", "EVRTCEKWKCKP", "PCDIOKARJEIU", "QPOXIXQMSHIU", "NSSXWDOLHRUW", "DWPMAXGSOXRY", "UHLORTKENDEJ", "ISVRKRNPPECR", "DKLTHDSBMDRD", "WCKLFOUPIRGU", "KWKZCMQGWEZE", "HRHVUZBSDLFI", "BCZJVHEGDOHG", "CAMYENENFMIB", "NJWQUDAVFBFB", "ILHMBQUDQIBW", "VIJCWSGJBEBY", "HDVNECQMNXAQ", "PUTIEXEAFOEB", "IMMLQPJYSHNW", "JDKZCLPRHJZM", "IGOPUUSCHENX", "TZXLGMJPRTOT", "GGNOPOAZUQOO", "KGSRMIRFHQSN", "DDEUYVQFBDTS", "RVROLHEVNXPB", "FGIOWCBBFHWD", "COIFRDXKYQYJ", "XFHMCWPJEXXC", "ZAEEHCKKQUPJ", "YPVYFWKFBRTD", "PJMVGLXILBMS", "FYEXTWGTLCRS", "YDZZWVELESIM", "DGUQJJIPJPME", "LVXYZRSXUUYT", "PEEVYNJDVGTE", "RBVAQIFDFEBE", "XWDSQDLFJRAH", "GLKDRDIIGDJZ", "NQCSUGYSCBMS", "GZZPSBWBMIEE", "NMMUSXTHPXCK", "DAEHESZKRYCL", "ZAMOJRSWFGSZ", "GNHVLJHQLLYP", "FZCWAGKBGWPR", "PHQXQIYWYFRL", "QBBCMBTSDXQD", "DCGMBWDSFVPV", "EQTCVNPOOQSC", "UNUXLNCQPIES", "EKLMFCJLSDPO", "SEEGVWIRJFQW", "USPLCTEJFPVL", "RGWKJMABQGJN", "CSGNZWMTQDGT", "YKCEBZPVFLHR", "ZHUQPEFRYMGZ", "IUUZXAUWNYCQ", "ZRLEESXEBSWQ", "YBJYPSZYOTZM", "VTKKTMBSFOYJ", "JWPKQNDQPOOG", "IPEXIFLFAXQT", "JRLQHKBQIRDY", "EIQVWGCFVIED", "OPIQMYKXRXNZ", "JQRRHUROCHLZ", "NPGIYMNOBYEP", "YQOSODRXTIRB", "FIRHSCIHUOSU", "CFIFFOUEFIWV", "NPUHZLIEWBMQ", "FWXZLPTPXDVC", "URIBAGWPVSWX", "EGDCHRSPOPOB", "HKQGPLIJDTMF", "ZKUXDRWJXZLH", "RDWFUMGDWWJO", "KUXNNMUOWONZ", "HJKHLVOCAKHX", "WPAVNMJXGIMV", "WGJTXZUEIFLT", "CBXFNGCMVEHJ", "QSIWCVTZBFSA", "EOFOVSKYUHDJ", "OHVLLEWEWFCB", "CWAFBUGHKLVG", "FFEBPJLFSGQD", "LPJJUMKWKMBN", "GJURWPXCXDDM", "OQRGZJLKYVVU", "JGSTUWGBFCUC", "RTEOYJAMCTSB", "DFNDAIYLQQGL", "MOOSQKUIDAYD", "LBPPUJQZOFDR", "OBEGRLTGZJYQ", "TUAYWYBJZSZW", "DPVUXYNLZRTT", "CPZEYZWSTYSR", "WWAYOZWURROO", "SBBTUWMZLNDK", "MBEHZWAXUBXJ", "CTFVLTLDWOWQ", "LLRWYUINXMWW", "LXWHYTQCNXYA", "SLFOADHLQYJR", "VSESGCRTZNBZ", "ITEXTCXLPECP", "KLCALMRGGXBO", "AUKZJNBRIFPB", "JONYTPQDASDL", "GXUMUXDUTPWC", "CZTKEIMNXBNS", "SDVSWAFCXBRU", "AWQTLMVPLRZR", "ZNGYQUSIZNCX", "QICPLVJMRAFE", "ODTCUUVVICWY", "YOHZCJXUTZJH", "UVTNXARNFMRZ", "GNXOPTPPHYOL", "JNFDORMKOFXL", "HQANCSOJFLZW", "EONMOBXYRFDF", "WPQMWNZDGZSI", "RHTYUTUZJHNY", "LMWCRZHPQZBM", "NAPVAKDTRZSL", "SOMBYBBJOXNF", "YWXOWYCLBUGD", "ELWVMQIEFXID", "YLOMLDUJZRAX", "REKSYSVCGUZS", "KKZRHHWHUMWF", "PQRRJTQAXBVW", "TQYZMAUXKTQT", "CNAWBWCROTKZ", "MAALDXHXPIYC", "IUBSNRLPGNOI", "KQBALLAZNCKR", "ZUQQCQSMLTEA", "NRSTEGDQYGTL", "TTMHXWAYSSOW", "IHIVCOYPHQLM", "YQEWXXJSSVBP", "TBPMVGKGNTBR", "JZJRRUFPMJNL", "JWEBRHTLLKZG", "QJMDCQXORGFJ", "CMAOXOCGKGKE", "NDPYNOHEZTJE", "JISDOZMQLMHK", "CJRNRDTGGIHV", "YOBXJNDTVVYM", "WKEJYNUBWLQP", "OLWWTFTTTXSC", "MWXJTVVQHCZG", "PTJOGBDWMBUH", "GQCZPUEBSDMO", "ZIEGMFOBBZPJ", "CVIQWEZFUBEL", "YKMSOZGNJMVX" };
    
    int l=3;
    //int l=2;
    bool ascending=true;
    int iter;
    iter = radixSort(arr,ascending,size,l);
    std::cout<<"iter: "<<iter<<std::endl;

   
    print(arr,size);



    return 0;
}