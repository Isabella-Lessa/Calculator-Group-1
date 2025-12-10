#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Biblioteca para lidar com DATAS
#include <time.h>

// Definição do tipo estrutura (semelhante aos Objeto em JS) para armazaenar as características de um produtos
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
    int i;

    printf("\n--- CATALOGO TECHSTORE ---\n");

    for (i = 0; i < 10; i++)
    {
        printf("[%d] %-15s | R$ %8.2f | Peso: %.3fkg\n", i + 1, instock[i].name, instock[i].price, instock[i].weight);
    }
    printf("--------------------------\n");
}

// Função dedicada ao usuário escolher sua região
void SelectRegion() {
    printf("Ficamos felizes por você ter encontrado o que procura! \nO próximo passo é calcular o frete :) \n");
    printf("Por favor, selecione sua região abaixo:\n\n");
    printf("[1] - SUL\n[2] - SUDESTE\n[3] - NORTE\n[4] - NORDESTE\n");
    printf("Opcao: ");
}

// Função usada para calcular o preço do frete com base na região + peso do produto
float ShippingCostsByRegionAndWeight(int region, float weight) {
    float shippingPrice = 0.0;
    
    // Regiões
    switch (region) {
    case 1: // Sul
        shippingPrice = (weight > 2.00) ? 50.00 : 30.00;
        break;
    case 2: // Sudeste
        shippingPrice = (weight > 2.00) ? 45.00 : 25.00;
        break;
    case 3: // Norte
        shippingPrice = (weight > 2.00) ? 55.00 : 35.00;
        break;
    case 4: // Nordeste
        shippingPrice = (weight > 2.00) ? 60.00 : 40.00;
        break;
    default:
        printf("Regiao invalida! Considerando frete padrao de segurança.\n");
        shippingPrice = 50.00; // Valor de fallback
        break;
    }
    return shippingPrice;
}

// Função auxiliar para pegar o nome da região
const char* GetRegionName(int region) {
    switch(region) {
        case 1: return "Regiao Sul";
        case 2: return "Regiao Sudeste";
        case 3: return "Regiao Norte";
        case 4: return "Regiao Nordeste";
        default: return "Desconhecida";
    }
}

// Função usada para exibir detalhes da compra
void OrderDetails(int index, int region, float shipping) {
    product p = instock[index];
    float total = p.price + shipping;
    struct tm *data_atual;
    time_t segundos;

    time(&segundos);
    data_atual = localtime(&segundos);

    printf("\n========================================\n");
    printf("          RESUMO DO PEDIDO\n");
    printf("========================================\n");
    printf("Codigo do Produto: %d\n", index + 1);
    printf("Produto:           %s\n", p.name);
    printf("Peso:              %.3f Kg\n", p.weight);
    printf("Preco do Produto:  R$ %.2f\n", p.price);
    printf("----------------------------------------\n");
    printf("Local de Entrega:  %s\n", GetRegionName(region));
    printf("Frete:             R$ %.2f\n", shipping);
    printf("----------------------------------------\n");
    printf("TOTAL DA COMPRA:   R$ %.2f\n", total);
    printf("----------------------------------------\n");
    
    // Data da Compra
    printf("Data da Compra:    %02d/%02d/%d as %02d:%02d\n", 
           data_atual->tm_mday, data_atual->tm_mon+1, data_atual->tm_year+1900,
           data_atual->tm_hour, data_atual->tm_min);

    // Data de Entrega
    data_atual->tm_mday += 7; 
    mktime(data_atual); 

    printf("Previsao Entrega:  %02d/%02d/%d\n", 
           data_atual->tm_mday, data_atual->tm_mon+1, data_atual->tm_year+1900);
    printf("========================================\n\n");
}

int main() {
    // Valores base de escolha de id de produto e região
    int product_id = 0, region = 0;
    // Valores base para frete e peso
    float shipping = 0.00;
    
    ListProducts();
    // O usuário escolheu o produto a ser comprado com base na lista exibida
    printf("Digite o codigo do produto desejado: ");
    scanf("%d", &product_id);
    
    if (product_id < 1 || product_id > 10) {
        printf("Produto invalido. Encerrando.\n");
        return 1;
    }
    
    int index = product_id - 1;

    SelectRegion();
    scanf("%d", &region);

    if (region < 1 || region > 4) {
        printf("Regiao invalida. Encerrando.\n");
        return 1;
    }

    // Variável que armazena valor final do frete como resultado da função que faz este cálculo
    shipping = ShippingCostsByRegionAndWeight(region, instock[index].weight);

    // Exibe detalhes da compra
    OrderDetails(index, region, shipping);

    printf("Pressione Enter para sair...");
    getchar(); getchar(); 

    return 0;
}