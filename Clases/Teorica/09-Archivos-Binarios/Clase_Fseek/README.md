## Clase de **fseek** para la materia Algoritmos y Programación 1, curso Méndez.
<br>
<br>

### [fseek](https://man7.org/linux/man-pages/man3/fseek.3.html) es una función perteneciente a la biblioteca estándar de C.
Es la herramienta que nos da el sistema para poder acceder a archivos de forma aleatoria.
### Antes de arrancar, una serie de aclaraciones : 
1. En este curso vamos a utilizar [fseek](https://man7.org/linux/man-pages/man3/fseek.3.html) para trabajar exclusivamente con archivos binarios, esto no quiere decir que no sea valido para otro tipos de formatos.
2. Esta función pertenece a una familia de funciones para manejar accesos aleatorios a archivos, entre las que se encuentran  :  
    * fseek()
    * rewind()
    * ftell()
    * fgetpos()
    * fsetpos()

    En este curso vamos a trabajar solo con las dos primeras. Para el que quiera indagar mas le recomendamos que lea las respectivas paginas de manual.
3. Si en un hipotético examen final sienten la necesidad de usar una de estas funciones que no sea ni ***fseek*** ni ***rewind***, preguntar en el momento si esta permitido.
4. En base a ***fseek*** y ***fteel*** se pueden implementar todas las otras funciones. 


### Vamos a lo importante, que hace fseek? 

Como bien dijimos es una herramienta para poder acceder a archivos de manera aleatoria. Que mejor para ver que hace que leer la pagina de manual? Los invito a que escriban en su terminal  "`man 3 fseek`".

Obtenemos una firma : 

 ```c
 int fseek(FILE *stream, long offset, int whence);
```

Una descripción :

```
The  fseek()  function  sets  the file position indicator for the stream pointed to by stream.  The new position, measured in
bytes, is obtained by adding offset bytes to the position specified by whence.  
If whence is set to  SEEK_SET,  SEEK_CUR,  or SEEK_END,  the  offset is relative to the start of the file, the current position indicator, or end-of-file, respectively.
A successful call to the fseek() function clears the end-of-file indicator for  the  stream  and  undoes  any  effects  of  the ungetc(3) function on the same stream.
```

y una especificación sobre el valor de retorno : 
```
Upon successful completion -> 0. <br>
Otherwhise -> -1.
```

Listo!!! Con esto ya tenemos todo lo que necesitamos para usar el tan aclamado ***fseek***, y de paso aprendimos a usar el manual!

Se adjunta un ejemplo el cual fue utilizado en clase. #ALGO1-FSEEK
