#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define max 100

//Funciones Principales
int menu();
void concatenar();
void prefijo();
void sufijo();
void subcadena();
void subsecuencia();
void inversa();
void potencia();

//Funciones de apoyo
int solchar(char *s);
void solint(int *n);
void quitar(int ini, int fin, int tam, char *c);
void unir(char *s, char *c, char *c2);
int size(char *c);
void invertir(char *s, int tam);
void potenciar(char *s, int tam,int n);

//Funcion principal
int main()
{
    int opc = 0;
    do
    {
        opc = menu();
        switch (opc)
        {
        case 1:
            concatenar();
            break;
        case 2:
            prefijo();
            break;
        case 3:
            sufijo();
            break;
        case 4:
            subcadena();
            break;
        case 5:
            subsecuencia();
            break;
        case 6:
            inversa();
            break;
        case 7:
            potencia();
            break;
        case 8:
            break;
        default:
            printf("esa no es una opcion valida, intentalo de nuevo\n");
        }
    } while (opc != 8);
    return 0;
}

int menu()
{
    int opc;
    printf("-------------------------MENU-------------------------\n");
    printf("Escribe el numero del proceso que quieres hacer\n");
    printf("1. Concatenar dos cadenas\n");
    printf("2. Prefijo de una cadena\n");
    printf("3. Sufijo de una cadena\n");
    printf("4. Subcadena de una cadena\n");
    printf("5. Subsecuencia de una cadena\n");
    printf("6. Inversa de una cadena\n");
    printf("7. Potencia de una cadena\n");
    printf("8. Salir\n");
    printf("------------------------------------------------------\n");
    solint(&opc);
    return opc;
}

//Inicio de funciones 

void concatenar()
{   
    int n,m,i,j;
    char *cad1, *cad2, aux[1],*s;
    cad1 = malloc(max * sizeof(char));
    cad2 = malloc(max * sizeof(char));
    fgets(aux, max, stdin);
    n = solchar(cad1);
    m = solchar(cad2);
    s = malloc((m + n) * sizeof(char));
    for (i = 0; i < n; i++)
        s[i] = cad1[i];
    for (j = 0; j < m; j++)
        s[i + j] = cad2[j];

    s[i + j + 1] = '\0';
    printf("Tus cadenas concatenadas, forman la siguiente cadena:\n\n%s\n\n",s);
    free(cad1);
    free(cad2);
    free(s);
}

void prefijo()
{
    int n, m;
    char aux[1], *s;
    fgets(aux, max, stdin);
    s = malloc(max * sizeof(char));
    n = solchar(s);
    printf("ingresa la cantidad de caracteres a eliminar \n");
    solint(&m);
    if (m > n)
    {
        printf("No podemos quitar mas caracteres de los que hay, intentalo de nuevo o disminuye los caracteres a quitar\n");
    }
    else if(m == n)
    {
        printf("El prefijo es el conjunto vacio\n");
    }else
    {
        quitar(0, (n - m - 1), n, s);
        printf("El prefijo es:\n\n%s\n\n", s);
    }
    free(s);
}

void sufijo()
{
    int n, m;
    char aux[1], *s;
    fgets(aux, max, stdin);
    s = malloc(max * sizeof(char)); 
    n = solchar(s);
    printf("ingresa la cantidad de caracteres a eliminar \n");
    solint(&m);
    if (m > n)
    {
        printf("No podemos quitar mas caracteres de los que hay, intentalo de nuevo o disminuye los caracteres a quitar\n");
    }
    else if(m == n)
    {
        printf("El sufijo es el conjunto vacio\n");
    }else
    {
        quitar(m, n + 1, n, s);
        printf("El sufijo es:\n\n%s\n\n", s);
    }
    free(s);
}

void subcadena()
{
    int n, m, l;
    char aux[1], *s;
    fgets(aux, max, stdin);
    s = malloc(max * sizeof(char));
    l = solchar(s);
    printf("Ingresa desde que numero de caracter quieres hacer la subcadena\n");
    solint(&n);
    printf("Ingresa hasta que numero de caracter quieres hacer la subcadena\n");
    solint(&m);
    if(m>n && n+m<l)
    {
        quitar(n, m - 1, l, s);
        printf("la subcadena que formada es la siguiente:\n%s\n",s);
    }else if(n == m)
    {
        printf("La subcadena formada es un conjunto vacio\n");
    }else
    {
        printf("rango de subcadena no valido\n");
    }
    free(s);
}

void subsecuencia()
{
    int n=0, m, l,i=0;
    char aux[1],*tmp,*s;
    fgets(aux, max, stdin);
    s = malloc(max * sizeof(char));
    l = solchar(s);
    tmp = malloc(l * sizeof(char)); 
    m = rand() % (2) + 1;
    while(s[n]){
        tmp[i]= s[n];
        i++;
        n+=m;
    }
    i = 0;
    while(tmp[i]){
        s[i]= tmp[i];
        i++;
    }
    s[i] = '\0';
    printf("La subsecuencia es la siguiente:\n\n%s\n\n",s);
    free(s);
    free(tmp);
}

void inversa()
{
    char *s, aux[1];
    int i, tam, j = 0; 
    fgets(aux, max, stdin);
    s = malloc(max * sizeof(char));
    tam = solchar(s);
    invertir(s,tam);
    printf("La inversa de la cadena ingresada es la siguiente:\n\n%s\n\n",s);
    free(s);
}

void potencia()
{
    int tam, n;
    char aux[1], *s;
    fgets(aux, max, stdin);
    s = malloc(max * sizeof(char));
    tam = solchar(s);
    printf("ingresa a que potencia elevaras el arrglo \n");
    solint(&n);
    if(n<0){
        invertir(s,tam);
        potenciar(s,tam,fabs(n));
    }else if(n == 0){
        printf("El resultado es el conjunto vacio\n");
    }else{
        potenciar(s,tam,n);
    }
}

//Inicio de Funciones de apoyo

int solchar(char *s)
{
    int n;
    printf("Escribe la cadena de texto a oontinuacion\n");
    fflush(stdin);
    fgets(s, max, stdin);
    n = size(s);
    s = realloc(s, n * sizeof(char));
    return n;
}

void solint(int *n)
{
    fflush(stdin);
    scanf("%d",n);
}

void quitar(int ini, int fin, int tam, char *c)
{
    char *tmp;
    int i, j = 0;
    tmp = malloc(tam * sizeof(char));
    for (i = 0; i < tam; i++)
        tmp[i] = c[i];
    c = realloc(c, (fin - ini) * sizeof(char));
    for (i = ini; i <= fin; i++)
    {
        c[j] = tmp[i];
        j++;
    }
    c[j] = '\0';
    free(tmp);
}

int size(char *c)
{
    int n = 0;
    while (c[n])
        n++;
    return (n - 1);
}

void invertir(char *s, int tam){
    char *tmp;
    int i;
    tmp = malloc((tam + 1) * sizeof(char));
    tmp[tam] = '\0';
    for (i = 0; i < tam; i++)
        tmp[i] = s[i];
    for (i = 0; i < tam; i++)
        s[i] = tmp[tam - 1 - i];
    free(tmp);
}

void potenciar(char *s, int tam,int n){
    int i,j;
    s = realloc(s, (tam * n) * sizeof(char));
    for (i = 0; i < tam; i++)
        for (j = i; j < (tam * n); j += tam)
            s[j] = s[i];
    printf("Tu cadena elevada a esa potencia es la siguiente:\n\n%s\n\n",s);
}