#include <iostream>
#include <api.hpp>

using namespace Google::Maps;

int main ()
{
	point Sofia ("Sofia");
	std::cout << Sofia.to_string () << "\n";
	API::client maps ("AIzaSyDrMTsyXH5f1Ib7GPyKk8aXgnVvWaaKi5E");
	std::cout << maps.distance_matrix (API::output_format_t ("json"), point ("Sofia"), point ("Varna")) << "\n"; 
}
