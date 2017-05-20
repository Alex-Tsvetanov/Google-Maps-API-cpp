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
			struct output_format_t
			{
			private:
				static const std::string output_formats [2];
				unsigned short index;
			public:
				output_format_t (std::string a = "xml")
				{
					bool in;
					for (unsigned short i = 0 ; i < sizeof(output_formats)/sizeof(output_formats[0]) ; i ++)
						if (in = (a == output_formats [i]))
							index = i;
					if (!in)
						throw std::range_error ("Output format is invalid");
				}

				std::string get () const
				{
					return output_formats [index];
				}
			};
			const std::string output_format_t::output_formats [2] = { "xml" , "json" }; 
		}
	}
}
