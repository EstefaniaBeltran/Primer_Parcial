**Yeimy Estefanía Beltrán Sandoval**
# PRIMER PARCIAL - PARADIGMAS DE PROGRAMACIÓN 
# Punto 1
**Análisis Comparativo entre Programación Imperativa y Declarativa**

En el desarrollo del ejercicio se implementaron dos enfoques de programación diferentes para resolver el mismo problema: ordenar una lista de estudiantes con la nota del parcial final de forma descendente y, en caso de tener la misma nota, en orden alfabético. Aunque ambos métodos alcanzan el mismo resultado, la forma de lograrlo es distinta y esto se refleja en la claridad, la abstracción, el manejo de datos, el mantenimiento y la eficiencia del código.

En la solución imperativa, el código describe de manera explícita cada paso que debe ejecutarse para alcanzar el objetivo. Se utiliza un algoritmo de burbuja que recorre la lista, compara elementos y los intercambia cuando es necesario. Este enfoque brinda un control total sobre el proceso, pero genera un código más extenso y detallado. Además, como se manipula el contenido de la lista durante las iteraciones, se trabaja directamente con la mutabilidad de las estructuras de datos y se mantiene un estado que va cambiando en cada paso del algoritmo.

Por otro lado, la solución declarativa se centra en expresar qué se quiere lograr, delegando al lenguaje el cómo hacerlo. Gracias a la función integrada `sorted()` de Python y la expresión `lambda`, el código se reduce a una sola línea, logrando un resultado inmediato y claro. Además, al generar una nueva lista ordenada, se favorece la inmutabilidad y se evita modificar los datos originales.

En términos de mantenibilidad, el enfoque declarativo es más flexible: cambiar el criterio de ordenamiento requiere solo ajustar la función key de sorted(), mientras que en la solución imperativa habría que modificar la lógica del algoritmo.

Respecto a la eficiencia, la diferencia es significativa. El enfoque imperativo implementa un algoritmo de burbuja, cuyo desempeño es poco óptimo para listas grandes, ya que el número de operaciones necesarias crece proporcionalmente al cuadrado del tamaño de la lista. Esto significa que, a medida que aumentan los datos, el tiempo de ejecución aumenta muy rápido.

Por el contrario, la función sorted() utilizada en el enfoque declarativo implementa Timsort, un algoritmo híbrido mucho más eficiente que realiza un número de operaciones considerablemente menor, incluso cuando se trabaja con listas extensas. lo que ofrece un rendimiento mucho mejor sin necesidad de que el programador intervenga en los detalles técnicos.

En conclusión, aunque ambos enfoques cumplen con el objetivo propuesto, sus características los hacen más adecuados para contextos distintos. La programación imperativa es útil para comprender en detalle cómo funciona un algoritmo y tener control absoluto sobre cada paso, pero su mantenimiento y rendimiento pueden verse limitados. La programación declarativa, en cambio, permite escribir código más claro, compacto y eficiente, lo que la convierte en una opción más conveniente en entornos reales donde la legibilidad, la mantenibilidad y la optimización son prioritarias.


# Punto 2

**Funcionamiento del programa**

El programa implementa un sistema de gestión de estudiantes diseñado para optimizar el uso de memoria utilizando asignación dinámica. Cada estudiante tiene un registro con su nombre, apellido, edad, número de identificación, materias y notas. Para evitar desperdicio de memoria, el programa solo reserva el espacio estrictamente necesario para cada dato mediante el uso de las funciones malloc, realloc y free.

Para mejorar la eficiencia, la estructura de datos utiliza bitfields en el campo de la edad, reduciendo el tamaño ocupado por cada registro. Además, tanto los nombres, apellidos y materias como las notas se almacenan en memoria dinámica, ajustando el tamaño según su longitud real.

El funcionamiento del sistema se organiza en diferentes etapas, utilizando funciones específicas para cada tarea:

 1. Creación de registros dinámicos → crearEstudiante()

Cuando se agrega un nuevo estudiante, la función crearEstudiante():

* Asigna memoria dinámica para el nombre y apellido según su longitud real.
* Reserva espacio exacto para cada materia utilizando punteros a cadenas.
* Asigna un arreglo dinámico para las calificaciones.
* Devuelve un registro completo del estudiante con toda la información almacenada eficientemente.

De esta forma, si un estudiante tiene tres materias y su nombre ocupa 10 caracteres, el programa solo utiliza la memoria necesaria para esos datos.

2. Visualización de estudiantes enumerados → mostrarEstudiante()

Para que la información sea clara y fácil de interpretar, el programa utiliza la función mostrarEstudiante(), que muestra todos los datos del estudiante de forma ordenada

3. Cálculo de estadísticas de memoria → mostrarEstadisticas()

El sistema incluye la función mostrarEstadisticas(), que calcula y muestra:

* Cantidad de estudiantes registrados.
* Memoria total utilizada por todos los registros.
* Consumo promedio por estudiante.

Estas estadísticas se muestran antes y después de eliminar estudiantes, lo que permite verificar que el sistema libera correctamente la memoria y evita fugas.

4. Eliminación de estudiantes y compactación → eliminarEstudiante()

Cuando se elimina un estudiante, la función eliminarEstudiante():

1. Libera la memoria dinámica asociada a su nombre, apellido, materias y notas usando free.
2. Compacta la lista moviendo los registros restantes para que no queden espacios vacíos.
3. Ajusta el tamaño del arreglo de estudiantes con realloc, reduciendo el consumo de memoria.

Después de esta operación, la numeración de estudiantes se actualiza automáticamente y las estadísticas reflejan los nuevos valores, confirmando que no hay desperdicio de memoria.

5. Conclusión 

El programa combina eficiencia en memoria con claridad en la visualización y gestión dinámica de registros.
Las funciones principales que garantizan su funcionamiento son:

* crearEstudiante() → crea y almacena registros dinámicamente.
* mostrarEstudiante() → visualiza los datos de cada estudiante.
* mostrarEstadisticas() → calcula la memoria usada y su eficiencia.
* eliminarEstudiante() → libera memoria y compacta los registros.

Gracias a la utilización de malloc, free y realloc, el programa gestiona de forma controlada y eficiente el espacio de memoria, cumpliendo con todos los requisitos solicitados.

# Punto 3

-Codigo original de Haskell

```haskell
promedio xs = realToFrac (sum xs) / genericLength xs
main :: IO ()
main = do
    putStrLn "Ingrese una lista de números separados por espacios:"
    entrada <- getLine
    let numeros = map read (words entrada) :: [Double]
    if null numeros
        then putStrLn "La lista está vacía, no se puede calcular el promedio."
        else putStrLn $ "El promedio es: " ++ show (promedio numeros)
```
**Solución** 

$$
promedio(L) = \frac{suma(L)}{longitud(L)}
$$


En notación de cálculo lambda se puede expresar de forma simplificada como:

$$
\lambda L . \dfrac{foldr( + )\ 0L}{length\ L}
$$

**Funcionamiento**
- λ L. define una función que recibe una lista L.
-  foldr (+) 0 L obtiene la suma de los elementos.
-  Length L obtiene el tamaño de la lista.
-  La división representa el promedio

**Aplicación en Haskell** 

1. Lambda en `promedio`: La función `promedio` está definida usando una lambda `\xs -> ...`, donde `xs` es la lista de números. En este caso, se utiliza `foldr (+) 0 xs` para calcular la suma de los elementos de la lista, y `fromIntegral (length xs)` para obtener la longitud de la lista convertida a tipo `Double` (usando `fromIntegral` para evitar problemas de tipos).

2. Main: El `main` sigue siendo el mismo que antes. Solicita al usuario que ingrese una lista de números separados por espacios, los lee, los convierte a tipo `Double` y luego calcula el promedio usando la función `promedio`.
