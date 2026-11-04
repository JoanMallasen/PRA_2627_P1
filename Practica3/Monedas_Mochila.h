#ifndef PD_H
#define PD_H

#include <vector>
#include <limits>
#include <algorithm>

// ==========================================
// 1. Ejercicio: Cambio de Monedas
// ==========================================
void monedas(const std::vector<int>& m, int d, std::vector<int>& s) {
    int n = m.size();
    s.assign(n, 0); // Inicializar vector de solución (cantidades a devolver) a 0
    if (n == 0 || d <= 0) return;

    // Representación del valor "infinito" según las especificaciones de la práctica
    int inf_val = std::numeric_limits<int>::max();
    
    // Matriz de tamaño n x (d+1) inicializada a inf_val
    std::vector<std::vector<int>> T(n, std::vector<int>(d + 1, inf_val));

    // Inicializar la primera columna a 0 (0 monedas necesarias para cantidad 0)
    for (int i = 0; i < n; ++i) {
        T[i][0] = 0;
    }

    // Cálculo de la primera fila (moneda 0)
    for (int j = 1; j <= d; ++j) {
        if (j >= m[0] && T[0][j - m[0]] != inf_val) {
            T[0][j] = 1 + T[0][j - m[0]];
        }
    }

    // Cálculo del resto de las filas (resto de monedas)
    for (int i = 1; i < n; ++i) {
        for (int j = 1; j <= d; ++j) {
            if (j < m[i] || T[i][j - m[i]] == inf_val) {
                // Si la moneda es más grande que la cantidad j, o no hay solución previa, 
                // copiamos el valor de la fila superior
                T[i][j] = T[i - 1][j];
            } else {
                if (T[i - 1][j] != inf_val) {
                    // Tomamos el mínimo entre no usar la moneda o usarla
                    T[i][j] = std::min(T[i - 1][j], 1 + T[i][j - m[i]]);
                } else {
                    T[i][j] = 1 + T[i][j - m[i]];
                }
            }
        }
    }

    // Recuperar la solución de la matriz
    int i = n - 1;
    int j = d;
    while (j > 0 && i >= 0) {
        if (i == 0 || T[i][j] != T[i - 1][j]) {
            s[i] = s[i] + 1; // Sumamos 1 a la cantidad de esta moneda
            j = j - m[i];    // Restamos el valor de la moneda a la cantidad pendiente
        } else {
            i = i - 1;       // Pasamos a evaluar la moneda anterior
        }
    }
}

// ==========================================
// 2. Ejercicio: El Caso de la Mochila
// ==========================================
int mochila(const std::vector<int>& p, const std::vector<int>& b, int m, std::vector<int>& s) {
    int n = p.size();
    s.assign(n, 0); // Inicializar vector de solución (0: no elegido, 1: elegido)
    if (n == 0 || m <= 0) return 0;

    // Matriz para almacenar los beneficios máximos
    std::vector<std::vector<int>> g(n, std::vector<int>(m + 1, 0));

    // Inicialización de la primera fila (solo consideramos el objeto 0)
    for (int C = 0; C <= m; ++C) {
        if (p[0] <= C) {
            g[0][C] = b[0];
        }
    }

    // Cálculo del resto de filas (aplicando la ecuación de recurrencia)
    for (int i = 1; i < n; ++i) {
        for (int C = 0; C <= m; ++C) {
            if (p[i] > C) {
                // El objeto excede la capacidad actual, no lo podemos meter
                g[i][C] = g[i - 1][C];
            } else {
                // Elegimos el máximo beneficio entre no meter el objeto o meterlo y sumar su beneficio
                g[i][C] = std::max(g[i - 1][C], g[i - 1][C - p[i]] + b[i]);
            }
        }
    }

    // Recuperar la solución: determinamos qué objetos forman parte del beneficio máximo
    int C = m;
    for (int i = n - 1; i > 0; --i) {
        // Si el beneficio es diferente al de la fila superior, significa que el objeto fue incluido
        if (g[i][C] != g[i - 1][C]) {
            s[i] = 1;       // Marcamos el elemento como elegido
            C = C - p[i];   // Reducimos la capacidad de la mochila
        } else {
            s[i] = 0;       // Elemento descartado
        }
    }
    
    // Comprobar si el elemento inicial (i = 0) entró en la mochila
    if (C >= p[0] && g[0][C] == b[0]) {
        s[0] = 1;
    }

    // Retornamos el beneficio máximo alcanzado, ubicado en la esquina inferior derecha
    return g[n - 1][m];
}

#endif