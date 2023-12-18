#pragma once
#include <gl2d/gl2d.h>


struct Bullet
{
	glm::vec2 position = {};
	glm::vec2 fireDirection = {};

	void render(gl2d::Renderer2D &renderer,
		gl2d::Texture bulletsTexture, gl2d::TextureAtlasPadding bulletsAtlas
		);

	void update(float deltaTime);

	bool isEnemy = 0;
	float speed = 3000;

};