#include <stdio.h> //Se incluye la biblioteca stdio.h y la creacion de funcion main
float Promedio(float x, float y, float z){
    return (x+y+z)/3;
}
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

    FILE *archivo, *archivonuevo;
    archivo = fopen("alumnos.txt","r");
    archivonuevo = fopen("AlumnosConPromedio.txt","a+");
    int mayor = 0;
    float promedio = 0;


    while(!feof(archivo)){
        fscanf(archivo, "%d %s %s %f %f %f", &alumnos.numero, &alumnos.NombreApellido, &alumnos.Carrera, &alumnos.nota1, &alumnos.nota2, &alumnos.nota3);
        alumnos.promedio = Promedio(alumnos.nota1,alumnos.nota2,alumnos.nota3);
    }

    fprintf(archivonuevo, "%d; %s; %s; %f; %f; %f; %f\n", alumnos.numero, alumnos.NombreApellido, alumnos.Carrera, alumnos.nota1, alumnos.nota2, alumnos.nota3, alumnos.promedio);
    printf("\nSe imprimieron los datos con exito\n");
    fclose(archivo);
    fclose(archivonuevo);
    
    return 0;
}