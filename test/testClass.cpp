#include "unity.h"
#include "point.hpp"
#include "forme.hpp"
#include "carre.hpp"
#include "cercle.hpp"
#include "rectangle.hpp"
#include "listeforme.hpp"

// Ces fonctions sont appelées avant et après CHAQUE test
void setUp(void) {
    // Optionnel : Initialisation si besoin
}

void tearDown(void) {
    // Optionnel : Nettoyage si besoin
}

// 1. Test des constructeurs et Getters
void test_point_initialization(void) {
    point p1; // Par défaut (0,0)
    TEST_ASSERT_EQUAL_INT(0, p1.getX());
    TEST_ASSERT_EQUAL_INT(0, p1.getY());

    point p2(10, -5); // Avec paramètres
    TEST_ASSERT_EQUAL_INT(10, p2.getX());
    TEST_ASSERT_EQUAL_INT(-5, p2.getY());
}

// 2. Test du constructeur de recopie
void test_point_copy_constructor(void) {
    point p1(42, 84);
    point p2(p1);
    
    TEST_ASSERT_EQUAL_INT(42, p2.getX());
    TEST_ASSERT_EQUAL_INT(84, p2.getY());
}

// 3. Test des Setters
void test_point_setters(void) {
    point p;
    p.setX(15);
    p.setY(30);
    TEST_ASSERT_EQUAL_INT(15, p.getX());
    TEST_ASSERT_EQUAL_INT(30, p.getY());

    p.setXandY(100, 200);
    TEST_ASSERT_EQUAL_INT(100, p.getX());
    TEST_ASSERT_EQUAL_INT(200, p.getY());
}

// 4. Test de la translation
void test_point_translation(void) {
    point p1(10, 10);
    point p2(5, -2);
    
    p1.translater(p2); // p1 devient (10+5, 10-2)
    
    TEST_ASSERT_EQUAL_INT(15, p1.getX());
    TEST_ASSERT_EQUAL_INT(8, p1.getY());
    
    // On vérifie que p2 n'a pas bougé
    TEST_ASSERT_EQUAL_INT(5, p2.getX());
    TEST_ASSERT_EQUAL_INT(-2, p2.getY());
}


void test_rectangle_logic(void) {
    point centre(5, 5);
    Rectangle rect(10, 5, centre);

    // Test des dimensions
    TEST_ASSERT_EQUAL_FLOAT(10.0, rect.getLongueur());
    TEST_ASSERT_EQUAL_FLOAT(5.0, rect.getLargeur());

    // Test des méthodes abstraites implémentées 
    TEST_ASSERT_EQUAL_FLOAT(50.0, rect.surface());   // 10 * 5
    TEST_ASSERT_EQUAL_FLOAT(30.0, rect.perimetre()); // 2 * (10 + 5)
}

void test_rectangle_translation(void) {
    point centre(0, 0);
    Rectangle rect(10, 10, centre);
    point vecteur(5, 2);

    rect += vecteur; // Utilisation de la surcharge += héritée ou définie [cite: 17, 24]

    TEST_ASSERT_EQUAL_INT(5, rect.getOriginX());
    TEST_ASSERT_EQUAL_INT(2, rect.getOriginY());
}

void test_carre_logic(void) {
    point centre(0, 0);
    double cote = 4.0;
    Carre c(cote, centre);

    // Vérifie que longueur et largeur sont identiques
    TEST_ASSERT_EQUAL_FLOAT(4.0, c.getLongueur());
    TEST_ASSERT_EQUAL_FLOAT(4.0, c.getLargeur());

    // Vérifie les calculs hérités du Rectangle
    // Surface : 4 * 4 = 16
    TEST_ASSERT_EQUAL_FLOAT(16.0, c.surface());
    // Périmètre : 2 * (4 + 4) = 16
    TEST_ASSERT_EQUAL_FLOAT(16.0, c.perimetre());
}

void test_carre_display(void) {
    point p(1, 2);
    Carre c(10.0, p);
    
    // On peut tester visuellement avec cout ou vérifier que l'objet est bien construit
    cout << "Test affichage Carre : " << c << endl;
    TEST_ASSERT_EQUAL_FLOAT(10.0, c.getLongueur());
}

// Test de l'initialisation et du rayon
void test_cercle_initialization(void) {
    point p(10, 10);
    Cercle c(p, 5.0);
    
    TEST_ASSERT_EQUAL_FLOAT(5.0, c.getRayon());
    TEST_ASSERT_EQUAL_INT(10, c.getOriginX());
}

// Test des calculs géométriques
void test_cercle_geometry(void) {
    point p(0, 0);
    double r = 10.0;
    Cercle c(p, r);

    // Surface : PI * r^2 = 3.14 * 100 = 314
    TEST_ASSERT_EQUAL_FLOAT(314.0, c.surface());
    
    // Périmètre : 2 * PI * r = 2 * 3.14 * 10 = 62.8
    TEST_ASSERT_EQUAL_FLOAT(62.8, c.perimetre());
}

// Test de la translation (héritée de Forme)
void test_cercle_translation(void) {
    point centre(1, 1);
    Cercle c(centre, 5.0);
    point dep(4, 4);
    
    c += dep; // Utilise la surcharge héritée

    TEST_ASSERT_EQUAL_INT(5, c.getOriginX());
    TEST_ASSERT_EQUAL_INT(5, c.getOriginY());
}

void test_liste_ajout_et_surface(void) {
    ListeForme maListe;
    
    // Ajout d'un carré de 10x10 (Surface 100)
    point p1(0, 0);
    maListe.addForme(new Carre(10.0, p1));
    
    // Ajout d'un cercle de rayon 5 (Surface ~78.5)
    point p2(10, 10);
    maListe.addForme(new Cercle(p2, 5.0));
    
    // Test de la surface totale (100 + 3.14 * 25)
    double attendu = 100.0 + (3.14 * 25.0);
    TEST_ASSERT_EQUAL_FLOAT(attendu, maListe.surface());
}

void test_liste_suppression(void) {
    ListeForme maListe;
    maListe.addForme(new Rectangle(10, 5, point(0,0)));
    maListe.addForme(new Carre(5, point(10,10)));
        
    maListe.suprForme(0); // Supprime le rectangle
    
    // Il ne doit rester que le carré (surface 25)
    TEST_ASSERT_EQUAL_FLOAT(25.0, maListe.surface());
}

void test_liste_boite_englobante(void) {
    ListeForme maListe;
    // Un carré au centre (0,0) de côté 2 -> Limites X: [-1, 1], Y: [-1, 1]
    maListe.addForme(new Carre(2.0, point(0,0)));
    
    // Un cercle au centre (10,10) de rayon 2 -> Limites X: [8, 12], Y: [8, 12]
    maListe.addForme(new Cercle(point(10,10), 2.0));
    
    Rectangle b = maListe.boite();
    
    // La boîte doit aller de X=-1 à X=12 (Longueur 13)
    // Et de Y=-1 à Y=12 (Largeur 13)
    TEST_ASSERT_EQUAL_FLOAT(13.0, b.getLongueur());
    TEST_ASSERT_EQUAL_FLOAT(13.0, b.getLargeur());
}

// --- MAIN ---
int main(void) {
    UNITY_BEGIN();

    //Test point
    RUN_TEST(test_point_initialization);
    RUN_TEST(test_point_copy_constructor);
    RUN_TEST(test_point_setters);
    RUN_TEST(test_point_translation);
    //Test rectangle
    RUN_TEST(test_rectangle_logic);
    RUN_TEST(test_rectangle_translation);
    //test carre 
    RUN_TEST(test_carre_logic);
    RUN_TEST(test_carre_display);
    //Test rectangle
    RUN_TEST(test_cercle_initialization);
    RUN_TEST(test_cercle_geometry);
    RUN_TEST(test_cercle_translation);

    //test class
    RUN_TEST(test_liste_ajout_et_surface);
    RUN_TEST(test_liste_suppression);
    RUN_TEST(test_liste_boite_englobante);


    return UNITY_END();
}