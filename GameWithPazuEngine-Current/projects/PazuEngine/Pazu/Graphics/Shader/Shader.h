#pragma once
#include "../Object.h"

namespace Pazu::Graphics
{
	class Shader : public Object
	{
	public:
		Shader() = default;
		Shader(const std::string &source, const bool compiled);
		const std::string &GetSource() const;
		bool GetCompiled() const;
		void SetSource(const std::string &source);
		void SetCompiled(const bool compiled);

	protected:
		std::string m_source;
		bool m_compiled;
	};
} // namespace Pazu
