#include "menus.h"



int mainMenu()
{



    int opcion;

    do
    {
        // Menú principal
        system("cls");
        printf("Seleccione una opción:\n");
        printf("1. DEPOSITO GENERAL\n");
        printf("2. DEPOSITO POR SUCURSAL\n");
        printf("3. VENTAS\n");
        printf("4. Salir\n");

        scanf("\n%d", &opcion);

        switch (opcion)
        {
        case 1:
            menuOpcionDeposito();
            break;
        case 2:
            menuOpcionDepositoSucursal();
            break;
        case 3:
            menuOpcionVentas();
            break;
        case 4:
            printf("Saliendo del programa. ¡Hasta luego!\n");

            break;
        default:
            printf("Opción no válida. Inténtelo de nuevo.\n");

        }
        system("pause");
    }
    while (opcion != 4);

    return 0;
}



int menuOpcionDeposito()
{
    int selected;
    catalogo arreglo[40];

    int validos = 0, buscar = 0, pos = 0;
    int idDeProdu=0;
    nodoProductos *buscado;

    do
    {

        selected = menuDeposito();

        switch (selected)
        {
        case 1:
            //barra();
            muestraArchivo(ARCHIVO_DEPOSITO);
            break;

        case 2:
            printf("\nARCHIVO:\n");

            cargaArchivo(ARCHIVO_DEPOSITO);
            muestraArchivo(ARCHIVO_DEPOSITO);

            break;

        case 3:
            validos = pasardeArchivoAArreglo(ARCHIVO_DEPOSITO, arreglo, 40);
            muestraDeCatalogo(arreglo, validos);

            break;
        case 4:
            validos = pasardeArchivoAArreglo(ARCHIVO_DEPOSITO, arreglo, 40);
            muestraDeCatalogo(arreglo, validos);

            printf("\nIngrese el id del catalogo que desea desactivar: \n");
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
                printf("\nNo se encontro catalogo\n");
            }


            break;
        case 5 :



            validos = pasardeArchivoAArreglo(ARCHIVO_DEPOSITO, arreglo, 40);
            muestraDeCatalogo(arreglo, validos);

            printf("\nIngrese el id del catalogo del producto a dersactivar: \n");
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

            break;


        case 0:


            printf("\n\nTERMINATE THE PROGRAM\n");
            break;
        }
        system("pause");
    }
    while (selected != 0);


    system("cls");
    return 0;
}
int menuDeposito()
{

    int input;
    system("cls");

    printf("\t\t\t\t\t\t\t\t\n----------");

    printf("                   \n MENU");
    printf("\n\t\t\t\t\t\t\t\t\t-----------");
    printf("\n\t\t\t\t\t\t\t\t\t1-MUESTRA DEL ARCHIVO DEPOSTIO");
    printf("\n\t\t\t\t\t\t\t\t\t2-CARGA DEL ARCHIVO DEPOSITO");
    printf("\n\t\t\t\t\t\t\t\t\t3-MOSTRAR ARREGLO DE LISTAS DEPOSITO ");
    printf("\n\t\t\t\t\t\t\t\t\t4-DAR DE BAJA CATEGORIA del DEPOSITO");
    printf("\n\t\t\t\t\t\t\t\t\t5-DAR DE BAJA PRODUCTO DEL DEPOSITO" );
    printf("\n\t\t\t\t\t\t\t\t\t6-DAR DE ALTA PRODUCTO  ");// PASAR A LIBRERIA CATALOGO DE CARNICERIAS
    printf("\n\t\t\t\t\t\t\t\t\t7-DAR DE ALTA CATALOGO");
    printf("\n\t\t\t\t\t\t\t\t\t0-SALIR\n");


    printf("\n\n\t\t\t\t\t\t\t\t\tENTER YOUR CHOICE: ");
    scanf("%d",&input);
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

int menuOpcionDepositoSucursal()
{
    int selected;
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
        selected = menuDepositoSucursales();

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

            printf("\n\ncargue el id de la suc:  ");// esta la voy a pedir del menu de sucursales
            scanf("%d",&idDesuc);

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

int menuDepositoSucursales()
{

    int input;
    system("cls");

    printf("\t\t\t\t\t\t\t\t\n----------");

    printf("                   \n MENU");
    printf("\n\t\t\t\t\t\t\t\t\t-----------");
    printf("\n\t\t\t\t\t\t\t\t\t1-CARGA DE ARCHIVO DEPOSITO SUCURSAL");
    printf("\n\t\t\t\t\t\t\t\t\t2-MUESTRA DE ARCHIVO DEPOSITO SUCURSAL");
    printf("\n\t\t\t\t\t\t\t\t\t3-MOSTRAR ARREGLO DE LISTAS DEPOSITO SUCURSAL");
    printf("\n\t\t\t\t\t\t\t\t\t4-DESACTIVAR PRODUCTO DEL DEPOSITO DE SUCURSAL");
    printf("\n\t\t\t\t\t\t\t\t\t5-DESACTIVAR CATALOGO DEL DEPOSITO DE SUCURSAL");
    printf("\n\t\t\t\t\t\t\t\t\t6-ACTIVAR CATALOGO DEL DEPOSITO DE SUCURSAL");
    printf("\n\t\t\t\t\t\t\t\t\t7-ACTIVAR PRODUCTO DEL DEPOSITO DE SUCURSAL");
    printf("\n\t\t\t\t\t\t\t\t\t0-SALIR\n");
    printf("\n\n\t\t\t\t\t\t\t\t\tENTER YOUR CHOICE: ");
    scanf("%d",&input);
    system("cls");
    return input;
}


int menuOpcionVentas()
{
    int selected;
    catalogoSuc arregloSucur[40];
    int idDeSuc, buscar, validos, pos,idDeProdu;
    nodoproductosSucursal *buscado;
    do
    {
        selected = menuVentas();

        switch (selected)
        {
        case 1:
            printf("\n\nIngrese el ID de la sucursal: ");
            scanf("%d", &idDeSuc);

            validos = pasardeArchivoAArregloSucursal(ARCHIVO_SUCUSALDep, arregloSucur, 40, idDeSuc);
            muestraDecatalogoSucursal(arregloSucur, validos);

            printf("\nIngrese el ID del catálogo del producto para registrar la venta: ");
            scanf("%d", &buscar);

            // Verificar si el catálogo existe en el arreglo
            pos = buscaEnCatalogoPorIdSUCURSAL(arregloSucur, validos, buscar);

            if (pos == -1)
            {
                printf("\nEl catálogo con ID %d no existe.\n", buscar);
                getchar(); // Esperar la entrada del usuario
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

           pasarDeArregloDeposAArchivoVenta(arregloSucur, pos,idDeProdu, ARCHIVO_VENTAS, idDeSuc);
            getchar(); // Esperar la entrada del usuario
            system("pause");
            break;

        case 2:
            muestraArchivoVentas(ARCHIVO_VENTAS);
            system("pause");
            break;

        case 0:
            printf("\n\nTERMINATE THE PROGRAM\n");
            break;
        }

    } while (selected != 0);

    printf("\n");
    return 0;
}
int menuVentas()
{

    int input;
    system("cls");

    printf("\t\t\t\t\t\t\t\t\n----------");

    printf("                   \n MENU");
    printf("\n\t\t\t\t\t\t\t\t\t-----------");
    printf("\n\t\t\t\t\t\t\t\t\t1-CARGA DE ARCHIVO VENTAS");
    printf("\n\t\t\t\t\t\t\t\t\t2-MUESTRA DE ARCHIVO VENTAS");
    printf("\n\t\t\t\t\t\t\t\t\t0-SALIR\n");

    scanf("%d",&input);
    system("cls");
    return input;
}



