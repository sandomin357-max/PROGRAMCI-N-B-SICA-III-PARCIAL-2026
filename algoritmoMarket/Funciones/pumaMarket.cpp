#include <iostream>
#include <iomanip>
#include <string>
#include <limits>

using namespace std;

const int TOTAL_PRODUCTOS = 10;
const double IMPUESTO = 0.15; // ISV

struct Producto {
	int codigo;
	string nombre;
	string area;
	string unidad;
	double precio;
	int inventario;
};

void mostrarProductos(const Producto productos[], int total, const string &area) {
	cout << "\n========== PRODUCTOS DE " << area << " DISPONIBLES ==========" << endl;
	for (int i = 0; i < total; i++) {
		if (productos[i].area != area)
			continue;
		cout << "Codigo: " << productos[i].codigo << endl;
		cout << "Area: " << productos[i].area << endl;
		cout << "Producto: " << productos[i].nombre << endl;
		cout << "Precio: L. " << fixed << setprecision(2) << productos[i].precio
			 << " por " << productos[i].unidad << endl;
		cout << "Cantidad disponible: " << productos[i].inventario << " "
			 << productos[i].unidad << "(s)" << endl;
		cout << "-------------------------------------------" << endl;
	}
}

double descuentoCliente(const string &tipo, const string &area) {
	if (tipo == "Estrella" && (area == "Carnes" || area == "Verduras"))
		return 0.04;
	if (tipo == "Regular" && area == "Carnes")
		return 0.03;
	if (tipo == "Nuevo" && area == "Licores")
		return 0.02;
	return 0.0;
}

bool ingresarEntero(const string &mensaje, int &valor) {
	cout << mensaje;
	if (cin >> valor)
		return true;
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cout << "Entrada no valida. Intente nuevamente." << endl;
	return false;
}

void registrarCompra(Producto productos[], int cantidades[], int total) {
	int codigo, opcionArea;
	string areaSeleccionada;
	while (true) {
		cout << "\nSeleccione el area que desea comprar:" << endl;
		cout << "1. Verduras" << endl;
		cout << "2. Carnes" << endl;
		cout << "3. Licores" << endl;
		cout << "0. Finalizar compra" << endl;
		if (!ingresarEntero("Opcion: ", opcionArea))
			continue;
		if (opcionArea == 0)
			break;
		if (opcionArea == 1) areaSeleccionada = "Verduras";
		else if (opcionArea == 2) areaSeleccionada = "Carnes";
		else if (opcionArea == 3) areaSeleccionada = "Licores";
		else {
			cout << "Error: seleccione una opcion entre 0 y 3." << endl;
			continue;
		}

		mostrarProductos(productos, total, areaSeleccionada);
		if (!ingresarEntero("Seleccione el codigo del producto del area elegida: ", codigo))
			continue;

		int indice = -1;
		for (int i = 0; i < total; i++) {
			if (productos[i].codigo == codigo && productos[i].area == areaSeleccionada) {
				indice = i;
				break;
			}
		}
		if (indice == -1) {
			cout << "Error: el codigo no corresponde a un producto del area elegida." << endl;
			continue;
		}

		int cantidad;
		if (!ingresarEntero("Cantidad que desea comprar: ", cantidad))
			continue;
		if (cantidad <= 0) {
			cout << "Error: la cantidad debe ser mayor que cero." << endl;
			continue;
		}
		if (cantidad > productos[indice].inventario) {
			cout << "Error: inventario insuficiente. Disponibles: "
				 << productos[indice].inventario << " " << productos[indice].unidad << "(s)." << endl;
			continue;
		}

		cantidades[indice] += cantidad;
		productos[indice].inventario -= cantidad;
		cout << "Producto agregado a la compra." << endl;
	}
}

void mostrarFactura(const Producto productos[], const int cantidades[], int total,
					const string &nombreCliente, const string &tipoCliente,
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
		if (cantidades[i] == 0)
			continue;

		double bruto = productos[i].precio * cantidades[i];
		double descuento = bruto * descuentoCliente(tipoCliente, productos[i].area);

		if (productos[i].area == "Carnes") {
			for (int unidad = 0; unidad < cantidades[i]; unidad++) {
				unidadesCarne++;
				if (unidadesCarne == 2)
					descuentoSegundaCarne = productos[i].precio * 0.50;
			}
		}

		if (productos[i].codigo == 7 || productos[i].codigo == 8)
			descuentoSixPack += (cantidades[i] / 6) * 10.0;

		subtotal += bruto;
		descuentoTotal += descuento;

		cout << "Producto: " << productos[i].nombre << endl;
		cout << "Cantidad: " << cantidades[i] << " " << productos[i].unidad << "(s)" << endl;
		cout << "Precio unitario: L. " << fixed << setprecision(2) << productos[i].precio << endl;
		cout << "Subtotal: L. " << bruto << endl;
		cout << "Descuento de cliente: L. " << descuento << endl;
		cout << "-----------------------------------------" << endl;
	}

	descuentoTotal += descuentoSegundaCarne + descuentoSixPack;
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
	Producto productos[TOTAL_PRODUCTOS] = {
		{1, "Tomate", "Verduras", "libra", 10.0, 100},
		{2, "Repollo", "Verduras", "libra", 15.0, 100},
		{3, "Papas", "Verduras", "libra", 17.0, 100},
		{4, "Carne molida", "Carnes", "libra", 50.0, 100},
		{5, "Carne de cerdo", "Carnes", "libra", 70.0, 100},
		{6, "Carne para asar", "Carnes", "libra", 75.0, 100},
		{7, "Cerveza nacional", "Licores", "unidad", 50.0, 100},
		{8, "Cerveza extranjera", "Licores", "unidad", 80.0, 100},
		{9, "Vino", "Licores", "botella", 200.0, 100},
		{10, "Vodka", "Licores", "botella", 100.0, 100}
	};
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
	while (!ingresarEntero("Opcion: ", opcionTipo) || opcionTipo < 1 || opcionTipo > 3)
		cout << "Seleccione una opcion entre 1 y 3." << endl;

	if (opcionTipo == 1) tipoCliente = "Estrella";
	else if (opcionTipo == 2) tipoCliente = "Regular";
	else tipoCliente = "Nuevo";

	while (!ingresarEntero("Ingrese la edad del cliente: ", edad) || edad < 0)
		cout << "Ingrese una edad valida." << endl;

	registrarCompra(productos, cantidades, TOTAL_PRODUCTOS);
	mostrarFactura(productos, cantidades, TOTAL_PRODUCTOS, nombreCliente, tipoCliente,
				   edad, subtotal, descuento, impuesto, totalPagar);
	cout << "Gracias por su compra, " << nombreCliente << "." << endl;
	return 0;
}
