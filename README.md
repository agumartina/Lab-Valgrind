FACULTAD DE CIENCIAS EXACTAS, FÍSICA Y NATURALES | UNIVERSIDAD NACIONAL DE CÓRDOBA
### Sistemas Operativos I
# Lab-Valgrind
## Objetivo
El objetivo de este laboratorio es que el estudiante se familiarice con la herramienta de análisis dinámico Valgrind.

## Problema
Se provee de un programa escrito en C el cual utiliza unas librerías __custom__ de listas, que estan dentro de la carpeta **src/** del presente repositorio. 

El mismo posee algunos errores de memoria, que utilizando las herramientas de Valgrind ustedes deben analizar, detectar y corrregir.

Para ello deben ejecutar Valgrind con las siguientes flags

```Bash
valgrind --leak-check=full --log-file=valgrind.txt --show-leak-kinds=definite,indirect ./main
```


## Entrega
Se debe entregar
- El codigo fixed
- Documentación que explique lo realizado

## Ayudas
+ [Valgrind Manual](https://www.valgrind.org/docs/manual/valgrind_manual.pdf)

