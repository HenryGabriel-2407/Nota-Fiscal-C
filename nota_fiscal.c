//Bibliotecas necessárias
#include <stdio.h>
#include <stdlib.h>
//Dados declarados
typedef struct{
    char mercadoria[30];
    float valor;
}TMercadoria;
typedef enum{
    SANTA_CATARINA = 1,
    PARANA,
    RIO_GRANDE_DO_SUL,
    NAO_DEFINIDO
}Estados;
typedef struct{
    int numero;
    char emissor[30];
    char destinatario[30];
    float valor;
    TMercadoria *mercadorias;
    Estados estados[2];
}TNota;

//função para popular esses dados
void popular_dados(int quant, TNota nota[], Estados estados[], TMercadoria mercadoria[]){
    int auxiliar;     //usado para auxiliar para as escolhas dos Estados emissor/destinatario e também quantidade de mercadoria por nota;
    int quantidades_de_mercadorias[quant];
    for (int i = 0; i < quant; i++){     //para cabeçalho da nota fiscal
        printf("Numero: ");
        scanf("%d", &nota[i].numero);
        getchar();
            
        //Emissor
        printf("Emissor: ");
        scanf("%[^\n]%*c", nota[i].emissor);
        printf("Estado emissor \n[1]SANTA CATARINA \n[2]PARANA\n[3]RIO GRANDE DO SUL\n-> ");
        scanf("%d", &auxiliar);
        getchar();
        switch (auxiliar){
            case SANTA_CATARINA:
                nota[i].estados[0] = auxiliar;
                break;
            case PARANA:
                nota[i].estados[0] = auxiliar;
                break;
            case RIO_GRANDE_DO_SUL:
                nota[i].estados[0] = auxiliar;
                break;
            default:
                printf("Estado nao definido\n");
                nota[i].estados[0] = NAO_DEFINIDO;
                break;
        }

        //Destinatario
        printf("Destinatario: ");
        scanf("%[^\n]%*s", nota[i].destinatario);
        printf("Estado destinatario \n[1]SANTA CATARINA \n[2]PARANA\n[3]RIO GRANDE DO SUL\n-> ");
        scanf("%d", &auxiliar);
        switch (auxiliar){
            case SANTA_CATARINA:
                nota[i].estados[1] = auxiliar;
                break;
            case PARANA:
                nota[i].estados[1] = auxiliar;
                break;
            case RIO_GRANDE_DO_SUL:
                nota[i].estados[1] = auxiliar;
                break;
            default:
                printf("Estado nao definido\n");
                nota[i].estados[1] = NAO_DEFINIDO;
                break;
        }

        //Mercadoria
        printf("Digite a quantidade de mercadoria: ");
        scanf("%d", &auxiliar);
        quantidades_de_mercadorias[i] = auxiliar;
        getchar();
        nota[i].mercadorias = malloc(sizeof(TMercadoria) * auxiliar);
        nota[i].valor = 0.0; // importante para não somar com um número de "lixo de memória"
        for (int j = 0; j < auxiliar; j++){
            printf("Mercadoria %d: ", j+1);
            scanf("%[^\n]%*s", nota[i].mercadorias[j].mercadoria);
            printf("Valor: ");
            scanf("%f", &nota[i].mercadorias[j].valor);
            nota[i].valor += nota[i].mercadorias[j].valor;
            getchar();
        }
        printf("\n\n");
    }
    //Imprimir notas
    printf("\n=================================================\n");
    printf("Exibindo dados das notas fiscais\n");
    exibir_dados(quant, nota, NULL, NULL, quantidades_de_mercadorias);
}

void exibir_dados(int quant, TNota nota[], Estados estados[], TMercadoria mercadoria[], int quantidades_de_mercadorias[]){
    for (int i = 0; i < quant; i++){
        printf("Numero: %d\n", nota[i].numero);
        //Emissor:
        printf("Emissor: %s\n", nota[i].emissor);
        switch (nota[i].estados[0]){
        case SANTA_CATARINA:
            printf("Estado Emissor: SANTA CATARINA\n");
            break;
        case PARANA:
            printf("Estado Emissor: PARANA\n");
            break;
        case RIO_GRANDE_DO_SUL:
            printf("Estado Emissor: RIO GRANDE DO SUL\n");
            break;
        default:
            printf("Estado Emissor: NAO DEFINIDO\n");
            break;
        }
        //Destinatario:
        printf("Destinatario: %s\n", nota[i].destinatario);
        switch (nota[i].estados[1]){
        case SANTA_CATARINA:
            printf("Estado Emissor: SANTA CATARINA\n");
            break;
        case PARANA:
            printf("Estado Emissor: PARANA\n");
            break;
        case RIO_GRANDE_DO_SUL:
            printf("Estado Emissor: RIO GRANDE DO SUL\n");
            break;
        default:
            printf("Estado Emissor: NAO DEFINIDO\n");
            break;
        }
        //imprimir mercadoria e seu valor
        printf("Valor: %.2f\n", nota[i].valor);
        printf("Itens da Nota Fiscal: \n");
        for (int j = 0; j < quantidades_de_mercadorias[i]; j++){
            printf("\tMercadoria: %s\n", nota[i].mercadorias[j].mercadoria);
            printf("\tValor: %.2f\n", nota[i].mercadorias[j].valor);
        }
        printf("\n\n");
    } 
}

//e no final... limpar a memória
void liberar_memoria_notas(int quant, TNota nota[]) {
    for (int i = 0; i < quant; i++) {
        free(nota[i].mercadorias);
    }
}

int main(){
    int quant;
    printf("Digite quantas notas fiscais deseja fazer: ");
    scanf("%d", &quant);
    TNota nota[quant];
    popular_dados(quant, nota, NULL, NULL);
    liberar_memoria_notas(quant, nota);
    return 0;
}