#pragma once
#include <utility>

namespace nb
{
	template<typename F, typename... ARGS>
	concept invocable = requires(F && f, ARGS&&... args)
	{
		std::invoke(std::forward<F>(f), std::forward<ARGS>(args)...);
	};
}


template<typename COLLECTION>
void add(COLLECTION& collection, const typename COLLECTION::value_type& value)
{
	if constexpr (requires{collection.push_back(value); })
	{
		collection.push_back(value);
	}
	else
	{
		collection.insert(value);
	}
}