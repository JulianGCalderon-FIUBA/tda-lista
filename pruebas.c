#include "src/lista.h"
#include "src/pila.h"
#include "src/cola.h"
#include "src/interno.h"
#include "pa2mm.h"

// PILA

void puedoCrearUnaPilaCorrectamente()
{
  pila_t *pila = pila_crear();

  pa2m_afirmar(pila, "La pila creada no es NULL");
  pa2m_afirmar(pila->nodo_fin == NULL, "La pila se crea con tope NULL");
  pa2m_afirmar(pila->cantidad == 0, "La pila se crea con tamaño CERO");

  pila_destruir(pila);
}

void dadaUnaPilaVacia_alPedirElTope_devuelveNULL()
{
  pila_t *pila = pila_crear();

  pa2m_afirmar(pila_tope(pila) == NULL, "Dada una pila vacia, al pedir el tope, devuelve NULL");

  pila_destruir(pila);
}

void dadaUnaPilaNoVacia_alPedirElTope_devuelveElUltimoElemento()
{
  pila_t *pila = pila_crear();
  int elemento1 = 11;
  int elemento2 = 22;

  pila_apilar(pila, &elemento1);
  pila_apilar(pila, &elemento2);

  pa2m_afirmar(pila_tope(pila) == (void *)&elemento2, "Dada una pila con dos elementos, al pedir el tope, devuelve el ultimo");

  pila_destruir(pila);
}

void dadaUnaPilaVacia_puedoApilarYDesapilarVariosElementos()
{
  pila_t *pila = pila_crear();
  int elemento1 = 11;
  int elemento2 = 22;

  pila_apilar(pila, &elemento1);
  pa2m_afirmar(pila->nodo_inicio->elemento == (void *)&elemento1, "Dada una pila vacia, puedo apilar un elemento");
  pila_apilar(pila, &elemento2);
  pa2m_afirmar(pila->nodo_inicio->elemento == (void *)&elemento2, "Dada una pila con un elemento, puedo apilar otro elemento");

  pa2m_afirmar(pila_desapilar(pila) == (void *)&elemento2, "Dada una pila con dos elementos, puedo desapilar el ultimo elemento");
  pa2m_afirmar(pila_desapilar(pila) == (void *)&elemento1, "Dada una pila con un elemento, puedo desapilar el unico elemento");

  pila_destruir(pila);
}

void dadaUnaPilaVacia_alDesapilarUnElemento_devuelveNULL()
{
  pila_t *pila = pila_crear();

  pa2m_afirmar(!pila_desapilar(pila), "Dada una pila vacia, no puedo desapilar un elemento");

  pila_destruir(pila);
}

void dadaUnaPilaVacia_alPedirElTamanio_devuelveCero()
{
  pila_t *pila = pila_crear();

  pa2m_afirmar(pila_tamanio(pila) == 0, "Dada una pila vacia, al pedir el tamaño, devuelve CERO");

  pila_destruir(pila);
}

void dadaUnaPilaNoVacia_alPedirElTamanio_devuelveLaCantidadDeElementos()
{
  pila_t *pila = pila_crear();
  int elemento1 = 11;
  int elemento2 = 22;

  pila_apilar(pila, &elemento1);
  pila_apilar(pila, &elemento2);

  pa2m_afirmar(pila_tamanio(pila) == 2, "Dada una pila con dos elementos, al pedir el tamaño, devuelve DOS");

  pila_destruir(pila);
}

void dadaUnaPilaVacia_alVerificarSiEstaVacia_devuelveTrue()
{
  pila_t *pila = pila_crear();

  pa2m_afirmar(pila_vacia(pila), "Dada una pila vacia, al preguntar si esta vacia, devuelve TRUE");

  pila_destruir(pila);
}

void dadaUnaPilaNoVacia_alVerificarSiEstaVacia_devuelveFalse()
{
  pila_t *pila = pila_crear();
  int elemento1 = 11;
  int elemento2 = 22;

  pila_apilar(pila, &elemento1);
  pila_apilar(pila, &elemento2);

  pa2m_afirmar(pila_vacia(pila) == false, "Dada una pila no vacia, al preguntar si esta vacia, devuelve FALSE");

  pila_destruir(pila);
}

// COLA

void puedoCrearUnaColaCorrectamente()
{
  cola_t *cola = cola_crear();

  pa2m_afirmar(cola, "La cola creada no es NULL");
  pa2m_afirmar(cola->nodo_inicio == NULL, "La cola se crea con inicio NULL");
  pa2m_afirmar(cola->nodo_fin == NULL, "La cola se crea con final NULL");
  pa2m_afirmar(cola->cantidad == 0, "La cola se crea con tamaño CERO");

  cola_destruir(cola);
}

void dadaUnaColaVacia_alPedirElFrente_devuelveNULL()
{
  cola_t *cola = cola_crear();

  pa2m_afirmar(!cola_frente(cola), "Dada una cola vacia, al pedir el frente, devuelve NULL");

  cola_destruir(cola);
}

void dadaUnaColaNoVacia_alPedirElFrente_devuelveElPrimero()
{
  cola_t *cola = cola_crear();
  int elemento1 = 11;
  int elemento2 = 22;

  cola_encolar(cola, &elemento1);
  cola_encolar(cola, &elemento2);

  pa2m_afirmar(cola_frente(cola) == (void *)&elemento1, "Dada una cola con dos elementos, al pedir el frente, devuelve el primer elemento");

  cola_destruir(cola);
}

void dadaUnaColaVacia_puedoEncolarYDesencolarVariosElementos()
{
  cola_t *cola = cola_crear();
  int elemento1 = 11;
  int elemento2 = 22;

  cola_encolar(cola, &elemento1);
  pa2m_afirmar(cola->nodo_fin->elemento == (void *)&elemento1, "Dada una cola vacia, puedo encolar un elemento");

  cola_encolar(cola, &elemento2);
  pa2m_afirmar(cola->nodo_fin->elemento == (void *)&elemento2, "Dada una cola con un elemento, puedo encolar otro elemento");

  pa2m_afirmar(cola_desencolar(cola) == (void *)&elemento1, "Dada una cola con dos elementos, puedo desencolar el primero");
  pa2m_afirmar(cola_desencolar(cola) == (void *)&elemento2, "Dada una cola con un elemento, puedo desencolar el unico elemento");

  cola_destruir(cola);
}

void dadaUnaColaVacia_alDesencolarUnElemento_devuelveNULL()
{
  cola_t *cola = cola_crear();

  pa2m_afirmar(!cola_desencolar(cola), "Dada una cola vacia, no puedo desencolar un elemento");

  cola_destruir(cola);
}

void dadaUnaColaVacia_alPedirElTamanio_devuelveCero()
{
  cola_t *cola = cola_crear();

  pa2m_afirmar(cola_tamanio(cola) == 0, "Dada una cola vacia, al pedir el tamaño, devuelve CERO");

  cola_destruir(cola);
}

void dadaUnaColaNoVacia_alPedirElTamanio_devuelveLaCantidadDeElementos()
{
  cola_t *cola = cola_crear();
  int elemento1 = 11;
  int elemento2 = 22;

  cola_encolar(cola, &elemento1);
  cola_encolar(cola, &elemento2);

  pa2m_afirmar(cola_tamanio(cola) == 2, "Dada una cola con dos elementos, al pedir el tamaño, devuelve DOS");

  cola_destruir(cola);
}

void dadaUnaColaVacia_alVerificarSiEstaVacia_devuelveTrue()
{
  cola_t *cola = cola_crear();

  pa2m_afirmar(cola_vacia(cola), "Dada una cola vacia, al preguntar si esta vacia, devuelve TRUE");

  cola_destruir(cola);
}

void dadaUnaColaNoVacia_alVerificarSiEstaVacia_devuelveFalse()
{
  cola_t *cola = cola_crear();
  int elemento1 = 11;
  int elemento2 = 22;

  cola_encolar(cola, &elemento1);
  cola_encolar(cola, &elemento2);

  pa2m_afirmar(!cola_vacia(cola), "Dada una cola con dos elementos, al preguntar si esta vacia, devuelve FALSE");

  cola_destruir(cola);
}

// LISTA

void puedoCrearUnaListaCorrectamente()
{
  lista_t *lista = lista_crear();

  pa2m_afirmar(lista, "La lista se crea correctamente");
  pa2m_afirmar(lista->nodo_inicio == NULL, "La lista se crea con inicio NULL");
  pa2m_afirmar(lista->nodo_fin == NULL, "La lista se crea con fin NULL");
  pa2m_afirmar(lista->cantidad == 0, "La lista se crea con cantidad CERO");

  lista_destruir(lista);
}

void dadaUnaListaVacia_puedoInsertarVariosElemento()
{
  lista_t *lista = lista_crear();
  int elemento1 = 11;
  int elemento2 = 22;

  lista_insertar(lista, &elemento1);
  pa2m_afirmar(lista->nodo_fin->elemento == (void *)&elemento1, "Dada una lista vacia, puedo insertar un elemento");

  lista_insertar(lista, &elemento2);
  pa2m_afirmar(lista->nodo_fin->elemento == (void *)&elemento2, "Dada una lista con un elemento, puedo insertar otro elemento");

  lista_destruir(lista);
}

void dadaUnaListaNoVacia_puedoInsertarEnDeterminadaPosicion()
{
  lista_t *lista = lista_crear();

  int elemento1 = 11;
  int elemento2 = 22;
  int elemento3 = 33;
  int elemento_nuevo = 44;

  lista_insertar(lista, &elemento1);
  lista_insertar(lista, &elemento2);
  lista_insertar(lista, &elemento3);

  lista_insertar_en_posicion(lista, &elemento_nuevo, 1);
  pa2m_afirmar(lista->nodo_inicio->siguiente->elemento == (void *)&elemento_nuevo, "Dada una lista con tres elementos, puedo insertar un elemento en la segunda posicion");

  lista_destruir(lista);
}

void dadaUnaListaNoVacia_alInsertarElementoEnPosicionInvalida_insertaAlFinal()
{
  lista_t *lista = lista_crear();

  int elemento1 = 11;
  int elemento2 = 22;
  int elemento3 = 33;
  int elemento_nuevo = 44;

  lista_insertar(lista, &elemento1);
  lista_insertar(lista, &elemento2);
  lista_insertar(lista, &elemento3);

  lista_insertar_en_posicion(lista, &elemento_nuevo, 7);
  pa2m_afirmar(lista->nodo_fin->elemento == (void *)&elemento_nuevo, "Dada una lista con tres elementos, al insertar un elemento en una posicion invalida, se inserta al final");

  lista_destruir(lista);
}

void dadaUnaListaNoVacia_puedoQuitarLosElementos()
{
  lista_t *lista = lista_crear();

  int elemento1 = 11;
  int elemento2 = 22;

  lista_insertar(lista, &elemento1);
  lista_insertar(lista, &elemento2);

  pa2m_afirmar(lista_quitar(lista) == (void *)&elemento2, "Dada una lista con dos elementos puedo quitar el ultimo");
  pa2m_afirmar(lista_quitar(lista) == (void *)&elemento1, "Dada una lista con un elemento, puedo quitar el unico elemento");

  lista_destruir(lista);
}

void dadaUnaListaNoVacia_puedoQuitarUnaPosicionEspecifica()
{
  lista_t *lista = lista_crear();

  int elemento1 = 11;
  int elemento2 = 22;
  int elemento3 = 33;

  lista_insertar(lista, &elemento1);
  lista_insertar(lista, &elemento2);
  lista_insertar(lista, &elemento3);

  pa2m_afirmar(lista_quitar_de_posicion(lista, 1) == (void *)&elemento2, "Dada una lista con tres elementos, puedo quitar el elemento en la posicion dos");

  lista_destruir(lista);
}

void dadaUnaListaNoVacia_alQuitarDeUnaPosicionInvalida_devuelvoNULL()
{
  lista_t *lista = lista_crear();

  int elemento1 = 11;
  int elemento2 = 22;
  int elemento3 = 33;

  lista_insertar(lista, &elemento1);
  lista_insertar(lista, &elemento2);
  lista_insertar(lista, &elemento3);

  pa2m_afirmar(lista_quitar_de_posicion(lista, 8) == (void *)&elemento3, "Dada una lista con tres elementos, al quitar un elemento en una posicion invalida, se quita del final");

  lista_destruir(lista);
}

void dadaUnaListaVacia_alQuitarUnElemento_devuelvoNULL()
{
  lista_t *lista = lista_crear();

  pa2m_afirmar(!lista_quitar(lista), "Dada una lista vacia, no puedo quitar un elemento");

  lista_destruir(lista);
}

void dadaUnaListaNoVacia_puedoAccederAlPrimeroYAlUltimo()
{
  lista_t *lista = lista_crear();

  int elemento1 = 11;
  int elemento2 = 22;
  int elemento3 = 33;

  lista_insertar(lista, &elemento1);
  lista_insertar(lista, &elemento2);
  lista_insertar(lista, &elemento3);

  pa2m_afirmar(lista_primero(lista) == (void *)&elemento1, "Dada una lista con tres elementos, puedo acceder al primer elemento");
  pa2m_afirmar(lista_ultimo(lista) == (void *)&elemento3, "Dada una lista con tres elementos, puedo acceder al ultimo elemento");

  lista_destruir(lista);
}

void dadaUnaListaVacia_alAccederAlPrimeroYAlUltimo_devuelveNULL()
{
  lista_t *lista = lista_crear();

  pa2m_afirmar(lista_primero(lista) == NULL, "Dada una lista vacia, acceder al primero devuelve NULL");
  pa2m_afirmar(lista_ultimo(lista) == NULL, "Dada una lista vacia, acceder al ultimo devuelve NULL");

  lista_destruir(lista);
}

void dadaUnaListaNoVacia_puedoAccederAUnaPosicionDeterminada()
{
  lista_t *lista = lista_crear();

  int elemento1 = 11;
  int elemento2 = 22;
  int elemento3 = 33;

  lista_insertar(lista, &elemento1);
  lista_insertar(lista, &elemento2);
  lista_insertar(lista, &elemento3);

  pa2m_afirmar(lista_elemento_en_posicion(lista, 1) == (void *)&elemento2, "Dada una lista con tres elementos, puedo acceder al segundo elemento");
  pa2m_afirmar(lista_elemento_en_posicion(lista, 10) == NULL, "Dada una lista con tres elementos, al acceder a una posicion invalida, devuelvo NULL");

  lista_destruir(lista);
}

void dadaUnaListaVacia_alAccederAUnaPosicionDeterminada_devuelveNULL()
{
  lista_t *lista = lista_crear();

  pa2m_afirmar(lista_elemento_en_posicion(lista, 2) == NULL, "Dada una lista vacia, al acceder a una posicion determinda, devuelve NULL");

  lista_destruir(lista);
}

void dadaUnaListaConCuatroElementos_TamanioDevuelveCuatro()
{
  lista_t *lista = lista_crear();

  int elemento1 = 11;
  int elemento2 = 22;
  int elemento3 = 33;
  int elemento4 = 44;

  lista_insertar(lista, &elemento1);
  lista_insertar(lista, &elemento2);
  lista_insertar(lista, &elemento3);
  lista_insertar(lista, &elemento4);

  pa2m_afirmar(lista_tamanio(lista) == 4, "Dada una lista con cuatro elementos, al pedir el tamaño devuelve CUATRO");

  lista_quitar(lista);
  lista_quitar(lista);

  pa2m_afirmar(lista_tamanio(lista) == 2, "Dada una lista con cuatro elementos, luego de quitar dos elementos, al pedir el tamaño, devuelve DOS");

  lista_destruir(lista);
}

void dadaUnaListaVacia_TamanioDevuelveCero()
{
  lista_t *lista = lista_crear();

  pa2m_afirmar(lista_tamanio(lista) == 0, "Dada una lista vacia, al pedir el tamaño, devuelve CERO");

  lista_destruir(lista);
}

void dadaUnaListaVacia_alVerificarSiEstaVacia_devuelveTrue()
{
  lista_t *lista = lista_crear();

  pa2m_afirmar(lista_vacia(lista), "Dada una lista vacia, Al preguntar si esta vacia, devuelve TRUE");

  lista_destruir(lista);
}

void dadaUnaListaNoVacia_alVerificarSiEstaVacia_devuelveFalse()
{
  lista_t *lista = lista_crear();

  int elemento1 = 11;
  int elemento2 = 22;
  int elemento3 = 33;
  int elemento4 = 44;

  lista_insertar(lista, &elemento1);
  lista_insertar(lista, &elemento2);
  lista_insertar(lista, &elemento3);
  lista_insertar(lista, &elemento4);

  pa2m_afirmar(!lista_vacia(lista), "Dada una lista con cuatro elementos, al preguntar si esta vacia, devuelve false");

  lista_destruir(lista);
}

void puedoCrearUnIteradorCorrectamente()
{
  lista_t *lista = lista_crear();
  char a = 'h', b = 'o', c = 'l', d = 'a';

  lista_insertar(lista, &a);
  lista_insertar(lista, &b);
  lista_insertar(lista, &c);
  lista_insertar(lista, &d);

  lista_iterador_t *it = lista_iterador_crear(lista);
  pa2m_afirmar(it, "El iterador de una lista no vacia se crea correctamente");
  pa2m_afirmar(it->corriente == lista->nodo_inicio, "El iterador de una lista no vacia se crea con corriente en el nodo inicial");
  pa2m_afirmar(it->lista == lista, "El iterador de una lista no vacia se crea con la lista especificada");

  lista_iterador_destruir(it);
  lista_destruir(lista);
}

void puedoCrearUnIteradorDeUnaListaVaciaCorrectamente()
{
  lista_t *lista = lista_crear();

  lista_iterador_t *it = lista_iterador_crear(lista);
  pa2m_afirmar(it, "El iterador de una lista vacia se crea correctamente");
  pa2m_afirmar(it->corriente == NULL, "El iterador de una lista vacia se crea con corriente NULL");
  pa2m_afirmar(it->lista == lista, "El iterador de una lista vacia se crea con la lista especificada");

  lista_iterador_destruir(it);
  lista_destruir(lista);
}

void noPuedoCrearUnIteradorDeUnaListaNULL()
{
  lista_t *lista = NULL;

  lista_iterador_t *it = lista_iterador_crear(lista);
  pa2m_afirmar(!it, "El iterador de una lista NULL vale NULL");

  lista_iterador_destruir(it);
  lista_destruir(lista);
}

void dadoUnIteradorDeUnaListaNoVacia_alPreguntarSiTieneSiguiente_devuelveCorrectamente()
{
  lista_t *lista = lista_crear();
  char a = 'h', b = 'o';

  lista_insertar(lista, &a);
  lista_insertar(lista, &b);

  lista_iterador_t *it = lista_iterador_crear(lista);

  pa2m_afirmar(lista_iterador_tiene_siguiente(it), "Dado un interador en el primer elemento de una lista con dos elementos, al preguntar si tiene siguiente, devuelve true");

  it->corriente = it->corriente->siguiente;
  pa2m_afirmar(lista_iterador_tiene_siguiente(it), "Dado un interador en el segundo elemento de una lista con dos elementos, al preguntar si tiene siguiente, devuelve true");

  it->corriente = it->corriente->siguiente;
  pa2m_afirmar(!lista_iterador_tiene_siguiente(it), "Dado un interador en el ultimo elemento (NULL) de una lista con dos elementos, al preguntar si tiene siguiente, devuelve false");

  lista_iterador_destruir(it);
  lista_destruir(lista);
}

void dadoUnIteradorDeUnaListaVacia_alPreguntarSiTieneSiguiente_devuelveFalse()
{
  lista_t *lista = lista_crear();

  lista_iterador_t *it = lista_iterador_crear(lista);

  pa2m_afirmar(!lista_iterador_tiene_siguiente(it), "Dado un interador de una lista vacia, al preguntar si tiene siguiente, devuelve false");

  lista_iterador_destruir(it);
  lista_destruir(lista);
}

void dadoUnIteradorNULL_alPreguntarSiTieneSiguiente_devuelveFalse()
{
  lista_iterador_t *it = NULL;
  pa2m_afirmar(!lista_iterador_tiene_siguiente(it), "Dado un interador NULL, al preguntar si tiene siguiente, devuelve false");
}

void dadoUnIteradorDeUnaListaNoVacia_puedoAvanzarHastaLlegarAlFinal()
{
  lista_t *lista = lista_crear();
  char a = 'h', b = 'o';

  lista_insertar(lista, &a);
  lista_insertar(lista, &b);

  lista_iterador_t *it = lista_iterador_crear(lista);

  pa2m_afirmar(lista_iterador_avanzar(it), "Dado un iterador en el primer elemento de una lista de dos elementos, al avanzar, devuelvo true");
  pa2m_afirmar(!lista_iterador_avanzar(it), "Dado un iterador en el segundo elemento de una lista de dos elementos, al avanzar, devuelvo false");

  lista_iterador_destruir(it);
  lista_destruir(lista);
}

void dadoUnIteradorNULL_noPuedoAvanzar()
{
  lista_iterador_t *it = NULL;
  pa2m_afirmar(!lista_iterador_avanzar(it), "Dado un iterador NULL, no puedo avanzar");
}

void dadoUnIteradorDeUnaListaNoVacia_puedoAccederATodosLosElementos()
{
  lista_t *lista = lista_crear();
  char a = 'h', b = 'o';

  lista_insertar(lista, &a);
  lista_insertar(lista, &b);

  lista_iterador_t *it = lista_iterador_crear(lista);

  pa2m_afirmar(lista_iterador_elemento_actual(it) == (void *)&a, "Dado un iterador en el primer elemento de una lista de dos elementos, puedo acceder al primer elemento");

  it->corriente = it->corriente->siguiente;
  pa2m_afirmar(lista_iterador_elemento_actual(it) == (void *)&b, "Dado un iterador en el segundo elemento de una lista de dos elementos, puedo acceder al segundo elemento");

  it->corriente = it->corriente->siguiente;
  pa2m_afirmar(!lista_iterador_elemento_actual(it), "Dado un iterador en la ultima posicion (NULL) de una lista de dos elementos, acceder a ese elemento devuleve NULL");

  lista_iterador_destruir(it);
  lista_destruir(lista);
}

void dadoUnIteradorDeUnaListaVacia_alAccederASuElementoActual_devuelveNULL()
{
  lista_t *lista = lista_crear();

  lista_iterador_t *it = lista_iterador_crear(lista);

  pa2m_afirmar(!lista_iterador_elemento_actual(it), "Dado un iterador de una lista vacia, al acceder a su elemento actual, devuelve NULL");

  lista_iterador_destruir(it);
  lista_destruir(lista);
}

void dadoUnIteradorNULL_noPuedoAccederASuElementoActual()
{
  lista_iterador_t *it = NULL;

  pa2m_afirmar(!lista_iterador_elemento_actual(it), "Dado un iterador NULL, al acceder a su elemento actual, devuelve NULL");
}

bool acumular_caracteres(void *_elemento, void *_contexto)
{
  int *elemento = _elemento;
  int *contexto = _contexto;

  *contexto += *elemento;

  return *elemento != '.';
}

void dadaUnaListaNoVacia_alAplicarFuncionACadaElemento_devuelveLaCantidadDeElementos()
{
  lista_t *lista = lista_crear();
  int a = 'h', b = 'o', c = 'l', d = 'a';

  lista_insertar(lista, &a);
  lista_insertar(lista, &b);
  lista_insertar(lista, &c);
  lista_insertar(lista, &d);

  int contexto = 0;
  pa2m_afirmar(lista_con_cada_elemento(lista, acumular_caracteres, &contexto) == 4, "Dada una lista con cuatro elementos, Al aplicar una funcion a cada elemento, la cantidad de elementos aplicados es CUATRO");
  pa2m_afirmar(contexto == a + b + c + d, "Dada una lista con cuatro elementos, la funcion se aplica correctamente a cada elemento");

  lista_destruir(lista);
}

void dadaUnaListaNoVacia_alAplicarFuncionACadaElemento_devuelveLACantidadDeElementosHastaPUNTO()
{
  lista_t *lista = lista_crear();
  int a = 'h', b = 'o', c = 'l', d = '.', e = 'a';

  lista_insertar(lista, &a);
  lista_insertar(lista, &b);
  lista_insertar(lista, &c);
  lista_insertar(lista, &d);
  lista_insertar(lista, &e);

  int contexto = 0;
  pa2m_afirmar(lista_con_cada_elemento(lista, acumular_caracteres, &contexto) == 4, "Dada una lista con cinco elementos, Al aplicar una funcion a cada elemento hasta PUNTO (4to), la cantidad de elementos aplicados es CUATRO");
  pa2m_afirmar(contexto == a + b + c + d, "Dada una lista con cinco elementos, la funcion se aplica correctamente a cada elemento hasta PUNTO (4to)");

  lista_destruir(lista);
}

void dadaUnaListaVacia_alAplicarFuncionACadaElemento_devuelveCERO()
{
  lista_t *lista = lista_crear();

  int contexto = 0;
  pa2m_afirmar(lista_con_cada_elemento(lista, acumular_caracteres, &contexto) == 0, "Dada una lista vacia, Al aplicar una funcion a cada elemento devuelve CERO");

  lista_destruir(lista);
}

void dadaUnaListaNULL_alAplicarFuncionACadaElemento_devuelveCERO()
{
  lista_t *lista = NULL;

  char contexto = 0;
  pa2m_afirmar(lista_con_cada_elemento(lista, acumular_caracteres, &contexto) == 0, "Dada una lista NULL, al aplicar una funciona a cada elemento, devuelve CERO");
}

void dadaUnaListaNULL_quitarElementoDevuelveNULL()
{
  lista_t *lista = NULL;

  pa2m_afirmar(!lista_quitar(lista), "Dada una lista NULL, al quitar elemento, devuelve NULL");
}

void dadaUnaListaNULL_insertarElementoDevuelveNULL()
{
  lista_t *lista = NULL;

  int elemento = 3;
  pa2m_afirmar(!lista_insertar(lista, &elemento), "Dada una lista NULL, al insertar a un elemento, devuelve NULL");
}

void dadaUnaListaNULL_accederElementoDevuelveNULL()
{
  lista_t *lista = NULL;

  pa2m_afirmar(!lista_primero(lista), "Dada una lista NULL, al acceder a un elemento, devuelve NULL");
}

void dadaUnaListaNULL_tamanioElementoDevuelveCERO()
{
  lista_t *lista = NULL;

  pa2m_afirmar(lista_tamanio(lista) == 0, "Dada una lista NULL, al pedir el tamaño, devuelve CERO");
}

void dadaUnaListaNULL_alPreguntarSiEstaVacia_DevuelveTRUE()
{
  lista_t *lista = NULL;

  pa2m_afirmar(lista_vacia(lista), "Dada una lista NULL, al verificar si esta vacia, devuelve TRUE");
}

// MAIN

int main()
{

  // PILA

  pa2m_nuevo_grupo("PILA: Creacion");
  puedoCrearUnaPilaCorrectamente();

  pa2m_nuevo_grupo("PILA: Tope");
  dadaUnaPilaVacia_alPedirElTope_devuelveNULL();
  dadaUnaPilaNoVacia_alPedirElTope_devuelveElUltimoElemento();

  pa2m_nuevo_grupo("PILA: Apilar y Desapilar");
  dadaUnaPilaVacia_puedoApilarYDesapilarVariosElementos();
  dadaUnaPilaVacia_alDesapilarUnElemento_devuelveNULL();

  pa2m_nuevo_grupo("PILA: Contenido");
  dadaUnaPilaVacia_alPedirElTamanio_devuelveCero();
  dadaUnaPilaNoVacia_alPedirElTamanio_devuelveLaCantidadDeElementos();
  dadaUnaPilaVacia_alVerificarSiEstaVacia_devuelveTrue();
  dadaUnaPilaNoVacia_alVerificarSiEstaVacia_devuelveFalse();

  // COLA

  pa2m_nuevo_grupo("COLA: Creacion");
  puedoCrearUnaColaCorrectamente();

  pa2m_nuevo_grupo("COLA: Frente");
  dadaUnaColaVacia_alPedirElFrente_devuelveNULL();
  dadaUnaColaNoVacia_alPedirElFrente_devuelveElPrimero();

  pa2m_nuevo_grupo("COLA: Encolar y Desencolar");
  dadaUnaColaVacia_puedoEncolarYDesencolarVariosElementos();
  dadaUnaColaVacia_alDesencolarUnElemento_devuelveNULL();

  pa2m_nuevo_grupo("COLA: Contenido");
  dadaUnaColaVacia_alPedirElTamanio_devuelveCero();
  dadaUnaColaNoVacia_alPedirElTamanio_devuelveLaCantidadDeElementos();
  dadaUnaColaVacia_alVerificarSiEstaVacia_devuelveTrue();
  dadaUnaColaNoVacia_alVerificarSiEstaVacia_devuelveFalse();

  // LISTA

  pa2m_nuevo_grupo("LISTA: Creacion");
  puedoCrearUnaListaCorrectamente();

  pa2m_nuevo_grupo("LISTA: Insertar");
  dadaUnaListaVacia_puedoInsertarVariosElemento();
  dadaUnaListaNoVacia_puedoInsertarEnDeterminadaPosicion();
  dadaUnaListaNoVacia_alInsertarElementoEnPosicionInvalida_insertaAlFinal();

  pa2m_nuevo_grupo("LISTA: Quitar");
  dadaUnaListaNoVacia_puedoQuitarLosElementos();
  dadaUnaListaNoVacia_puedoQuitarUnaPosicionEspecifica();
  dadaUnaListaNoVacia_alQuitarDeUnaPosicionInvalida_devuelvoNULL();
  dadaUnaListaVacia_alQuitarUnElemento_devuelvoNULL();

  pa2m_nuevo_grupo("LISTA: Acceder");
  dadaUnaListaNoVacia_puedoAccederAlPrimeroYAlUltimo();
  dadaUnaListaVacia_alAccederAlPrimeroYAlUltimo_devuelveNULL();
  dadaUnaListaNoVacia_puedoAccederAUnaPosicionDeterminada();
  dadaUnaListaVacia_alAccederAUnaPosicionDeterminada_devuelveNULL();

  pa2m_nuevo_grupo("LISTA: Contenido");
  dadaUnaListaConCuatroElementos_TamanioDevuelveCuatro();
  dadaUnaListaVacia_TamanioDevuelveCero();
  dadaUnaListaVacia_alVerificarSiEstaVacia_devuelveTrue();
  dadaUnaListaNoVacia_alVerificarSiEstaVacia_devuelveFalse();

  pa2m_nuevo_grupo("LISTA: NULL");
  dadaUnaListaNULL_insertarElementoDevuelveNULL();
  dadaUnaListaNULL_quitarElementoDevuelveNULL();
  dadaUnaListaNULL_accederElementoDevuelveNULL();
  dadaUnaListaNULL_tamanioElementoDevuelveCERO();
  dadaUnaListaNULL_alPreguntarSiEstaVacia_DevuelveTRUE();

  // ITERADOR

  pa2m_nuevo_grupo("ITERADOR: Creacion");
  puedoCrearUnIteradorCorrectamente();
  puedoCrearUnIteradorDeUnaListaVaciaCorrectamente();
  noPuedoCrearUnIteradorDeUnaListaNULL();

  pa2m_nuevo_grupo("ITERADOR: Tiene Siguiente");
  dadoUnIteradorDeUnaListaNoVacia_alPreguntarSiTieneSiguiente_devuelveCorrectamente();
  dadoUnIteradorDeUnaListaVacia_alPreguntarSiTieneSiguiente_devuelveFalse();

  pa2m_nuevo_grupo("ITERADOR: Avanzar");
  dadoUnIteradorDeUnaListaNoVacia_puedoAvanzarHastaLlegarAlFinal();

  pa2m_nuevo_grupo("ITERADOR: Elemento Actual");
  dadoUnIteradorDeUnaListaNoVacia_puedoAccederATodosLosElementos();
  dadoUnIteradorDeUnaListaVacia_alAccederASuElementoActual_devuelveNULL();

  pa2m_nuevo_grupo("ITERADOR: Funcion a cada elemento");
  dadaUnaListaNoVacia_alAplicarFuncionACadaElemento_devuelveLaCantidadDeElementos();
  dadaUnaListaNoVacia_alAplicarFuncionACadaElemento_devuelveLACantidadDeElementosHastaPUNTO();
  dadaUnaListaVacia_alAplicarFuncionACadaElemento_devuelveCERO();

  pa2m_nuevo_grupo("ITERADOR: NULL");
  dadoUnIteradorNULL_alPreguntarSiTieneSiguiente_devuelveFalse();
  dadoUnIteradorNULL_noPuedoAvanzar();
  dadoUnIteradorNULL_noPuedoAccederASuElementoActual();
  dadaUnaListaNULL_alAplicarFuncionACadaElemento_devuelveCERO();

  return pa2m_mostrar_reporte();
}
