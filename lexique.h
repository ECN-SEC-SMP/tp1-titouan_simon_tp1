#ifndef LEXIQUE_H
#define LEXIQUE_H

#include <map>
#include <string>
#include <iostream>
#include "utilitaire.hpp"
class Lexique {
    private:
    std::map<std::string, int> lexique;

    public:
    // Constructeur
    Lexique();
    
    // Getteur
    void nombreOccurrences(const std::string& mot) const;
    void afficherLexique() const;
    bool motExiste(const std::string& mot) const;
    void motExisteOccurence(const std::string& mot) const;
    void nombreMots() const;
    
    // Setteur
    void ajouterMot(const std::string& mot);
    void incrementerOccurrence(const std::string& mot);
    void supprimerMot(const std::string& mot);
    void ajouterTexte(const std::string& chemin_Texte);

    // Destructeur
    ~Lexique();
    
    //Opérateurs
    //interne
    Lexique& operator+=(const Lexique& autre);    
    Lexique& operator-=(const Lexique& autre);    
    //Externe
    friend std::ostream& operator<<(std::ostream& os, const Lexique& lex);

    void sauvegarder(const std::string& cheminFichier) const;


};
#endif // LEXIQUE_H