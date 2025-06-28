# cpp-cell-simulation
Simulation of a animal cell on C++

Este ejemplo ilustra poderosamente por qué se inventaron los punteros inteligentes: automatizan este proceso de new/delete, eliminan la necesidad de escribir destructores para este fin y previenen errores de copia, haciendo el código más seguro y fácil de escribir.

Concepto Clave: Composición
En este ejemplo, una Cell (célula) no es un Nucleus (núcleo), sino que tiene un Nucleus. Esta relación de "tiene un/a" se modela mediante la composición, donde una clase (la contenedora, Cell) tiene como miembros a instancias de otras clases (los componentes, como Nucleus, Mitochondrion, etc.).

Esto nos permite construir objetos complejos a partir de partes más simples y reutilizables, reflejando de manera muy natural las relaciones del mundo real.

A continuación, te presento el código separado en sus respectivos archivos .hpp (declaraciones) y .cpp (implementaciones), junto con un main.cpp para probarlo.

Cuando gestionamos la memoria manualmente con punteros "crudos" (*), nos volvemos responsables de tres operaciones críticas, conocidas como la "Regla de los Tres" (que en C++ moderno se expande a la "Regla de los Cinco"):

** *1 Destructor: Debemos liberar la memoria que reservamos.

** *2 Constructor de Copia: Debemos definir cómo se copia un objeto que maneja memoria.

** *3 Operador de Asignación de Copia: Debemos definir cómo se asigna un objeto a otro.

Para este ejemplo didáctico, en lugar de implementar una lógica de copia compleja (copia profunda), haremos algo más seguro y común: deshabilitaremos la copia. Esto evita problemas como que dos objetos Cell apunten y luego intenten borrar la misma memoria.
