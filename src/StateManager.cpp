#include "StateManager.hpp"
#include "Engine.hpp"

namespace Dot
{
	void	StateManager::clear()
	{
		_states.clear();
	}

	void	StateManager::handleEvents(Engine * e)
	{
		_ensureStatesIsNotEmpty();
		(void)e;
		//_states.at(0)->handleEvents(e);
	}

	void	StateManager::update(Engine * e)
	{
		_ensureStatesIsNotEmpty();
		_states.at(0)->update(e);
	}

	void	StateManager::draw(Engine * e)
	{
		_ensureStatesIsNotEmpty();
		_states.at(0)->draw(e);
	}

	void	StateManager::pushState(AGameState * state)
	{
		_states.insert(_states.begin(), std::unique_ptr<AGameState>(state));
	}

	void	StateManager::popState(void)
	{
		_states.erase(_states.begin());
	}

	void	StateManager::_ensureStatesIsNotEmpty(void)
	{
		if (_states.size() == 0)
			throw _noStateException;
	}

	StateManager::NoStateException::NoStateException() { }
	StateManager::NoStateException::NoStateException(StateManager::NoStateException const & src) { *this = src; }
	StateManager::NoStateException::~NoStateException(void) throw() { }
	const char  * StateManager::NoStateException::what() const throw() { return "Trying to execute a state but states vector is empty."; }
}
