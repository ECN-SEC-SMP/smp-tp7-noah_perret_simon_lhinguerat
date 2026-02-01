# Rapport de TP7 - Formes géométriques (héritage & polymorphisme)

**Nom :** PERRET Noah & L'HINGUERAT Simon

**Groupe :** SEC28

**Date :** 1 février 2026

## Compilation et exécution

```bash
# Compilation (main + tests)
make

# Exécution du binaire principal
./main

# Exécution des tests unitaires
./testClass

# Nettoyage
make clean
```

## Préambule : objectifs du projet

Ce TP met en place une hiérarchie de formes 2D et une liste polymorphe :
- classe `point` pour les coordonnées et la translation
- classe abstraite `Forme` (centre, translation, `surface()` et `perimetre()`)
- classes dérivées : `Rectangle`, `Carre`, `Cercle`
- classe `ListeForme` pour agréger des formes, calculer la surface totale et la boîte englobante.

# 1 - Structures de données

### `point`
Fichier : `include/point.hpp` — implémentation dans `src/point.cpp`.

Classe de base représentant un point 2D :
```cpp
class point {
private:
    int _x;
    int _y;
public:
    point();           // Constructeur par défaut (0, 0)
    point(int x, int y);  // Constructeur paramétré
    point(const point &p); // Constructeur de copie
    ~point();
    
    int getX() const;
    int getY() const;
    void setX(int NewX);
    void setY(int NewY);
    void setXandY(int NewX, int NewY);
    void translater(const point &p); // Addition vectorielle
};
```

### `Forme`
Fichier : `include/forme.hpp` — implémentation dans `src/forme.cpp`.

Classe abstraite mère pour toutes les formes :
```cpp
class Forme {
protected:
    point _centre;
public:
    Forme(point p);
    ~Forme();
    
    void translater(point &p);
    int getOriginX() const;
    int getOriginY() const;
    void setOriginX(int NewX);
    void setOriginY(int NewY);
    void setOriginXY(int NewX, int NewY);
    void operator+=(point const&p);
    
    virtual double perimetre() = 0;   // Méthode abstraite
    virtual double surface() = 0;     // Méthode abstraite
};
```

# 2 - Formes spécifiques

### `Rectangle`
Fichier : `include/formeSpecifique/rectangle.hpp` — implémentation dans `src/formeSpecifique/rectangle.cpp`.

Classe rectangle héritant de `Forme` :
```cpp
class Rectangle : public Forme {
protected:
    double _largeur, _longueur;
public:
    Rectangle(double longueur, double largeur, point p);
    ~Rectangle();
    
    double getLongueur() const;
    double getLargeur() const;
    void setLongueur(double NewL);
    void setLargeur(double NewL);
    
    virtual double perimetre();   // 2 * (longueur + largeur)
    virtual double surface();     // longueur * largeur
};
```

#### Résumé
- Centre du rectangle défini par le `point` hérité
- Calcul de surface : $L \times l$
- Calcul de périmètre : $2(L + l)$

### `Carre`
Fichier : `include/formeSpecifique/carre.hpp` — implémentation dans `src/formeSpecifique/carre.cpp`.

Classe carré héritant de `Rectangle` :
```cpp
class Carre : public Rectangle {
public:
    Carre(double longueur, point p);
    ~Carre();
};
```

#### Résumé
- Héritage : `Carre` est un cas spécial de `Rectangle` où longueur = largeur
- Constructeur unique : paramètre `longueur` appliqué aux deux dimensions
- Calcul de surface : $c^2$
- Calcul de périmètre : $4c$

### `Cercle`
Fichier : `include/formeSpecifique/cercle.hpp` — implémentation dans `src/formeSpecifique/cercle.cpp`.

Classe cercle héritant de `Forme` :
```cpp
class Cercle : public Forme {
protected:
    double _rayon;
public:
    Cercle(point p, double r);
    ~Cercle();
    
    double getRayon() const;
    void setRayon(double NewR);
    
    virtual double perimetre();   // 2 * PI * rayon
    virtual double surface();     // PI * rayon^2
};
```

#### Résumé
- Rayon `_rayon` comme attribut principal
- Utilise $\pi = 3.14$
- Calcul de surface : $\pi r^2$
- Calcul de périmètre : $2\pi r$

### `ListeForme`
Fichier : `include/listeforme.hpp` — implémentation dans `src/listeforme.cpp`.

Classe conteneur polymorphe :
```cpp
class ListeForme {
private:
    vector<Forme*> _listeForme;
public:
    ListeForme();
    ~ListeForme();
    
    void addForme(Forme* f);
    void suprForme(unsigned int nb);
    Forme* getForme(unsigned int nb);
    
    double surface();        // Somme des surfaces
    Rectangle boite();       // Rectangle englobant
};
```

#### Résumé
- Stockage polymorphe : `std::vector<Forme*>`
- `surface()` : agrégation des surfaces de toutes les formes
- `boite()` : calcul d'une boîte englobante (Rectangle) de toutes les formes consécutives et allignées sur un axe.

# 3 - Jeux d'essais avec Unity

Fichier : `test/testClass.cpp`.

Nous utilisons le framework **Unity** pour réaliser des tests unitaires automatisés.

### Organisation des tests
- **setUp/tearDown** : appelés avant/après chaque test (isolation)
- **Assertions** : macros `TEST_ASSERT_EQUAL_INT`, `TEST_ASSERT_EQUAL_FLOAT`, etc.
- **Granularité** : un test par fonctionnalité

### Couverture des tests

#### Tests `point`
- `test_point_initialization` : constructeurs par défaut et paramétré
- `test_point_copy_constructor` : copie
- `test_point_setters` : modification des coordonnées
- `test_point_translation` : translation par addition

#### Tests `Rectangle`
- `test_rectangle_logic` : dimensions, surface, périmètre
- `test_rectangle_translation` : translation via `operator+=`

#### Tests `Carre`
- `test_carre_logic` : cohérence longueur/largeur, surface, périmètre
- `test_carre_display` : affichage (flux ostream)

#### Tests `Cercle`
- `test_cercle_initialization` : rayon et position
- `test_cercle_geometry` : surface et périmètre
- `test_cercle_translation` : translation

#### Tests `ListeForme`
- `test_liste_ajout_et_surface` : ajout de formes et calcul de surface totale
- `test_liste_suppression` : suppression avec libération mémoire
- `test_liste_boite_englobante` : calcul de la boîte englobante

### Lancer les tests

```bash
make all
./testClass
```

### Résultats

Tous les tests passent avec succès, validant la robustesse de notre implémentation.

# 4 - Points clés / limites

- **Héritage** : `Carre` hérite de `Rectangle` (cas spécial où longueur = largeur), maximisant la réutilisation de code.
- **Polymorphisme** : `ListeForme` stocke des pointeurs `Forme*` et appelle les bonnes méthodes `surface()` et `perimetre()` via dispatch virtuel.
- **Gestion mémoire** : `suprForme()` libère explicitement la mémoire avec `delete` avant suppression du vecteur.
- **Constante PI** : définie globalement à 3.14 dans `cercle.hpp` pour les calculs de cercle.
- **Translation polymorphe** : l'opérateur `operator+=` hérit de `Forme` et permet de déplacer n'importe quelle forme.
- **Boîte englobante** : `boite()` calcule les limites min/max de toutes les formes (y compris cercles avec rayon).
