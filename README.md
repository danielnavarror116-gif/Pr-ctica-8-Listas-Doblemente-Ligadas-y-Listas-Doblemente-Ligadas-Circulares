# Pr-ctica-8-Listas-Doblemente-Ligadas-y-Listas-Doblemente-Ligadas-Circulares

Preguntas (A)
1. ¿Por qué es más fácil eliminar un nodo intermedio en una lista doblemente ligada que en una lista simple?
  Porque cada nodo tiene dos punteros: anterior y siguiente

2. ¿Qué sucede si se olvida actualizar alguno de los punteros anterior o siguiente?
  La estructura se rompe y la lista deja de ser confiable.

3. ¿En qué escenarios prácticos se usa una lista doblemente ligada?
  Se usa cuando se necesita recorrer en ambos sentidos o eliminar e insertar en posiciones intermedias de forma eficiente.

Preguntas (B)
1. ¿Qué diferencia hay entre una lista doblemente ligada y una circular doblemente ligada?
  En la doblemente ligada normal, el primer nodo tiene anterior = NULL y el último nodo tiene siguiente = NULL.
  En cambio en la doblemente ligada circular, el primer nodo apunta al último en anterior, el último nodo apunta al primero en siguiente y no existen punteros NULL

2. ¿Qué errores pueden causar ciclos infinitos al recorrer una lista circular?
  No detener el recorrido cuando actual regresa al nodo inicial, olvidar actualizar alguno de los punteros durante una inserción o eliminación, provocando que el recorrido nunca regrese al inicio, etc.
  
3. ¿Qué tipo de aplicaciones reales usan este tipo de listas (por ejemplo, reproductores multimedia, navegación en historial, juegos)?
   Normalmente plataformas digitales de musica, juegos virtuales en el q se usan turnos, etc.
