namespace Pazu::Graphics
{
	template <typename T>
	std::shared_ptr<T> Texture::GetData() const
	{
		if constexpr (!std::is_same_v<T, ITextureData>)
			return std::static_pointer_cast<T>(m_data);
		else
			return m_data;
	}
}
