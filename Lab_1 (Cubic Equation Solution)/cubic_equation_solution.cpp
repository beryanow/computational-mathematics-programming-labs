#include <iostream>
#include <cmath>

using namespace std;

int discriminant_evaluation(int a, int b) {
    int derivative_coefficient_a = a * 2;
    return derivative_coefficient_a * derivative_coefficient_a - 3 * 4 * b;
}

float f(int a, int b, int c, float x) {
    return x * x * x + a * x * x + b * x + c;
}

void find_another_end_with_delta(int a, int b, int c, float &y1, float e, float d, int var) {
    if (var == 0) {
        while (f(a, b, c, y1) < e) {
            y1 += d;
        }
    }
    else if (var == 1) {
        while (f(a, b, c, y1) > e) {
            y1 += d;
        }
    }
}

float plus_value(float discriminant, int a, int var) {
    if (var == 0)
        return (-2 * a + sqrt(discriminant)) / 6;
    if (var == 1)
        return (-2 * a - sqrt(discriminant)) / 6;
}

float bisection_method(int a, int b, int c, float x1, float y1, float e, int var) {
    if (var == 0) {
        if (f(a, b, c, x1) >= -e) {
            return x1;
        }

        if (f(a, b, c, y1) <= e) {
            return y1;
        }
        while ((f(a, b, c, x1) < -e) && (f(a, b, c, y1) > e)) {
            float z1 = (x1 + y1) / 2;
            if (f(a, b, c, z1) > e) {
                y1 = z1;
            } else {
                x1 = z1;
            }

            if (f(a, b, c, x1) >= -e) {
                return x1;
            }

            if (f(a, b, c, y1) <= e) {
                return y1;
            }
        }
    }
    else if (var == 1) {
        if (f(a, b, c, x1) <= e) {
            return x1;
        }

        if (f(a, b, c, y1) >= -e) {
            return y1;
        }
        while ((f(a, b, c, x1) > e) && (f(a, b, c, y1) < -e)) {
            float z1 = (x1 + y1) / 2;
            if (f(a, b, c, z1) < e) {
                y1 = z1;
            } else {
                x1 = z1;
            }

            if (f(a, b, c, x1) < e) {
                return x1;
            }

            if (f(a, b, c, y1) > -e) {
                return y1;
            }
        }
    }
}

int main() {
    int a, b, c;
    float x1, y1, d, e;

    cout << "Enter value for a, b, c:\n";
    cin >> a >> b >> c;

    cout << "Enter value for d, e:\n";
    cin >> d >> e;

    cout << "Enter starting value:\n";
    cin >> x1;

    y1 = x1;
    find_another_end_with_delta(a, b, c, y1, e, d, 0);
    float value_1 = bisection_method(a, b, c, x1, y1, e, 0);


    int derivative_discriminant = discriminant_evaluation(a, b);
    if (derivative_discriminant < 0) {
        cout << "The only value is: " << value_1;
    } else if (derivative_discriminant == 0) {
        float v1 = plus_value(derivative_discriminant, a, 1);
        if ((f(a, b, c, v1) < e) && (f(a, b, c, v1) > -e)) {
            cout << endl << "The first root is: " << value_1 << endl;
            cout << "The second root is: " << value_1 << endl;
            cout << "The third root is: " << value_1 << endl;
        }
    }
    else if (derivative_discriminant > 0) {
        float v1 = plus_value(derivative_discriminant, a, 1);
        float v2 = plus_value(derivative_discriminant, a, 0);

        if (((f(a, b, c, v1) > 0) && (f(a, b, c, v2) > 0)) || ((f(a, b, c, v1) < 0) && (f(a, b, c, v2) < 0))) {
            cout << "The only value is: " << value_1;
        } else if ((f(a, b, c, v1) > 0) && (f(a, b, c, v2) < 0)) {
            x1 = v1;
            y1 = x1;
            find_another_end_with_delta(a, b, c, y1, e, d, 1);
            float value_2 = bisection_method(a, b, c, x1, y1, e, 1);

            x1 = v2;
            y1 = x1;
            find_another_end_with_delta(a, b, c, y1, e, d, 0);
            float value_3 = bisection_method(a, b, c, x1, y1, e, 0);

            cout << endl << "The first root is: " << value_1 << endl;
            cout << "The second root is: " << value_2 << endl;
            cout << "The third root is: " << value_3 << endl;
        }
        else if ((f(a, b, c, v1) < e) && (f(a, b, c, v1) > -e)) {
            x1 = v1;
            y1 = x1;
            find_another_end_with_delta(a, b, c, y1, e, d, 1);
            float value_2 = bisection_method(a, b, c, x1, y1, e, 1);
            cout << endl << "The first root is: " << value_1 << endl;
            cout << "The second root is: " << value_2 << endl;
            cout << "The third root is: " << value_2 << endl;
        }
        else if ((f(a, b, c, v2) < e) && (f(a, b, c, v2) > -e)) {
            x1 = v1;
            y1 = x1;
            find_another_end_with_delta(a, b, c, y1, e, d, 1);
            float value_2 = bisection_method(a, b, c, x1, y1, e, 1);
            cout << endl << "The first root is: " << value_1 << endl;
            cout << "The second root is: " << value_2 << endl;
            cout << "The third root is: " << value_2 << endl;
        }
    }

    return 0;
}
