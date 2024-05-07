#include "Scene.hpp"
void Scene::SendLightInShader()
{
    for (int i = 0 ; i < light_list.size() ; i++ ){
        GLuint lightposlocation = glGetUniformLocation(light_list[i]->getprogID() , std::string("light_pos["+ std::to_string(i)+"]").c_str());
        GLuint lightcollocation = glGetUniformLocation(light_list[i]->getprogID() , std::string("light_col["+ std::to_string(i)+"]").c_str());
        glUniform3fv(lightposlocation , 1 , &(light_list[i]->getpos())[0]);
        glUniform3fv(lightcollocation , 1 , &(light_list[i]->getcolor())[0]);
    }
     glUniform1i(glGetUniformLocation(light_list[0]->getprogID() , "numberOfLight") , light_list.size());
    
}
// void Scene::RenderLightInScene()
// {
//         glEnableVertexAttribArray(3);
//         glBindVertexArray(lightbuffer[0]);
//         glDrawArrays(
//         GL_POINTS,      // mode
//         0,    
//         light_list.size()         
//         );
//         glDisableVertexAttribArray(2);
//         glBindVertexArray(0);
//    
// 
// }

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
Node* Scene::make_node_event(typeEvent typeevent,unsigned int indice_programID){
    Node* n= new Node();
    GameObject* go = new CubeInit();
    go->setprogId(programID_list[indice_programID]);
    go->getgameObjectInfo().setIsEvent(true);
    go->calculateBoundingBox();
    Event ev(typeevent);
    go->setEvent(ev);
    go->set_color(glm::vec3(0.1,1.0,0.2));
    n->add_data(go);
    node_list.push_back(n);
    event_list.push_back(go);
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
Node* Scene::make_node_light(unsigned int indice_programID)
{
    Node* n= new Node();
    GameObject* go = new Light();
    go->getgameObjectInfo().setIsRendered(false);
    go->setprogId(programID_list[indice_programID]);
    n->add_data(go);
    if (light_list.size() <  20) {
        light_list.push_back(go);
        node_list.push_back(n);
    }else {
     std::cout<< "max light set to 20"<<std::endl;   
    }
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
        if (go->getgameObjectInfo().getIsRendered()){go->initobject();

            glBindVertexArray(0);}
    }
    //
     

    
}

void Scene::drawscene(Camera* camera, Node* n)
{   
    GameObject *camera_temp = static_cast<GameObject*>(camera); 
    glm::mat4 vm = camera->getViewMatrix();
    glm::mat4 pm = camera->getProjectionMatrix();
         //RenderLightInScene();

    auto l = get_children_list(*n);
    //std::cout<<l.size()<<std::endl;
    
    for(GameObject* go : l){
        if (go->getgameObjectInfo().getIsRendered()) 
        {

            //std::cout << go << std::endl;
            glUseProgram(go->getprogID());
            glUniformMatrix4fv(glGetUniformLocation(go->getprogID(),"viewmat"), 1 ,GL_FALSE, &vm[0][0]);
            glUniformMatrix4fv(glGetUniformLocation(go->getprogID(),"projmat"), 1 ,GL_FALSE, &pm[0][0]);
            glUniformMatrix3fv(glGetUniformLocation(go->getprogID(),"pos_camera_worldspace"), 1 ,GL_FALSE, &(camera_temp->getpos()[0]));
            go->drawobject();
            SendLightInShader();
            glBindVertexArray(0);
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
        if(child->getgameObjectInfo().getIsCamera() == false){
            child->calculateBoundingBox();
            child->updateBoundingBox();
        }
    }
}
