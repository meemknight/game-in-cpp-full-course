#pragma once
#include <gl2d/gl2d.h>

struct TiledRenderer
{

	float backgroundSize = 10000;
	gl2d::Texture texture;

	float paralaxStrength = 1;

	void render(gl2d::Renderer2D &renderer);
};

void renderSpaceShip(
	gl2d::Renderer2D &renderer,
	glm::vec2 position, float size,
	gl2d::Texture texture,
	glm::vec4 uvs, glm::vec2 viewDirection);