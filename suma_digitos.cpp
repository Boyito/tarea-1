#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int suma = 0;

    while (n > 0) {
        suma += n % 10;
        n = n / 10;
    }

    cout << suma;
    return 0;
}