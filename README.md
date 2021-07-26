# SisOp_TP2_Grupo3_FIUBA
75.08 Sistemas Operativos - TP 2 - Cabinas de Entretenimiento

## Integrantes:

- 96722 - Bogovic, Federico Ezequiel
- 98541 - Zambelli Tello, Brian
- 100752 - Parodi, Joaquin

## Compilacion y makefile
Es necesario ejecutar el comando

`make all` 

para la correcta compilacion del codigo. En caso de que se quieran borrar los ejecutables, se utiliza el siguiente comando: 

`make clean` 

Esto es posible gracias al archivo Makefile creado, por tanto, estos comandos deben ejecutarse en la localizacion de dicho archivo.

El output serán dos ejecutables (espera y libera)

## Modo de uso

### Creacion de Otaku/Gotico
Para la creacion de una instancia de cualquiera de los dos grupos, es necesario ejecutar:

Para gotico:

`./espera gotico`

Para otaku:

`./espera otaku`

De esta manera se ingresa a la sala de espera.
Una vez que se cumpla cualquiera de las siguientes tres condiciones:

- Hay dos instancias de otakus y dos instancias de goticos (sala "mixta")
- Hay cuatro instancias de otakus (sala "otaku")
- Hay cuatro instancias de goticos (sala "gotica")


Se emulará la creacion de una cabina finalizando las instancias que cumplan, dandolos como que ingresaron a la misma informando a qué número de sala ingresaron y de qué tipo es.

### Finalizacion
Una vez terminada la simulacion de procesos, se recomienda la ejecucion del comando:

`./libera`

para la eliminacion de cualquier archivo generado producto del manejo de memoria compartida.
