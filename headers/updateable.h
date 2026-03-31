#ifndef UPDATEABLE_H_
#define UPDATEABLE_H_

class Updateable {
public:
    virtual void onUpdate() = 0;
};

class Startable {
public:
    virtual void onStart() = 0;
};

#endif /* UPDATEABLE_H_ */
