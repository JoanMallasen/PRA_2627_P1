#ifndef DYV_H
#define DYV_H

#include <vector>
#include <stdexcept>

using namespace std;

template <typename T>
int busquedaBinaria(T x, const vector<T>& V, int ini, int fin) {
    if (ini > fin) {
        return -1;
    }
    int medio = ini + (fin - ini) / 2;

    if (V[medio] == x) {
        return medio;
    } else if (V[medio] > x) {
        return busquedaBinaria(x, V, ini, medio - 1);
    } else {
        return busquedaBinaria(x, V, medio + 1, fin);
    }
}

template <typename T>
int partition(vector<T>& V, int ini, int fin) {
    T x = V[fin];
    int i = ini;
    for (int j = ini; j < fin; j++) {
        if (V[j] <= x) {
            T temp = V[i];
            V[i] = V[j];
            V[j] = temp;
            i++;
        }
    }
    T temp = V[i];
    V[i] = V[fin];
    V[fin] = temp;
    return i;
}

template <typename T>
void quicksort(vector<T>& V, int ini, int fin) {
    if (ini < fin) {
        int pivot = partition(V, ini, fin);
        quicksort(V, ini, pivot - 1);
        quicksort(V, pivot + 1, fin);
    }
}

#endif
