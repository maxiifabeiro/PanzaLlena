#ifndef MENUEMPLEADOS_H_INCLUDED
#define MENUEMPLEADOS_H_INCLUDED

void menuEmpleados(){
    while(true){
        system("cls");
        int opc;
        recuadro(40, 7, 40, 16, cAMARILLO, cNEGRO);
        gotoxy(45,9);
        cout<<"MENU EMPLEADOS"<<endl;
        linecolor(45,10,22,cAMARILLO);
        gotoxy(45,11);
        cout<<"1 - AGREGAR NUEVO EMPLEADO"<<endl;
        gotoxy(45,12);
        cout<<"2 - LISTAR EMPLEADO POR NUMERO"<<endl;
        gotoxy(45,13);
        cout<<"3 - LISTAR TODOS LOS EMPLEADOS"<<endl;
        gotoxy(45,14);
        cout<<"4 - MODIFICAR EMAIL EMPLEADO"<<endl;
        gotoxy(45,15);
        cout<<"5 - ELIMINAR EMPLEADO"<<endl;
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
                altaEmpleados();
                break;
            case 2:
                buscarRegistroEmpleados();
                break;
            case 3:
                listarEmpleados();
                break;
            case 4:
                modificarRegistroEmailEmpleado();
                break;
            case 5:
                bajaLogicaEmpleados();
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


#endif // MENUEMPLEADOS_H_INCLUDED
