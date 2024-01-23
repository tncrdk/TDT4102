#include <iostream>
#include <math.h>
#include <vector>

namespace cannonball {
double acclY() { return -9.81; }

double velY(double initVelY, double time) { return initVelY + acclY() * time; }

double posX(double initPosX, double initVelX, double time) {
    return initPosX + initVelX * time;
}

double posY(double initPosY, double initVelY, double time) {
    return initPosY + initVelY * time + acclY() * time * time / 2;
}

void printTime(double time) {
    int hours = static_cast<int>(time / 3600);
    int minutes = static_cast<int>((time - hours * 3600) / 60);
    double seconds = time - hours * 3600 - minutes * 60;
    std::cout << "Timer: " << hours << "\nMinutter: " << minutes
              << "\nSekunder: " << seconds << "\n";
}

double flightTime(double initVelY) { return -2 * initVelY / acclY(); }

double getUserInputTheta() {
    std::cout << "Skriv inn theta (Defaults to 0): ";
    double theta;
    std::cin >> theta;
    return theta;
}

// Ber brukeren om en startfart
double getUserInputInitVelocity() {
    double initVel = 0;
    while (initVel == 0) {
        std::cout << "Skriv inn InitVelocity: ";
        std::cin >> initVel;
    }
    return initVel;
}

// Konverterer fra grader til radianer
double degToRad(double deg) { return deg / 180 * M_PI; }

// Returnerer henholdsvis farten i x-, og y-retning, gitt en vinkel
// theta i grader og en startfart initVelocity.
double getVelocityX(double theta, double initVelocity) {
    return initVelocity * std::cos(degToRad(theta));
}

double getVelocityY(double theta, double initVelocity) {
    return initVelocity * std::sin(degToRad(theta));
}

// Dekomponerer farten gitt av initVelocity, i x- og y-komponentene
// gitt vinkelen theta. Det første elementet i vectoren skal være
// x-komponenten, og det andre elementet skal være y-komponenten.
// "Vector" i funksjonsnavnet er vektor-begrepet i geometri
std::vector<double> getVelocityVector(double theta, double initVelocity) {
    return std::vector<double>{getVelocityX(theta, initVelocity),
                               getVelocityY(theta, initVelocity)};
}

double getDistanceTraveled(double velX, double velY) {
    double time = flightTime(velY);
    return posX(0, velX, time);
}

double targetPractice(double distanceToTarget, double velX, double velY) {
    double distance = getDistanceTraveled(velX, velY);
    return abs(distance - distanceToTarget);
}
} // namespace cannonball