#include <iostream>
#include <string>
using namespace std;

struct Record {
    int code;
    float promedio;
    string nombre;
		bool alto;
    enum Attribute { Code, Promedio, Nombre, Alto };
    
    // Función para obtener el atributo correspondiente
    string getAttribute(Attribute attr) const {
        switch (attr) {
            case Code:
                return to_string(code);
            case Promedio:
                return to_string(promedio);
						case Alto:
								return to_string(alto);
            case Nombre:
                return nombre;
            default:
                cerr << "Atributo no válido" << endl;
                exit(EXIT_FAILURE);
        }
    }
};

struct Record2 {
    int code;
    float promedio;
    string nombre;
    enum Attribute { Code, Promedio, Nombre };
};

int main() {
    Record r1 = {10, 85.5, "Juan"};

    // Llamando a la función para obtener el atributo
    cout << "Código: " << r1.getAttribute(Record::Code) << endl;
    cout << "Promedio: " << r1.getAttribute(Record::Promedio) << endl;
    cout << "Nombre: " << r1.getAttribute(Record::Nombre) << endl;


    cout << sizeof(Record) << " " << sizeof(Record2);
    return 0;
}
