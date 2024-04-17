#pragma once
#include "common/utils.hpp"
#include "common/Graph.hpp"
#include "common/GameObject.hpp"
#include "Plan.hpp"
#include "CubeInit.hpp"
#include "Camera.hpp"
#include "Mesh.hpp"

class Scene {
    
private:
    std::vector<Node> node_list;
    std::vector<GameObject*> camera_list;

public:
    Scene(){} 
    
    std::vector<GameObject*> get_children_list(Node & n){return n.getDescendantsData();}
    std::vector<Node> get_node_list(){return node_list;}
    std::vector<GameObject*> get_camera_list(){return camera_list;}
    
    Node make_node_camera(bool is_locked, unsigned int w , unsigned int h); // 1er parametre pour savoir si la camera peut yaw a 360 degree
    Node make_node_plan(int longeur, int largeur);
    Node make_node_cube();
    Node make_node_mesh(const std::string & path);
    GameObject* get_data(Node & n){return n.getData();}
    

    
    void initscene();
    void drawscene(glm::mat4 & vm ,glm::mat4 & pm, Node & n);
    void deletescene();
    void loadtexturesinscene();
    void resetmodelmatrix(Node & n);
    
    void calculateBoundingBoxRecursive(Node& node);
    //////SCALE/////////////////////
    void scalenode(Node & node , glm::vec3 scale){ // pour scale tout un noeud et ses enfants
        std::vector<GameObject*>  children_data =  get_children_list(node);
        for (GameObject* go : children_data){
            go->setscale(scale);
        }      
    }

    //////TRANSLATE////////////////
    void translatenode(Node & node , glm::vec3 translate){ // pour translate tout un noeud et ses enfants
        std::vector<GameObject*>  children_data =  get_children_list(node);
        for (GameObject* go : children_data){
            go->settranslate(translate);
        }        
    }
    //////ROTATE//////////////////
    void rotatenode(Node & node , float angle , glm::vec3 axe){ // pour scale tout les enfants du noeud recursivement
        std::vector<GameObject*> children_data =  get_children_list(node);
        for (GameObject* go : children_data){
            go->setrotate(angle , axe);
        }           
    }
  
    ///////////////////////////

    
    
   
//scene mouvement system stellaire
//  {
//      s.rotatenode(soleil , angle/1.5 , glm::vec3(0.f,1.f,0.f));
//         s.translatenode(terre ,glm::vec3(6.f,0.0f,0.f));
//         s.scalenode(terre , glm::vec3(0.5f));
// 
//         s.rotatenode(terre , angle , glm::vec3(0.0f,1.f,0.f));
//         s.translatenode(lune ,  glm::vec3(3.f,0.f,0.f));
//         s.scalenode(lune , glm::vec3(0.5f));
// 
//         s.rotatenode(lune , angle , glm::vec3(0.f,1.f,0.f));
//         
//         glm::mat4 vm = camera->getViewMatrix();
//         glm::mat4 pm = camera->getProjectionMatrix();
//         
//         s.drawscene(vm, pm , soleil);
//     
//         s.resetmodelmatrix(soleil);
//      
//  }
    
};

