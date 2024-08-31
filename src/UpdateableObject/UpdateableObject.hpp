#ifndef UPDATEABLE_OBJECT_HPP
#define UPDATEABLE_OBJECT_HPP

class UpdateableObject {
public:
    virtual ~UpdateableObject() = default;
    virtual void update() = 0;
    virtual int size() = 0;
};

#endif // UPDATEABLE_OBJECT_HPP