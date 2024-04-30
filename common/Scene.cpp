#include "Scene.hpp"


Node* Scene::make_node_plan(int longeur = 16, int largeur = 16) 
{
    Node* n= new Node();
    GameObject* go = new Plan(glm::vec3(0.f) , longeur ,largeur);
    n->add_data(go);
    go->calculateBoundingBox();
    node_list.push_back(n);
    return node_list[node_list.size() - 1];
}
Node* Scene::make_node_npc() 
{
    Node* n= new Node();
    GameObject* go = new CubeInit();
    go->getgameObjectInfo().setIsRendered(true);
    go->calculateBoundingBox();
    n->add_data(go);
    node_list.push_back(n);
    npc_list.push_back(go);
    return node_list[node_list.size() - 1];
}
Node* Scene::make_node_camera(bool is_locked, unsigned int w , unsigned int h) 
{
    Node* n= new Node();
    GameObject* go = new Camera(is_locked , w , h);
    go->calculateBoundingBox();
    n->add_data(go);
    node_list.push_back(n);
    camera_list.push_back(go);
    return node_list[node_list.size() - 1];
}   
Node* Scene::make_node_event(typeEvent typeevent, glm::vec3 p){
    Node* n= new Node();
    GameObject* go = new CubeInit();
    go->getgameObjectInfo().setIsEvent(true);
    go->getgameObjectInfo().setIsRendered(true);
    go->calculateBoundingBox();
    Event ev(typeevent, p);
    go->setEvent(ev);
    go->set_color(glm::vec3(0.1,1.0,0.2));
    n->add_data(go);
    
    node_list.push_back(n);
    event_list.push_back(go);
    return node_list[node_list.size() - 1];
}

Node* Scene::make_node_cube() 
{
    Node* n= new Node();
    GameObject* go = new CubeInit();
    go->calculateBoundingBox();
    n->add_data(go);
    node_list.push_back(n);
    return node_list[node_list.size() - 1];
}  

Node* Scene::make_node_mesh(const std::string & path) 
{
    Node* n= new Node();
    GameObject* go = new Mesh(path);
    go->calculateBoundingBox();
    n->add_data(go);
    node_list.push_back(n);
    return node_list[node_list.size() - 1];
}

void Scene::resetmodelmatrix(Node* n)
{
    auto l = get_children_list(*n);
    for(GameObject* go : l){
        go->setmodelmat(glm::mat4(1.f));
    }
}

void Scene::initscene()
{
    for(Node * n : node_list){
        GameObject * go = n->getData();
        if (go->is_rendered){go->initobject();}
    }
    
}
void Scene::loadtexturesinscene()
{
    for(Node * n : node_list){
        GameObject * go = n->getData();
        if (go->is_rendered) go->loadtextures();
    }
    
}
void Scene::drawscene(glm::mat4 & vm ,glm::mat4 & pm , Node* n)
{   
   
    auto l = get_children_list(*n);
    for(GameObject* go : l){
        if (go->is_rendered) 
        {
            glUseProgram(go->getprogID());
            glUniformMatrix4fv(glGetUniformLocation(go->getprogID(),"viewmat"), 1 ,GL_FALSE, &vm[0][0]);
            glUniformMatrix4fv(glGetUniformLocation(go->getprogID(),"projmat"), 1 ,GL_FALSE, &pm[0][0]);
            go->drawobject();
        }
    }
}
void Scene::deletescene()
{   
    for(Node * n : node_list){
        GameObject * go = n->getData();
        if (go->is_rendered){
            glDeleteProgram(go->getprogID());
            go->deleteobject();
        }
    }
}

// Fonction récursive pour calculer les boîtes englobantes des enfants d'un nœud
void Scene::calculateBoundingBoxRecursive(Node* node) {
    std::vector<GameObject*> children = get_children_list(*node);

    for (GameObject* child : children) {
        child->calculateBoundingBox();
        }
}
