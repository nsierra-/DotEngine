#ifndef GAME_HPP
# define GAME_HPP
# include <vector>
# include <SFML/Graphics.hpp>
# include "StateManager.hpp"

namespace Dot
{
	using EventsVector = std::vector<std::unique_ptr<sf::Event> >;

	class StateManager;

	class Engine
	{
	public:

				Engine();

		void	handleEvents(void);
		void	update(void);
		void	draw(void);

		bool	isRunning(void) const;

		void	pushState(AGameState *);
		void	popState(void);

		void	loop(void);

	private:
		bool				_running;
		StateManager		_statesManager;

		sf::RenderWindow	_window;
		EventsVector		_events;

		void	_retrieveEvents(void);
	};
}

#endif
