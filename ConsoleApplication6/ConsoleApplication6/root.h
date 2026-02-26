#pragma once

class Root {
public:
    Root();
    Root(const Root& other);
    Root& operator= (Root& other);
    virtual void calculate() = 0;
    virtual void display() const = 0;
    virtual ~Root() {}
};