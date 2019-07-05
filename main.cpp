#include <iostream>
#include <vector>
#include <thread>
#include <future>
#include <assert.h>
#include "maximo.h"

using namespace std;

int main() {
    vector<int> n0={};
    vector<int> n1={10};
    vector<int> numeros={8,4,3,1,9,2,10};
    assert(maximo(n0,5)==-1);
    assert(maximo(n1,2)==10);
    assert(maximo(numeros,3)==10);

    vector<double> n2={};
    vector<double> n3={1.1};
    vector<double> numeros2={1.1,2.5,0.8,3.4,1.3,2.1};
    assert(maximo(n2,2)==-1);
    assert(maximo(n3,1)==1.1);
    assert(maximo(numeros2,5)==3.4);

    vector<char> letras={'y','d','f','z','a'};
    assert(maximo(letras,4)=='z');

    return 0;
}