#include "Transformable.hpp"
#include "BasicObject.hpp"
#include "BoundingBox.hpp"

namespace Dot
{
	Transformable::Transformable(BasicObject & parent) :
		parent(parent)
	{

	}


	void					Transformable::move(const sf::Vector2f & offset)
	{
		if (parent.colliders.size() == 0)
			_transform.move(offset);
		else
			moveIfNoCollision(offset);
	}


	void					Transformable::moveIfNoCollision(const sf::Vector2f & offset)
	{
		for (const auto * objCollider : parent.colliders)
		{
			for (const auto * sceneCollider : BoundingBox::all)
			{
				if (objCollider->collideWith(*sceneCollider))
					return ;
			}
		}
		_transform.move(offset);
	}

	void 					Transformable::move(float x, float y) { move(sf::Vector2f(x, y)); }
	void					Transformable::moveIfNoCollision(float x, float y) { moveIfNoCollision(sf::Vector2f(x, y)); }
	const sf::Transform &	Transformable::getTransform() const { return _transform.getTransform(); }
	const sf::Transform &	Transformable::getInverseTransform() const { return _transform.getInverseTransform(); }
	const sf::Vector2f &	Transformable::getPosition() const { return _transform.getPosition(); }
	float					Transformable::getRotation() const { return _transform.getRotation(); }
	const sf::Vector2f &	Transformable::getScale() const { return _transform.getScale(); }
	const sf::Vector2f &	Transformable::getOrigin() const { return _transform.getOrigin(); }

	void	Transformable::setPosition(float x, float y) { _transform.setPosition(x, y); }
	void	Transformable::setPosition(const sf::Vector2f & pos) { _transform.setPosition(pos); }
	// void	Transformable::setRotation(float angle) { _transform.setRotation(angle); }
	// void	Transformable::setScale(float x, float y) { _transform.setScale(x, y); }
	// void	Transformable::setScale(const sf::Vector2f & scale) { _transform.setScale(scale); }
	// void	Transformable::setOrigin(float x, float y) { _transform.setOrigin(x, y); }
	// void	Transformable::setOrigin(const sf::Vector2f & origin) { _transform.setOrigin(origin); }
	// void	Transformable::rotate(float angle) { _transform.rotate(angle); }
	// void	Transformable::scale(float x, float y) { _transform.scale(x, y); }
	// void	Transformable::scale(const sf::Vector2f & factor) { _transform.scale(factor); }
}
