#pragma once
#include "common/utils.hpp"
#include "common/GameObject.hpp"

class Node {
private:
    std::vector<Node> children;
    std::vector<Node> parent;
    GameObject* data;

public:
    Node(){}
    ~Node(){}
    void add_data(GameObject* data) {this->data = data;}
    GameObject* getData() {return data;}
    void addChild(Node & child) ;
    void addParent(Node & p);
    std::vector<Node> getDescendantsNode() ;
    std::vector<GameObject*> getDescendantsData() ;

    
};

// Définition de la classe NTree
// class NTree {
// private:
//     Node* root;
//     
// public:
//     NTree(){}
//     NTree(Node* root) {
//         this->root = root;
//     }
//     
//     
//     obtenir la liste des noeuds
//     std::vector<Node*> getNodes(){
//         std::vector<Node*> nodes;
//         nodes.push_back(root);
//         std::vector<Node*> descendants = root->getDescendants();
//         nodes.insert(nodes.end(), descendants.begin(), descendants.end());
//         return nodes;
//         
//     }
//     
//     Obtenir la liste des données de toutes les data de noeuds
//     std::vector<GameObject*> getNodesData() {
//         std::vector<GameObject*> nodesData;
//         std::vector<GameObject*> descendantsData = root->getDescendantsData();
//         nodesData.insert(nodesData.end(), descendantsData.begin(), descendantsData.end());
//         return nodesData;
//     }
//     
//     Obtenir la liste de data des descendants d'un noeud spécifique
//     std::vector<GameObject*> getNodeDescendantsData(Node* node) {
//         std::vector<GameObject*>  descendantsData = node->getDescendantsData();
//         return descendantsData;
//     }
//     std::vector<Node*> getNodeDescendants(Node* node) {
//         std::vector<Node*> descendants= node->getDescendants();
//         return descendants;
//     }
// };
