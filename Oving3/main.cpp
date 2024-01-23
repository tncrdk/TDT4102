#include "cannonball.h"
#include "cannonball_viz.h"
#include "std_lib_facilities.h"
#include "utilities.h"
#include <iomanip>

void testDeviation(double compareOperand, double toOperand, double maxError,
                   string name);

void playTargetPractice();

int main() {
    // double theta = 27.5;
    // double initVel = 15.64;

    // vector<double> result = cannonball::getVelocityVector(theta, initVel);

    // double error = cannonball::targetPractice(20, result.at(0),
    // result.at(1)); cout << error << "\n";

    playTargetPractice();

    return 0;
}

void testDeviation(double compareOperand, double toOperand, double maxError,
                   std::string name) {
    bool result = abs(compareOperand - toOperand) <= maxError;
    if (result) {
        cout << name << "\nResultat: is valid\n";
    } else {
        cout << name << "\nResultat: not valid. Expected " << toOperand
             << " but got " << compareOperand << ".\n";
    }
}

void playTargetPractice() {
    int chances_left = 3;
    double target_distance = utilities::randomWithLimits(100, 1000);
    while (chances_left > 0) {
        double input_vel = cannonball::getUserInputInitVelocity();
        double input_theta = cannonball::getUserInputTheta();
        std::vector<double> input_vel_vector =
            cannonball::getVelocityVector(input_theta, input_vel);
        double distance_traveled = cannonball::getDistanceTraveled(
            input_vel_vector.at(0), input_vel_vector.at(1));
        double error = cannonball::targetPractice(
            target_distance, input_vel_vector.at(0), input_vel_vector.at(1));

        cannonBallViz(target_distance, 1000, input_vel_vector.at(0),
                      input_vel_vector.at(1), 100);

        if (error < 5) {
            cout << "Gratulerer du har vunnet!\n";
            return;
        }

        cout << "Du skjøt " << setprecision(3) << error << "m for "
             << ((distance_traveled > target_distance) ? "langt" : "kort")
             << "!\n";
        chances_left--;
    }
    cout << "GAME OVER!\nDu har brukt opp sjansene dine.\n";
}