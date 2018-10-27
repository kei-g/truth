#include <algorithm>
#include <functional>

namespace algorithm
{
	struct truth
	{
		typedef truth *pointer;
		struct iterator : std::iterator_traits<pointer>
		{
			bool iterated;
			const truth &owner;
			iterator(const truth &owner, bool iterated)
				: iterated(iterated), owner(owner) {}
			iterator &operator++()
			{
				return iterated = true, *this;
			}
			bool operator!=(const iterator &other) const
			{
				return iterated != other.iterated;
			}
			bool operator<(const iterator &other) const
			{
				return iterated < other.iterated;
			}
			const truth &operator*() const { return owner; }
		};
		const bool condition;
		truth(bool condition) : condition(condition) {}
		iterator begin() const { return iterator(*this, !condition); }
		iterator end() const { return iterator(*this, true); }
	};

	template <typename _Fn>
	void when(bool condition, _Fn fn);
	template <typename _Ty, typename _Fn>
	void when(const _Ty *ptr, _Fn fn);

	template <typename _Fn>
	void unless(bool condition, _Fn fn)
	{
		when<_Fn>(!condition, fn);
	}

	template <typename _Ty, typename _Fn>
	void unless(const _Ty *ptr, _Fn fn)
	{
		when<_Fn>(!ptr, fn);
	}

	template <typename _Fn>
	void when(bool condition, _Fn fn)
	{
		auto t = truth(condition);
		std::for_each(t.begin(), t.end(), [&](const truth &) { fn(); });
	}

	template <typename _Ty, typename _Fn>
	void when(const _Ty *ptr, _Fn fn)
	{
		when<_Fn>(!!ptr, fn);
	}
}
