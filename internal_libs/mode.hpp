#pragma once
#include <stdexcept>
#include <string>
#include <sstream>

namespace Google
{
	namespace Maps
	{
		namespace API
		{
			struct mode_t
			{
			private:
				static const std::string modes [4];
				unsigned short index;
			public:
				mode_t (std::string a)
				{
					bool in;
					for (unsigned short i = 0 ; i < sizeof(modes)/sizeof(modes[0]) ; i ++)
						if (in = (a == modes [i]))
						{
							index = i;
							break;
						}
					if (!in)
						throw std::range_error ("Mode is invalid");
				}

				std::string get () const
				{
					return modes [index];
				}
			};
			const std::string mode_t::modes [4] = { "driving", "walking", "bicycling", "transit" }; 	
		}
	}
}

