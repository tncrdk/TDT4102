#pragma once
#include <vector>

namespace cannonball {
double acclY();
double velY(double initVelY, double time);

double posX(double initPosX, double initVelX, double time);
double posY(double initPosY, double initVelY, double time);

void printTime(double time);
double flightTime(double initVelY);

// ---------------------------

double getUserInputTheta();
// Ber brukeren om en startfart
double getUserInputInitVelocity();
// Konverterer fra grader til radianer
double degToRad(double deg);
// Returnerer henholdsvis farten i x-, og y-retning, gitt en vinkel
// theta i grader og en startfart initVelocity.
double getVelocityX(double theta, double initVelocity);
double getVelocityY(double theta, double initVelocity);
// Dekomponerer farten gitt av initVelocity, i x- og y-komponentene
// gitt vinkelen theta. Det første elementet i vectoren skal være
// x-komponenten, og det andre elementet skal være y-komponenten.
// "Vector" i funksjonsnavnet er vektor-begrepet i geometri
std::vector<double> getVelocityVector(double theta, double initVelocity);

double getDistanceTraveled(double velX, double velY);
double targetPractice(double distanceToTarget, double velX, double velY);
} // namespace cannonball