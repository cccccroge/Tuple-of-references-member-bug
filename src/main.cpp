#include <tuple>
#include <string>
#include <vector>
#include <iostream>

class ElementA
{
public:
    ElementA(const int i) : integer(i)
    {
    }
    ElementA() : integer(-1)
    {
    }

private:
    int integer;
};

class ElementB
{
public:
    ElementB(const std::string s) : string(s)
    {
    }
    ElementB() : string("HI")
    {
    }

private:
    std::string string;
};

class Holder
{
public:
    Holder()
    {

    }

    void pushElementA(const ElementA& e)
    {
        ElementA a;
        ElementB b;
        ElementA &ra = a;
        ElementB &rb = b;
        std::tuple<ElementA&, ElementB&> tup = std::forward_as_tuple(ra, rb);

        try
        {
            tup = vector.at(0);
        }
        catch(const std::exception& exception)
        {
            std::cerr << exception.what() << '\n';
            std::get<0>(tup) = e;
            vector.insert(vector.begin()+0, tup);
            return;
        }

        std::get<0>(vector.at(0)) = e;
    }

    void pushElementB(const ElementB& e)
    {
        ElementA a;
        ElementB b;
        ElementA &ra = a;
        ElementB &rb = b;
        std::tuple<ElementA&, ElementB&> tup = std::forward_as_tuple(ra, rb);

        try
        {
            tup = vector.at(0);
        }
        catch(const std::exception& exception)
        {
            std::cerr << exception.what() << '\n';
            std::get<1>(tup) = e;
            vector.insert(vector.begin()+0, tup);
            return;
        }

        std::get<1>(vector.at(0)) = e;
    }

    void doSomethingElse()
    {
        ElementA a;
        ElementB b;
        ElementA &ra = a;
        ElementB &rb = b;
        std::tuple<ElementA&, ElementB&> tup = std::forward_as_tuple(ra, rb);

        tup = vector.at(0);
    }

private:
    std::vector<std::tuple<ElementA &, ElementB &>> vector;
};

int main(void)
{
    Holder *holder = new Holder();

    ElementA *a = new ElementA(18);
    holder->pushElementA((*a));

    ElementB *b = new ElementB("YO");
    holder->pushElementB((*b));
    
    holder->doSomethingElse();

    return 0;
}