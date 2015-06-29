#ifndef BOUNDINGBOX_HPP
# define BOUNDINGBOX_HPP

# include <SFML/System/Vector2.hpp>
# include <vector>
# include "AObjectPlugin.hpp"

namespace Dot
{
	using CollidersVector = std::vector<BoundingBox *>;

	class BoundingBox : AObjectPlugin
	{
	public:
		static CollidersVector		all;
		sf::Vector2f				size;
		sf::Vector2f				min;
		sf::Vector2f				max;
		std::vector<std::string>	layers;

				BoundingBox(float = 0, float = 0);
				BoundingBox(BasicObject *, float = 0, float = 0);
		bool	collideWith(const BoundingBox &) const;
		bool	isOnSameLayer(const BoundingBox &) const;

		virtual void	update();
		virtual void	draw();
		virtual void	setParent(BasicObject *);

	private:
		void			_resetBoxPosition(void);
	};
}

#endif
