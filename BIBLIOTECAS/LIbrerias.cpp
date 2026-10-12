#include <iostream> // Biblioteca estándar para entrada y salida
#include <string>   // Biblioteca estándar para manipulación de cadenas de texto
#include <cmath>     // Biblioteca estándar para trabajar con funciones matemáticas  
#include <iomanip>  // Biblioteca estándar para manipulación de la salida formateada

using namespace std;

int main()
{

    int edad;
    string nombre;

    cout << "Ingrese su edad: ";            // Solicita al usuario que ingrese su edad
    cin >> edad;                            // Lee la edad ingresada por el usuario
    cout << "Su edad es: " << edad << endl; // Muestra la edad ingresada


cout << "Ingrese su nombre: ";          // Solicita al usuario que ingrese su nombre
getline(cin >> ws, nombre); // Lee el nombre ingresado por el usuario, incluyendo espacios



cout << "Su nombre es: " << nombre << endl; // Muestra el nombre ingresado

//ejemplo de la libreria math para redondear un número
double numero = 3.7;        

cout << "Numero original: " << numero << endl; // Muestra el número original
cout << "Numero redondeado: " << round(numero) << endl; // Muestra el número redondeado utilizando la función round de la biblioteca math


//ejemplo de la libreria iomanip para formatear la salida
double pi = 3.14159265358979323846; // Valor de pi  

// Muestra el valor de pi con 2 decimales utilizando la función setprecision de la biblioteca iomanip
cout << "Valor de pi con 2 decimales: " << fixed << setprecision    (2) << pi << endl;  



    return 0;
}