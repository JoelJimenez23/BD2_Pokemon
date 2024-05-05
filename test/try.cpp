#include <iostream>
#include <filesystem>
#include <string>
using namespace std;
namespace fs = std::filesystem;

string getFileName(const string& directoryPath) {
    // Verifica si el directorio existe
    if (!fs::exists(directoryPath) || !fs::is_directory(directoryPath)) {
        throw invalid_argument("El directorio no existe o no es válido.");
    }

    // Itera sobre los archivos en el directorio
    for (const auto& entry : fs::directory_iterator(directoryPath)) {
        if (fs::is_regular_file(entry)) {
            return entry.path().filename().string();
        }
    }

    // Si no se encontró ningún archivo
    throw runtime_error("No se encontraron archivos en el directorio.");
}

int main() {
    try {
        string directoryPath = "/home/joel/Programacion/bd2/bplus/test/AppleStore.csv";
        string fileName = getFileName(directoryPath);
        cout << "Nombre del archivo: " << fileName << endl;
    } catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }
    return 0;
}
