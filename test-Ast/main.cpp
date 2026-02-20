#include <iostream>
// #include <array>
using namespace std;

int main()
{
    double  arrayd[6]{30,25,10,54,20,63};
    double  min = arrayd[0];
    double  max = arrayd[0];
    double  sum = 0.0;
    double  avg = 0.0;
    double  estMedian = 0.0; // this is just an estimate of the median, it is not accurate because if the array is not even, it will not be accurate.
    int     len = sizeof(arrayd)/sizeof(arrayd[0]);

    //divisable by 7
    int count7 = 0;
    double  sum7 = 0.0;
    double  avg7 = 0.0;

    // divisible by 12
    int count12 = 0;
    double  sum12 = 0.0;
    double  avg12 = 0.0;

    for (int i = 0; i < len; i++)
    {

        // this adds up all the values of the array and stores it in sum
        sum += arrayd[i];
        if (arrayd[i] < min){
            min = arrayd[i];
        }
        if (arrayd[i] > max){
            max = arrayd[i];
        }
        if ((int)arrayd[i]%7 == 0)
        {
            count7++;
            sum7 += arrayd[i];
        }
        if ((int)arrayd[i]%12 == 0)
        {
            count12++;
            sum12 += arrayd[i];
        }
    }   // median == odd
        if ( len %2  != 0)
            {
                int mid = len / 2; // this gives mid index
                estMedian = (arrayd[0]+arrayd[mid]+arrayd[len-1])/3;
            }else // median == even
            {
                int mid = len / 2;  //upper middle
                int mid2 = mid - 1; //lower middle
                // estMedian = ((mid + mid2) / 2)+(arrayd[0]+arrayd[len-1])/4; //giberdangle
               estMedian = (((arrayd[mid] + arrayd[mid2]) /2) + arrayd[0]+ arrayd[len-1]) / 4; //giberdangle

            }


    avg = sum / len;
    cout << "Min: " << min << endl;
    cout << "Max: " << max << endl;
    cout << "Sum: " << sum << endl;
    cout << "Avg: " << avg << endl;
    cout << "Estimated Median: " << estMedian << endl;

}