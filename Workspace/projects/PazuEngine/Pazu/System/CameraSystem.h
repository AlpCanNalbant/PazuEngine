#pragma once
#include "../Math/Matrix.h"
#include "../Entity.h"
#include "../Component/Camera/Camera3DComponent.h"
#include "../Component/Camera/Camera2DComponent.h"
#include "ISystem.h"
#include "IResizableSystem.h"

namespace Pazu
{
	class CameraSystem : public ISystem, public IResizableSystem
	{
	public:
		void Register(const std::shared_ptr<Entity> &entity) final;
		void Unregister(const std::shared_ptr<Entity> &entity) final;
		void Resize(const Size &size) final;
		template <unsigned int Dimension>
		void CalculateProjection() const;
		template <unsigned int Dimension>
		void CalculateView() const;
		template <unsigned int Dimension>
		const Matrix &GetProjection() const;
		template <unsigned int Dimension>
		Matrix GetView() const;
		template <unsigned int Dimension>
		bool GetProjectionDirty() const;
		template <unsigned int Dimension>
		bool GetViewDirty() const;
		template <unsigned int Dimension>
		void SetProjection(const Matrix &projection) const;
		template <unsigned int Dimension>
		void SetView(const Matrix &view) const;
		template <unsigned int Dimension>
		void SetProjectionDirty(const bool dirty) const;
		template <unsigned int Dimension>
		void SetViewDirty(const bool dirty) const;

	private:
		std::tuple<std::shared_ptr<Entity>, std::shared_ptr<Camera3DComponent>> m_3dComponent;
		std::tuple<std::shared_ptr<Entity>, std::shared_ptr<Camera2DComponent>> m_2dComponent;
	};
}
#include "CameraSystem.inl"
