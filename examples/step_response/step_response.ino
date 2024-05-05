#include <Arduino.h>
#include "RichardsonCriterion.h"

double pt1(double x) {
    return 2.0 * (1.0 - exp(-x / 0.5));
}

void setup() {
	Serial.begin(9600);
    while (!Serial) {
        ; // Wait for serial port to connect
    }
    double step = 0.1;
    double epsilon = 0.001;
    double t = 0.0;
    bool converged = false;

    Serial.println("x\t\tf(x)\t\tsettled");
    Serial.println("-------------------------------------");

	RichardsonCriterion<double> criterion;
    while (!converged)
    {
        double ft = pt1(t);
        criterion.addDataPoint(ft);
        converged = criterion.hasConverged(epsilon);
        Serial.print(t);
        Serial.print("\t\t");
        Serial.print(ft, 6);
        Serial.print("\t\t");
        Serial.println(converged ? "true" : "false");
        t += step;
    }

    Serial.println("-------------------------------------");
    Serial.print("\nConvergence at x = ");
    Serial.print(t - step, 1);
    Serial.print(" for epsilon = ");
    Serial.println(epsilon);
}

void loop() {
}