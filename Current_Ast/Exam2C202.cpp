#include <iostream>

using namespace std;
class shape
        {
        public:
            shape(): length(0), width(0), height(0){};

            shape(double length, double width, double height) : length(length), width(width), height(height){};

            ~shape();

            virtual void volume() = 0;

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

class cube: public shape
{
public:
    cube() : shape(){};
    cube(double l, double w, double h) : shape(l, w, h){};

    void volume()
    {
        cout << "Volume of cube is " << getLength() * getWidth() * getHeight() << endl;
    }

    void area()
    {
        cout << "Area of cube is " << 2 * (getLength() * getWidth() + getWidth() * getHeight() + getLength() * getHeight()) << endl;
    }

    void perimeter()
    {
        cout << "Perimeter of cube is " << 4 * (getLength() + getWidth() + getHeight()) << endl;
    }


};

class fraction
{
    int numerator;
    int denominator;

    fraction operator* ( const fraction& rhs)
    {
        fraction total;
        total.numerator = this->numerator * rhs.numerator;
        total.denominator = this->denominator * rhs.denominator;
        return total;
    }

    fraction operator/ (const fraction& rhs)
    {
        fraction total;
        total.numerator = this->numerator * rhs.denominator;
        total.denominator = this->denominator * rhs.numerator;
        return total;
    }

    fraction operator! ()
    {
        fraction total;
        total.numerator = this->denominator;
        total.denominator = this->numerator;
        return total;

    }
};

class

int main()
{
    do{
    cout << endl <<"Enter a cube: i.e. <l> <w> <h>" << endl;
    int l1, w1, h1;
    cin >> l1 >> w1 >> h1;
    cube c(l1, w1, h1);
    c.area();
    c.perimeter();
    c.volume();
    cout << "Thank you for using this program" << endl;
    cout << endl << "Do you want to continue? (y/n)" << endl;
    char c1;
    cin >> c1;
    if(c1 == 'n')
    {
        break;

    }
    }while(true);
    return 0;
}