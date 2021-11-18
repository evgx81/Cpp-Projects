#ifndef BAR_H
#define BAR_H

#include "foo.hh"

class Bar : public Foo
{
public:
    Bar();
    ~Bar() {};
};

#endif