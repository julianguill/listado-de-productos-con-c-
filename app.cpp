#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <fstream>

using namespace std;

struct Compra{
	char nombre[100];
	float precio;
}producto[100], *pr = producto;

void consultar(Compra *, int n){
	
	for(int i=0; i<n-1; i++){
		for(int j=0; j<n-i-1; j++){
			if((pr+j)->precio > (pr+j+1)->precio){
				Compra aux = *(pr+j);
				*(pr+j) = *(pr+j+1);
				*(pr+j+1) = aux;
			}
		}
	}
}

void escribir(Compra *, int n){
	
	ofstream archivo;
	archivo.open("Productos.txt", ios::out); //abriendo archivo 

	if(archivo.fail()){
		cout<<"No se pudo abrir el archivo";
		exit(1);
	}
	
	for(int i=0;i<n;i++){
		archivo<<"\n(X) Producto Numero: "<<i+1<<endl;
		archivo<<" * "<<(pr+i)->nombre<<endl;
		archivo<<" * Precio en Dolares: "<<(pr+i)->precio<<"$"<<endl;
		archivo<<" * Precio en Bolivares: "<<(pr+i)->precio*40<<" Bs"<<endl;
	}

	archivo.close(); //cerrando archivo 
}

int main(){

	int opcion = -1;
	
	int p = 0;
	
	do{
		fflush(stdin);
		
		cout<<"\n\nIngrese el nombre del producto: "; cin.getline((pr+p)->nombre,20,'\n');

		cout<<"Ingrese el precio del producto: "; cin>>(pr+p)->precio;

		p++;
		
		cout<<"\nDesea ingresar otro producto? [1] Si [2] No: [3] ver agregados: "; 
		cin>>opcion;
		
		if(opcion == 3){
			
			consultar(pr, p);
			
			for(int i=0; i<p; i++){
				cout<<"\n____________________\n";
				cout<<"->Compra Numero: "<<i+1<<endl;
				cout<<" * "<<(pr+i)->nombre<<endl;
				cout<<" * Precio en Dolares: "<<(pr+i)->precio<<"$"<<" | Bs: "<<(pr+i)->precio*40;
			}
			
			cout<<"\nDesea Ingresar Otro Producto? [1] Si [2] No: ";
			cin>>opcion;
		}

	}while(opcion == 1);
	
	cout<<"\n\n";
	
	consultar(pr, p);

	for(int i=0; i<p; i++){
		cout<<"\n____________________\n";
		cout<<"->Compra Numero: "<<i+1<<endl;
		cout<<" * "<<(pr+i)->nombre<<endl;
		cout<<" * Precio en Dolares: "<<(pr+i)->precio<<"$"<<" | Bs: "<<(pr+i)->precio*40;
	}
	
	escribir(pr,p);
	
	getch();
	return 0;
}


//Programa Listo Gracias por Preferirnos (Dolbear Center).
