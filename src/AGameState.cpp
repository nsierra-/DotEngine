#include "AGameState.hpp"


namespace Dot
{
	void	AGameState::update(Engine * e)
	{
		for (auto & o : _objects)
			o->update(e);
	}

	void	AGameState::draw(Engine *)
	{

	}
}
