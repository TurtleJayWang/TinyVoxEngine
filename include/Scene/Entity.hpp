#pragma once

#include <GL/glew.h>
#include <SDL2/SDL.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <iostream>
#include <vector>
#include <algorithm>

#include <CL/opencl.h>

#include <Scene/Renderer.hpp>

class EntityRenderer : public Renderer
{
public:

    virtual void render();

private:

    EntityRenderer();

};

class Entity
{
public:

    Entity();

    Entity(int width, int height, int depth);

    void at(int idxX, int idxY, int idxZ);

    void setGlobalSize(float width, float height, float depth);

    void resize(int width, int height, int depth);

    void addSphere(const glm::ivec3& position, int radius);

    void addCube(int size);

private:

    struct Size
    {
        struct GlobalSize      { float width, height, depth; } global;
        struct IndexSpaceSize  { int   width, height, depth; } indexSpace;
    } _size;

};
