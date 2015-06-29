#ifndef TRANSFORMABLE_HPP
# define TRANSFORMABLE_HPP

# include <vector>
# include <string>
# include <SFML/System/Vector2.hpp>
# include <SFML/Graphics/Transformable.hpp>

namespace Dot
{
	class BasicObject;

	class Transformable
	{
	public:
		BasicObject &			parent;

				Transformable(BasicObject &);
		void 	move(float, float);
		void	move(const sf::Vector2f &);
		void	moveIfNoCollision(float, float);
		void	moveIfNoCollision(const sf::Vector2f &);
		void	setPosition(const sf::Vector2f &);
		void	setPosition(float, float);

		float					getRotation() const;
		const sf::Vector2f &	getPosition() const;
		const sf::Vector2f &	getScale() const;
		const sf::Vector2f &	getOrigin() const;
		const sf::Transform &	getTransform() const;
		const sf::Transform &	getInverseTransform() const;

		// void	setRotation(float);
		// void	setScale(float, float);
		// void	setScale(const sf::Vector2f &);
		// void	setOrigin(float, float);
		// void	setOrigin(const sf::Vector2f &);
		// void	rotate(float);
		// void	scale(float, float);
		// void	scale(const sf::Vector2f &);

	private:
		sf::Transformable	_transform;

	};
}

#endif
