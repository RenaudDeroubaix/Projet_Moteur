#pragma once
#include "common/utils.hpp"
#include "common/Camera.hpp"
#include "common/GameObject.hpp"
 
class InputManager {
public:
    static double previousX;
    static double previousY;
    static double deltaX;
    static double deltaY;
    
    InputManager();
    ~InputManager();

    bool isKeyDown(int key) const; 

    bool isKeyPressed(int key); 

    bool isKeyHeld(int key);
    
    static void onMouseMove(GLFWwindow* window, double xpos, double ypos); 
    
    void Input_Camera(Camera *c , float deltaTime);
    void Input_GameObject(GameObject * go, float deltaTime);
    
};

