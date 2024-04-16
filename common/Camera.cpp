#include "Camera.hpp"


Camera::Camera( unsigned int w ,unsigned int h , glm::vec3 pos , glm::vec3 target )
{
    _SCR_WIDTH = w;
    _SCR_HEIGHT = h;
    _camera_position = pos;
    _camera_target = target;
    _aspectRatio = (double)_SCR_WIDTH / (double)_SCR_HEIGHT;
    _ProjectionMatrix = glm::perspective(glm::radians(_initialFOV), _aspectRatio, 0.1f, 100.f);  
    _ViewMatrix = glm::lookAt(_camera_position, _camera_position+_camera_target, _camera_up);
    verticalAngle = asin(_camera_target.y);
    horizontalAngle = acos( _camera_target.z / cos(verticalAngle));
    update();
    
    
    
    
}

unsigned int Camera::getw(){return _SCR_WIDTH;}
unsigned int Camera::geth(){return _SCR_HEIGHT;}

glm::mat4 Camera::getViewMatrix() {
    return _ViewMatrix;
}
glm::mat4 Camera::getProjectionMatrix(){
    return _ProjectionMatrix;
}

float Camera::getlastX(){return _lastX;}
float Camera::getlastY(){return _lastY;}
void Camera::setlastX(float x){_lastX = x;}
void Camera::setlastY(float y){_lastY = y;}

glm::vec3 Camera::getPos(){return _camera_position;}


void Camera::set_camera_position(glm::vec3 pos){
    _camera_target = glm::normalize( pos - _camera_position);
    verticalAngle = asin(_camera_target.y);
    horizontalAngle = acos( _camera_target.z / cos(verticalAngle));
}

void Camera::camera_translate(glm::vec3 translation){
    _camera_position += translation; update();
}
glm::vec3 Camera::right_vector(){
    return _camera_right ;        
}
glm::vec3 Camera::target_vector(){
    return _camera_target ;        
}  
glm::vec3 Camera::up_vector(){
    return _dir_up ;        
}   
bool Camera::get_orbital() {
    return _is_orbital;
}
void Camera::set_orbital(bool b){
    _is_orbital = b;
}
void Camera::rotateCamera (float moveX, float moveY){
    //Compute new orientation
    horizontalAngle += mouseSpeed * moveX;
    verticalAngle += mouseSpeed * moveY;
    
    
    glm::vec3 direction;            
    direction.x = cos(verticalAngle) * sin(horizontalAngle);
    direction.y = sin(verticalAngle);
    direction.z = cos(verticalAngle) * cos(horizontalAngle);
    
    _camera_target = direction;
    
    glm::normalize(_camera_target);
    
    
//     printf("in Camera: %p" , this);
//     
//     std::cout<<"cam target:"<<std::endl;
//     std::cout<<"\t"<<_camera_target[0]<< "\t" << _camera_target[1] << "\t" << _camera_target[2]<< "\t" << std::endl;
//     std::cout<<"horizontalAngle : " << horizontalAngle <<std::endl;
//     
    update();
}

void Camera::be_orbital(glm::vec3 pos_objet, float moveX, float moveY ){
    _last_pos_orbital = pos_objet;
    if (_is_orbital){
        horizontalAngle += mouseSpeed * moveX;
        verticalAngle += mouseSpeed * moveY;
        float rayon = glm::length( _last_pos_orbital - _camera_position);
        
        glm::vec3 position;            
        position.x =  -rayon * cos(verticalAngle) * sin(horizontalAngle);
        position.y = -rayon * sin(verticalAngle);
        position.z = -rayon * cos(verticalAngle) * cos(horizontalAngle);
        
        
        _camera_position = position + pos_objet ; 
        
        _camera_target = glm::normalize( _last_pos_orbital - _camera_position);
        
        update();
    }
    
}

void Camera::printCameradetail(){
    std::cout<<"Aspect Ratio: " << _aspectRatio <<std::endl;
    std::cout<<"FOV: " << _initialFOV <<std::endl;
    
    //         std::cout<<"View Matrix:"<<std::endl;
    //         for (int i = 0 ; i<4 ; i++){
    //             std::cout<<"\t"<<_ViewMatrix[i][0] << "\t" << _ViewMatrix[i][1] << "\t" << _ViewMatrix[i][2]<< "\t" << _ViewMatrix[i][3] << std::endl;
    //         }
    std::cout<<"cam pos:"<<std::endl;
    
    std::cout<<"\t"<<_camera_position[0]<< "\t" << _camera_position[1] << "\t" << _camera_position[2]<< "\t" << std::endl;
    
    
    
    //         std::cout<<"Projection Matrix:"<<std::endl;
    //         for (int i = 0 ; i<4 ; i++){
    //             std::cout<<"\t"<<_ProjectionMatrix[i][0] << "\t" << _ProjectionMatrix[i][1] << "\t" << _ProjectionMatrix[i][2]<< "\t" << _ProjectionMatrix[i][3] << std::endl;
    //         }
    
}

