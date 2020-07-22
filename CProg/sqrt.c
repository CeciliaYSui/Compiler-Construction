/*-----------------------------------------------------------
* Programmer--Bryan Crawley
* Course------CS 4223
* Project-----Homework #2
* Due---------September 10, 2019 *
* This program computes and displays an estimated square
* root. *----------------------------------------------------------- */
#include <stdio.h>
int main() {
/* The number whose square root is estimated */ /* Estimated square root */
float x;
float estimate;
float newEstimate; /* Closer estimated square root */ float difference; /* Difference between estimates */
/* Enter the raw data. */ printf("Select number: "); scanf("%f",&x);
/* An initial estimate of the square root */ newEstimate = 1.0;
/* Estimate the square root */ do {
estimate = newEstimate;
newEstimate = 0.5*(estimate + x/estimate); difference = newEstimate - estimate;
} while ((difference < -0.005) || (difference > 0.005));
/* Display the estimated square root */ printf("Approximate square root: %e\n", newEstimate); return 0;
}