#include "geom_module.h"
#include "curve.h"
#include "editor/curve_editor.h"

namespace Echo
{
	DECLARE_MODULE(GeomModule)

	GeomModule::GeomModule()
	{

	}

	GeomModule* GeomModule::instance()
	{
		static GeomModule* inst = EchoNew(GeomModule);
		return inst;
	}

	void GeomModule::bindMethods()
	{

	}

	void GeomModule::registerTypes()
	{
		Class::registerType<Curve>();

		REGISTER_OBJECT_EDITOR(Curve, CurveEditor)
	}
}
