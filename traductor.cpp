#include <iostream>
#include <string>
#include <map>
#include <sstream>
#include <cctype>
#include <fstream>

using namespace std;

map<string, string> traducciones;

void inicializarTraducciones() {
    
    traducciones.insert(make_pair("asm", "ensamblador"));
    traducciones.insert(make_pair("auto", "automÃ¡tico"));
    traducciones.insert(make_pair("bool", "booleano"));
    traducciones.insert(make_pair("break", "salir"));
    traducciones.insert(make_pair("case", "caso"));
    traducciones.insert(make_pair("catch", "capturar"));
    traducciones.insert(make_pair("char", "carÃ¡cter"));
    traducciones.insert(make_pair("class", "clase"));
    traducciones.insert(make_pair("const", "constante"));
    traducciones.insert(make_pair("const_cast", "casting_constante"));
    traducciones.insert(make_pair("continue", "continuar"));
    traducciones.insert(make_pair("default", "predeterminado"));
    traducciones.insert(make_pair("delete", "eliminar"));
    traducciones.insert(make_pair("do", "hacer"));
    traducciones.insert(make_pair("double", "doble"));
    traducciones.insert(make_pair("dynamic_cast", "casting_dinÃ¡mico"));
    traducciones.insert(make_pair("else", "sino"));
    traducciones.insert(make_pair("enum", "enumeraciÃ³n"));
    traducciones.insert(make_pair("explicit", "explÃ­cito"));
    traducciones.insert(make_pair("extern", "externo"));
    traducciones.insert(make_pair("false", "falso"));
    traducciones.insert(make_pair("float", "flotante"));
    traducciones.insert(make_pair("for", "para"));
    traducciones.insert(make_pair("friend", "amigo"));
    traducciones.insert(make_pair("goto", "ir"));
    traducciones.insert(make_pair("if", "si"));
    traducciones.insert(make_pair("inline", "en_lÃ­nea"));
    traducciones.insert(make_pair("int", "entero"));
    traducciones.insert(make_pair("long", "largo"));
    traducciones.insert(make_pair("mutable", "mutable"));
    traducciones.insert(make_pair("namespace", "espacio_de_nombres"));
    traducciones.insert(make_pair("new", "nuevo"));
    traducciones.insert(make_pair("operator", "operador"));
    traducciones.insert(make_pair("private", "privado"));
    traducciones.insert(make_pair("protected", "protegido"));
    traducciones.insert(make_pair("public", "pÃºblico"));
    traducciones.insert(make_pair("register", "registro"));
    traducciones.insert(make_pair("reinterpret_cast", "casting_reinterpretado"));
    traducciones.insert(make_pair("return", "retorno"));
    traducciones.insert(make_pair("short", "corto"));
    traducciones.insert(make_pair("signed", "firmado"));
    traducciones.insert(make_pair("sizeof", "tamaÃ±o_de"));
    traducciones.insert(make_pair("static", "estÃ¡tico"));
    traducciones.insert(make_pair("static_cast", "casting_estÃ¡tico"));
    traducciones.insert(make_pair("struct", "estructura"));
    traducciones.insert(make_pair("switch", "cambiar"));
    traducciones.insert(make_pair("template", "plantilla"));
    traducciones.insert(make_pair("this", "este"));
    traducciones.insert(make_pair("throw", "lanzar"));
    traducciones.insert(make_pair("true", "verdadero"));
    traducciones.insert(make_pair("try", "intentar"));
    traducciones.insert(make_pair("typedef", "tipo_definido"));
    traducciones.insert(make_pair("typeid", "tipo_id"));
    traducciones.insert(make_pair("typename", "nombre_tipo"));
    traducciones.insert(make_pair("union", "uniÃ³n"));
    traducciones.insert(make_pair("unsigned", "sin_signo"));
    traducciones.insert(make_pair("using", "usando"));
    traducciones.insert(make_pair("virtual", "virtual"));
    traducciones.insert(make_pair("void", "vacÃ­o"));
    traducciones.insert(make_pair("volatile", "volÃ¡til"));
    traducciones.insert(make_pair("while", "mientras"));

    
    traducciones.insert(make_pair("exit", "salir_programa"));
    
    
    traducciones.insert(make_pair("string", "cadena"));
    traducciones.insert(make_pair("cout", "salida"));
    traducciones.insert(make_pair("cin", "entrada"));
    traducciones.insert(make_pair("endl", "finalizar"));
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
    cout << "Ingrese la palabra en ingles: ";
    cin >> palabra;
    cout << "Ingrese su traduccion al espanol: ";
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
        cout << "Ingrese la nueva traduccion: ";
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
void guardarDiccionarioEnArchivo() {
    ofstream archivo("diccionario.dat");
    if (!archivo) {
        cerr << "No se pudo crear el archivo diccionario.dat" << endl;
        return;
    }

    for (const auto& par : traducciones) {
        archivo << par.first << " => " << par.second << endl;
    }

    archivo.close();
    cout << "Diccionario guardado exitosamente en diccionario.dat\n";
}
void menuCRUD() {
    int opcion;
    do {
        cout << "\n--- Menu CRUD de Traducciones ---\n";
        cout << "1. Crear nueva traduccion\n";
        cout << "2. Leer (mostrar) todas las traducciones\n";
        cout << "3. Actualizar una traduccion\n";
        cout << "4. Eliminar una traduccion\n";
        cout << "5. Salir\n";
        cout << "Seleccione una opcion: ";
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
                cout << "Saliendo del menu...\n";
                break;
            default:
                cout << "Opcion no valida, intente de nuevo.\n";
        }
    } while (opcion != 5);
}

string traducirCodigo(const string& linea) {
    stringstream ss(linea);
    string palabra, resultado;

    while (ss >> palabra) {
        if (traducciones.find(palabra) != traducciones.end()) {
            resultado += traducciones[palabra] + " ";
        } else {
            resultado += palabra + " ";
        }
    }

    return resultado;
}

string traducirEstructurasDeControl(string linea) {
    size_t pos = 0;
    while ((pos = linea.find("if", pos)) != string::npos) {
        if (pos == 0 || !isalpha(linea[pos - 1])) {
            linea.replace(pos, 2, "si");
        }
        pos += 2;
    }

    pos = 0;
    while ((pos = linea.find("else", pos)) != string::npos) {
        if (pos == 0 || !isalpha(linea[pos - 1])) {
            linea.replace(pos, 4, "sino");
        }
        pos += 4;
    }

    return linea;
}

int main() {
    inicializarTraducciones();

    int opcion;
    do {
        cout << "\n--- Programa Principal ---\n";
        cout << "1. Traducir codigo C++\n";
        cout << "2. Administrar traducciones (CRUD)\n";
        cout << "3. Guardar traducciones en archivo\n";
        cout << "4. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        cin.ignore();

        if (opcion == 1) {
            string linea, codigo;
            cout << "Ingresa tu codigo C++ (termina con una linea vacia):" << endl;
            while (true) {
                getline(cin, linea);
                if (linea.empty()) break;
                codigo += linea + "\n";
            }

            string nombreArchivo;
            cout << "Ingrese el nombre del archivo para guardar la traduccion (sin extension): ";
            getline(cin, nombreArchivo);
            nombreArchivo += ".dat";

            ofstream archivoSalida(nombreArchivo);
            if (!archivoSalida) {
                cerr << "Error al crear el archivo " << nombreArchivo << endl;
                continue;
            }

            stringstream ss(codigo);
            string lineaTraducida;
            while (getline(ss, linea)) {
                linea = traducirEstructurasDeControl(linea);
                lineaTraducida = traducirCodigo(linea);

                size_t pos;
                while ((pos = lineaTraducida.find("{")) != string::npos) {
                    lineaTraducida.replace(pos, 1, "inicio ");
                }
                while ((pos = lineaTraducida.find("}")) != string::npos) {
                    lineaTraducida.replace(pos, 1, "fin ");
                }

                cout << lineaTraducida << endl;
                archivoSalida << lineaTraducida << endl;
            }

            archivoSalida.close();
            cout << "Traduccion guardada en " << nombreArchivo << endl;
        } else if (opcion == 2) {
            menuCRUD();
        } else if (opcion == 3) {
            guardarDiccionarioEnArchivo();
        } else if (opcion == 4) {
            cout << "Saliendo del programa...\n";
        }
    } while (opcion != 4);

    return 0;
}
