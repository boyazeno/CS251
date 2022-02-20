#include "SimpleArray.h"
 SimpleArray::SimpleArray(AllocationTracker* ptr)
 {
    mArray = ptr;
 }

SimpleArray::~SimpleArray()
{
    delete[] mArray;
}

// Accessors
AllocationTracker* SimpleArray::get() const
{
    return mArray;
}
bool SimpleArray::isNonNull() const
{
    return mArray != nullptr;
}

/**
*  getReference() is const and returns a non-const type in order
*  to mimic dereferencing raw pointers through the subscript
*  operator as closely as possible. A pointer-that-is-const is
*  permitted to alter the data where it points, but may never
*  point to a different address; the same should be true of
*  SimpleArrays-that-are-const.
*/
AllocationTracker& SimpleArray::getReference(const uint32_t i) const
{
    return mArray[i];
}

// Mutators
AllocationTracker* SimpleArray::release()
{
    AllocationTracker* ptr = this->mArray;
    this->mArray = nullptr;
    return ptr;
}

void SimpleArray::reset(AllocationTracker* rhs )
{
    delete[] mArray;
    mArray = rhs;
    return;
}

void SimpleArray::swap(SimpleArray& rhs)
{
    auto t_ptr = rhs.get();
    rhs.reset(this->get());
    this->reset(t_ptr);
    return;
}
