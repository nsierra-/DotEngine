#ifndef BASICOBJECT_HPP
# define BASICOBJECT_HPP

# include <vector>
# include <string>
# include <SFML/System/Vector2.hpp>
# include "Transformable.hpp"
# include "AObjectPlugin.hpp"

namespace Dot
{
	class AObjectPlugin;
	class Engine;
	class BoundingBox;

	using BasicObjectsVector = std::vector<std::unique_ptr<BasicObject> >;
	using PluginsVector = std::vector<std::unique_ptr<AObjectPlugin> >;
	using CollidersVector = std::vector<BoundingBox *>;

	class BasicObject
	{
	public:
		static std::unique_ptr<BasicObject>		null;
		static BasicObjectsVector	objects;
		const unsigned				index;
		const std::string			name;
		Transformable				transform;
		PluginsVector				plugins;
		CollidersVector				colliders;

		BasicObject(const std::string & = "BasicObject", sf::Vector2f = sf::Vector2f(0, 0));
		static BasicObject &		getByIndex(unsigned);
		AObjectPlugin &				getPluginByIndex(unsigned);
		void						update(Engine *);
		void						draw(Engine *);

	private:
	};
}

#endif
