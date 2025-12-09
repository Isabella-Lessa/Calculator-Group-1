#include <stdio.h>
// Biblioteca para lidar com DATAS
#include <time.h>

// Definição do tipo estrutura (semelhante aos Objeto em JS) para armazenar as características de um produto
typedef struct {
    char name[30];
    float price;
    float weight;
} product;

// Array armazenando os produtos usando a estrutura acima como modelo
product instock[10] = {
    {"Mouse", 79.90, 0.125},
    {"Monitor", 799.90, 2.050},
    {"Teclado", 279.90, 0.500},
    {"Webcam", 129.90, 0.250},
    {"Mousepad", 49.90, 0.200},
    {"Microfone", 249.90, 0.300},
    {"Fone", 179.90, 0.250},
    {"Power Bank", 269.90, 0.400},
    {"Carregador", 129.90, 0.180},
    {"Pendrive", 49.90, 0.050}
};


// Função usada para listar os produtos
void ListProducts() {
    printf("Bem vindo à TechStore. Confira nosso catálogo abaixo: \n");

    for (size_t i = 0; i < 10; i++)
    {
        printf("%d - %s R$%.2f \n", i+1, instock[i].name, instock[i].price);
    }
    
}

// Função dedicada ao usuário escolher sua região
void SelectRegion() {
    printf("Ficamos felizes por você ter encontrado o que procura! \nO próximo passo é calcular o frete :) \n");
    printf("Por favor, selecione sua região abaixo:\n\n");
    printf("1 - SUL\n2 - SUDESTE\n3 - NORTE\n4 - NORDESTE\n");
}

// Função usada para calcular o preço do frete com base na região + peso do produto
float ShippingCostsByRegionAndWeight(int region, float weight) {
    switch (region)
    {
    case 1:
        if (weight > 2.00)
        {
            return 50.00;
        }
        return 30.00;
        break;
    case 2:
        if (weight > 2.00)
        {
            return 45.00;
        }
        return 25.00;
        break;
    case 3:
        if (weight > 2.00)
        {
            return 55.00;
        }
        return 35.00;
        break;
    case 4:
        if (weight > 2.00)
        {
            return 60.00;
        }
        return 40.00;
        break;
    default:
        break;
    }
}

// Função usada para exibir detalhes da compra (adicionar os parâmetros a serem exibidos)
void OrderDetails() {

}



int main() {
    // Valores base de escolha de id de produto e região
    int product_id = -1, region = -1;
    // Valores base para frete e peso
    float shipping = 0.00, weight = 0.00;
    
    ListProducts();
    // O usuário escolheu o produto a ser comprado com base na lista exibida
    scanf("%d", &product_id);
    // Alteramos o número do produto escolhido para corresponder ao seu índex no array
    int index = product_id-1;

    SelectRegion();
    // O usuário define sua região com base na lista exibida
    scanf("%d", &region);

    // Variável que armazena valor final do frete como resultado da função que faz este cálculo
    shipping = ShippingCostsByRegionAndWeight(region, instock[index].weight);

    // Exibe detalhes da compra (incluindo hora e prazo de entrega: feature pendente)
    OrderDetails();

    return 0;
}