// Copyright (C) 2015 Jérôme Leclercq
// This file is part of the "Nazara Engine - Core module"
// For conditions of distribution and use, see copyright notice in Config.hpp

#pragma once

#ifndef NAZARA_INITIALIZER_HPP
#define NAZARA_INITIALIZER_HPP

#include <Nazara/Prerequesites.hpp>

template<typename... Args>
class NzInitializer
{
	public:
		NzInitializer(bool initialize = true);
		NzInitializer(const NzInitializer&) = delete;
		NzInitializer(NzInitializer&&) = delete; ///TODO
		~NzInitializer();

		bool Initialize();
		bool IsInitialized() const;
		void Uninitialize();

		operator bool() const;

		NzInitializer& operator=(const NzInitializer&) = delete;
		NzInitializer& operator=(NzInitializer&&) = delete; ///TODO

	private:
		bool m_initialized;
};

#include <Nazara/Core/Initializer.inl>

#endif // NAZARA_INITIALIZER_HPP
