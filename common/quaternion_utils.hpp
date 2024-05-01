#pragma once
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/quaternion.hpp>
#include <glm/gtx/quaternion.hpp>
#include <glm/gtx/euler_angles.hpp>
#include <glm/gtx/norm.hpp>
#include <glm/gtx/string_cast.hpp>



glm::quat RotationBetweenVectors(glm::vec3 start, glm::vec3 dest);

glm::quat LookAt(glm::vec3 direction, glm::vec3 desiredUp);

glm::quat RotateTowards(glm::quat q1, glm::quat q2, float maxAngle);


