#include <cstdio>
#include <ctime>

int base8_asm( int num ) {
    int result;
    asm volatile(".intel_syntax noprefix;\n"
    // ===== add your codes here =====
            " mov   eax,  %1    ;\n"
            " mov    %0, eax    ;\n"
    // =====---------------------=====
        ".att_syntax;\n" : "=r" (result) : "r" (num) : "%eax","%ebx","%ecx","%edx"
                                        // ^ you can add more varibles/general purpose registers if you need them
    );
    return result ;
}
int base8_cpp( int num ){
    int result = 0;
    int base = 1;
    int rem;

    do{
        rem = num%8;
        num /= 8;
        result += rem * base;
        base *= 10;
    }while(num>0);

    return result ;
}

#define CASENUM 10000000
#define NUM 0
void evaluate(){
    int* golden = new int[CASENUM];
    int* ans    = new int[CASENUM];
    double cpp_time,asm_time;
    clock_t start;
    //===== run asm function  =====
    start = clock();
    for(int i=0,numA=NUM;i<CASENUM;++i,++numA){
        ans[i]=base8_asm(numA);
    }
    asm_time = double(clock()-start)/CLOCKS_PER_SEC;
    //===== run cpp function =====
    start = clock();
    for(int i=0,numA=NUM;i<CASENUM;++i,++numA){
        golden[i]=base8_cpp(numA);
    }
    cpp_time = double(clock()-start)/CLOCKS_PER_SEC;
    //===== checking =====
    int error = 0;
    for(int i=0;i<CASENUM;++i){
        if(ans[i]!=golden[i]) ++error;
        if(ans[i]!=golden[i] && error==1) printf("first error at %d: %d(cpp)!=%d(asm)\n",i,golden[i],ans[i]);
    }
    if(error==0){
        if(asm_time<cpp_time) printf("Congratulation!!, you pass the bonus work ^_^ \n");
        else printf("You pass the basic problem, it's near the bonus requirement >w< \n");
    }else printf("there are %d error(s) T^T \n",error);


    printf("cpp_time = %f sec for %d times\n",cpp_time,CASENUM);
    printf("asm_time = %f sec for %d times\n",asm_time,CASENUM);

    delete [] ans;
    delete [] golden;
}

int main(){
    //printf("result: %d\n",base8_asm(23));
    //printf("result: %d\n",base8_asm(1024));
    //printf("result: %d\n",base8_asm(1234));
    //printf("result: %d\n",base8_cpp(23));
    //printf("result: %d\n",base8_cpp(1024));
    //printf("result: %d\n",base8_cpp(1234));

    //for(int i=0;i<100;++i)
        evaluate();

    return 0;
}
