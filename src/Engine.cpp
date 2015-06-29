#include "Engine.hpp"
#include "Logger.hpp"

namespace Dot
{
	Engine::Engine() :
		_running(true),
		_window(sf::VideoMode(800, 600), "DotEngine")
	{
	}

	void	Engine::handleEvents(void)
	{
		Logger::debug("Engine - handleEvents()");
		_retrieveEvents();
		_statesManager.handleEvents(this);
	}

	void	Engine::update(void)
	{
		Logger::debug("Engine - update()");

		_statesManager.update(this);
	}

	void	Engine::draw(void)
	{
		Logger::debug("Engine - draw()");
		_statesManager.draw(this);
	}

	void	Engine::_retrieveEvents(void)
	{
		sf::Event * tmp = new sf::Event;

		_events.clear();
		while (_window.pollEvent(*tmp))
		{
			if (tmp->type == sf::Event::Closed)
			{
				_running = false;
				delete tmp;
				return ;
			}
			_events.push_back(std::unique_ptr<sf::Event>(tmp));
			tmp = new sf::Event;
		}
		delete tmp;
	}

	void	Engine::loop(void)
	{
		while (_running)
		{
			handleEvents();
			update();
			draw();
		}
	}

	void	Engine::pushState(AGameState * state) { _statesManager.pushState(state); }
	void	Engine::popState(void) { _statesManager.popState(); }
	bool	Engine::isRunning() const	{ return _running; }
}
