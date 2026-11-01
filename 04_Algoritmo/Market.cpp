#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main() {
    // Configurar formato para mostrar dos decimales en moneda
    cout << fixed << setprecision(2);

    // ==========================================
    // 1. DATOS DE ENTRADA Y VALIDACIONES CLIENTE
    // ==========================================
    string nombreCliente;
    char sexoCliente;
    int edadCliente;
    int tipoCliente;

    cout << "Ingrese su nombre: ";
    getline(cin >> ws, nombreCliente);

    cout << "Ingrese su sexo (M/F): ";
    cin >> sexoCliente;
    if (sexoCliente != 'M' && sexoCliente != 'm' && sexoCliente != 'F' && sexoCliente != 'f') {
        cout << "Sexo de cliente incorrecto" << endl;
        return 0;
    }

    cout << "Ingrese su edad: ";
    cin >> edadCliente;
    if (edadCliente < 15 || edadCliente > 100) {
        cout << "Edad fuera de rango" << endl;
        return 0;
    }

    cout << "Diferentes tipos de clientes:\n";
    cout << "1. Cliente estrella\n2. Cliente Regular\n3. Cliente nuevo\n";
    cout << "Seleccione tipo de cliente (1-3): ";
    cin >> tipoCliente;
    if (tipoCliente < 1 || tipoCliente > 3) {
        cout << "Tipo de cliente incorrecto" << endl;
        return 0;
    }

    // ==========================================
    // 2. MODULO 1: SELECCION DE PRODUCTO
    // ==========================================
    int opcionMenu;
    int opcionVerduras, opcionCarnes, opcionLicores;

    // ---- VERDURAS ----
    // Tomates
    double precioTomate = 10.00;
    int librasTotalesTomates = 100;
    double cantidadTomates = 0, librasTomatesCliente = 0;
    double subtotalTomates = 0, subtotalGeneralTomates = 0, totalLibrasVendidasTomates = 0;

    // Repollo
    double precioRepollo = 12.00;
    int librasTotalesRepollo = 80;
    double cantidadRepollo = 0, librasRepolloCliente = 0;
    double subtotalRepollo = 0, subtotalGeneralRepollo = 0, totalLibrasVendidasRepollo = 0;

    // Papas
    double precioPapas = 8.00;
    int librasTotalesPapas = 120;
    double cantidadPapas = 0, librasPapasCliente = 0;
    double subtotalPapas = 0, subtotalGeneralPapas = 0, totalLibrasVendidasPapas = 0;

    // ---- CARNES ----
    // Res
    double precioRes = 75.00;
    int librasTotalesRes = 150;
    double cantidadRes = 0, librasResCliente = 0;
    double subtotalRes = 0, subtotalGeneralRes = 0, totalLibrasVendidasRes = 0;

    // Pollo
    double precioPollo = 45.00;
    int librasTotalesPollo = 100;
    double cantidadPollo = 0, librasPolloCliente = 0;
    double subtotalPollo = 0, subtotalGeneralPollo = 0, totalLibrasVendidasPollo = 0;

    // Cerdo
    double precioCerdo = 60.00;
    int librasTotalesCerdo = 90;
    double cantidadCerdo = 0, librasCerdoCliente = 0;
    double subtotalCerdo = 0, subtotalGeneralCerdo = 0, totalLibrasVendidasCerdo = 0;

    // ---- LICORES ----
    // Cerveza
    double precioCerveza = 35.00;
    int unidadesTotalesCerveza = 200;
    int cantidadCerveza = 0, unidadesCervezaCliente = 0;
    double subtotalCerveza = 0, subtotalGeneralCerveza = 0;
    int totalUnidadesVendidasCerveza = 0;

    // Ron
    double precioRon = 150.00;
    int unidadesTotalesRon = 60;
    int cantidadRon = 0, unidadesRonCliente = 0;
    double subtotalRon = 0, subtotalGeneralRon = 0;
    int totalUnidadesVendidasRon = 0;

    // Aguardiente
    double precioAguardiente = 120.00;
    int unidadesTotalesAguardiente = 50;
    int cantidadAguardiente = 0, unidadesAguardienteCliente = 0;
    double subtotalAguardiente = 0, subtotalGeneralAguardiente = 0;
    int totalUnidadesVendidasAguardiente = 0;

    cout << "\n--- MODULO 1: SELECCION PRODUCTO ---\n";
    cout << "Menu Principal:\n1. Verduras\n2. Carnes\n3. Licores\n";
    cout << "Seleccione opcion de menu (1-3): ";
    cin >> opcionMenu;

    switch (opcionMenu) {
        case 1:
            cout << "\n--- CASE 1: VERDURAS ---\n";
            cout << "1. Tomates\n2. Repollo\n3. Papas\n";
            cout << "Seleccione opcion para verduras: ";
            cin >> opcionVerduras;

            if (opcionVerduras == 1) {
                cout << "Ingrese cantidad de libras de Tomates: ";
                cin >> cantidadTomates;
                if (cantidadTomates > librasTotalesTomates) {
                    cout << "Cantidad supera el stock" << endl;
                } else {
                    librasTomatesCliente = librasTomatesCliente + cantidadTomates;
                    subtotalTomates = precioTomate * librasTomatesCliente;
                    subtotalGeneralTomates = subtotalGeneralTomates + subtotalTomates;
                    totalLibrasVendidasTomates = totalLibrasVendidasTomates + librasTomatesCliente;
                    cout << "Total libras Tomate: " << librasTomatesCliente << endl;
                }
            } else if (opcionVerduras == 2) {
                cout << "Ingrese cantidad de libras de Repollo: ";
                cin >> cantidadRepollo;
                if (cantidadRepollo > librasTotalesRepollo) {
                    cout << "Cantidad supera el stock" << endl;
                } else {
                    librasRepolloCliente = librasRepolloCliente + cantidadRepollo;
                    subtotalRepollo = precioRepollo * librasRepolloCliente;
                    subtotalGeneralRepollo = subtotalGeneralRepollo + subtotalRepollo;
                    totalLibrasVendidasRepollo = totalLibrasVendidasRepollo + librasRepolloCliente;
                    cout << "Total libras Repollo: " << librasRepolloCliente << endl;
                }
            } else if (opcionVerduras == 3) {
                cout << "Ingrese cantidad de libras de Papas: ";
                cin >> cantidadPapas;
                if (cantidadPapas > librasTotalesPapas) {
                    cout << "Cantidad supera el stock" << endl;
                } else {
                    librasPapasCliente = librasPapasCliente + cantidadPapas;
                    subtotalPapas = precioPapas * librasPapasCliente;
                    subtotalGeneralPapas = subtotalGeneralPapas + subtotalPapas;
                    totalLibrasVendidasPapas = totalLibrasVendidasPapas + librasPapasCliente;
                    cout << "Total libras Papas: " << librasPapasCliente << endl;
                }
            } else {
                cout << "Opcion para verduras incorrecta" << endl;
            }
            break;

        case 2:
            cout << "\n--- CASE 2: CARNES ---\n";
            cout << "1. Res\n2. Pollo\n3. Cerdo\n";
            cout << "Seleccione opcion para carnes: ";
            cin >> opcionCarnes;

            if (opcionCarnes == 1) {
                cout << "Ingrese cantidad de libras de Res: ";
                cin >> cantidadRes;
                if (cantidadRes > librasTotalesRes) {
                    cout << "Cantidad supera el stock" << endl;
                } else {
                    librasResCliente = librasResCliente + cantidadRes;
                    subtotalRes = precioRes * librasResCliente;
                    subtotalGeneralRes = subtotalGeneralRes + subtotalRes;
                    totalLibrasVendidasRes = totalLibrasVendidasRes + librasResCliente;
                    cout << "Total libras Res: " << librasResCliente << endl;
                }
            } else if (opcionCarnes == 2) {
                cout << "Ingrese cantidad de libras de Pollo: ";
                cin >> cantidadPollo;
                if (cantidadPollo > librasTotalesPollo) {
                    cout << "Cantidad supera el stock" << endl;
                } else {
                    librasPolloCliente = librasPolloCliente + cantidadPollo;
                    subtotalPollo = precioPollo * librasPolloCliente;
                    subtotalGeneralPollo = subtotalGeneralPollo + subtotalPollo;
                    totalLibrasVendidasPollo = totalLibrasVendidasPollo + librasPolloCliente;
                    cout << "Total libras Pollo: " << librasPolloCliente << endl;
                }
            } else if (opcionCarnes == 3) {
                cout << "Ingrese cantidad de libras de Cerdo: ";
                cin >> cantidadCerdo;
                if (cantidadCerdo > librasTotalesCerdo) {
                    cout << "Cantidad supera el stock" << endl;
                } else {
                    librasCerdoCliente = librasCerdoCliente + cantidadCerdo;
                    subtotalCerdo = precioCerdo * librasCerdoCliente;
                    subtotalGeneralCerdo = subtotalGeneralCerdo + subtotalCerdo;
                    totalLibrasVendidasCerdo = totalLibrasVendidasCerdo + librasCerdoCliente;
                    cout << "Total libras Cerdo: " << librasCerdoCliente << endl;
                }
            } else {
                cout << "Opcion para carnes incorrecta" << endl;
            }
            break;

        case 3:
            cout << "\n--- CASE 3: LICORES ---\n";
            cout << "1. Cerveza\n2. Ron\n3. Aguardiente\n";
            cout << "Seleccione opcion para licores: ";
            cin >> opcionLicores;

            if (opcionLicores == 1) {
                cout << "Ingrese cantidad de unidades de Cerveza: ";
                cin >> cantidadCerveza;
                if (cantidadCerveza > unidadesTotalesCerveza) {
                    cout << "Cantidad supera el stock" << endl;
                } else {
                    unidadesCervezaCliente = unidadesCervezaCliente + cantidadCerveza;
                    subtotalCerveza = precioCerveza * unidadesCervezaCliente;
                    subtotalGeneralCerveza = subtotalGeneralCerveza + subtotalCerveza;
                    totalUnidadesVendidasCerveza = totalUnidadesVendidasCerveza + unidadesCervezaCliente;
                    cout << "Total unidades Cerveza: " << unidadesCervezaCliente << endl;
                }
            } else if (opcionLicores == 2) {
                cout << "Ingrese cantidad de unidades de Ron: ";
                cin >> cantidadRon;
                if (cantidadRon > unidadesTotalesRon) {
                    cout << "Cantidad supera el stock" << endl;
                } else {
                    unidadesRonCliente = unidadesRonCliente + cantidadRon;
                    subtotalRon = precioRon * unidadesRonCliente;
                    subtotalGeneralRon = subtotalGeneralRon + subtotalRon;
                    totalUnidadesVendidasRon = totalUnidadesVendidasRon + unidadesRonCliente;
                    cout << "Total unidades Ron: " << unidadesRonCliente << endl;
                }
            } else if (opcionLicores == 3) {
                cout << "Ingrese cantidad de unidades de Aguardiente: ";
                cin >> cantidadAguardiente;
                if (cantidadAguardiente > unidadesTotalesAguardiente) {
                    cout << "Cantidad supera el stock" << endl;
                } else {
                    unidadesAguardienteCliente = unidadesAguardienteCliente + cantidadAguardiente;
                    subtotalAguardiente = precioAguardiente * unidadesAguardienteCliente;
                    subtotalGeneralAguardiente = subtotalGeneralAguardiente + subtotalAguardiente;
                    totalUnidadesVendidasAguardiente = totalUnidadesVendidasAguardiente + unidadesAguardienteCliente;
                    cout << "Total unidades Aguardiente: " << unidadesAguardienteCliente << endl;
                }
            } else {
                cout << "Opcion para licores incorrecta" << endl;
            }
            break;

        default:
            cout << "Opcion de menu incorrecta" << endl;
            return 0;
    }

    // ==========================================
    // 3. CALCULO DE SUBTOTALES Y DESCUENTOS
    // ==========================================
    double subtotalCliente = subtotalTomates + subtotalRepollo + subtotalPapas
                           + subtotalRes + subtotalPollo + subtotalCerdo
                           + subtotalCerveza + subtotalRon + subtotalAguardiente;

    double descuentoClienteEstrella = 0;
    double descuentoClienteRegular = 0;
    double descuentoClienteNuevo = 0;

    if (tipoCliente == 1) {
        descuentoClienteEstrella = subtotalCliente * 0.04;
        cout << "\nDescuento Cliente Estrella (4%): Lps. " << descuentoClienteEstrella << endl;
    } else if (tipoCliente == 2) {
        descuentoClienteRegular = subtotalCliente * 0.02;
        cout << "\nDescuento Cliente Regular (2%): Lps. " << descuentoClienteRegular << endl;
    } else if (tipoCliente == 3) {
        descuentoClienteNuevo = 0;
        cout << "\nDescuento Cliente Nuevo (0%): Lps. " << descuentoClienteNuevo << endl;
    }

    double descuentoTotal = descuentoClienteEstrella + descuentoClienteRegular + descuentoClienteNuevo;
    double subtotalConDescuento = subtotalCliente - descuentoTotal;
    double impuestoISV = subtotalConDescuento * 0.15;
    double totalPagarCliente = subtotalConDescuento + impuestoISV;

    cout << "Total descuento aplicado: Lps. " << descuentoTotal << endl;
    cout << "Subtotal Neto: Lps. " << subtotalConDescuento << endl;
    cout << "Impuesto sobre Venta (15%): Lps. " << impuestoISV << endl;
    cout << "Monto Total a Pagar por Cliente: Lps. " << totalPagarCliente << endl;

    // ==========================================
    // 4. MODULO 2: RESUMEN GENERAL Y TOTALES DE VENTA
    // ==========================================
    double totalVentasGeneral = 0;
    double totalRecaudadoISV = 0;

    totalVentasGeneral = totalVentasGeneral + totalPagarCliente;
    totalRecaudadoISV = totalRecaudadoISV + impuestoISV;

    cout << "\n===============================" << endl;
    cout << "  MODULO 2: RESUMEN GENERAL" << endl;
    cout << "===============================" << endl;
    cout << "Cliente: " << nombreCliente << endl;
    cout << "Reporte de Ventas Totales: Lps. " << totalVentasGeneral << endl;
    cout << "Reporte Total Impuestos Recaudados: Lps. " << totalRecaudadoISV << endl;

    cout << "\n--- Consolidado de ventas por tipo de producto ---" << endl;
    cout << "Tomates: " << totalLibrasVendidasTomates << " libras | Subtotal general: Lps. " << subtotalGeneralTomates << endl;
    cout << "Repollo: " << totalLibrasVendidasRepollo << " libras | Subtotal general: Lps. " << subtotalGeneralRepollo << endl;
    cout << "Papas: " << totalLibrasVendidasPapas << " libras | Subtotal general: Lps. " << subtotalGeneralPapas << endl;
    cout << "Res: " << totalLibrasVendidasRes << " libras | Subtotal general: Lps. " << subtotalGeneralRes << endl;
    cout << "Pollo: " << totalLibrasVendidasPollo << " libras | Subtotal general: Lps. " << subtotalGeneralPollo << endl;
    cout << "Cerdo: " << totalLibrasVendidasCerdo << " libras | Subtotal general: Lps. " << subtotalGeneralCerdo << endl;
    cout << "Cerveza: " << totalUnidadesVendidasCerveza << " unidades | Subtotal general: Lps. " << subtotalGeneralCerveza << endl;
    cout << "Ron: " << totalUnidadesVendidasRon << " unidades | Subtotal general: Lps. " << subtotalGeneralRon << endl;
    cout << "Aguardiente: " << totalUnidadesVendidasAguardiente << " unidades | Subtotal general: Lps. " << subtotalGeneralAguardiente << endl;

    cout << "\n--- Reporte de Inventario Final ---" << endl;
    cout << "Tomates: " << librasTotalesTomates - totalLibrasVendidasTomates << " libras" << endl;
    cout << "Repollo: " << librasTotalesRepollo - totalLibrasVendidasRepollo << " libras" << endl;
    cout << "Papas: " << librasTotalesPapas - totalLibrasVendidasPapas << " libras" << endl;
    cout << "Res: " << librasTotalesRes - totalLibrasVendidasRes << " libras" << endl;
    cout << "Pollo: " << librasTotalesPollo - totalLibrasVendidasPollo << " libras" << endl;
    cout << "Cerdo: " << librasTotalesCerdo - totalLibrasVendidasCerdo << " libras" << endl;
    cout << "Cerveza: " << unidadesTotalesCerveza - totalUnidadesVendidasCerveza << " unidades" << endl;
    cout << "Ron: " << unidadesTotalesRon - totalUnidadesVendidasRon << " unidades" << endl;
    cout << "Aguardiente: " << unidadesTotalesAguardiente - totalUnidadesVendidasAguardiente << " unidades" << endl;
    cout << "===============================" << endl;

    return 0;
}