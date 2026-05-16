#include <vector>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <string>

using namespace std;
double mean(vector<double> v);
double variance(vector<double> v);

int main(){
    vector<double> ejemplo = {8.0, 1.0, 0.0, 40.0, 25.0};
    fprintf(stdout, "Promedio: %f\n", mean(ejemplo));
    fprintf(stdout, "Varianza: %f\n", variance(ejemplo));

    return 0;
}

double mean(vector<double> v){
    if (v.empty()) return 0;

    double suma = 0;
    for(size_t i = 0; i < v.size(); i++) {
        suma += v[i];
    }
    return suma / v.size();
}

double variance(vector<double> v){
    if (v.size() <= 1) return 0; 
    double prom = mean(v); 
    double suma_cuadrados = 0;
    for(size_t i = 0; i < v.size(); i++) {
        double diferencia = v[i] - prom;
        suma_cuadrados += diferencia * diferencia;
    }
    return suma_cuadrados / (v.size() - 1);
}


using namespace std;

double pearson_r(vector<double> VA, vector<double> VB) {
    int n = VA.size();
    if (n != VB.size() || n == 0) {
        return 0.0; 
    }
    double sumaA = 0.0;
    double sumaB = 0.0;
    
    for (size_t i = 0; i < n; i++) {
        sumaA += VA[i];
        sumaB += VB[i];
    }
    
    double mediaA = sumaA / n;
    double mediaB = sumaB / n;
    double numerador = 0.0;
    double suma_cuadradosA = 0.0;
    double suma_cuadradosB = 0.0;
    for (int i = 0; i < n; i++) {
        double difA = VA[i] - mediaA;
        double difB = VB[i] - mediaB;

        numerador += difA * difB; 
        suma_cuadradosA += difA * difA; 
        suma_cuadradosB += difB * difB; 
    }
    if (suma_cuadradosA == 0.0 || suma_cuadradosB == 0.0) {
        return 0.0;
    }
    return numerador / sqrt(suma_cuadradosA * suma_cuadradosB);
}

vector<char> dec_to_septapus(int n) {
    if (n == 0) return {'0'}; 
    
    vector<char> result;
    while (n > 0) {
        int residuo = n % 7;
        result.push_back(residuo + '0');
        n /= 7;
    }
    
    reverse(result.begin(), result.end()); 
    return result;
}

vector<char> dec_to_octopus(int n) {
    if (n == 0) return {'0'};
    
    vector<char> result;
    while (n > 0) {
        int residuo = n % 8;
        result.push_back(residuo + '0');
        n /= 8;
    }
    
    reverse(result.begin(), result.end());
    return result;
}

vector<char> dec_to_hexakaidecapus(int n) {
    if (n == 0) return {'0'};
    
    vector<char> result;
    char hex_chars[] = "0123456789ABCDEF"; 
    
    while (n > 0) {
        int residuo = n % 16;
        result.push_back(hex_chars[residuo]);
        n /= 16;
    }
    
    reverse(result.begin(), result.end());
    return result;
}

vector<char> septapus_to_dec(vector<char> s) {
    int valor_decimal = 0;

    for (char digito : s) {

        valor_decimal = valor_decimal * 7 + (digito - '0'); 
    }
    string str_decimal = to_string(valor_decimal); 
    vector<char> result(str_decimal.begin(), str_decimal.end()); 
    
    return result;
}

vector<char> octopus_to_dec(vector<char> s) {
    int valor_decimal = 0;
    
    for (char digito : s) {
        valor_decimal = valor_decimal * 8 + (digito - '0');
    }
    
    string str_decimal = to_string(valor_decimal);
    return vector<char>(str_decimal.begin(), str_decimal.end());
}

vector<char> hexakaidecapus_to_dec(vector<char> s) {
    int valor_decimal = 0;
    
    for (char digito : s) {
        int valor_digito;
        if (digito >= '0' && digito <= '9') {
            valor_digito = digito - '0';
        } else {
            valor_digito = digito - 'A' + 10; 
        }
        valor_decimal = valor_decimal * 16 + valor_digito;
    }
    
    string str_decimal = to_string(valor_decimal);
    return vector<char>(str_decimal.begin(), str_decimal.end());
}

vector<char> septapus_to_octopus(vector<char> s) {
    vector<char> dec_vec = septapus_to_dec(s);
    int n = stoi(string(dec_vec.begin(), dec_vec.end()));
    return dec_to_octopus(n);
}

vector<char> septapus_to_hexakaidecapus(vector<char> s) {
    vector<char> dec_vec = septapus_to_dec(s);
    int n = stoi(string(dec_vec.begin(), dec_vec.end()));
    return dec_to_hexakaidecapus(n);
}

vector<char> octapus_to_septapus(vector<char> s) {
    vector<char> dec_vec = octopus_to_dec(s);
    int n = stoi(string(dec_vec.begin(), dec_vec.end()));
    return dec_to_septapus(n);
}

vector<char> octopus_to_hexakaidecapus(vector<char> s) {
    vector<char> dec_vec = octopus_to_dec(s);
    int n = stoi(string(dec_vec.begin(), dec_vec.end()));
    return dec_to_hexakaidecapus(n);
}

vector<char> hexakaidecapus_to_septapus(vector<char> s) {
    vector<char> dec_vec = hexakaidecapus_to_dec(s);
    int n = stoi(string(dec_vec.begin(), dec_vec.end()));
    return dec_to_septapus(n);
}

vector<char> hexakaidecapus_to_octopus(vector<char> s) {
    vector<char> dec_vec = hexakaidecapus_to_dec(s);
    int n = stoi(string(dec_vec.begin(), dec_vec.end()));
    return dec_to_octopus(n);
}