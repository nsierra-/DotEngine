#ifndef STATEMANAGER_HPP
# define STATEMANAGER_HPP
# include <vector>
# include "AGameState.hpp"

namespace Dot
{
	using StatesVector = std::vector<std::unique_ptr<AGameState> >;

	class Engine;

	class StateManager
	{
	public:

		void	clear();

		void	pushState(AGameState *);
		void	popState(void);

		void	handleEvents(Engine *);
		void	update(Engine *);
		void	draw(Engine *);

		class   NoStateException : public std::exception
		{
			public:
				NoStateException();
				NoStateException(NoStateException const &src);
				virtual ~NoStateException(void) throw();

				virtual const char * what() const throw();
		};

	private:
		StatesVector	_states;

		NoStateException			_noStateException;

		void	_ensureStatesIsNotEmpty(void);
	};
}

#endif
