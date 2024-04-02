#pragma once
#include "common/utils.hpp"
quat RotationBetweenVectors(vec3 start, vec3 dest);

quat LookAt(vec3 direction, vec3 desiredUp);

quat RotateTowards(quat q1, quat q2, float maxAngle);

