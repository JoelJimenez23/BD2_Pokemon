#include "avl.hpp"
#include <cstdlib>
#include <iostream>
#include "persona.hpp"

using namespace std;

greater<int> cmp;

function<int(Persona &)> index_dni = [](Persona& p) -> int {return p.dni;};
function<int(Persona &)> index_edad = [](Persona& p) -> int {return p.edad;};

void test_dni(){
    AVLFile<int, Persona, decltype(index_dni), decltype(cmp)> avl("personas.dat","dni",index_dni, cmp);
    if (!avl){
        avl.create_index();
        cout << "INDICE CREADO" << endl;
    }

    Persona p(77866655, "Alvamau", "Garcia", "CS", 19, 123, 1.80, 70);
    cout << "INSERTANDO UN NUEVO REGISTRO CON DNI: " << p.dni << endl;
    avl.insert(p);
    avl.print();

    vector<Persona> res;
    cout << "BUSQUEDA POR DNI A LA PERSONA CON DNI 12345678" << endl;
    res = std::move(avl.search(12345678));
    for (auto &p : res){
        cout << p << endl;
    }

    cout << "BUSQUEDA POR RANGO DE DNIs ENTRE 10000000 Y 20000000" << endl;
    res = std::move(avl.range_search(10000000, 20000000));
    for (auto &p : res){
        cout << p << endl;
    }

    vector<Persona> ordenado = std::move(avl.inorder());
    cout << "\nIN ORDER TRAVERSAL USANDO DNI COMO LLAVE DE ORDENACION" << endl;
    for (auto &p : ordenado){
        cout << p << endl;
    }

    cout << "ELIMINANDO 12345678 y 77766655" << endl;
    avl.remove(12345678);
    avl.remove(77766655);

    ordenado = std::move(avl.inorder());
    cout << "\nIN ORDER DESPUES DE LA ELIMINACION" << endl;
    for (auto &p : ordenado){
        cout << p << endl;
    }
    avl.print();
}

void test_age(){
    AVLFile<int, Persona, decltype(index_edad), decltype(cmp)> avl("personas.dat","edad",index_edad, cmp);
    vector<Persona> res;
    if (!avl){
        avl.create_index();
        cout << "index created" << endl;
    }

    Persona p(77866655, "Alvamau", "Garcia", "CS", 19, 123, 1.80, 70);
    cout << "INSERTANDO UN NUEVO REGISTRO CON EDAD: " << p.edad << endl;
    avl.insert(p);
    avl.print();

    cout << "BUSQUEDA POR EDAD A LA PERSONA CON EDAD 19" << endl;
    res = std::move(avl.search(19));
    for (auto &p : res){
        cout << p << endl;
    }

    cout << "BUSQUEDA POR RANGO DE EDAD ENTRE 20 Y 30" << endl;
    res = std::move(avl.range_search(20, 30));
    for (auto &p : res){
        cout << p << endl;
    }

    vector<Persona> ordenado = std::move(avl.inorder());
    cout << "\nIN ORDER TRAVERSAL USANDO EDAD COMO LLAVE DE ORDENACION" << endl;
    for (auto &p : ordenado){
        cout << p << endl;
    }

    cout << "ELIMINANDO 19, 22, 23, 24, 25 y 27" << endl;
    avl.remove(19);
    avl.remove(22);
    avl.remove(23);
    avl.remove(24);
    avl.remove(25);
    avl.remove(27);

    ordenado = std::move(avl.inorder());
    cout << "\nIN ORDER DESPUES DE LA ELIMINACION" << endl;
    for (auto &p : ordenado){
        cout << p << endl;
    }
    avl.print();

}

int main(){
    function<void ()> f[] = {test_dni, test_age};

    cout << "DNIs" << endl;
    cout << string(50, '-') << endl;
    f[0]();
    cout << endl <<string(50, '-') << endl;
    cout << "Edades" << endl;
    f[1]();
    return EXIT_SUCCESS;
}
