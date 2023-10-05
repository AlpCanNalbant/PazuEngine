// Copyright (c) Alp Can Nalbant. Licensed under the MIT License.

#include "Material.h"
using namespace Pazu::Graphics;

namespace Pazu
{
	Material::Material(std::unique_ptr<Shader> shader, std::array<std::unique_ptr<Texture>, 3> textures, const std::array<Color, 3> &colors, const bool twoSided, const DrawMode drawMode)
		: m_shader(std::move(shader)), m_colors(colors), m_twoSided(twoSided), m_drawMode(drawMode)
	{
		for (std::size_t x = 0; x < textures.size(); ++x)
		{
			if (const auto &texture = textures[x])
				m_textures.emplace(x, std::make_unique<Texture>(*texture));
		}
	}

	Material::Material(const Material &other)
		: m_shader(std::make_unique<Shader>(*other.m_shader)), m_colors(other.m_colors), m_twoSided(other.m_twoSided), m_drawMode(other.m_drawMode)
	{
		for (const auto &[index, texture] : other.m_textures)
		{
			if (texture)
				m_textures.emplace(index, std::make_unique<Texture>(*texture));
		}
	}

	const std::unique_ptr<Shader> &Material::GetShader() const
	{
		return m_shader;
	}

	std::optional<std::reference_wrapper<const std::unique_ptr<Texture>>> Material::GetDiffuseTexture() const
	{
		return GetTexture(0);
	}

	std::optional<std::reference_wrapper<const std::unique_ptr<Texture>>> Material::GetSpecularTexture() const
	{
		return GetTexture(1);
	}

	std::optional<std::reference_wrapper<const std::unique_ptr<Texture>>> Material::GetNormalTexture() const
	{
		return GetTexture(2);
	}

	std::optional<std::reference_wrapper<const std::unique_ptr<Texture>>> Material::GetTexture(const std::size_t index) const
	{
		if (const auto pos = m_textures.find(index); pos != m_textures.cend())
			return std::make_optional(std::cref(pos->second));
		return std::nullopt;
	}

	const Color &Material::GetDiffuseColor() const
	{
		return m_colors[0];
	}

	const Color &Material::GetSpecularColor() const
	{
		return m_colors[1];
	}

	const Color &Material::GetAmbientColor() const
	{
		return m_colors[2];
	}

	bool Material::GetTwoSided() const
	{
		return m_twoSided;
	}

	DrawMode Material::GetDrawMode() const
	{
		return m_drawMode;
	}

	void Material::SetShader(std::unique_ptr<Shader> shader)
	{
		m_shader = std::move(shader);
	}

	void Material::SetDiffuseTexture(std::unique_ptr<Texture> diffuse)
	{
		if (diffuse)
			m_textures.emplace(0, std::move(diffuse));
		else
			m_textures.erase(0);
	}

	void Material::SetSpecularTexture(std::unique_ptr<Texture> specular)
	{
		if (specular)
			m_textures.emplace(1, std::move(specular));
		else
			m_textures.erase(1);
	}

	void Material::SetNormalTexture(std::unique_ptr<Texture> normal)
	{
		if (normal)
			m_textures.emplace(2, std::move(normal));
		else
			m_textures.erase(2);
	}

	void Material::SetDiffuseColor(const Color &color)
	{
		m_colors[0] = color;
	}

	void Material::SetSpecularColor(const Color &color)
	{
		m_colors[1] = color;
	}

	void Material::SetAmbientColor(const Color &color)
	{
		m_colors[2] = color;
	}

	void Material::SetTwoSided(const bool twoSided)
	{
		m_twoSided = twoSided;
	}

	void Material::SetDrawMode(const DrawMode drawMode)
	{
		m_drawMode = drawMode;
	}
}
