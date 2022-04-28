///Ejercicio:
///Autor:DEK
///Fecha:
///Comentario:

# include<iostream>
# include<cstdlib>
# include<cstdio>
# include<cstring>

using namespace std;

//NUEVA MODIFICACION

# include "clases.h"

class Esencial{
private:
    int numeroEmpresa;
    char nombreEmpresa[30];
    int cantidadEmpleados;
public:
    void setNumeroEmpresa(int ne){numeroEmpresa=ne;}
    void setNombreEmpresa (const char *ne){strcpy(nombreEmpresa, ne);}
    void setCantidadEmpleados(int ce){cantidadEmpleados=ce;}
    bool grabarEnDisco(){
        FILE *p;
        p=fopen("esenciales.dat", "ab");
        if(p==NULL) return false;
        bool escribio=fwrite(this, sizeof (Esencial),1,p);
        fclose(p);
        return escribio;
    }

};
///prototipos
void puntoA();
 void mostrarVector(int *, int );
void puntoB();
void puntoC();
    bool buscarCategoria(int cat);
bool crearArchivoEsencial();
///fin prototipos

int main(){
    puntoA();
    puntoB();
	if(crearArchivoEsencial()!=true){
        cout<<"NO SE PUDO GENERAR EL ARCHIVO DE ESENCIALES"<<endl;
        return -1;
    }
	puntoC();
	cout<<endl;
	system("pause");
	return 0;
}


void puntoA(){
    int pos=0, cantPorSeccion[9]={};
    Municipio reg;
    while(reg.leerDeDisco(pos)==true){
        cantPorSeccion[reg.getSeccion()-1]++;
        pos++;
    }
    cout<<"CANTIDAD DE MUNICIPIOS POR SECCION: "<<endl;
    mostrarVector(cantPorSeccion, 9);
}

void puntoB(){
    Empresa reg;
    int pos=0;
    while(reg.leerDeDisco(pos++)){
        if(reg.getCantidadEmpleados()>200)
            cout<<reg.getNombreEmpresa()<<endl;
    }
}


void puntoC(){
    Empresa reg;
    Esencial aux;
    bool esencial;
    int pos=0;
    while(reg.leerDeDisco(pos++)){
        esencial=buscarCategoria(reg.getCategoria());
        if(esencial==true){
            aux.setNumeroEmpresa(reg.getNumeroEmpresa());
            aux.setNombreEmpresa(reg.getNombreEmpresa());
            aux.setCantidadEmpleados(reg.getCantidadEmpleados());
            aux.grabarEnDisco();
        }

    }
}

bool buscarCategoria(int cat){
    Categoria reg;
    int pos=0;
    while(reg.leerDeDisco(pos++)){
        if(cat==reg.getNumeroCategoria()) return reg.getEsencial();
    }
    return false;
}


void copiarValorEsencial(bool *categorias){
    Categoria reg;
    int pos=0;
    while(reg.leerDeDisco(pos++)){
        categorias[reg.getNumeroCategoria()-1]=reg.getEsencial();
    }

}

void otro_puntoC(){
    bool categorias[80];
    copiarValorEsencial(categorias);
    Empresa reg;
    Esencial aux;
    bool esencial;
    int pos=0;
    while(reg.leerDeDisco(pos++)){
        if(categorias[reg.getCategoria()-1]==true){
            aux.setNumeroEmpresa(reg.getNumeroEmpresa());
            aux.setNombreEmpresa(reg.getNombreEmpresa());
            aux.setCantidadEmpleados(reg.getCantidadEmpleados());
            aux.grabarEnDisco();
        }

    }
}


bool crearArchivoEsencial(){
        FILE *p;
        p=fopen("esenciales.dat", "wb");
        if(p==NULL) return false;
        fclose(p);
        return escribio;
    }
