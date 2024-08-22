#pragma once

#include <GL/glew.h>
#include <SDL2/SDL.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <iostream>
#include <vector>
#include <algorithm>

class Camera
{
public:

    Camera(const glm::vec3& position);

    ~Camera();

    void moveForward(float step);

    void moveUpward(float step);

    void moveRight(float step);

    void move(const glm::vec3& step);

    void rotateEuler(float deltaPitch, float deltaYaw, float deltaRoll);

    glm::vec3 getFrontVector();

    glm::vec3 getUpVector();

    glm::vec3 getRightVector();

private:

    float _pitch = 0, _yaw = 0, _roll = 0;

    glm::vec3 _position;

};
