#include "menus.h"



//MENUS ADMIN

int mainMenuAdmin()
{



    int opcion=99;

    do
    {
        // Menú principal
        system("cls");
        printf("\n\n\n");
        printf("\t\t _______________________________________________________________________________________________\n");
        printf("\t\t|                                                                                               |\n");
        printf("\t\t|                                                                                               |\n");
        printf("\t\t|   ##   ##  ### ###  ### ##    ## ##     ##     ### ##   ### ###  ### ##     ####     ##       |\n");
        printf("\t\t|    ## ##    ##  ##   ##  ##  ##   ##     ##     ##  ##   ##  ##   ##  ##     ##       ##      |\n");
        printf("\t\t|   # ### #   ##       ##  ##  ##        ## ##    ##  ##   ##       ##  ##     ##     ## ##     |\n");
        printf("\t\t|   ## # ##   ## ##    ## ##   ##        ##  ##   ##  ##   ## ##    ## ##      ##     ##  ##    |\n");
        printf("\t\t|   ##   ##   ##       ## ##   ##        ## ###   ##  ##   ##       ## ##      ##     ## ###    |\n");
        printf("\t\t|   ##   ##   ##  ##   ##  ##  ##   ##   ##  ##   ##  ##   ##  ##   ##  ##     ##     ##  ##    |\n");
        printf("\t\t|   ##   ##  ### ###  #### ##   ## ##   ###  ##  ### ##   ### ###  #### ##    ####   ###  ##    |\n");
        printf("\t\t|                                                                                               |\n");
        printf("\t\t|                             1. DEPOSITO GENERAL                                               |\n");
        printf("\t\t|                             2. VENTAS                                                         |\n");
        printf("\t\t|                             3. COMPRA DE PROVEEDORES                                          |\n");
        printf("\t\t|                             0. VOLVER                                                         |\n");
        printf("\t\t|                                                                                               |\n");
        printf("\t\t|_______________________________________________________________________________________________|\n");
        printf("\n");

        opcion=getch() - '0';
        system("cls");
        switch (opcion)
        {
        case 1:
            menuOpcionDepositoAdmin();
            break;

        case 2:
            menuOpcionVentasAdmin();
            break;
        case 3:
           menuOpcionProveedoresAdmin();
            system("pause");
            break;
        default:
            printf("Opción no válida. Inténtelo de nuevo.\n");
        }

    }
    while (opcion != 0);

    return 0;
}



int menuOpcionDepositoAdmin()
{
    int selected;
    provincia ar[30];

    int validosProv = 0;


    validosProv = descargarArchivo(ar, validosProv, 30);

    do
    {
        selected = menuDepositoAdmin();

        switch (selected)
        {
        case 1:


            realizarCargaStockProducto(ar,validosProv);
            //muestraArchivo(ARCHIVO_DEPOSITO);
             system("pause");
            break;

        case 2:
            printf("\n---MUESTRA DE CATALOGO--\n");
            muestraCatalgoMenu();
            system("pause");
            break;

        case 3:

                menuAltaBaja(ar,validosProv);
                system("pause");

            break;

        case 4:
            printf("\n---MODIFICACIONES DEPOSITO GENERAL--\n");
            menuModificaionesDeposGRL();
            system("pause");
            break;
        }
    }
    while (selected != 0);

    return 0;
}

void realizarCargaStockProducto(provincia ar[], int validosProv)
{
    printf("--CARGA DE STOCK PRODUCTO--\n\n");
    mostrarTodo(ar, validosProv);

    printf("\n\nCargue el id de la sucursal: ");
    int idDesuc;
    scanf("%d", &idDesuc);

    int posProv = VerificarSucursal(idDesuc);
    system("pause");
    system("cls");

    if (posProv != 1) {
        printf("No Existe la sucursal\n");
    } else {
        cargaArchivo(ARCHIVO_DEPOSITO, idDesuc);
        //muestraArchivo(ARCHIVO_DEPOSITO);
        system("pause");
    }
}


void muestraCatalgoMenu() {
    int validosProv = 0, idDesuc;
    provincia ar[30];
    int validos=0;
    catalogo arreglo[40];
    int posProv;



    validosProv = descargarArchivo(ar, validosProv, 30);

    printf("--CARGA DE STOCK PRODUCTO--\n\n");

    mostrarTodo(ar, validosProv);
    printf("\n\nCargue el id de la sucursal:  ");
    scanf("%d", &idDesuc);
    posProv = VerificarSucursal(idDesuc);
    printf("%d",posProv);
    system("pause");
    system("cls");
    if (posProv != 1) {
        printf("No Existe la sucursal\n");
    }
    else
    {

        validos = pasardeArchivoAArreglo(ARCHIVO_DEPOSITO, idDesuc, arreglo, 40);

        ordenarCatalogoAlfabeticamente(arreglo, validos);
        muestraDeCatalogo(arreglo, validos);
    }

    system("pause");
}

int menuModificaionesDeposGRL()
{
    char opcion;
    int validosProv = 0,  idDesuc;
    provincia ar[30];
    int posProv;
    validosProv = descargarArchivo(ar, validosProv, 30);

    do
    {
        system("cls");
        printf("\t\t\t1) CAMBIAR DE NOMBRE DE LA CATEGORIA\n");
        printf("\t\t\t2) CAMBIAR DE NOMBRE EL PRODUCTO\n");
        printf("\t\t\t3) CAMBIAR EL PRECIO\n");
        printf("\t\t\t0) Volver\n");

        opcion = getch(); // No es necesario restar '0', ya que getch devuelve un char

        switch (opcion)
        {
        case '1':



            mostrarTodo(ar, validosProv);
            printf("\n\nCargue el id de la sucursal:  ");
            scanf("%d", &idDesuc);
            posProv = VerificarSucursal(idDesuc);
            if (posProv != 1)
            {
                printf("No Existe la sucursal\n");
            }
            else
            {

                modificacionCatalogo(idDesuc);
                system("pause");
            }

            break;

        case '2':
            mostrarTodo(ar, validosProv);
            printf("\n\nCargue el id de la sucursal:  ");
            scanf("%d", &idDesuc);
            posProv = VerificarSucursal(idDesuc);
            if (posProv != 1)
            {
                printf("No Existe la sucursal\n");
            }
            else
            {

                modificacionProduc(idDesuc);
                system("pause");
            }

            break;

        case '3':
            mostrarTodo(ar, validosProv);
            printf("\n\nCargue el id de la sucursal:  ");
            scanf("%d", &idDesuc);
            posProv = VerificarSucursal(idDesuc);
            if (posProv != 1)
            {
                printf("No Existe la sucursal\n");
            }
            else
            {

                modificacionProducPrecio(idDesuc);
                system("pause");
            }


            break;

        case '0':
            break;

        default:
            printf("Opcion no valida. Intente de nuevo.\n");
            system("pause");
            break;
        }

    }
    while (opcion != '0');

    return 0;
}




void modificacionProducPrecio(int idDesuc)
{
    int buscar = 0, posCatalogo = 0;
    int validos;
    nodoProductos *buscado;
    catalogo arreglo[40];
    int idDeProdu = 0;
    int productoDat;

    system("cls");



    validos = pasardeArchivoAArreglo(ARCHIVO_DEPOSITO,idDesuc,arreglo,40);
    ordenarCatalogoAlfabeticamente(arreglo, validos);
    muestraDeCatalogo(arreglo, validos);

    printf("\n\t\t\t\tIngrese el ID del catálogo del producto que desea cambiar: ");
    scanf("%d", &buscar);

    printf("\n\t\t\t\tIngrese el ID del producto que desea cambiar: ");
    scanf("%d", &idDeProdu);

    posCatalogo = buscaEnCatalogoPorId(arreglo, validos, buscar);

    if (posCatalogo != -1)
    {
        buscado = buscaEnListaId(arreglo, posCatalogo,idDeProdu);

        if (buscado != NULL)
        {
            system("cls");
            printf("\n\t\t\t\tProducto encontrado en el catálogo %s\n", arreglo[posCatalogo].nombreDeCategoria);
            printf("\t\t\t\t-------------------------------------\n");

            printf("\n\t\t\t\tPRECIO actual del producto: %d\n", buscado->dato.precioPorKilo);
            printf("\t\t\t\tPRECIO nombre del producto: ");
            scanf("%d",&productoDat);



            // Modificar el producto en el archivo
            modificarProductoPrecioArchivo(arreglo,posCatalogo,buscado->dato.id,productoDat);

            printf("\n\t\t\t\tProducto modificado con éxito.\n");
        }
        else
        {
            printf("\n\t\t\t\tNo se encontró el producto con el ID %d en el catálogo.\n", idDeProdu);
        }
    }
    else
    {
        printf("\n\t\t\t\tNo se encontró el catálogo con el ID %d.\n", buscar);
    }

    system("pause");
}








void modificacionProduc(int idDeSuc)
{
    int buscar = 0, posCatalogo = 0;
    int validos;
    nodoProductos *buscado;
    catalogo arreglo[40];
    int idDeProdu = 0;
    char productoDat[40];

    system("cls");

    validos = pasardeArchivoAArreglo(ARCHIVO_DEPOSITO,idDeSuc,arreglo,40);
    ordenarCatalogoAlfabeticamente(arreglo, validos);
    muestraDeCatalogo(arreglo, validos);

    printf("\n\t\t\t\tIngrese el ID del catálogo del producto que desea cambiar: ");
    scanf("%d", &buscar);

    printf("\n\t\t\t\tIngrese el ID del producto que desea cambiar: ");
    scanf("%d", &idDeProdu);

    posCatalogo = buscaEnCatalogoPorId(arreglo, validos, buscar);

    if (posCatalogo != -1)
    {
        buscado = buscaEnListaId(arreglo, posCatalogo,idDeProdu);

        if (buscado != NULL)
        {
            system("cls");
            printf("\n\t\t\t\tProducto encontrado en el catálogo %s\n", arreglo[posCatalogo].nombreDeCategoria);
            printf("\t\t\t\t-------------------------------------\n");

            printf("\n\t\t\t\tNombre actual del producto: %s\n", buscado->dato.nombreDeProductos);
            printf("\t\t\t\tNuevo nombre del producto: ");
            fflush(stdin);
            gets(productoDat);

            // Modificar el producto en la lista en memoria
            strcpy(buscado->dato.nombreDeProductos, productoDat);

            // Modificar el producto en el archivo
            modificarProductoArchivo(arreglo,posCatalogo,buscado->dato.id,productoDat);

            printf("\n\t\t\t\tProducto modificado con éxito.\n");
        }
        else
        {
            printf("\n\t\t\t\tNo se encontró el producto con el ID %d en el catálogo.\n", idDeProdu);
        }
    }
    else
    {
        printf("\n\t\t\t\tNo se encontró el catálogo con el ID %d.\n", buscar);
    }

    system("pause");
}

void modificacionCatalogo(int idDeSuc)
{
    int buscar = 0, pos = 0;
    int validos;
    catalogo arreglo[40];
    char catalogoDat[40];

    system("cls");

    printf("\n");
    validos = pasardeArchivoAArreglo(ARCHIVO_DEPOSITO, idDeSuc,arreglo,40);
    ordenarCatalogoAlfabeticamente(arreglo, validos);
    muestraDeCatalogo(arreglo, validos);

    printf("\nIngrese el ID del catálogo que desea modificar: ");
    scanf("%d", &buscar);

    pos = buscaEnCatalogoPorId(arreglo, validos, buscar);

    if (pos != -1)
    {
        system("pause");
        system("cls");
        printf("\n\t\t\t\tNombre actual del catalogo: %s\n",arreglo[pos].nombreDeCategoria);
        printf("\t\t\t\tNuevo nombre del producto: ");
        fflush(stdin);
        gets(catalogoDat);

        modificarCatalogoArchivo(arreglo, pos, catalogoDat);
        printf("\n\t\t\t\tCatálogo modificado con éxito.\n");
    }
    else
    {
        printf("\n\t\t\t\tNo se encontró el catálogo con el ID %d.\n", buscar);
        return 0;//se me rompe sino cuando cargo una mal
    }

    system("pause");
}





void menuAltaBaja(provincia ar[], int validosProv)
{
    int opcion;
    int validos = 0, buscar = 0, pos = 0;
    int idDeProdu = 0;
    catalogo arreglo[40];
    nodoProductos *buscado;






    mostrarTodo(ar, validosProv);

    printf("\n\nCargue el id de la sucursal que va a modificar: ");
    int idDesuc;
    scanf("%d", &idDesuc);

    int posProv = VerificarSucursal(idDesuc);
   validos = pasardeArchivoAArreglo(ARCHIVO_DEPOSITO,idDesuc, arreglo, 40);
             ordenarCatalogoAlfabeticamente(arreglo, validos);
    system("pause");
    system("cls");

if(posProv==1)
{

    do
    {
        system("cls");
        printf("\t\t\t1)Dar de baja a una categoria\n");
        printf("\t\t\t2)Dar de baja a un producto\n");
        printf("\t\t\t3)Dar de alta a una producto\n");
        printf("\t\t\t4)Dar de alta a una categoria\n");
        printf("\t\t\t0)Volver\n");
        opcion=getch() -'0';

        switch(opcion)
        {

        case 1://muestra archivo depos general

                //muestraCatalgoMenu();


        muestraDeCatalogo(arreglo, validos);

         printf("\nid de suc: %d",idDesuc);
            printf("\nIngrese el id de la categoria que desea desactivar: \n");
            scanf("%d", &buscar);

            pos = buscaEnCatalogoPorId(arreglo, validos, buscar);

            system("pause");
            if (pos !=-1)
            {
                desactivarCatalogo(ARCHIVO_DEPOSITO,arreglo,pos,idDesuc);

                system("pause");
            }
            else
            {
                printf("\nNo se encontro catalogo.\n");
            }
            system("pause");
            break;
        case 2 ://carga deposito general solo los productos y catalogos



            muestraDeCatalogo(arreglo,validos);
            printf("\nIngrese el id del catalogo del producto a desactivar: \n");
            scanf("%d", &buscar);
            printf("\nIngrese el id del producto a dar de baja: ");
            scanf("%d",&idDeProdu);
            system("pause");
            pos = buscaEnCatalogoPorId(arreglo, validos, buscar);
            buscado=buscaEnListaId(arreglo,pos,idDeProdu);


            if (pos !=-1 )
            {
                if(buscado!=NULL)
                {
                    desactivarProducto(ARCHIVO_DEPOSITO,arreglo, pos,buscado,idDesuc);
                }
                else
                {
                    printf("\nNo se encontro producto.\n");
                }


            }
            else
            {
                printf("\nNo se encontro catalogo.\n");
            }


            break;
        case 3://muestra  depos general



         muestraDeCatalogoTodos(arreglo,validos);

               printf("\nIngrese el id del catalogo del producto a activar: \n");
            scanf("%d", &buscar);

            printf("\nIngrese el id del producto a activar: ");
            scanf("%d",&idDeProdu);

            system("pause");
            pos = buscaEnCatalogoPorId(arreglo, validos, buscar);
            buscado=buscaEnListaId(arreglo,pos,idDeProdu);

            system("pause");
            if (pos !=-1)
            {
                activarProducto(ARCHIVO_DEPOSITO,arreglo,pos,buscado,idDesuc);

            }
            else
            {
                printf("\nNo se encontro catalogo.\n");
            }
            break;

        case 4://activar catalogo depos
               //muestraCatalgoMenu();
            ;
              muestraDeCatalogoTodos(arreglo,validos);

            printf("\nIngrese el id de la categoria que desea desactivar: \n");
            scanf("%d", &buscar);

            pos = buscaEnCatalogoPorId(arreglo, validos, buscar);
            printf("1pos:%d",pos);
            system("pause");
            if (pos !=-1)
            {
                activarCatalogo(ARCHIVO_DEPOSITO,arreglo, buscar, pos,idDesuc);
                printf("\n1entor");
            }
            else
            {
                printf("\nNo se encontro catalogo.\n");
            }
            break;


        }
    }
    while(opcion!=0);
}

}
int menuDepositoAdmin()
{

    int input;
    system("cls");
    printf("\n\n\n");
    printf("\t\t _____________________________________________________________________________________________________________________________________________________________________________\n");
    printf("\t\t|                                                                                                                                                                             |\n");
    printf("\t\t|                                                                                                                                                                             |\n");
    printf("\t\t|   ###                                         ##       ##                                                                                       ###                         |\n");
    printf("\t\t|    ##                                                  ##                                                                                        ##                         |\n");
    printf("\t\t|    ##    ####     ######   ####     #####    ###      #####    ####              #####   ##  ##    ####    ##  ##   ######    #####    ####      ##      ####     #####     |\n");
    printf("\t\t| #####   ##  ##    ##  ##  ##  ##   ##         ##       ##     ##  ##            ##       ##  ##   ##  ##   ##  ##    ##  ##  ##           ##     ##     ##  ##   ##         |\n");
    printf("\t\t| ##  ##  ######    ##  ##  ##  ##    #####     ##       ##     ##  ##             #####   ##  ##   ##       ##  ##    ##       #####    #####     ##     ######    #####     |\n");
    printf("\t\t| ##  ##  ##        #####   ##  ##        ##    ##       ## ##  ##  ##                 ##  ##  ##   ##  ##   ##  ##    ##           ##  ##  ##     ##     ##            ##    |\n");
    printf("\t\t| ######  #####     ##       ####    ######    ####       ###    ####             ######    ######   ####     ######  ####     ######    #####    ####     #####   ######     |\n");
    printf("\t\t|                  ####                                                                                                                                                       |\n");
    printf("\t\t|                                                                                                                                                                             |\n");
    printf("\t\t|                                            1.CARGA DEPOSITO DE SUCURSAL                                                                                                     |\n");
    printf("\t\t|                                            2.MUESTRA DEPOSITO                                                                                                               |\n");
    printf("\t\t|                                            3.ALTA/BAJA                                                                                                                      |\n");
    printf("\t\t|                                            4.MODIFICACIONES                                                                                                                 |\n");
    printf("\t\t|                                            0. SALIR                                                                                                                         |\n");
    printf("\t\t|_____________________________________________________________________________________________________________________________________________________________________________|\n");

    input=getch()-'0';
    system("cls");
    return input;
}




//BARRA DE CARGA INNCIO







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
            system("pause");
            break;
        case 3:
            menuGanancias();
            break;


        }
    }
    while (selected != 0);

    printf("\n");
    return 0;
}


void cargarArchivoVentasMenu()
{


    provincia ar[30];
    int validosProv=0;
    validosProv=descargarArchivo(ar,validosProv,30);
    int pos=0;
    catalogo arreglo[40];
    int idDeSuc,  validos;
    char fechaVenta[11];


    mostrarTodo(ar,validosProv);
    printf("\n\ncargue el id de la sucursal:  ");// esta la voy a pedir del menu de sucursales
    scanf("%d",&idDeSuc);
    system("pause");
    system("cls");
        pos=VerificarSucursal(idDeSuc);
    if(pos==1)
    {

        printf("\nIngrese la fecha de la venta(DIA/MES/ANIO): ");
        fflush(stdin);
        gets(fechaVenta);
        int seEncuentraFechaGanancias=buscaEnArchivoGanancias(nombreArchivoGanancias, fechaVenta);
        if(seEncuentraFechaGanancias==0 || seEncuentraFechaGanancias==-1)
        {
            validos = pasardeArchivoAArreglo(ARCHIVO_DEPOSITO,idDeSuc,arreglo,40);
            muestraDeCatalogo(arreglo, validos);
            pasarDeArregloDeposAArchivoVenta(arreglo,validos,ARCHIVO_VENTAS, idDeSuc,fechaVenta);
            crearArchivoGananciasConVentas();
            getchar();
        }
        else
        {
            printf("\nLa fecha ya ha sido cargada.\n");
        }
    }
    else
    {
        printf("No Existe la sucursal\n");
        system("pause");

    }
    system("pause");
    system("cls");


}


int menuVentasAdmin()
{

    int input;
    system("cls");
    printf("\n\n\n");
    printf("\t\t ______________________________________________________\n");
    printf("\t\t|                              ##                      |\n");
    printf("\t\t|                              ##                      |\n");
    printf("\t\t| ##  ##    ####    #####     #####    ####     #####  |\n");
    printf("\t\t| ##  ##   ##  ##   ##  ##     ##         ##   ##      |\n");
    printf("\t\t| ##  ##   ######   ##  ##     ##      #####    #####  |\n");
    printf("\t\t|  ####    ##       ##  ##     ## ##  ##  ##        ## |\n");
    printf("\t\t|   ##      #####   ##  ##      ###    #####   ######  |\n");
    printf("\t\t|                                                      |\n");
    printf("\t\t|                                                      |\n");
    printf("\t\t|                 1. CARGA DE ARCHIVO VENTAS           |\n");
    printf("\t\t|                 2. MUESTRA DE ARCHIVO VENTAS         |\n");
    printf("\t\t|                 3. MENU GANANCIAS                    |\n");
    printf("\t\t|                 0. VOLVER                            |\n");
    printf("\t\t|______________________________________________________|\n");

    input=getch()-'0';
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

    int validosProv = 0,  idDesuc;
    provincia ar[30];


    int posProv;
    validosProv = descargarArchivo(ar, validosProv, 30);

    do
    {
        selected = menuProveedoresAdmin();

        switch (selected)
        {
        case 1://carga la mercaderia en depos general

            mostrarTodo(ar, validosProv);
            printf("\n\nCargue el id de la sucursal:  ");
            scanf("%d", &idDesuc);
            system("pause");
            system("cls");
            posProv = VerificarSucursal(idDesuc);
            if (posProv != 1)
            {
                printf("No Existe la sucursal\n");
            }
            else
            {
                validos = pasardeArchivoAArreglo(ARCHIVO_DEPOSITO,idDesuc,arregloDepos,40);
                pasarDeDepositoAAFilas(arregloDepos, validos, &prov, ARCHIVO_DEPOSITO);
                mostrarFila(prov);
                system("pause");
            }

            system("pause");


            break;

        case 0:

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
    printf("\n\n\n");
    printf("\t\t __________________________________________________________________________________________\n");
    printf("\t\t|                                                 ###                                      |\n");
    printf("\t\t|                                                  ##                                      |\n");
    printf("\t\t| ######   ######    ####    ##  ##    ####        ##    ####    ######    ####     #####  |\n");
    printf("\t\t|  ##  ##   ##  ##  ##  ##   ##  ##   ##  ##    #####   ##  ##    ##  ##  ##  ##   ##      |\n");
    printf("\t\t|  ##  ##   ##      ##  ##   ##  ##   ######   ##  ##   ##  ##    ##      ######    #####  |\n");
    printf("\t\t|  #####    ##      ##  ##    ####    ##       ##  ##   ##  ##    ##      ##            ## |\n");
    printf("\t\t|  ##      ####      ####      ##      #####    ######   ####    ####      #####   ######  |\n");
    printf("\t\t| ####                                                                                     |\n");
    printf("\t\t|                                                                                          |\n");
    printf("\t\t|                                                                                          |\n");
    printf("\t\t|                               1. COMPRA DE STOCK                                         |\n");
    printf("\t\t|                               0. VOLVER                                                  |\n");
    printf("\t\t|__________________________________________________________________________________________|\n");



    scanf("%d", &input);
    system("cls");
    return input;
}
//MENUS USUARIO



int mainMenuUsuario ()
{



    int opcion=99;

    do
    {
        // Menú principal
        system("cls");
        printf("\n\n\n");
        printf("\t\t _______________________________________________________________________________________________\n");
        printf("\t\t|                                                                                               |\n");
        printf("\t\t|                                                                                               |\n");
        printf("\t\t|   ##   ##  ### ###  ### ##    ## ##     ##     ### ##   ### ###  ### ##     ####     ##       |\n");
        printf("\t\t|    ## ##    ##  ##   ##  ##  ##   ##     ##     ##  ##   ##  ##   ##  ##     ##       ##      |\n");
        printf("\t\t|   # ### #   ##       ##  ##  ##        ## ##    ##  ##   ##       ##  ##     ##     ## ##     |\n");
        printf("\t\t|   ## # ##   ## ##    ## ##   ##        ##  ##   ##  ##   ## ##    ## ##      ##     ##  ##    |\n");
        printf("\t\t|   ##   ##   ##       ## ##   ##        ## ###   ##  ##   ##       ## ##      ##     ## ###    |\n");
        printf("\t\t|   ##   ##   ##  ##   ##  ##  ##   ##   ##  ##   ##  ##   ##  ##   ##  ##     ##     ##  ##    |\n");
        printf("\t\t|   ##   ##  ### ###  #### ##   ## ##   ###  ##  ### ##   ### ###  #### ##    ####   ###  ##    |\n");
        printf("\t\t|                                                                                               |\n");
        printf("\t\t|                                                                                               |\n");
        printf("\t\t|                             1. DEPOSITO POR SUCURSAL                                          |\n");
        printf("\t\t|                                                                                               |\n");
        printf("\t\t|_______________________________________________________________________________________________|\n");
        printf("\n");

        opcion=getch() - '0';
        system("cls");
        switch (opcion)
        {

        case 1:
            menuOpcionDepositoSucursalUsuario();
            break;
        default:
            printf("Opción no válida. Inténtelo de nuevo.\n");
        }

    }
    while (opcion != 0);

    return 0;
}





int menuOpcionDepositoSucursalUsuario()
{
    int opcion;
    do
    {
        opcion = menuDepositoSucursalesUusario();
        switch (opcion)
        {

        case 1:
           muestraCatalgoMenu();
            break;

        }

    }
    while (opcion != 0);

    return 0;
}



int menuDepositoSucursalesUusario()
{

    int input;
    system("cls");
    printf("\n\n\n");
    printf("\t\t _____________________________________________________________________________________________________________________________________________________________________________\n");
    printf("\t\t|                                                                                                                                                                             |\n");
    printf("\t\t|                                                                                                                                                                             |\n");
    printf("\t\t|   ###                                         ##       ##                                                                                       ###                         |\n");
    printf("\t\t|    ##                                                  ##                                                                                        ##                         |\n");
    printf("\t\t|    ##    ####     ######   ####     #####    ###      #####    ####              #####   ##  ##    ####    ##  ##   ######    #####    ####      ##      ####     #####     |\n");
    printf("\t\t| #####   ##  ##    ##  ##  ##  ##   ##         ##       ##     ##  ##            ##       ##  ##   ##  ##   ##  ##    ##  ##  ##           ##     ##     ##  ##   ##         |\n");
    printf("\t\t| ##  ##  ######    ##  ##  ##  ##    #####     ##       ##     ##  ##             #####   ##  ##   ##       ##  ##    ##       #####    #####     ##     ######    #####     |\n");
    printf("\t\t| ##  ##  ##        #####   ##  ##        ##    ##       ## ##  ##  ##                 ##  ##  ##   ##  ##   ##  ##    ##           ##  ##  ##     ##     ##            ##    |\n");
    printf("\t\t| ######  #####     ##       ####    ######    ####       ###    ####             ######    ######   ####     ######  ####     ######    #####    ####     #####   ######     |\n");
    printf("\t\t|                  ####                                                                                                                                                       |\n");
    printf("\t\t|                                                                                                                                                                             |\n");
    printf("\t\t|                                            1. MOSTRAR DEPOSITO SUCURSAL                                                                                                     |\n");
    printf("\t\t|                                            0. SALIR                                                                                                                         |\n");
    printf("\t\t|_____________________________________________________________________________________________________________________________________________________________________________|\n");

    input=getch()- '0';
    system("cls");
    return input;
}


