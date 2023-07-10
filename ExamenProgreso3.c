#include <stdio.h> //Se incluye la biblioteca stdio.h y la creacion de funcion main
int main(){
    struct alumnos{
        int numero;
        char NombreApellido [30];
        char Carrera [30];
        float nota1;
        float nota2;
        float nota3;
        float promedio;
    }alumnos;

    FILE *archivo;
    archivo = fopen("alumnos.txt","r");

    while(!feof(archivo)){
        fscanf(archivo, "%d %s %s %f %f %f", &alumnos.numero, &alumnos.NombreApellido, &alumnos.Carrera, &alumnos.nota1, &alumnos.nota2, &alumnos.nota3);

    }



    return 0;
}