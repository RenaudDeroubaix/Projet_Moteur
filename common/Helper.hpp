#pragma once
#include "common/utils.hpp"
#include "common/Camera.hpp"
#define M_PI       3.14159265358979323846f   // pi

enum class InterpolationType {
    Cos,
    Exp,
    Log
};

class Helper
{
public: 
    static float stopAngle(float angle , float f);
    static float stopAngle(float angle_a_clipper , float fmin, float fmax);
    static float interpolation(float value, InterpolationType type);
    static float clipAngle180(float angle_a_clipper);
    static void ProjectVectorOnPlan(const glm::vec3& v, const glm::vec3& n , glm::vec3 & proj);
	static glm::vec3 quatToEuler(glm::quat _quat);
    static void setViewtowardFront(GameObject* go );
    static bool computeBarycentre(glm::vec3 P , glm::vec3 A ,  glm::vec3 B , glm::vec3 C );
    static glm::vec3 intersectionDroitePlan(glm::vec3 NPC ,glm::vec3 PLAYER ,glm::vec3 A, glm::vec3 B, glm::vec3 C);
};
