/*
 * Blazing Griffin code test
 * Part 3 : Game logic
 *
 * Trevor Fountain
 * April 2013
 */

#include <vector>
#include <map>
#include <iostream>

/**
@brief Represents a point in space.
*/
class Star
{
public:
	/// The x-coordinate of this Star's location, in pixel coordinates
	double x;
	/// The y-coordinate of this Star's location, in pixel coordinates
	double y;

	/// Create a star at the specified location in pixel coordinates
	Star(double x, double y) { this->x = x; this->y = y; }

	/// Print this Star as a coordinate pair
    friend std::ostream& operator<<( std::ostream &out, const Star &star );
};

std::ostream &operator<<(std::ostream &out, const Star &star)
{
	out << "(" << star.x << ", " << star.y << ")";

	return out;
}

/// A randomly-accessible list of Stars
typedef std::vector<Star *> StarList;
/// Maps Stars onto lists of adjacent Stars
typedef std::map<Star *, StarList> StarAdjacencyList;

/**
@brief Hold information about stars and lanes.
*/
class Galaxy
{
protected:
	/// A list of Stars in the Galaxy
	StarList stars;
	/// A map of lanes between Stars
	StarAdjacencyList lanes;

public:
	/// Create the default Galaxy
	Galaxy();

	// Get a star
	Star *getStar(int index);

	// Return a list of stars to traverse in order to move from A to B.
	StarList getRouteBetween(Star *a, Star *b);
};

Galaxy::Galaxy()
{
	// Set up a simple galaxy
	// ...with a few stars
	stars.push_back(new Star(0, 0));
	stars.push_back(new Star(50, 30));
	stars.push_back(new Star(100, 0));
	stars.push_back(new Star(40, -10));
	stars.push_back(new Star(60, -10));

	// ...and a few lanes between them
	lanes[stars[0]].push_back(stars[1]);
	lanes[stars[0]].push_back(stars[3]);
	lanes[stars[1]].push_back(stars[0]);
	lanes[stars[1]].push_back(stars[4]);
	lanes[stars[1]].push_back(stars[2]);
	lanes[stars[2]].push_back(stars[1]);
	lanes[stars[2]].push_back(stars[4]);
	lanes[stars[3]].push_back(stars[0]);
	lanes[stars[3]].push_back(stars[4]);
	lanes[stars[4]].push_back(stars[1]);
	lanes[stars[4]].push_back(stars[2]);
	lanes[stars[4]].push_back(stars[3]);
}

Star *Galaxy::getStar(int index)
{
	if (index < 0 || index >= stars.size())
	{
		return NULL;
	}

	return stars[index];
}

StarList Galaxy::getRouteBetween(Star *a, Star *b)
{
	StarList route;

	// Implement me!

	return route;
}

/// Helper function to print a route to the console
void printRoute(StarList route)
{
	std::cout << "[" << route.size() << "]:";

	// Don't print 0-length routes!
	if (route.size() <= 0)
	{
		std::cout << std::endl;
		return;
	}

	for(int starIndex = 0; starIndex < route.size()-1; ++starIndex)
	{
		std::cout << *route[starIndex] << " -> ";
	}

	if (route.size() > 0)
	{
		std::cout << *route[route.size()-1] << std::endl;
	}
}

int main(int argc, char **argv)
{
	Galaxy galaxy;

	printRoute(galaxy.getRouteBetween(galaxy.getStar(0), galaxy.getStar(2)));
}