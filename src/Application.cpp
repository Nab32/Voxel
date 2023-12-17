#include "Rendering.h"
#define STB_IMAGE_IMPLEMENTATION
#include <stb/stb_image.h>

float deltaTime = 0.0f;	// Time between current frame and last frame
float lastFrame = 0.0f; // Time of last frame

int main(){
    Rendering* rendering = new Rendering();
    rendering->render();
    delete rendering;
    return 0;
}