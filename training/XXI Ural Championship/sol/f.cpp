#define _CRT_SECURE_NO_DEPRECATE

#include <string>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <memory.h>
#include <string.h>

using namespace std;

double pi = acos(-1.);

double time_spent;
int cur_time_zone;

double need_psi, need_phi;

char day_of_week[7][4] = {
	"mon",
	"tue",
	"wed",
	"thu",
	"fri",
	"sat",
	"sun"
};

void query(double angle, double dist) {
	if (fabs(angle) < 1e-12 && fabs(dist) < 1e-12) return;
	printf("%.12lf %.12lf\n", angle, dist * 40000 / (2 * pi));
	fflush(stdout);

	time_spent += (angle / 360) * 0.25 + (dist / (2 * pi)) * (13333.333333333333333333333333333);

	int week;
	int hour;
	int minute;

	char week_str[4];

	if (scanf("%s %d:%d", week_str, &hour, &minute) != 3) exit(0);

	if (strcmp(week_str, "---") == 0) {
		exit(0);
	}

	for (int i = 0; i < 7; i++) {
		if (strcmp(week_str, day_of_week[i]) == 0) {
			week = i;
			break;
		}
	}

	double local_time = week * 24 * 60 + hour * 60 + minute;

	double mod2 = fmod(time_spent, 7 * 24 * 60);

	if (mod2 < local_time - 24 * 60 - 5) mod2 += 7 * 24 * 60;
	else if (mod2 > local_time + 24 * 60 + 5) mod2 -= 7 * 24 * 60;

	cur_time_zone = (int) floor(((local_time - mod2 + 5) / 60.) + 1e-9);
}

int check_time_zone(double angle, double dist) {
	query(angle, dist);
	int z = cur_time_zone;
	query(180, dist);
	query(180 - angle, 0.);
	return z;
}

void random_query() {
	query(((double)rand() / RAND_MAX) * 360, ((double)rand() / RAND_MAX) * 2 * pi);
}

void first_binary() {
	int z = cur_time_zone;
	double l = 0, r = pi;
	for (int i = 0; i < 80; i++) {
		double h = (l + r) / 2;
		if (check_time_zone(0, h) == z) {
			l = h;
		} else {
			r = h;
		}
	}
	query(0, l);
}

void second_binary() {
	int z = cur_time_zone;
	double l = 0, r = 180;
	for (int i = 0; i < 80; i++) {
		double h = (l + r) / 2;
		if (check_time_zone(h, 0.01) != z) {
			l = h;
		} else {
			r = h;
		}
	}
	query(r + 1e-9, 0);
}

void third_binary() {
	int z = cur_time_zone;
	double l = 0, r = pi;
	for (int i = 0; i < 80; i++) {
		double h = (l + r) / 2;
		if (check_time_zone(0, h) == z) {
			l = h;
		} else {
			r = h;
		}
	}
	query(0, (l + r) / 2);
	query(0, pi / 2);
}

int main() {
	scanf("%lf %lf", &need_psi, &need_phi);
	need_phi = need_phi * pi / 180.;
	need_psi = need_psi * pi / 180.;
	scanf("%*s %*s");
	while (1) {
		random_query();
		first_binary();
		second_binary();
		third_binary();

		query(90, 0);

		int z = cur_time_zone;

		if (check_time_zone(0, pi / 12) == z - 1) {
			query(180, 0);
		}

		if (check_time_zone(180, pi / 12) == z + 1) {
			query(180, 0);
		}

		for (int i = 0; i < 24; i++) {
			query(0, pi / 12);
			if (abs(cur_time_zone - z) > 1) {
				query(180, 0);
				first_binary();
				query(180, pi - pi / 24);
				break;
			}
			z = cur_time_zone;
		}

		if (need_phi < 0) {
			query(180, -need_phi);
			query(180, 0);
		} else {
			query(0, need_phi);
		}
		if (need_psi < 0) {
			query(-90, 0);
			query(0, -need_psi);
		} else {
			query(90, 0);
			query(0, need_psi);
		}
	}

	return 0;
}
