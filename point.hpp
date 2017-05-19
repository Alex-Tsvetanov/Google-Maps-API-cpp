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

			const std::string to_string () const
			{
				std::stringstream ss;
				ss << latitude << "," << longitude;
				return ss.str ();
			}
		};
	}
}
