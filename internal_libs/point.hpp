#pragma once 
#include <ex/url.hpp>
#include <ex/log.hpp>
#include <ex/json.hpp>
#include <ex/curl.hpp>
#include <string>
#include <list>

namespace Google
{
	namespace Maps
	{
		struct point
		{
		public:	
			float latitude, longitude;
			const float Latitude () const { return latitude; }
			const float Longitude () const { return longitude; }

			point (float x, float y)
			{
				this->latitude = x;
				this->longitude = y;
			}
			
			point (const std::string& name)
			{
				std::string hyperlink = "http://maps.google.com/maps/api/geocode/json?address=" + url_encode (name);
				std::string response = curlpp::get (hyperlink); 
				auto response_object = json::parse (response);
				std::clog << response_object["results"][0]["geometry"]["location"] << std::endl;
				float x = response_object["results"][0]["geometry"]["location"]["lat"];
				float y = response_object["results"][0]["geometry"]["location"]["lng"];
				this->latitude = x;
				this->longitude = y;
			}

			const std::string to_string () const
			{
				std::stringstream ss;
				ss << Latitude () << "," << Longitude ();
				return ss.str ();
			}
		};

		struct points
		{
		private:
			std::list <point> point_set;

		public:
			const std::list <point>& get () const
			{
				return point_set;
			}

			points (float x, float y)
			{
				append (point (x, y));
			}

			points (const std::string& name)
			{
				append (point (name));
			}

			points (const char* name)
			{
				append (point (std::string (name)));
			}

			points (const point& p)
			{
				append (p);
			}

			const std::string to_string () const
			{
				if (point_set.size () == 0)
					throw std::runtime_error ("Empty set of points");

				std::stringstream ss;
				bool first = true;
				for (auto& x : this->point_set)
				{
					if (!first)
						ss << "|";
					ss << x.to_string ();
					first = false;
				}
				return ss.str ();
			}

			void append (point a)
			{
				point_set.push_back (a);
			}
			operator point () const { return *(get ().begin ()); }
		};
	}
}

