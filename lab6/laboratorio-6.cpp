#include <iostream>
#include <string>
using namespace std;


struct Direccion {
    string calle;
    int numero;
    string ciudad;
};


struct Estudiante {
    string nombre;
    int edad;
    float calificaciones[5];
    Direccion direccion;
};


int main() {
    Estudiante estudiantes[50]; 
    int cantidad = 0; 
    int opcion;

    do {
        cout << "\n========= MENU =========" << endl;
        cout << "1. Ingresar estudiante" << endl;
        cout << "2. Mostrar todos los estudiantes" << endl;
        cout << "3. Buscar estudiante" << endl;
        cout << "4. Modificar estudiante" << endl;
        cout << "5. Salir" << endl;
        cout << "Elija una opcion: ";
        cin >> opcion;
        cin.ignore(); 

        if (opcion == 1) {
            
            cout << "\n--- INGRESAR NUEVO ESTUDIANTE ---" << endl;

            cout << "Nombre: ";
            getline(cin, estudiantes[cantidad].nombre);

            cout << "Edad: ";
            cin >> estudiantes[cantidad].edad;

            cout << "Ingrese 5 calificaciones:" << endl;
            for (int j = 0; j < 5; j++) {
                cout << "Calificacion " << j + 1 << ": ";
                cin >> estudiantes[cantidad].calificaciones[j];
            }
            cin.ignore();

            cout << "Calle: ";
            getline(cin, estudiantes[cantidad].direccion.calle);

            cout << "Numero: ";
            cin >> estudiantes[cantidad].direccion.numero;
            cin.ignore();

            cout << "Ciudad: ";
            getline(cin, estudiantes[cantidad].direccion.ciudad);

            cantidad++;
            cout << "✅ Estudiante agregado correctamente." << endl;
        }

        else if (opcion == 2) {
            
            if (cantidad == 0) {
                cout << "\nNo hay estudiantes guardados." << endl;
            } else {
                cout << "\n--- LISTA DE ESTUDIANTES ---" << endl;
                for (int i = 0; i < cantidad; i++) {
                    cout << "\nEstudiante #" << i + 1 << endl;
                    cout << "Nombre: " << estudiantes[i].nombre << endl;
                    cout << "Edad: " << estudiantes[i].edad << endl;
                    cout << "Calificaciones: ";
                    for (int j = 0; j < 5; j++) {
                        cout << estudiantes[i].calificaciones[j] << " ";
                    }
                    cout << endl;
                    cout << "Direccion: " << estudiantes[i].direccion.calle
                         << ", " << estudiantes[i].direccion.numero
                         << ", " << estudiantes[i].direccion.ciudad << endl;
                }
            }
        }

        else if (opcion == 3) {
            
            string nombreBuscar;
            bool encontrado = false;

            cout << "Ingrese el nombre del estudiante que desea buscar: ";
            getline(cin, nombreBuscar);

            for (int i = 0; i < cantidad; i++) {
                if (estudiantes[i].nombre == nombreBuscar) {
                    cout << "\nEstudiante encontrado:" << endl;
                    cout << "Nombre: " << estudiantes[i].nombre << endl;
                    cout << "Edad: " << estudiantes[i].edad << endl;
                    cout << "Calificaciones: ";
                    for (int j = 0; j < 5; j++) {
                        cout << estudiantes[i].calificaciones[j] << " ";
                    }
                    cout << endl;
                    cout << "Direccion: " << estudiantes[i].direccion.calle
                         << ", " << estudiantes[i].direccion.numero
                         << ", " << estudiantes[i].direccion.ciudad << endl;
                    encontrado = true;
                    break;
                }
            }

            if (!encontrado) {
                cout << " No se encontro ese estudiante." << endl;
            }
        }

        else if (opcion == 4) {
           
            string nombreModificar;
            bool encontrado = false;

            cout << "Ingrese el nombre del estudiante que desea modificar: ";
            getline(cin, nombreModificar);

            for (int i = 0; i < cantidad; i++) {
                if (estudiantes[i].nombre == nombreModificar) {
                    cout << "\nModificando datos de " << estudiantes[i].nombre << "..." << endl;

                    cout << "Nuevo nombre: ";
                    getline(cin, estudiantes[i].nombre);

                    cout << "Nueva edad: ";
                    cin >> estudiantes[i].edad;

                    cout << "Nuevas 5 calificaciones:" << endl;
                    for (int j = 0; j < 5; j++) {
                        cout << "Calificacion " << j + 1 << ": ";
                        cin >> estudiantes[i].calificaciones[j];
                    }
                    cin.ignore();

                    cout << "Nueva calle: ";
                    getline(cin, estudiantes[i].direccion.calle);

                    cout << "Nuevo numero: ";
                    cin >> estudiantes[i].direccion.numero;
                    cin.ignore();

                    cout << "Nueva ciudad: ";
                    getline(cin, estudiantes[i].direccion.ciudad);

                    cout << "✅ Datos modificados correctamente." << endl;
                    encontrado = true;
                    break;
                }
            }

            if (!encontrado) {
                cout << "❌ No se encontro ese estudiante." << endl;
            }
        }

        else if (opcion == 5) {
            cout << "👋 Saliendo del programa... Adios!" << endl;
        }

        else {
            cout << "Opcion no valida. Intente de nuevo." << endl;
        }

    } while (opcion != 5);

    return 0;
}
