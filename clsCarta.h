#ifndef CLSCARTA_H_INCLUDED
#define CLSCARTA_H_INCLUDED

bool numeroVerificadoCarta(int n);

/*CATEGORIAS
A- LINEA BLACK PREMIUM
C- LINEA CLÁSICA
P- PAPAS- CODIGO FIJO 5000*/

class Carta {
private:
    int idCarta;
    char nombre[30];
    char categoria;
    double precio;
    bool estado;
public:
    Carta();

    // Sobrecarga del operador ==
    bool operator==(const Carta& otra) const {
        return idCarta == otra.idCarta &&
               strcmp(nombre, otra.nombre) == 0 &&
               categoria == otra.categoria &&
               precio == otra.precio &&
               estado == otra.estado;
    }

    void setIdCarta(int num) { idCarta = num; }
    void setNombre(const char* n) { strcpy(nombre, n); }
    void setCategoria(char c) { categoria = c; }
    void setPrecio(double p) { precio = p; }
    void setEstado(bool e) { estado = e; }

    int getIdCarta() { return idCarta; }
    const char* getNombre() { return nombre; }
    char getCategoria() { return categoria; }
    double getPrecio() { return precio; }
    bool getEstado() { return estado; }

    void Cargar();
    void Mostrar();
};

Carta::Carta() { estado = false; }

void Carta::Cargar() {
    cout << "INGRESE ID DEL NUEVO PRODUCTO: ";
    cin >> idCarta;
    if (numeroVerificadoCarta(idCarta)) {
        cout << "ID EXISTENTE" << endl;
        return;
    }
    cout << "INGRESE NOMBRE DEL PRODUCTO: ";
    cargarCadena(nombre, 29);
    cout << "INGRESE CATEGORIA (A/C/P): ";
    cin >> categoria;
    categoria = tolower(categoria);
    if (categoria == 'a' || categoria == 'c' || categoria == 'p') {
        cout << "CATEGORIA VALIDA, CONTINUE" << endl;
    } else {
        cout << "CATEGORIA INVALIDA" << endl;
        return;
    }
    cout << "INGRESE PRECIO: $";
    cin >> precio;
    if (precio < 1) {
        cout << "PRECIO INVALIDO" << endl;
        return;
    }

    estado = true;
}

void Carta::Mostrar(){
    if(estado==true){
    cout<<"ID CARTA: "<<idCarta<<endl;
    cout<<"NOMBRE DEL PRODUCTO: "<<nombre<<endl;
    cout<<"CATEGORIA: "<<categoria<<endl;
    cout<<"PRECIO: $"<<precio<<endl;
    }
}


#endif // CLSCARTA_H_INCLUDED
