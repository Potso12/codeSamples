
#include <c++sample.hh>


/*
!!this is just one part of bigger programm so some parts could look odd!!

rules:
one publication can be referenced by only one publication. 
one publication can reference many Publications reference.
this means that publications form a tree.

for example with datastructure
         P1
        /  \
      P2    P3
     /     /  \  
    P4    P5   P6
                 \
                  P7

get_closest_common_parent(P5.id,P7.id) would return P3.id
*/


PublicationID Datastructures::get_closest_common_parent(PublicationID id1, PublicationID id2)
{
    auto pubIter1 = this->publications.find(id1);
    auto pubIter2 = this->publications.find(id2);

    if(pubIter1 == this->publications.end() || pubIter2 == this->publications.end()){
        return NO_PUBLICATION;
    }

    std::unordered_set<PublicationID> publication1ancestors;

    while(pubIter1->second.referencer != NO_PUBLICATION){
        publication1ancestors.insert(pubIter1->second.referencer);
        pubIter1 = this->publications.find(pubIter1->second.referencer);
    }

    while(pubIter2->second.referencer != NO_PUBLICATION){
        if(publication1ancestors.count(pubIter2->second.referencer) != 0){
            return pubIter2->second.referencer;
        }
        pubIter2 = this->publications.find(pubIter2->second.referencer);
    }
    return NO_PUBLICATION;
}