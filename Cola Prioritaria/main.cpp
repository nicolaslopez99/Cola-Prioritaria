#include<iostream>
#include "colapri.h"

using namespace std;
int main(){
	colapri cola(100);
	int prioridad,opcion;
	char clave;
	bool salir=false;
	
	while(!salir){
		cout<<"1.ingresar un dato a la cola"<<endl;
		cout<<"2.atender la cola"<<endl;
		cout<<"3.cola vacia?"<<endl;
		cout<<"4.cola llena?"<<endl;
		cout<<"5.tamaño actual de la cola"<<endl;
		cout<<"6.mostrar arreglo"<<endl;
		cout<<"7.salir"<<endl;
		cin>>opcion;
		cout<<endl;
		switch(opcion){
			case 1:
				cout<<"ingrese el dato:"<<endl;
				cin>>clave;
				cout<<"ingrese la prioridad:"<<endl;
				cin>>prioridad;
				cola.insertar(prioridad, clave);
				break;
			case 2:
				cout<<"atendiendo la cola"<<endl;
				cola.atender();
				break;
			case 3:
	   			if (cola.lista_vacia()==1){
					cout<<"La cola esta vacia"<<endl;
				}else{
					cout<<"La cola no esta vacia"<<endl;
				}			
				break;
			case 4:
				if (cola.lista_llena()==1){
					cout<<"La cola esta llena"<<endl;
				}else{
					cout<<"La cola no esta llena"<<endl;
				}
				break;
			case 5:
				cout<<"el tamaño del la cola es "<<cola.lista_tamano()<<endl;
				break;
			case 6:
				cola.prueba();
				break;
			case 7:
				salir=true;
				break;
			default:
				break;
		}
		cout<<endl;
	}
	return 0;
}
