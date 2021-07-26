# SisOp_TP2_Grupo3_FIUBA
75.08 Sistemas Operativos - TP 2 - Cabinas de Entretenimiento

## Integrantes:

- 96722 - Bogovic, Federico Ezequiel
- 98541 - Zambelli Tello, Brian
- 100752 - Parodi, Joaquin

## Compilacion y makefile
Es necesario ejecutar el comando

`Make all` 

para la correcta compilacion del codigo. En caso de que se quieran borrar los ejecutables, se utiliza el siguiente comando: 

`Make clean` 

Esto es posible gracias al archivo Makefile creado, por tanto, estos comandos deben ejecutarse en la localizacion de dicho archivo.

## Modo de uso

### Creacion de Otaku/Gotico
Para la creacion de una instancia de cualquiera de los dos grupos, es necesario ejecutar:

Para gotico:

`./espera gotico`

Para otaku:

`./espera otaku`

En ambos casos, es necesaria una posterior confirmacion con el ingreso de cualquier caracter.
Una vez que se cumpla cualquiera de las siguientes dos condiciones:

1- Hay dos instancias de otakus y dos instancias de goticos
2- Hay cuatro instancias de otakus o cuatro instancias de goticos

El proceso principal finalizara a las instancias que cumplan la condicion.

### Finalizacion
Una vez terminada la simulacion de procesos, se recomienda la ejecucion de 

`./libera`

para la eliminacion de cualquier archivo basura generado producto del manejo de memoria compartida
