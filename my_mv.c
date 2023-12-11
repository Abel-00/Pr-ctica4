#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>


char a_canviar[50],canvi[50],c[1];
char linea[1] = "\n";
int fd1,fd2;


int main(){
//Demanem quin arxiu volem canviar i comprovem que es pugui obrir
	printf("Nom o lloc de l'arxiu que vols canviar: ");
	scanf("%s",a_canviar);
	if ((fd1 = open(a_canviar, O_RDONLY))<0){
           printf("Error: el fitxer no existeix \n" );
           return fd1;}
//Demanem quin canvi volem fer i comprovem que es pugui fer
	printf("Nom o lloc al qual vols canviar: ");
	scanf("%s",canvi);
	if((fd2 = open( canvi, O_CREAT|O_WRONLY|O_TRUNC, S_IRWXU ))<0){
           printf("Error: no es pot obrir el nou fitxer \n");
           return fd2;}

// Copiem a la variable C cada lletra de l'arxiu a_canviar
else{
     	while (read(fd1, c, 1) !=0 ){ write(fd2, c, 1); }
}	

close(fd2);
close(fd1);
unlink(a_canviar);

}
