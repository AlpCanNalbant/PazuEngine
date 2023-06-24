namespace Pazu
{
	template <typename T>
	ModelComponent<T>::ModelComponent(const std::shared_ptr<ModelAsset<T>> &asset)
	{
		SetAsset(asset);
	}

	template <typename T>
	std::optional<std::reference_wrapper<const std::unique_ptr<T>>> ModelComponent<T>::FindSurface(const std::shared_ptr<Material> &material) const
	{
		if (const auto pos = std::find_if(m_surfaces.cbegin(), m_surfaces.cend(), [&material](const auto &s)
																			{ return s->material == material; });
				pos != m_surfaces.cend())
			return std::make_optional(std::cref(*pos));
		return std::nullopt;
	}

	template <typename T>
	const std::vector<std::unique_ptr<T>> &ModelComponent<T>::GetSurfaces() const
	{
		return m_surfaces;
	}

	template <typename T>
	void ModelComponent<T>::SetAsset(const std::shared_ptr<ModelAsset<T>> &asset)
	{
		for (const auto &surface : asset->surfaces)
			m_surfaces.emplace_back(std::make_unique<T>(surface));
		m_asset = asset;
	}
}
