#include <tiledRenderer.h>



void TiledRenderer::render(gl2d::Renderer2D &renderer)
{

	auto viewRect = renderer.getViewRect();
	//this allows us to see what we can see

	glm::vec2 paralaxDistance = {viewRect.x, viewRect.y};
	paralaxDistance *= -paralaxStrength;

	for (int y = -1; y <= 1; y++)
	{
		for (int x = -1; x <= 1; x++)
		{
			int posX = x + int((viewRect.x - paralaxDistance.x)/ backgroundSize);
			int posY = y + int((viewRect.y - paralaxDistance.y)/ backgroundSize);
			
			renderer.renderRectangle(
				glm::vec4{posX, posY, 1, 1} * backgroundSize
				+glm::vec4(paralaxDistance,0,0)
				, texture);

		}
	}



}

void renderSpaceShip(gl2d::Renderer2D &renderer,
	glm::vec2 position, float size,
	gl2d::Texture texture, glm::vec4 uvs, glm::vec2 viewDirection)
{
	float spaceShipAngle = atan2(viewDirection.y, -viewDirection.x);

	renderer.renderRectangle({position - glm::vec2(size / 2, size/ 2)
	, size,size}, texture,
		Colors_White, {}, glm::degrees(spaceShipAngle) + 90.f,
		uvs);
}
