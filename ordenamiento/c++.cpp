#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Parte A: Ordenamiento de Burbuja
void burbuja(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        bool intercambiado = false; 
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                intercambiado = true;
            }
        }
        if (!intercambiado) break; // Lista ya ordenada 
    }
}

// Parte B: Ordenamiento por Selección 
void seleccion(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i; 
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        if (min_idx != i) {
            swap(arr[i], arr[min_idx]); // Único intercambio por iteración 
        }
    }
}

// Parte C: Merge Sort (Ordenamiento por Fusión)
vector<int> mezclar(const vector<int>& izq, const vector<int>& der) {
    vector<int> resultado;
    int i = 0, j = 0;
    // Fusionar mientras haya elementos en ambas mitades 
    while (i < izq.size() && j < der.size()) {
        if (izq[i] <= der[j]) {
            resultado.push_back(izq[i]);
            i++;
        } else {
            resultado.push_back(der[j]);
            j++;
        }
    }
    // Agregar elementos restantes 
    while (i < izq.size()) resultado.push_back(izq[i++]);
    while (j < der.size()) resultado.push_back(der[j++]);
    return resultado;
}

vector<int> mergesort(const vector<int>& arr) {
    if (arr.size() <= 1) return arr; // Caso base 

    int medio = arr.size() / 2;
    // Dividir y Vencer 
    vector<int> izq(arr.begin(), arr.begin() + medio);
    vector<int> der(arr.begin() + medio, arr.end());

    return mezclar(mergesort(izq), mergesort(der)); // Combinar 
}

int main() {
    string algoritmo;
    int n;

    if (!(cin >> algoritmo >> n)) return 0; // Lectura de parámetros 

    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i]; // Lectura de elementos

    // Selección del algoritmo 
    if (algoritmo == "burbuja") {
        burbuja(arr);
    } else if (algoritmo == "seleccion") {
        seleccion(arr);
    } else if (algoritmo == "mergesort") {
        arr = mergesort(arr);
    }

    // Imprimir resultado en una sola líne
    for (int i = 0; i < n; i++) {
        cout << arr[i] << (i == n - 1 ? "" : " ");
    }
    cout << endl;

    return 0;
}
