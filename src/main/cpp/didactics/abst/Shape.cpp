
#ifndef SHAPE_HPP
#define SHAPE_HPP
#include <experimental/bits/shared_ptr.h>

#ifndef TESTING
    # define TESTING  (default value)
#endif

// = delete Inhibiting the automatic generation of a default constructor by the compiler.;
// = default Explicitly forcing the automatic generation of a default constructor by the compiler.
// = noexcept;
#if TESTING==HOST
    # define TESTING
#elif TESTING==TARGET
    # define TESTING
#else
    # define TESTING
#endif

#ifndef TESTING
    # error You must define a value for TESTING
#endif
template <class T>

class Shape
{
enum e_acomany
{
    Audi =4,
    BMW  =5,
    Cadillac  =11,
    Ford      =44,
    Jaguar    =45,
    Lexus,
    Maybach   =55,
    RollsRoyce=65,
    Saab      =111
};

struct movies_t
{
    std::string title;
    int year;
} mine, yours;

struct Books
{
    char title[50];
    char author[50];
    char subject[100];
    int book_id;
};

enum color
{
    red,
    yellow,
    green = 20,
    blue
};

enum class altitude : char
{
    high='h',
    low ='l',

    // C++11 allows the extra comma
};

/*
   std::ostream&
   operator<<(std::ostream& os, color c)
   {
    std::cout<<""<std::endl;

    do
    {
        std::cout<<""<std::endl;
    }
    while(0);

    switch(c)
    {
    case red:
        os << "red";    break;
    case yellow:
        os << "yellow"; break;
    case green:
        os << "green";  break;
    case blue:
        os << "blue";   break;
    default:
        os.setstate(std::ios_base::failbit);
    }

    return os;
   }
   std::ostream&
   operator<<(std::ostream& os, altitude al)
   {
    return os << static_cast<char>(al);
   }
 */

public:

/*! default constructor*/
Shape( );                                                      /*! default constructor*/
Shape( const Shape & ) =     default;                           /*! copy constructor */
Shape( Shape && ) =     default;                                /*! move constructor  noexcept is deduced*/
Shape & operator = ( const Shape & ) =        default;                            /*! copy assignment: clean up target and copy  noexcept is deduced*/
Shape & operator = ( Shape && )      =        default;                            /*! move assignment: clean up target and move */
void swap ( Shape & other ) noexcept;                                /*! ???? */
virtual
~Shape( ) =        default;                                                                   /*! Inline explicitly defaulted destructor definition : clean up */
/*
   Shape() = delete;
   Shape(Shape const&) = delete;
   Shape(Shape &&) = delete;
   Shape& operator=(Shape const&) = delete;
   Shape& operator=(Shape &&) = delete;

   Shape() = delete;
   Shape(Shape const&) = delete;
   Shape(Shape &&) = noexcept;
   Shape& operator=(Shape const&) = delete;
   Shape& operator=(Shape &&) = noexcept;
 */
virtual double surfaceLaterale ( ) =0;
virtual double equationsOfMotion ( ) final;                                                                                                  /* final identifier marks this function as non-overrideable */
virtual unsigned long perimeter ( unsigned long height,unsigned long width ) =        0;                                                                               /* Can create with a unsigned long */

// template<typename T> perimeter(T) = delete; /* But can't create it with anything else */
virtual unsigned long perimeter ( unsigned int height,unsigned int width ) =delete;                                                                                /* But can't create it with anything smaller */
virtual double area ( )                                                    =  0;
virtual void draw ( ) const;
virtual void rotate ( int degrees );

// virtual Point center() const = 0;

void
test ( )
{
    char grade =
        'D';

    switch (grade)
    {
    case 'A':
        std::cout <<
            "Excellent!" <<
            std::endl;
        break;
    case 'B':
    case 'C':
        std::cout <<
            "Well done" <<
            std::endl;
        break;
    case 'D':
        std::cout <<
            "You passed" <<
            std::endl;
        break;
    case 'F':
        std::cout << "Better try again" << std::endl;
        break;
    default:
        std::cout <<
            "Invalid grade" <<
            std::endl;
    }
}
protected:

private:

/*
   typedef CppUnitSet<TestFactory *, std::less<TestFactory *> > Factories;
   Factories m_factories;

   char *test;*/
std::string m_name;
};
#endif
