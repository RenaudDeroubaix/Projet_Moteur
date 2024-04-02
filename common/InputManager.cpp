#include "InputManager.hpp"


InputManager::InputManager()
{
    
    
    if( !glfwInit() )
        {
            fprintf( stderr, "Failed to initialize GLFW\n" );
            getchar();
        }
    
    
}
InputManager::~InputManager()
{
    glfwTerminate();
}

bool InputManager::isKeyDown(int key) const
{
    return glfwGetKey(glfwGetCurrentContext(), key) == GLFW_PRESS;
}
bool InputManager::isKeyPressed(int key) 
{
    // Stocker l'état précédent de la touche
    static bool previousState[GLFW_KEY_LAST] = { false };
    
    // Déterminer si la touche est pressée et si elle ne l'était pas auparavant
    bool currentState = isKeyDown(key);
    bool isPressed = currentState && !previousState[key];
    
    // Mettre à jour l'état précédent
    previousState[key] = currentState;
    
    return isPressed;
}
bool InputManager::isKeyHeld(int key)
{
    // Déterminer si la touche est pressée
    return isKeyDown(key);
}

void InputManager::onMouseMove(GLFWwindow* window, double xpos, double ypos)
{
    // Calculer le déplacement de la souris
    deltaX = previousX - xpos;
    deltaY =  previousY - ypos;
    
    // Stocker la position actuelle de la souris
    previousX = xpos;
    previousY = ypos;
}

void InputManager::Input_Camera(Camera *c , float deltaTime)
{
    
    //Keyboard control camera
    float cameraSpeed = 2.5 * deltaTime;
    
    //         if (isKeyHeld(GLFW_KEY_6))
    //             c->camera_translate(-cameraSpeed * c->target_vector());
    //         if (isKeyHeld(GLFW_KEY_EQUAL))
    //             c->camera_translate(cameraSpeed * c->target_vector());
    if (isKeyHeld(GLFW_KEY_W))
        c->camera_translate(cameraSpeed * c->target_vector());
    if (isKeyHeld( GLFW_KEY_S))
        c->camera_translate(-cameraSpeed * c->target_vector());
    if (isKeyHeld(GLFW_KEY_D))
        c->camera_translate(cameraSpeed * c->right_vector());
    if (isKeyHeld(GLFW_KEY_A))
        c->camera_translate(-cameraSpeed * c->right_vector());
    if (isKeyPressed(GLFW_KEY_C))
        c->set_orbital(!c->get_orbital());
    
    //Mouse control camera
    c->rotateCamera(deltaX/c->getw() , deltaY/c->getw());
    deltaX = 0.0; deltaY = 0.0;
    glfwSetCursorPosCallback(glfwGetCurrentContext(), onMouseMove);
    
}
void InputManager::Input_GameObject(GameObject * go , float deltaTime)
{
    //Keyboard control camera
    float playerSpeed = 1. * deltaTime;
    
    //         if (isKeyHeld(GLFW_KEY_6))
    //             c->camera_translate(-cameraSpeed * c->target_vector());
    //         if (isKeyHeld(GLFW_KEY_EQUAL))
    //             c->camera_translate(cameraSpeed * c->target_vector());
    if (isKeyHeld(GLFW_KEY_UP))
        go->settranslate(-playerSpeed * glm::vec3(0.f , 0.f , 1.f));
    if (isKeyHeld( GLFW_KEY_DOWN))
        go->settranslate(playerSpeed * glm::vec3(0.f , 0.f , 1.f));
    if (isKeyHeld(GLFW_KEY_RIGHT))
        go->settranslate(playerSpeed * glm::vec3(1.f , 0.f , 0.f));
    if (isKeyHeld(GLFW_KEY_LEFT))
        go->settranslate(-playerSpeed  * glm::vec3(1.f , 0.f , 0.f));
 
    
}
