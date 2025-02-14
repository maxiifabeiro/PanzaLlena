#ifndef MENUCLIENTE_H_INCLUDED
#define MENUCLIENTE_H_INCLUDED

void menuCliente(){
    while(true){
        int opc;
        system("cls");
        recuadro(40, 7, 40, 16, cAMARILLO, cNEGRO);
        gotoxy(45,9);
        cout<<"MENU CLIENTE"<<endl;
        linecolor(45,10,22,cAMARILLO);
        gotoxy(45,11);
        cout<<"1 - AGREGAR CLIENTE"<<endl;
        gotoxy(45,12);
        cout<<"2 - LISTAR CLIENTE POR NUMERO"<<endl;
        gotoxy(45,13);
        cout<<"3 - LISTAR TODOS LOS CLIENTES"<<endl;
        gotoxy(45,14);
        cout<<"4 - MODIFICAR NUM TELEFONO CLIENTE"<<endl;
        gotoxy(45,15);
        cout<<"5 - ELIMINAR CLIENTE"<<endl;
        gotoxy(45,16);
        cout<<"0 - VOLVER AL MENU PRINCIPAL"<<endl;
        gotoxy(45,17);
        linecolor(45,18,22,cAMARILLO);
        gotoxy(45,19);
        cout<<"INGRESE LA OPCION: ";
        cin>>opc;
        system("cls");
        switch(opc){
            case 1:
                altaClientes();
                break;
            case 2:
                buscarRegistroCliente();
                break;
            case 3:
                listarClientes();
                break;
            case 4:
                modificarRegistroTelefonoClientes();
                break;
            case 5:
                bajaLogicaCliente();
                break;
            case 0:
                return;
            default:
                cout<<"LA OPCION INGRESADA NO ES CORRECTA"<<endl;
                system("pause");
                system("cls");
                break;
        }
        system("pause");
    }
}


#endif // MENUCLIENTE_H_INCLUDED
