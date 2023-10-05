// Copyright (c) Alp Can Nalbant. Licensed under the MIT License.

namespace Pazu
{
	template <typename T>
	std::shared_ptr<T> AssetManager::Load(const std::string &path) const
	{
		if (const auto pair = m_cache.find(path); pair != m_cache.cend())
		{
			if (const auto content = pair->second.lock())
				return std::static_pointer_cast<T>(content);
			m_cache.erase(pair);
			return Load<T>(path);
		}
		if (const auto pair = m_loaders.find(typeid(T)); pair != m_loaders.cend())
		{
			if (const auto content = std::static_pointer_cast<T>(pair->second->Load(path, *this)))
			{
				m_cache[path] = content;
				return content;
			}
			return nullptr;
		}
		return Log::Get().Print<LogMode::Error, std::nullptr_t>("Gecersiz asset tipi.");
	}
} // namespace Pazu
