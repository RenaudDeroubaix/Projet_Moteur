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

// void InputManager::onMouseMove(GLFWwindow* window, double xpos, double ypos)
// {
//     Calculer le déplacement de la souris
//     deltaX = previousX - xpos;
//     deltaY =  previousY - ypos;
//     
//     Stocker la position actuelle de la souris
//     previousX = xpos;
//     previousY = ypos;
// }

// void InputManager::Input_Camera(float deltaTime)
// {
//     
//     Keyboard control camera
//     float cameraSpeed = current_cam->get_speed() * deltaTime;
//     
//     if (isKeyHeld(GLFW_KEY_6))
//                 c->camera_translate(-cameraSpeed * c->target_vector());
//     if (isKeyHeld(GLFW_KEY_EQUAL))
//                 c->camera_translate(cameraSpeed * c->target_vector());
//     if (isKeyHeld(GLFW_KEY_W))
//         current_cam->settranslate(cameraSpeed * current_cam->get_front() );
//     if (isKeyHeld( GLFW_KEY_S))
//         current_cam->settranslate(-cameraSpeed * c->get_front());
//     if (isKeyHeld(GLFW_KEY_D))
//         current_cam->settranslate(cameraSpeed *  c->get_right());
//     if (isKeyHeld(GLFW_KEY_A))
//         current_cam->settranslate(-cameraSpeed  * c->get_right());
//      if (isKeyPressed(GLFW_KEY_C))
//         c->set_orbital(!c->get_orbital());
//     
//     Mouse control camera
// 
//     double mouseX , mouseY;
//     
//     glfwGetCursorPos(glfwGetCurrentContext(), &mouseX , &mouseY);
//     current_cam->setEulerAngle((current_cam->getlastX() - mouseX) * deltaTime * 0.1f, (current_cam->getlastY() - mouseY) * deltaTime * 0.1f );
//  Stocker la position actuelle de la souris
//     current_cam->setlastX(mouseX) ;
//     current_cam->setlastY(mouseY) ;
//     
//     current_cam->rotateCamera();
// }
void InputManager::Input_SecurityCam(GameObject * player  ,float deltaTime)
{
    

    if (isKeyHeld(GLFW_KEY_UP))
    {
        current_cam->setFOV(current_cam->getFOV() - 0.1f);
    }
    if (isKeyHeld(GLFW_KEY_DOWN))
    {
        current_cam->setFOV(current_cam->getFOV() + 0.1f);
    }
    
    double mouseX  , mouseY = 0;
    glfwGetCursorPos(glfwGetCurrentContext(), &mouseX , &mouseY);
    
    current_cam->rotateCamera(previousX - mouseX , previousY - mouseY , deltaTime);
    if (current_cam->get_is_locked())
    {
        current_cam->setEulerAngle(glm::vec3(Helper::stopAngle(current_cam->getEulerAngle().x , current_cam->getlimit_pitch_min(),current_cam->getlimit_pitch_max()) ,
                                             Helper::stopAngle(current_cam->getEulerAngle().y , current_cam->getlimit_yaw_min(), current_cam->getlimit_yaw_max()) ,
                                             current_cam->getEulerAngle().z));
    } 
    current_cam->setlastX(mouseX);
    current_cam->setlastY(mouseY);
    previousX = current_cam->getlastX();
    previousY = current_cam->getlastY();
    current_cam->update();
    GameObject* c = static_cast<GameObject*>(current_cam);

    player->set_front(c->get_front());
    
    
    
    
}

void InputManager::Input_GameObject(GameObject * go , float deltaTime)
{
    //Keyboard control camera
   
    float playerSpeed =  0.2 *  deltaTime;
    //         if (isKeyHeld(GLFW_KEY_6))
    //             c->camera_translate(-cameraSpeed * c->target_vector());
    //         if (isKeyHeld(GLFW_KEY_EQUAL))
    //             c->camera_translate(cameraSpeed * c->target_vector());
    bool b = true;
    glm::vec3 front = go->get_front();
    glm::vec3 right = go->get_right();
    glm::vec3 up = go->get_up();

    if (isKeyHeld(GLFW_KEY_W)){
        go->addVitesse(front * playerSpeed);
          //go->setVitesse( go->getVitesse()); 
        go->getgameObjectInfo().setMovedRecently(true);
        b = false;
    }
    if (isKeyHeld( GLFW_KEY_S)){
        go->addVitesse(front * -playerSpeed);
          //go->setVitesse( go->getVitesse()); 
          go->getgameObjectInfo().setMovedRecently(true);
        b = false;
    }
    if (isKeyHeld(GLFW_KEY_A)){
        go->addVitesse(right * -playerSpeed);
         //go->setVitesse( go->getVitesse()); 
         go->getgameObjectInfo().setMovedRecently(true);
        b = false;
    }
    if (isKeyHeld(GLFW_KEY_D)){
        go->addVitesse(right * playerSpeed);
        //go->setVitesse( go->getVitesse()); 
        go->getgameObjectInfo().setMovedRecently(true);
        b = false;
    }
    if (isKeyPressed(GLFW_KEY_SPACE)&&  !go->getgameObjectInfo().getIsFalling()){
        go->addVitesse(glm::vec3(0.f , 1.f ,0.f) * deltaTime  * 15.f );
        go->getgameObjectInfo().setMovedRecently(true);
        go->getgameObjectInfo().setIsFalling(true);
        b = false;
    }/*
    if (isKeyPressed(GLFW_KEY_SPACE)){
        glm::vec3 translation=(go->getpos()- c->getPos()) *glm::vec3(-1);
       
        go->settranslate(translation); 
        glm::vec3 direction = glm::normalize(c->target_vector());

        float speed = 10.0f; 
        glm::vec3 velocity = direction * speed * deltaTime;
        go->setVitesse(velocity);
        //std::cout << c->target_vector().x <<" "<< c->target_vector().y <<" "<<c->target_vector().z << std::endl;
        
        b = false;
    }*/
    if (b) {
        //go->setVitesse(glm::vec3(0.0));
        go->reduceVitesse(playerSpeed);
    }
}

void InputManager::Input_ViewMode(Scene & s, GameObject* player)
{
    if (isKeyPressed(GLFW_KEY_RIGHT))
    {
        view ++;
        view = view % s.get_camera_list().size();
        GameObject* camera = s.get_camera_list()[view];
        current_cam = static_cast<Camera*>(camera); 
        camera->set_front(player->getpos()-camera->getpos());
        current_cam->setEulerAngle(Helper::quatToEuler(LookAt(camera->get_front(),camera->get_up())));
        
    }
    if (isKeyPressed(GLFW_KEY_LEFT))
    {
        if(view == 0){view = s.get_camera_list().size() - 1;}
        else{view --;}
        view = view % s.get_camera_list().size();
        GameObject* camera = s.get_camera_list()[view];
        current_cam = static_cast<Camera*>(camera); 
        camera->set_front(player->getpos()-camera->getpos());
        current_cam->setEulerAngle(Helper::quatToEuler(LookAt(camera->get_front(),camera->get_up())));
        
    } 
    if (isKeyPressed(GLFW_KEY_R))
    {
        s.reset();      
    }
    if (isKeyPressed(GLFW_KEY_P))
    {
        s.pause();      
    }

}
bool InputManager::Input_light_on_off(){
    if (isKeyPressed(GLFW_KEY_E))
    {
        return true;
    }
    return false;
}
void InputManager::Input_GamePlay(Scene & s , GameObject* player, float deltaTime )
{
    Input_ViewMode(s,player);
    Input_GameObject(player , deltaTime);
    Input_SecurityCam(player ,deltaTime);
}
