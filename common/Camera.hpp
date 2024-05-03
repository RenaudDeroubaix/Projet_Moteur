#pragma once
#include "common/utils.hpp"
#include "common/GameObject.hpp"
#include "common/shader.hpp"
#include "common/Helper.hpp"

class Camera : public GameObject{
    
private:
    // settings
    
    unsigned int _SCR_WIDTH;
    unsigned int _SCR_HEIGHT;
    
    bool _is_locked;
    
    glm::vec3 _vec_right = glm::vec3(1.f , 0.f , 0.f) ;  
    glm::vec3 _vec_front = glm::vec3(0.f , 0.f , 1.f) ;
    glm::vec3 _vec_up = glm::vec3(0.f , 1.f , 0.f);
    
    glm::vec3 _angleEuler = glm::vec3(0.001f,0.001f,0.001f);
    glm::quat _rotation = glm::quat(_angleEuler);
    
    float _FOV;
    float _aspectRatio;
    
    glm::mat4 _ViewMatrix;
    glm::mat4 _ProjectionMatrix ;
    
    double _lastX = 0.f ;
    double _lastY = 0.f;

    
   
    
    
public:
    Camera() : GameObject() {}
    
    Camera(bool b, unsigned int w ,unsigned int h);
    void setFOV(float fov);
    float getFOV();
    bool get_is_locked(){return _is_locked;}
    unsigned int getw();
    unsigned int geth();
    void setw(unsigned int w);
    void seth(unsigned int h);
    glm::mat4 getViewMatrix();
    glm::mat4 getProjectionMatrix();

    float getlastX();
    float getlastY();
    void setlastX(double x);
    void setlastY(double y);
    glm::vec3 getEulerAngle();
    void setEulerAngle(glm::vec3 euler);
    
            
    //     bool get_orbital();
    //     void set_orbital(bool b);
    
    
    void rotateCamera(float X , float Y, float d);
    void set_target(glm::vec3 p);
    // void be_orbital(glm::vec3 pos_objet, float moveX, float moveY );

    void printCameradetail();
    void initobject() override;
    void drawobject()  override;
    void deleteobject()  override;
    void settexture(const std::string & path , GLuint textureIndex, const std::string & name_in_shader) override;
    void update() {
        _rotation = glm::quat(_angleEuler);

        _ProjectionMatrix = glm::perspective(glm::radians(_FOV), _aspectRatio , 0.1f, 200.0f);
        
        front = normalize(_rotation * _vec_front);
        up = normalize(_rotation * _vec_up);
        right = normalize(cross(front , up));
        
        // Camera matrix
        _ViewMatrix = glm::lookAt(getpos(), getpos() + front, up);
    }
    
private :
    
    
};

