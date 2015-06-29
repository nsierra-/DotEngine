#include "BasicObject.hpp"

namespace Dot
{
	BasicObjectsVector	BasicObject::objects = BasicObjectsVector();
	BasicObject &		BasicObject::getByIndex(unsigned index) { return *objects.at(index); }
	AObjectPlugin &		BasicObject::getPluginByIndex(unsigned index) { return *plugins.at(index); }

	BasicObject::BasicObject(const std::string & name, sf::Vector2f pos) :
		index(objects.size()),
		name(name),
		transform(*this)
	{
		transform.setPosition(pos);
		objects.push_back(std::unique_ptr<BasicObject>(this));
	}

	void				BasicObject::update(Engine *)
	{
	}

	void				BasicObject::draw(Engine *)
	{
	}
}
