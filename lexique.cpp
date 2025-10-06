
#include <map>
#include <string>
#include <iostream>
#include "lexique.h"
#include "utilitaire.hpp"
#include <cstring>
#include <fstream> 

using namespace std;

// Constructeur par défaut : initialise un lexique vide
Lexique::Lexique() {
    lexique = map<string, int>();
}

// Affiche tous les mots du lexique avec leurs occurrences sur la console
void Lexique::afficherLexique() const {
    for (const auto& pair : this->lexique) {
        cout << pair.first << ": " << pair.second << endl;
    }
}

// Vérifie si un mot donné existe dans le lexique
// Retourne true si le mot est présent, false sinon
bool Lexique::motExiste(const string& mot) const {
    bool exist=false;
    if (this->lexique.find(mot) != this->lexique.end()) {
        exist=true;
    }
    return exist;
}

// Vérifie l'existence d'un mot et affiche ses occurrences
// Affiche un message informatif sur la console
void Lexique::motExisteOccurence(const string& mot) const {
    bool exist=motExiste(mot);
    if (exist) {
        cout << "Le mot '" << mot << "' existe dans le lexique avec " 
             << this->lexique.at(mot) << " occurrences." << endl;
    } else {
        cout << "Le mot '" << mot << "' n'existe pas dans le lexique." << endl;
    }
}

// Affiche le nombre total de mots uniques dans le lexique
void Lexique::nombreMots() const {
    cout << "Nombre de mots dans le lexique : " << this->lexique.size() << endl;
}

// Affiche le nombre d'occurrences d'un mot spécifique
// Affiche un message d'erreur si le mot n'existe pas
void Lexique::nombreOccurrences(const string& mot) const {
    if (motExiste(mot)) {
        cout << "Le mot '" << mot << "' a " << lexique.at(mot) << " occurrences." << endl;
    } else {
        cout << "Le mot '" << mot << "' n'existe pas." << endl;
    }
}

// Ajoute un mot au lexique ou incrémente ses occurrences s'il existe déjà
// Si le mot est nouveau, il est ajouté avec 1 occurrence
void Lexique::ajouterMot(const string& mot) {
    //Ajoute le mot avec une occurrence initiale de 1 ou incrémente si déjà présent
    this->lexique[mot] ++;
}

// Incrémente le nombre d'occurrences d'un mot donné
// Crée le mot avec 1 occurrence s'il n'existe pas
void Lexique::incrementerOccurrence(const string& mot) {
    this->lexique[mot]++;
}

// Supprime complètement un mot du lexique
void Lexique::supprimerMot(const string& mot) {
    this->lexique.erase(mot);
}

// Destructeur : libère la mémoire en vidant le lexique
Lexique::~Lexique() {
    lexique.clear();
}

// Opérateur de fusion : additionne les occurrences de deux lexiques
// Les mots communs voient leurs occurrences additionnées
Lexique& Lexique::operator+=(const Lexique& autre) {

    for (const auto& pair : autre.lexique) {
        if(motExiste(pair.first)){
            this->lexique[pair.first] += pair.second;
        } else {
            this->lexique[pair.first] = pair.second;
        }
        //this->lexique[pair.first] += pair.second;
    }
    return *this;
}

// Lit un fichier texte et ajoute tous ses mots au lexique
// Le texte est découpé en mots selon les séparateurs définis
void Lexique::ajouterTexte(const std::string& chemin_Texte){
    //Iporter le texte en string
    string texte;
    if (!util::readFileIntoString(chemin_Texte, texte)) {
        cerr << "Erreur lors de la lecture du fichier : " << chemin_Texte << endl;
        return;
    }
    // Conversion en char*
    const char* texte_char = texte.c_str();
    char* texte_dup = strdup(texte_char);

    for(char* token= strtok(texte_dup, " ,.-?!:_'*"); token != nullptr; token = strtok(nullptr, " ,.-?!:_'*")){
        ajouterMot(string(token));
    }//Ajoute chaque élement dans le lexique

    free(texte_dup);

}

// Opérateur de différence : supprime les mots présents dans l'autre lexique
// Les mots communs sont complètement supprimés de ce lexique
Lexique& Lexique::operator-=(const Lexique& autre) {
    for (const auto& pair : autre.lexique) {
        if(motExiste(pair.first)){
            supprimerMot(pair.first);
        }
    }
    return *this;
}

// Opérateur de flux de sortie : permet d'afficher un lexique avec cout <<
// Affiche chaque mot avec ses occurrences sur une ligne séparée
ostream& operator<<(ostream& os, const Lexique& lex) {
    for (const auto& pair : lex.lexique) {
        os << pair.first << ": " << pair.second << "\n";
    }
    return os;
}

// Sauvegarde le lexique dans un fichier texte
// Chaque ligne contient un mot et ses occurrences au format "mot: nombre"
void Lexique::sauvegarder(const string& cheminFichier) const {
    ofstream fichier(cheminFichier);
    
    if (!fichier.is_open()) {
        cerr << "Erreur : impossible d'ouvrir le fichier " << cheminFichier << endl;
        return;
    }
    
    // Écriture du lexique
    for (const auto& pair : this->lexique) {
        fichier << pair.first << ": " << pair.second << endl;
    }
    
    fichier.close();
    cout << "Lexique sauvegardé dans " << cheminFichier << endl;
}
