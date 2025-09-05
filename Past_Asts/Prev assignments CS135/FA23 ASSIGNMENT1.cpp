/*
    * Name: Jacob Martinez,
    * NSHE_ID_#5007553403, 1008,
    * ASSIGNMENT_# FA23 ASSIGNMENT 1.
    * Description: use input/output variables
    * and arithmetic.
    * Input: values for arithmetic.
    * Output: prices/profits/quantities.
*/
#include <iostream>
int main(){using namespace std;
    const int Bundle_Size = 100;
    const double Markup =.75 ;
    long double input_bundle_cost (0);
    double single_door_sale_price (0);
    double single_door_cost (0);
    double single_door_profit (0);
    double input_bundle_qty (0);
    int total_doors (0);
    cout << "How many door bundles are needed? ";
    cin >> input_bundle_qty;
    cout << "How much does each bundle cost? \n";
    cin >> input_bundle_cost;
    cout << "Bundle Quantity: " << input_bundle_qty << endl;
    cout << "Bundle Cost: " << input_bundle_cost << endl;
    total_doors = Bundle_Size * input_bundle_qty;
    cout << "Total Doors Purchased: " << total_doors << endl;
    single_door_cost = input_bundle_cost / Bundle_Size;
    cout << "Single Door Cost: " << single_door_cost << endl;
    cout << "Total Cost: "<< input_bundle_cost * input_bundle_qty<< endl;
    single_door_sale_price=single_door_cost+single_door_cost*Markup;
    cout << "Single Door Sale Price: " << single_door_sale_price << endl;
    cout<<"Total Sale Price: "<<single_door_sale_price*total_doors<<endl;
    single_door_profit = single_door_sale_price - single_door_cost;
    cout << "Single Door Profit: " << single_door_profit << endl;
    cout << "Total Profit: " << single_door_profit * total_doors;
    return 0;
}