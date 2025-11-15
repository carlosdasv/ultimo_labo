#include <iostream>
using namespace std;

int main() {
    int numero;
    int factorial = 1;

    
    cout << "Escribe un número entero positivo: ";
    cin >> numero;

    
    if (numero < 0) {
        cout << "El número debe ser positivo." << endl;
    } else {
        
        for (int i = 1; i <= numero; i++) {
            factorial = factorial * i;
        }

       
        cout << "El factorial de " << numero << " es: " << factorial << endl;
    }

    
    cout << "Fin del programa." << endl;

    return 0;
}