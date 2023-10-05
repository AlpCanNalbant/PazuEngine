// Copyright (c) Alp Can Nalbant. Licensed under the MIT License.

namespace Pazu
{
	template <typename T>
	const T *Shader::Get() const
	{
		if (const auto pos = m_asset->stages.find(typeid(T)); pos != m_asset->stages.cend())
			return static_cast<T *>(pos->second.get());
		return nullptr;
	}
}
