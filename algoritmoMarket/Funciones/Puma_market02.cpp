#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

const int TOTAL_PRODUCTOS = 10;
const double IMPUESTO = 0.15; // ISV

// Muestra los productos de un area (el codigo de cada producto es su posicion + 1)
void mostrarProductos(string nombre[], string area[], string unidad[], double precio[],
                      int inventario[], int total, string areaElegida) {
    cout << "\n========== PRODUCTOS DE " << areaElegida << " DISPONIBLES ==========" << endl;
    for (int i = 0; i < total; i++) {
        if (area[i] == areaElegida) {
            cout << "Codigo: " << i + 1 << endl;
            cout << "Area: " << area[i] << endl;
            cout << "Producto: " << nombre[i] << endl;
            cout << "Precio: L. " << precio[i] << " por " << unidad[i] << endl;
            cout << "Cantidad disponible: " << inventario[i] << " " << unidad[i] << "(s)" << endl;
            cout << "-------------------------------------------" << endl;
        }
    }
}

// Devuelve el porcentaje de descuento segun tipo de cliente y area
double descuentoCliente(string tipo, string area) {
    if (tipo == "Estrella" && (area == "Carnes" || area == "Verduras")) {
        return 0.04;
    }
    if (tipo == "Regular" && area == "Carnes") {
        return 0.03;
    }
    if (tipo == "Nuevo" && area == "Licores") {
        return 0.02;
    }
    return 0.0;
}

// Pide un numero entero. Devuelve true si es valido y false si no.
// "valor" es por referencia: aqui se guarda lo que escribe el usuario.
bool ingresarEntero(string mensaje, int &valor) {
    cout << mensaje;
    if (cin >> valor) {
        return true;
    }
    cin.clear();
    cin.ignore(1000, '\n');
    cout << "Entrada no valida. Intente nuevamente." << endl;
    return false;
}

// Agrega un producto de un area a la compra del cliente
void agregarProducto(string nombre[], string area[], string unidad[], double precio[],
                     int inventario[], int cantidades[], int total, string areaElegida) {
    int codigo;
    int cantidad;

    mostrarProductos(nombre, area, unidad, precio, inventario, total, areaElegida);
    if (ingresarEntero("Seleccione el codigo del producto del area elegida: ", codigo) == false) {
        return;
    }

    // Buscar la posicion del producto
    int indice = -1;
    for (int i = 0; i < total; i++) {
        if (i + 1 == codigo && area[i] == areaElegida) {
            indice = i;
        }
    }
    if (indice == -1) {
        cout << "Error: el codigo no corresponde a un producto del area elegida." << endl;
        return;
    }

    if (ingresarEntero("Cantidad que desea comprar: ", cantidad) == false) {
        return;
    }
    if (cantidad <= 0) {
        cout << "Error: la cantidad debe ser mayor que cero." << endl;
        return;
    }
    if (cantidad > inventario[indice]) {
        cout << "Error: inventario insuficiente. Disponibles: "
             << inventario[indice] << " " << unidad[indice] << "(s)." << endl;
        return;
    }

    cantidades[indice] = cantidades[indice] + cantidad;
    inventario[indice] = inventario[indice] - cantidad;
    cout << "Producto agregado a la compra." << endl;
}

// Menu de areas: se repite hasta que el cliente elija 0
void registrarCompra(string nombre[], string area[], string unidad[], double precio[],
                     int inventario[], int cantidades[], int total) {
    int opcionArea = -1;

    while (opcionArea != 0) {
        cout << "\nSeleccione el area que desea comprar:" << endl;
        cout << "1. Verduras" << endl;
        cout << "2. Carnes" << endl;
        cout << "3. Licores" << endl;
        cout << "0. Finalizar compra" << endl;

        if (ingresarEntero("Opcion: ", opcionArea) == false) {
            opcionArea = -1; // entrada invalida: se vuelve a mostrar el menu
        } else if (opcionArea == 1) {
            agregarProducto(nombre, area, unidad, precio, inventario, cantidades, total, "Verduras");
        } else if (opcionArea == 2) {
            agregarProducto(nombre, area, unidad, precio, inventario, cantidades, total, "Carnes");
        } else if (opcionArea == 3) {
            agregarProducto(nombre, area, unidad, precio, inventario, cantidades, total, "Licores");
        } else if (opcionArea != 0) {
            cout << "Error: seleccione una opcion entre 0 y 3." << endl;
        }
    }
}

// Calcula y muestra la factura.
// subtotal, descuentoTotal, impuesto y totalPagar son por referencia: se devuelven a main.
void mostrarFactura(string nombre[], string area[], string unidad[], double precio[],
                    int cantidades[], int total, string nombreCliente, string tipoCliente,
                    int edad, double &subtotal, double &descuentoTotal,
                    double &impuesto, double &totalPagar) {
    subtotal = 0.0;
    descuentoTotal = 0.0;
    int unidadesCarne = 0;
    double descuentoSegundaCarne = 0.0;
    double descuentoSixPack = 0.0;

    cout << "\n================ FACTURA ================" << endl;
    cout << "Cliente: " << nombreCliente << endl;
    cout << "Tipo de cliente: " << tipoCliente << endl;
    cout << "Edad: " << edad << " anos" << endl;
    cout << "-----------------------------------------" << endl;

    for (int i = 0; i < total; i++) {
        if (cantidades[i] > 0) {
            double bruto = precio[i] * cantidades[i];
            double descuento = bruto * descuentoCliente(tipoCliente, area[i]);

            // Segunda unidad de carne: 50% de descuento (solo una vez en toda la compra)
            if (area[i] == "Carnes") {
                for (int u = 0; u < cantidades[i]; u++) {
                    unidadesCarne++;
                    if (unidadesCarne == 2) {
                        descuentoSegundaCarne = precio[i] * 0.50;
                    }
                }
            }

            // Six-pack: cervezas (codigos 7 y 8), L. 10 por cada 6 unidades
            if (i == 6 || i == 7) {
                descuentoSixPack = descuentoSixPack + (cantidades[i] / 6) * 10.0;
            }

            subtotal = subtotal + bruto;
            descuentoTotal = descuentoTotal + descuento;

            cout << "Producto: " << nombre[i] << endl;
            cout << "Cantidad: " << cantidades[i] << " " << unidad[i] << "(s)" << endl;
            cout << "Precio unitario: L. " << precio[i] << endl;
            cout << "Subtotal: L. " << bruto << endl;
            cout << "Descuento de cliente: L. " << descuento << endl;
            cout << "-----------------------------------------" << endl;
        }
    }

    descuentoTotal = descuentoTotal + descuentoSegundaCarne + descuentoSixPack;
    double subtotalConDescuento = subtotal - descuentoTotal;
    impuesto = subtotalConDescuento * IMPUESTO;
    totalPagar = subtotalConDescuento + impuesto;

    cout << "Subtotal de compra: L. " << subtotal << endl;
    cout << "Descuento por segunda unidad de carne: L. " << descuentoSegundaCarne << endl;
    cout << "Descuento por six-pack: L. " << descuentoSixPack << endl;
    cout << "Descuento total: L. " << descuentoTotal << endl;
    cout << "Subtotal con descuentos: L. " << subtotalConDescuento << endl;
    cout << "ISV (15%): L. " << impuesto << endl;
    cout << "TOTAL A PAGAR: L. " << totalPagar << endl;
    cout << "=========================================\n";
}

int main() {
    // Mostrar siempre 2 decimales
    cout << fixed << setprecision(2);

    // Datos de los productos: cada posicion de los arreglos es un producto
    // (el codigo del producto es la posicion + 1)
    string nombre[TOTAL_PRODUCTOS] = {"Tomate", "Repollo", "Papas",
                                      "Carne molida", "Carne de cerdo", "Carne para asar",
                                      "Cerveza nacional", "Cerveza extranjera", "Vino", "Vodka"};
    string area[TOTAL_PRODUCTOS] = {"Verduras", "Verduras", "Verduras",
                                    "Carnes", "Carnes", "Carnes",
                                    "Licores", "Licores", "Licores", "Licores"};
    string unidad[TOTAL_PRODUCTOS] = {"libra", "libra", "libra",
                                      "libra", "libra", "libra",
                                      "unidad", "unidad", "botella", "botella"};
    double precio[TOTAL_PRODUCTOS] = {10.0, 15.0, 17.0, 50.0, 70.0, 75.0, 50.0, 80.0, 200.0, 100.0};
    int inventario[TOTAL_PRODUCTOS] = {100, 100, 100, 100, 100, 100, 100, 100, 100, 100};
    int cantidades[TOTAL_PRODUCTOS] = {0};

    string nombreCliente, tipoCliente;
    int opcionTipo, edad;
    double subtotal, descuento, impuesto, totalPagar;

    cout << "========== SUPERMERCADO PUMA MARKET ==========" << endl;
    cout << "Ingrese el nombre del cliente: ";
    getline(cin, nombreCliente);
    while (nombreCliente.empty()) {
        cout << "El nombre no puede quedar vacio. Ingrese el nombre: ";
        getline(cin, nombreCliente);
    }

    cout << "\nSeleccione el tipo de cliente:" << endl;
    cout << "1. Estrella" << endl;
    cout << "2. Regular" << endl;
    cout << "3. Nuevo" << endl;
    while (ingresarEntero("Opcion: ", opcionTipo) == false || opcionTipo < 1 || opcionTipo > 3) {
        cout << "Seleccione una opcion entre 1 y 3." << endl;
    }

    if (opcionTipo == 1) {
        tipoCliente = "Estrella";
    } else if (opcionTipo == 2) {
        tipoCliente = "Regular";
    } else {
        tipoCliente = "Nuevo";
    }

    while (ingresarEntero("Ingrese la edad del cliente: ", edad) == false || edad < 0) {
        cout << "Ingrese una edad valida." << endl;
    }

    registrarCompra(nombre, area, unidad, precio, inventario, cantidades, TOTAL_PRODUCTOS);
    mostrarFactura(nombre, area, unidad, precio, cantidades, TOTAL_PRODUCTOS,
                   nombreCliente, tipoCliente, edad,
                   subtotal, descuento, impuesto, totalPagar);
    cout << "Gracias por su compra, " << nombreCliente << "." << endl;
    return 0;
}