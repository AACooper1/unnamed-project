#pragma once

#ifndef BASIC_RENDER_H
#define BASIC_RENDER_H

#include <GLAD/glad.h>
#include <GLFW/glfw3.h>

// This projects a point in 3D space onto the 2D screen. Matrices :D!!!
void vertexShader(float x, float y, float z, GLFWWindow* window);
// 
void primitiveAssembler();

// Don't get ahead of yourself lmao. This is the one we're working up to.
void drawTriangle();


#endif
