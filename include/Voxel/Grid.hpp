#pragma once

#include <GL/glew.h>
#include <SDL2/SDL.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <iostream>
#include <vector>
#include <algorithm>

class DTGrid3D
{
public:

    DTGrid3D(int width, int height, int depth);

    ~DTGrid3D();

    void at(int idxX, int idxY, int idxZ);

    void createBall(const glm::vec3& leftBackBottom, int radius);

    void createBox(int width, int height, int depth);
    
    void resize(int width, int height, int depth);

    void addSubGrid(int offsetX, int offsetY, int offsetZ, const DTGrid3D* grid);

private:

    struct NonLeafData
    {
        Uint16 childOffset;
        Uint8 validMask;
        Uint8 leafMask;
    };

    int _width, _height, _depth;

};
