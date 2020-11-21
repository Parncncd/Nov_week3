#include<stdio.h>
struct type {
	float lightBulb;
	float waterHeater;
	float air;
	float iron;
}p1, p2, p;
float onePersonCalculator(float, float, float, float);
float twoPersonCalculator(float, float, float, float, float, float);
int main() {

	int answer = -1;
	printf("                 This is an electricity bill calculator                \n ");
	printf("If you are living with a room mate please enter 1,if not enter 0 \n");
	while (!(answer == 0 || answer == 1))
	{
		scanf_s("%d", &answer);
		if (answer != 0 && answer != 1) {
			printf("Please enter 0 or 1\n");
		}
			
	}


	if (answer == 0) {

		p1.lightBulb = -1, p1.waterHeater = -1, p1.air = -1, p1.iron = -1;
		while (!(p1.lightBulb >= 0)) {
			printf("Please enter amount time(number of hour) that you use the light in one day: ");
			scanf_s("%f", &p1.lightBulb);
			if (p1.lightBulb < 0) {
				printf("           !!!!!!Please enter positive number!!!!!!             \n");
			}
		}
		while (!(p1.waterHeater >= 0)) {

			printf("Please enter amount time(number of hour) that you use the water heater in one day: ");
			scanf_s("%f", &p1.waterHeater);
			if (p1.waterHeater < 0) {
				printf("           !!!!!!Please enter positive number!!!!!!             \n");
			}
		}
		while (!(p1.air >= 0)) {

			printf("Please enter amount time(number of hour) that you use the air conditioner in one day: ");
			scanf_s("%f", &p1.air);
			if (p1.air < 0) {
				printf("           !!!!!!Please enter positive number!!!!!!             \n");
			}
		}
		while (!(p1.iron >= 0)) {

			printf("Please enter amount time(number of hour) that you use the iron in one week: ");
			scanf_s("%f", &p1.iron);
			if (p1.iron < 0) {
				printf("           !!!!!!Please enter positive number!!!!!!             \n");
			}
		}
		float unit = onePersonCalculator(p1.lightBulb, p1.waterHeater, p1.air, p1.iron);
		printf("Unit: %.0f\n", unit);
		printf("                    You must pay for electricity bill: %.0f THB\n          ", unit * 5);

	}

	else if (answer == 1) {

		p1.waterHeater = -1, p1.iron = -1;
		p2.waterHeater = -1, p2.iron = -1;
		p.lightBulb = -1, p.air = -1;


		while (!(p.lightBulb >= 0)) {
			printf("Please enter amount time(number of hour) that you two turn on the light in one day: ");
			scanf_s("%f", &p.lightBulb);
			if (p.lightBulb < 0) {
				printf("           !!!!!!Please enter positive number!!!!!!             \n");
			}
		}

		while (!(p1.waterHeater >= 0 && p2.waterHeater >= 0)) {

			printf("Please enter amount time(number of hour) that you use the water heater in one day: ");
			scanf_s("%f", &p1.waterHeater);
			printf("Please enter amount time(number of hour) that your roommate use the water heater in one day: ");
			scanf_s("%f", &p2.waterHeater);
			if (p1.waterHeater < 0 || p2.waterHeater < 0) {
				printf("           !!!!!!Please enter positive number!!!!!!             \n");
			}
		}
		while (!(p.air >= 0)) {

			printf("Please enter amount time(number of hour) that you two use the air conditioner in one day: ");
			scanf_s("%f", &p.air);

			if (p.air < 0) {
				printf("           !!!!!!Please enter positive number!!!!!!             \n");
			}
		}
		while (!(p1.iron >= 0 && p2.iron >= 0)) {

			printf("Please enter amount time(number of hour) that you use the iron in one week: ");
			scanf_s("%f", &p1.iron);
			printf("Please enter amount time(number of hour) that your roommate use the iron in one week: ");
			scanf_s("%f", &p2.iron);
			if (p1.iron < 0 || p2.iron < 0) {
				printf("           !!!!!!Please enter positive number!!!!!!             \n");
			}
		}
		float unit = twoPersonCalculator(p.lightBulb, p.air, p1.waterHeater, p2.waterHeater, p1.iron, p2.iron);
		printf("You and your roommate used  %.0f unit:\n", unit);

		printf("                You and your roommate must pay for electricity bill: %.0f\n          ", unit * 5);
		printf("                  About %.0f THB each              ", unit * 5/2);

	}

	return 0;
}
float onePersonCalculator(float a, float c, float d, float e) {
	float light = (a * 50 / 1000) * 30;
	float water = (4500 * c / 1000) * 30;
	float air = (2000 * d / 1000) * 30;
	float iron = (800 * e / 1000) * 4;
	float unit = light + water + air + iron;
	return unit;
}

float twoPersonCalculator(float a, float b, float c, float d, float e, float f) {
	float light = (a * 50 / 1000) * 30;
	float air = (2000 * b / 1000) * 30;
	float water1 = (4500 * c / 1000) * 30;
	float water2 = (4500 * d / 1000) * 30;
	float iron1 = (800 * e / 1000) * 4;
	float iron2 = (800 * f / 1000) * 4;
	float unit = light + water1 + water2 + air + iron1 + iron2;
	return unit;
}
