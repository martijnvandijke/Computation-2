////////////////////////////////////////////////////////////
//
// File: drawlist.h
// Author: Peter Koek
// Purpose:
//      Class definitions of Item and alias for std::list<Item*>
//
///////////////////////////////////////////////////////////

#ifndef DRAWLIST_H
#define DRAWLIST_H

#include <string>
#include <list>     // For std::list<T>

class Drawable;

//
// Define a name alias for a list of pointers to items
// DrawList is the exact same as std::list<Item*>
//

using DrawList = std::list<Drawable*>;

// The comments below present you with some member functions of DrawList
// For a detailed overview of what std::list<T> template has to offer,
// go to http://en.cppreference.com/w/cpp/container/list

// void DrawList::clear()
//      Clears the list of its contents, resulting in an empty list

// void DrawList::push_back(Drawable* value)
//      Adds a Drawable to the end of the list

// void DrawList::push_front(Drawable* value)
//       Adds a Drawable to the front of the list

// DrawList::iterator DrawList::erase(DrawList::iterator position)
//      Erases the Drawable pointed to by the iterator
//      Returns an iterator to the Drawable after the removed Drawable

// std::size_t size()
//      Returns the number of Drawables that are in the list

// Use the following function to obtain an iterator to a Drawable
// with the specified name
// Note that an iterator can be used as a pointer
DrawList::iterator findDrawable(DrawList& list,
                                const std::string& name);

//
// Drawable is the base class for all drawable objects
//

class Drawable
{
public:
    // Construct a Drawable without a name
    Drawable() = default;

    // Construct a Drawable with a given name
    Drawable(const std::string& name);

    // Defaulted (empty) virtual destructor
    virtual ~Drawable() = default;

    // Draw the object onto the screen
    // The "= 0" part means that this function is a pure virtual
    // Classes that inherit from Drawable must override this
    virtual void draw() const = 0;

    // Print the object in the EDIF++ format
    // Inheriting classes must override this
    virtual void print() const = 0;
      
    // Get the name of the Drawable
    const std::string& name() const;

private:
    std::string _name;    // my name (the payload)
};

#endif // DRAWLIST_H
