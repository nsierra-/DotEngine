#ifndef AOBJECTPLUGIN_HPP
# define AOBJECTPLUGIN_HPP

# include <vector>
# include <string>
# include <SFML/System/Vector2.hpp>
# include "BasicObject.hpp"

namespace Dot
{
	class BasicObject;

	class AObjectPlugin
	{
	public:

		enum Type
		{
			Empty,
			BoundingBox
		};

		class   OrphanGetException : public std::exception
		{
			public:
				OrphanGetException();
				OrphanGetException(OrphanGetException const &src);
				virtual ~OrphanGetException(void) throw();

				virtual const char * what() const throw();
		};

		class   OrphanSetException : public std::exception
		{
			public:
				OrphanSetException();
				OrphanSetException(OrphanSetException const &src);
				virtual ~OrphanSetException(void) throw();

				virtual const char * what() const throw();
		};

		const Type		type;
		unsigned		index;

		virtual void	update(void) = 0;
		virtual void	draw(void) = 0;

		bool			isOrphan(void);
		void			setParent(BasicObject * parent);
		BasicObject	&	parent(void);
		BasicObject	&	parent(void) const;

	protected:
		AObjectPlugin(BasicObject * = nullptr, Type = Empty);
		AObjectPlugin(Type = Empty, BasicObject * = nullptr);

		BasicObject *	_parent;

	private:
		OrphanGetException	_orphanGetEx;
		OrphanSetException	_orphanSetEx;
	};
}

#endif
