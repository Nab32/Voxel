#include "Window.h"
//Singleton

//This is the pointer to the instance of the singleton class
Window* Window::instancePtr = nullptr;

//This is a singleton class, so the constructor is private
//The constructor creates a GLFW window and sets the context to the window
//The constructor also sets the callback function for when the window is resized
//Params: width - the width of the window
//        height - the height of the window
//        title - the title of the window
//returns: none
Window::Window(const unsigned int width, const unsigned int height, const char* title){
    _window = glfwCreateWindow(width, height, title, NULL, NULL);
    if(_window == NULL){
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        exit(-1);
    }
    glfwMakeContextCurrent(_window);
    glfwSetFramebufferSizeCallback(_window, framebuffer_size_callback);
}

//This function returns the instance of the singleton class
//Params: width - the width of the window
//        height - the height of the window
//        title - the title of the window
//returns: the instance of the singleton class
Window* Window::getInstance(const unsigned int width, const unsigned int height, const char* title){
    if(instancePtr == nullptr){
        instancePtr = new Window(width, height, title);
    }
    return instancePtr;
}

//This function returns the GLFW window
//Params: none
//returns: the GLFW window
GLFWwindow* Window::getWindow(){
    return _window;
}


//This function terminates GLFW
//Params: none
//returns: none
void Window::terminate(){
    glfwTerminate();
}


//This function polls GLFW events
//Params: none
//returns: none
void Window::pollEvents(){
    glfwPollEvents();
}

//This function swaps the buffers
//Params: none
//returns: none
void Window::swapBuffers(){
    glfwSwapBuffers(_window);
}

//This function returns whether or not the window is closed
//Params: none
//returns: 1 if the window is closed, 0 if the window is not closed
int Window::isClosed(){
    return glfwWindowShouldClose(_window);
}

//This function is the callback function for when the window is resized
//Params: window - the GLFW window
//        width - the new width of the window
//        height - the new height of the window
//returns: none
void Window::framebuffer_size_callback(GLFWwindow* window, int width, int height){
    glViewport(0, 0, width, height);
}

//This function changes the background color of the window
//Params: r - the red value of the new background color
//        g - the green value of the new background color
//        b - the blue value of the new background color
//        a - the alpha value of the new background color
//returns: none
void Window::changeBGColor(float r, float g, float b, float a){
    glClearColor(r, g, b, a);
    glClear(GL_COLOR_BUFFER_BIT);
}