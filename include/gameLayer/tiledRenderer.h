#pragma once
#include <gl2d/gl2d.h>

struct TiledRenderer
{

	float backgroundSize = 10000;
	gl2d::Texture texture;

	float paralaxStrength = 1;

	void render(gl2d::Renderer2D &renderer);
};