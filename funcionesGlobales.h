#ifndef FUNCIONESGLOBALES_H_INCLUDED
#define FUNCIONESGLOBALES_H_INCLUDED

void cargarCadena(char *pal, int tam){
    int i;
    fflush (stdin);
    for(i=0; i<tam;i++){
        pal[i]=cin.get();
        if(pal[i]=='\n')break;
    }
    pal[i]='\0';
    fflush(stdin); ///vuelve a limpiar el buffer para eliminar los caracteres sobrantes
}

///DEFINICIONES DE CONSTANTES Y FUNCIONES QUE SON UTILIZADAS POR LA CLASE PUNTO
enum Color{
    cNEGRO=0,
    cAZUL=1,
    cVERDE=2,
    cCIAN=3,
    cROJO=4,
    cMAGENTA=5,
    cMARRON=6,
    cGRIS_CLARO=7,
    cGRIS=8,
    cAZUL_CLARO=9,
    cVERDE_CLARO=10,
    cCIAN_CLARO=11,
    cROJO_CLARO=12,
    cMAGENTA_CLARO=13,
    cAMARILLO=14,
    cBLANCO=15
};
/// Se definen una serie de constantes que asumen el valor que se le asignó.
/// Es más fácil usar cBLANCO para setear el color a blanco, que acordarse el número 15

void ocultarCursor(){
   HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
   CONSOLE_CURSOR_INFO info;
   info.dwSize = 100;
   info.bVisible = FALSE;
   SetConsoleCursorInfo(consoleHandle, &info);
}

void mostrarCursor(){
   HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
   CONSOLE_CURSOR_INFO info;
   info.dwSize = 10;
   info.bVisible = TRUE;
   SetConsoleCursorInfo(consoleHandle, &info);
}

void gotoxy(short x, short y){ ///UBICA EL CURSOR EN LA POSICIÓN x,y DE LA PANTALLA
    COORD a;
    a.X = x;
    a.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),a);
}
///ASIGNA COLORES AL TEXTO Y AL FONDO DEL TEXTO
void textcolor(int colorTexto=15, int colorFondo=0){
    int color = colorTexto + colorFondo * 16;
    SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE), color);
}

void linecolor( int x = 0, int y = 0, int ancho = 10,int colorLinea = cBLANCO) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colorLinea);
    gotoxy(x, y);
    for (int i = 0; i < ancho; ++i) {
        cout << "-";
    }
}

void recuadro(short iniX, short iniY, short ancho, short alto, short colorLinea=cBLANCO, short colorFondo=cNEGRO){
    int i, j;
    for(i=iniX; i<=iniX+ancho; i++){
        for(j=iniY; j<=iniY+alto; j++){
            gotoxy(i, j);
            textcolor(colorLinea, colorFondo);
            //Arriba izquierda
            if(i==iniX && j==iniY){
                cout << (char) 201;
            }
            //Arriba derecha
            else if(i==iniX+ancho && j==iniY){
                cout << (char) 187;
            }
            //Abajo izquierda
            else if(i==iniX && j==iniY+alto){
                cout << (char) 200;
            }
            //Abajo derecha
            else if(i==iniX+ancho && j==iniY+alto){
                cout << (char) 188;
            }
            //Lineas arriba y abajo
            else if(j==iniY || j==iniY+alto){
                cout << (char) 205;
            }
            //Lineas izquierda y derecha
            else if(i==iniX || i==iniX+ancho){
                cout << (char) 186;
            }
            //Dentro del recuadro
            else{
                cout << " ";
            }
        }
    }
}

void hora(){
    time_t t=time(0);
    struct tm *now= localtime(&t);
    cout<<"HORA ACTUAL ";
    int hora=now->tm_hour;
    int minutos=now->tm_min;
    int segundos=now->tm_sec;
    cout<<hora<<":";
    cout<<minutos<<":";
    cout<<segundos<<endl;
}

///**FIN FUNCIONES
#endif // FUNCIONESGLOBALES_H_INCLUDED
