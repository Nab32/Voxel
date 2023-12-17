#pragma once
#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "Shader.h"
#include <stb/stb_image.h>
#include <filesystem>
#include <string>


class Texture {
public:
	Texture(char* path, Shader* shader);
	void loadTexture();
	void bind();
private:
	int _width, _height, _nrChannels;
	unsigned char* _data;
	unsigned int _textureID;
	Shader* _shader;
};