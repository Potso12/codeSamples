//c++sample.cpp includes the important code
//!!this is just one part of bigger programm so some parts could look odd!!

#include <string>
#include <vector>
#include <tuple>
#include <utility>
#include <limits>
#include <functional>
#include <exception>
#include <map>
#include <set>
#include <queue>

#include <unordered_set>
#include <iostream>
#include <cmath>



using PublicationID = unsigned long long int;
using Year = unsigned short int;


PublicationID const NO_PUBLICATION = -1;
Year const NO_YEAR = -1;

struct Publication {
    PublicationID uniqueIntegerID;
    std::string title;
    Year publicationYear;
    std::vector<PublicationID> publicationsReferences;
    PublicationID referencer; // this is the id of parent
};

class Datastructures
{
public:
    Datastructures();
    ~Datastructures();
    PublicationID get_closest_common_parent(PublicationID id1, PublicationID id2);

private:

    std::unordered_map<PublicationID, Publication> publications;

};
