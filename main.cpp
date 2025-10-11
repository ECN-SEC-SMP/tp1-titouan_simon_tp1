#include "utilitaire.hpp"
#include "lexique.h"
#include <iostream>
#include <string>

using namespace std;
int main() {
    Lexique test;        
    string cheminTexte_NDDP="./tp1-Lexique-fichiers/notreDameDeParis_A.txt";
    string cheminTexte_LM="./tp1-Lexique-fichiers/lesMiserables_A.txt";
    
    test.ajouterTexte(cheminTexte_NDDP);
    cout<<test;
    test.sauvegarder("./lexique.txt");
    
    return 0;

    // test.ajouterMot("test1");
    // test.ajouterMot("test2");
    // test.incrementerOccurrence("test1");
    // //test.supprimerMot("test2");
    // test.afficherLexique(); 
    // // test.motExisteOccurence("test1");
    // // test.nombreMots();
    // Lexique test_2;
    // test_2.ajouterMot("test1");
    // // test += test_2;
    // // test.afficherLexique();
    // test -= test_2;
    // //test.afficherLexique();
    // cout<<test;

}
