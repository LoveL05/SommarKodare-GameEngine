#ifndef UPDATEABLE_H_
#define UPDATEABLE_H_

class Updateable {
public:
    virtual void OnUpdate() = 0;
};

class Startable {
public:
    virtual void OnStart() = 0;
};

#endif /* UPDATEABLE_H_ */
