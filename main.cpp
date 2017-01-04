#include <iostream>
#include <string>
using namespace std;
void full (string dnas[], int size);
string two(string& dna1, string& dna2, int index);
int length(string dna1, string dna2);

int main()
{   //the original one is: ACCTGGACTGACCGCAGTT ACTT AGGATACCTAGATAACC GCTTATGCAACAGGT
    int const size=5;
    string dnas[size]={"TT ACTT AGGATACCTAGATAA","ACTGACCGCAGTT ACTT A","C GCTTATGCAACAGGT","ACCTGGACTGACCGC","ATACCTAGATAACC GCTTATGC"};
    full (dnas, size);
    int fnl=0;
    for (int i=1; i<size; i++){
        if (dnas[i].length()> dnas[fnl].length())
            fnl=i;
    }
    cout<< dnas[fnl]<<endl;
    return 0;
}

void full (string dnas[], int size){
    int index=0;
for (int i=0; i<size; i++){
        int a=0, x=0;
    for (int j=0; j<size; j++){
        index=length(dnas[i],dnas[j]);
        if (index>a){
            a=index;
            x=j;
        }
    }
    if (a>=8){
        dnas[i]=two(dnas[i], dnas[x], a);
        i--;
    }
}
}

int length(string dna1, string dna2){
    int index=0;
    for (int overlap=8; overlap< dna1.length() && overlap< (dna2.length()-1); overlap++){
       string test1="", test2="";
        for (int i=0; i<overlap; i++){
            test1=test1 + dna1[(dna1.length())-overlap+i];
            test2=test2 + dna2[i];}
        if (test1==test2){
            index=overlap;}
        }
    return index;
}


string two(string& dna1, string& dna2, int index){
    string dna0=dna1;
    for(int i=index; i<dna2.length(); i++){
        dna0=dna0+dna2[i];
    }
    return dna0;
}
