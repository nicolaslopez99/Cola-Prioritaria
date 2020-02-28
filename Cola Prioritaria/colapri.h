#ifndef COLAPRI_H
# define COLAPRI_H
# include<iostream>
#include<iostream>
using namespace std;
struct nodop{
	int prioridad=0;
	char dato;
};

class colapri{
	int tam=0;
	int max;
	nodop arreglo[];
	
	public:
		colapri(int tamano){
			max=tamano;
			arreglo[tamano];
		}
		void prueba();
		int lista_vacia();
		int lista_llena();
		int lista_tamano();
		void insertar(int prioridad , char dato);
		void atender();
};
void colapri::atender(){
	nodop aux;
	int elemento;
	int hijoiz,hijoder;
	aux.prioridad=arreglo[tam].prioridad;
	aux.dato=arreglo[tam].dato;
	tam--;
	elemento=arreglo[1].prioridad;
	int pos=1;
	hijoiz=pos*2;
	hijoder=(pos*2)+1;
	while(aux.prioridad!=0){ 
		if (arreglo[hijoiz].prioridad<=aux.prioridad && arreglo[hijoder].prioridad<=aux.prioridad){
			arreglo[pos].dato=aux.dato;
			arreglo[pos].prioridad=aux.prioridad;
			aux.prioridad=0;
		} else if(aux.prioridad<=arreglo[hijoder].prioridad &&arreglo[hijoiz].prioridad <= arreglo[hijoder].prioridad){
			arreglo[pos].dato=arreglo[hijoder].dato;
			arreglo[pos].prioridad=arreglo[hijoder].prioridad;
			pos = hijoder;
			hijoiz=pos*2;
			hijoder=(pos*2)+1;
		} else if(aux.prioridad<=arreglo[hijoiz].prioridad &&arreglo[hijoder].prioridad <= arreglo[hijoiz].prioridad){
			arreglo[pos].dato=arreglo[hijoiz].dato;
			arreglo[pos].prioridad=arreglo[hijoiz].prioridad;
			pos = hijoiz;
			hijoiz=pos*2;
			hijoder=(pos*2)+1;
		}
		if (hijoiz>tam){
			hijoiz=0;
		}
		if (hijoder>tam){
			hijoder=0;
		}  
	}
	
	
}

void colapri::insertar(int prioridad,char dato){
	if (tam==0){
		arreglo[1].prioridad=prioridad;
		arreglo[1].dato=dato;
		tam++;
	}else{
		tam++;
		int pos=tam;
		int padre=tam/2;

		while( padre!=0  && arreglo[padre].prioridad<=prioridad ){
			arreglo[pos].prioridad=arreglo[padre].prioridad;
			arreglo[pos].dato=arreglo[padre].dato;
			arreglo[padre].prioridad=0;
			pos = padre;
			padre=padre/2;
		}
		arreglo[pos].prioridad=prioridad;
		arreglo[pos].dato=dato;
	}
}


int colapri::lista_llena(){
	if(tam==max){
		return 1;
	}else{
		return 0;
	}
}
int colapri::lista_vacia(){
	if (tam==0){
		return 1;
	}else{
		return 0;
	}
}

int colapri::lista_tamano(){
	return tam;	
}

void colapri::prueba(){
	for (int i=1;i<=tam;i++){
		cout<<i<<"- Dato: "<<arreglo[i].dato<<" Prioridad: "<<arreglo[i].prioridad<<endl;
	}
}

#endif
