#include <stdio.h>
#include <locale.h>
#include <math.h>

_Bool iswholenumber(long double unknown) {
	if (ceilf(unknown) == unknown)
		return 1;
	else
		return 0;
}

int main() {
	long double bill, deductible, the_value, outofpocket_max;

	setlocale(LC_NUMERIC, "");

	printf("Enter the bill (without the currency sign or commas): ");
	scanf("%Lf", &bill);
	printf("Enter the deductible (without the currency sign or commas): ");
	scanf("%Lf", &deductible);
	printf("Enter the value after \"/\" in the coinsurance: ");
	scanf("%Lf", &the_value);
	printf("Enter the out-of-pocket maximum (without the currency sign or commas): ");
	scanf("%Lf", &outofpocket_max);
	const long double result = (bill - deductible) * (the_value / 100) + deductible;
	if (result <= outofpocket_max) {
		if (iswholenumber(result))
			printf("$%'.0Lf has to be paid out of pocket.\n", result);
		else
			printf("$%'Lf has to be paid out of pocket.\n", result);
	}
	else {
		if (iswholenumber(outofpocket_max))
			printf("$%'.0Lf has to be paid out of pocket.\n", outofpocket_max);
		else
			printf("$%'Lf has to be paid out of pocket.\n", outofpocket_max);
	}
	return 0;
}
		
