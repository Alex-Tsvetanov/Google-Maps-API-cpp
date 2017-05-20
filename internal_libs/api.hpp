#pragma once 
#include <stdexcept>
#include <string>
#include <sstream>

#include <ex/curl.hpp>

#include <langs.hpp>
#include <point.hpp>
#include <points-operations.hpp>
#include <output_format.hpp>
#include <mode.hpp>

namespace Google
{
	namespace Maps
	{
		namespace API
		{
			struct client
			{
			private:
				std::string key;
				std::string lang;

				const std::string choose (std::string new_lang) const
				{
					if (Google::Languages::isNotValid (new_lang))
						return this->lang; //default
					return new_lang;
				}

			public:
				client (std::string k, std::string lang = "en-US")
				{
					if (Google::Languages::isNotValid (lang))
						throw std::range_error ("Initial language is not valid"); 

					this->key = k;
					this->lang = lang;
				}

				std::string distance_matrix (output_format_t output, points origins, points destinations, mode_t mode = mode_t("driving"), std::string lang = "")
				{
					lang = choose (lang);
					std::string hyperlink = "https://maps.googleapis.com/maps/api/distancematrix/" + output.get () + "?origins=" + origins.to_string () + "&destinations=" + destinations.to_string () + "&mode=" + mode.get () + "&language=" + lang + "&key=" + this->key;

					std::clog << hyperlink << std::endl;

					return curlpp::get (hyperlink);
				}

				json distance_matrix (points origins, points destinations, mode_t mode = mode_t("driving"), std::string lang = "")
				{
					lang = choose (lang);
					std::string hyperlink = "https://maps.googleapis.com/maps/api/distancematrix/json?origins=" + origins.to_string () + "&destinations=" + destinations.to_string () + "&mode=" + mode.get () + "&language=" + lang + "&key=" + this->key;

					return json::parse (curlpp::get (hyperlink));
				}
			};
		}
	}
}
