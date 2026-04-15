#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main() {
    string linea;
    getline(cin, linea);

    int contador = 0;

    for (char c : linea) {
        c = tolower(c);

        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            contador++;
        }
    }

    cout << contador;
    return 0;
}