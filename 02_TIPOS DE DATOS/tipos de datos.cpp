#include <iostream>
#include <string>
using namespace std;

int main()
{
    // Tipos de datos primitivos
    int edadEstudiante = 23;                    // Entero
    float alturaEstudiante = 1.74;              // Flotante
    double recorridoEstudiante = 3.14159;       // Doble precisión
    char sexoEstudiante = 'F';                  // Carácter
    bool estudianteActivo = true;               // Booleano
    short int numeroCorto = 32767;              // Entero corto
    long int numeroLargo = 9223372036854775807; // Entero largo
    long long int numeroMuyLargo = 20101000245; // Entero muy largo
    signed int numeroPositivo = 4294967295;     // Entero sin signo
    unsigned int numeroNegativo = -1;           // Entero con signo
    string nombreEstudiante = "Juan Perez";     // Cadena de caracteres

    // Mostrar los valores en consola
    cout << "Edad del estudiante: " << edadEstudiante << endl;
    cout << "Altura del estudiante: " << alturaEstudiante << endl;
    cout << "Recorrido del estudiante: " << recorridoEstudiante << endl;
    cout << "Sexo del estudiante: " << sexoEstudiante << endl;
    cout << "Estudiante activo: " << estudianteActivo << endl;
    cout << "Número corto: " << numeroCorto << endl;
    cout << "Numero largo: " << numeroLargo << endl;
    cout << "Numero muy largo: " << numeroMuyLargo << endl;
    cout << "Nombre del estudiante: " << nombreEstudiante << endl;

    return 0;
