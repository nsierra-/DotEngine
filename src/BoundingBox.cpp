#include "BoundingBox.hpp"
#include "BasicObject.hpp"
#include <string>

namespace Dot
{
	CollidersVector	BoundingBox::all = std::vector<BoundingBox *>();

	BoundingBox::BoundingBox(float sizeX, float sizeY) :
		AObjectPlugin(AObjectPlugin::BoundingBox),
		size(sizeX, sizeY),
		min(0, 0),
		max(0, 0)
	{ }

	BoundingBox::BoundingBox(BasicObject * parent, float sizeX, float sizeY) :
		BoundingBox(sizeX, sizeY)
	{
		setParent(parent);
	}

	bool	BoundingBox::collideWith(const BoundingBox & box) const
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

	void	BoundingBox::setParent(BasicObject * p)
	{
		AObjectPlugin::setParent(p);

		parent().colliders.push_back(this);
		all.push_back(this);
		_resetBoxPosition();
	}

	void	BoundingBox::_resetBoxPosition(void)
	{
		min = parent().transform.getPosition();
		max = min + size;
	}

	void	BoundingBox::update(void)
	{
		_resetBoxPosition();
	}

	void	BoundingBox::draw(void)
	{

	}
}
