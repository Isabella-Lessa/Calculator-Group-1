#include <stdio.h>

int main() {
    
    typedef struct {
        char name[30];
        float price;
        float weight;
    } product;

    product instock[10] = {
        {"Mouse", 79.90, 0.125},
        {"Monitor", 799.90, 1.25},
        {"Teclado", 279.90, 0.500},
        {"Webcam", 129.90, 0.250},
        {"Mousepad", 49.90, 0.200},
        {"Microfone", 249.90, 0.300},
        {"Fone", 179.90, 0.250},
        {"Power Bank", 269.90, 0.400},
        {"Carregador", 129.90, 0.180},
        {"Pendrive", 49.90, 0.050}
    };
    
    return 0;
}