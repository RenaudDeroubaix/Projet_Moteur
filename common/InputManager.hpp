#pragma once
#include "common/utils.hpp"
#include "common/GameObject.hpp"
#include "common/Helper.hpp"
#include "common/Camera.hpp"
#include "common/Scene.hpp"

class InputManager {
public:
   
    InputManager();
    ~InputManager();
    
    bool isKeyDown(int key) const; 

    bool isKeyPressed(int key); 

    bool isKeyHeld(int key);
    
    static void onMouseMove(GLFWwindow* window, double xpos, double ypos); 
    
    //void Input_Camera(float deltaTime);
    void Input_SecurityCam(GameObject * go ,float deltaTime);
    void Input_GameObject(GameObject * go, float deltaTime);
    void Input_ViewMode(Scene & s, GameObject* player);
    void Input_GamePlay(Scene & s , GameObject * go , float deltaTime);
    bool Input_light_on_off();
public:
    static double previousX;
    static double previousY;
    static unsigned int view;
    Camera* current_cam;
    
    void Input_Camera(Camera *c , float deltaTime);
    
};

