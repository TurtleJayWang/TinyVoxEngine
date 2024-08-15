#pragma once

#include <GL/glew.h>
#include <SDL2/SDL.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <Voxel/Grid.hpp>

#include <iostream>
#include <vector>
#include <algorithm>

class VoxelRenderer
{
public:

    VoxelRenderer();

    ~VoxelRenderer();

    void Render(DTGrid3D* grid);

private:

};
