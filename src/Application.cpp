#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include "Rendering.h"
#include <noise/noise.h>
#include <windows.h>



float deltaTime = 0.0f;	// Time between current frame and last frame
float lastFrame = 0.0f; // Time of last frame



int main(){
    noise::module::Perlin perlinModule;

    Rendering* rendering = new Rendering();
    rendering->render();
    delete rendering;
    return 0;
}