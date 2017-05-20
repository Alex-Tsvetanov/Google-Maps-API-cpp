#include <iostream>
#include <api.hpp>

using namespace Google::Maps;

int main ()
{
	point Sofia ("Sofia");
	std::cout << Sofia.to_string () << "\n";

	try
	{
		points origins = (std::string)"Sofia" | (std::string)"Plovdiv";
		points destinations = (std::string)"Varna" | (std::string)"Veliko Tarnovo";

		try
		{
			API::client maps ("AIzaSyDrMTsyXH5f1Ib7GPyKk8aXgnVvWaaKi5E");
			try 
			{
				std::cout << maps.distance_matrix (API::output_format_t ("json"), origins, destinations) << "\n"; 
				std::cout << maps.distance_matrix (origins, destinations) << "\n"; 
			}
			catch (std::exception& e) { std::cout << e.what (); }
		}
		catch (std::exception& e) { std::cout << e.what (); }
	}
	catch (std::exception& e) { std::cout << e.what (); }
}
