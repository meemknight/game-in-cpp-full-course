#include <enemy.h>
#include <tiledRenderer.h>


void Enemy::render(gl2d::Renderer2D &renderer,
	gl2d::Texture &sprites, gl2d::TextureAtlasPadding &atlas)
{
	renderSpaceShip(renderer, position, enemyShipSize,
		sprites, atlas.get(type.x, type.y), viewDirection);
}



void Enemy::update(float deltaTime, glm::vec2 playerPos)
{

	glm::vec2 directionToPlayer = playerPos - position;
	if (glm::length(directionToPlayer) == 0) { directionToPlayer = {1,0}; }
	else { directionToPlayer = glm::normalize(directionToPlayer); }

	glm::vec2 newDirection = {};

	if (glm::length(directionToPlayer + viewDirection) <= 0.1)
	{
		newDirection = glm::vec2(directionToPlayer.y, -directionToPlayer.x);
	}
	else
	{
		newDirection =
			deltaTime * turnSpeed * directionToPlayer + viewDirection;
	}


	viewDirection = glm::normalize(newDirection);
	position += viewDirection * deltaTime * speed;

}
