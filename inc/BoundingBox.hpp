#ifndef BOUNDINGBOX_HPP
# define BOUNDINGBOX_HPP

# include <SFML/System/Vector2.hpp>
# include <vector>
# include "AObjectPlugin.hpp"

namespace Dot
{
	class BoundingBox : AObjectPlugin
	{
	public:
		sf::Vector2f				min;
		sf::Vector2f				max;
		std::vector<std::string>	layers;

				BoundingBox(sf::Vector2f = sf::Vector2f(0, 0), sf::Vector2f = sf::Vector2f(0, 0));
				BoundingBox(BasicObject *, sf::Vector2f = sf::Vector2f(0, 0), sf::Vector2f = sf::Vector2f(0, 0));
		bool	collidesWith(const BoundingBox &) const;
		bool	isOnSameLayer(const BoundingBox &) const;

		virtual void	update();
		virtual void	draw();

	private:
	};
}

#endif
