#include "menus.h"



//MENUS ADMIN
int mainMenuAdmin()
{



    int opcion;

    do
    {
        // Menú principal
        printf("Seleccione una opción:\n");
        printf("1. DEPOSITO GENERAL\n");
        printf("2. DEPOSITO POR SUCURSAL\n");
        printf("3. VENTAS\n");
        printf("4. COMPRA DE PROVEDORES\n");
        printf("5. Salir\n");

        scanf("\n%d", &opcion);

        switch (opcion)
        {
        case 1:
            menuOpcionDepositoAdmin();

            break;
        case 2:
            menuOpcionDepositoSucursalAdmin();

            break;
        case 3:
            menuOpcionVentasAdmin();
            break;
        case 4:
            menuOpcionProveedoresAdmin();
            break;
        case 5:
            printf("Saliendo del programa. ¡Hasta luego!\n");
            system("pause");
            break;
        default:
            printf("Opción no válida. Inténtelo de nuevo.\n");
            system("cls");
        }
    }
    while (opcion != 5);

    return 0;
}



int menuOpcionDepositoAdmin()
{
    int selected;
    catalogo arreglo[40];

    int validos = 0, buscar = 0, pos = 0;
    int idDeProdu=0;
    nodoProductos *buscado;

    do
    {

        selected = menuDepositoAdmin();

        switch (selected)
        {
        case 1:
            //barra();
            muestraArchivo(ARCHIVO_DEPOSITO);
            system("pause");
            break;

        case 2:
            printf("\nARCHIVO:\n");

            cargaArchivo(ARCHIVO_DEPOSITO);
            muestraArchivo(ARCHIVO_DEPOSITO);
            system("pause");
            break;

        case 3:
            validos = pasardeArchivoAArreglo(ARCHIVO_DEPOSITO, arreglo, 40);
            muestraDeCatalogo(arreglo, validos);
            system("pause");

            break;
        case 4:
            validos = pasardeArchivoAArreglo(ARCHIVO_DEPOSITO, arreglo, 40);
            muestraDeCatalogo(arreglo, validos);

            printf("\ningrese el id del catalogo que desea desactivar\n");
            scanf("%d", &buscar);
            pos = buscaEnCatalogoPorId(arreglo, validos, buscar);

            if (pos !=-1 )
            {
                desactivarCatalogo(ARCHIVO_DEPOSITO,arreglo, buscar, pos);
                validos = pasardeArchivoAArreglo(ARCHIVO_DEPOSITO, arreglo, 40);
                muestraDeCatalogo(arreglo, validos);

            }
            else
            {
                printf("\nno se encontro catalogo\n");
            }

            system("pause");

            break;
        case 5 :



            validos = pasardeArchivoAArreglo(ARCHIVO_DEPOSITO, arreglo, 40);
            muestraDeCatalogo(arreglo, validos);

            printf("\ningrese el id del catalogo del producto a dersactivar\n");
            scanf("%d", &buscar);
            printf("\nINGRESE EL ID DEL PRODUCTO A DAR DE BAJA");
            scanf("%d",&idDeProdu);

            pos = buscaEnCatalogoPorId(arreglo, validos, buscar);
            buscado=buscaEnListaId(arreglo,pos,idDeProdu);


            if (pos !=-1 )
            {
                if(buscado!=NULL)
                {
                    desactivarProducto(ARCHIVO_DEPOSITO,arreglo, pos,buscado);
                }
                else
                {
                    printf("\nno se encontro producto\n");
                }


            }
            else
            {
                printf("\nno se encontro catalogo\n");
            }

            system("pause");

            break;
        case 6:
            validos = pasardeArchivoAArreglo(ARCHIVO_DEPOSITO, arreglo, 40);
            muestraDeCatalogoTodos(arreglo, validos);

            printf("\ningrese el id del catalogo del producto a activar\n");
            scanf("%d", &buscar);
            printf("\nINGRESE EL ID DEL PRODUCTO A  activar");
            scanf("%d",&idDeProdu);

            pos = buscaEnCatalogoPorId(arreglo, validos, buscar);
            buscado=buscaEnListaId(arreglo,pos,idDeProdu);

            activarProducto(ARCHIVO_DEPOSITO,arreglo,pos,buscado);
            system("pause");
            break;

        case 7:
            validos = pasardeArchivoAArreglo(ARCHIVO_DEPOSITO, arreglo, 40);
            muestraDeCatalogoTodos(arreglo, validos);

            printf("\ningrese el id del catalogo que desea activar\n");
            scanf("%d", &buscar);
            pos = buscaEnCatalogoPorId(arreglo, validos, buscar);

            if (pos !=-1 )
            {
                activarCatalogo(ARCHIVO_DEPOSITO,arreglo, buscar, pos);



            }
            else
            {
                printf("\nno se encontro catalogo\n");
            }

            system("pause");
            break;


        case 0:


            printf("\n\nTERMINATE THE PROGRAM\n");
            break;
        }

    }
    while (selected != 0);

    system("pause");
    system("cls");
    return 0;
}
int menuDepositoAdmin()
{

    int input;
    system("cls");


    printf("\n\n\n");
    printf("\t\t\t|-------------------------------------------------------------------------------------------------------------------------------------------------\n");
    printf("\t\t\t|#####    #######  ######    #####    #####    ####    ######    #####              ####   #######  ##   ##  #######  ######     ##     ####     |\n");
    printf("\t\t\t|## ##    ##   #   ##  ##  ##   ##  ##   ##    ##     # ## #   ##   ##            ##  ##   ##   #  ###  ##   ##   #   ##  ##   ####     ##       |\n");
    printf("\t\t\t|##  ##   ## #     ##  ##  ##   ##  #          ##       ##     ##   ##           ##        ## #    #### ##   ## #     ##  ##  ##  ##    ##       |\n");
    printf("\t\t\t||##  ##   ####     #####   ##   ##   #####     ##       ##     ##   ##           ##        ####    ## ####   ####     #####   ##  ##    ##      |\n");
    printf("\t\t\t||##  ##   ## #     ##      ##   ##       ##    ##       ##     ##   ##           ##  ###   ## #    ##  ###   ## #     ## ##   ######    ##   #  |\n");
    printf("\t\t\t| ## ##    ##   #   ##      ##   ##  ##   ##    ##       ##     ##   ##            ##  ##   ##   #  ##   ##   ##   #   ##  ##  ##  ##    ##  ##  |\n");
    printf("\t\t\t|#####    #######  ####      #####    #####    ####     ####     #####              #####  #######  ##   ##  #######  #### ##  ##  ##   #######  |\n");
    printf("\t\t\t|                                                    1MUESTRA DEL ARCHIVO DEPOSTIO                                                               |\n");
    printf("\t\t\t|                                                    2-CARGA DEL ARCHIVO DEPOSITO                                                                |\n");
    printf("\t\t\t|                                                    3-MOSTRAR ARREGLO DE LISTAS DEPOSITO                                                        |\n");
    printf("\t\t\t|                                                    4-DAR DE BAJA CATEGORIA del DEPOSITO                                                        |\n");
    printf("\t\t\t|                                                    5-DAR DE BAJA PRODUCTO DEL DEPOSITO                                                         |\n");
    printf("\t\t\t|                                                    6-DAR DE ALTA PRODUCTO                                                                      |\n");
    printf("\t\t\t|                                                    7-DAR DE ALTA CATALOGO                                                                      |\n");
    printf("\t\t\t|-----------------------------------------------------------------------------------------------------------------------------------------------|\n");

           printf("\n\n\t\t\t\t\t\t\t\t\tENTER YOUR CHOICE: ");
           scanf("%d",&input);
           system("pause");
           system("cls");
           return input;
}






//BARRA DE CARGA INNCIO
void barra()
{
    printf("\n");
    printf("+------------------+\n");
    printf("|                  |\n");
    printf("|    CARGANDO...   |\n");
    printf("|                  |\n");
    printf("|------------------|");
    printf("\n");
    int porcentaje;
    for (porcentaje = 0; porcentaje <= 100; porcentaje++)
    {
        imprimirBarraCarga(porcentaje);
        Sleep(10000); // Esperar 100ms (0.1 segundos)
    }
    printf("\nCarga completa\n");
    // sleep(1);
    system("cls");
}

void imprimirBarraCarga(int porcentaje)
{
    int i;
    for (i = 0; i < 50; i++)
    {
        if (i < porcentaje / 2)
        {
            printf("#");
        }
        else
        {
            printf(" ");
        }
        fflush(stdout); // Limpiar y mostrar la salida inmediatamente
    }
    printf("] %d%%\r", porcentaje);
    fflush(stdout); // Limpiar y mostrar la salida inmediatamente
}


//MENU DEPOSITO SUCURSALES

int menuOpcionDepositoSucursalAdmin()
{
    int selected;
    provincia ar[30];
    int validosProv=0;
    validosProv=descargarArchivo(ar,validosProv,30);
    catalogo arreglo[40];
    nodoProductos* buscadoDepos;
    catalogoSuc arregloSucur[40];
    int validos = 0, buscar = 0, pos = 0;
    int idDeProdu=0;
    nodoproductosSucursal *buscado;
    int idDesuc;
    int stock;
    do
    {
        selected = menuDepositoSucursalesAdmin();

        switch (selected)
        {
        case 1:


            validos = pasardeArchivoAArreglo(ARCHIVO_DEPOSITO, arreglo, 40);
            muestraDeCatalogo(arreglo, validos);


            printf("\ningrese el id del catálogo del producto a modificar stock\n");
            scanf("%d", &buscar);

            // Verificar si el catálogo existe en el arreglo
            pos = buscaEnCatalogoPorId(arreglo, validos, buscar);
            if (pos == -1)
            {
                printf("\nEl catálogo con ID %d no existe.\n", buscar);
                system("pause");
                break;
            }

            printf("\nINGRESE EL ID DEL PRODUCTO a modificar stock\n");
            scanf("%d", &idDeProdu);

            // Verificar si el producto existe en el catálogo
            buscadoDepos = buscaEnListaId(arreglo, pos, idDeProdu);
            if (buscadoDepos == NULL)
            {
                printf("\nEl producto con ID %d no existe en el catálogo %d.\n", idDeProdu, buscar);
                system("pause");
                break;
            }
            system("pause");
            system("cls");
            mostrarTodo(ar,validosProv);
            printf("\n\ncargue el id de la sucursal:  ");// esta la voy a pedir del menu de sucursales
            scanf("%d",&idDesuc);
            pos=VerificarSucursal(idDesuc);
            if(pos==1)
            {

            }
            else{
                printf("No Existe la sucursal\n");
                system("pause");
                break;
            }

            stock=cargarStockYmodificarlos(ARCHIVO_DEPOSITO,buscadoDepos);

            if(modificarStockEnArchivoDepSuc(ARCHIVO_SUCUSALDep,idDeProdu,idDesuc,stock)==1)//separa la funcion verifiar si en el archivo existe y si exite modificar su atock
            {
                // modificarStockEnArchivoDepSuc(ARCHIVO_SUCUSALDep,idDeProdu,idDesuc,stock);
            }
            else
            {
                recorrerDeposito(ARCHIVO_DEPOSITO,ARCHIVO_SUCUSALDep,idDesuc,idDeProdu,stock);
                // muestraArchivoSucursal(ARCHIVO_SUCUSALDep);
            }
            system("pause");
            break;
        case 2:

            muestraArchivoSucursal(ARCHIVO_SUCUSALDep);
            system("pause");
            break;
        case 3:

            printf("\n\ncargue el id de la suc:  ");// esta la voy a pedir del menu de sucursales
            scanf("%d",&idDesuc);

            printf("\nMUESTRA DEPOSITO DEL LOCAL:\n");
            validos=pasardeArchivoAArregloSucursal(ARCHIVO_SUCUSALDep,arregloSucur,40,idDesuc);
            printf("\nvalidos: %d",validos);
            muestraDecatalogoSucursal(arregloSucur,validos);
            system("pause");



            break;

        case 4 :

            printf("\n\ncargue el id de la suc:  ");// esta la voy a pedir del menu de sucursales
            scanf("%d",&idDesuc);
            validos = pasardeArchivoAArregloSucursal(ARCHIVO_SUCUSALDep, arregloSucur, 40,idDesuc);
            muestraDecatalogoSucursal(arregloSucur, validos);
            printf("\ningrese el id del catálogo del producto a DESACTIVAR\n");
            scanf("%d", &buscar);

            // Verificar si el catálogo existe en el arreglo
            pos = buscaEnCatalogoPorIdSUCURSAL(arregloSucur, validos, buscar);
            if (pos == -1)
            {
                printf("\nEl catálogo con ID %d no existe.\n", buscar);
                system("pause");
                break;
            }

            printf("\nINGRESE EL ID DEL PRODUCTO a DESACTIVAR\n");
            scanf("%d", &idDeProdu);

            // Verificar si el producto existe en el catálogo
            buscado = buscaEnListaIdSucursal(arregloSucur, pos, idDeProdu);
            if (buscado == NULL)
            {
                printf("\nEl producto con ID %d no existe en el catálogo %d.\n", idDeProdu, buscar);
                system("pause");
                break;
            }


            if (pos !=-1 )
            {
                desactivarProductoEnSucursal(ARCHIVO_SUCUSALDep,arregloSucur, pos, buscado,idDesuc);
                validos = pasardeArchivoAArregloSucursal(ARCHIVO_SUCUSALDep, arregloSucur, 40,idDesuc);
                muestraDecatalogoSucursal(arregloSucur, validos);

            }
            else
            {
                printf("\nno se encontro catalogo\n");
            }

            system("pause");
            break;
        case 5:

            printf("\n\ncargue el id de la suc:  ");// esta la voy a pedir del menu de sucursales
            scanf("%d",&idDesuc);
            validos = pasardeArchivoAArregloSucursal(ARCHIVO_SUCUSALDep, arregloSucur, 40,idDesuc);
            muestraDecatalogoSucursal(arregloSucur, validos);
            printf("\ningrese el id del catálogo  DESACTIVAR\n");
            scanf("%d", &buscar);

            // Verificar si el catálogo existe en el arreglo
            pos = buscaEnCatalogoPorIdSUCURSAL(arregloSucur, validos, buscar);
            if (pos == -1)
            {
                printf("\nEl catálogo con ID %d no existe.\n", buscar);
                system("pause");
                break;
            }


            if (pos !=-1 )
            {
                desactivarCatalogoSucursal(ARCHIVO_SUCUSALDep,arregloSucur, buscar,pos,idDesuc);
                validos = pasardeArchivoAArregloSucursal(ARCHIVO_SUCUSALDep, arregloSucur, 40,idDesuc);
                muestraDecatalogoSucursal(arregloSucur, validos);

            }
            else
            {
                printf("\nno se encontro catalogo\n");
            }

            system("pause");

            break;

        case 6:
            printf("\n\ncargue el id de la suc:  ");// esta la voy a pedir del menu de sucursales
            scanf("%d",&idDesuc);
            validos = pasardeArchivoAArregloSucursal(ARCHIVO_SUCUSALDep, arregloSucur, 40,idDesuc);
            muestraDecatalogoSucursalTodos(arregloSucur, validos);
            printf("\ningrese el id del catálogo del producto a ACTIVAR\n");
            scanf("%d", &buscar);

            // Verificar si el catálogo existe en el arreglo
            pos = buscaEnCatalogoPorIdSUCURSAL(arregloSucur, validos, buscar);
            if (pos == -1)
            {
                printf("\nEl catálogo con ID %d no existe.\n", buscar);
                system("pause");
                break;
            }


            if (pos !=-1 )
            {
                activarCatalogoSucursal(ARCHIVO_SUCUSALDep,arregloSucur, buscar,pos,idDesuc);
                validos = pasardeArchivoAArregloSucursal(ARCHIVO_SUCUSALDep, arregloSucur, 40,idDesuc);
                muestraDecatalogoSucursalTodos(arregloSucur, validos);

            }
            else
            {
                printf("\nno se encontro catalogo\n");
            }

            system("pause");

            break;

        case 7:
            printf("\n\ncargue el id de la suc:  ");// esta la voy a pedir del menu de sucursales
            scanf("%d",&idDesuc);
            validos = pasardeArchivoAArregloSucursal(ARCHIVO_SUCUSALDep, arregloSucur, 40,idDesuc);
            muestraDecatalogoSucursalTodos(arregloSucur, validos);
            printf("\ningrese el id del catálogo del producto a ACTIVAR\n");
            scanf("%d", &buscar);

            // Verificar si el catálogo existe en el arreglo
            pos = buscaEnCatalogoPorIdSUCURSAL(arregloSucur, validos, buscar);
            if (pos == -1)
            {
                printf("\nEl catálogo con ID %d no existe.\n", buscar);
                system("pause");
                break;
            }

            printf("\nINGRESE EL ID DEL PRODUCTO a ACTIVAR\n");
            scanf("%d", &idDeProdu);

            // Verificar si el producto existe en el catálogo
            buscado = buscaEnListaIdSucursal(arregloSucur, pos, idDeProdu);
            if (buscado == NULL)
            {
                printf("\nEl producto con ID %d no existe en el catálogo %d.\n", idDeProdu, buscar);
                system("pause");
                break;
            }


            if (pos !=-1 )
            {
                activarProductoEnSucursal(ARCHIVO_SUCUSALDep,arregloSucur, pos, buscado,idDesuc);
                validos = pasardeArchivoAArregloSucursal(ARCHIVO_SUCUSALDep, arregloSucur, 40,idDesuc);
                muestraDecatalogoSucursalTodos(arregloSucur, validos);

            }
            else
            {
                printf("\nno se encontro catalogo\n");
            }

            system("pause");

            break;



        case 0:


            printf("\n\nTERMINATE THE PROGRAM\n");
            break;
        }

    }
    while (selected != 0);

    system("PAUSE");
    system("cls");
    return 0;
}

int menuDepositoSucursalesAdmin()
{

    int input;
    system("cls");

    printf("\t\t\t\t\t\t\t\t\n----------");

    printf("                   \n MENU");
    printf("\n\t\t\t\t\t\t\t\t\t-----------");
    printf("\n\t\t\t\t\t\t\t\t\t1CARGA DE ARCHIVO DEPOSITO SUCURSAL");
    printf("\n\t\t\t\t\t\t\t\t\t2-MUESTRA DE ARCHIVO DEPOSITO SUCURSAL");
    printf("\n\t\t\t\t\t\t\t\t\t3-MOSTRAR ARREGLO DE LISTAS DEPOSITO SUCURSAL");
    printf("\n\t\t\t\t\t\t\t\t\t4-DESACTIVAR PRODUCTO DEL DEPOSITO DE SUCURSAL");
    printf("\n\t\t\t\t\t\t\t\t\t5-DESACTIVAR CATALOGO DEL DEPOSITO DE SUCURSAL");
    printf("\n\t\t\t\t\t\t\t\t\t6-ACTIVAR CATALOGO DEL DEPOSITO DE SUCURSAL");
    printf("\n\t\t\t\t\t\t\t\t\t7-ACTIVAR PRODUCTO DEL DEPOSITO DE SUCURSAL");
    printf("\n\n\t\t\t\t\t\t\t\t\tENTER YOUR CHOICE: ");
    scanf("%d",&input);
    system("cls");
    return input;
}


int menuOpcionVentasAdmin()
{
    int selected;
    do
    {
        selected = menuVentasAdmin();

        switch (selected)
        {
        case 1:
            cargarArchivoVentasMenu();
            break;

        case 2:
            muestraArchivoVentas(ARCHIVO_VENTAS);
            break;
        case 3:
            menuGanancias();
            break;

        case 0:
            printf("\n\nTERMINATE THE PROGRAM\n");
            break;
        }
    }
    while (selected != 0);

    printf("\n");
    return 0;
}


void cargarArchivoVentasMenu(){
    catalogoSuc arregloSucur[40];
    int idDeSuc,  validos;
    char fechaVenta[11];
    printf("\n\nIngrese el ID de la sucursal: ");
    scanf("%d", &idDeSuc);
    printf("\nINGRESE LA FECHA DE LA VENTA\n");
    fflush(stdin);
    gets(fechaVenta);

    validos = pasardeArchivoAArregloSucursal(ARCHIVO_SUCUSALDep, arregloSucur, 40, idDeSuc);
    muestraDecatalogoSucursal(arregloSucur, validos);
    pasarDeArregloDeposAArchivoVenta(arregloSucur,validos,ARCHIVO_VENTAS,ARCHIVO_SUCUSALDep, idDeSuc,fechaVenta);
    crearArchivoGananciasConVentas();
    getchar();
}


int menuVentasAdmin()
{

    int input;
    system("cls");

    printf("\t\t\t\t\t\t\t\t\n----------");

    printf("                   \n MENU");
    printf("\n\t\t\t\t\t\t\t\t\t-----------");
    printf("\n\t\t\t\t\t\t\t\t\t1CARGA DE ARCHIVO VENTAS");
    printf("\n\t\t\t\t\t\t\t\t\t2-MUESTRA DE ARCHIVO VENTAS");
    printf("\n\t\t\t\t\t\t\t\t\t3-MENU GANANCIAS");

    scanf("%d",&input);
    system("cls");
    return input;
}



//MENU PROVEDORES


int menuOpcionProveedoresAdmin()
{
    catalogo arregloDepos[40];
    int validos, selected;
    fila prov;
    inicFila(&prov);

    do
    {
        selected = menuProveedoresAdmin();

        switch (selected)
        {
        case 1:
            validos = pasardeArchivoAArreglo(ARCHIVO_DEPOSITO, arregloDepos, 40);
            pasarDeDepositoAAFilas(arregloDepos, validos, &prov, ARCHIVO_DEPOSITO);
            mostrarFila(prov);
            system("pause");
            break;

        case 0:
            printf("\n\nTERMINATE THE PROGRAM\n");
            break;
        }

    }
    while (selected != 0);

    printf("\n");
    return 0;
}

int menuProveedoresAdmin()
{
    int input;
    system("cls");

    printf("\t\t\t\t\t\t\t\t\n----------");
    printf("                   \n MENU");
    printf("\n\t\t\t\t\t\t\t\t\t-----------");
    printf("\n\t\t\t\t\t\t\t\t\t1 COMPRA DE STOCK");
    printf("\n\t\t\t\t\t\t\t\t\t0 EXIT");
    printf("\n\t\t\t\t\t\t\t\t\tSelect an option: ");

    scanf("%d", &input);
    system("cls");
    return input;
}


//MENUS USUARIO
int menuOpcionDepositoUsuario()
{
    int selected;
    catalogo arreglo[40];

    int validos = 0, buscar = 0, pos = 0;
    int idDeProdu=0;
    nodoProductos *buscado;

    do
    {

        selected = menuDepositoAdmin();

        switch (selected)
        {


        case 1:
            validos = pasardeArchivoAArreglo(ARCHIVO_DEPOSITO, arreglo, 40);
            muestraDeCatalogo(arreglo, validos);
            system("pause");

            break;

        case 6:
            validos = pasardeArchivoAArreglo(ARCHIVO_DEPOSITO, arreglo, 40);
            muestraDeCatalogoTodos(arreglo, validos);

            printf("\ningrese el id del catalogo del producto a activar\n");
            scanf("%d", &buscar);
            printf("\nINGRESE EL ID DEL PRODUCTO A  activar");
            scanf("%d",&idDeProdu);

            pos = buscaEnCatalogoPorId(arreglo, validos, buscar);
            buscado=buscaEnListaId(arreglo,pos,idDeProdu);

            activarProducto(ARCHIVO_DEPOSITO,arreglo,pos,buscado);
            system("pause");
            break;

        case 7:
            validos = pasardeArchivoAArreglo(ARCHIVO_DEPOSITO, arreglo, 40);
            muestraDeCatalogoTodos(arreglo, validos);

            printf("\ningrese el id del catalogo que desea activar\n");
            scanf("%d", &buscar);
            pos = buscaEnCatalogoPorId(arreglo, validos, buscar);

            if (pos !=-1 )
            {
                activarCatalogo(ARCHIVO_DEPOSITO,arreglo, buscar, pos);



            }
            else
            {
                printf("\nno se encontro catalogo\n");
            }

            system("pause");
            break;


        case 0:


            printf("\n\nTERMINATE THE PROGRAM\n");
            break;
        }

    }
    while (selected != 0);

    system("pause");
    system("cls");
    return 0;
}




