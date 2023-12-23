#include "Textures.h"


Texture::Texture(char* path, Shader* shader) :
	_shader(shader) {
	stbi_set_flip_vertically_on_load(true);
	_data = stbi_load(path, &_width, &_height, &_nrChannels, 0);
	loadTexture();
	std::cout << path << std::endl;
}

void Texture::loadTexture() {
	glGenTextures(1, &_textureID);
	glBindTexture(GL_TEXTURE_2D, _textureID);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	if (_data) {
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, _width, _height, 0, GL_RGB, GL_UNSIGNED_BYTE, _data);
		glGenerateMipmap(GL_TEXTURE_2D);
		std::cout << "IT WENT HERE" << std::endl;
	}
	else {
		std::cout << "TEXTURE DIDNT LOAD CORRECTLY" << std::endl;
	}
}

void Texture::bind() {
	_shader->setInt("text", (_textureID - 1));
	glActiveTexture(GL_TEXTURE0 + (_textureID - 1));
	glBindTexture(GL_TEXTURE_2D, _textureID);
}