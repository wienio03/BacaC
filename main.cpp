//Wieńczysław Włodyga
#include <iostream>
void Cardinality(int set[], int* cardinality) {
    *(cardinality)=0;
    while (set[*cardinality]!=(-1)) {
            (*cardinality)++;
        }

}
void MinMax(int set[], int* min, int &max){
    int size;
    *min=set[0];
    max=set[0];
    int i = 0 , j = 0;
    Cardinality(set, &size);
    while (i<size) {
        if(set[i]>max) max=set[i];
        i++;
    }
    while (j<size) {
        if(set[j]<*min) *min=set[j];
        j++;
    }

}
void Add(int number, int set[]){
    int n;
    Cardinality(set,&n);
    if (number>=1 && number <=4095){
        n++;
    set[n-1]=number;
    set[n]=(-1);
    }
}
    void Union(int set1[],int set2[], int setResultant[]){
      int length1;
      int length2;
      Cardinality(set1,&length1);
      Cardinality(set2,&length2);
      int lengthUnion;
      if(length1>length2) lengthUnion=length1;
      if(length2>length1) lengthUnion=length2;
    }
    void Intersection (int set1[], int set2[], int setResultant[]){

}
bool Empty(int set[]){
    int size;
    Cardinality(set,&size);
    if(size==0) return true;
    if(size=!0) return false;
}
bool Nonempty(int set[]){
    int size;
    Cardinality(set,&size);
    if(size==0) return false;
    if(size!=0) return true;
}
bool Element(int x, int set[]){
    int n=0;
    int size;
    Cardinality(set, &size);
    if (x<1 || x>4095) return false;
    else {
        while(n<size-1 && x!=set[n]){
            if (x==set[n]) return true;
            n++;
            if(n==size-1) return false;
        }
    }
}
double Arithmetic (int set[]){
    int size;
    double aMean;
    int n = 0;
    Cardinality (set,&size);
    if (size==0) aMean=0;
    else {
        while(n<size){
            aMean+=set[n];
            n++;
        }
        aMean=(aMean/n);
    }
    return aMean;
}
double Harmonic (int set[]){
    int size;
    double hMean;
    double hDenominator=0;
    double hNumerator=0;
    int n = 0;
    Cardinality(set, &size);
    if (size==0) hMean=1;
    else {
        while (n<size){
            hDenominator+=(1.0/set[n]);
            n++;
        }
    hNumerator=size;
    hMean = hNumerator/hDenominator;
    }
    return hMean;
}
int main() {
    int array[5]={4,3,2,1, -1};
    int arraytest[1]{-1};
    int sizetest;
    int setsize;
    int number1=6;
    int maximum;
    int minimum;
    Add(number1,array);
    int z;
    for (z=0; z<6;z++) {
        std::cout << array[z] << " ";
    }
    Cardinality(array,&setsize);
    Cardinality(arraytest, &sizetest);
    std::cout << std::endl;
    std::cout << setsize;
    std::cout << std::endl;
    std::cout << sizetest << std::endl;
    std::cout << Harmonic(array) << std::endl;
    std::cout << Arithmetic(array)<< std::endl;
    MinMax(array, &minimum, maximum);
    std::cout << minimum << " " << maximum;
    return 0;

}