#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <vector>
#include <cstdlib>

using namespace std;


long long randbtwn(long long a , long long b){
  srand(time(0));
  return rand() % (b-a+1)+a;
}

class Persona {
  string nombre;
  string apellido;
  long long dni;

public:
  Persona(string nombre = "vacio" , string apellido = "vacio" , long long dni = 0) : nombre(nombre),
                                                                                    apellido(apellido),
                                                                                    dni(dni){}

  string GetNombres(){return this->nombre;}
  string getApellido(){return this->apellido;}
  long long getDni(){return this->dni; }
  void Imprimir(){ cout << nombre << "    " << apellido << "    "<<dni;}


};


void load_data(vector<string>& nombres , vector<string>& apellidos){
    string dato;
    ifstream fn("nombres.txt");
    while(getline(fn,dato)){nombres.push_back(dato); }
    fn.close();
    ifstream fa("apellidos.txt");
    while(getline(fa,dato)){apellidos.push_back(dato); }
    fa.close();
}

void clean_data(vector<string>& nombres , vector<string>& apellidos){
  nombres.clear();
  apellidos.clear();
}

void insert_data_arr(Persona * array[10000]){
  vector<string> nombres;
  vector<string> apellidos;
  long long dni;
  string nom, ape;

  load_data(nombres,apellidos);
  for(int i = 0 ; i < 10000 ; ++i){
    Persona * oPersona;
    nom = nombres[randbtwn(0,nombres.size()-1)] + " " + nombres[randbtwn(0,nombres.size()-1)];
    ape = apellidos[randbtwn(0,apellidos.size()-1)] + " " + apellidos[randbtwn(0,apellidos.size()-1)];
    dni = randbtwn(10000000,99999999);
    oPersona = new Persona(nom,ape,dni);
    array[i] = oPersona;
    delete oPersona;
  }
  clean_data(nombres,apellidos);
}

Persona * search_data_arr(string data , Persona* array[10000]){
  for(int i = 0 ; i < 10000 ; ++i){
    if(array[i]->GetNombres() == data) return array[i];
  }
  return NULL;
}

bool delete_data_arr(string name, Persona *array[10000]){
  Persona * arr_aux [10000-1];
  Persona * aux;
  bool deleted = false;

  if(search_data_arr(name,array) == NULL) return false;
  else{
    for(int i = 0 ; i < 10000 ; ++i){
      if(array[i]-> GetNombres() == name && deleted == false){
        aux = array[i];
        delete aux;
        deleted = true;
      } else if( deleted == false ){
        arr_aux[i] = array[i];
      }else{
        arr_aux[i-1] = array[i];
      }
    }
  }
  return true;
}


// SIMPLE LINKED LIST

template< class T>

class SimpleList {

struct Nodo{
  Nodo*next;
  Persona *elemento;
  Nodo(Persona* elemento = NULL , Nodo* next = NULL): elemento(elemento),next(next){}
};
private:
  int n;
  Nodo* inicio;

public:

  class Iterador{
    Nodo* aux;
  public:
    Iterador(Nodo*aux = NULL):aux(aux){}
    bool operator !=(Iterador it){ return aux != it.aux; }
    T operator *(){ return aux->elemento; }
    void operator ++(int dummy){ aux = aux->next; }
  };

  Iterador First(){ return inicio; }
  Iterador Last(){ return NULL ; }

  SimpleList ():n(0),inicio(NULL){}
  ~SimpleList (){
    while(inicio != NULL){
      Nodo *aux = inicio;
      inicio = inicio->next;
      delete aux;
    }
  }

  void insert_data_front(){
      vector<string> nombres;
  		vector<string> apellidos;
  		long long dni;
		  string nom,ape;

      load_data(nombres,apellidos);

      for(int i=0;i<10000;++i){
  			Persona* data;
  			nom = nombres[randbtwn(0,nombres.size()-1)] + " " + nombres[randbtwn(0,nombres.size()-1)];
  			ape = apellidos[randbtwn(0,apellidos.size()-1)] + " " + apellidos[randbtwn(0,apellidos.size()-1)];
  			dni = randbtwn(10000000,99999999);
        data = new Persona(nom,ape,dni);
        Nodo* nuevo = new Nodo(data,inicio);
        inicio = nuevo;
        ++n;
        delete data,nuevo;
      }

      clean_data(nombres,apellidos);
  }

  void insert_data_back(){
    vector<string> nombres;
    vector<string> apellidos;
    long long dni;
    string nom,ape;

    load_data(nombres,apellidos);

    for(int i=0;i<10000;++i){
      Persona* data;
      nom = nombres[randbtwn(0,nombres.size()-1)] + " " + nombres[randbtwn(0,nombres.size()-1)];
      ape = apellidos[randbtwn(0,apellidos.size()-1)] + " " + apellidos[randbtwn(0,apellidos.size()-1)];
      dni = randbtwn(10000000,99999999);
      data = new Persona(nom,ape,dni);

      if(n == 0){
        Nodo* nuevo = new Nodo(data,inicio);
        inicio = nuevo;
        ++n;
        delete nuevo;
      }else{
        Nodo *aux = inicio ; int c = 1;
        while(c++ < n ){
          aux = aux->next;
        }

        Nodo*nuevo = new Nodo(data,aux->next);
        aux->next = nuevo;
        ++n;
        delete nuevo;
      }
      delete data;
    }
    clean_data(nombres,apellidos);
  }


  bool delete_front(){
    if(n == 0) return false;
    Nodo *aux = inicio;
    inicio = inicio->next;
    delete aux;
    --n;
    return true;
  }

  bool delete_pos(int pos){

		if(pos < 0 || pos > n ) return false;
		if(pos == 0) { delete_front(); return true; }
		int c = 1; Nodo*aux = inicio;
		while(c++ < pos)
		{
			aux = aux->next;
		}
		Nodo *aux2 = aux->next;
		aux->next = aux2->next;
		delete aux2;
		--n;
		return true;
	}

  bool delete_back(){
		delete_pos(n-1);
	}

};
