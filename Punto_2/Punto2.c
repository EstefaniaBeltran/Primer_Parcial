#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estructura  para cada estudiante
typedef struct {
    char *nombre;
    char *apellido;
    unsigned int edad : 7; 
    unsigned int id;
    char **materias;
    float *notas;
    int num_materias;
} Estudiante;

// Función para crear un estudiante dinámicamente
Estudiante crearEstudiante(
    const char *nombre,
    const char *apellido,
    unsigned int edad,
    unsigned int id,
    char **materias,
    float *notas,
    int num_materias
) {
    Estudiante e;

    // Asignar memoria exacta para nombre y apellido
    e.nombre = (char *)malloc(strlen(nombre) + 1);
    strcpy(e.nombre, nombre);

    e.apellido = (char *)malloc(strlen(apellido) + 1);
    strcpy(e.apellido, apellido);

    e.edad = edad;
    e.id = id;
    e.num_materias = num_materias;

    // Reservar memoria para materias y copiar cada nombre
    e.materias = (char **)malloc(num_materias * sizeof(char *));
    for (int i = 0; i < num_materias; i++) {
        e.materias[i] = (char *)malloc(strlen(materias[i]) + 1);
        strcpy(e.materias[i], materias[i]);
    }

    // Reservar memoria para las notas
    e.notas = (float *)malloc(num_materias * sizeof(float));
    for (int i = 0; i < num_materias; i++) {
        e.notas[i] = notas[i];
    }

    return e;
}

// Función para mostrar la información de un estudiante
void mostrarEstudiante(Estudiante e) {
    printf("\nNombre: %s %s", e.nombre, e.apellido);
    printf("\nEdad: %u", e.edad);
    printf("\nID: %u", e.id);
    printf("\nMaterias y notas:\n");
    for (int i = 0; i < e.num_materias; i++) {
        printf("  - %s: %.1f\n", e.materias[i], e.notas[i]);
    }
    printf("---------------------------\n");
}

// Función para liberar la memoria ocupada por un estudiante
void liberarEstudiante(Estudiante *e) {
    free(e->nombre);
    free(e->apellido);

    for (int i = 0; i < e->num_materias; i++) {
        free(e->materias[i]);
    }
    free(e->materias);
    free(e->notas);
}

// Compactar memoria al eliminar un estudiante
void eliminarEstudiante(Estudiante **lista, int *total, int indice) {
    liberarEstudiante(&(*lista)[indice]);

    for (int i = indice; i < (*total) - 1; i++) {
        (*lista)[i] = (*lista)[i + 1];
    }

    *lista = (Estudiante *)realloc(*lista, ((*total) - 1) * sizeof(Estudiante));
    (*total)--;
}

// Calcular memoria usada por estructuras y datos dinámicos
size_t calcularMemoriaDinamica(Estudiante *lista, int total) {
    size_t memoria = 0;
    for (int i = 0; i < total; i++) {
        memoria += strlen(lista[i].nombre) + 1;
        memoria += strlen(lista[i].apellido) + 1;
        for (int j = 0; j < lista[i].num_materias; j++) {
            memoria += strlen(lista[i].materias[j]) + 1;
        }
        memoria += lista[i].num_materias * sizeof(float);
    }
    return memoria;
}

// Mostrar estadísticas del sistema
void mostrarEstadisticas(Estudiante *lista, int total, int capacidad) {
    size_t memoria_estudiantes = total * sizeof(Estudiante);
    size_t memoria_total = capacidad * sizeof(Estudiante);
    size_t memoria_dinamica = calcularMemoriaDinamica(lista, total);
    float eficiencia = ((float)memoria_estudiantes / memoria_total) * 100.0;

    printf("\n-----Estadisticas del sistema-----\n");
    printf("Estudiantes registrados: %d\n", total);
    printf("Capacidad del sistema: %d\n", capacidad);
    printf("Memoria usada por estudiantes: %zu bytes\n", memoria_estudiantes);
    printf("Memoria total asignada: %zu bytes\n", memoria_total);
    printf("Memoria dinámica (strings + calificaciones): %zu bytes\n", memoria_dinamica);
    printf("Eficiencia de memoria: %.2f%%\n", eficiencia);
}

int main() {
    int capacidad = 4;
    int total = 2;

    // Creamos array dinámico para 4 estudiantes (capacidad inicial)
    Estudiante *lista = (Estudiante *)malloc(capacidad * sizeof(Estudiante));

    // Datos para Estefanía Beltrán
    char *materias1[] = {"Español", "Sociales", "Programación"};
    float notas1[] = {3.5, 2.5, 4.0};
    lista[0] = crearEstudiante("Estefania", "Beltran", 18, 1014481086, materias1, notas1, 3);

    // Datos para Carol Arenas
    char *materias2[] = {"Español", "Sociales", "Programación"};
    float notas2[] = {4.2, 3.5, 2.8};
    lista[1] = crearEstudiante("Carol", "Arenas", 11, 1014482451, materias2, notas2, 3);

    // Mostramos la lista completa
    printf("\n----Lista de Estudiantes-----\n");
    for (int i = 0; i < total; i++) {
        mostrarEstudiante(lista[i]);
    }

    // Mostrar estadísticas ANTES de eliminar a Carol
    mostrarEstadisticas(lista, total, capacidad);

    // Eliminamos a Carol para demostrar compactación de memoria
    printf("\n>>> Eliminando a Carol...\n");
    eliminarEstudiante(&lista, &total, 1);

    // Mostramos lista actualizada
    printf("\n-----Lista Actualizada-----\n");
    for (int i = 0; i < total; i++) {
        mostrarEstudiante(lista[i]);
    }

    // Mostrar estadísticas DESPUÉS de eliminar a Carol
    mostrarEstadisticas(lista, total, capacidad);

    // Liberamos memoria final
    for (int i = 0; i < total; i++) {
        liberarEstudiante(&lista[i]);
    }
    free(lista);

    return 0;
}
