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
	StarList getRouteBetween(Star *a, Star *b, StarList& visited);
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

/**
 *  \brief
 *  Gets the shortest route between 2 stars.
 *
 *  \details
 *  This method traverses the start node and its lanes until it reaches it's destination.
 *  The terminating condition is considered to be when the start node and the destination node are the
 *  same. The algorithm maintains a list of visited nodes to avoid infinite looping that'd cause
 *  seg_faults.
 *  This function assumes a directed graph as hinted by the lanes datastructure.
 *  This means that star.1 -> star.2 is not the same as star.2 -> star.1. Please see example below.
 *  
 *  \example
 *  For example consider the following topography:
 *
 *  star.1 -> star.2
 *  star.3 -> star.1
 *  star.2 -> star.3
 *
 *  In the above case, the shortest route from star.1 to star.2 is 1 hop. However, the shortest route
 *  from star.2 to star.1 is 2 hops as it goes via star.3.
 */ 
StarList Galaxy::getRouteBetween(Star *a, Star *b, StarList& visited)
{
    // update route
    StarList route(visited);
    route.push_back(a);
    
    // Already at the destination so return the route
    if (a == b) { return route; }

    const StarList& a_lanes = lanes[a];
    std::vector<StarList> routes;

    StarList shorter_route;
    for (size_t i = 0; i < a_lanes.size(); ++i)
    {
        // skip if the node has been previously traversed 
        if (std::find(visited.begin(), visited.end(), a_lanes[i]) != visited.end()) { continue; } 

        StarList potential_route = getRouteBetween(a_lanes[i], b, route);

        // store if its the first route we find.
        if (shorter_route.empty())
            shorter_route = potential_route;

        // compare to see if we have found a shorter_route and if so store that.
        if (!potential_route.empty() && potential_route.size() < shorter_route.size())
            shorter_route = potential_route;
    }
    
    return shorter_route;
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

	StarList route;
	route = galaxy.getRouteBetween(galaxy.getStar(0), galaxy.getStar(2), route);

	printRoute(route);
}
