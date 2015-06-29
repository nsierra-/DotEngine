#include "BoundingBox.hpp"
#include "BasicObject.hpp"
#include <string>

namespace Dot
{
	BoundingBox::BoundingBox(sf::Vector2f minimun, sf::Vector2f maximum) :
		AObjectPlugin(AObjectPlugin::BoundingBox),
		min(minimun),
		max(maximum)
	{ }

	bool	BoundingBox::collidesWith(const BoundingBox & box) const
	{
		if (parent().index == box.parent().index || !isOnSameLayer(box))
			return false;

		if (max.x < box.min.x or min.x > box.max.x)
			return false;
		else if (max.y < box.min.y or min.y > box.max.y)
			return false;
		return true;
	}

	bool	BoundingBox::isOnSameLayer(const BoundingBox & box) const
	{
		for (const auto & layer : layers)
		{
			if (std::find(box.layers.begin(), box.layers.end(), layer) != box.layers.end())
				return true;
		}
		return false;
	}

	void	BoundingBox::update(void)
	{

	}

	void	BoundingBox::draw(void)
	{

	}

}
