#pragma once

#pragma once

#include <GL/glew.h>
#include <SDL2/SDL.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <iostream>
#include <vector>
#include <algorithm>

struct RenderAttrib
{
    glm::vec3 Kd;
    glm::vec3 Ks;
    glm::vec3 normal;
};

struct SparseOctreeNode
{
    std::vector<SparseOctreeNode*>::iterator firstChild;
    Uint8 leafMask;
    Uint8 validMask;
};
