#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

char nom[50],c[1];
int linies,count,fd;


int main(){
//Definim les variables


//Demanem el valor de les variables

	printf("Nom de l'arxiu: \n");
	scanf("%s",nom);
	printf("Nombre de línies a mostrar: \n");
	scanf("%d",&linies);

if (linies <=0){
	printf("Error: nombre de línies no disponible \n");
       return -1;
}
	
if ((fd = open(nom, O_RDONLY))<0){
	printf("Error: el fitxer no existeix \n" );
	return fd;}
	
else{
	while(read(fd,c,1) != 0){
		
		while (c[0]!=10){
			printf("%s",c);
			read(fd,c,1);}
		if (c[0] ==10){
			count++;
			printf("\n");}
		if (count == linies){break;}}}

close(fd);
}


