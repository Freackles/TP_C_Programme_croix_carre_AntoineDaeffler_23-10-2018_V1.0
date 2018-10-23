#include <stdio.h>
#include <stdlib.h>
#include <conio.h> //Bibliothèque pour la fonction getche()

int choix_prog();
void carre();
void croix();
char caractere();
int taille_carre();
void afficher_carre(char, char, int);
void afficher_croix(char, int);

int main()
{
    int start;
    do{
        printf("Choix du programme :\n1 - carre\n2- croix\n");
        //Lance la fonction de choix dans un menu pour choisir le programme à lancer
        int choix = choix_prog();

        //Lance le programme choisie par l'utilisateur
        if(choix==1){
            carre();
        }else{
            croix();
        }

        printf("\n\nVoulez-vous recommencer ?\n1 - oui\n2 - non\n");
        //Lance la fonction de choix dans un menu pour choisir le programme à lancer
        start = choix_prog();

        //Efface le contenue de la console si 1
        if(start==1){
            system("cls");
        }
    }while(start==1);
    return 0;
}

//Fonction de choix dans un menu
int choix_prog(){
    int choix;

    do{ //Blindage de saisie
        fflush(stdin);
        scanf("%d", &choix);
        if(choix<1 || choix>2){
            printf("Erreur !\n");
        }
    }while(choix<1 || choix>2);

    return choix;
}

//Fonction du carre
void carre(){
    printf("\nVous avez lancer le programme du carre !\n\n");

    //Initialisation des variable que l'utilisateur devra rentrer au clavier
    char carac1, carac2;
    int taille;

    printf("Premier caractere :\n");
    carac1 = caractere(); //Fonction qui récupère le caractère choisi
    printf("\nDeuxieme caractere :\n");
    carac2 = caractere();
    taille = taille_carre(); //Fonction qui récupère la taille choisie
    afficher_carre(carac1, carac2, taille); //Fonction qui affiche le carre
}

//Fonction de la croix
void croix(){
    printf("\nVous avez lancer le programme de la croix !\n\n");

    //Initialisation des variable que l'utilisateur devra rentrer au clavier
    char carac;
    int taille;

    carac = caractere(); //Fonction qui récupère le caractère choisi
    taille = taille_carre(); //Fonction qui récupère la taille choisie
    afficher_croix(carac, taille); //Fonction qui affiche la croix
}

//Fonction qui récupère le caractère choisie par l'utilisateur
char caractere(){
    char carac;
    printf("Choissisez un caractere (compris entre a et z et A et Z) :");
    do //Blindage de saisie
    {
        fflush(stdin); //Permet de vider la mémoire pour éviter que la saisie soit encombré
        carac = getche(); //fonction qui recupere le premier caractère ecrit
        if((carac<97 || carac>122) && (carac<65 || carac>90)){  //Mets une erreur si le caractère n'est pas de a à z et pas de A à Z
            printf("\nErreur !\n");
        }
    }while((carac<97 || carac>122) && (carac<65 || carac>90));
    return carac;
}

//Fonction qui récupère la taille choisie par l'utilisateur
int taille_carre(){
    int taille;
    printf("\nParfait !\nMaintenant rentrez la taille du carre (entre 1 et 20) : ");
    do //Blindage de saisie
    {
        fflush(stdin); //Permet de vider la mémoire pour éviter que la saisie soit encombré
        scanf("%d", &taille);
        if(taille<=0 || taille>20){ //Mets une erreur si la taille est trop grande ou négative (max 20 pour que ca rentre dans une console fenêtrer)
            printf("Erreur !\n");
        }
    }while(taille<=0 || taille>20);
    return taille;
}

//Fonction qui affiche le carre
void afficher_carre(char carac1, char carac2, int taille){
    int i, j;
    for(i=1;i<=taille;i++) {
            printf("\n ");
        for(j=1;j<=taille;j++){
            //ecrire le caractère 1 si c'est sa place sinon ecrire le caractère 2
            if(i==1 || j==1 || i==taille || j==taille){
                printf("%c", carac1);
            }else{
                printf("%c", carac2);
            }
        }
    }
}

//Fonction qui affiche la croix
void afficher_croix(char carac, int taille){
    int i, j;
    for(i=1;i<=taille;i++) {
            printf("\n ");
        for(j=1;j<=taille;j++){
            //ecrire le caractère si c'est sa place sinon ecrire un espace
            if(i==j || j==(taille-i)+1){
                printf("%c", carac);
            }else{
                printf(" ");
            }
        }
    }
}
