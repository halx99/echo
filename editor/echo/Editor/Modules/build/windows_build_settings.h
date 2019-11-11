#pragma once

#include "build_settings.h"

namespace Echo
{
	class WindowsBuildSettings : public BuildSettings
	{
		ECHO_SINGLETON_CLASS(WindowsBuildSettings, BuildSettings)

	public:
		WindowsBuildSettings();
		virtual ~WindowsBuildSettings();

		// instance
		static WindowsBuildSettings* instance();

		// build
		virtual void build() override;

		// set
		virtual void setOutputDir(const String& outputDir) override;

		// get final result path
		virtual String getFinalResultPath() override;

		// icon res path
		void setIconRes(const ResourcePath& path);
		const ResourcePath& getIconRes() { return m_iconRes; }

	private:
		// output directory
		bool prepare();

		// copy
		void copySrc();
		void copyRes();

		// cmake
		void cmake();

		// compile
		void compile();

	private:
		String                  m_rootDir;
		String                  m_projectDir;
		String                  m_outputDir;
		ResourcePath            m_iconRes;
	};
}
