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
    traducciones.insert(make_pair("auto", "automático"));
    traducciones.insert(make_pair("bool", "booleano"));
    traducciones.insert(make_pair("break", "salir"));
    traducciones.insert(make_pair("case", "caso"));
    traducciones.insert(make_pair("catch", "capturar"));
    traducciones.insert(make_pair("char", "carácter"));
    traducciones.insert(make_pair("class", "clase"));
    traducciones.insert(make_pair("const", "constante"));
    traducciones.insert(make_pair("const_cast", "casting_constante"));
    traducciones.insert(make_pair("continue", "continuar"));
    traducciones.insert(make_pair("default", "predeterminado"));
    traducciones.insert(make_pair("delete", "eliminar"));
    traducciones.insert(make_pair("do", "hacer"));
    traducciones.insert(make_pair("double", "doble"));
    traducciones.insert(make_pair("dynamic_cast", "casting_dinámico"));
    traducciones.insert(make_pair("else", "sino"));
    traducciones.insert(make_pair("enum", "enumeración"));
    traducciones.insert(make_pair("explicit", "explícito"));
    traducciones.insert(make_pair("extern", "externo"));
    traducciones.insert(make_pair("false", "falso"));
    traducciones.insert(make_pair("float", "flotante"));
    traducciones.insert(make_pair("for", "para"));
    traducciones.insert(make_pair("friend", "amigo"));
    traducciones.insert(make_pair("goto", "ir"));
    traducciones.insert(make_pair("if", "si"));
    traducciones.insert(make_pair("inline", "en_línea"));
    traducciones.insert(make_pair("int", "entero"));
    traducciones.insert(make_pair("long", "largo"));
    traducciones.insert(make_pair("mutable", "mutable"));
    traducciones.insert(make_pair("namespace", "espacio_de_nombres"));
    traducciones.insert(make_pair("new", "nuevo"));
    traducciones.insert(make_pair("operator", "operador"));
    traducciones.insert(make_pair("private", "privado"));
    traducciones.insert(make_pair("protected", "protegido"));
    traducciones.insert(make_pair("public", "público"));
    traducciones.insert(make_pair("register", "registro"));
    traducciones.insert(make_pair("reinterpret_cast", "casting_reinterpretado"));
    traducciones.insert(make_pair("return", "retorno"));
    traducciones.insert(make_pair("short", "corto"));
    traducciones.insert(make_pair("signed", "firmado"));
    traducciones.insert(make_pair("sizeof", "tamaño_de"));
    traducciones.insert(make_pair("static", "estático"));
    traducciones.insert(make_pair("static_cast", "casting_estático"));
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
    traducciones.insert(make_pair("union", "unión"));
    traducciones.insert(make_pair("unsigned", "sin_signo"));
    traducciones.insert(make_pair("using", "usando"));
    traducciones.insert(make_pair("virtual", "virtual"));
    traducciones.insert(make_pair("void", "vacío"));
    traducciones.insert(make_pair("volatile", "volátil"));
    traducciones.insert(make_pair("while", "mientras"));

    
    traducciones.insert(make_pair("exit", "salir_programa"));
    
    
    traducciones.insert(make_pair("string", "cadena"));
    traducciones.insert(make_pair("cout", "salida"));
    traducciones.insert(make_pair("cin", "entrada"));
    traducciones.insert(make_pair("endl", "finalizar"));
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
    string linea;
    string codigo;

    cout << "Ingresa tu codigo C++ (termina con una linea vacia):" << endl;

    
    inicializarTraducciones();

   
    while (true) {
        getline(cin, linea);
        if (linea.empty()) break; 
        codigo += linea + "\n";
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
    }

    return 0;
}
