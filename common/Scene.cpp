#include "Scene.hpp"
Node Scene::make_node(Object o) 
{
    Node n;
    if (o == Object::Heightmap){
        GameObject* go = new Plan(glm::vec3(0.f) , 16 ,16);
        n.add_data(go);
    }
    //         if (o == Object::Sphere) 
   
   
    node_list.push_back(n);
    return node_list[node_list.size() - 1];
}
Node Scene::make_node_mesh(const std::string & path) 
{
    Node n;
    GameObject* go = new Mesh(path);
    n.add_data(go);
    node_list.push_back(n);
    return node_list[node_list.size() - 1];
}

void Scene::resetmodelmatrix(Node & n)
{
    auto l = get_children_list(n);
    for(GameObject* go : l){
        go->setmodelmat(glm::mat4(1.f));
    }
}

void Scene::initscene()
{
    for(Node & n : node_list){
        n.getData()->initobject();
    }
    
}
void Scene::loadtexturesinscene()
{
    for(Node & n : node_list){
        n.getData()->loadtextures();
    }
    
}
void Scene::drawscene(glm::mat4 & vm ,glm::mat4 & pm , Node & n)
{   
    //std::cout<<"in graph : "<< std::endl;
    //std::vector<GameObject*> go_list = get_children_list(n);
    
    auto l = get_children_list(n);
    for(GameObject* go : l){
        glUseProgram(go->getprogID());
        glUniformMatrix4fv(glGetUniformLocation(go->getprogID(),"viewmat"), 1 ,GL_FALSE, &vm[0][0]);
        glUniformMatrix4fv(glGetUniformLocation(go->getprogID(),"projmat"), 1 ,GL_FALSE, &pm[0][0]);
        //std::cout<< "in scene : " << go<< std::endl;
        go->drawobject();
    }
}
void Scene::deletescene()
{   
    for(Node & n : node_list){
        glDeleteProgram(n.getData()->getprogID());
        n.getData()->deleteobject();
    }
}
