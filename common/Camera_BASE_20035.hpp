#pragma once
#include "common/utils.hpp"
#include "common/shader.hpp"
class Camera {
    
private:
    // settings
    
    
    unsigned int _SCR_WIDTH;
    unsigned int _SCR_HEIGHT;
    bool _is_orbital = true;
    
    glm::vec3 _last_pos_orbital = glm::vec3(0,0,0);
    
    glm::vec3 _camera_position;  
    glm::vec3 _camera_target;
    glm::vec3 _camera_up = glm::vec3(0.f , 1.f , 0.f);
    
    glm::vec3 _dir_up;
    glm::vec3 _camera_right = glm::normalize(glm::cross(_camera_target , _camera_up));

    
    float verticalAngle;
    float horizontalAngle;

    
    float _initialFOV = 45.0f;
    float _aspectRatio;
    

    glm::mat4 _ViewMatrix;
    glm::mat4 _ProjectionMatrix ;
    
    float _lastX = 0;
    float _lastY = 0;
    
    float mouseSpeed = 1.f;
    
   
    
    
public:
    Camera(){}
    
    Camera(unsigned int w ,unsigned int h , glm::vec3 pos , glm::vec3 target );
    
    unsigned int getw();
    unsigned int geth();
    glm::mat4 getViewMatrix();
    glm::mat4 getProjectionMatrix();
    float getlastX();
    float getlastY();
    void setlastX(float x);
    void setlastY(float y);
    
    void set_camera_position(glm::vec3 pos);
    void camera_translate(glm::vec3 translation);
    glm::vec3 right_vector();
    glm::vec3 target_vector();
    glm::vec3 up_vector();
    
    bool get_orbital();
    void set_orbital(bool b);
    
    void rotateCamera (float moveX, float moveY);
    void be_orbital(glm::vec3 pos_objet, float moveX, float moveY );

    void printCameradetail();
    
    
    
private :
     void update() {
        
        _camera_right = glm::normalize(glm::cross(_camera_target , _camera_up));
        _ViewMatrix = glm::lookAt(_camera_position,_camera_position+_camera_target,_camera_up);
        _dir_up =  glm::normalize(glm::cross(_camera_right , _camera_target));
        
       
    }

};

