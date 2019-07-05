//
// Created by utec on 05/07/19.
//

#ifndef PC4_MAXIMO_H
#define PC4_MAXIMO_H

#include <thread>
#include <vector>
#include <future>

using namespace std;

template <typename T>
void maximo_hilo(vector<T> conjunto, int a, int b,promise<T> prom){
    T max=conjunto[a];
    for (a=a+1;a<b;a++){
        if (max<conjunto[a]){
            max=conjunto[a];
        }
    }
    prom.set_value(max);
}

template <typename T>
T maximo(vector<T> conjunto, int n){
    if(conjunto.empty())
        return -1;

    vector<thread> hilos;
    int len = conjunto.size()/n;
    if(conjunto.size()%n!=0){
        len++;
    }
    vector<T> max;
    for (int i=0; i<n; i++){
        promise<T> prom;
        future<T> fut = prom.get_future();
        hilos.emplace_back(maximo_hilo<T>,conjunto,i*len,(i+1)*len,move(prom));
        max.emplace_back(fut.get());
    }
    for (int j = 0; j < n; ++j) {
        hilos[j].join();
    }
    T m=max[0];
    for (int i=1;i<max.size();i++){
        if (m<max[i]){
            m=max[i];
        }
    }
    return m;
}


#endif //PC4_MAXIMO_H
