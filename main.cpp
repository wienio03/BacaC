//Wieńczysław Włodyga
#include <iostream>

bool Universe(int x){
    if (x<=4095 && x>=1) return true;
    else return false;
}
void Cardinality(int set[], int* cardinality) {
    *(cardinality)=0;
    while (set[*cardinality]!=(-1)) {
            (*cardinality)++;
        }
}
void bubbleSort(int set[]) {
    int size;
    Cardinality(set, &size);
    int i,j;
    for (i=0; i<size; i++){
        for (j=1; j<size; j++){
            if (set[i]<set[j]) std::swap(set[i],set[j]);
        }
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
void Create(unsigned int usedElements, int sourceSet[], int set[]){
int i;
for (i=0; i<usedElements; i++){
    if(Universe(sourceSet[i]))Add(sourceSet[i],set);
}
}
void Union(int set1[],int set2[], int setResultant[]){
      int size1;
      int size2;
      setResultant[0]=-1;
      Cardinality(set2,&size2);
      Cardinality(set1,&size1);
      int sizeUnion;
      if(size1>size2) {
          sizeUnion = size1;
          int i,k;
          for (i=0; i<size1; i++){
              Add(set1[i],setResultant);
          }
          for (i=0; i<sizeUnion; i++){
              for(k=0; k<size2; k++){
                  if(setResultant[i]!=set2[k]) Add(set2[k], setResultant);
              }
          }
      }
      if(size2>size1) {
          sizeUnion = size2;
          int j,l;
          for (j=0; j<size2; j++){
              Add(set2[j], setResultant);
          }
          for (j=0; j<sizeUnion; j++){
              for(l=0; l<size1; l++){
                  if(setResultant[j]!=set1[l]) Add(set1[l], setResultant);
              }
          }

      }
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
    if (Universe(x)) return false;
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
    double aMean=0;
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
    double hMean=0;
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
bool Equal(int set1[], int set2[]){
    int size1,size2;
    Cardinality(set1,&size1);
    Cardinality( set2, &size2);
    if (size1!=size2) return false;
    else {
        bubbleSort(set1);
        bubbleSort(set2);
        for (int i = 0; i < size1; i++){
            if (set1[i]!=set2[i]) return false;
        }
    }
    return true;
}
bool Subset(int set1[], int set2[]){
    int size1,size2;
    Cardinality(set1,&size1);
    Cardinality(set2,&size2);
    int j, i,k=0;
    if(size1>size2){
        for (i=0;i<size2;i++){
            for(j=0;j<size1;j++){
                if(set2[i]==set1[j]) k++;
            }
        }
        if (k==size2) return true;
        else return false;
    }
    if(size1<size2){
        for(i=0;i<size1;i++){
            for(j=0;j<size2;j++){
                if(set1[i]==set2[j]) k++;
            }
        }
        if(k==size1) return true;
        else return false;
    }
    if(size1==size2) Equal(set1,set2);
}
int main() {
    int tab[5]={6,7,100,200,300};
    int creation[0];
    int array1[3]={1,2,-1};
    int array2[4]={1,2,3,-1};
    int array3[3]={1,3,-1};
    int array4[3]={1,2,-1};
    std::cout<<Equal(array1,array2)<<std::endl;
    std::cout<<Equal(array1,array3)<<std::endl;
    std::cout<<Equal(array1,array4)<<std::endl;
    int size1,size2,size3,size4;
    Cardinality(array1,&size1);
    Cardinality(array2,&size2);
    Cardinality(array3,&size3);
    Cardinality(array4,&size4);
    std::cout << size1 << " " << size2 << " " << size3 << " " << size4 << " " << Subset(array1,array4)<< std::endl;
    Add(6, array1);
    Add(7, array1);
    std::cout << array1[2]<<" "<<array1[3]<<" "<<array1[4]<<std::endl;
    Create(5,tab,creation);
    std::cout << creation[0] << creation[2]<<creation[5];
    return 0;
}
