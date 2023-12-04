#include "Rendering.h"

float vTri[] = {
	1.0f, 0.0f, 0.0f,
	0.0f, 1.0f, 0.0f,
	-1.0f, 0.0f, 0.0f
};

//This is the constructor for the Rendering class
//The constructor initializes GLFW and GLAD
//Params: none
//returns: none
Rendering::Rendering(){
    init();
    _shader = new Shader("/Users/nabilibarissen/Documents/personal/vox/Voxel/src/shaders/vertexShader.glsl", "/Users/nabilibarissen/Documents/personal/vox/Voxel/src/shaders/fragmentShader.glsl");
    _projection = glm::perspective(glm::radians(FOV), (float)width / (float)height, NEAR_PLANE, FAR_PLANE);
    camera = new Camera(glm::vec3(0.0f, 0.0f, -30.0f), _window);
    scene = new Scene(_shader);
    scene->createCube();
    scene->generateModels();
}

//This function initializes GLFW and GLAD
//Params: none
//returns: none
void Rendering::init(){
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); //OpenGL version 3.3
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    #ifdef __APPLE__
        glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    #endif

    _window = Window::getInstance(width, height, "Voxel Engine");

    if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)){
        std::cout << "Failed to initialize GLAD" << std::endl;
        exit(-1);
    }

    std::cout << "Everything initialized correctly" << std::endl;
}

//This function renders the scene
//Params: none
//returns: none
void Rendering::render(){
    while (!_window->isClosed()){
        renderFrame();
    }
}

//This function renders a frame
//Params: none
//returns: none
void Rendering::renderFrame(){
    _window->changeBGColor(0.4f, 0.3f, 0.3f, 1.0f);
    camera->cameraInputs();
    _window->commonInputs();
    glClear(GL_DEPTH_BUFFER_BIT);

    _shader->use();
    _shader->setMat4("view", camera->getView());
    _shader->setMat4("projection", _projection);

    std::vector<Model> models = scene->getModels();
    for (int i = 0; i < models.size(); i++) {
        models[i].render();
    }

    
    _window->swapBuffers();
    _window->pollEvents();
}