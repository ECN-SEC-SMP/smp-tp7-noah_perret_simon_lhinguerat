#include "unity.h"
#include "class.hpp"

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

// --- MAIN ---
int main(void) {
    UNITY_BEGIN();

    RUN_TEST(test_point_initialization);
    RUN_TEST(test_point_copy_constructor);
    RUN_TEST(test_point_setters);
    RUN_TEST(test_point_translation);

    return UNITY_END();
}