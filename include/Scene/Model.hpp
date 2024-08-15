#pragma once

#include <iostream>
#include <vector>
#include <algorithm>

#include <GL/glew.h>
#include <SDL2/SDL.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <Voxel/VoxelData.hpp>

class Model
{
public:

    Model();

    ~Model();

    void loadFromFile(const char* fileName);

private:

    

};
