#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include "Rendering.h"

int main(){
    Rendering* rendering = new Rendering();
    rendering->render();
    return 0;
}