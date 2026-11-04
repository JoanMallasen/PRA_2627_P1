#include <iostream>
#include <vector>
#include "Monedas_Mochila.h"

int main() {
    // ==========================================
    // PRUEBA 1: Cambio de Monedas
    // ==========================================
    std::cout << "--- EJERCICIO: CAMBIO DE MONEDAS ---\n";
    std::vector<int> m = {1, 4, 6};
    int d = 8;
    std::vector<int> s_monedas;
    
    monedas(m, d, s_monedas);
    
    std::cout << "Cantidad a devolver: " << d << "\nMonedas usadas:\n";
    for (size_t i = 0; i < m.size(); ++i) {
        if (s_monedas[i] > 0) {
            std::cout << " -> " << s_monedas[i] << " moneda(s) de " << m[i] << " u.v.\n";
        }
    }
    std::cout << "\n";

    // ==========================================
    // PRUEBA 2: El Caso de la Mochila (Ejemplo A)
    // ==========================================
    std::cout << "--- EJERCICIO: LA MOCHILA (Ejemplo A) ---\n";
    std::vector<int> p1 = {9, 6, 5};
    std::vector<int> b1 = {38, 40, 24};
    int M1 = 15;
    std::vector<int> s_mochila1;
    
    int beneficio1 = mochila(p1, b1, M1, s_mochila1);
    
    std::cout << "Beneficio maximo alcanzado: " << beneficio1 << "\nElementos elegidos (indices): ";
    for (size_t i = 0; i < s_mochila1.size(); ++i) {
        if (s_mochila1[i] == 1) std::cout << i << " ";
    }
    std::cout << "\n\n";

    // ==========================================
    // PRUEBA 3: El Caso de la Mochila (Ejemplo B)
    // ==========================================
    std::cout << "--- EJERCICIO: LA MOCHILA (Ejemplo B) ---\n";
    std::vector<int> p2 = {1, 3, 2, 4};
    std::vector<int> b2 = {10, 20, 15, 20};
    int M2 = 5;
    std::vector<int> s_mochila2;
    
    int beneficio2 = mochila(p2, b2, M2, s_mochila2);
    
    std::cout << "Beneficio maximo alcanzado: " << beneficio2 << "\nElementos elegidos (indices): ";
    for (size_t i = 0; i < s_mochila2.size(); ++i) {
        if (s_mochila2[i] == 1) std::cout << i << " ";
    }
    std::cout << "\n";

    return 0;
}