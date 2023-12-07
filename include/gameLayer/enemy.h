#pragma once
#include <gl2d/gl2d.h>

constexpr float enemyShipSize = 250.f;

struct Enemy
{
	glm::uvec2 type = {}; //used to index into the texture atlas
	glm::vec2 position = {};

	glm::vec2 viewDirection = {1,0};

	float speed = 1500.f;
	float turnSpeed = 3.f;

	void render(gl2d::Renderer2D &renderer, gl2d::Texture &sprites,
		gl2d::TextureAtlasPadding &atlas);

	void update(float deltaTime, glm::vec2 playerPos);
};
