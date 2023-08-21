#include <iostream>
using namespace std;

int SumaRec(int n){
    if(n>=0){
        return n + SumaRec(n-1);
    }
    else{
        return 0;
    }
}

int SumaIterativa(int n){
    int total=0;
    for(int i=0;i<=n;i++){
        total=total+i;
    }
    return total;
}

int SumaDirecta(int n){
    int resultado = (n>0) ? ((n*(n+1)/2)): 0;
    return resultado;
}

int main(){
    cout<<SumaIterativa(10);
    return 1;
}