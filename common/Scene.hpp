#pragma once
#include "common/utils.hpp"
#include "common/Graph.hpp"
#include "common/GameObject.hpp"
#include "Plan.hpp"
#include "Mur.hpp"
#include "lumiere.hpp"
#include "CubeInit.hpp"
#include "Camera.hpp"
#include "Mesh.hpp"

class Scene {
    
private:
    GLuint lightbuffer;
    std::vector<Node*> node_list;
    Node* player;
    std::vector<GameObject*> camera_list;
    std::vector<GameObject*> event_list;
    std::vector<GameObject*> npc_list;
    std::vector<GLuint> programID_list;
    std::vector<GameObject*> light_list;

public:
    Scene(){} 
    void setNodePlayer(Node* n){player=n;}
    Node* getNodePlayer(){return player;}

    void setprogIdList(std::vector<GLuint>& progID_list){programID_list = progID_list;}

    void removeNodeFromNodeList(Node* n){node_list.erase(std::find(node_list.begin(),node_list.end(),n));}
    
    std::vector<GameObject*> get_children_list(Node & n){return n.getDescendantsData();}
    std::vector<Node*>& get_node_list(){return node_list;}
    std::vector<GameObject*>& get_camera_list(){return camera_list;}
    std::vector<GameObject*>& get_event_list(){return event_list;}
    std::vector<GameObject*>& get_npc_list(){return npc_list;}
    std::vector<GameObject*>& get_light_list(){return light_list;}
    
    Node* make_node_camera(bool is_locked, unsigned int w , unsigned int h, unsigned int  indice_programID); // 1er parametre pour savoir si la camera peut yaw a 360 degree
    Node* make_node_plan(int longeur, int largeur, unsigned int  indice_programID);
    Node* make_node_mur(int longeur, int largeur, unsigned int  indice_programID);
    Node* make_node_cube(unsigned int  indice_programID );
    Node* make_node_npc(unsigned int  indice_programID );
    Node* make_node_light();
    Node* make_node_mesh(const std::string & path, unsigned int  indice_programID);
    Node* make_node_event(typeEvent typeevent, glm::vec3 p, unsigned int  indice_programID);
    GameObject* get_data(Node * n){return n->getData();}
    

    void GenBufferLightInScene(std::vector<glm::vec3> & lightlist);
    void RenderLightInScene();
    void initscene();
    void drawscene(Camera * c, Node * n);
    void deletescene();
    
    void resetmodelmatrix(Node * n);
    
    void calculateBoundingBoxRecursive(Node* node);
    //////SCALE/////////////////////
    void scalenode(Node * node , glm::vec3 scale){ // pour scale tout un noeud et ses enfants
        std::vector<GameObject*>  children_data =  get_children_list(*node);
        for (GameObject* go : children_data){
            go->setscale(scale);
        }      
    }

    //////TRANSLATE////////////////
    void translatenode(Node * node , glm::vec3 translate){ // pour translate tout un noeud et ses enfants
        std::vector<GameObject*>  children_data =  get_children_list(*node);
        for (GameObject* go : children_data){
            go->settranslate(translate);
        }        
    }
    //////ROTATE//////////////////
    void rotatenode(Node * node , float angle , glm::vec3 axe){ // pour scale tout les enfants du noeud recursivement
        std::vector<GameObject*> children_data =  get_children_list(*node);
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

