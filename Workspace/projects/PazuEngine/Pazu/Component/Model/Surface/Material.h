// Copyright (c) Alp Can Nalbant. Licensed under the MIT License.

#pragma once
#include "../../../Math/Color.h"
#include "../../../Graphics/DrawMode.h"
#include "Texture.h"
#include "Shader.h"

namespace Pazu
{
	class Material
	{
	public:
		Material() = default;
		Material(std::unique_ptr<Shader> shader, std::array<std::unique_ptr<Texture>, 3> textures, const std::array<Color, 3> &colors, const bool twoSided = false, const Graphics::DrawMode drawMode = Graphics::DrawMode::TriangleList);
		Material(const Material &other);
		Material(Material &&other) = default;
		~Material() = default;
		Material &operator=(const Material &other);
		Material &operator=(Material &&other) = default;
		const std::unique_ptr<Shader> &GetShader() const;
		std::optional<std::reference_wrapper<const std::unique_ptr<Texture>>> GetDiffuseTexture() const;
		std::optional<std::reference_wrapper<const std::unique_ptr<Texture>>> GetSpecularTexture() const;
		std::optional<std::reference_wrapper<const std::unique_ptr<Texture>>> GetNormalTexture() const;
		const Color &GetDiffuseColor() const;
		const Color &GetSpecularColor() const;
		const Color &GetAmbientColor() const;
		bool GetTwoSided() const;
		Graphics::DrawMode GetDrawMode() const;
		void SetShader(std::unique_ptr<Shader> shader);
		void SetDiffuseTexture(std::unique_ptr<Texture> diffuse);
		void SetSpecularTexture(std::unique_ptr<Texture> specular);
		void SetNormalTexture(std::unique_ptr<Texture> normal);
		void SetDiffuseColor(const Color &color);
		void SetSpecularColor(const Color &color);
		void SetAmbientColor(const Color &color);
		void SetTwoSided(const bool twoSided);
		void SetDrawMode(const Graphics::DrawMode drawMode);

		static constexpr Color DefaultDiffuseColor = Color(0.75f, 0.75f, 0.75f);
		static constexpr Color DefaultSpecularColor = Color(1.f, 1.f, 1.f);
		static constexpr Color DefaultAmbientColor = Color(0.1f, 0.1f, 0.1f);

	private:
		std::optional<std::reference_wrapper<const std::unique_ptr<Texture>>> GetTexture(const std::size_t index) const;

		std::unique_ptr<Shader> m_shader;
		std::unordered_map<int, std::unique_ptr<Texture>> m_textures;
		std::array<Color, 3> m_colors{DefaultDiffuseColor, DefaultSpecularColor, DefaultAmbientColor};
		bool m_twoSided{false};
		Graphics::DrawMode m_drawMode{Graphics::DrawMode::TriangleList};
	};
}
