#pragma once 
#include <ex/log.hpp>
#include <ex/json.hpp>
#include <ex/curl.hpp>
#include <string>

namespace Google
{
	namespace Maps
	{
		struct point
		{
		private:
			float latitude, longitude;
		public:	
			point (float x, float y)
			{
				this->latitude = x;
				this->longitude = y;
			}
			
			point (std::string name)
			{
				std::string hyperlink = "http://maps.google.com/maps/api/geocode/json?address=" + name;
				std::clog << hyperlink << std::endl;
				std::string response = curlpp::get (hyperlink); 
				std::clog << response << std::endl;
				auto response_object = json::parse (response);
				std::clog << response_object << std::endl;
				std::clog << response_object["results"] << std::endl;
				std::clog << response_object["results"][0] << std::endl;
				std::clog << response_object["results"][0]["geometry"]["location"] << std::endl;
				float x = response_object["results"][0]["geometry"]["location"]["lat"];
				float y = response_object["results"][0]["geometry"]["location"]["lng"];
				this->latitude = x;
				this->longitude = y;
			}

			const std::string to_string () const
			{
				std::stringstream ss;
				ss << latitude << "," << longitude;
				return ss.str ();
			}
		};
	}
}
