// Copyright (c) Alp Can Nalbant. Licensed under the MIT License.

#include "Shader.h"

namespace Pazu::Graphics
{
	Shader::Shader(const std::string &source, const bool compiled)
		: m_source(source), m_compiled(compiled) {}

	const std::string &Shader::GetSource() const
	{
		return m_source;
	}

	bool Shader::GetCompiled() const
	{
		return m_compiled;
	}

	void Shader::SetSource(const std::string &source)
	{
		m_source = source;
	}

	void Shader::SetCompiled(const bool compiled)
	{
		m_compiled = compiled;
	}
}
