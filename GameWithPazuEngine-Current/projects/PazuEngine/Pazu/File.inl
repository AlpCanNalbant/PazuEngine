namespace Pazu
{
	template <typename T>
	std::unique_ptr<T> File::Open(const std::string &path)
	{
		const auto fullPath = m_dir + path;
		std::basic_ofstream<typename T::Type> ofstream(fullPath, std::ios::out);
		std::basic_ifstream<typename T::Type> ifstream(fullPath, std::ios::in);
		if (!ofstream.is_open() || !ifstream.is_open())
			return nullptr;
		return std::make_unique<T>(std::move(ofstream), std::move(ifstream));
	}
}
