#include <iostream>
#include <string>
using namespace std;
int main()
{
 int edad;
 string nombre;
 cout << "Ingrese su edad: ";
 cin >> edad;
 cout << "Ingrese su nombre: ";
 getline(cin >> ws, nombre);
 cout << "Hola " << nombre << endl;
 cout << "Tu edad es: " << edad << endl;
 return 0;
}