#include "Helper.hpp"


void Helper::ProjectVectorOnPlan(const glm::vec3& v, const glm::vec3& n , glm::vec3& proj ){
    proj = glm::cross(n,glm::cross(v,n));
}

float Helper::clipAngle180(float angle_a_clipper){
    float angle = glm::degrees(angle_a_clipper);
    if(angle < -180) angle += 360;
    if(angle > 180) angle -= 360;
    return  glm::radians(angle);
}
float Helper::stopAngle(float angle_a_clipper , float f){
    float angle = glm::degrees(angle_a_clipper);
    if(angle < -f) angle = -f;
    if(angle > f) angle = f;
    return  glm::radians(angle);
}
float Helper::stopAngle(float angle_a_clipper , float fmin, float fmax){
    float angle = glm::degrees(angle_a_clipper);
    if(angle < fmin) angle = fmin;
    if(angle > fmax) angle = fmax;
    return  glm::radians(angle);
}

float Helper::interpolation(float value, InterpolationType type){
    if(type == InterpolationType::Cos) return (1 - std::cos(value * M_PI)) / 2.;
    if(type == InterpolationType::Exp) return std::pow(value , 2.718281828459);
    if(type == InterpolationType::Log) return std::log(value * 9 + 1);
}
bool Helper::computeBarycentre(glm::vec3 P , glm::vec3 A ,  glm::vec3 B , glm::vec3 C ) {
    
    glm::vec3 v0 = B - A, v1 = C - A, v2 = P - A;
    float d00 = dot(v0, v0);
    float d01 = dot(v0, v1);
    float d11 = dot(v1, v1);
    float d20 = dot(v2, v0);
    float d21 = dot(v2, v1);
    float denom = d00 * d11 - d01 * d01;
    float v = (d11 * d20 - d01 * d21) / denom;
    float w = (d00 * d21 - d01 * d20) / denom;
    float u = 1.0f - v - w;
    return u >= 0 && v >= 0 && w >= 0;
    
}

glm::vec3 Helper::intersectionDroitePlan(glm::vec3 NPC ,glm::vec3 PLAYER ,glm::vec3 A, glm::vec3 B, glm::vec3 C) {
    glm::vec3 NPCPLAYER = PLAYER - NPC;
    glm::vec3 N = glm::normalize(glm::cross(B - A, C - A));
    float t = dot(N, A - NPC) / dot(N, NPCPLAYER);
    return NPC + t * NPCPLAYER;
}


glm::vec3 Helper::quatToEuler(glm::quat _quat)
{
	// Opengl quat to euler function give yaw betweel -90 and 90
	// If you want correct pitch and yaw you can use this 
	// Src http://www.euclideanspace.com/maths/geometry/rotations/conversions/quaternionToEuler/index.htm
	// But roll will be bewteen -90 and 90 here

	glm::vec3 eulerAngles;

	float test = _quat.x * _quat.y + _quat.z * _quat.w;

	if (test > 0.499f) { // singularity at north pole
		eulerAngles.y = 2.f * atan2(_quat.x, _quat.w);
		eulerAngles.z = M_PI / 2.f;
		eulerAngles.x = 0.f;
		return eulerAngles;
	}
	if (test < -0.499f) { // singularity at south pole
		eulerAngles.y = -2.f * atan2(_quat.x, _quat.w);
		eulerAngles.z = -M_PI / 2.f;
		eulerAngles.x = 0.f;
		return eulerAngles;
	}
	float sqx = _quat.x * _quat.x;
	float sqy = _quat.y * _quat.y;
	float sqz = _quat.z * _quat.z;


	eulerAngles.y = atan2(2.f * _quat.y * _quat.w - 2.f * _quat.x * _quat.z, 1.f - 2.f * sqy - 2.f * sqz);
	eulerAngles.z = asin(2.f * test);
	eulerAngles.x = atan2(2.f * _quat.x * _quat.w - 2.f * _quat.y * _quat.z, 1.f - 2.f * sqx - 2.f * sqz);

	return eulerAngles;
}


void Helper::setViewtowardFront(GameObject* go ){
	Camera * c = static_cast<Camera*>(go);
    glm::quat quatCam1=LookAt(go->get_front() , go->get_up());
    c->setEulerAngle(Helper::quatToEuler(quatCam1));
}
