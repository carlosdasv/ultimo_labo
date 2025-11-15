#include <iostream>
using namespace std;

int main() {
    
    string usuarioCorrecto = "admin";
    string contrasenaCorrecta = "1234";

    string usuario;
    string contrasena;

    int intentos = 0;
    int accesoPermitido = 0;

   
    while (intentos < 3) {
        cout << "Ingrese su usuario: ";
        cin >> usuario;

        cout << "Ingrese su contraseña: ";
        cin >> contrasena;

        if (usuario == usuarioCorrecto && contrasena == contrasenaCorrecta) {
            cout << "Acceso correcto.\n";
            accesoPermitido = 1;
            intentos = 3; 
        } else {
            cout << "Usuario o contraseña incorrectos.\n";
            intentos = intentos + 1;
        }
    }

    if (accesoPermitido == 0) {
        cout << "Demasiados intentos fallidos. Saliendo...\n";
    } else {
        
        int opcion = 0;
        int numero1;
        int numero2;
        int resultado;

        do {
           
            cout << "\n--- CALCULADORA ---\n";
            cout << "1. Sumar\n";
            cout << "2. Restar\n";
            cout << "3. Multiplicar\n";
            cout << "4. Dividir\n";
            cout << "5. Salir\n";
            cout << "Elija una opcion (1-5): ";
            cin >> opcion;

            if (opcion == 1) {
                cout << "Ingrese el primer número: ";
                cin >> numero1;
                cout << "Ingrese el segundo número: ";
                cin >> numero2;
                resultado = numero1 + numero2;
                cout << "Resultado: " << resultado << endl;
            } else {
                if (opcion == 2) {
                    cout << "Ingrese el primer número: ";
                    cin >> numero1;
                    cout << "Ingrese el segundo número: ";
                    cin >> numero2;
                    resultado = numero1 - numero2;
                    cout << "Resultado: " << resultado << endl;
                } else {
                    if (opcion == 3) {
                        cout << "Ingrese el primer número: ";
                        cin >> numero1;
                        cout << "Ingrese el segundo número: ";
                        cin >> numero2;
                        resultado = numero1 * numero2;
                        cout << "Resultado: " << resultado << endl;
                    } else {
                        if (opcion == 4) {
                            cout << "Ingrese el primer número: ";
                            cin >> numero1;
                            cout << "Ingrese el segundo número: ";
                            cin >> numero2;

                            if (numero2 == 0) {
                                cout << "Error: No se puede dividir entre 0.\n";
                            } else {
                                resultado = numero1 / numero2;
                                cout << "Resultado: " << resultado << endl;
                            }
                        } else {
                            if (opcion == 5) {
                                cout << "Saliendo de la calculadora...\n";
                            } else {
                                cout << "Opción no válida.\n";
                            }
                        }
                    }
                }
            }

        }
        while (opcion != 5);
    }
    return 0; 
}