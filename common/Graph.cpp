
#include "common/Graph.hpp"

void Node::addChild(Node & child) 
{
    children.push_back(child); 
    child.parent.push_back(*this);
}

// Obtenir la liste des noeuds descendants
    std::vector<Node> Node::getDescendantsNode() {
        std::vector<Node> descendants;
        for (auto child : children) {
            descendants.push_back(child);
            auto childDescendants = child.getDescendantsNode();
            descendants.insert(descendants.end(), childDescendants.begin(), childDescendants.end());
        }
        return descendants;
    }

    // Obtenir la liste des données des noeuds descendants
    std::vector<GameObject*>  Node::getDescendantsData() {
        std::vector<Node> descendants = getDescendantsNode();
        std::vector<GameObject*> listdata = {this->getData()};
        for (auto descendant : descendants) {
            listdata.push_back(descendant.getData());
        }
        return listdata;
    }
