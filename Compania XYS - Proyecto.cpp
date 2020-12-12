#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

//PROYECTO DEL ULTIMO CORTE DE LA ASIGNATURA DE ESTRUCTURA DE DATOS 1, DE LISTAS SIMPLES

//AUTOR: NAIVER ANILLO

struct articulos
{
	int codigo;
	string nombre;
	int cant_stock;
	int stock_minimo;
	float costo_articulo;
	int articulos_dev;
	
	articulos *sig;	
};

struct reporte
{
	int codigo;
	string nombre;
	int cant_pedir;
	
	reporte *sig;
};

struct suministros
{
	int codigo;
	int cant_unid_suminis;
	
	suministros *sig;
};

struct notas_pend
{
	int codigo;
	string nom;
	int cant_np;
	
	notas_pend *sig;
};

void crear_nodo(articulos **cab);
void imprimir_lista(articulos *cab);
void imprimir_notas_pendientes(notas_pend *cab4);
void art_mayor_cant_dev(articulos *cab);
void imprimir_reporte(reporte **cab2);
bool verificar_codigo(articulos *cab, int cod);
void pedir_articulos(articulos *cab, reporte **cab2, suministros **cab3);
void actualizar_reporte(reporte **cab2, int cant, int cod, string nom);
void actualizar_suministros(suministros **cab3,int cant, int cod);
void actualizar_stock(articulos **cab, suministros **cab3);
void despachar(articulos **cab, notas_pend **cab4, int cant, int cod);
void notas_pendientes(notas_pend **cab4, int cod, string nom, int aux, int aviso);
void nuevo_articulo(articulos **cab);
void eliminar_articulo(articulos **cab, int cod);
void art_defectuoso(articulos **cab, int cod, int cant);
int main(){
	
	struct articulos *cab=NULL;
	struct reporte *cab2=NULL;
	struct suministros *cab3=NULL;
	struct notas_pend *cab4=NULL;
	bool sw;
	int cod=0,cant=0,opc=0,exit=1;
	
	crear_nodo(&cab);
	
	while (exit == 1){
	
		system("cls");
		cout<<endl<<endl<<endl;
		cout<<"\t\t\t\t[BODEGA]"<<endl<<endl;
		cout<<"\t\t1. Registrar Nuevo Articulo."<<endl<<
			"\t\t2. Eliminar Articulo."<<endl<<
			"\t\t3. Pedir Articulos a los Proveedores."<<endl<<
			"\t\t4. Despachar Articulos."<<endl<<
			"\t\t5. Lista de Articulos."<<endl<<
			"\t\t6. Lista de Reportes."<<endl<<
			"\t\t7. Lista de Notas Pendientes y el Articulo con Mayor Cantidad de Notas Pendientes."<<endl<<
			"\t\t8. Actualizar Stock."<<endl<<
			"\t\t9. Articulo con Mayor Cantidad de Unidades Devueltas."<<endl<<
			"\t\t10. Devolucion de un Articulo Defectuoso."<<endl<<
			"\t\t11. Salir."<<endl;
		
		cout<<"\t\tElige una Opcion: ";
		cin>>opc;					
		cout<<endl;			
		
		switch(opc) 
		{
	    case 1: 
	    	system("cls");
	    	nuevo_articulo(&cab);
	    	system ("pause");
	    break;
	    
	    case 2: 
	   		system("cls");
	    	sw=false;
	    	cout<<"\n[ELIMINAR ARTICULO]"<<endl;
		    while(sw==false){
				cout<<"Digite el codigo del Articulo: ";
				cin>>cod;
				sw=verificar_codigo(cab,cod);
				if (sw==false)
				{
					cout<<"\n[ESTE CODIGO NO EXISTE, INTENTE NUEVAMENTE]"<<endl;
				}
			}		
	    	eliminar_articulo(&cab, cod);
	    	system ("pause");
	    break;
	    
	    case 3:
	    	system("cls");
	    	pedir_articulos(cab,&cab2, &cab3);
	    	system("pause");
	    break;
	    
	    case 4:
	    	system("cls");
	    	sw=false;
	    	cout<<"\n[DESPACHAR ARTICULO]"<<endl;
		    while(sw==false){
				cout<<"Digite el codigo del Articulo: ";
				cin>>cod;
				sw=verificar_codigo(cab,cod);
				if (sw==false)
				{
					cout<<"\n[ESTE CODIGO NO EXISTE, INTENTE NUEVAMENTE]"<<endl;
				}
			}
			cout<<"Digite la cantidad: ";
			cin>>cant;
	    	despachar(&cab, &cab4, cant, cod);
	    	system("pause");
	    break;
	    
	    case 5: 
	    	system("cls");
	    	imprimir_lista(cab);
	    	system("pause");
	    break;
	    
	    case 6: 
	    	system("cls");
	    	imprimir_reporte(&cab2);
	    	system("pause");
	    break;
	    
	    case 7: 
	    	system("cls");
	    	imprimir_notas_pendientes(cab4);
	    	system("pause");
	    break;
	    
	    case 8: 
	    	actualizar_stock(&cab, &cab3);
	    	system("pause");
	    break;
	    
	    case 9:
	    	system("cls");
	    	art_mayor_cant_dev(cab);
	    	system("pause");
	    break;
	    
	    case 10:
	    	sw=false;
	    	cout<<"[ARTICULO DEFECTUOSO]"<<endl;
	    	while(sw==false){
				cout<<"Digite el codigo del Articulo: ";
				cin>>cod;
				sw=verificar_codigo(cab,cod);
				if (sw==false)
				{
					cout<<"\n[ESTE CODIGO NO EXISTE, INTENTE NUEVAMENTE]"<<endl;
				}
			}
			cout<<"Digite la cantidad de defectuosos: ";
			cin>>cant;		
	    	art_defectuoso(&cab,cod,cant);
	    	system("pause");
	    break;
	    
	    case 11:
	    	exit=0;
	    break;
	    default: 
			cout<<"\n[OPCION INCORRECTA, INTENTE DE NUEVO]"<<endl;
			system("pause");
	    
	}

}
	
	
}

void crear_nodo(articulos **cab)
{
	struct articulos *nuevo=NULL,*p;
	float auxfloat;
	int auxint,i=0,sw=1;
	string auxstring;
	bool sw2;
	
	while(sw==1)
	{
		i=i+1;
		system("cls");
		cout<<"[REGISTRAR ARTICULOS]"<<endl;
		cout<<"[ARTICULO "<<i<<"]"<<endl<<endl;
		if (*cab==NULL)
		{
			cout<<"Codigo del articulo: ";
			cin>>auxint;
			nuevo= new articulos;
			nuevo->codigo=auxint;
			cout<<"Nombre del articulo: ";
			cin>>auxstring;
			nuevo->nombre=auxstring;
			cout<<"Cantidad del Stock: ";
			cin>>auxint;
			nuevo->cant_stock=auxint;
			cout<<"Stock Minimo: ";
			cin>>auxint;
			nuevo->stock_minimo=auxint;
			cout<<"Costo Articulo: ";
			cin>>auxfloat;
			nuevo->costo_articulo=auxfloat;
			nuevo->articulos_dev=0;
			nuevo->sig=NULL;
			*cab=nuevo;
			p=*cab;
		}else{
			sw2=true;
			while(sw2==true){
				cout<<"Codigo del articulo: ";
				cin>>auxint;
				sw2=verificar_codigo(*cab,auxint);
				
				if (sw2==true)
				{
					cout<<"[ERROR!! CODIGO REPETIDO]"<<endl;
				}
			}
			nuevo= new articulos;
			nuevo->codigo=auxint;
			cout<<"Nombre del articulo: ";
			cin>>auxstring;
			nuevo->nombre=auxstring;
			cout<<"Cantidad del Stock: ";
			cin>>auxint;
			nuevo->cant_stock=auxint;
			cout<<"Stock Minimo: ";
			cin>>auxint;
			nuevo->stock_minimo=auxint;
			cout<<"Costo Articulo: ";
			cin>>auxfloat;
			nuevo->costo_articulo=auxfloat;
			nuevo->articulos_dev=0;
			nuevo->sig=NULL;
			p->sig=nuevo;
			p=p->sig;
		}
		
		cout<<"\n[ARTICULO REGISTRADO CON EXITO]"<<endl;
		
		cout<<"\nSeguir registrando articulos? SI[1] | NO[0]: ";
		cin>>sw;
	}
}

bool verificar_codigo(articulos *cab, int cod)
{
	struct articulos *p;
	bool sw=false;
	
	p=cab;
	
	while (p != NULL && sw==false)
	{
		if(p->codigo == cod)
		{
			sw=true;
		}else{
			p=p->sig;
		}
			
	}
	
	
	return(sw);
}

void pedir_articulos(articulos *cab, reporte **cab2, suministros **cab3)
{
	
	struct articulos *p;
	int cod, cant=0,sw=1;
	string nom;
	bool sw2;
	
	
	if (cab == NULL)
	{
		cout<<"\nERROR!!"<<endl;
		cout<<"[NO HAY ARTICULOS]"<<endl;
	}else{
		cout<<"\n[PEDIDO DE ARTICULOS]"<<endl;
		while (sw==1)
		{
			sw2=false;
			while(sw2==false){
				cout<<"Digite el codigo del Articulo: ";
				cin>>cod;
				sw2=verificar_codigo(cab,cod);
			
				if (sw2==false)
				{
					cout<<"\n[ESTE CODIGO NO EXISTE, INTENTE NUEVAMENTE]"<<endl;
				}
			}
			p=cab;
			sw2=false;
			while (p != NULL && sw2==false) //REVISAR: PROBAR QUITANDOLE "P != NULL", INSTRUCCION INNECESARIA
			{
				if(p->codigo == cod)
				{
					if(p->cant_stock<p->stock_minimo){
						nom=p->nombre;
						cout<<"Digite la cantidad a pedir: ";
						cin>>cant;
						actualizar_reporte(&*cab2, cant, cod, nom);
						actualizar_suministros(&*cab3, cant, cod);
					
						cout<<"\n[SE HA GENERADO EL PEDIDO DEL ARTICULO | COD: "<<cod<<" |"<<endl;
						sw2=true;
					}else{
						cout<<"[SE GENERA EL PEDIDO, CUANDO LA CANTIDAD EN STOCK DEL ARTICULO ES INFERIOR"<<endl;
						cout<<"AL STOCK MINIMO]"<<endl;
						sw2=true;
					}
				}else{
					p=p->sig;
				}	
			}

			cout<<"\nQuiere seguir pidiendo? SI[1] | NO[0]: ";
			cin>>sw;
		}
	}
	
	
}

void actualizar_reporte(reporte **cab2, int cant, int cod, string nom)
{
	struct reporte *p,*nuevo;
	
	
	if (*cab2==NULL)
	{			
		nuevo= new reporte;
		nuevo->codigo=cod;
		nuevo->nombre=nom;
		nuevo->cant_pedir=cant;
		nuevo->sig=NULL;
		*cab2=nuevo;
	}else{
		p=*cab2;
		while(p->sig != NULL)
		{
			p=p->sig;
		}
		nuevo= new reporte;
		nuevo->codigo=cod;
		nuevo->nombre=nom;
		nuevo->cant_pedir=cant;
		nuevo->sig=NULL;
		p->sig=nuevo;

	}
	
}

void imprimir_reporte(reporte **cab2)
{
	struct reporte *p,*q;
	int i=0,auxcod=0,auxcant=0;
	string auxnom;
	p=*cab2;
	
	if(*cab2 == NULL)
	{
		cout<<"\nERROR!!"<<endl;
		cout<<"[NO HAY REPORTES]"<<endl;
	}else{
		if( p->sig == NULL)
		{
			cout<<"\n[REPORTE DE PEDIDOS]"<<endl<<endl;
			while (p != NULL)
			{
				cout<<"[REPORTE "<<(i=i+1)<<"]"<<endl;
				cout<<"CODIGO DEL ARTICULO: "<<p->codigo<<endl;
				cout<<"NOMBRE DEL ARTICULO:"<<p->nombre<<endl;
				cout<<"CANTIDAD A PEDIR: "<<p->cant_pedir<<endl<<endl;
					
				p=p->sig;
			}
		}else{
			while(p->sig != NULL)
			{
				q=p->sig;
			
				while(q != NULL)
				{
					if(p->codigo>q->codigo)
					{
						auxcod=p->codigo;
						auxcant=p->cant_pedir;
						auxnom=p->nombre;
						p->codigo=q->codigo;
						p->cant_pedir=q->cant_pedir;
						p->nombre=q->nombre;
						q->codigo=auxcod;
						q->cant_pedir=auxcant;
						q->nombre=auxnom;
					}
			
					q=q->sig;
				}	
		
				p=p->sig;
			}
	
	
			p=*cab2;
			cout<<"\n[REPORTE DE PEDIDOS]"<<endl<<endl;
			while (p != NULL)
			{
				cout<<"[REPORTE "<<(i=i+1)<<"]"<<endl;
				cout<<"CODIGO DEL ARTICULO: "<<p->codigo<<endl;
				cout<<"NOMBRE DEL ARTICULO:"<<p->nombre<<endl;
				cout<<"CANTIDAD A PEDIR: "<<p->cant_pedir<<endl<<endl;
				
				p=p->sig;
			}
		}
		
		}
}

void imprimir_lista(articulos *cab)
{
	struct articulos *p;
	int i=0;
	
	if (cab == NULL)
	{
		cout<<"\nERROR!!"<<endl;
		cout<<"[NO HAY ARTICULOS]"<<endl;
	}else{
		
		p=cab;
		cout<<"\n[ARTICULOS EN LA BODEGA]"<<endl<<endl;
	
		while (p != NULL)
		{
			cout<<"[ARTICULO "<<(i=i+1)<<"]"<<endl;
			cout<<"CODIGO DEL ARTICULO: "<<p->codigo<<endl;
			cout<<"NOMBRE DEL ARTICULO: "<<p->nombre<<endl;
			cout<<"CANTIDAD DE STOCK: "<<p->cant_stock<<endl;
			cout<<"STOCK MINIMO: "<<p->stock_minimo<<endl;
			cout<<"COSTO ARTICULO: "<<p->costo_articulo<<endl;
			cout<<"ARTICULOS DEVUELTOS: "<<p->articulos_dev<<endl<<endl;
	
			p=p->sig;
		}
	}
	

}

void art_mayor_cant_dev(articulos *cab)
{
	struct articulos *p;
	int artmay,cod,auxcod;
	string nom;
	
	
	if (cab == NULL)
	{
		cout<<"\nERROR!!"<<endl;
		cout<<"[NO HAY ARTICULOS]"<<endl;
	}else{
		p=cab;
		artmay=p->articulos_dev;
		cod=p->codigo;
		auxcod=p->codigo;
		nom=p->nombre;
		
		while ( p != NULL)
		{
			if(p->articulos_dev>artmay)
			{
				artmay=p->articulos_dev;
				cod=p->codigo;
				nom=p->nombre;
			}
		
			p=p->sig;	
		}
		
		if (auxcod == cod && artmay == 0)
		{
			cout<<"\n[NO HAY ARTICULOS DEVUELTOS]"<<endl;
		}else{
			cout<<"\n[EL ARTICULO CON MAYOR CANTIDAD DE UNIDADES DEVUELTAS]"<<endl;
			cout<<"CODIGO: "<<cod<<endl;
			cout<<"NOMBRE: "<<nom<<endl;
			cout<<"ARTICULOS DEVUELTOS: "<<artmay<<endl;
		}
		
	}
}

void actualizar_suministros(suministros **cab3,int cant, int cod)
{
	struct suministros *p, *nuevo;
	bool sw=false;
	if (*cab3==NULL)
	{			
		nuevo= new suministros;
		nuevo->codigo=cod;
		nuevo->cant_unid_suminis=cant;
		nuevo->sig=NULL;
		*cab3=nuevo;
	}else{
		p=*cab3;
		
		while (p != NULL && sw==false)
		{
			if (p->codigo == cod)
			{
				p->cant_unid_suminis=p->cant_unid_suminis+cant;
				sw=true;
			}else{
				p=p->sig;
			}
		}

		if (sw == false)
		{
			nuevo= new suministros;
			nuevo->codigo=cod;
			nuevo->cant_unid_suminis=cant;
			nuevo->sig=NULL;
			
			nuevo->sig=*cab3;
			*cab3=nuevo;
		}
		
	}
}

void actualizar_stock(articulos **cab, suministros **cab3)
{
	struct suministros *q;
	struct articulos *p;
	bool sw;
	
	
	if(*cab3 == NULL || *cab== NULL)
	{
		cout<<"ERROR!!"<<endl;
		cout<<"\n[NO HAY SUMINISTROS Y/O NO HAY ARTICULOS]"<<endl;
	}else{
		p=*cab;
		while (p != NULL)
		{
			q=*cab3;
			sw=false;
		
			while(q != NULL && sw==false)
			{
				if (p->codigo == q->codigo && q->cant_unid_suminis>0)
				{
					p->cant_stock=p->cant_stock+q->cant_unid_suminis;
					q->cant_unid_suminis=0;
					sw=true;
				}else{
					q=q->sig;
				}
			}
		
			p=p->sig;
		}
	
		cout<<"\n[LOS STOCKS HAN SIDO ACTUALIZADOS CON EXITO]"<<endl;
	}
	
}

void despachar(articulos **cab, notas_pend **cab4, int cant, int cod)
{
	struct articulos *p;
	struct notas_pend *q;
	bool sw=false;
	string nom;
	int aux=0, aviso=0;

	if(*cab == NULL)
	{
		cout<<"/nERROR!!"<<endl;
		cout<<"[NO HAY ARTICULOS]"<<endl;
	}else{
		p=*cab;
		while ( p != NULL && sw==false)
		{	
			//LA CANTIDAD ES MAYOR QUE EL STOCK
			if (cod == p->codigo && cant <= p->cant_stock)
			{
				aux=p->cant_stock-cant;
				p->cant_stock=aux;
				sw=true;
				aviso=1;
				nom=p->nombre;
				notas_pendientes(*&cab4, cod, nom, aux, aviso);
				//SUBPROGRAMA DE NOTAS PENDIENTES
				cout<<"\n[PEDIDO DESPACHADO]"<<endl;
			}else{
				//LA CANTIDAD ES MENOR QUE EL STOCK
				if (cod == p->codigo && cant>p->cant_stock)
				{
					cout<<"\n[NO HAY SUFICIENTES]"<<endl;
					cout<<"ARTICULOS ENTREGADOS: "<<p->cant_stock<<endl;
					aux=cant-p->cant_stock;
					p->cant_stock=0;
					aviso=2;
					nom=p->nombre;
					notas_pendientes(*&cab4, cod, nom, aux, aviso);
					//SUBPROGRAMA DE NOTAS PENDIENTES
					q=*cab4;
					while(q != NULL && sw==false)
					{
						if (cod == q->codigo)
						{
							sw=true;
						}else{
							q=q->sig;
						}
					}
				cout<<"CANTIDAD DE UNIDADES PENDIENTES POR DESPACHAR: "<<q->cant_np<<endl;
				
				}
					
				}
				
				p=p->sig;
			}
		}
	}
	


void notas_pendientes(notas_pend **cab4, int cod, string nom, int aux, int aviso)
{
	struct notas_pend *p,*nuevo;
	bool sw=false;
	if (*cab4 == NULL)
	{
		nuevo= new notas_pend;
		nuevo->codigo=cod;
		nuevo->nom=nom;
		
		if (aviso == 1)
		{	
			nuevo->cant_np=0;
		}else{
			nuevo->cant_np=aux;
		}
		nuevo->sig=NULL;
		*cab4=nuevo;
	}else{
		p=*cab4;
		
		if (aviso == 1)
		{
			while (p != NULL && sw==false)
			{
				if (cod == p->codigo && p->cant_np-aux<0 )
				{
					p->cant_np=p->cant_np-aux;
					p->cant_np=p->cant_np*(-1);
					sw=true;
				}else{
					p=p->sig;
				}
				
			}
			
			if (sw == false)
			{
				nuevo= new notas_pend;
				nuevo->codigo=cod;
				nuevo->nom=nom;
				nuevo->cant_np=0;	
				nuevo->sig=NULL;
				
				nuevo->sig=*cab4;
				*cab4=nuevo;
			}
			
		}else{
			
			while (p != NULL && sw==false)
			{
				if (cod == p->codigo)
				{
					p->cant_np=p->cant_np+aux;
					sw=true;
				}else{
					p=p->sig;
				}
				
			}
			
			if (sw == false)
			{
				nuevo= new notas_pend;
				nuevo->codigo=cod;
				nuevo->nom=nom;
				nuevo->cant_np=aux;	
				nuevo->sig=NULL;

				nuevo->sig=*cab4;
				*cab4=nuevo;
			}
		}
			
	}
	
}

void nuevo_articulo(articulos **cab)
{
	struct articulos *p, *nuevo;
	int cod=0,cant=0,stockm=0;
	float costo=0;
	bool sw;
	string nom;
	
	cout<<"\n[REGISTRAR NUEVO ARTICULO]"<<endl;
	if (*cab == NULL)
	{
		cout<<"\nCodigo del articulo: ";
		cin>>cod;
		nuevo= new articulos;
		nuevo->codigo=cod;
		cout<<"Nombre del articulo: ";
		cin>>nom;
		nuevo->nombre=nom;
		cout<<"Cantidad del Stock: ";
		cin>>cant;
		nuevo->cant_stock=cant;
		cout<<"Stock Minimo: ";
		cin>>stockm;
		nuevo->stock_minimo=stockm;
		cout<<"Costo Articulo: ";
		cin>>costo;
		nuevo->costo_articulo=costo;
		nuevo->articulos_dev=0;
		nuevo->sig=NULL;
		
		*cab=nuevo;
	}else{
		sw=true;
			while(sw==true){
				cout<<"\nCodigo del articulo: ";
				cin>>cod;
				sw=verificar_codigo(*cab,cod);
				
				if (sw==true)
				{
					cout<<"\n[ERROR!! CODIGO REPETIDO]"<<endl;
				}
			}
		nuevo= new articulos;
		nuevo->codigo=cod;
		cout<<"Nombre del articulo: ";
		cin>>nom;
		nuevo->nombre=nom;
		cout<<"Cantidad del Stock: ";
		cin>>cant;
		nuevo->cant_stock=cant;
		cout<<"Stock Minimo: ";
		cin>>stockm;
		nuevo->stock_minimo=stockm;
		cout<<"Costo Articulo: ";
		cin>>costo;
		nuevo->costo_articulo=costo;
		nuevo->articulos_dev=0;
		nuevo->sig=NULL;
		/*
		  Lo agrego al inicio de la lista para no gastar mucha memoria en recorrer
		  toda la lista para ir al ultimo nodo y enlazar el nuevo articulo.
		  La desventaja que a la hora de imprimir la lista de articulos, los articulos
		  que se agregaron al inicio del programa quedarian con el mismo orden, pero
		  los nuevos articulos que se agregan con la opcion de "Agregar nuevo articulo"
		  quedarian de primeros en ves de quedar de ultimos a la hora de listar los articulos.
		*/
		nuevo->sig=*cab;
		*cab=nuevo;
	}
	
	cout<<"\n[ARTICULO REGISTRADO]"<<endl;
}

void eliminar_articulo(articulos **cab, int cod)
{
	struct articulos *p,*q;
	bool sw;
	if(*cab == NULL)
	{
		cout<<"\nERROR!!!"<<endl;
		cout<<"[NO HAY ARTICULOS]"<<endl;
	}else{
		sw=false;
		p=*cab;
		while (p != NULL && sw==false)
		{
			if (p->codigo == cod)
			{
				sw=true;
			}else{
				p=p->sig;
			}
		}

		if (p == *cab)
		{
			*cab=(*cab)->sig;
			p->sig=NULL;
			free(p);
		}else{
			q=*cab;
			while(q->sig != p)
			{
				q=q->sig;
			}
			
			q->sig=p->sig;
			p->sig=NULL;
			free(p);
		}
		
		cout<<"\n[ARTICULO ELIMINADO]"<<endl;
	
	}
	
}

void art_defectuoso(articulos **cab, int cod, int cant)
{
	struct articulos *p;
	bool sw;
	
	if ( *cab == NULL)
	{
		cout<<"\nERROR!!"<<endl;
		cout<<"[NO HAY ARTICULOS]"<<endl;
	}else{
		p=*cab;
		sw=false;
		while (p != NULL && sw==false)
		{
			if (cod == p->codigo)
			{
				p->articulos_dev=p->articulos_dev+cant;
				sw=true;
			}else{
				p=p->sig;
			}
		}
		
	}
	
	cout<<"\n[ACTUALIZADO]"<<endl;
}

void imprimir_notas_pendientes(notas_pend *cab4)
{
	struct notas_pend *p;
	int i=0,cod=0,ntp=0;
	
	if (cab4 == NULL)
	{
		cout<<"\nERROR!!"<<endl;
		cout<<"[NO HAY NOTAS PENDIENTES]"<<endl;
	}else{
		p=cab4;
		cout<<"\n[NOTAS PENDIENTES]"<<endl;
		while (p != NULL)
		{
			if (p->cant_np>0)
			{
				cout<<"\n"<<(i=i+1)<<". CODIGO: "<<p->codigo<<endl;
				cout<<"   NOMBRE: "<<p->nom<<endl;
				cout<<"   CANTIDAD: "<<p->cant_np<<endl;
			}
			p=p->sig;
		}
		
		p=cab4;
		ntp=p->cant_np;
		cod=p->codigo;
		
		while (p != NULL)
		{
			if (p->cant_np>ntp)
			{
				cod=p->codigo;
			}
			
			p=p->sig;

		}
		
		cout<<"\n[ARTICULO CON MAYOR CANTIDAD DE NOTAS PENDIENTES]: Codigo "<<cod<<endl;
		
	}
	
}


