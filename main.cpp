//Wieńczysław Włodyga
#include <iostream>
void Add(int x, int setsize, int set[]) {
    int n = setsize;
    if (1 <= x && x <= 4095) {
        n = n + 1;
        set[n - 1] = x;
    }
}
void Create(unsigned int usedElements, int setArray[], int set[]){
        int i;
        for(i=0; i<usedElements; i++){
            if(setArray[i] >=1 && setArray[i] <= 4095) set[i]=setArray[i];
            else usedElements++;
                }
        }
void Union();
void Intersection();
void Difference();
void Symmetric();
void Complement();
bool Subset();
bool Equal();
bool Empty();
bool Element();
double Arithmetic();
double Harmonic();
void MinMax();
void Cardinality();
void Properties();

int main() {
    int x = 12;
    int setsize = 6;
    int set[6] = {1,2,4096,3,4,5};
    int uE = 3;
    int mySet[uE];
    Add(x,setsize,set);
    Create(uE,set,mySet);
    std::cout << set[5] << std::endl;
    std::cout << mySet[0] << " " << mySet[1] << " " << mySet[2];
return 0;
}
