#include <iostream>
#include <fstream>
using namespace std;

// FUNCIONES SOLICITADAS
void leerArchivo();
void clasificarNumeros();
void ordenarArchivo(const string &nombre);
void mostrarArchivo(const string &nombre);

// Método burbuja (simple)
void burbuja(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Lee datos.txt y solo muestra su contenido
void leerArchivo() {
    ifstream archivo("datos.txt");
    int num;

    if (!archivo.is_open()) {
        cout << "No se pudo abrir datos.txt" << endl;
        return;
    }

    cout << "Contenido de datos.txt: ";
    while (archivo >> num) {
        cout << num << " ";
    }
    cout << endl;
    archivo.close();
}

// Clasifica pares e impares
void clasificarNumeros() {
    ifstream archivo("datos.txt");
    ofstream pares("pares.txt"), impares("impares.txt");
    int num;

    if (!archivo.is_open()) {
        cout << "No se pudo abrir datos.txt" << endl;
        return;
    }

    while (archivo >> num) {
        if (num % 2 == 0)
            pares << num << " ";
        else
            impares << num << " ";
    }

    cout << "Numeros clasificados en pares.txt e impares.txt";
    archivo.close();
    pares.close();
    impares.close();
}

// Ordena archivo usando burbuja
void ordenarArchivo(const string &nombre) {
    ifstream archivo(nombre);
    int datos[100], n = 0;

    while (archivo >> datos[n]) {
        n++;
    }
    archivo.close();

    cout << "Antes de ordenar (" << nombre << "): ";
    for (int i = 0; i < n; i++) cout << datos[i] << " ";
    cout << endl;

    burbuja(datos, n);

    ofstream salida(nombre);
    for (int i = 0; i < n; i++) salida << datos[i] << " ";
    salida.close();

    cout << "Despues de ordenar (" << nombre << "): ";
    for (int i = 0; i < n; i++) cout << datos[i] << " ";
    cout << endl;
}

// Muestra un archivo
void mostrarArchivo(const string &nombre) {
    ifstream archivo(nombre);
    int num;

    cout << "Contenido de " << nombre << ": ";
    while (archivo >> num) cout << num << " ";
    cout << endl;
    archivo.close();
}

int main() {
    int opcion;

    do {
        cout << "MENU" << endl;
        cout << "1. Leer archivo" << endl;
        cout << "2. Clasificar numeros" << endl;
        cout << "3. Ordenar archivos" << endl;
        cout << "4. Ver resultados" << endl;
        cout << "5. Salir" << endl;
        cout << "Opcion: ";
        cin >> opcion;

        switch (opcion) {
        case 1: leerArchivo(); break;
        case 2: clasificarNumeros(); break;
        case 3: ordenarArchivo("pares.txt"); ordenarArchivo("impares.txt"); break;
        case 4: mostrarArchivo("pares.txt"); mostrarArchivo("impares.txt"); break;
        case 5: cout << "Saliendo..." << endl; break;
        default: cout << "Opcion invalida" << endl;
        }

    } while (opcion != 5);

    return 0;
}
