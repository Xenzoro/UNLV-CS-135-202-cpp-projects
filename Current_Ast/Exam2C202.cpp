#include <iostream>

class shape
        {
        public:
            shape(): length(0), width(0), height(0){};

            shape(double length, double width, double height) : length(length), width(width), height(height){};

            virtual void area() = 0;

            virtual void perimeter() = 0;

            int getLength() const
            {
                return length;
            }

            int getWidth() const
            {
                return width;
            }

            int getHeight() const
            {
                return height;
            }

        private:
            double length;
            double width;
            double height;
        };
class rectangle : public shape
{
    public:
    rectangle() : shape(){};
    rectangle(double l, double w, double h) : shape(l, w, h){};

    void perimeter()
    {
        std::cout << "Perimeter of rectangle is " << 2 * (getWidth() + getHeight()) << std::endl;
    }
    void area()
    {
       std::cout << "Area of rectangle is " << getLength() * getWidth() << std::endl;
    }
    private:

};
int main()
{
    rectangle r(10, 5,0);
    r.area();
    r.perimeter();
    return 0;
}