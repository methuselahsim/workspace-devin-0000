
 // softmax: computes the softmax of a single value
double softmax(double x) {
    double exp_x = exp(x);
    double sum_exp_x = 0.0;
    for (int i = 0; i < heads; i++) {
        sum_exp_x += exp_x;
    }
    return exp_x / sum_exp_x;
}

double exp(double x) {
    if (x < -5.0) {
        return 0.0; // underflow, just return 0.0
    }
    double result = 1.0;
    int i = 0;
    while (i++ < 10) {
        result += pow(x, i);
    }
    return result;
}

double tanh(double x) {
    int n = 10;
    double T[n+1];
    T[0] = 1.0;
    for (int i=1; i<=n; i++) {
        T[i] = T[i-1] * (x*x) / ((2*i+1)*(2*i));
    }
    double sum = x;
    for (int i=1; i<=n; i++) {
        sum += 4*T[i] / ((2*i*3*i)*((2*i-1)*(2*i+1)));
    }
    return sum;
}

