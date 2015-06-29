#include "AObjectPlugin.hpp"
#include "BasicObject.hpp"
#include <string>

namespace Dot
{
	AObjectPlugin::AObjectPlugin(BasicObject * parent, Type type) :
		type(type),
		index(parent != nullptr ? parent->plugins.size() : -1),
		_parent(parent)
	{
		if (parent)
			setParent(parent);
	}

	AObjectPlugin::AObjectPlugin(Type type, BasicObject * parent) :
		AObjectPlugin(parent, type)
	{

	}

	void			AObjectPlugin::setParent(BasicObject * parent)
	{
		if (!isOrphan())
			throw _orphanSetEx;
		_parent = parent;
		_parent->plugins.push_back(std::unique_ptr<AObjectPlugin>(this));
	}

	BasicObject	&	AObjectPlugin::parent(void)
	{
		if (isOrphan())
			throw _orphanGetEx;
		return *_parent;
	}

	BasicObject	&	AObjectPlugin::parent(void) const { return parent(); }

	bool	AObjectPlugin::isOrphan(void) { return _parent == nullptr; }

	AObjectPlugin::OrphanGetException::OrphanGetException() { }
	AObjectPlugin::OrphanGetException::OrphanGetException(AObjectPlugin::OrphanGetException const & src) { *this = src; }
	AObjectPlugin::OrphanGetException::~OrphanGetException(void) throw() { }
	const char  * AObjectPlugin::OrphanGetException::what() const throw() { return "Trying to access parent of an orphan plugin."; }

	AObjectPlugin::OrphanSetException::OrphanSetException() { }
	AObjectPlugin::OrphanSetException::OrphanSetException(AObjectPlugin::OrphanSetException const & src) { *this = src; }
	AObjectPlugin::OrphanSetException::~OrphanSetException(void) throw() { }
	const char  * AObjectPlugin::OrphanSetException::what() const throw() { return "Trying to set parent an adopted plugin."; }
}
