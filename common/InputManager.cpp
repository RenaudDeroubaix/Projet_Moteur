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


void InputManager::Input_GameObject(Camera *c ,GameObject * go , float deltaTime)
{
    //Keyboard control camera
   
    float playerSpeed = 0.1 * deltaTime;
    //         if (isKeyHeld(GLFW_KEY_6))
    //             c->camera_translate(-cameraSpeed * c->target_vector());
    //         if (isKeyHeld(GLFW_KEY_EQUAL))
    //             c->camera_translate(cameraSpeed * c->target_vector());
    bool b = true;
    if (isKeyHeld(GLFW_KEY_UP)){
        go->addVitesse(glm::vec3(0.0 , 0.0 , -playerSpeed));
        b = false;
    }
    if (isKeyHeld( GLFW_KEY_DOWN)){
        go->addVitesse(glm::vec3(0.f , 0.f , playerSpeed));
        b = false;
    }
    if (isKeyHeld(GLFW_KEY_RIGHT)){
        go->addVitesse(glm::vec3(playerSpeed , 0.f , 0.f));
        b = false;
    }
    if (isKeyHeld(GLFW_KEY_LEFT)){
        go->addVitesse(glm::vec3(-playerSpeed, 0.f , 0.f));
        b = false;
    }
    if (isKeyPressed(GLFW_KEY_SPACE)){
        glm::vec3 translation=(go->getpos()- c->getPos()) *glm::vec3(-1);
       
        go->settranslate(translation); 
        glm::vec3 direction = glm::normalize(c->target_vector());

        float speed = 10.0f; 
        glm::vec3 velocity = direction * speed * deltaTime;
        go->setVitesse(velocity);
        //std::cout << c->target_vector().x <<" "<< c->target_vector().y <<" "<<c->target_vector().z << std::endl;
        
        b = false;
    }
    if (b) {
        //go->setVitesse(glm::vec3(0.0));
        go->reduceVitesse(playerSpeed);
    }
}