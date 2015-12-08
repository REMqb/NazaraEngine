// Copyright (C) 2015 Jérôme Leclercq
// This file is part of the "Nazara Development Kit"
// For conditions of distribution and use, see copyright notice in Prerequesites.hpp

#pragma once

#ifndef NDK_COMPONENTS_CAMERACOMPONENT_HPP
#define NDK_COMPONENTS_CAMERACOMPONENT_HPP

#include <Nazara/Math/Frustum.hpp>
#include <Nazara/Math/Matrix4.hpp>
#include <Nazara/Math/Vector3.hpp>
#include <Nazara/Graphics/AbstractViewer.hpp>
#include <Nazara/Renderer/RenderTarget.hpp>
#include <Nazara/Utility/Node.hpp>
#include <NDK/Component.hpp>

namespace Ndk
{
	class Entity;

	class NDK_API CameraComponent : public Component<CameraComponent>, public Nz::AbstractViewer
	{
		public:
			inline CameraComponent();
			inline CameraComponent(const CameraComponent& camera);
			~CameraComponent() = default;

			void ApplyView() const override;

			inline void EnsureFrustumUpdate() const;
			inline void EnsureProjectionMatrixUpdate() const;
			inline void EnsureViewMatrixUpdate() const;
			inline void EnsureViewportUpdate() const;

			inline float GetAspectRatio() const;
			inline Nz::Vector3f GetEyePosition() const;
			inline Nz::Vector3f GetForward() const;
			inline float GetFOV() const;
			inline const Nz::Frustumf& GetFrustum() const;
			inline unsigned int GetLayer() const;
			inline const Nz::Matrix4f& GetProjectionMatrix() const;
			inline Nz::ProjectionType GetProjectionType() const;
			inline const Nz::RenderTarget* GetTarget() const;
			inline const Nz::Rectf& GetTargetRegion() const;
			inline const Nz::Matrix4f& GetViewMatrix() const;
			inline const Nz::Recti& GetViewport() const;
			inline float GetZFar() const;
			inline float GetZNear() const;

			inline void SetFOV(float fov);
			inline void SetLayer(unsigned int layer);
			inline void SetProjectionType(Nz::ProjectionType projection);
			inline void SetTarget(const Nz::RenderTarget* renderTarget);
			inline void SetTargetRegion(const Nz::Rectf& region);
			inline void SetViewport(const Nz::Recti& viewport);
			inline void SetZFar(float zFar);
			inline void SetZNear(float zNear);

			static ComponentIndex componentIndex;

		private:
			inline void InvalidateFrustum() const;
			inline void InvalidateProjectionMatrix() const;
			inline void InvalidateViewMatrix() const;
			inline void InvalidateViewport() const;

			void OnAttached() override;
			void OnComponentAttached(BaseComponent& component) override;
			void OnComponentDetached(BaseComponent& component) override;
			void OnDetached() override;
			void OnNodeInvalidated(const Nz::Node* node);
			void OnRenderTargetRelease(const Nz::RenderTarget* renderTarget);
			void OnRenderTargetSizeChange(const Nz::RenderTarget* renderTarget);

			void UpdateFrustum() const;
			void UpdateProjectionMatrix() const;
			void UpdateViewMatrix() const;
			void UpdateViewport() const;

			NazaraSlot(Nz::Node, OnNodeInvalidation, m_nodeInvalidationSlot);
			NazaraSlot(Nz::RenderTarget, OnRenderTargetRelease, m_targetReleaseSlot);
			NazaraSlot(Nz::RenderTarget, OnRenderTargetSizeChange, m_targetResizeSlot);

			Nz::ProjectionType m_projectionType;
			mutable Nz::Frustumf m_frustum;
			mutable Nz::Matrix4f m_projectionMatrix;
			mutable Nz::Matrix4f m_viewMatrix;
			Nz::Rectf m_targetRegion;
			mutable Nz::Recti m_viewport;
			const Nz::RenderTarget* m_target;
			mutable bool m_frustumUpdated;
			mutable bool m_projectionMatrixUpdated;
			mutable bool m_viewMatrixUpdated;
			mutable bool m_viewportUpdated;
			mutable float m_aspectRatio;
			float m_fov;
			float m_zFar;
			float m_zNear;
			unsigned int m_layer;
	};
}

#include <NDK/Components/CameraComponent.inl>

#endif // NDK_COMPONENTS_CAMERACOMPONENT_HPP
