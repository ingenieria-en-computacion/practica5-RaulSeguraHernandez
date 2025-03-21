#include "stack.h"

/**
 * Crea una nueva pila vacía y la devuelve.
 * 
 * @param len valor que indica cuantos elementos se pueden guardar en la pila
 * @return Una nueva pila vacía. Si la creación falla, el estado de la cola es inválido.
 * @details Esta función inicializa una pila vacía. 
 *          Asigna memoria dinámica a data mediante malloc con un número de elementos igual a len
 */
Stack stack_create(int len){
    Stack s;
    s.data = (Data*)malloc(sizeof(Data)*len);
    if (s.data==NULL){
        printf("No se pudo realizar la creación de la pila\n");
        return s;
    }
    s.top = -1;
    return s;
}

/**
 * Inserta un elemento en la parte superior de la pila.
 * 
 * @param s Referencia a la pila donde se insertará el elemento.
 * @param d Dato que se insertará en la pila.
 * @details Esta función añade el dato `d` en la parte superior de la pila. Si la pila está llena, 
 *          la función no realiza ninguna operación.
 */
void stack_push(Stack* s, Data d){
    if (s->top+1==(sizeof(s->data)/sizeof(Data))){
        s->data = (Data*)realloc(s->data,sizeof(s->data)+sizeof(Data));
        if (s->data==NULL){
            printf("hubo un error al apilar \n");
            return;
        }
    }
    s->data[s->top+1]=d;
    s->top++;
    return;
}

/**
 * Elimina y devuelve el elemento en la parte superior de la pila.
 * 
 * @param s Referencia a la pila de la cual se eliminará el elemento.
 * @return El dato que estaba en la parte superior de la pila. Si la pila está vacía 
 *         devuelve un valor que indica error (por ejemplo, -1 o un valor predeterminado).
 * @details Esta función elimina el elemento en la parte superior de la pila y lo devuelve.
 *          Si la pila está vacía, no se realiza ninguna operación y se devuelve un valor de error.
 */
Data stack_pop(Stack* s){
    if((s==NULL) ||(stack_is_empty(s)) ){
        printf("hubo un error");
        return  -1;
    }
    int temp = s->data[s->top];
    s->top--;
    return temp;
}

/**
 * Verifica si la pila está vacía.
 * 
 * @param s Referencia a la pila que se desea verificar.
 * @return 1 si la pila está vacía, 0 si no lo está. Si el puntero `s` es NULL, devuelve -1.
 * @details Esta función comprueba si la pila no contiene elementos. Es útil para evitar operaciones
 *          como `stack_pop` en una pila vacía.
 */
int stack_is_empty(Stack* s){
    if(s==NULL){
        printf("pila inválida\n");
        return -1;
    }
    if (s->top==-1){
        return 1;
    }
    return 0;
}

/**
 * Vacía la pila, eliminando todos sus elementos.
 * 
 * @param s Referencia a la pila que se desea vaciar.
 * @details Esta función hace que top sea igual a -1
 */
void stack_empty(Stack* s){
        for (int i = s->top; i!=-1 ; i--){
            stack_pop(s);
        }
}

/**
 * Elimina data y libera la memoria asociada.
 * 
 * @param s Referencia a la pila que se desea liberar la memoria de data
 * @details Esta función libera la memoria asignada dinámicamente para data dentro de la pila
 */
void stack_delete(Stack *s){
    stack_empty(s);
    free(s->data);
    s->data = NULL;
    s=NULL;
}

/**
 * Imprime los elementos de la pila.
 * 
 * @param s Referencia a la pila que se desea imprimir.
 * @details Esta función imprime los elementos de la pila en orden, desde la parte superior
 *          hasta la base. Si la pila está vacía la función imprime
 *          un mensaje indicando que la pila está vacía o es inválida. La salida se dirige a
 *          la salida estándar (stdout).
 */
void stack_print(Stack *s){
    if(stack_is_empty(s)){
        printf("la pila está vacía\n");
        return;
    }
    for (int i = s->top; i!=-1 ; i--){
        printf("%d ",stack_pop(s));
    }
}