#ifndef CLSFECHA_H_INCLUDED
#define CLSFECHA_H_INCLUDED

class Fecha{
private:
    int dia,mes, anio;
    time_t t=time(0);
    struct tm *now= localtime(&t);
    int dia_h=now->tm_mday;
    int mes_h=now->tm_mon +1;
    int anio_h=now->tm_year+1900;
public:
    Fecha(){
        dia=dia_h;
        mes=mes_h;
        anio=anio_h;
    }
    bool Cargar(){
        bool valida=false;

        cout<<"INGRESE DIA: ";
        cin>>dia;
        if(dia<1 || dia>31){return false;}
        cout<<"INGRESE MES: ";
        cin>>mes;
        if(mes<1 || mes>12){return false;}
        cout<<"INGRESE ANIO: ";
        cin>>anio;
        if(anio<1900){return false;}

        if(anio>1900 && anio<anio_h){
        valida=true;
        return true;
        }else if (anio==anio_h && mes<mes_h){
        valida=true;
        return true;
        }if(anio==anio_h && mes==mes_h && dia<=dia_h){
        valida=true;
        return true;
        }

        if(valida){
        return true;
        }else {
        return false;}
    }
    void Mostrar(){
        cout<<dia<<"/";
        cout<<mes<<"/";
        cout<<anio<<endl;
    }
    void setDia(int d){dia=d;}
    void setMes(int m){mes=m;}
    void setAnio(int a){anio=a;}

    int getDia(){return dia;}
    int getMes(){return mes;}
    int getAnio(){return anio;}

    bool operator==(const Fecha &obj) const {
        if(dia == obj.dia && mes == obj.mes && anio == obj.anio){
            return true;
        };
        return false;
    }

};

#endif // CLSFECHA_H_INCLUDED
