#pragma once

#include <curlpp/cURLpp.hpp>
#include <curlpp/Options.hpp>

#include <sstream>

namespace curlpp
{
	std::string get (std::string hyperlink)
	{
		std::ostringstream os;
		os << curlpp::options::Url(hyperlink);
		return os.str ();
	}
}
