#include <iostream>
#include <cmath>
using namespace std;

const double GALLONS_TO_CUBIC_METERS = 0.00378541;
const double CUBIC_METERS_TO_SQUARE_KILOMETERS = 1e-6;

int main() {
    double rate;
    double thickness;
    int days;
    char choice;

    do {
        cout << "Enter the rate of oil pumping (in gallons per minute): ";
        cin >> rate;
        cout << "Enter the thickness of the oil layer (in meters): ";
        cin >> thickness;
        cout << "Enter the number of days: ";
        cin >> days;

        for (int day = 1; day <= days; ++day) {
            double minutes = day * 24 * 60;
            double volume_gallons = rate * minutes;
            double volume_cubic_meters = volume_gallons * GALLONS_TO_CUBIC_METERS;
            double area_square_meters = volume_cubic_meters / thickness;
            double area_square_kilometers = area_square_meters * CUBIC_METERS_TO_SQUARE_KILOMETERS;

            cout << "Day " << day << ":" << endl;
            cout << "Area covered by spilled oil: " << area_square_kilometers << " square kilometers" << endl;
            cout << "Volume of oil on top of the water: " << volume_gallons << " gallons" << endl;
        }

        cout << "Do you want to calculate another spill? (y/n): ";
        cin >> choice;

    } while (choice == 'y' || choice == 'Y');
    return 0;
}
