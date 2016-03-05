////////////////////////////////////////////////////////////
//
// File: drawlist.cpp
// Author: Peter Koek
// Purpose:
//      Implementation of Drawable
//
///////////////////////////////////////////////////////////

#include "drawlist.h"

#include <algorithm>    // For std::find_if
#include <iterator>     // For std::begin, std::end

DrawList::iterator findDrawable(DrawList& list,
                                const std::string& name)
{
    // Lambda function (not required for you to know about)
    // Captures local variable "name" by reference
    // Takes a pointer to a Drawable as parameter
    // Returns whether or not the name of the Drawable equals the captured name
    auto predicate = [&name](Drawable* d)
    {
        return (d->name() == name);
    };

    // Find the first Drawable in the list for which the predicate returns true
    // Use the std::find_if function, so we do not have to make it ourselves (yay!)
    return std::find_if(std::begin(list), std::end(list), predicate);

    // For more information about the available algorithms in the C++ standard library,
    // see http://en.cppreference.com/w/cpp/algorithm
}

Drawable::Drawable(const std::string& name)
    : _name(name)
{ }

const std::string& Drawable::name() const
{
    return _name;
}
