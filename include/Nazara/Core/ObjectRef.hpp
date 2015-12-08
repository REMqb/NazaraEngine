// Copyright (C) 2015 Jérôme Leclercq
// This file is part of the "Nazara Engine - Core module"
// For conditions of distribution and use, see copyright notice in Config.hpp

#pragma once

#ifndef NAZARA_RESOURCEREF_HPP
#define NAZARA_RESOURCEREF_HPP

#include <Nazara/Prerequesites.hpp>
#include <Nazara/Core/RefCounted.hpp>
#include <type_traits>

namespace Nz
{
	template<typename T>
	class ObjectRef
	{
		public:
			ObjectRef();
			ObjectRef(T* object);
			ObjectRef(const ObjectRef& ref);
			template<typename U> ObjectRef(const ObjectRef<U>& ref);
			ObjectRef(ObjectRef&& ref) noexcept;
			~ObjectRef();

			T* Get() const;
			bool IsValid() const;
			T* Release();
			bool Reset(T* object = nullptr);
			ObjectRef& Swap(ObjectRef& ref);

			operator bool() const;
			operator T*() const;
			T* operator->() const;

			ObjectRef& operator=(T* object);
			ObjectRef& operator=(const ObjectRef& ref);
			template<typename U> ObjectRef& operator=(const ObjectRef<U>& ref);
			ObjectRef& operator=(ObjectRef&& ref) noexcept;

		private:
			T* m_object;
	};
}

#include <Nazara/Core/ObjectRef.inl>

#endif // NAZARA_RESOURCEREF_HPP
