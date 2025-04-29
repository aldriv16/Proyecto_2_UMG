#include <iostream>
#include <string>
#include <map>
#include <sstream>
#include <cctype>

using namespace std;

// Mapa de traducciones de palabras clave
map<string, string> traducciones;

void inicializarTraducciones() {
    traducciones.insert(make_pair("int", "entero"));
    traducciones.insert(make_pair("float", "flotante"));
    traducciones.insert(make_pair("if", "si"));
    traducciones.insert(make_pair("else", "sino"));
    traducciones.insert(make_pair("for", "para"));
    traducciones.insert(make_pair("while", "mientras"));
    // Puedes agregar más si quieres
}

void mostrarTraducciones() {
    cout << "\n--- Lista de traducciones ---\n";
    for (const auto& par : traducciones) {
        cout << par.first << " => " << par.second << endl;
    }
    cout << "------------------------------\n";
}

void crearTraduccion() {
    string palabra, traduccion;
    cout << "Ingrese la palabra en inglés: ";
    cin >> palabra;
    cout << "Ingrese su traducción al español: ";
    cin >> traduccion;
    traducciones[palabra] = traduccion;
    cout << "Traducción agregada exitosamente.\n";
}

void actualizarTraduccion() {
    string palabra;
    cout << "Ingrese la palabra que desea actualizar: ";
    cin >> palabra;

    auto it = traducciones.find(palabra);
    if (it != traducciones.end()) {
        cout << "Traducción actual: " << it->second << endl;
        cout << "Ingrese la nueva traducción: ";
        string nuevaTraduccion;
        cin >> nuevaTraduccion;
        it->second = nuevaTraduccion;
        cout << "Traducción actualizada correctamente.\n";
    } else {
        cout << "La palabra no existe.\n";
    }
}

void eliminarTraduccion() {
    string palabra;
    cout << "Ingrese la palabra que desea eliminar: ";
    cin >> palabra;

    if (traducciones.erase(palabra)) {
        cout << "Traducción eliminada exitosamente.\n";
    } else {
        cout << "La palabra no fue encontrada.\n";
    }
}

void menuCRUD() {
    int opcion;
    do {
        cout << "\n--- Menu CRUD de Traducciones ---\n";
        cout << "1. Crear nueva traducción\n";
        cout << "2. Leer (mostrar) todas las traducciones\n";
        cout << "3. Actualizar una traducción\n";
        cout << "4. Eliminar una traducción\n";
        cout << "5. Salir\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                crearTraduccion();
                break;
            case 2:
                mostrarTraducciones();
                break;
            case 3:
                actualizarTraduccion();
                break;
            case 4:
                eliminarTraduccion();
                break;
            case 5:
                cout << "Saliendo del menú...\n";
                break;
            default:
                cout << "Opción no válida, intente de nuevo.\n";
        }
    } while (opcion != 5);
}

int main() {
    inicializarTraducciones();
    
    int opcion;
    do {
        cout << "\n--- Programa Principal ---\n";
        cout << "1. Traducir código C++\n";
        cout << "2. Administrar traducciones (CRUD)\n";
        cout << "3. Salir\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;
        cin.ignore(); // limpiar el buffer de entrada

        if (opcion == 1) {
            string linea, codigo;
            cout << "Ingresa tu código C++ (termina con una línea vacía):" << endl;
            while (true) {
                getline(cin, linea);
                if (linea.empty()) break;
                codigo += linea + "\n";
            }

            stringstream ss(codigo);
            while (getline(ss, linea)) {
                stringstream palabras(linea);
                string palabra, lineaTraducida;

                while (palabras >> palabra) {
                    if (traducciones.find(palabra) != traducciones.end()) {
                        lineaTraducida += traducciones[palabra] + " ";
                    } else {
                        lineaTraducida += palabra + " ";
                    }
                }
                cout << lineaTraducida << endl;
            }
        } else if (opcion == 2) {
            menuCRUD();
        } else if (opcion == 3) {
            cout << "Adiós.\n";
        } else {
            cout << "Opción inválida, intenta de nuevo.\n";
        }
    } while (opcion != 3);

    return 0;
}
