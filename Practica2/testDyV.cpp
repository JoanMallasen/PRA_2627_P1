#include <iostream>
#include <vector>
#include "DyV.h"

int main()
{
    std::vector<int> enteros = {8, 3, 1, 7, 0, 10, 2};
    std::cout << "Original: ";
    for (int x : enteros)
        std::cout << x << ' ';
    if (!enteros.empty())
        quicksort(enteros, 0, static_cast<int>(enteros.size()) - 1);
    std::cout << "\nOrdenado: ";
    for (int x : enteros)
        std::cout << x << ' ';
    int indiceInt = busquedaBinaria(7, enteros, 0, static_cast<int>(enteros.size()) - 1);
    std::cout << "\nBusqueda de 7: " << indiceInt << "\n\n";


    std::vector<float> reales = {3.5f, 1.2f, 8.7f, 2.4f, 5.1f};
    std::cout << "Original: ";
    for (float x : reales)
        std::cout << x << ' ';
    if (!reales.empty())
        quicksort(reales, 0, static_cast<int>(reales.size()) - 1);
    std::cout << "\nOrdenado: ";
    for (float x : reales)
        std::cout << x << ' ';
    int indiceFloat = busquedaBinaria(2.4f, reales, 0, static_cast<int>(reales.size()) - 1);
    std::cout << "\nBusqueda de 2.4: " << indiceFloat << "\n\n";
	
    std::vector<char> caracteres = {'d', 'a', 'z', 'c', 'b'};
    std::cout << "Original: ";
    for (char x : caracteres)
        std::cout << x << ' ';
    if (!caracteres.empty())
        quicksort(caracteres, 0,
                  static_cast<int>(caracteres.size()) - 1);
    std::cout << "\nOrdenado: ";
    for (char x : caracteres)
        std::cout << x << ' ';
    int indiceChar = busquedaBinaria('c', caracteres, 0, static_cast<int>(caracteres.size()) - 1);
    std::cout << "\nBusqueda de 'c': " << indiceChar << '\n';

    return 0;
}