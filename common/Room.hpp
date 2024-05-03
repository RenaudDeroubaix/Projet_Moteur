#include "common/utils.hpp"

Node * makeRoom(Scene &s, int longueur, int largeur, int hauteur, glm::vec3 scale, unsigned int indice_progId){
    float scale_plan = 1.0;
    // float pas_h  = 1. /  (float)hauteur;
    // float pas_la  = 1. /  (float)largeur;
    // float pas_lo  = 1. /  (float)longueur;

    // Création des éléments de la salle centrés en 0.0
    Node *sol = s.make_node_plan(longueur, largeur, indice_progId);
    Node* plafond = s.make_node_plan(longueur, largeur, indice_progId);
    Node* mur1 = s.make_node_plan(longueur, hauteur, indice_progId);
    Node* mur2 = s.make_node_plan(longueur, hauteur, indice_progId);
    Node* mur3 = s.make_node_plan(hauteur, largeur, indice_progId);
    Node* mur4 = s.make_node_plan(hauteur, largeur, indice_progId);




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
    sol->addChild(plafond);
    sol->addChild(mur1);
    sol->addChild(mur2);
    sol->addChild(mur3);
    sol->addChild(mur4);

    // Scale de la salle entière
    s.scalenode(sol, scale);

    // Attribution des couleurs
    s.get_data(sol)->set_color(glm::vec3(1.f)); //blanc
    s.get_data(plafond)->set_color(glm::vec3(1.f)); //blanc
    s.get_data(mur1)->set_color(glm::vec3(1.f)); //blanc
    s.get_data(mur2)->set_color(glm::vec3(1.f)); //blanc
    s.get_data(mur3)->set_color(glm::vec3(1.f)); //blanc
    s.get_data(mur4)->set_color(glm::vec3(1.f)); //blanc
    
    // Attribution des textures
    std::cout << "set texture .. "<< std::endl;
    s.get_data(sol)->settexture("../src/textures/ground.png" , s.get_data(sol)->getprogID() ,  "tex"); 
    s.get_data(mur1)->settexture("../src/textures/wall1.png" , s.get_data(mur1)->getprogID() , "tex");
    s.get_data(mur2)->settexture("../src/textures/wall1.png" , s.get_data(mur2)->getprogID() , "tex");
    s.get_data(mur3)->settexture("../src/textures/wall1.png" , s.get_data(mur3)->getprogID() , "tex"); 
    s.get_data(mur4)->settexture("../src/textures/wall1.png" , s.get_data(mur4)->getprogID() , "tex"); 
    std::cout << "end set texture "<< std::endl;
    
    

    std::cout <<"fin make room" << std::endl;
    return sol;
}
