#include <cstdio>
#include <ctime>

int gcd_asm( int a, int b ) {
    int result ;
    asm volatile( ".intel_syntax noprefix;\n"
            " mov   eax,  %1    ;\n"
            " mov   ebx,  %2    ;\n"
    "CHECK:   cmp   ebx,   0    ;\n"
            "  je  ISOK         ;\n"
            " xor   edx, edx    ;\n"
            "idiv   ebx         ;\n"
            " mov   eax, ebx    ;\n"
            " mov   ebx, edx    ;\n"
            " jmp CHECK         ;\n"
    "ISOK:    mov    %0, eax    ;\n"
        ".att_syntax;\n"
        : "=r" (result) : "r" (a), "r" (b) : "%eax","%ebx","%edx"
    );

    return result ;
}
int gcd_cpp(int A,int B){
    if(B<=0)return A;
    else    return gcd_cpp(B,A%B);
}
int gcd_loop(int A,int B){
    int temp;
    while(B>0){
        temp = B;
        B = A%B;
        A = temp;
    }
    return A;
}

#define CASENUM 1000000
#define NUMA 987654321
#define NAMB 901104318  //EENight
void evaluate(){
    int* golden = new int[CASENUM];
    int* ans    = new int[CASENUM];
    double gcd_cpp_time,gcd_asm_time;
    clock_t start;
    //===== run asm function  =====
    start = clock();
    for(int i=0,numA=NUMA,numB=NAMB;i<CASENUM;++i,++numA,++numB){
        ans[i]=gcd_asm(numA,numB);
    }
    gcd_asm_time = double(clock()-start)/CLOCKS_PER_SEC;
    //===== run cpp function =====
    start = clock();
    for(int i=0,numA=NUMA,numB=NAMB;i<CASENUM;++i,++numA,++numB){
        golden[i]=gcd_loop(numA,numB);
    }
    gcd_cpp_time = double(clock()-start)/CLOCKS_PER_SEC;
    //===== checking =====
    int error = 0;
    for(int i=0;i<CASENUM;++i){
        if(ans[i]!=golden[i]) ++error;
        if(ans[i]!=golden[i] && error==1) printf("first error at %d: %d(cpp)!=%d(asm)\n",i,golden[i],ans[i]);
    }
    if(error==0){
        if(gcd_asm_time<gcd_cpp_time) printf("WOW faster than what compiler did \\0.0/\n");
        else printf("Congratulation!!, you pass the work ^_^ \n");
    }else printf("there are %d error(s) T^T \n",error);


    printf("gcd_cpp_time = %f sec for %d times\n",gcd_cpp_time,CASENUM);
    printf("gcd_asm_time = %f sec for %d times\n",gcd_asm_time,CASENUM);

    delete [] ans;
    delete [] golden;
}

int main() {
    //int first=NUMA, second=NAMB ;
    //printf( "GCD of %d & %d is %d\n", first, second, gcd_asm(first, second) ) ;

    evaluate();

    return 0 ;
}



