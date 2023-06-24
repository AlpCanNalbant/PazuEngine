namespace Pazu
{
	template <unsigned int Dimension>
	void CameraSystem::CalculateProjection() const
	{
		if constexpr (Dimension == 3)
		{
			if (std::get<0>(m_3dComponent))
				std::get<1>(m_3dComponent)->CalculateProjection();
		}
		else if constexpr (Dimension == 2)
		{
			if (std::get<0>(m_2dComponent))
				std::get<1>(m_2dComponent)->CalculateProjection();
		}
	}

	template <unsigned int Dimension>
	void CameraSystem::CalculateView() const
	{
		if constexpr (Dimension == 3)
		{
			if (const auto &entity = std::get<0>(m_3dComponent))
				entity->GetTransform().CalculateLookAt();
		}
		else if constexpr (Dimension == 2)
		{
			if (const auto &entity = std::get<0>(m_2dComponent))
				entity->GetTransform().CalculateLookAt();
		}
	}

	template <unsigned int Dimension>
	const Matrix &CameraSystem::GetProjection() const
	{
		if constexpr (Dimension == 3)
		{
			if (std::get<0>(m_3dComponent))
				return std::get<1>(m_3dComponent)->GetProjection();
		}
		else if constexpr (Dimension == 2)
		{
			if (std::get<0>(m_2dComponent))
				return std::get<1>(m_2dComponent)->GetProjection();
		}
		return Matrix::Identity;
	}

	template <unsigned int Dimension>
	Matrix CameraSystem::GetView() const
	{
		if constexpr (Dimension == 3)
		{
			if (const auto &entity = std::get<0>(m_3dComponent))
				return entity->GetTransform().GetMatrix();
		}
		else if constexpr (Dimension == 2)
		{
			if (const auto &entity = std::get<0>(m_2dComponent))
				return entity->GetTransform().GetMatrix();
		}
		return Matrix::Identity;
	}

	template <unsigned int Dimension>
	bool CameraSystem::GetProjectionDirty() const
	{
		if constexpr (Dimension == 3)
		{
			if (std::get<0>(m_3dComponent))
				return std::get<1>(m_3dComponent)->GetDirty();
		}
		else if constexpr (Dimension == 2)
		{
			if (std::get<0>(m_2dComponent))
				return std::get<1>(m_2dComponent)->GetDirty();
		}
		return false;
	}

	template <unsigned int Dimension>
	bool CameraSystem::GetViewDirty() const
	{
		if constexpr (Dimension == 3)
		{
			if (const auto &entity = std::get<0>(m_3dComponent))
				return entity->GetTransform().GetDirty();
		}
		else if constexpr (Dimension == 2)
		{
			if (const auto &entity = std::get<0>(m_2dComponent))
				return entity->GetTransform().GetDirty();
		}
		return false;
	}

	template <unsigned int Dimension>
	void CameraSystem::SetProjection(const Matrix &projection) const
	{
		if constexpr (Dimension == 3)
		{
			if (std::get<0>(m_3dComponent))
				return std::get<1>(m_3dComponent)->SetProjection(projection);
		}
		else if constexpr (Dimension == 2)
		{
			if (std::get<0>(m_2dComponent))
				return std::get<1>(m_2dComponent)->SetProjection(projection);
		}
	}

	template <unsigned int Dimension>
	void CameraSystem::SetView(const Matrix &view) const
	{
		if constexpr (Dimension == 3)
		{
			if (const auto &entity = std::get<0>(m_3dComponent))
				return entity->GetTransform().SetMatrix(view);
		}
		else if constexpr (Dimension == 2)
		{
			if (const auto &entity = std::get<0>(m_2dComponent))
				return entity->GetTransform().SetMatrix(view);
		}
	}

	template <unsigned int Dimension>
	void CameraSystem::SetProjectionDirty(const bool dirty) const
	{
		if constexpr (Dimension == 3)
		{
			if (std::get<0>(m_3dComponent))
				std::get<1>(m_3dComponent)->SetDirty(dirty);
		}
		else if constexpr (Dimension == 2)
		{
			if (std::get<0>(m_2dComponent))
				std::get<1>(m_2dComponent)->SetDirty(dirty);
		}
	}

	template <unsigned int Dimension>
	void CameraSystem::SetViewDirty(const bool dirty) const
	{
		if constexpr (Dimension == 3)
		{
			if (const auto &entity = std::get<0>(m_3dComponent))
				entity->GetTransform().SetDirty(dirty);
		}
		else if constexpr (Dimension == 2)
		{
			if (const auto &entity = std::get<0>(m_2dComponent))
				entity->GetTransform().SetDirty(dirty);
		}
	}
}
