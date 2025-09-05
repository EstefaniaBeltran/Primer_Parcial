
#Lista de estudiantes con sus notas
estudiantes = [
    ("Juan", 3.4),
    ("Ana",4.5), 
    ("Daniela", 2.3),
    ("Marta",4.5 ),
    ("Laura",4.8),
    ("Carlos", 3.9)
    ]

#Mostramos la lista original
print("\n--------LISTA-------")
for nombre, nota in estudiantes:
    print(f"{nombre}: {nota}")

# Paradigma Imperativo 

def ordenar_imperativo(lista):
    lista = lista[:]  # copiar para no modificar el original
    n = len(lista)

    
    for i in range(n - 1):
        for j in range(n - i - 1):
            # Comparar por nota
            if lista[j][1] < lista[j + 1][1]:
                lista[j], lista[j + 1] = lista[j + 1], lista[j]
            # Si las notas son iguales, ordenar alfabéticamente por nombre
            elif lista[j][1] == lista[j + 1][1] and lista[j][0] > lista[j + 1][0]:
                lista[j], lista[j + 1] = lista[j + 1], lista[j]
    return lista

ordenada_imperativa = ordenar_imperativo(estudiantes)

print("\n--------ORDEN IMPERATIVO -------")
for nombre, nota in ordenada_imperativa:
    print(f"{nombre}: {nota}")


#Paradgma Declarativo

# Con la función sorted y una función lambda para definir el criterio de ordenamiento

ordenada_declarativa = sorted(
    estudiantes,
    key=lambda x: (-x[1], x[0])  # Primero ordenar por nota descendente, luego por nombre ascendente
)

print("\n--------ORDEN DECLARATIVO -------")
for nombre, nota in ordenada_declarativa:
    print(f"{nombre}: {nota}")
