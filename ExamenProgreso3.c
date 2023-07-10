#include <stdio.h> //Se incluye la biblioteca stdio.h y la creacion de funcion main
float Promedio(float x, float y, float z){
    float resultado;
    resultado = (x+y+z)/3;
    return resultado;
}
struct alumnos{
        int numero;
        char NombreApellido [30];
        char Carrera [30];
        float nota1;
        float nota2;
        float nota3;
        float promedio;
    }alumnos;
int main(){
    struct alumnos alumnos;    

    FILE *archivo;
    FILE *archivonuevo;
    archivo = fopen("alumnos.txt","r+");
    archivonuevo = fopen("AlumnosConPromedio.txt","a+");
    int mayor = 0;
    int opcion = 0;

    do
    {
        printf("Menu:\n");
        printf("\n1.Leer los datos \n2.Escribir los datos en nuevo archivo \n3.Salir\n");
        printf("\nIngrese una opcion del menu: ");
        scanf("%d", &opcion);
        getchar();

        switch (opcion){
            case 1: printf("\nLos datos leidos se imprimiran a continuacion: \n");
                while(!feof(archivo)){
                    while(fscanf(archivo, "%d %s %s %f %f %f", &alumnos.numero, alumnos.NombreApellido, alumnos.Carrera, &alumnos.nota1, &alumnos.nota2, &alumnos.nota3) != EOF){
                        printf("%d %s %s %f %f %f\n", alumnos.numero, alumnos.NombreApellido, alumnos.Carrera, alumnos.nota1, alumnos.nota2, alumnos.nota3);
                        fflush(archivo);
                    }
                }
                break;
            case 2: while(fscanf(archivo, "%d %s %s %f %f %f", &alumnos.numero, alumnos.NombreApellido, alumnos.Carrera, &alumnos.nota1, &alumnos.nota2, &alumnos.nota3) != EOF){
                        alumnos.promedio = Promedio(alumnos.nota1, alumnos.nota2, alumnos.nota3);
                        fprintf(archivonuevo, "%d %s %s %f %f %f %f\n", alumnos.numero, alumnos.NombreApellido, alumnos.Carrera, alumnos.nota1, alumnos.nota2, alumnos.nota3, alumnos.promedio);
                        fflush(archivo);
                    }
                    printf("\nSe imprimieron los datos con exito\n");
                break;
            case 3: printf("\nSalio con exito del programa!\n");
                break;
            default: printf("\nIngrese una opcion valida\n");
                break;
        }
    } while (opcion!=3);
        
    fclose(archivo);
    fclose(archivonuevo);
    
    return 0;
}