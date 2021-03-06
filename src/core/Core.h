#pragma once
#include <memory>
#include <utility>
#include <map>
#include <thread>

namespace mc
{
	using Byte = unsigned char;

	template <typename T>
	using Ref = std::shared_ptr<T>;

	template <typename T, typename... Args>
	constexpr Ref<T> MakeRef(Args&& ... args)
	{
		return std::make_shared<T>(std::forward<Args>(args)...);
	}

	template <typename T>
	using UniqueRef = std::unique_ptr<T>;

	template <typename T, typename... Args>
	constexpr UniqueRef<T> MakeUniqueRef(Args&& ... args)
	{
		return std::make_unique<T>(std::forward<Args>(args)...);
	}

	template <typename T>
	using WeakRef = std::weak_ptr<T>;
}
