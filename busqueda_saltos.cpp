#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    const int TAMANO = 5;
    int lista[TAMANO];

    cout << "Ingresa lista:" << endl;
    for (int i = 0; i < TAMANO; i++) {
        cout << "Numero [" << i + 1 << "]: ";
        cin >> lista[i];
    }

    int objetivo;
    cout << "Ingresa objetivo:" << endl;
    cin >> objetivo;

    int i = 0;
    while (i < TAMANO && lista[i] < objetivo) {
        i += 2;
    }

    i = i - 1;

    int encontrado = -1;
    for (int j = max(0, i); j <= min(i + 1, TAMANO - 1); j++) {
        if (lista[j] == objetivo) {
            encontrado = j;
            break;
        }
    }

    cout << encontrado;
    return 0;
}