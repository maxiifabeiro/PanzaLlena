#ifndef MENUCARTA_H_INCLUDED
#define MENUCARTA_H_INCLUDED

void menuCarta(){
    while(true){
        system("cls");
        int opc;
        recuadro(40, 7, 40, 16, cAMARILLO, cNEGRO);
        gotoxy(45,9);
        cout<<"MENU CARTA"<<endl;
        linecolor(45,10,22,cAMARILLO);
        gotoxy(45,11);
        cout<<"1 - AGREGAR PLATO A LA CARTA"<<endl;
        gotoxy(45,12);
        cout<<"2 - LISTAR PLATO SEGUN ID"<<endl;
        gotoxy(45,13);
        cout<<"3 - LISTAR TODA LA CARTA"<<endl;
        gotoxy(45,14);
        cout<<"4 - MODIFICAR PRECIO"<<endl;
        gotoxy(45,15);
        cout<<"5 - ELIMINAR CARTA"<<endl;
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
                altaCarta();
                break;
            case 2:
                buscarRegistroCarta();
                break;
            case 3:
                listarCarta();
                break;
            case 4:
                modificarCarta();
                break;
            case 5:
                bajaLogicaCarta();
                break;
            case 0:
                return;
            default:
                cout<<"LA OPCION INGRESADA NO ES CORRECTA"<<endl;
                system("pause");
                system("cls");
                return;
        }
        system("pause");
    }
}

#endif // MENUCARTA_H_INCLUDED
