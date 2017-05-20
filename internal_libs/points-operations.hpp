#pragma once 
#include <point.hpp>

namespace Google
{
	namespace Maps 
	{
		template <typename A, typename B>
		points operator | (A a, B b)
		{
			points ans = points (point (a));
			ans.append (point (b));
			return (ans); 
		}

		points operator | (points a, points b)
		{
			for (auto& x : b.get ())
				a.append (x);
			return std::move (a); 
		}

		points operator | (std::pair <float, float> a, points b)
		{
			points c = points (a.first, a.second);
			for (auto& x : b.get ())
				c.append (x);
			return (c); 
		}

		points operator | (std::string a, points b)
		{
			points c = points (a);
			for (auto& x : b.get ())
				c.append (x);
			return (c); 
		}

		points operator | (const char* a, points b)
		{
			points c = points (std::string (a));
			for (auto& x : b.get ())
				c.append (x);
			return (c); 
		}
	}
}
