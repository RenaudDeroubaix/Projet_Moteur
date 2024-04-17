#include "Camera.hpp"


Camera::Camera(bool is_locked, unsigned int w ,unsigned int h) : GameObject()
{
    is_camera = true;
    _is_locked = is_locked;
    _SCR_WIDTH = w;
    _SCR_HEIGHT = h;
    _FOV = 70.0;
    _aspectRatio = (double)_SCR_WIDTH / (double)_SCR_HEIGHT;   
    update();
}


void Camera::setFOV(float fov){_FOV = fov;}
float Camera::getFOV(){return _FOV;}

unsigned int Camera::getw(){return _SCR_WIDTH;}
unsigned int Camera::geth(){return _SCR_HEIGHT;}
void Camera::setw(unsigned int w){ _SCR_WIDTH  = w;}
void Camera::seth(unsigned int h){ _SCR_HEIGHT = h;}


glm::mat4 Camera::getViewMatrix() {
    return _ViewMatrix;
}
glm::mat4 Camera::getProjectionMatrix(){
    return _ProjectionMatrix;
}


float Camera::getlastX(){return _lastX;}
float Camera::getlastY(){return _lastY;}
void Camera::setlastX(double x){_lastX = x;}
void Camera::setlastY(double y){_lastY = y;}

glm::vec3 Camera::getEulerAngle(){return _angleEuler;}
void Camera::setEulerAngle(glm::vec3 a){ _angleEuler = a;}

glm::vec3 Camera::getPos(){return _camera_position;}


void Camera::set_target(glm::vec3 p){
     set_pos(p + glm::vec3 (1 , 0 , 0));
    _angleEuler = glm::normalize(p - getpos());
    _rotation = glm::quat(_angleEuler);
}
// bool Camera::get_orbital() {
//     return _is_orbital;
// }
// void Camera::set_orbital(bool b){
//     _is_orbital = b;
// }

void Camera::rotateCamera(float moveX, float moveY , float deltatime){
    //Compute new orientation
    _angleEuler.y += (moveX) * 0.1 * deltatime;
    _angleEuler.x -= (moveY) * 0.1 * deltatime;
    _angleEuler.y = Helper::clipAngle180(_angleEuler.y);
    
}


// void Camera::be_orbital(glm::vec3 pos_objet, float moveX, float moveY ){
//     _last_pos_orbital = pos_objet;
//     if (_is_orbital){
//         horizontalAngle += mouseSpeed * moveX;
//         verticalAngle += mouseSpeed * moveY;
//         float rayon = glm::length( _last_pos_orbital - _camera_position);
//         
//         glm::vec3 position;            
//         position.x =  -rayon * cos(verticalAngle) * sin(horizontalAngle);
//         position.y = -rayon * sin(verticalAngle);
//         position.z = -rayon * cos(verticalAngle) * cos(horizontalAngle);
//         
//         
//         _camera_position = position + pos_objet ; 
//         
//         _camera_target = glm::normalize( _last_pos_orbital - _camera_position);
//         
//         update();
//     }
//     
// }

// void Camera::printCameradetail(){
//     std::cout<<"Aspect Ratio: " << _aspectRatio <<std::endl;
//     std::cout<<"FOV: " << _FOV <<std::endl;
//     
//             std::cout<<"View Matrix:"<<std::endl;
//             for (int i = 0 ; i<4 ; i++){
//                 std::cout<<"\t"<<_ViewMatrix[i][0] << "\t" << _ViewMatrix[i][1] << "\t" << _ViewMatrix[i][2]<< "\t" << _ViewMatrix[i][3] << std::endl;
//             }
//     
//             std::cout<<"Projection Matrix:"<<std::endl;
//             for (int i = 0 ; i<4 ; i++){
//                 std::cout<<"\t"<<_ProjectionMatrix[i][0] << "\t" << _ProjectionMatrix[i][1] << "\t" << _ProjectionMatrix[i][2]<< "\t" << _ProjectionMatrix[i][3] << std::endl;
//             }
//     
// }




void Camera::settexture(const std::string & path , GLuint textureIndex, const std::string & name_in_shader) 
{}
void Camera::initobject() 
{}
void Camera::drawobject() 
{}
void Camera::deleteobject() 
{delete this;}
void Camera::loadtextures() 
{}


