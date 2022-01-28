/*
 Programme : Shifumi
 But : Jouer au jeux du shifumi
 Date de dernière modification : 22 septembre 2021
 Auteur : T. Cocheril
 Remarques : Code conforme aux spécifications internes vues en TD2
*/


#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;


int randomMinMax(int min, int max);

int main (void)
{


//VARIABLES

 char choixUtilisateur; //signe choisi par l'utilisateur
 char choixMachine; //signe choisi aléatoirement par la machine 
 int nombreAleatoire; //Nombre aléatoire entre 1 et 4
 int scoreUtilisateur; // score de l'utilisateur
 scoreUtilisateur = 0;
 int scoreMachine; // score de la machine
 scoreMachine = 0;
 
 

 srand(time(NULL));


//AFFICHAGE REGLE DU JEU 

cout << "Jeu du Shifumi" << endl ;
cout << "---------------" << endl;
cout << "" << endl;
cout << "" << endl;
cout << "---------------" << endl;
cout << "Vous (joueur1) jouerez contre la machine (joueur2). " << endl;
cout << "Le jeu se compose de manches. " << endl;
cout << "Vous pourrez arreter quand vous le souhaitez. La question est vous sera poser a la fin de chaque manche " << endl;
cout << "" << endl;
cout << "Dans une manche, chaque joueur choisit une figure : PIERRE(P), FEUILLE(F), CISEAU(C). " << endl;
cout << "Le CISEAU(C) bat la FEUILLE(F), qui bat la PIERRE(P), qui bat le CISEAU(C)." << endl;
cout << "Le joueur ayant choisi la figure gagnante gagne le point. " << endl;
cout << "Pas de point en cas d'egalite. " << endl;
cout << "---------------" << endl;


//NOUVELLE MANCHE    

while (true)
{

//SAISI DE L'UTILISATEUR
        while(true)
{
 cout << "Entrez le signe que vous souhaitez [(P),(F),(C)] ou (Q) pour quitter : " ;
 cin >> choixUtilisateur;
    if ((choixUtilisateur == 'P') || (choixUtilisateur == 'F') || (choixUtilisateur == 'C') || (choixUtilisateur == 'Q'))//verifier si le signe choisi est valide
    {
    break;
    }
    else
    {
    cout << "Vous avez entrer une mauvaise valeur, veuillez recommencer ! " << endl;
    cout << ""<< endl;
        }
 }

if (choixUtilisateur == 'Q'){
    break;
}

//SAISI DE LA MACHINE
        nombreAleatoire = randomMinMax(1, 4);

        switch (nombreAleatoire)//rentrer la valeur numérique de nombreAleatoire dans une chaine de caractère nommé choixMachine
            {
            case 1:
                choixMachine = 'P';
                break;

            case 2:
                choixMachine = 'C';
                break;        
            
            case 3:
                choixMachine = 'F';
                break;  
            }
            
    //COMPARAISON DES SIGNES ET SCORE MIS A JOUR

    if((choixUtilisateur == 'P') &&( choixMachine == 'C')){
            scoreUtilisateur ++;
        }
        else if((choixUtilisateur == 'F') && (choixMachine == 'P')){
            scoreUtilisateur ++;
        }
        else if((choixUtilisateur == 'C') && (choixMachine == 'F')){
            scoreUtilisateur ++;
        }
        else if(choixUtilisateur == choixMachine){
            scoreUtilisateur +=0;
        }
        else{
            scoreMachine ++;
        }


cout << "" << endl;
cout << "Vous avez choisi " <<choixUtilisateur << ", votre score est de " << scoreUtilisateur <<endl;//suivi des signes ainsi que les scores mise en jeu dans la partie
cout << "Machine a choisi " <<choixMachine << ", son score est de " << scoreMachine <<endl;//suivi des signes ainsi que les scores mise en jeu dans la partie
cout << "" << endl;


}
 //AFFICHER RESULTAT DE LA PARTIE

 if(scoreUtilisateur == scoreMachine)
 {
     cout << "Vous etes a egalite" <<endl;
 }  
 else if (scoreMachine < scoreUtilisateur)
 {
     cout << "Vous avez gagne la partie !" << endl ;
 }
 else
 {
     cout << "Vous avez perdu la partie !" << endl ;
 }   


//AFFICHER LA FIN DU JEU 
cout << "" <<endl;
cout << "FIN DU JEU" <<endl;
cout << "" <<endl;
cout << "A tres vite j'espere  :)" <<endl;
cout << "------------------------" <<endl;
    
    return 0;


}

int randomMinMax (int min, int max){
    return rand()%(max-min) +min;
}