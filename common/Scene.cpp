#include "Scene.hpp"
void Scene::GenBufferLightInScene(std::vector<glm::vec3> & lightlist)
{
    
    glGenBuffers(1, &lightbuffer);
    glBindBuffer(GL_ARRAY_BUFFER, lightbuffer);
    glBufferData(GL_ARRAY_BUFFER, lightlist.size() * sizeof(glm::vec3), &(lightlist)[0], GL_STATIC_DRAW);
    
}

void Scene::RenderLightInScene()
{
    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, lightbuffer);
    glVertexAttribPointer(
        0,                  // attribute
        3,                  // size
        GL_FLOAT,           // type
        GL_FALSE,           // normalized?
        0,                     // stride
        (void*)0            // array buffer offset
    ); 
    
    glDisableVertexAttribArray(0);
}

Node* Scene::make_node_plan(int longeur , int largeur , unsigned int indice_programID ) 
{
    Node* n= new Node();
    GameObject* go = new Plan(glm::vec3(0.f) , longeur ,largeur);
    go->setprogId(programID_list[indice_programID]);
    n->add_data(go);
    go->calculateBoundingBox();
    node_list.push_back(n);
    return node_list[node_list.size() - 1];
}
Node* Scene::make_node_mur(int longeur, int largeur ,unsigned int indice_programID) 
{
    Node* n= new Node();
    GameObject* go = new Mur(glm::vec3(0.f) , longeur ,largeur);
    go->setprogId(programID_list[indice_programID]);
    n->add_data(go);
    go->calculateBoundingBox();
    node_list.push_back(n);
    return node_list[node_list.size() - 1];
}
Node* Scene::make_node_npc(unsigned int indice_programID) 
{
    Node* n= new Node();
    GameObject* go = new CubeInit();
    go->setprogId(programID_list[indice_programID]);

    go->calculateBoundingBox();
    n->add_data(go);
    node_list.push_back(n);
    npc_list.push_back(go);
    return node_list[node_list.size() - 1];
}
Node* Scene::make_node_npc_mesh(const std::string & path, unsigned int indice_programID) 
{
    Node* n= new Node();
    GameObject* go = new Mesh(path);
    go->setprogId(programID_list[indice_programID]);
    go->calculateBoundingBox();
    n->add_data(go);
    node_list.push_back(n);
    npc_list.push_back(go);
    return node_list[node_list.size() - 1];
}
Node* Scene::make_node_camera(bool is_locked, unsigned int w , unsigned int h,unsigned int indice_programID) 
{
    Node* n= new Node();
    GameObject* go = new Camera(is_locked , w , h);
    go->setprogId(programID_list[indice_programID]);
    go->getgameObjectInfo().setIsRendered(false);
    go->getgameObjectInfo().setIsCamera(true);
    n->add_data(go);
    node_list.push_back(n);
    camera_list.push_back(go);
    return node_list[node_list.size() - 1];
}   
Node* Scene::make_node_event(typeEvent typeevent, glm::vec3 p,unsigned int indice_programID){
    Node* n= new Node();
    GameObject* go = new CubeInit();
    go->setprogId(programID_list[indice_programID]);
    go->getgameObjectInfo().setIsEvent(true);
    go->calculateBoundingBox();
    Event ev(typeevent, p);
    go->setEvent(ev);
    go->set_color(glm::vec3(0.1,1.0,0.2));
    n->add_data(go);
    node_list.push_back(n);
    event_list.push_back(go);
    return node_list[node_list.size() - 1];
}

Node* Scene::make_node_event(typeEvent typeevent,int longeur, int largeur, unsigned int cam_i,unsigned int indice_programID){
    Node* n= new Node();
    GameObject* go = new Plan(glm::vec3(0.f) , longeur ,largeur);
    go->setprogId(programID_list[indice_programID]);
    go->getgameObjectInfo().setIsEvent(true);
    go->getgameObjectInfo().setIsRendered(false);
    go->calculateBoundingBox();
    Event ev(typeevent, cam_i);
    go->setEvent(ev);
    go->set_color(glm::vec3(0.1,1.0,0.2));
    n->add_data(go);
    node_list.push_back(n);
    event_list.push_back(go);
    return node_list[node_list.size() - 1];
}

Node* Scene::make_node_cube(unsigned int indice_programID) 
{
    Node* n= new Node();
    GameObject* go = new CubeInit();
    go->setprogId(programID_list[indice_programID]);
    go->calculateBoundingBox();
    n->add_data(go);
    node_list.push_back(n);
    return node_list[node_list.size() - 1];
}  

Node* Scene::make_node_mesh(const std::string & path, unsigned int indice_programID) 
{
    Node* n= new Node();
    GameObject* go = new Mesh(path);
    go->setprogId(programID_list[indice_programID]);
    go->calculateBoundingBox();
    n->add_data(go);
    node_list.push_back(n);
    return node_list[node_list.size() - 1];
}
Node* Scene::make_node_light()
{
    Node* n= new Node();
    GameObject* go = new Light();
    n->add_data(go);
    light_list.push_back(go);
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
    std::vector<glm::vec3> pos_dir_lights;
    for(GameObject* light : light_list)
    {
        pos_dir_lights.push_back(light->getpos());
       // pos_dir_lights.push_back(light->get_front());
    }
    GenBufferLightInScene(pos_dir_lights);
    
    for(Node * n : node_list){
        GameObject * go = n->getData();
        if (go->getgameObjectInfo().getIsRendered()){go->initobject();}
    }
    
}

void Scene::drawscene(Camera* camera, Node* n)
{   
    GameObject *camera_temp = static_cast<GameObject*>(camera); 
    glm::mat4 vm = camera->getViewMatrix();
    glm::mat4 pm = camera->getProjectionMatrix();
    
    auto l = get_children_list(*n);
    //std::cout<<l.size()<<std::endl;
    
    for(GameObject* go : l){
        if (go->getgameObjectInfo().getIsRendered()) 
        {
            //std::cout << go << std::endl;
            //go->initobject();
            glUseProgram(go->getprogID());
            glUniformMatrix4fv(glGetUniformLocation(go->getprogID(),"viewmat"), 1 ,GL_FALSE, &vm[0][0]);
            glUniformMatrix4fv(glGetUniformLocation(go->getprogID(),"projmat"), 1 ,GL_FALSE, &pm[0][0]);
            glUniformMatrix3fv(glGetUniformLocation(go->getprogID(),"pos_camera"), 1 ,GL_FALSE, &(camera_temp->getpos()[0]));
            RenderLightInScene();
            go->drawobject();
            
            glUseProgram(0);
        }
    }

}

void Scene::deletescene()
{   
    for(Node * n : node_list){
        GameObject * go = n->getData();
        if (go->getgameObjectInfo().getIsRendered()){
            glDeleteProgram(go->getprogID());
            go->deleteobject();
        }
    }
    node_list.clear();
    camera_list.clear();
    event_list.clear();
    npc_list.clear();
    programID_list.clear();
    light_list.clear();
}
void Scene::resetscene()
{   
    for(Node * n : node_list){
        GameObject * go = n->getData();
        go->deleteobject();
        
    }
    node_list.clear();
    camera_list.clear();
    event_list.clear();
    npc_list.clear();
    programID_list.clear();
    light_list.clear();
}

// Fonction récursive pour calculer les boîtes englobantes des enfants d'un nœud
void Scene::calculateBoundingBoxRecursive(Node* node) {
    std::vector<GameObject*> children = get_children_list(*node);

    for (GameObject* child : children) {
        child->calculateBoundingBox();
        }
}
