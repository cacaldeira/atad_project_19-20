/* PROJETO  ATAD 2019-20
 * Identificacao dos Alunos:
 *
 *      Numero: 180221010 | Nome: César Caldeira
 *      Numero: 180221063 | Nome: Rita Matos
 *
 */

#include <ctype.h>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "functions.h" //está a trazer o include do list.h e do map.h também

typedef char String[255];

/* definicao de prototipos de funcoes, definidas depois do main() */
int equalsStringIgnoreCase(char str1[], char str2[]);
void printCommandsMenu();
//...

/*
 * Descrição do Programa
 */
int main(int argc, char** argv)
{
    /* declaracao de variaveis */
    PtList listPatients = NULL;
    PtMap listRegions = NULL;

    /* interpretador de comandos */
    String command;
    int quit = 0;

    setlocale(LC_ALL, "PT");
    while (!quit) {
        printCommandsMenu();
        fgets(command, sizeof(command), stdin);
        /* descartar 'newline'. Utilizar esta técnica sempre que for lida uma
     * string para ser utilizada, e.g., nome de ficheiro, chave, etc.. */
        command[strlen(command) - 1] = '\0';

        if (equalsStringIgnoreCase(command, "QUIT")) {
            quit = 1; /* vai provocar a saída do interpretador */

        } else if (equalsStringIgnoreCase(command, "LOADP")) {
            listPatients = loadp();

        } else if (equalsStringIgnoreCase(command, "LOADR")) {
            listRegions = loadr();
            
        } else if (equalsStringIgnoreCase(command, "CLEAR")) {
            clear(&listPatients, &listRegions);

        } else if (equalsStringIgnoreCase(command, "AVERAGE")) {
            average(listPatients);

        } else if (equalsStringIgnoreCase(command, "FOLLOW")) {
            follow(listPatients);

        } else if (equalsStringIgnoreCase(command, "SEX")) {
            sex(listPatients);

        } else if (equalsStringIgnoreCase(command, "SHOW")) {
            show(listPatients);

        } else if (equalsStringIgnoreCase(command, "TOP5")) {
            topFive(listPatients);

        } else if (equalsStringIgnoreCase(command, "OLDEST")) {
            oldest(listPatients);

        } else if (equalsStringIgnoreCase(command, "GROWTH")) {
            growth(listPatients);

        } else if (equalsStringIgnoreCase(command, "MATRIX")) {
            matrix(listPatients);

        } else if (equalsStringIgnoreCase(command, "REGIONS")) {
            printf("Comando REGIONS nao implementado.\n");

        } else if (equalsStringIgnoreCase(command, "REPORT")) {
            printf("Comando REPORT nao implementado.\n");

        } else {
            printf("%s : Comando não encontrado.\n", command);
        }
    }

    /* libertar memória e apresentar mensagem de saída. */
    clear(&listPatients, &listRegions);
    printf("\nGoodbye!\n");

    return (EXIT_SUCCESS);
}

int equalsStringIgnoreCase(char str1[], char str2[])
{
    if (strlen(str1) != strlen(str2))
        return 0;

    for (int i = 0; i < strlen(str1); i++)
        if (tolower(str1[i]) != tolower(str2[i]))
            return 0;

    return 1;
}

void printCommandsMenu()
{
    printf(
        "\n======================================================================"
        "=============");
    printf("\n                          PROJECT: COVID-19                    ");
    printf(
        "\n======================================================================"
        "=============");
    printf("\nA. Base Commands (LOADP, LOADR, CLEAR).");
    printf(
        "\nB. Simple Indicators and searchs (AVERAGE, FOLLOW, MATRIX, OLDEST, "
        "GROWTH, SEX, SHOW, TOP5).");
    printf("\nC. Advanced indicator (REGIONS, REPORTS)");
    printf("\nD. Exit (QUIT)\n\n");
    printf("COMMAND> ");
}
