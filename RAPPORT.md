# Rapport TP1 - Lexique

Titouan Copin Simon Cau
## Table des matières
- [Rapport TP1 - Lexique](#rapport-tp1---lexique)
  - [Table des matières](#table-des-matières)
  - [Introduction](#introduction)
  - [Algorithmes implémentés](#algorithmes-implémentés)
    - [Fusion de lexiques (operator+=)](#fusion-de-lexiques-operator)
      - [Description](#description)
      - [Algorithme](#algorithme)
      - [Principe](#principe)
    - [Différence de lexiques (operator-=)](#différence-de-lexiques-operator-)
      - [Description](#description-1)
      - [Algorithme](#algorithme-1)
      - [Principe](#principe-1)
  - [Jeux d'essais](#jeux-dessais)
    - [Test 1 : Fusion](#test-1--fusion)
    - [Test 2 : Différence avec suppression](#test-2--différence-avec-suppression)
    - [Test 3 : Différence avec suppression complète](#test-3--différence-avec-suppression-complète)
  - [Conclusion](#conclusion)

## Introduction

Ce rapport présente l'implémentation de deux algorithmes fondamentaux pour la manipulation de lexiques :
- **Fusion** : Combiner deux lexiques en additionnant les occurrences
- **Différence** : Soustraire les occurrences d'un lexique à un autre

La classe `Lexique` utilise une `std::map<std::string, int>` pour stocker les mots et leurs occurrences, garantissant un ordre alphabétique automatique.

## Algorithmes implémentés

### Fusion de lexiques (operator+=)

#### Description
L'opérateur `+=` fusionne deux lexiques en additionnant les occurrences de chaque mot.

#### Algorithme
```cpp
Lexique& Lexique::operator+=(const Lexique& autre) {
    for (const auto& pair : autre.lexique) {
        this->lexique[pair.first] += pair.second;
    }
    return *this;
}
```

#### Principe
1. **Parcours** : Itère sur tous les mots du lexique `autre`
2. **Addition** : Pour chaque mot trouvé :
   - Si le mot existe déjà dans `this`, additionne les occurrences
   - Si le mot n'existe pas, l'opérateur `[]` le crée avec la valeur donnée
3. **Retour** : Retourne une référence vers `this` pour permettre le chaînage

### Différence de lexiques (operator-=)

#### Description
L'opérateur `-=` soustrait les occurrences d'un lexique à un autre, supprimant les mots dont le compte devient ≤ 0.

#### Algorithme
```cpp
Lexique& Lexique::operator-=(const Lexique& autre) {
    for (const auto& pair : autre.lexique) {
        if(motExiste(pair.first)){
            this->lexique[pair.first] -= pair.second;
            if (this->lexique[pair.first] <= 0) {
                supprimerMot(pair.first);
            }
        }
    }
    return *this;
}
```

#### Principe
1. **Parcours** : Itère sur tous les mots du lexique `autre`
2. **Vérification** : Vérifie si le mot existe dans `this`
3. **Soustraction** : Soustrait les occurrences
4. **Nettoyage** : Si le résultat ≤ 0, supprime le mot complètement
5. **Retour** : Retourne une référence vers `this`


## Jeux d'essais

### Test 1 : Fusion 

```cpp
// Initialisation
Lexique lex1, lex2;

// Lexique 1
lex1.ajouterMot("chat");         // chat: 1
lex1.ajouterMot("chien");        // chien: 1
lex1.incrementerOccurrence("chat"); // chat: 2

// Lexique 2
lex2.ajouterMot("chat");         // chat: 1
lex2.ajouterMot("oiseau");       // oiseau: 1

// Fusion
lex1 += lex2;

// Résultat attendu dans lex1:
// chat: 3 (2 + 1)
// chien: 1
// oiseau: 1
```

**Sortie console :**
```
chat: 3
chien: 1
oiseau: 1
```

### Test 2 : Différence avec suppression

```cpp
// Initialisation
Lexique lex1, lex2;

// Lexique 1
lex1.ajouterMot("chat");         // chat: 1
lex1.ajouterMot("chien");        // chien: 1

// Lexique 2
lex2.ajouterMot("chat");         // chat: 1
lex2.ajouterMot("oiseau");       // oiseau: 1 (n'existe pas dans lex1)

// Différence
lex1 -= lex2;

// Résultat attendu dans lex1:
// chien: 1 (inchangé)
// oiseau n'affecte pas lex1
```

**Sortie console :**
```
chien: 1
```

### Test 3 : Différence avec suppression complète

```cpp
// Initialisation
Lexique lex1, lex2;

// Lexique 1
lex1.ajouterMot("chat");         // chat: 1
lex1.ajouterMot("chien");        // chien: 1

// Lexique 2
lex2.ajouterMot("chat");         // chat: 1

// Différence
lex1 -= lex2;

// Résultat attendu dans lex1:
// chat: supprimé (1 - 2 = -1 ≤ 0)
// chien: 1 (inchangé)
```

**Sortie console :**
```
chien: 1
```

## Conclusion

L'implémentation présentée offre une base solide pour des applications de traitement de texte nécessitant des opérations sur des lexiques.