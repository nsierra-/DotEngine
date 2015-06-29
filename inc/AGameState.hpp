#ifndef AGAMESTATE_HPP
# define AGAMESTATE_HPP

# include <vector>
# include "BasicObject.hpp"

namespace Dot
{
	class Engine;

	using ObjectsVector = std::vector<std::unique_ptr<BasicObject> >;

	class AGameState
	{
	public:
		virtual			~AGameState() {};

		virtual void	init()			= 0;
		virtual void	clean()			= 0;
		virtual void	pause()			= 0;
		virtual void	resume()		= 0;

		virtual void	update(Engine *);
		virtual void	draw(Engine *);

	protected:
				AGameState() {};
		ObjectsVector	_objects;
	};
}

#endif
