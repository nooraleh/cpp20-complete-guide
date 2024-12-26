#pragma once
#include <concepts>

template<typename COLLECTION>
concept push_backable = requires(COLLECTION collection, COLLECTION::value_type value)
{
	collection.push_back(value);
};


template<typename Coll, typename T>
void add(Coll& coll, const T& val)
{
	coll.push_back(val);
}


template<typename Coll>
requires push_backable<Coll> && std::copyable<Coll>
void add(Coll& coll, const typename Coll::value_type& val)
{
	coll.push_back(val);
}