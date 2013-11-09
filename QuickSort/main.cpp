#include <functional>
#include <algorithm>
#include <iterator>

#include <iostream>
#include <stdio.h>
#include <stdlib.h>

#include <iostream>

using namespace std;

// Función para dividir el array y hacer los intercambios
int divide(int *array, int start, int end) {
    int left;
    int right;
    int pivot;
    int temp;
    
    pivot = array[start];
    left = start;
    right = end;
    
    // Mientras no se cruzen los índices
    while (left < right) {
        while (array[right] > pivot) {
            right--;
        }
        
        while ((left < right) && (array[left] <= pivot)) {
            left++;
        }
        
        // Si todavía no se cruzan los indices seguimos intercambiando
        if (left < right) {
            temp = array[left];
            array[left] = array[right];
            array[right] = temp;
        }
    }
    
    // Los índices ya se han cruzado, ponemos el pivot en el lugar que le corresponde
    temp = array[right];
    array[right] = array[start];
    array[start] = temp;
    
    // La nueva posición del pivot
    return right;
}

// Función recursiva para hacer el ordenamiento
void quicksort(int *array, int start, int end)
{
    int pivot;
    
    if (start < end) {
        pivot = divide(array, start, end);
        
        // Ordeno la lista de los menores
        quicksort(array, start, pivot - 1);
        
        // Ordeno la lista de los mayores
        quicksort(array, pivot + 1, end);
    }
}

void llenarArregloRand(int array[],int largo){
    
    
    for (int i=0; i<largo; i++) {
        array[i]=rand()%100;
    }

}

void imprimirArreglo(int array[],int largo){
    
    for (int i=0; i<largo; i++) {
        cout<<array[i]<<" | ";
    }
    cout<<endl<<endl;
    
    
}
int main(){
    int const MAX = 100;
    int arraySize;
    clock_t start_time;
    clock_t final_time;
    double total_time;
    
    
    cout << "Ingresa tamanyo: " << endl;
    cin >> arraySize;
    cout<<"------------------------------------------------------------------------"<<endl;
    
    int a[arraySize];
    
    
    // Para que el rand no genere siempre los mismos números, utilizando la hora del sistema
    srand(time(0));
    
    // Para generar enteros aleatorios usamos rand()
    llenarArregloRand(a,arraySize);
    //imprimirArreglo(a,arraySize);
  
   
    cout<<"------------------------------------------------------------------------"<<endl;
    cout<<"Cantidad de Digitos : "<<arraySize<<endl;
    cout<<"QuickSort -> Arreglo Desordenado "<<endl;
    start_time = clock();
    quicksort(a, 0, arraySize - 1);
    
    final_time = clock();
    total_time = ((double)(final_time - start_time)) / CLOCKS_PER_SEC;
    
    printf("Tiempo de ejecución : %lf segundos \n", total_time);
    //imprimirArreglo(a,arraySize);
     cout<<"                   -------------------------"<<endl;
    
    cout<<"QuickSort -> Arreglo Ordenado  "<<endl;
    start_time = clock();
    quicksort(a, 0, arraySize - 1);
    
    final_time = clock();
    total_time = ((double)(final_time - start_time)) / CLOCKS_PER_SEC;
    
    printf("Tiempo de ejecución : %lf segundos \n", total_time);
    //imprimirArreglo(a,arraySize);
    cout<<"------------------------------------------------------------------------"<<endl;
    cout << endl << endl;
    
    return 0;
}