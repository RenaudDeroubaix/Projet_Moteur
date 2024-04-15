#include "common/utils.hpp"

void makeRoom(Scene &s, int longueur, int largeur, int hauteur, glm::vec3 scale, Node &sol){
    float scale_plan = 0.1;
    float pas_h  = 1. /  (float)hauteur;
    float pas_la  = 1. /  (float)largeur;
    float pas_lo  = 1. /  (float)longueur;

    // Création des éléments de la salle centrés en 0.0
    sol = s.make_node(Plane, longueur, largeur);
    Node plafond = s.make_node(Plane, longueur, largeur);
    Node mur1 = s.make_node(Plane, longueur, hauteur);
    Node mur2 = s.make_node(Plane, longueur, hauteur);
    Node mur3 = s.make_node(Plane, hauteur, largeur);
    Node mur4 = s.make_node(Plane, hauteur, largeur);




    // Rotation et translation des éléments
    s.rotatenode(plafond, 180, glm::vec3(0.0, 0.0, 1.0));
    s.translatenode(plafond, glm::vec3(0.0, (hauteur- 1 ) * scale_plan, 0.0));

    s.rotatenode(mur1, 90.f, glm::vec3(1.0, 0.0, 0.0));
    s.rotatenode(mur2, 90.f, glm::vec3(1.0, 0.0, 0.0));
    s.rotatenode(mur3, 90.f, glm::vec3(0.0, 0.0, 1.0));
    s.rotatenode(mur4, 90.f, glm::vec3(0.0, 0.0, 1.0));

    s.translatenode(mur1, glm::vec3(0.0, (hauteur- 1 )/2.0 * scale_plan , (largeur-1 )/2.0 * scale_plan ));
    s.translatenode(mur2, glm::vec3(0.0, (hauteur- 1 )/2.0 * scale_plan, -(largeur-1 )/2.0 * scale_plan));
    s.translatenode(mur3, glm::vec3(-(longueur-1)/2.0 * scale_plan, (hauteur- 1 )/2.0 * scale_plan, 0.0));
    s.translatenode(mur4, glm::vec3((longueur-1)/2.0 * scale_plan, (hauteur- 1 )/2.0 * scale_plan, 0.0));

    // Ajout des enfants à sol
    sol.addChild(plafond);
    sol.addChild(mur1);
    sol.addChild(mur2);
    sol.addChild(mur3);
    sol.addChild(mur4);

    // Scale de la salle entière
    s.scalenode(sol, scale);

    // Attribution des couleurs
    s.get_data(sol)->set_color(glm::vec3(0.9f , 0.9f, 0.9f)); //blanc
    s.get_data(plafond)->set_color(glm::vec3(0.5f , 0.0f, 0.9f)); //violet
    s.get_data(mur1)->set_color(glm::vec3(0.9f , 0.0f, 0.0f)); //rouge
    s.get_data(mur2)->set_color(glm::vec3(0.9f , 0.5f, 0.1f)); //orange
    s.get_data(mur3)->set_color(glm::vec3(0.1f , 0.5f, 0.1f));  //vert
    s.get_data(mur4)->set_color(glm::vec3(0.0f , 0.5f, 0.9f)); //bleu

    std::cout <<"fin make room" << std::endl;
}
