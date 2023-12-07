#include <bullet.h>	





void Bullet::render(gl2d::Renderer2D &renderer,
	gl2d::Texture bulletsTexture, gl2d::TextureAtlasPadding bulletsAtlas)
{
	float spaceShipAngle = atan2(fireDirection.y, -fireDirection.x);
	spaceShipAngle = glm::degrees(spaceShipAngle) + 90.f;

	renderer.renderRectangle({position - glm::vec2(25,25), 50,50},
		bulletsTexture, Colors_White, {}, spaceShipAngle, bulletsAtlas.get(1, 1));
}

void Bullet::update(float deltaTime)
{

	position += fireDirection * deltaTime * 3000.f;

}
