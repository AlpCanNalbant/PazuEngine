#pragma once
#include "../Object.h"

namespace Pazu::Graphics
{
	struct ITextureData;
	class Texture : public Object
	{
	public:
		Texture() = default;
		Texture(const std::shared_ptr<ITextureData> &data, const Size &size);
		template <typename T = ITextureData>
		std::shared_ptr<T> GetData() const;
		const Size &GetSize() const;
		void SetData(const std::shared_ptr<ITextureData> &data);
		void SetSize(const Size &size);

	protected:
		std::shared_ptr<ITextureData> m_data;
		Size m_size;
	};
}
#include "Texture.inl"
